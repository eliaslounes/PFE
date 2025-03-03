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

#include "du_high_scheduler_cell_metrics_consumers.h"
#include "du_high_rlc_metrics.h"
#include "srsran/scheduler/scheduler_metrics.h"
#include "srsran/support/engineering_notation.h"
#include "fmt/ranges.h"
#include "fmt/std.h"
#include <ostream>

using namespace srsran;

namespace {

/// UE container metrics.
DECLARE_METRIC("pci", metric_pci, pci_t, "");
DECLARE_METRIC("rnti", metric_rnti, uint16_t, "");
DECLARE_METRIC("cqi", metric_cqi, uint8_t, "");
DECLARE_METRIC("dl_ri", metric_dl_ri, float, "");
DECLARE_METRIC("ul_ri", metric_ul_ri, float, "");
DECLARE_METRIC("dl_mcs", metric_dl_mcs, uint8_t, "");
DECLARE_METRIC("dl_brate", metric_dl_brate, double, "");
DECLARE_METRIC("dl_nof_ok", metric_dl_nof_ok, unsigned, "");
DECLARE_METRIC("dl_nof_nok", metric_dl_nof_nok, unsigned, "");
DECLARE_METRIC("dl_bs", metric_dl_bs, unsigned, "");
DECLARE_METRIC("pusch_snr_db", metric_pusch_snr_db, float, "");
DECLARE_METRIC("pucch_snr_db", metric_pucch_snr_db, float, "");
DECLARE_METRIC("ta_ns", metric_ta_ns, std::string, "");
DECLARE_METRIC("pusch_ta_ns", metric_pusch_ta_ns, std::string, "");
DECLARE_METRIC("pucch_ta_ns", metric_pucch_ta_ns, std::string, "");
DECLARE_METRIC("srs_ta_ns", metric_srs_ta_ns, std::string, "");
DECLARE_METRIC("ul_mcs", metric_ul_mcs, uint8_t, "");
DECLARE_METRIC("ul_brate", metric_ul_brate, double, "");
DECLARE_METRIC("ul_nof_ok", metric_ul_nof_ok, unsigned, "");
DECLARE_METRIC("ul_nof_nok", metric_ul_nof_nok, unsigned, "");
DECLARE_METRIC("bsr", metric_bsr, unsigned, "");
DECLARE_METRIC("nof_pucch_f0f1_invalid_harqs", metric_nof_pucch_f0f1_invalid_harqs, unsigned, "");
DECLARE_METRIC("nof_pucch_f2f3f4_invalid_harqs", metric_nof_pucch_f2f3f4_invalid_harqs, unsigned, "");
DECLARE_METRIC("nof_pucch_f2f3f4_invalid_csis", metric_nof_pucch_f2f3f4_invalid_csis, unsigned, "");
DECLARE_METRIC("nof_pusch_invalid_harqs", metric_nof_pusch_invalid_harqs, unsigned, "");
DECLARE_METRIC("nof_pusch_invalid_csis", metric_nof_pusch_invalid_csis, unsigned, "");
DECLARE_METRIC("avg_ce_delay", metric_avg_ce_delay, float, "ms");
DECLARE_METRIC("max_ce_delay", metric_max_ce_delay, float, "ms");
DECLARE_METRIC("avg_crc_delay", metric_avg_crc_delay, float, "ms");
DECLARE_METRIC("max_crc_delay", metric_max_crc_delay, float, "ms");
DECLARE_METRIC("avg_pusch_harq_delay", metric_avg_pusch_harq_delay, float, "ms");
DECLARE_METRIC("max_pusch_harq_delay", metric_max_pusch_harq_delay, float, "ms");
DECLARE_METRIC("avg_pucch_harq_delay", metric_avg_pucch_harq_delay, float, "ms");
DECLARE_METRIC("max_pucch_harq_delay", metric_max_pucch_harq_delay, float, "ms");
DECLARE_METRIC_SET("ue_container",
                   mset_ue_container,
                   metric_pci,
                   metric_rnti,
                   metric_cqi,
                   metric_dl_ri,
                   metric_ul_ri,
                   metric_dl_mcs,
                   metric_dl_brate,
                   metric_dl_nof_ok,
                   metric_dl_nof_nok,
                   metric_dl_bs,
                   metric_pusch_snr_db,
                   metric_pucch_snr_db,
                   metric_ta_ns,
                   metric_pusch_ta_ns,
                   metric_pucch_ta_ns,
                   metric_srs_ta_ns,
                   metric_ul_mcs,
                   metric_ul_brate,
                   metric_ul_nof_ok,
                   metric_ul_nof_nok,
                   metric_bsr,
                   metric_nof_pucch_f0f1_invalid_harqs,
                   metric_nof_pucch_f2f3f4_invalid_harqs,
                   metric_nof_pucch_f2f3f4_invalid_csis,
                   metric_nof_pusch_invalid_harqs,
                   metric_nof_pusch_invalid_csis,
                   metric_avg_ce_delay,
                   metric_max_ce_delay,
                   metric_avg_crc_delay,
                   metric_max_crc_delay,
                   metric_avg_pusch_harq_delay,
                   metric_max_pusch_harq_delay,
                   metric_avg_pucch_harq_delay,
                   metric_max_pucch_harq_delay);

// Cell event metrics.
DECLARE_METRIC("sfn", metric_sfn, uint16_t, "");
DECLARE_METRIC("slot_index", metric_slot_index, uint16_t, "");
DECLARE_METRIC("event_type", metric_event_type, std::string, "");
DECLARE_METRIC_SET("cell_events", mset_cell_event, metric_sfn, metric_slot_index, metric_rnti, metric_event_type);

/// cell-wide metrics.
DECLARE_METRIC("error_indication_count", metric_error_indication_count, unsigned, "");
DECLARE_METRIC("average_latency", metric_average_latency, unsigned, "");
DECLARE_METRIC("latency_histogram", latency_histogram, std::vector<unsigned>, "");
DECLARE_METRIC_SET("cell_metrics",
                   cell_metrics,
                   metric_error_indication_count,
                   metric_average_latency,
                   latency_histogram);

/// Metrics root object.
DECLARE_METRIC("timestamp", metric_timestamp_tag, double, "");
DECLARE_METRIC_LIST("ue_list", mlist_ues, std::vector<mset_ue_container>);
DECLARE_METRIC_LIST("event_list", mlist_events, std::vector<mset_cell_event>);

/// Metrics context.
using metric_context_t = srslog::build_context_type<metric_timestamp_tag, cell_metrics, mlist_ues, mlist_events>;

} // namespace

static void print_header()
{
  fmt::print("\n");
  fmt::print(
      "          "
      "|--------------------DL---------------------|-------------------------UL----------------------------------\n");
  fmt::print(" pci rnti | cqi  ri  mcs  brate   ok  nok  (%)  dl_bs | pusch  rsrp  ri  mcs  brate   ok  nok  (%)    "
             "bsr     ta  phr\n");
}

static const char* event_to_string(scheduler_cell_event::event_type ev)
{
  switch (ev) {
    case scheduler_cell_event::event_type::ue_add:
      return "ue_create";
    case scheduler_cell_event::event_type::ue_reconf:
      return "ue_reconf";
    case scheduler_cell_event::event_type::ue_rem:
      return "ue_rem";
    default:
      break;
  }
  return "invalid";
}

void scheduler_cell_metrics_consumer_stdout::handle_metric(const app_services::metrics_set& metric)
{
  if (!print_metrics) {
    return;
  }

  const scheduler_cell_metrics& metrics = static_cast<const scheduler_cell_metrics_impl&>(metric).get_metrics();

  if (metrics.ue_metrics.size() > 10) {
    print_header();
  } else if (++nof_lines > 10 && !metrics.ue_metrics.empty()) {
    nof_lines = 0;
    print_header();
  }

  for (const auto& ue : metrics.ue_metrics) {
    fmt::print("{:>4}", ue.pci);
    fmt::print("{:>5x}", to_value(ue.rnti));

    if (ue.cqi_stats.get_nof_observations() > 0) {
      fmt::print(" | {:>3}", static_cast<unsigned>(std::roundf(ue.cqi_stats.get_mean())));
    } else {
      fmt::print(" | {:>3.3}", "n/a");
    }

    if (ue.dl_ri_stats.get_nof_observations() > 0) {
      fmt::print(" {:>3.1f}", ue.dl_ri_stats.get_mean());
    } else {
      fmt::print(" {:>3}", "n/a");
    }

    fmt::print("   {:>2}", int(ue.dl_mcs.to_uint()));
    if (ue.dl_brate_kbps > 0) {
      fmt::print(" {:>6.6}", float_to_eng_string(ue.dl_brate_kbps * 1e3, 1, true));
    } else {
      fmt::print(" {:>6}", 0);
    }
    fmt::print(" {:>4}", ue.dl_nof_ok);
    fmt::print(" {:>4}", ue.dl_nof_nok);
    unsigned dl_total = ue.dl_nof_ok + ue.dl_nof_nok;
    if (dl_total > 0) {
      fmt::print(" {:>3}%", int((float)100 * ue.dl_nof_nok / dl_total));
    } else {
      fmt::print(" {:>3}%", 0);
    }
    fmt::print(" {}", scaled_fmt_integer(ue.dl_bs, true));

    fmt::print(" |");

    if (!std::isnan(ue.pusch_snr_db) && !iszero(ue.pusch_snr_db)) {
      fmt::print(" {:>5.1f}", std::clamp(ue.pusch_snr_db, -99.9f, 99.9f));
    } else {
      fmt::print(" {:>5.5}", "n/a");
    }

    if (!std::isinf(ue.pusch_rsrp_db) && !std::isnan(ue.pusch_rsrp_db)) {
      if (ue.pusch_rsrp_db >= 0.0F) {
        fmt::print(" {:>5.5}", "ovl");
      } else {
        fmt::print(" {:>5.1f}", std::clamp(ue.pusch_rsrp_db, -99.9F, 0.0F));
      }
    } else {
      fmt::print(" {:>5.5}", "n/a");
    }

    if (ue.ul_ri_stats.get_nof_observations() > 0) {
      fmt::print(" {:>3.1f}", ue.ul_ri_stats.get_mean());
    } else {
      fmt::print(" {:>3}", "n/a");
    }

    fmt::print("   {:>2}", ue.ul_mcs.to_uint());
    if (ue.ul_brate_kbps > 0) {
      fmt::print(" {:>6.6}", float_to_eng_string(ue.ul_brate_kbps * 1e3, 1, true));
    } else {
      fmt::print(" {:>6}", 0);
    }
    fmt::print(" {:>4}", ue.ul_nof_ok);
    fmt::print(" {:>4}", ue.ul_nof_nok);

    unsigned ul_total = ue.ul_nof_ok + ue.ul_nof_nok;
    if (ul_total > 0) {
      fmt::print(" {:>3}%", int((float)100 * ue.ul_nof_nok / ul_total));
    } else {
      fmt::print(" {:>3}%", 0);
    }
    fmt::print(" {}", scaled_fmt_integer(ue.bsr, true));
    if (ue.srs_ta_stats.get_nof_observations() > 0) {
      fmt::print(" {}", float_to_eng_string(ue.srs_ta_stats.get_mean(), 0, true));
    } else if (ue.pusch_ta_stats.get_nof_observations() > 0) {
      fmt::print(" {}", float_to_eng_string(ue.pusch_ta_stats.get_mean(), 0, true));
    } else if (ue.pucch_ta_stats.get_nof_observations() > 0) {
      fmt::print(" {}", float_to_eng_string(ue.pucch_ta_stats.get_mean(), 0, true));
    } else {
      fmt::print("   n/a");
    }
    if (ue.last_phr.has_value()) {
      fmt::print(" {:>4}", ue.last_phr.value());
    } else {
      fmt::print("  n/a");
    }

    fmt::print("\n");
  }
}

/// Returns the current time in seconds with ms precision since UNIX epoch.
static double get_time_stamp()
{
  auto tp = std::chrono::system_clock::now().time_since_epoch();
  return std::chrono::duration_cast<std::chrono::milliseconds>(tp).count() * 1e-3;
}

void scheduler_cell_metrics_consumer_json::handle_metric(const app_services::metrics_set& metric)
{
  const scheduler_cell_metrics& metrics = static_cast<const scheduler_cell_metrics_impl&>(metric).get_metrics();

  metric_context_t ctx("JSON Metrics");

  for (const auto& ue : metrics.ue_metrics) {
    ctx.get<mlist_ues>().emplace_back();
    auto& output = ctx.get<mlist_ues>().back();

    output.write<metric_pci>(ue.pci);
    output.write<metric_rnti>(to_value(ue.rnti));
    if (ue.cqi_stats.get_nof_observations() > 0) {
      output.write<metric_cqi>(static_cast<uint8_t>(std::roundf(ue.cqi_stats.get_mean())));
    }
    if (ue.dl_ri_stats.get_nof_observations() > 0) {
      output.write<metric_dl_ri>(ue.dl_ri_stats.get_mean());
    }
    if (ue.ul_ri_stats.get_nof_observations() > 0) {
      output.write<metric_ul_ri>(ue.ul_ri_stats.get_mean());
    }
    output.write<metric_dl_mcs>(ue.dl_mcs.to_uint());
    output.write<metric_dl_brate>(ue.dl_brate_kbps * 1e3);
    output.write<metric_dl_nof_ok>(ue.dl_nof_ok);
    output.write<metric_dl_nof_nok>(ue.dl_nof_nok);
    output.write<metric_dl_bs>(ue.dl_bs);
    output.write<metric_nof_pucch_f0f1_invalid_harqs>(ue.nof_pucch_f0f1_invalid_harqs);
    output.write<metric_nof_pucch_f2f3f4_invalid_harqs>(ue.nof_pucch_f2f3f4_invalid_harqs);
    output.write<metric_nof_pucch_f2f3f4_invalid_csis>(ue.nof_pucch_f2f3f4_invalid_csis);
    output.write<metric_nof_pusch_invalid_harqs>(ue.nof_pusch_invalid_harqs);
    output.write<metric_nof_pusch_invalid_csis>(ue.nof_pusch_invalid_csis);
    if (!std::isnan(ue.pusch_snr_db) && !iszero(ue.pusch_snr_db)) {
      output.write<metric_pusch_snr_db>(std::clamp(ue.pusch_snr_db, -99.9f, 99.9f));
    }
    if (!std::isnan(ue.pucch_snr_db) && !iszero(ue.pucch_snr_db)) {
      output.write<metric_pucch_snr_db>(std::clamp(ue.pucch_snr_db, -99.9f, 99.9f));
    }
    output.write<metric_ta_ns>((ue.ta_stats.get_nof_observations() > 0) ? std::to_string(ue.ta_stats.get_mean() * 1e9)
                                                                        : "n/a");
    output.write<metric_pusch_ta_ns>(
        (ue.pusch_ta_stats.get_nof_observations() > 0) ? std::to_string(ue.pusch_ta_stats.get_mean() * 1e9) : "n/a");
    output.write<metric_pucch_ta_ns>(
        (ue.pucch_ta_stats.get_nof_observations() > 0) ? std::to_string(ue.pucch_ta_stats.get_mean() * 1e9) : "n/a");
    output.write<metric_srs_ta_ns>(
        (ue.srs_ta_stats.get_nof_observations() > 0) ? std::to_string(ue.srs_ta_stats.get_mean() * 1e9) : "n/a");
    output.write<metric_ul_mcs>(ue.ul_mcs.to_uint());
    output.write<metric_ul_brate>(ue.ul_brate_kbps * 1e3);
    output.write<metric_ul_nof_ok>(ue.ul_nof_ok);
    output.write<metric_ul_nof_nok>(ue.ul_nof_nok);
    output.write<metric_bsr>(ue.bsr);

    output.write<metric_avg_ce_delay>(ue.avg_ce_delay_ms.value_or(0.0f));
    output.write<metric_max_ce_delay>(ue.max_ce_delay_ms.value_or(0.0f));
    output.write<metric_avg_crc_delay>(ue.avg_crc_delay_ms.value_or(0.0f));
    output.write<metric_max_crc_delay>(ue.max_crc_delay_ms.value_or(0.0f));
    output.write<metric_avg_pusch_harq_delay>(ue.avg_pusch_harq_delay_ms.value_or(0.0f));
    output.write<metric_max_pusch_harq_delay>(ue.max_pusch_harq_delay_ms.value_or(0.0f));
    output.write<metric_avg_pucch_harq_delay>(ue.avg_pucch_harq_delay_ms.value_or(0.0f));
    output.write<metric_max_pucch_harq_delay>(ue.max_pucch_harq_delay_ms.value_or(0.0f));
  }

  for (const auto& event : metrics.events) {
    ctx.get<mlist_events>().emplace_back();
    auto& output = ctx.get<mlist_events>().back();

    output.write<metric_sfn>(event.slot.sfn());
    output.write<metric_slot_index>(event.slot.slot_index());
    output.write<metric_rnti>(to_value(event.rnti));
    output.write<metric_event_type>(event_to_string(event.type));
  }

  auto& cell_output = ctx.get<cell_metrics>();
  cell_output.write<metric_error_indication_count>(metrics.nof_error_indications);
  cell_output.write<metric_average_latency>(metrics.average_decision_latency.count());
  cell_output.write<latency_histogram>(
      std::vector<unsigned>(metrics.latency_histogram.begin(), metrics.latency_histogram.end()));

  // Log the context.
  ctx.write<metric_timestamp_tag>(get_time_stamp());
  log_chan(ctx);
}

template <typename ResultType>
static ResultType to_percentage(unsigned numerator, unsigned denominator)
{
  return static_cast<ResultType>(100.0 * static_cast<double>(numerator) / static_cast<double>(denominator));
}

void scheduler_cell_metrics_consumer_log::handle_metric(const app_services::metrics_set& metric)
{
  const scheduler_cell_metrics& metrics = static_cast<const scheduler_cell_metrics_impl&>(metric).get_metrics();

  fmt::memory_buffer buffer;

  unsigned sum_dl_bitrate_kbps = 0;
  unsigned sum_ul_bitrate_kbps = 0;
  for (const auto& ue : metrics.ue_metrics) {
    sum_dl_bitrate_kbps += ue.dl_brate_kbps;
    sum_ul_bitrate_kbps += ue.ul_brate_kbps;
  }

  // log cell-wide metrics
  fmt::format_to(std::back_inserter(buffer), "Cell Scheduler Metrics:");
  fmt::format_to(
      std::back_inserter(buffer),
      " total_dl_brate={}bps total_ul_brate={}bps nof_prbs={} nof_dl_slots={} nof_ul_slots={} error_indications={} "
      "mean_latency={}usec latency_hist=[{}]",
      float_to_eng_string(sum_dl_bitrate_kbps * 1e3, 1, false),
      float_to_eng_string(sum_ul_bitrate_kbps * 1e3, 1, false),
      metrics.nof_prbs,
      metrics.nof_dl_slots,
      metrics.nof_ul_slots,
      metrics.nof_error_indications,
      metrics.average_decision_latency.count(),
      fmt::join(metrics.latency_histogram.begin(), metrics.latency_histogram.end(), ", "));
  if (not metrics.events.empty()) {
    fmt::format_to(std::back_inserter(buffer), " events=[");
    bool first = true;
    for (const auto& event : metrics.events) {
      fmt::format_to(std::back_inserter(buffer),
                     "{}{{rnti={} slot={} type={}}}",
                     first ? "" : ", ",
                     event.rnti,
                     event.slot,
                     event_to_string(event.type));
      first = false;
    }
    fmt::format_to(std::back_inserter(buffer), "]");
  }
  log_chan("{}", to_c_str(buffer));
  buffer.clear();

  // log ue-specific metrics
  for (const auto& ue : metrics.ue_metrics) {
    fmt::format_to(std::back_inserter(buffer), "Scheduler UE Metrics:");
    fmt::format_to(std::back_inserter(buffer), " pci={}", ue.pci);
    fmt::format_to(std::back_inserter(buffer), " rnti={:x}", to_value(ue.rnti));
    if (ue.cqi_stats.get_nof_observations() > 0) {
      fmt::format_to(
          std::back_inserter(buffer), " cqi={}", static_cast<unsigned>(std::roundf(ue.cqi_stats.get_mean())));
    } else {
      fmt::format_to(std::back_inserter(buffer), " cqi=n/a");
    }

    if (ue.dl_ri_stats.get_nof_observations() > 0) {
      fmt::format_to(std::back_inserter(buffer), " dl_ri={:.1f}", ue.dl_ri_stats.get_mean());
    } else {
      fmt::format_to(std::back_inserter(buffer), " dl_ri=n/a");
    }

    fmt::format_to(std::back_inserter(buffer), " dl_mcs={}", int(ue.dl_mcs.to_uint()));
    if (ue.dl_brate_kbps > 0) {
      fmt::format_to(
          std::back_inserter(buffer), " dl_brate={}bps", float_to_eng_string(ue.dl_brate_kbps * 1e3, 1, false));
    } else {
      fmt::format_to(std::back_inserter(buffer), " dl_brate={}bps", 0);
    }
    fmt::format_to(std::back_inserter(buffer), " dl_nof_ok={}", ue.dl_nof_ok);
    fmt::format_to(std::back_inserter(buffer), " dl_nof_nok={}", ue.dl_nof_nok);
    unsigned dl_total = ue.dl_nof_ok + ue.dl_nof_nok;
    fmt::format_to(std::back_inserter(buffer),
                   " dl_error_rate={}%",
                   dl_total > 0 ? to_percentage<int>(ue.dl_nof_nok, dl_total) : 0);
    fmt::format_to(std::back_inserter(buffer), " dl_bs={}", scaled_fmt_integer(ue.dl_bs, false));
    fmt::format_to(std::back_inserter(buffer), " dl_nof_prbs={}", ue.tot_dl_prbs_used);
    if (ue.last_dl_olla.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " dl_olla={}", ue.last_dl_olla);
    }

    if (!std::isnan(ue.pusch_snr_db) && !iszero(ue.pusch_snr_db)) {
      fmt::format_to(std::back_inserter(buffer), " pusch_snr_db={:.1f}", std::clamp(ue.pusch_snr_db, -99.9f, 99.9f));
    } else {
      fmt::format_to(std::back_inserter(buffer), " pusch_snr_db=n/a");
    }

    if (!std::isinf(ue.pusch_rsrp_db) && !std::isnan(ue.pusch_rsrp_db)) {
      if (ue.pusch_rsrp_db >= 0.0F) {
        fmt::format_to(std::back_inserter(buffer), " pusch_rsrp_db=ovl");
      } else {
        fmt::format_to(std::back_inserter(buffer), " pusch_rsrp_db={:.1f}", std::clamp(ue.pusch_rsrp_db, -99.9F, 0.0F));
      }
    } else {
      fmt::format_to(std::back_inserter(buffer), " pusch_rsrp_db=n/a");
    }

    if (ue.ul_ri_stats.get_nof_observations() > 0) {
      fmt::format_to(std::back_inserter(buffer), " ul_ri={:.1f}", ue.ul_ri_stats.get_mean());
    } else {
      fmt::format_to(std::back_inserter(buffer), " ul_ri=n/a");
    }

    fmt::format_to(std::back_inserter(buffer), " ul_mcs={}", ue.ul_mcs.to_uint());
    if (ue.ul_brate_kbps > 0) {
      fmt::format_to(
          std::back_inserter(buffer), " ul_brate={}bps", float_to_eng_string(ue.ul_brate_kbps * 1e3, 1, false));
    } else {
      fmt::format_to(std::back_inserter(buffer), " ul_brate={}bps", 0);
    }
    fmt::format_to(std::back_inserter(buffer), " ul_nof_ok={}", ue.ul_nof_ok);
    fmt::format_to(std::back_inserter(buffer), " ul_nof_nok={}", ue.ul_nof_nok);

    unsigned ul_total = ue.ul_nof_ok + ue.ul_nof_nok;
    fmt::format_to(std::back_inserter(buffer),
                   " ul_error_rate={}%",
                   ul_total > 0 ? to_percentage<int>(ue.ul_nof_nok, ul_total) : 0);
    if (ul_total > 0) {
      fmt::format_to(std::back_inserter(buffer), " avg_crc_delay={:.3}ms", ue.avg_crc_delay_ms);
    } else {
      fmt::format_to(std::back_inserter(buffer), " avg_crc_delay=n/a");
    }
    fmt::format_to(std::back_inserter(buffer), " ul_nof_prbs={}", ue.tot_ul_prbs_used);
    fmt::format_to(std::back_inserter(buffer), " bsr={}", scaled_fmt_integer(ue.bsr, false));
    fmt::format_to(std::back_inserter(buffer), " sr_count={}", ue.sr_count);
    fmt::format_to(std::back_inserter(buffer), " f0f1_invalid_harqs={}", ue.nof_pucch_f0f1_invalid_harqs);
    fmt::format_to(std::back_inserter(buffer), " f2f3f4_invalid_harqs={}", ue.nof_pucch_f2f3f4_invalid_harqs);
    fmt::format_to(std::back_inserter(buffer), " f2f3f4_invalid_csis={}", ue.nof_pucch_f2f3f4_invalid_csis);
    fmt::format_to(std::back_inserter(buffer), " pusch_invalid_harqs={}", ue.nof_pusch_invalid_harqs);
    fmt::format_to(std::back_inserter(buffer), " pusch_invalid_csis={}", ue.nof_pusch_invalid_csis);
    if (ue.last_ul_olla.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " ul_olla={}", ue.last_ul_olla.value());
    }
    if (ue.ta_stats.get_nof_observations() > 0) {
      fmt::format_to(std::back_inserter(buffer), " ta={}s", float_to_eng_string(ue.ta_stats.get_mean(), 0, false));
    } else {
      fmt::format_to(std::back_inserter(buffer), " ta=n/a");
    }
    if (ue.srs_ta_stats.get_nof_observations() > 0) {
      fmt::format_to(
          std::back_inserter(buffer), " srs_ta={}s", float_to_eng_string(ue.srs_ta_stats.get_mean(), 0, false));
    } else {
      fmt::format_to(std::back_inserter(buffer), " srs_ta=n/a");
    }
    if (ue.last_phr.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " last_phr={}", ue.last_phr.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " last_phr=n/a");
    }
    if (ue.avg_ce_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " avg_ul_ce_delay={:.2}ms", ue.avg_ce_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " avg_ul_ce_delay=n/a");
    }
    if (ue.max_ce_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " max_ul_ce_delay={:.2}ms", ue.max_ce_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " max_ul_ce_delay=n/a");
    }
    if (ue.avg_crc_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " avg_crc_delay={:.2}ms", ue.avg_crc_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " avg_crc_delay=n/a");
    }
    if (ue.max_crc_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " max_crc_delay={:.2}ms", ue.max_crc_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " max_crc_delay=n/a");
    }
    if (ue.avg_pusch_harq_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " avg_pusch_harq_delay={:.2}ms", ue.avg_pusch_harq_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " avg_pusch_harq_delay=n/a");
    }
    if (ue.max_pusch_harq_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " max_pusch_harq_delay={:.2}ms", ue.max_pusch_harq_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " max_pusch_harq_delay=n/a");
    }
    if (ue.avg_pucch_harq_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " avg_pucch_harq_delay={:.2}ms", ue.avg_pucch_harq_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " avg_pucch_harq_delay=n/a");
    }
    if (ue.max_pucch_harq_delay_ms.has_value()) {
      fmt::format_to(std::back_inserter(buffer), " max_pucch_harq_delay={:.2}ms", ue.max_pucch_harq_delay_ms.value());
    } else {
      fmt::format_to(std::back_inserter(buffer), " max_pucch_harq_delay=n/a");
    }

    log_chan("{}", to_c_str(buffer));
    buffer.clear();
  }
}

void scheduler_cell_metrics_consumer_e2::handle_metric(const app_services::metrics_set& metric)
{
  notifier.report_metrics(static_cast<const scheduler_cell_metrics_impl&>(metric).get_metrics());
}
