#
# Copyright 2021-2025 Software Radio Systems Limited
#
# This file is part of srsRAN
#
# srsRAN is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# srsRAN is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Affero General Public License for more details.
#
# A copy of the GNU Affero General Public License can be found in
# the LICENSE file in the top-level directory of this distribution
# and at http://www.gnu.org/licenses/.
#

set_directory_properties(PROPERTIES LABELS "fapi")

add_executable(message_bufferer_slot_gateway_impl_test message_bufferer_slot_gateway_impl_test.cpp)
target_link_libraries(message_bufferer_slot_gateway_impl_test srsran_support srsran_fapi_message_builder_test_helpers srslog srsran_fapi gtest gtest_main)
gtest_discover_tests(message_bufferer_slot_gateway_impl_test)
