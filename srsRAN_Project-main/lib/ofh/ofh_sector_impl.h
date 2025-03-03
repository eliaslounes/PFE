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

#pragma once

#include "ofh_metrics_collector_impl.h"
#include "ofh_sector_controller.h"
#include "support/prach_context_repository.h"
#include "support/uplink_context_repository.h"
#include "support/uplink_cplane_context_repository.h"
#include "srsran/ofh/ofh_sector.h"
#include "srsran/ofh/receiver/ofh_receiver.h"
#include "srsran/ofh/transmitter/ofh_transmitter.h"

namespace srsran {
namespace ofh {

/// Sector implementation configuration.
struct sector_impl_config {
  unsigned sector_id;
  bool     are_metrics_enabled = false;
};

/// Sector implementation dependencies.
struct sector_impl_dependencies {
  std::unique_ptr<receiver>                         ofh_receiver;
  std::unique_ptr<transmitter>                      ofh_transmitter;
  std::shared_ptr<uplink_cplane_context_repository> cp_repo;
  std::shared_ptr<uplink_cplane_context_repository> cp_prach_repo;
  std::shared_ptr<prach_context_repository>         prach_repo;
  std::shared_ptr<uplink_context_repository>        slot_repo;
};

/// Open Fronthaul sector implementation.
class sector_impl : public sector
{
public:
  sector_impl(const sector_impl_config& config, sector_impl_dependencies&& dependencies) :
    cp_repo(std::move(dependencies.cp_repo)),
    cp_prach_repo(std::move(dependencies.cp_prach_repo)),
    prach_repo(std::move(dependencies.prach_repo)),
    slot_repo(std::move(dependencies.slot_repo)),
    ofh_receiver(std::move(dependencies.ofh_receiver)),
    ofh_transmitter(std::move(dependencies.ofh_transmitter)),
    ofh_sector_controller(*ofh_receiver),
    ofh_metrics_collector(ofh_receiver->get_metrics_collector(), config.are_metrics_enabled, config.sector_id)
  {
    srsran_assert(ofh_receiver, "Invalid Open Fronthaul receiver");
    srsran_assert(ofh_transmitter, "Invalid Open Fronthaul transmitter");
    srsran_assert(cp_repo, "Invalid Control-Plane uplink context repository");
    srsran_assert(cp_prach_repo, "Invalid Control-Plane PRACH context repository");
    srsran_assert(prach_repo, "Invalid PRACH context repository");
    srsran_assert(slot_repo, "Invalid UL slot context repository");
  }

  // See interface for documentation.
  receiver& get_receiver() override;

  // See interface for documentation.
  transmitter& get_transmitter() override;

  // See interface for documentation.
  controller& get_controller() override;

  // See interface for documentation.
  metrics_collector* get_metrics_collector() override;

  // See interface for documentation.
  void set_error_notifier(error_notifier& notifier) override;

private:
  std::shared_ptr<uplink_cplane_context_repository> cp_repo;
  std::shared_ptr<uplink_cplane_context_repository> cp_prach_repo;
  std::shared_ptr<prach_context_repository>         prach_repo;
  std::shared_ptr<uplink_context_repository>        slot_repo;
  std::unique_ptr<receiver>                         ofh_receiver;
  std::unique_ptr<transmitter>                      ofh_transmitter;
  sector_controller                                 ofh_sector_controller;
  metrics_collector_impl                            ofh_metrics_collector;
};

} // namespace ofh
} // namespace srsran
