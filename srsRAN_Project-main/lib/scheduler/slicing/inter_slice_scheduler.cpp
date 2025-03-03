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

#include "inter_slice_scheduler.h"
#include "../policy/scheduler_policy_factory.h"
#include "../support/pusch/pusch_td_resource_indices.h"
#include "srsran/srslog/srslog.h"

using namespace srsran;

inter_slice_scheduler::inter_slice_scheduler(const cell_configuration& cell_cfg_, ue_repository& ues_) :
  cell_cfg(cell_cfg_),
  logger(srslog::fetch_basic_logger("SCHED")),
  ues(ues_),
  valid_pusch_td_list_per_slot(get_fairly_distributed_pusch_td_resource_indices(cell_cfg))
{
  // Create a number of slices equal to the number of configured RRM Policy members + 1 (default SRB slice) + 1 (default
  // DRB slice).
  slices.reserve(cell_cfg.rrm_policy_members.size() + 2);

  // NOTE: We assume nof. CRBs in a cell for both DL and UL are same.
  const unsigned cell_max_rbs = cell_cfg.dl_cfg_common.init_dl_bwp.generic_params.crbs.length();

  // Create RAN slice instances.
  // Default SRB slice.
  // NOTE: We set \c min_prb for default SRB slice to maximum nof. PRBs of a UE carrier to give maximum priority to this
  // slice.
  slices.emplace_back(
      SRB_RAN_SLICE_ID, cell_cfg, slice_rrm_policy_config{.min_prb = cell_max_rbs, .max_prb = cell_max_rbs});
  slices.back().policy = create_scheduler_strategy(cell_cfg.expert_cfg.ue);
  // Default DRB slice.
  slices.emplace_back(DEFAULT_DRB_RAN_SLICE_ID, cell_cfg, slice_rrm_policy_config{.max_prb = cell_max_rbs});
  slices.back().policy = create_scheduler_strategy(cell_cfg.expert_cfg.ue);
  // NOTE: RAN slice IDs 0 and 1 are reserved for default SRB and default DRB slice respectively.
  ran_slice_id_t id_count{2};
  // Configured RRM policy members.
  for (const slice_rrm_policy_config& rrm : cell_cfg.rrm_policy_members) {
    slices.emplace_back(id_count, cell_cfg, rrm);
    // Adjust maximum PRBs per slice based on the number of PRBs in a cell.
    slices.back().inst.cfg.max_prb = std::min(slices.back().inst.cfg.max_prb, cell_max_rbs);
    // Set policy scheduler based on slice configuration.
    scheduler_ue_expert_config slice_scheduler_ue_expert_cfg{cell_cfg.expert_cfg.ue};
    slice_scheduler_ue_expert_cfg.strategy_cfg = rrm.policy_sched_cfg;
    slices.back().policy                       = create_scheduler_strategy(slice_scheduler_ue_expert_cfg);
    ++id_count;
  }
}

void inter_slice_scheduler::slot_indication(slot_point slot_tx, const cell_resource_allocator& res_grid)
{
  // Update the context of each slice.
  if (not current_slot.valid()) {
    // First call.
    current_slot = slot_tx - 1;
  }
  while (current_slot != slot_tx) {
    ++current_slot;
    for (auto& slice : slices) {
      slice.inst.slot_indication(current_slot);
    }
  }

  // Clear the priority queues.
  dl_prio_queue.clear();
  ul_prio_queue.clear();

  if (not cell_cfg.is_dl_enabled(slot_tx)) {
    // If PDCCH is inactive in this slot, we don't generate any slice candidates.
    return;
  }

  // Recompute the priority queues.
  unsigned max_rbs = 0;
  for (const auto& slice : slices) {
    const bool pdsch_enabled =
        cell_cfg.expert_cfg.ue.enable_csi_rs_pdsch_multiplexing or res_grid[0].result.dl.csi_rs.empty();
    if (pdsch_enabled) {
      max_rbs = slice.inst.pdsch_rb_count <= slice.inst.cfg.min_prb and slice.inst.cfg.min_prb > 0
                    ? slice.inst.cfg.min_prb
                    : slice.inst.cfg.max_prb;
      dl_prio_queue.push(slice_candidate_context{slice.inst.id,
                                                 slice.get_prio(true, slot_tx, slot_tx, slices.size(), false),
                                                 {slice.inst.pdsch_rb_count, max_rbs},
                                                 slot_tx});
    }

    // TODO: Revisit when PUSCH time domain resource list is also defined in UE dedicated configuration.
    span<const pusch_time_domain_resource_allocation> pusch_time_domain_list =
        cell_cfg.ul_cfg_common.init_ul_bwp.pusch_cfg_common.value().pusch_td_alloc_list;
    for (const unsigned pusch_td_res_idx :
         valid_pusch_td_list_per_slot[slot_tx.to_uint() % valid_pusch_td_list_per_slot.size()]) {
      const cell_slot_resource_allocator& pusch_alloc = res_grid[pusch_time_domain_list[pusch_td_res_idx].k2];
      const crb_bitmap                    pusch_used_crbs =
          pusch_alloc.ul_res_grid.used_crbs(cell_cfg.ul_cfg_common.init_ul_bwp.generic_params.scs,
                                            cell_cfg.ul_cfg_common.init_ul_bwp.generic_params.crbs,
                                            pusch_time_domain_list[pusch_td_res_idx].symbols);
      if (pusch_used_crbs.all()) {
        // No more RBs left to allocated so skip adding slice candidate.
        continue;
      }

      slot_point pusch_slot     = slot_tx + pusch_time_domain_list[pusch_td_res_idx].k2;
      unsigned   pusch_rb_count = slice.inst.nof_pusch_rbs_allocated(pusch_slot);
      max_rbs = pusch_rb_count <= slice.inst.cfg.min_prb and slice.inst.cfg.min_prb > 0 ? slice.inst.cfg.min_prb
                                                                                        : slice.inst.cfg.max_prb;
      ul_prio_queue.push(slice_candidate_context{slice.inst.id,
                                                 slice.get_prio(false, slot_tx, pusch_slot, slices.size(), false),
                                                 {pusch_rb_count, max_rbs},
                                                 pusch_slot});
    }
  }
}

void inter_slice_scheduler::add_ue(du_ue_index_t ue_idx)
{
  ue* u = fetch_ue_to_update(ue_idx);
  if (u == nullptr) {
    return;
  }

  // Add UE and new bearers.
  add_impl(*u);
}

void inter_slice_scheduler::reconf_ue(du_ue_index_t ue_idx)
{
  // When the UE is reconfigured, it enters fallback mode and only leaves it when config_applied is called.
  // For this reason, we remove the UE from its slices.
  rem_ue(ue_idx);
}

void inter_slice_scheduler::rem_ue(du_ue_index_t ue_idx)
{
  // Remove all logical channels of UE.
  // Note: We take the conservative approach of traversing all slices, because the current UE config might not match
  // the UE repositories inside each slice instance (e.g. in case of fallback or during reconfig).
  for (auto& slice : slices) {
    slice.inst.rem_ue(ue_idx);
  }
}

void inter_slice_scheduler::config_applied(du_ue_index_t ue_idx)
{
  ue* u = fetch_ue_to_update(ue_idx);
  if (u == nullptr) {
    logger.error("Config applied to a UE that is inactive or in fallback");
    return;
  }

  // Add UE to slices.
  add_impl(*u);
}

void inter_slice_scheduler::add_impl(ue& u)
{
  const ue_configuration& ue_cfg = *u.ue_cfg_dedicated();
  for (logical_channel_config_ptr lc_cfg : *ue_cfg.logical_channels()) {
    ran_slice_instance& sl_inst = get_slice(*lc_cfg);
    sl_inst.add_logical_channel(u, lc_cfg->lcid, lc_cfg->lc_group);
  }
}

ue* inter_slice_scheduler::fetch_ue_to_update(du_ue_index_t ue_idx)
{
  if (not ues.contains(ue_idx)) {
    // UE should be added to the repository at this stage.
    logger.warning("ue={}: Not configuring UE to slice scheduler. Cause: No UE context found", fmt::underlying(ue_idx));
    return nullptr;
  }

  auto&                   u      = ues[ue_idx];
  const ue_configuration& ue_cfg = *u.ue_cfg_dedicated();

  // If UE does not have complete configuration, we won't be added to any slice.
  if (not ue_cfg.is_ue_cfg_complete()) {
    return nullptr;
  }

  // If UE is in fallback mode, we do not add it to the slice scheduler.
  const ue_cell* ue_cc = u.find_cell(cell_cfg.cell_index);
  if (ue_cc == nullptr) {
    logger.warning("ue={}: Not adding UE to slice scheduler. Cause: No UE context found in cell {}",
                   fmt::underlying(ue_cfg.ue_index),
                   fmt::underlying(cell_cfg.cell_index));
    return nullptr;
  }
  if (ue_cc->is_in_fallback_mode()) {
    // Do not include yet the UE in the slice scheduler.
    return nullptr;
  }

  return &u;
}

ran_slice_instance& inter_slice_scheduler::get_slice(const logical_channel_config& lc_cfg)
{
  // Return default SRB slice if LCID belongs to a SRB.
  if (lc_cfg.lcid < LCID_MIN_DRB) {
    return slices[SRB_RAN_SLICE_ID.value()].inst;
  }
  auto it = std::find_if(slices.begin(), slices.end(), [&lc_cfg](const ran_slice_sched_context& slice) {
    return slice.inst.cfg.rrc_member == lc_cfg.rrm_policy;
  });
  if (it == slices.end() or lc_cfg.rrm_policy == rrm_policy_member{}) {
    // Slice with the provided RRM policy member was not found. Return default DRB slice.
    return slices[DEFAULT_DRB_RAN_SLICE_ID.value()].inst;
  }
  return it->inst;
}

template <bool IsDownlink>
std::optional<std::conditional_t<IsDownlink, dl_ran_slice_candidate, ul_ran_slice_candidate>>
inter_slice_scheduler::get_next_candidate()
{
  using candidate_type = std::conditional_t<IsDownlink, dl_ran_slice_candidate, ul_ran_slice_candidate>;

  slice_prio_queue& prio_queue = IsDownlink ? dl_prio_queue : ul_prio_queue;
  while (not prio_queue.empty()) {
    ran_slice_sched_context& chosen_slice = slices[prio_queue.top().id.value()];
    interval<unsigned>       rb_lims      = prio_queue.top().rb_lims;
    slot_point               pxsch_slot   = prio_queue.top().slot_tx;
    prio_queue.pop();

    unsigned rb_count =
        IsDownlink
            ? chosen_slice.inst.pdsch_rb_count
            : chosen_slice.inst
                  .pusch_rb_count_per_slot[pxsch_slot.to_uint() % chosen_slice.inst.pusch_rb_count_per_slot.size()];
    if (not rb_lims.contains(rb_count)) {
      // The slice has been scheduled in this slot with a number of RBs that is not within the limits for this
      // candidate. This could happen, for instance, if the scheduler could not schedule all RBs of a candidate
      // bounded between {RBLimsMin, RBLimsMax}. In this case, the second candidate for the same slice with bounds
      // {RBLimsMax, maxRB} is skipped.
      continue;
    }

    const slice_rrm_policy_config& cfg = chosen_slice.inst.cfg;
    if (cfg.min_prb > 0 and cfg.min_prb != cfg.max_prb and rb_lims.stop() >= cfg.min_prb and
        rb_lims.stop() != cfg.max_prb) {
      // For the special case when minRB ratio>0, the first candidate for this slice was bounded between {RBLimsMin,
      // RBLimsMax}. We re-add the slice as a candidate, this time, with RB bounds {RBLimsMax, maxRB}.
      priority_type prio    = chosen_slice.get_prio(IsDownlink, current_slot, pxsch_slot, slices.size(), true);
      unsigned      min_rbs = rb_count > 0 ? rb_count : cfg.min_prb;
      prio_queue.push(slice_candidate_context{chosen_slice.inst.id, prio, {min_rbs, cfg.max_prb}, pxsch_slot});
    }

    // Return the candidate.
    return candidate_type{chosen_slice.inst, pxsch_slot, rb_lims.stop()};
  }
  return std::nullopt;
}

std::optional<dl_ran_slice_candidate> inter_slice_scheduler::get_next_dl_candidate()
{
  return get_next_candidate<true>();
}

std::optional<ul_ran_slice_candidate> inter_slice_scheduler::get_next_ul_candidate()
{
  return get_next_candidate<false>();
}

inter_slice_scheduler::priority_type inter_slice_scheduler::ran_slice_sched_context::get_prio(bool       is_dl,
                                                                                              slot_point pdcch_slot,
                                                                                              slot_point pxsch_slot,
                                                                                              unsigned   nof_slices,
                                                                                              bool slice_resched) const
{
  // Note: The positive integer representing the priority of a slice consists of a concatenation of three priority
  // values:
  // 1. slice traffic priority (16 most significant bits). It differentiates slices based on whether they have
  // minimum required traffic agreements (e.g. minRB ratio).
  // 2. delay priority (8 bits), which attributes the highest priority to slices that have not been scheduled for a
  // long time.
  // 3. round-robin based on slot indication count (8 least significant bits).

  // Priority when slice has already reached its minimum RB ratio agreement.
  static constexpr priority_type default_prio = 0x1U;
  // Priority when slice still needs to reach its minimum RB ratio agreement.
  static constexpr priority_type high_prio          = 0x2U;
  static constexpr priority_type slice_prio_bitsize = 4U;
  static constexpr priority_type delay_prio_bitsize = 8U;
  static constexpr priority_type delay_prio_bitmask = (1U << delay_prio_bitsize) - 1U;
  static constexpr priority_type rr_bitsize         = 8U;

  unsigned rb_count = is_dl ? inst.pdsch_rb_count : inst.nof_pusch_rbs_allocated(pxsch_slot);
  if (not inst.active() or rb_count >= inst.cfg.max_prb) {
    // If the slice is not in a state to be scheduled in this slot, return skip priority level.
    return skip_prio;
  }

  // Prioritize closer slots over slots further away into the future. This is relevant for UL-heavy cases.
  unsigned slot_dist = 0xfU - std::min(static_cast<unsigned>(pxsch_slot - pdcch_slot), 0xfU);

  // In case minRB > 0 and minimum RB ratio agreement is not yet reached, we give it a higher priority.
  priority_type slice_prio =
      not slice_resched and inst.cfg.min_prb > 0 and rb_count < inst.cfg.min_prb ? high_prio : default_prio;

  // Increase priorities of slices that have not been scheduled for a long time.
  priority_type delay_prio =
      is_dl ? inst.nof_slots_since_last_pdsch(pxsch_slot) : inst.nof_slots_since_last_pusch(pxsch_slot);
  delay_prio = std::min(delay_prio, delay_prio_bitmask);

  // Round-robin across slices with the same slice and delay priorities.
  float          rbs_per_slot = is_dl ? inst.average_pdsch_rbs_per_slot() : inst.average_pusch_rbs_per_slot();
  const unsigned rr_prio_max  = (1U << rr_bitsize) - 1U;
  priority_type  rr_prio      = rr_prio_max - std::min((unsigned)std::round(rbs_per_slot), rr_prio_max);

  return (slot_dist << (delay_prio_bitsize + rr_bitsize + slice_prio_bitsize)) +
         (slice_prio << (delay_prio_bitsize + rr_bitsize)) + (delay_prio << rr_bitsize) + rr_prio;
}
