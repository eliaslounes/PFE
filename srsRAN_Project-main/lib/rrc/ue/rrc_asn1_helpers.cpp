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

#include "rrc_asn1_helpers.h"
#include "rrc_asn1_converters.h"
#include "rrc_measurement_types_asn1_converters.h"

using namespace srsran;
using namespace srs_cu_cp;

bool srsran::srs_cu_cp::fill_asn1_rrc_setup_msg(asn1::rrc_nr::rrc_setup_s& rrc_setup,
                                                const byte_buffer&         mcg,
                                                uint8_t                    rrc_transaction_id)
{
  using namespace asn1::rrc_nr;
  rrc_setup_ies_s& setup_ies   = rrc_setup.crit_exts.set_rrc_setup();
  rrc_setup.rrc_transaction_id = rrc_transaction_id;

  // Add SRB1
  // Note: See TS 38.331 section 5.3.5.6.3 - SRB addition/modification
  auto& radio_bearer_cfg = setup_ies.radio_bearer_cfg;
  radio_bearer_cfg.srb_to_add_mod_list.push_back(srb_to_add_mod_s{});
  radio_bearer_cfg.srb_to_add_mod_list.back().srb_id = 1; // SRB1

  // Copy cell config from DU_to_CU_RRC_Container to master cell group
  auto& master_cell_group = setup_ies.master_cell_group;
  if (!master_cell_group.resize(mcg.length())) {
    return false;
  }

  std::copy(mcg.begin(), mcg.end(), master_cell_group.begin());
  return true;
}

expected<uint8_t> srsran::srs_cu_cp::get_transaction_id(const asn1::rrc_nr::rrc_setup_complete_s& msg)
{
  return msg.rrc_transaction_id;
}

expected<uint8_t> srsran::srs_cu_cp::get_transaction_id(const asn1::rrc_nr::ul_dcch_msg_s& msg)
{
  using namespace asn1::rrc_nr;
  switch (msg.msg.c1().type().value) {
    case ul_dcch_msg_type_c::c1_c_::types_opts::rrc_setup_complete:
      return msg.msg.c1().rrc_setup_complete().rrc_transaction_id;
      // TODO: Remaining cases.
    default:
      break;
  }
  return make_unexpected(default_error_t{});
}

void srsran::srs_cu_cp::fill_asn1_rrc_smc_msg(asn1::rrc_nr::security_mode_cmd_s&   rrc_smc,
                                              const security::integrity_algorithm& int_algo,
                                              const security::ciphering_algorithm& ciph_algo,
                                              uint8_t                              rrc_transaction_id)
{
  using namespace asn1::rrc_nr;
  security_mode_cmd_ies_s& smc_ies = rrc_smc.crit_exts.set_security_mode_cmd();
  rrc_smc.rrc_transaction_id       = rrc_transaction_id;

  // Set security algorithms
  security_cfg_smc_s&       security_cfg_smc       = smc_ies.security_cfg_smc;
  security_algorithm_cfg_s& security_algorithm_cfg = security_cfg_smc.security_algorithm_cfg;

  security_algorithm_cfg.integrity_prot_algorithm_present = true;
  switch (int_algo) {
    case security::integrity_algorithm::nia0:
      security_algorithm_cfg.integrity_prot_algorithm = integrity_prot_algorithm_e::nia0;
      break;
    case security::integrity_algorithm::nia1:
      security_algorithm_cfg.integrity_prot_algorithm = integrity_prot_algorithm_e::nia1;
      break;
    case security::integrity_algorithm::nia2:
      security_algorithm_cfg.integrity_prot_algorithm = integrity_prot_algorithm_e::nia2;
      break;
    case security::integrity_algorithm::nia3:
      security_algorithm_cfg.integrity_prot_algorithm = integrity_prot_algorithm_e::nia3;
      break;
  }
  switch (ciph_algo) {
    case security::ciphering_algorithm::nea0:
      security_algorithm_cfg.ciphering_algorithm = ciphering_algorithm_e::nea0;
      break;
    case security::ciphering_algorithm::nea1:
      security_algorithm_cfg.ciphering_algorithm = ciphering_algorithm_e::nea1;
      break;
    case security::ciphering_algorithm::nea2:
      security_algorithm_cfg.ciphering_algorithm = ciphering_algorithm_e::nea2;
      break;
    case security::ciphering_algorithm::nea3:
      security_algorithm_cfg.ciphering_algorithm = ciphering_algorithm_e::nea3;
      break;
  }
}

void srsran::srs_cu_cp::fill_asn1_rrc_reconfiguration_msg(asn1::rrc_nr::rrc_recfg_s&            asn1_rrc_reconf,
                                                          uint8_t                               rrc_transaction_id,
                                                          rrc_reconfiguration_procedure_request rrc_reconf)
{
  using namespace asn1::rrc_nr;

  asn1_rrc_reconf.rrc_transaction_id = rrc_transaction_id;

  rrc_recfg_ies_s& asn1_reconfig_ies = asn1_rrc_reconf.crit_exts.set_rrc_recfg();

  // Fill radio bearer config.
  if (rrc_reconf.radio_bearer_cfg.has_value()) {
    asn1_reconfig_ies.radio_bearer_cfg_present = true;
    auto& asn1_radio_bearer_cfg                = asn1_reconfig_ies.radio_bearer_cfg;

    auto& cu_cp_radio_bearer_cfg = rrc_reconf.radio_bearer_cfg.value();

    // Fill SRB to add mod list.
    for (const auto& srb_to_add : cu_cp_radio_bearer_cfg.srb_to_add_mod_list) {
      srsran_assert(srb_to_add.srb_id != srb_id_t::nulltype, "Invalid SRB ID");

      asn1::rrc_nr::srb_to_add_mod_s asn1_srb_to_add;
      asn1_srb_to_add.srb_id = srb_id_to_uint(srb_to_add.srb_id);

      asn1_srb_to_add.reestablish_pdcp_present = srb_to_add.reestablish_pdcp_present;

      asn1_srb_to_add.discard_on_pdcp_present = srb_to_add.discard_on_pdcp_present;

      // Fill PDCP config.
      if (srb_to_add.pdcp_cfg.has_value()) {
        asn1_srb_to_add.pdcp_cfg_present = true;
        asn1_srb_to_add.pdcp_cfg         = pdcp_config_to_rrc_nr_asn1(srb_to_add.pdcp_cfg.value());
      }

      asn1_radio_bearer_cfg.srb_to_add_mod_list.push_back(asn1_srb_to_add);
    }

    // Fill DRB to add mod list.
    for (const auto& drb_to_add : cu_cp_radio_bearer_cfg.drb_to_add_mod_list) {
      srsran_assert(drb_to_add.drb_id != drb_id_t::invalid, "Invalid DRB ID");

      asn1::rrc_nr::drb_to_add_mod_s asn1_drb_to_add;
      asn1_drb_to_add.drb_id = drb_id_to_uint(drb_to_add.drb_id);

      asn1_drb_to_add.reestablish_pdcp_present = drb_to_add.reestablish_pdcp_present;

      // Fill PDCP config.
      if (drb_to_add.pdcp_cfg.has_value()) {
        asn1_drb_to_add.pdcp_cfg_present = true;
        asn1_drb_to_add.pdcp_cfg         = pdcp_config_to_rrc_nr_asn1(drb_to_add.pdcp_cfg.value());
      }

      // Fill CN association and SDAP config.
      if (drb_to_add.cn_assoc.has_value()) {
        asn1_drb_to_add.cn_assoc_present = true;
        if (drb_to_add.cn_assoc.value().sdap_cfg.has_value()) {
          asn1_drb_to_add.cn_assoc.set_sdap_cfg();
          asn1_drb_to_add.cn_assoc.sdap_cfg() = sdap_config_to_rrc_asn1(drb_to_add.cn_assoc.value().sdap_cfg.value());
        } else {
          asn1_drb_to_add.cn_assoc.set_eps_bearer_id();
          asn1_drb_to_add.cn_assoc.eps_bearer_id() = drb_to_add.cn_assoc.value().eps_bearer_id.value();
        }
      }

      asn1_radio_bearer_cfg.drb_to_add_mod_list.push_back(asn1_drb_to_add);
    }

    // Fill DRB to release list.
    for (const auto& drb_to_release : cu_cp_radio_bearer_cfg.drb_to_release_list) {
      srsran_assert(drb_to_release != drb_id_t::invalid, "Invalid DRB ID");
      asn1_radio_bearer_cfg.drb_to_release_list.push_back(drb_id_to_uint(drb_to_release));
    }

    // Fill security config.
    if (cu_cp_radio_bearer_cfg.security_cfg.has_value()) {
      asn1_radio_bearer_cfg.security_cfg_present = true;

      const auto& security_cfg = cu_cp_radio_bearer_cfg.security_cfg.value();

      // Fill security algorithm config.
      if (security_cfg.security_algorithm_cfg.has_value()) {
        asn1_radio_bearer_cfg.security_cfg.security_algorithm_cfg_present = true;

        // Fill ciphering algorithm config.
        asn1_radio_bearer_cfg.security_cfg.security_algorithm_cfg.ciphering_algorithm =
            ciphering_algorithm_to_rrc_asn1(security_cfg.security_algorithm_cfg.value().ciphering_algorithm);

        // Fill integrity prot algorithm config.
        if (security_cfg.security_algorithm_cfg.value().integrity_prot_algorithm.has_value()) {
          asn1_radio_bearer_cfg.security_cfg.security_algorithm_cfg.integrity_prot_algorithm_present = true;
          asn1_radio_bearer_cfg.security_cfg.security_algorithm_cfg.integrity_prot_algorithm =
              integrity_prot_algorithm_to_rrc_asn1(
                  security_cfg.security_algorithm_cfg.value().integrity_prot_algorithm.value());
        }
      }
      // Fill key to use.
      if (security_cfg.key_to_use.has_value()) {
        asn1_radio_bearer_cfg.security_cfg.key_to_use_present = true;
        asn1::string_to_enum(asn1_radio_bearer_cfg.security_cfg.key_to_use, security_cfg.key_to_use.value());
      }
    }

    // Fill SRB3 to release present.
    asn1_radio_bearer_cfg.srb3_to_release_present = cu_cp_radio_bearer_cfg.srb3_to_release_present;
  }

  // Fill secondary cell group.
  asn1_reconfig_ies.secondary_cell_group = rrc_reconf.secondary_cell_group.copy();

  // Fill measurement config.
  if (rrc_reconf.meas_cfg.has_value()) {
    asn1_reconfig_ies.meas_cfg_present = true;
    asn1_reconfig_ies.meas_cfg         = meas_config_to_rrc_asn1(rrc_reconf.meas_cfg.value());

    // Fill measurement gap config.
    if (!rrc_reconf.meas_gap_cfg.empty()) {
      asn1_reconfig_ies.meas_cfg.meas_gap_cfg_present = true;

      // Unpack measurement gap config PDU.
      asn1::rrc_nr::meas_gap_cfg_s asn1_meas_gap_cfg;
      asn1::cbit_ref               bref(rrc_reconf.meas_gap_cfg);

      if (asn1_reconfig_ies.meas_cfg.meas_gap_cfg.unpack(bref) != asn1::SRSASN_SUCCESS) {
        report_fatal_error("Couldn't unpack MeasGapConfig RRC container");
      }
    }
  }

  // non crit ext
  if (rrc_reconf.non_crit_ext.has_value()) {
    asn1_reconfig_ies.non_crit_ext_present = true;
    const auto& non_crit_ext               = rrc_reconf.non_crit_ext.value();

    // full cfg
    asn1_reconfig_ies.non_crit_ext.full_cfg_present = non_crit_ext.full_cfg_present;

    // master cell group config
    if (!non_crit_ext.master_cell_group.empty()) {
      asn1_reconfig_ies.non_crit_ext.master_cell_group = non_crit_ext.master_cell_group.copy();
    }

    // ded nas msg list
    for (const auto& nas_pdu : non_crit_ext.ded_nas_msg_list) {
      asn1_reconfig_ies.non_crit_ext.ded_nas_msg_list.push_back(nas_pdu.copy());
    }

    // master key upd
    if (non_crit_ext.master_key_upd.has_value()) {
      asn1_reconfig_ies.non_crit_ext.master_key_upd_present = true;
      asn1_reconfig_ies.non_crit_ext.master_key_upd.key_set_change_ind =
          non_crit_ext.master_key_upd.value().key_set_change_ind;
      asn1_reconfig_ies.non_crit_ext.master_key_upd.next_hop_chaining_count =
          non_crit_ext.master_key_upd.value().next_hop_chaining_count;
      asn1_reconfig_ies.non_crit_ext.master_key_upd.nas_container =
          non_crit_ext.master_key_upd.value().nas_container.copy();
    }

    // ded sib1 delivery
    if (!non_crit_ext.ded_sib1_delivery.empty()) {
      asn1_reconfig_ies.non_crit_ext.ded_sib1_delivery = non_crit_ext.ded_sib1_delivery.copy();
    }

    // ded sys info delivery
    if (!non_crit_ext.ded_sys_info_delivery.empty()) {
      asn1_reconfig_ies.non_crit_ext.ded_sys_info_delivery = non_crit_ext.ded_sys_info_delivery.copy();
    }

    // other cfg
    if (non_crit_ext.other_cfg.has_value()) {
      asn1_reconfig_ies.non_crit_ext.other_cfg_present = true;
      if (non_crit_ext.other_cfg.value().delay_budget_report_cfg.has_value()) {
        asn1_reconfig_ies.non_crit_ext.other_cfg.delay_budget_report_cfg_present = true;
        const auto& delay_budget_report_cfg = non_crit_ext.other_cfg.value().delay_budget_report_cfg.value();

        if (delay_budget_report_cfg.type == "setup") {
          asn1_reconfig_ies.non_crit_ext.other_cfg.delay_budget_report_cfg.set_setup();
          asn1::string_to_enum(asn1_reconfig_ies.non_crit_ext.other_cfg.delay_budget_report_cfg.setup()
                                   .delay_budget_report_prohibit_timer,
                               delay_budget_report_cfg.delay_budget_report_prohibit_timer);
        } else if (delay_budget_report_cfg.type == "release") {
          asn1_reconfig_ies.non_crit_ext.other_cfg.delay_budget_report_cfg.set_release();
        } else {
          asn1_reconfig_ies.non_crit_ext.other_cfg.delay_budget_report_cfg.set(
              asn1::rrc_nr::other_cfg_s::delay_budget_report_cfg_c_::types_opts::nulltype);
        }
      }
    }

    // TODO: add further extensions
  }
}
