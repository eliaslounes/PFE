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

#include "srsran/srsvec/compare.h"
#include "srsran/support/math/math_utils.h"
#include "srsran/support/srsran_test.h"
#include <random>

static std::mt19937 rgen(0);

using namespace srsran;

static void test_max_abs_ccc(std::size_t N)
{
  std::uniform_real_distribution<float> dist(-1.0, 1.0);

  std::vector<cf_t> x(N);
  for (cf_t& v : x) {
    v = {dist(rgen), dist(rgen)};
  }

  std::pair<unsigned, float> result = srsvec::max_abs_element(x);

  auto     expected_it = std::max_element(x.begin(), x.end(), [](cf_t a, cf_t b) { return abs_sq(a) < abs_sq(b); });
  unsigned expected_max_index = static_cast<unsigned>(expected_it - x.begin());
  float    expected_max_value = abs_sq(*expected_it);

  TESTASSERT_EQ(expected_max_index, result.first);
  TESTASSERT(std::abs(expected_max_value - result.second) < 1e-6);
}

static void test_max_abs_ccc_same(std::size_t N)
{
  std::uniform_real_distribution<float> dist(-1.0, 1.0);

  std::vector<cf_t> x(N);
  std::fill(x.begin(), x.end(), 0);

  std::pair<unsigned, float> result = srsvec::max_abs_element(x);

  TESTASSERT_EQ(0, result.first);
  TESTASSERT_EQ(0.0, result.second);
}

static void test_max_f(std::size_t N)
{
  std::uniform_real_distribution<float> dist(-1.0, 1.0);

  std::vector<float> x(N);
  for (float& v : x) {
    v = dist(rgen);
  }

  std::pair<unsigned, float> result = srsvec::max_element(x);

  auto     expected_it        = std::max_element(x.begin(), x.end());
  unsigned expected_max_index = static_cast<unsigned>(expected_it - x.begin());
  float    expected_max_value = *expected_it;

  TESTASSERT_EQ(expected_max_index, result.first);
  TESTASSERT_EQ(expected_max_value, result.second);
}

static void test_max_f_same(std::size_t N)
{
  std::vector<float> x(N);
  std::fill(x.begin(), x.end(), 0);

  std::pair<unsigned, float> result = srsvec::max_element(x);

  TESTASSERT_EQ(0, result.first);
  TESTASSERT_EQ(0.0, result.second);
}

static void test_count_if_part_abs_greater_than(std::size_t N)
{
  float                                 threshold = 0.5;
  std::uniform_real_distribution<float> dist(-1.0, 1.0);

  std::vector<cf_t> x(N);
  std::generate(x.begin(), x.end(), [&dist]() { return cf_t{dist(rgen), dist(rgen)}; });

  unsigned result = srsvec::count_if_part_abs_greater_than(x, threshold);

  unsigned expected = std::count_if(x.begin(), x.end(), [threshold](cf_t sample) {
    return (std::abs(sample.real()) > threshold) || (std::abs(sample.imag()) > threshold);
  });

  TESTASSERT_EQ(expected, result);
}

int main()
{
  std::vector<std::size_t> sizes = {1, 5, 7, 19, 23, 65, 130, 257, 1234};

  for (std::size_t N : sizes) {
    test_max_abs_ccc(N);
    test_max_abs_ccc_same(N);
    test_max_f(N);
    test_max_f_same(N);
    test_count_if_part_abs_greater_than(N);
  }
}
