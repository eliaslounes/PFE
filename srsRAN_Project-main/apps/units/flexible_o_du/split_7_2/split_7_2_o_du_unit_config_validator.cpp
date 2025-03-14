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

#include "split_7_2_o_du_unit_config_validator.h"
#include "apps/units/flexible_o_du/o_du_high/o_du_high_unit_config_validator.h"
#include "apps/units/flexible_o_du/o_du_low/du_low_config_validator.h"
#include "apps/units/flexible_o_du/split_7_2/helpers/ru_ofh_config_validator.h"
#include "srsran/ran/prach/prach_configuration.h"
#include "srsran/ran/prach/prach_preamble_information.h"

using namespace srsran;

static std::vector<du_low_prach_validation_config> get_du_low_validation_dependencies(const du_high_unit_config& config)
{
  std::vector<du_low_prach_validation_config> out_cfg(config.cells_cfg.size());

  for (unsigned i = 0, e = config.cells_cfg.size(); i != e; ++i) {
    du_low_prach_validation_config&      out_cell = out_cfg[i];
    const du_high_unit_base_cell_config& in_cell  = config.cells_cfg[i].cell;

    // Get PRACH info.
    subcarrier_spacing  common_scs = in_cell.common_scs;
    prach_configuration prach_info = prach_configuration_get(frequency_range::FR1,
                                                             band_helper::get_duplex_mode(in_cell.band.value()),
                                                             in_cell.prach_cfg.prach_config_index.value());

    // PRACH format type.
    out_cell.format = prach_info.format;

    // Get preamble info.
    prach_preamble_information preamble_info =
        is_long_preamble(prach_info.format)
            ? get_prach_preamble_long_info(prach_info.format)
            : get_prach_preamble_short_info(prach_info.format, to_ra_subcarrier_spacing(common_scs), false);

    out_cell.prach_scs             = preamble_info.scs;
    out_cell.zero_correlation_zone = in_cell.prach_cfg.zero_correlation_zone;
    out_cell.nof_prach_ports       = in_cell.prach_cfg.ports.size();
    out_cell.nof_antennas_ul       = in_cell.nof_antennas_ul;
  }

  return out_cfg;
}

static std::vector<ru_ofh_cell_validation_config> get_ru_ofh_validation_dependencies(const du_high_unit_config& config)
{
  std::vector<ru_ofh_cell_validation_config> out_cfg(config.cells_cfg.size());

  for (unsigned i = 0, e = config.cells_cfg.size(); i != e; ++i) {
    ru_ofh_cell_validation_config&       out_cell = out_cfg[i];
    const du_high_unit_base_cell_config& in_cell  = config.cells_cfg[i].cell;

    // Validates the sampling rate is compatible with the PRACH sequence.
    out_cell.scs             = in_cell.common_scs;
    out_cell.nof_prach_ports = in_cell.prach_cfg.ports.size();
    out_cell.nof_antennas_dl = in_cell.nof_antennas_dl;
    out_cell.nof_antennas_ul = in_cell.nof_antennas_ul;
  }

  return out_cfg;
}

bool srsran::validate_split_7_2_o_du_unit_config(const split_7_2_o_du_unit_config& config,
                                                 const os_sched_affinity_bitmask&  available_cpus)
{
  if (!validate_o_du_high_config(config.odu_high_cfg, available_cpus)) {
    return false;
  }

  auto du_low_dependencies = get_du_low_validation_dependencies(config.odu_high_cfg.du_high_cfg.config);
  if (!validate_du_low_config(config.du_low_cfg, du_low_dependencies, available_cpus)) {
    return false;
  }

  auto ru_ofh_dependencies = get_ru_ofh_validation_dependencies(config.odu_high_cfg.du_high_cfg.config);
  return validate_ru_ofh_config(config.ru_cfg.config, ru_ofh_dependencies, available_cpus);
}
