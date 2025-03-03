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

// This file was generated using the following MATLAB class on 18-02-2025 (seed 0):
//   + "srsPUSCHDemodulatorUnittest.m"

#include "../../../support/resource_grid_test_doubles.h"
#include "srsran/phy/upper/channel_processors/pusch/pusch_demodulator.h"
#include "srsran/support/file_tensor.h"

namespace srsran {

enum class ch_dims : unsigned { subcarrier = 0, symbol = 1, rx_port = 2, tx_layer = 3, nof_dims = 4 };

struct context_t {
  float                            noise_var;
  float                            sinr_dB;
  pusch_demodulator::configuration config;
};

struct test_case_t {
  context_t                                                            context;
  file_vector<resource_grid_reader_spy::expected_entry_t>              symbols;
  file_tensor<static_cast<unsigned>(ch_dims::nof_dims), cf_t, ch_dims> estimates;
  file_vector<uint8_t>                                                 scrambling_seq;
  file_vector<log_likelihood_ratio>                                    codeword;
};

static const std::vector<test_case_t> pusch_demodulator_test_data = {
    // clang-format off
  {{0.016194, 20.1985, {6393, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 128, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols0.dat"}, {"test_data/pusch_demodulator_test_input_estimates0.dat", {288, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq0.dat"}, {"test_data/pusch_demodulator_test_output0.dat"}},
  {{0.023644, 18.2904, {29714, {{1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 401, 1, true, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols2.dat"}, {"test_data/pusch_demodulator_test_input_estimates2.dat", {96, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq2.dat"}, {"test_data/pusch_demodulator_test_output2.dat"}},
  {{0.01932, 15.3112, {35832, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 881, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols4.dat"}, {"test_data/pusch_demodulator_test_input_estimates4.dat", {144, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq4.dat"}, {"test_data/pusch_demodulator_test_output4.dat"}},
  {{0.0006635, 32.9662, {7320, {{1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 0, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 347, 1, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols6.dat"}, {"test_data/pusch_demodulator_test_input_estimates6.dat", {60, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq6.dat"}, {"test_data/pusch_demodulator_test_output6.dat"}},
  {{0.0022768, 26.4585, {52579, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 1, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 9, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols8.dat"}, {"test_data/pusch_demodulator_test_input_estimates8.dat", {240, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq8.dat"}, {"test_data/pusch_demodulator_test_output8.dat"}},
  {{0.0032429, 22.2412, {55032, {{1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 853, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols10.dat"}, {"test_data/pusch_demodulator_test_input_estimates10.dat", {36, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq10.dat"}, {"test_data/pusch_demodulator_test_output10.dat"}},
  {{0.0031711, 16.7027, {48772, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 0, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 107, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols12.dat"}, {"test_data/pusch_demodulator_test_input_estimates12.dat", {72, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq12.dat"}, {"test_data/pusch_demodulator_test_output12.dat"}},
  {{0.10174, 11.9761, {8406, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 0, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 635, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols14.dat"}, {"test_data/pusch_demodulator_test_input_estimates14.dat", {300, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq14.dat"}, {"test_data/pusch_demodulator_test_output14.dat"}},
  {{0.019558, 19.1405, {45362, {{1, 1}}, modulation_scheme::QPSK, 0, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 576, 1, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols16.dat"}, {"test_data/pusch_demodulator_test_input_estimates16.dat", {24, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq16.dat"}, {"test_data/pusch_demodulator_test_output16.dat"}},
  {{0.00086413, 26.3568, {59300, {1}, modulation_scheme::QPSK, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 206, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols18.dat"}, {"test_data/pusch_demodulator_test_input_estimates18.dat", {12, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq18.dat"}, {"test_data/pusch_demodulator_test_output18.dat"}},
  {{0.00032864, 35.9245, {24060, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 1, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 479, 1, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols20.dat"}, {"test_data/pusch_demodulator_test_input_estimates20.dat", {72, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq20.dat"}, {"test_data/pusch_demodulator_test_output20.dat"}},
  {{0.0014541, 28.9384, {6827, {{1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 1, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 463, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols22.dat"}, {"test_data/pusch_demodulator_test_input_estimates22.dat", {96, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq22.dat"}, {"test_data/pusch_demodulator_test_output22.dat"}},
  {{0.00091283, 28.1383, {39604, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 1, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 343, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols24.dat"}, {"test_data/pusch_demodulator_test_input_estimates24.dat", {216, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq24.dat"}, {"test_data/pusch_demodulator_test_output24.dat"}},
  {{0.00062096, 23.5379, {44589, {{1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 0, 10, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 993, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols26.dat"}, {"test_data/pusch_demodulator_test_input_estimates26.dat", {96, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq26.dat"}, {"test_data/pusch_demodulator_test_output26.dat"}},
  {{0.002672, 28.2565, {61522, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 905, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols28.dat"}, {"test_data/pusch_demodulator_test_input_estimates28.dat", {180, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq28.dat"}, {"test_data/pusch_demodulator_test_output28.dat"}},
  {{0.0075241, 21.7121, {21526, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 1, 367, 1, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols30.dat"}, {"test_data/pusch_demodulator_test_input_estimates30.dat", {216, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq30.dat"}, {"test_data/pusch_demodulator_test_output30.dat"}},
  {{0.0037903, 22.4597, {52193, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 8, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 852, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols32.dat"}, {"test_data/pusch_demodulator_test_input_estimates32.dat", {180, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq32.dat"}, {"test_data/pusch_demodulator_test_output32.dat"}},
  {{0.0010853, 30.9739, {44058, {1}, modulation_scheme::QAM16, 0, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 76, 1, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols34.dat"}, {"test_data/pusch_demodulator_test_input_estimates34.dat", {12, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq34.dat"}, {"test_data/pusch_demodulator_test_output34.dat"}},
  {{0.035577, 14.2392, {28310, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 2, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 542, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols36.dat"}, {"test_data/pusch_demodulator_test_input_estimates36.dat", {288, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq36.dat"}, {"test_data/pusch_demodulator_test_output36.dat"}},
  {{0.0006507, 29.9321, {47493, {{1, 1}}, modulation_scheme::QAM16, 0, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 147, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols38.dat"}, {"test_data/pusch_demodulator_test_input_estimates38.dat", {24, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq38.dat"}, {"test_data/pusch_demodulator_test_output38.dat"}},
  {{0.01549, 9.8148, {35301, {{1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 0, 9, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 465, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols40.dat"}, {"test_data/pusch_demodulator_test_input_estimates40.dat", {108, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq40.dat"}, {"test_data/pusch_demodulator_test_output40.dat"}},
  {{0.052613, 15.2653, {55220, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 7, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 415, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols42.dat"}, {"test_data/pusch_demodulator_test_input_estimates42.dat", {216, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq42.dat"}, {"test_data/pusch_demodulator_test_output42.dat"}},
  {{0.0038745, 26.128, {33746, {1}, modulation_scheme::QAM64, 0, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 62, 1, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols44.dat"}, {"test_data/pusch_demodulator_test_input_estimates44.dat", {12, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq44.dat"}, {"test_data/pusch_demodulator_test_output44.dat"}},
  {{0.0053494, 16.8746, {8771, {{1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 574, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols46.dat"}, {"test_data/pusch_demodulator_test_input_estimates46.dat", {48, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq46.dat"}, {"test_data/pusch_demodulator_test_output46.dat"}},
  {{0.0011777, 29.7064, {57804, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 0, 7, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 694, 1, true, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols48.dat"}, {"test_data/pusch_demodulator_test_input_estimates48.dat", {240, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq48.dat"}, {"test_data/pusch_demodulator_test_output48.dat"}},
  {{0.0036469, 24.7086, {9508, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 142, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols50.dat"}, {"test_data/pusch_demodulator_test_input_estimates50.dat", {192, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq50.dat"}, {"test_data/pusch_demodulator_test_output50.dat"}},
  {{0.007921, 19.3937, {4208, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 762, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols52.dat"}, {"test_data/pusch_demodulator_test_input_estimates52.dat", {72, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq52.dat"}, {"test_data/pusch_demodulator_test_output52.dat"}},
  {{0.010246, 15.4014, {49425, {{1, 1}}, modulation_scheme::QAM64, 2, 8, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 605, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols54.dat"}, {"test_data/pusch_demodulator_test_input_estimates54.dat", {24, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq54.dat"}, {"test_data/pusch_demodulator_test_output54.dat"}},
  {{0.13566, 11.2196, {47713, {{1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 1, 8, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 713, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols56.dat"}, {"test_data/pusch_demodulator_test_input_estimates56.dat", {108, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq56.dat"}, {"test_data/pusch_demodulator_test_output56.dat"}},
  {{0.0036188, 26.4368, {31604, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 2, 7, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 671, 1, true, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols58.dat"}, {"test_data/pusch_demodulator_test_input_estimates58.dat", {120, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq58.dat"}, {"test_data/pusch_demodulator_test_output58.dat"}},
  {{0.0092616, 18.5347, {31441, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 1, 8, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 1, 922, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols60.dat"}, {"test_data/pusch_demodulator_test_input_estimates60.dat", {288, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq60.dat"}, {"test_data/pusch_demodulator_test_output60.dat"}},
  {{0.0010516, 30.9987, {28149, {{1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 0, 14, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 707, 1, true, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols62.dat"}, {"test_data/pusch_demodulator_test_input_estimates62.dat", {60, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq62.dat"}, {"test_data/pusch_demodulator_test_output62.dat"}},
  {{0.0014622, 28.7336, {37021, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 0, 12, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 353, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols64.dat"}, {"test_data/pusch_demodulator_test_input_estimates64.dat", {120, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq64.dat"}, {"test_data/pusch_demodulator_test_output64.dat"}},
  {{0.0028691, 24.0366, {43082, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 0, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 599, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols66.dat"}, {"test_data/pusch_demodulator_test_input_estimates66.dat", {300, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq66.dat"}, {"test_data/pusch_demodulator_test_output66.dat"}},
  {{0.018941, 3.114, {38879, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 0, 12, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 532, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols68.dat"}, {"test_data/pusch_demodulator_test_input_estimates68.dat", {300, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq68.dat"}, {"test_data/pusch_demodulator_test_output68.dat"}},
  {{0.002115, 29.3288, {57172, {1}, modulation_scheme::PI_2_BPSK, 2, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 759, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols70.dat"}, {"test_data/pusch_demodulator_test_input_estimates70.dat", {12, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq70.dat"}, {"test_data/pusch_demodulator_test_output70.dat"}},
  {{0.038987, 15.9087, {24096, {{1, 1, 1}}, modulation_scheme::PI_2_BPSK, 0, 14, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 552, 1, true, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols72.dat"}, {"test_data/pusch_demodulator_test_input_estimates72.dat", {36, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq72.dat"}, {"test_data/pusch_demodulator_test_output72.dat"}},
  {{0.046418, -1.1535, {26878, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 1, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 75, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols74.dat"}, {"test_data/pusch_demodulator_test_input_estimates74.dat", {288, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq74.dat"}, {"test_data/pusch_demodulator_test_output74.dat"}},
  {{0.00029218, 35.9345, {43372, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 146, 1, true, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols76.dat"}, {"test_data/pusch_demodulator_test_input_estimates76.dat", {288, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq76.dat"}, {"test_data/pusch_demodulator_test_output76.dat"}},
  {{0.028424, 16.1653, {65065, {{1, 1}}, modulation_scheme::PI_2_BPSK, 1, 9, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 384, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols78.dat"}, {"test_data/pusch_demodulator_test_input_estimates78.dat", {24, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq78.dat"}, {"test_data/pusch_demodulator_test_output78.dat"}},
  {{0.0036391, 23.1224, {3055, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 2, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 348, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols80.dat"}, {"test_data/pusch_demodulator_test_input_estimates80.dat", {240, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq80.dat"}, {"test_data/pusch_demodulator_test_output80.dat"}},
  {{0.023365, 6.6463, {34761, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::PI_2_BPSK, 1, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 67, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols82.dat"}, {"test_data/pusch_demodulator_test_input_estimates82.dat", {216, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq82.dat"}, {"test_data/pusch_demodulator_test_output82.dat"}},
  {{0.0021352, 29.2169, {26674, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 810, 1, false, {0}}}, {"test_data/pusch_demodulator_test_input_symbols84.dat"}, {"test_data/pusch_demodulator_test_input_estimates84.dat", {144, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq84.dat"}, {"test_data/pusch_demodulator_test_output84.dat"}},
  {{0.00097027, 31.9605, {61970, {{1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 0, 13, {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 729, 1, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols86.dat"}, {"test_data/pusch_demodulator_test_input_estimates86.dat", {60, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq86.dat"}, {"test_data/pusch_demodulator_test_output86.dat"}},
  {{0.0046318, 18.983, {24489, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 0, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 206, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols88.dat"}, {"test_data/pusch_demodulator_test_input_estimates88.dat", {300, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq88.dat"}, {"test_data/pusch_demodulator_test_output88.dat"}},
  {{0.00034083, 35.8882, {13672, {{1, 1, 1}}, modulation_scheme::QPSK, 0, 7, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 936, 1, true, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols90.dat"}, {"test_data/pusch_demodulator_test_input_estimates90.dat", {36, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq90.dat"}, {"test_data/pusch_demodulator_test_output90.dat"}},
  {{0.00035902, 35.3275, {28219, {{1, 1, 1}}, modulation_scheme::QPSK, 2, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 633, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols92.dat"}, {"test_data/pusch_demodulator_test_input_estimates92.dat", {36, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq92.dat"}, {"test_data/pusch_demodulator_test_output92.dat"}},
  {{0.028944, 12.5068, {40420, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 2, 12, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 778, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols94.dat"}, {"test_data/pusch_demodulator_test_input_estimates94.dat", {192, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq94.dat"}, {"test_data/pusch_demodulator_test_output94.dat"}},
  {{0.0015045, 13.3375, {54798, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QPSK, 2, 11, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 93, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols96.dat"}, {"test_data/pusch_demodulator_test_input_estimates96.dat", {300, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq96.dat"}, {"test_data/pusch_demodulator_test_output96.dat"}},
  {{0.042861, 15.9832, {60312, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 0, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 462, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols98.dat"}, {"test_data/pusch_demodulator_test_input_estimates98.dat", {72, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq98.dat"}, {"test_data/pusch_demodulator_test_output98.dat"}},
  {{0.0019558, 29.1849, {1912, {{1, 1}}, modulation_scheme::QAM16, 1, 11, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 307, 1, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols100.dat"}, {"test_data/pusch_demodulator_test_input_estimates100.dat", {24, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq100.dat"}, {"test_data/pusch_demodulator_test_output100.dat"}},
  {{0.001327, 27.8536, {55065, {{1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 0, 9, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 454, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols102.dat"}, {"test_data/pusch_demodulator_test_input_estimates102.dat", {60, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq102.dat"}, {"test_data/pusch_demodulator_test_output102.dat"}},
  {{0.00060951, 32.8889, {38432, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 62, 1, true, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols104.dat"}, {"test_data/pusch_demodulator_test_input_estimates104.dat", {144, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq104.dat"}, {"test_data/pusch_demodulator_test_output104.dat"}},
  {{0.028673, 16.1925, {29075, {{1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 3, 240, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols106.dat"}, {"test_data/pusch_demodulator_test_input_estimates106.dat", {60, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq106.dat"}, {"test_data/pusch_demodulator_test_output106.dat"}},
  {{0.037185, 12.8629, {44476, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 1, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 710, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols108.dat"}, {"test_data/pusch_demodulator_test_input_estimates108.dat", {144, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq108.dat"}, {"test_data/pusch_demodulator_test_output108.dat"}},
  {{0.0049324, 17.5948, {56327, {{1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM16, 2, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 950, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols110.dat"}, {"test_data/pusch_demodulator_test_input_estimates110.dat", {96, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq110.dat"}, {"test_data/pusch_demodulator_test_output110.dat"}},
  {{0.021482, 19.0034, {57401, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE1, 2, 93, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols112.dat"}, {"test_data/pusch_demodulator_test_input_estimates112.dat", {72, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq112.dat"}, {"test_data/pusch_demodulator_test_output112.dat"}},
  {{0.07786, 13.1119, {37825, {{1, 1}}, modulation_scheme::QAM64, 0, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 571, 1, true, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols114.dat"}, {"test_data/pusch_demodulator_test_input_estimates114.dat", {24, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq114.dat"}, {"test_data/pusch_demodulator_test_output114.dat"}},
  {{0.0017123, 27.1906, {50651, {{1, 1, 1}}, modulation_scheme::QAM64, 0, 8, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 22, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols116.dat"}, {"test_data/pusch_demodulator_test_input_estimates116.dat", {36, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq116.dat"}, {"test_data/pusch_demodulator_test_output116.dat"}},
  {{0.0013405, 29.8664, {59076, {{1, 1, 1, 1}}, modulation_scheme::QAM64, 0, 7, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 962, 1, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols118.dat"}, {"test_data/pusch_demodulator_test_input_estimates118.dat", {48, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq118.dat"}, {"test_data/pusch_demodulator_test_output118.dat"}},
  {{0.0028663, 25.0884, {6787, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 0, 9, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 808, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols120.dat"}, {"test_data/pusch_demodulator_test_input_estimates120.dat", {240, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq120.dat"}, {"test_data/pusch_demodulator_test_output120.dat"}},
  {{0.00081459, 28.5678, {8641, {{1, 1, 1}}, modulation_scheme::QAM64, 1, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 930, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols122.dat"}, {"test_data/pusch_demodulator_test_input_estimates122.dat", {36, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq122.dat"}, {"test_data/pusch_demodulator_test_output122.dat"}},
  {{0.019636, 10.4939, {65449, {{1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM64, 1, 13, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 815, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols124.dat"}, {"test_data/pusch_demodulator_test_input_estimates124.dat", {96, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq124.dat"}, {"test_data/pusch_demodulator_test_output124.dat"}},
  {{0.1072, 11.9975, {5471, {{1, 1, 1}}, modulation_scheme::QAM256, 0, 11, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 286, 1, true, {0}}}, {"test_data/pusch_demodulator_test_input_symbols126.dat"}, {"test_data/pusch_demodulator_test_input_estimates126.dat", {36, 14, 1, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq126.dat"}, {"test_data/pusch_demodulator_test_output126.dat"}},
  {{0.0014673, 29.0138, {11525, {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 2, 9, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0}, dmrs_type::TYPE1, 2, 180, 1, true, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols128.dat"}, {"test_data/pusch_demodulator_test_input_estimates128.dat", {240, 14, 2, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq128.dat"}, {"test_data/pusch_demodulator_test_output128.dat"}},
  {{0.034424, 10.2213, {31928, {{1, 1}}, modulation_scheme::QAM256, 2, 12, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, dmrs_type::TYPE2, 2, 868, 2, false, {0, 1}}}, {"test_data/pusch_demodulator_test_input_symbols130.dat"}, {"test_data/pusch_demodulator_test_input_estimates130.dat", {24, 14, 2, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq130.dat"}, {"test_data/pusch_demodulator_test_output130.dat"}},
  {{0.010778, 21.0603, {41981, {{1, 1, 1}}, modulation_scheme::QAM256, 2, 10, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 1, 187, 1, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols132.dat"}, {"test_data/pusch_demodulator_test_input_estimates132.dat", {36, 14, 4, 1}}, {"test_data/pusch_demodulator_test_output_scrambling_seq132.dat"}, {"test_data/pusch_demodulator_test_output132.dat"}},
  {{0.018203, 18.0938, {2906, {{1, 1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 2, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 369, 2, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols134.dat"}, {"test_data/pusch_demodulator_test_input_estimates134.dat", {72, 14, 4, 2}}, {"test_data/pusch_demodulator_test_output_scrambling_seq134.dat"}, {"test_data/pusch_demodulator_test_output134.dat"}},
  {{0.0064705, 20.135, {21534, {{1, 1, 1}}, modulation_scheme::QAM256, 2, 7, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 196, 3, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols136.dat"}, {"test_data/pusch_demodulator_test_input_estimates136.dat", {36, 14, 4, 3}}, {"test_data/pusch_demodulator_test_output_scrambling_seq136.dat"}, {"test_data/pusch_demodulator_test_output136.dat"}},
  {{0.0020116, 20.8789, {15454, {{1, 1, 1, 1, 1}}, modulation_scheme::QAM256, 1, 8, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, dmrs_type::TYPE2, 2, 719, 4, false, {0, 1, 2, 3}}}, {"test_data/pusch_demodulator_test_input_symbols138.dat"}, {"test_data/pusch_demodulator_test_input_estimates138.dat", {60, 14, 4, 4}}, {"test_data/pusch_demodulator_test_output_scrambling_seq138.dat"}, {"test_data/pusch_demodulator_test_output138.dat"}},
    // clang-format on
};

} // namespace srsran
