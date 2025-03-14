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

#include "srsran/adt/slotted_array.h"
#include "srsran/f1ap/du/f1ap_du.h"
#include "srsran/ran/gnb_du_id.h"

namespace srsran {
namespace srs_du {

struct f1ap_du_cell_context {
  nr_cell_global_id_t nr_cgi;
};

/// DU Context stored in the F1AP-DU. It includes information about the DU serving cells.
struct f1ap_du_context {
  gnb_du_id_t                       du_id = gnb_du_id_t::invalid;
  std::string                       gnb_du_name;
  std::vector<f1ap_du_cell_context> served_cells;
};

} // namespace srs_du
} // namespace srsran
