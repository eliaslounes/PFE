/*
 *
 * Copyright 2021-2025 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include "grant_params_selector.h"
#include "../support/dmrs_helpers.h"
#include "../support/prbs_calculator.h"
#include "../ue_context/ue_cell.h"

using namespace srsran;
using namespace sched_helper;

std::optional<mcs_prbs_selection>
sched_helper::compute_newtx_required_mcs_and_prbs(const pdsch_config_params& pdsch_cfg,
                                                  const ue_cell&             ue_cc,
                                                  unsigned                   pending_bytes)
{
  const ue_cell_configuration& ue_cell_cfg = ue_cc.cfg();
  const cell_configuration&    cell_cfg    = ue_cell_cfg.cell_cfg_common;

  std::optional<sch_mcs_index> mcs = ue_cc.link_adaptation_controller().calculate_dl_mcs(pdsch_cfg.mcs_table);
  if (not mcs.has_value()) {
    // Return a grant with no PRBs if the MCS is invalid (CQI is either 0, for UE out of range, or > 15).
    return std::nullopt;
  }
  sch_mcs_description mcs_config = pdsch_mcs_get_config(pdsch_cfg.mcs_table, mcs.value());

  // Estimate max RBs per grant.
  const bwp_downlink_common& bwp_dl_cmn = *ue_cell_cfg.bwp(ue_cc.active_bwp_id()).dl_common.value();
  unsigned                   max_prbs   = std::min({bwp_dl_cmn.generic_params.crbs.length(),
                                                    cell_cfg.expert_cfg.ue.pdsch_nof_rbs.stop(),
                                                    ue_cell_cfg.rrm_cfg().pdsch_grant_size_limits.stop()});

  sch_prbs_tbs prbs_tbs = get_nof_prbs(prbs_calculator_sch_config{pending_bytes,
                                                                  pdsch_cfg.symbols.length(),
                                                                  calculate_nof_dmrs_per_rb(pdsch_cfg.dmrs),
                                                                  pdsch_cfg.nof_oh_prb,
                                                                  mcs_config,
                                                                  pdsch_cfg.nof_layers},
                                       max_prbs);
  srsran_sanity_check(prbs_tbs.nof_prbs <= max_prbs, "Error in RB computation");
  if (prbs_tbs.nof_prbs == 0) {
    return std::nullopt;
  }

  // Apply grant size limits specified in the config.
  prbs_tbs.nof_prbs = std::max(std::min(prbs_tbs.nof_prbs, cell_cfg.expert_cfg.ue.pdsch_nof_rbs.stop()),
                               cell_cfg.expert_cfg.ue.pdsch_nof_rbs.start());
  prbs_tbs.nof_prbs = std::max(std::min(prbs_tbs.nof_prbs, ue_cell_cfg.rrm_cfg().pdsch_grant_size_limits.stop()),
                               ue_cell_cfg.rrm_cfg().pdsch_grant_size_limits.start());

  return mcs_prbs_selection{mcs.value(), prbs_tbs.nof_prbs};
}

static pusch_config_params compute_pusch_config_params(const ue_cell&                               ue_cc,
                                                       dci_ul_rnti_config_type                      dci_type,
                                                       unsigned                                     nof_layers,
                                                       const pusch_time_domain_resource_allocation& pusch_td_cfg,
                                                       unsigned                                     uci_bits,
                                                       bool                                         is_csi_report_slot)
{
  const ue_cell_configuration& ue_cell_cfg = ue_cc.cfg();
  const cell_configuration&    cell_cfg    = ue_cc.cfg().cell_cfg_common;
  const bwp_uplink_common&     bwp_ul_cmn  = *ue_cell_cfg.bwp(ue_cc.active_bwp_id()).ul_common.value();

  pusch_config_params pusch_cfg;
  switch (dci_type) {
    case dci_ul_rnti_config_type::tc_rnti_f0_0:
      pusch_cfg = get_pusch_config_f0_0_tc_rnti(cell_cfg, pusch_td_cfg);
      break;
    case dci_ul_rnti_config_type::c_rnti_f0_0:
      pusch_cfg =
          get_pusch_config_f0_0_c_rnti(cell_cfg, &ue_cell_cfg, bwp_ul_cmn, pusch_td_cfg, uci_bits, is_csi_report_slot);
      break;
    case dci_ul_rnti_config_type::c_rnti_f0_1:
      pusch_cfg = get_pusch_config_f0_1_c_rnti(ue_cell_cfg, pusch_td_cfg, nof_layers, uci_bits, is_csi_report_slot);
      break;
    default:
      report_fatal_error("Unsupported PDCCH DCI UL format");
  }

  return pusch_cfg;
}

pusch_config_params
sched_helper::compute_newtx_pusch_config_params(const ue_cell&                               ue_cc,
                                                dci_ul_rnti_config_type                      dci_type,
                                                const pusch_time_domain_resource_allocation& pusch_td_cfg,
                                                unsigned                                     uci_bits,
                                                bool                                         is_csi_report_slot)
{
  return compute_pusch_config_params(
      ue_cc, dci_type, ue_cc.channel_state_manager().get_nof_ul_layers(), pusch_td_cfg, uci_bits, is_csi_report_slot);
}

pusch_config_params
sched_helper::compute_retx_pusch_config_params(const ue_cell&                               ue_cc,
                                               const ul_harq_process_handle&                h_ul,
                                               const pusch_time_domain_resource_allocation& pusch_td_cfg,
                                               unsigned                                     uci_bits,
                                               bool                                         is_csi_report_slot)
{
  return compute_pusch_config_params(ue_cc,
                                     h_ul.get_grant_params().dci_cfg_type,
                                     h_ul.get_grant_params().nof_layers,
                                     pusch_td_cfg,
                                     uci_bits,
                                     is_csi_report_slot);
}

mcs_prbs_selection sched_helper::compute_newtx_required_mcs_and_prbs(const pusch_config_params& pusch_cfg,
                                                                     const ue_cell&             ue_cc,
                                                                     unsigned                   pending_bytes)
{
  const ue_cell_configuration& ue_cell_cfg = ue_cc.cfg();
  const cell_configuration&    cell_cfg    = ue_cc.cfg().cell_cfg_common;
  const bwp_uplink_common&     bwp_ul_cmn  = *ue_cell_cfg.bwp(ue_cc.active_bwp_id()).ul_common.value();

  sch_mcs_index       mcs = ue_cc.link_adaptation_controller().calculate_ul_mcs(pusch_cfg.mcs_table);
  sch_mcs_description mcs_config =
      pusch_mcs_get_config(pusch_cfg.mcs_table, mcs, pusch_cfg.use_transform_precoder, false);

  const auto nof_symbols = pusch_cfg.symbols.length();

  sch_prbs_tbs prbs_tbs = get_nof_prbs(prbs_calculator_sch_config{pending_bytes,
                                                                  nof_symbols,
                                                                  calculate_nof_dmrs_per_rb(pusch_cfg.dmrs),
                                                                  pusch_cfg.nof_oh_prb,
                                                                  mcs_config,
                                                                  pusch_cfg.nof_layers});

  // Apply grant size limits specified in the config.
  unsigned nof_prbs = std::min(prbs_tbs.nof_prbs, bwp_ul_cmn.generic_params.crbs.length());
  nof_prbs          = std::max(std::min(nof_prbs, cell_cfg.expert_cfg.ue.pusch_nof_rbs.stop()),
                      cell_cfg.expert_cfg.ue.pusch_nof_rbs.start());
  nof_prbs          = std::max(std::min(nof_prbs, ue_cell_cfg.rrm_cfg().pusch_grant_size_limits.stop()),
                      ue_cell_cfg.rrm_cfg().pusch_grant_size_limits.start());

  return mcs_prbs_selection{mcs, nof_prbs};
}
