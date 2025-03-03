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

#include "cu_appconfig_cli11_schema.h"
#include "apps/helpers/metrics/metrics_config_cli11_schema.h"
#include "apps/services/buffer_pool/buffer_pool_appconfig_cli11_schema.h"
#include "apps/services/logger/logger_appconfig_cli11_schema.h"
#include "apps/services/remote_control/remote_control_appconfig_cli11_schema.h"
#include "apps/services/worker_manager/worker_manager_cli11_schema.h"
#include "cu_appconfig.h"
#include "srsran/support/cli11_utils.h"

using namespace srsran;

static void configure_cli11_f1ap_args(CLI::App& app, srs_cu::cu_f1ap_appconfig& f1ap_params)
{
  add_option(app, "--bind_addr", f1ap_params.bind_addr, "F1-C bind address")->capture_default_str();
}

static void configure_cli11_metrics_args(CLI::App& app, srs_cu::metrics_appconfig& metrics_params)
{
  add_option(app,
             "--resource_usage_report_period",
             metrics_params.rusage_report_period,
             "Resource usage metrics report period (in milliseconds)")
      ->capture_default_str();
}

void srsran::configure_cli11_with_cu_appconfig_schema(CLI::App& app, cu_appconfig& cu_cfg)
{
  // Logging section.
  configure_cli11_with_logger_appconfig_schema(app, cu_cfg.log_cfg);

  // Buffer pool section.
  configure_cli11_with_buffer_pool_appconfig_schema(app, cu_cfg.buffer_pool_config);

  // Expert execution section.
  configure_cli11_with_worker_manager_appconfig_schema(app, cu_cfg.expert_execution_cfg);

  // Remote control section.
  configure_cli11_with_remote_control_appconfig_schema(app, cu_cfg.remote_control_config);

  // Metrics section.
  CLI::App* metrics_subcmd = add_subcommand(app, "metrics", "Metrics configuration")->configurable();
  configure_cli11_metrics_args(*metrics_subcmd, cu_cfg.metrics_cfg);
  app_helpers::configure_cli11_with_metrics_appconfig_schema(app, cu_cfg.metrics_cfg.common_metrics_cfg);

  // F1AP section.
  CLI::App* cu_cp_subcmd = add_subcommand(app, "cu_cp", "CU-UP parameters")->configurable();
  CLI::App* f1ap_subcmd  = add_subcommand(*cu_cp_subcmd, "f1ap", "F1AP parameters")->configurable();
  configure_cli11_f1ap_args(*f1ap_subcmd, cu_cfg.f1ap_cfg);

  // NR-U section.
  CLI::App* cu_up_subcmd = add_subcommand(app, "cu_up", "CU-UP parameters")->configurable();
  CLI::App* f1u_subcmd   = add_subcommand(*cu_up_subcmd, "f1u", "F1-U parameters")->configurable();
  configure_cli11_f1u_sockets_args(*f1u_subcmd, cu_cfg.f1u_cfg);
}
