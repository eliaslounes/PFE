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

#include "srsran/asn1/e2sm/e2sm_rc_ies.h"
using namespace asn1;
using namespace asn1::e2sm;

/*******************************************************************************
 *                                Struct Methods
 ******************************************************************************/

// RANParameter-Testing-Item ::= SEQUENCE
SRSASN_CODE ran_param_testing_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_testing_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-Type");
  ran_param_type.to_json(j);
  j.end_obj();
}

void ran_param_testing_item_s::ran_param_type_c_::set(types::options e)
{
  type_ = e;
  switch (type_) {
    case types::ran_p_choice_list:
      c = ran_param_testing_item_choice_list_s{};
      break;
    case types::ran_p_choice_structure:
      c = ran_param_testing_item_choice_structure_s{};
      break;
    case types::ran_p_choice_elem_true:
      c = ran_param_testing_item_choice_elem_true_s{};
      break;
    case types::ran_p_choice_elem_false:
      c = ran_param_testing_item_choice_elem_false_s{};
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_item_s::ran_param_type_c_");
  }
}
ran_param_testing_item_choice_list_s& ran_param_testing_item_s::ran_param_type_c_::set_ran_p_choice_list()
{
  set(types::ran_p_choice_list);
  return c.get<ran_param_testing_item_choice_list_s>();
}
ran_param_testing_item_choice_structure_s& ran_param_testing_item_s::ran_param_type_c_::set_ran_p_choice_structure()
{
  set(types::ran_p_choice_structure);
  return c.get<ran_param_testing_item_choice_structure_s>();
}
ran_param_testing_item_choice_elem_true_s& ran_param_testing_item_s::ran_param_type_c_::set_ran_p_choice_elem_true()
{
  set(types::ran_p_choice_elem_true);
  return c.get<ran_param_testing_item_choice_elem_true_s>();
}
ran_param_testing_item_choice_elem_false_s& ran_param_testing_item_s::ran_param_type_c_::set_ran_p_choice_elem_false()
{
  set(types::ran_p_choice_elem_false);
  return c.get<ran_param_testing_item_choice_elem_false_s>();
}
void ran_param_testing_item_s::ran_param_type_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ran_p_choice_list:
      j.write_fieldname("ranP-Choice-List");
      c.get<ran_param_testing_item_choice_list_s>().to_json(j);
      break;
    case types::ran_p_choice_structure:
      j.write_fieldname("ranP-Choice-Structure");
      c.get<ran_param_testing_item_choice_structure_s>().to_json(j);
      break;
    case types::ran_p_choice_elem_true:
      j.write_fieldname("ranP-Choice-ElementTrue");
      c.get<ran_param_testing_item_choice_elem_true_s>().to_json(j);
      break;
    case types::ran_p_choice_elem_false:
      j.write_fieldname("ranP-Choice-ElementFalse");
      c.get<ran_param_testing_item_choice_elem_false_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_item_s::ran_param_type_c_");
  }
  j.end_obj();
}
SRSASN_CODE ran_param_testing_item_s::ran_param_type_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ran_p_choice_list:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_list_s>().pack(bref));
      break;
    case types::ran_p_choice_structure:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_structure_s>().pack(bref));
      break;
    case types::ran_p_choice_elem_true:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_elem_true_s>().pack(bref));
      break;
    case types::ran_p_choice_elem_false:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_elem_false_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_item_s::ran_param_type_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_s::ran_param_type_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ran_p_choice_list:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_list_s>().unpack(bref));
      break;
    case types::ran_p_choice_structure:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_structure_s>().unpack(bref));
      break;
    case types::ran_p_choice_elem_true:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_elem_true_s>().unpack(bref));
      break;
    case types::ran_p_choice_elem_false:
      HANDLE_CODE(c.get<ran_param_testing_item_choice_elem_false_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_item_s::ran_param_type_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* ran_param_testing_item_s::ran_param_type_c_::types_opts::to_string() const
{
  static const char* names[] = {
      "ranP-Choice-List", "ranP-Choice-Structure", "ranP-Choice-ElementTrue", "ranP-Choice-ElementFalse"};
  return convert_enum_idx(names, 4, value, "ran_param_testing_item_s::ran_param_type_c_::types");
}

// AdditionalSupportedFormat-UEGroupControl ::= SEQUENCE
SRSASN_CODE add_supported_format_ue_group_ctrl_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_hdr_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_msg_format_type, false, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE add_supported_format_ue_group_ctrl_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_hdr_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_msg_format_type, bref, false, true));

  return SRSASN_SUCCESS;
}
void add_supported_format_ue_group_ctrl_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-ControlHeaderFormat-Type", ric_ctrl_hdr_format_type);
  j.write_int("ric-ControlMessageFormat-Type", ric_ctrl_msg_format_type);
  j.end_obj();
}

// NeighborCell-Item-Choice-E-UTRA ::= SEQUENCE
SRSASN_CODE neighbor_cell_item_choice_e_utra_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(eutra_cgi.pack(bref));
  HANDLE_CODE(pack_integer(bref, eutra_pci, (uint16_t)0u, (uint16_t)503u, true, true));
  HANDLE_CODE(pack_integer(bref, eutra_arfcn, (uint32_t)0u, (uint32_t)65535u, false, true));
  HANDLE_CODE(eutra_tac.pack(bref));
  HANDLE_CODE(x2_xn_established.pack(bref));
  HANDLE_CODE(ho_validated.pack(bref));
  HANDLE_CODE(pack_integer(bref, version, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE neighbor_cell_item_choice_e_utra_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(eutra_cgi.unpack(bref));
  HANDLE_CODE(unpack_integer(eutra_pci, bref, (uint16_t)0u, (uint16_t)503u, true, true));
  HANDLE_CODE(unpack_integer(eutra_arfcn, bref, (uint32_t)0u, (uint32_t)65535u, false, true));
  HANDLE_CODE(eutra_tac.unpack(bref));
  HANDLE_CODE(x2_xn_established.unpack(bref));
  HANDLE_CODE(ho_validated.unpack(bref));
  HANDLE_CODE(unpack_integer(version, bref, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
void neighbor_cell_item_choice_e_utra_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("eUTRA-CGI");
  eutra_cgi.to_json(j);
  j.write_int("eUTRA-PCI", eutra_pci);
  j.write_int("eUTRA-ARFCN", eutra_arfcn);
  j.write_str("eUTRA-TAC", eutra_tac.to_string());
  j.write_str("x2-Xn-established", x2_xn_established.to_string());
  j.write_str("hO-validated", ho_validated.to_string());
  j.write_int("version", version);
  j.end_obj();
}

const char* neighbor_cell_item_choice_e_utra_s::x2_xn_established_opts::to_string() const
{
  static const char* names[] = {"true", "false"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_choice_e_utra_s::x2_xn_established_e_");
}

const char* neighbor_cell_item_choice_e_utra_s::ho_validated_opts::to_string() const
{
  static const char* names[] = {"true", "false"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_choice_e_utra_s::ho_validated_e_");
}

// NeighborCell-Item-Choice-NR ::= SEQUENCE
SRSASN_CODE neighbor_cell_item_choice_nr_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(nr_cgi.pack(bref));
  HANDLE_CODE(pack_integer(bref, nr_pci, (uint16_t)0u, (uint16_t)1007u, false, true));
  HANDLE_CODE(five_gs_tac.pack(bref));
  HANDLE_CODE(nr_mode_info.pack(bref));
  HANDLE_CODE(nr_freq_info.pack(bref));
  HANDLE_CODE(x2_xn_established.pack(bref));
  HANDLE_CODE(ho_validated.pack(bref));
  HANDLE_CODE(pack_integer(bref, version, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE neighbor_cell_item_choice_nr_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(nr_cgi.unpack(bref));
  HANDLE_CODE(unpack_integer(nr_pci, bref, (uint16_t)0u, (uint16_t)1007u, false, true));
  HANDLE_CODE(five_gs_tac.unpack(bref));
  HANDLE_CODE(nr_mode_info.unpack(bref));
  HANDLE_CODE(nr_freq_info.unpack(bref));
  HANDLE_CODE(x2_xn_established.unpack(bref));
  HANDLE_CODE(ho_validated.unpack(bref));
  HANDLE_CODE(unpack_integer(version, bref, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
void neighbor_cell_item_choice_nr_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("nR-CGI");
  nr_cgi.to_json(j);
  j.write_int("nR-PCI", nr_pci);
  j.write_str("fiveGS-TAC", five_gs_tac.to_string());
  j.write_str("nR-mode-info", nr_mode_info.to_string());
  j.write_fieldname("nR-FreqInfo");
  nr_freq_info.to_json(j);
  j.write_str("x2-Xn-established", x2_xn_established.to_string());
  j.write_str("hO-validated", ho_validated.to_string());
  j.write_int("version", version);
  j.end_obj();
}

const char* neighbor_cell_item_choice_nr_s::nr_mode_info_opts::to_string() const
{
  static const char* names[] = {"fdd", "tdd"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_choice_nr_s::nr_mode_info_e_");
}

const char* neighbor_cell_item_choice_nr_s::x2_xn_established_opts::to_string() const
{
  static const char* names[] = {"true", "false"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_choice_nr_s::x2_xn_established_e_");
}

const char* neighbor_cell_item_choice_nr_s::ho_validated_opts::to_string() const
{
  static const char* names[] = {"true", "false"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_choice_nr_s::ho_validated_e_");
}

// RANParameter-Definition-Choice ::= CHOICE
void ran_param_definition_choice_c::set(types::options e)
{
  type_ = e;
  switch (type_) {
    case types::choice_list:
      c = ran_param_definition_choice_list_s{};
      break;
    case types::choice_structure:
      c = ran_param_definition_choice_structure_s{};
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_definition_choice_c");
  }
}
ran_param_definition_choice_list_s& ran_param_definition_choice_c::set_choice_list()
{
  set(types::choice_list);
  return c.get<ran_param_definition_choice_list_s>();
}
ran_param_definition_choice_structure_s& ran_param_definition_choice_c::set_choice_structure()
{
  set(types::choice_structure);
  return c.get<ran_param_definition_choice_structure_s>();
}
void ran_param_definition_choice_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::choice_list:
      j.write_fieldname("choiceLIST");
      c.get<ran_param_definition_choice_list_s>().to_json(j);
      break;
    case types::choice_structure:
      j.write_fieldname("choiceSTRUCTURE");
      c.get<ran_param_definition_choice_structure_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_definition_choice_c");
  }
  j.end_obj();
}
SRSASN_CODE ran_param_definition_choice_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::choice_list:
      HANDLE_CODE(c.get<ran_param_definition_choice_list_s>().pack(bref));
      break;
    case types::choice_structure:
      HANDLE_CODE(c.get<ran_param_definition_choice_structure_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_definition_choice_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_choice_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::choice_list:
      HANDLE_CODE(c.get<ran_param_definition_choice_list_s>().unpack(bref));
      break;
    case types::choice_structure:
      HANDLE_CODE(c.get<ran_param_definition_choice_structure_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_definition_choice_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* ran_param_definition_choice_c::types_opts::to_string() const
{
  static const char* names[] = {"choiceLIST", "choiceSTRUCTURE"};
  return convert_enum_idx(names, 2, value, "ran_param_definition_choice_c::types");
}

// RANParameter-ValueType ::= CHOICE
void ran_param_value_type_c::set(types::options e)
{
  type_ = e;
  switch (type_) {
    case types::ran_p_choice_elem_true:
      c = ran_param_value_type_choice_elem_true_s{};
      break;
    case types::ran_p_choice_elem_false:
      c = ran_param_value_type_choice_elem_false_s{};
      break;
    case types::ran_p_choice_structure:
      c = ran_param_value_type_choice_structure_s{};
      break;
    case types::ran_p_choice_list:
      c = ran_param_value_type_choice_list_s{};
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_type_c");
  }
}
ran_param_value_type_choice_elem_true_s& ran_param_value_type_c::set_ran_p_choice_elem_true()
{
  set(types::ran_p_choice_elem_true);
  return c.get<ran_param_value_type_choice_elem_true_s>();
}
ran_param_value_type_choice_elem_false_s& ran_param_value_type_c::set_ran_p_choice_elem_false()
{
  set(types::ran_p_choice_elem_false);
  return c.get<ran_param_value_type_choice_elem_false_s>();
}
ran_param_value_type_choice_structure_s& ran_param_value_type_c::set_ran_p_choice_structure()
{
  set(types::ran_p_choice_structure);
  return c.get<ran_param_value_type_choice_structure_s>();
}
ran_param_value_type_choice_list_s& ran_param_value_type_c::set_ran_p_choice_list()
{
  set(types::ran_p_choice_list);
  return c.get<ran_param_value_type_choice_list_s>();
}
void ran_param_value_type_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ran_p_choice_elem_true:
      j.write_fieldname("ranP-Choice-ElementTrue");
      c.get<ran_param_value_type_choice_elem_true_s>().to_json(j);
      break;
    case types::ran_p_choice_elem_false:
      j.write_fieldname("ranP-Choice-ElementFalse");
      c.get<ran_param_value_type_choice_elem_false_s>().to_json(j);
      break;
    case types::ran_p_choice_structure:
      j.write_fieldname("ranP-Choice-Structure");
      c.get<ran_param_value_type_choice_structure_s>().to_json(j);
      break;
    case types::ran_p_choice_list:
      j.write_fieldname("ranP-Choice-List");
      c.get<ran_param_value_type_choice_list_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_type_c");
  }
  j.end_obj();
}
SRSASN_CODE ran_param_value_type_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ran_p_choice_elem_true:
      HANDLE_CODE(c.get<ran_param_value_type_choice_elem_true_s>().pack(bref));
      break;
    case types::ran_p_choice_elem_false:
      HANDLE_CODE(c.get<ran_param_value_type_choice_elem_false_s>().pack(bref));
      break;
    case types::ran_p_choice_structure:
      HANDLE_CODE(c.get<ran_param_value_type_choice_structure_s>().pack(bref));
      break;
    case types::ran_p_choice_list:
      HANDLE_CODE(c.get<ran_param_value_type_choice_list_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_type_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_type_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ran_p_choice_elem_true:
      HANDLE_CODE(c.get<ran_param_value_type_choice_elem_true_s>().unpack(bref));
      break;
    case types::ran_p_choice_elem_false:
      HANDLE_CODE(c.get<ran_param_value_type_choice_elem_false_s>().unpack(bref));
      break;
    case types::ran_p_choice_structure:
      HANDLE_CODE(c.get<ran_param_value_type_choice_structure_s>().unpack(bref));
      break;
    case types::ran_p_choice_list:
      HANDLE_CODE(c.get<ran_param_value_type_choice_list_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_type_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* ran_param_value_type_c::types_opts::to_string() const
{
  static const char* names[] = {
      "ranP-Choice-ElementTrue", "ranP-Choice-ElementFalse", "ranP-Choice-Structure", "ranP-Choice-List"};
  return convert_enum_idx(names, 4, value, "ran_param_value_type_c::types");
}

// RRC-State ::= ENUMERATED
const char* rrc_state_opts::to_string() const
{
  static const char* names[] = {"rrc-connected", "rrc-inactive", "rrc-idle", "any"};
  return convert_enum_idx(names, 4, value, "rrc_state_e");
}

// TriggerType-Choice-MIMOandBFconfig ::= SEQUENCE
SRSASN_CODE trigger_type_choice_mimo_and_b_fcfg_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(mimo_trans_mode_state.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_mimo_and_b_fcfg_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(mimo_trans_mode_state.unpack(bref));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_mimo_and_b_fcfg_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_str("mIMOtransModeState", mimo_trans_mode_state.to_string());
  j.end_obj();
}

const char* trigger_type_choice_mimo_and_b_fcfg_s::mimo_trans_mode_state_opts::to_string() const
{
  static const char* names[] = {"enabled", "disabled"};
  return convert_enum_idx(names, 2, value, "trigger_type_choice_mimo_and_b_fcfg_s::mimo_trans_mode_state_e_");
}

// E2SM-RC-ControlMessage-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format1_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format1-Item");
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// EventTrigger-Cell-Info-Item-Choice-Group ::= SEQUENCE
SRSASN_CODE event_trigger_cell_info_item_choice_group_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_testing, 1, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_cell_info_item_choice_group_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_testing, bref, 1, 255, true));

  return SRSASN_SUCCESS;
}
void event_trigger_cell_info_item_choice_group_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameterTesting");
  for (const auto& e1 : ran_param_testing) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// EventTrigger-Cell-Info-Item-Choice-Individual ::= SEQUENCE
SRSASN_CODE event_trigger_cell_info_item_choice_individual_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(cell_global_id.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_cell_info_item_choice_individual_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(cell_global_id.unpack(bref));

  return SRSASN_SUCCESS;
}
void event_trigger_cell_info_item_choice_individual_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("cellGlobalID");
  cell_global_id.to_json(j);
  j.end_obj();
}

// EventTrigger-UE-Info-Item-Choice-Group ::= SEQUENCE
SRSASN_CODE event_trigger_ue_info_item_choice_group_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_testing, 1, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_info_item_choice_group_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_testing, bref, 1, 255, true));

  return SRSASN_SUCCESS;
}
void event_trigger_ue_info_item_choice_group_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameterTesting");
  for (const auto& e1 : ran_param_testing) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// EventTrigger-UE-Info-Item-Choice-Individual ::= SEQUENCE
SRSASN_CODE event_trigger_ue_info_item_choice_individual_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_testing.size() > 0, 1));

  HANDLE_CODE(ue_id.pack(bref));
  if (ran_param_testing.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_testing, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_info_item_choice_individual_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_param_testing_present;
  HANDLE_CODE(bref.unpack(ran_param_testing_present, 1));

  HANDLE_CODE(ue_id.unpack(bref));
  if (ran_param_testing_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_param_testing, bref, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
void event_trigger_ue_info_item_choice_individual_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ueID");
  ue_id.to_json(j);
  if (ran_param_testing.size() > 0) {
    j.start_array("ranParameterTesting");
    for (const auto& e1 : ran_param_testing) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// L2MACschChgType-Choice ::= CHOICE
void l2_ma_csch_chg_type_choice_c::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("triggerType-Choice-MIMOandBFconfig");
  c.to_json(j);
  j.end_obj();
}
SRSASN_CODE l2_ma_csch_chg_type_choice_c::pack(bit_ref& bref) const
{
  pack_enum(bref, type());
  HANDLE_CODE(c.pack(bref));
  return SRSASN_SUCCESS;
}
SRSASN_CODE l2_ma_csch_chg_type_choice_c::unpack(cbit_ref& bref)
{
  types e;
  unpack_enum(e, bref);
  if (e != type()) {
    log_invalid_choice_id(e, "l2_ma_csch_chg_type_choice_c");
    return SRSASN_ERROR_DECODE_FAIL;
  }
  HANDLE_CODE(c.unpack(bref));
  return SRSASN_SUCCESS;
}

const char* l2_ma_csch_chg_type_choice_c::types_opts::to_string() const
{
  static const char* names[] = {"triggerType-Choice-MIMOandBFconfig"};
  return convert_enum_idx(names, 1, value, "l2_ma_csch_chg_type_choice_c::types");
}

// NeighborCell-Item ::= CHOICE
void neighbor_cell_item_c::destroy_()
{
  switch (type_) {
    case types::ran_type_choice_nr:
      c.destroy<neighbor_cell_item_choice_nr_s>();
      break;
    case types::ran_type_choice_eutra:
      c.destroy<neighbor_cell_item_choice_e_utra_s>();
      break;
    default:
      break;
  }
}
void neighbor_cell_item_c::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ran_type_choice_nr:
      c.init<neighbor_cell_item_choice_nr_s>();
      break;
    case types::ran_type_choice_eutra:
      c.init<neighbor_cell_item_choice_e_utra_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
  }
}
neighbor_cell_item_c::neighbor_cell_item_c(const neighbor_cell_item_c& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ran_type_choice_nr:
      c.init(other.c.get<neighbor_cell_item_choice_nr_s>());
      break;
    case types::ran_type_choice_eutra:
      c.init(other.c.get<neighbor_cell_item_choice_e_utra_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
  }
}
neighbor_cell_item_c& neighbor_cell_item_c::operator=(const neighbor_cell_item_c& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ran_type_choice_nr:
      c.set(other.c.get<neighbor_cell_item_choice_nr_s>());
      break;
    case types::ran_type_choice_eutra:
      c.set(other.c.get<neighbor_cell_item_choice_e_utra_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
  }

  return *this;
}
neighbor_cell_item_choice_nr_s& neighbor_cell_item_c::set_ran_type_choice_nr()
{
  set(types::ran_type_choice_nr);
  return c.get<neighbor_cell_item_choice_nr_s>();
}
neighbor_cell_item_choice_e_utra_s& neighbor_cell_item_c::set_ran_type_choice_eutra()
{
  set(types::ran_type_choice_eutra);
  return c.get<neighbor_cell_item_choice_e_utra_s>();
}
void neighbor_cell_item_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ran_type_choice_nr:
      j.write_fieldname("ranType-Choice-NR");
      c.get<neighbor_cell_item_choice_nr_s>().to_json(j);
      break;
    case types::ran_type_choice_eutra:
      j.write_fieldname("ranType-Choice-EUTRA");
      c.get<neighbor_cell_item_choice_e_utra_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
  }
  j.end_obj();
}
SRSASN_CODE neighbor_cell_item_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ran_type_choice_nr:
      HANDLE_CODE(c.get<neighbor_cell_item_choice_nr_s>().pack(bref));
      break;
    case types::ran_type_choice_eutra:
      HANDLE_CODE(c.get<neighbor_cell_item_choice_e_utra_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE neighbor_cell_item_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ran_type_choice_nr:
      HANDLE_CODE(c.get<neighbor_cell_item_choice_nr_s>().unpack(bref));
      break;
    case types::ran_type_choice_eutra:
      HANDLE_CODE(c.get<neighbor_cell_item_choice_e_utra_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "neighbor_cell_item_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* neighbor_cell_item_c::types_opts::to_string() const
{
  static const char* names[] = {"ranType-Choice-NR", "ranType-Choice-EUTRA"};
  return convert_enum_idx(names, 2, value, "neighbor_cell_item_c::types");
}

// RANParameter-Definition ::= SEQUENCE
SRSASN_CODE ran_param_definition_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ran_param_definition_choice.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ran_param_definition_choice.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_definition_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-Definition-Choice");
  ran_param_definition_choice.to_json(j);
  j.end_obj();
}

// RANParameter-Value ::= CHOICE
void ran_param_value_c::destroy_()
{
  switch (type_) {
    case types::value_boolean:
      c.destroy<bool>();
      break;
    case types::value_real:
      c.destroy<real_s>();
      break;
    case types::value_bit_s:
      c.destroy<dyn_bitstring>();
      break;
    case types::value_oct_s:
      c.destroy<unbounded_octstring<true>>();
      break;
    case types::value_printable_string:
      c.destroy<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>();
      break;
    default:
      break;
  }
}
void ran_param_value_c::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::value_boolean:
      c.init<bool>();
      break;
    case types::value_int:
      break;
    case types::value_real:
      c.init<real_s>();
      break;
    case types::value_bit_s:
      c.init<dyn_bitstring>();
      break;
    case types::value_oct_s:
      c.init<unbounded_octstring<true>>();
      break;
    case types::value_printable_string:
      c.init<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
  }
}
ran_param_value_c::ran_param_value_c(const ran_param_value_c& other)
{
  type_ = other.type();
  switch (type_) {
    case types::value_boolean:
      c.init(other.c.get<bool>());
      break;
    case types::value_int:
      c.init(other.c.get<int64_t>());
      break;
    case types::value_real:
      c.init(other.c.get<real_s>());
      break;
    case types::value_bit_s:
      c.init(other.c.get<dyn_bitstring>());
      break;
    case types::value_oct_s:
      c.init(other.c.get<unbounded_octstring<true>>());
      break;
    case types::value_printable_string:
      c.init(other.c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
  }
}
ran_param_value_c& ran_param_value_c::operator=(const ran_param_value_c& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::value_boolean:
      c.set(other.c.get<bool>());
      break;
    case types::value_int:
      c.set(other.c.get<int64_t>());
      break;
    case types::value_real:
      c.set(other.c.get<real_s>());
      break;
    case types::value_bit_s:
      c.set(other.c.get<dyn_bitstring>());
      break;
    case types::value_oct_s:
      c.set(other.c.get<unbounded_octstring<true>>());
      break;
    case types::value_printable_string:
      c.set(other.c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
  }

  return *this;
}
bool& ran_param_value_c::set_value_boolean()
{
  set(types::value_boolean);
  return c.get<bool>();
}
int64_t& ran_param_value_c::set_value_int()
{
  set(types::value_int);
  return c.get<int64_t>();
}
real_s& ran_param_value_c::set_value_real()
{
  set(types::value_real);
  return c.get<real_s>();
}
dyn_bitstring& ran_param_value_c::set_value_bit_s()
{
  set(types::value_bit_s);
  return c.get<dyn_bitstring>();
}
unbounded_octstring<true>& ran_param_value_c::set_value_oct_s()
{
  set(types::value_oct_s);
  return c.get<unbounded_octstring<true>>();
}
printable_string<0, MAX_ASN_STRING_LENGTH, false, true>& ran_param_value_c::set_value_printable_string()
{
  set(types::value_printable_string);
  return c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>();
}
void ran_param_value_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::value_boolean:
      j.write_bool("valueBoolean", c.get<bool>());
      break;
    case types::value_int:
      j.write_int("valueInt", c.get<int64_t>());
      break;
    case types::value_real:
      j.write_fieldname("valueReal");
      c.get<real_s>().to_json(j);
      break;
    case types::value_bit_s:
      j.write_str("valueBitS", c.get<dyn_bitstring>().to_string());
      break;
    case types::value_oct_s:
      j.write_str("valueOctS", c.get<unbounded_octstring<true>>().to_string());
      break;
    case types::value_printable_string:
      j.write_str("valuePrintableString", c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>().to_string());
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
  }
  j.end_obj();
}
SRSASN_CODE ran_param_value_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::value_boolean:
      HANDLE_CODE(bref.pack(c.get<bool>(), 1));
      break;
    case types::value_int:
      HANDLE_CODE(pack_unconstrained_integer(bref, c.get<int64_t>(), false, true));
      break;
    case types::value_real:
      HANDLE_CODE(c.get<real_s>().pack(bref));
      break;
    case types::value_bit_s:
      HANDLE_CODE(c.get<dyn_bitstring>().pack(bref));
      break;
    case types::value_oct_s:
      HANDLE_CODE(c.get<unbounded_octstring<true>>().pack(bref));
      break;
    case types::value_printable_string:
      HANDLE_CODE((c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>().pack(bref)));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::value_boolean:
      HANDLE_CODE(bref.unpack(c.get<bool>(), 1));
      break;
    case types::value_int:
      HANDLE_CODE(unpack_unconstrained_integer(c.get<int64_t>(), bref, false, true));
      break;
    case types::value_real:
      HANDLE_CODE(c.get<real_s>().unpack(bref));
      break;
    case types::value_bit_s:
      HANDLE_CODE(c.get<dyn_bitstring>().unpack(bref));
      break;
    case types::value_oct_s:
      HANDLE_CODE(c.get<unbounded_octstring<true>>().unpack(bref));
      break;
    case types::value_printable_string:
      HANDLE_CODE((c.get<printable_string<0, MAX_ASN_STRING_LENGTH, false, true>>().unpack(bref)));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_value_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* ran_param_value_c::types_opts::to_string() const
{
  static const char* names[] = {
      "valueBoolean", "valueInt", "valueReal", "valueBitS", "valueOctS", "valuePrintableString"};
  return convert_enum_idx(names, 6, value, "ran_param_value_c::types");
}

// TriggerType-Choice-RRCstate-Item ::= SEQUENCE
SRSASN_CODE trigger_type_choice_rrc_state_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(state_changed_to.pack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_rrc_state_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(state_changed_to.unpack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void trigger_type_choice_rrc_state_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_str("stateChangedTo", state_changed_to.to_string());
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// CallProcessBreakpoint-RANParameter-Item ::= SEQUENCE
SRSASN_CODE call_process_breakpoint_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE call_process_breakpoint_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void call_process_breakpoint_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// ControlAction-RANParameter-Item ::= SEQUENCE
SRSASN_CODE ctrl_action_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));
    HANDLE_CODE(bref.pack(list_of_add_supported_formats_ue_group_ctrl.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
    if (list_of_add_supported_formats_ue_group_ctrl.is_present()) {
      HANDLE_CODE(pack_dyn_seq_of(bref, *list_of_add_supported_formats_ue_group_ctrl, 0, 63, true));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ctrl_action_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);
    unpack_presence_flag(list_of_add_supported_formats_ue_group_ctrl, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
    if (list_of_add_supported_formats_ue_group_ctrl.is_present()) {
      HANDLE_CODE(unpack_dyn_seq_of(*list_of_add_supported_formats_ue_group_ctrl, bref, 0, 63, true));
    }
  }
  return SRSASN_SUCCESS;
}
void ctrl_action_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
    if (list_of_add_supported_formats_ue_group_ctrl.is_present()) {
      j.start_array("listOfAdditionalSupportedFormats-UEGroupControl");
      for (const auto& e1 : *list_of_add_supported_formats_ue_group_ctrl) {
        e1.to_json(j);
      }
      j.end_array();
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format4-RANP-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format4_ran_p_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format4_ran_p_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format4_ran_p_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ControlMessage-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 0, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 0, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format1_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format1");
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-ControlOutcome-Format2-RANP-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_ran_p_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_ran_p_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format2_ran_p_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-value");
  ran_param_value.to_json(j);
  j.end_obj();
}

// E2SM-RC-IndicationMessage-Format6-RANP-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format6_ran_p_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format6_ran_p_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format6_ran_p_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format6-RANP-Item");
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// EventTrigger-Cell-Info-Item ::= SEQUENCE
SRSASN_CODE event_trigger_cell_info_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, event_trigger_cell_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(cell_type.pack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_cell_info_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(event_trigger_cell_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(cell_type.unpack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void event_trigger_cell_info_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("eventTriggerCellID", event_trigger_cell_id);
  j.write_fieldname("cellType");
  cell_type.to_json(j);
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

void event_trigger_cell_info_item_s::cell_type_c_::destroy_()
{
  switch (type_) {
    case types::cell_type_choice_individual:
      c.destroy<event_trigger_cell_info_item_choice_individual_s>();
      break;
    case types::cell_type_choice_group:
      c.destroy<event_trigger_cell_info_item_choice_group_s>();
      break;
    default:
      break;
  }
}
void event_trigger_cell_info_item_s::cell_type_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::cell_type_choice_individual:
      c.init<event_trigger_cell_info_item_choice_individual_s>();
      break;
    case types::cell_type_choice_group:
      c.init<event_trigger_cell_info_item_choice_group_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
  }
}
event_trigger_cell_info_item_s::cell_type_c_::cell_type_c_(const event_trigger_cell_info_item_s::cell_type_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::cell_type_choice_individual:
      c.init(other.c.get<event_trigger_cell_info_item_choice_individual_s>());
      break;
    case types::cell_type_choice_group:
      c.init(other.c.get<event_trigger_cell_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
  }
}
event_trigger_cell_info_item_s::cell_type_c_&
event_trigger_cell_info_item_s::cell_type_c_::operator=(const event_trigger_cell_info_item_s::cell_type_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::cell_type_choice_individual:
      c.set(other.c.get<event_trigger_cell_info_item_choice_individual_s>());
      break;
    case types::cell_type_choice_group:
      c.set(other.c.get<event_trigger_cell_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
  }

  return *this;
}
event_trigger_cell_info_item_choice_individual_s&
event_trigger_cell_info_item_s::cell_type_c_::set_cell_type_choice_individual()
{
  set(types::cell_type_choice_individual);
  return c.get<event_trigger_cell_info_item_choice_individual_s>();
}
event_trigger_cell_info_item_choice_group_s& event_trigger_cell_info_item_s::cell_type_c_::set_cell_type_choice_group()
{
  set(types::cell_type_choice_group);
  return c.get<event_trigger_cell_info_item_choice_group_s>();
}
void event_trigger_cell_info_item_s::cell_type_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::cell_type_choice_individual:
      j.write_fieldname("cellType-Choice-Individual");
      c.get<event_trigger_cell_info_item_choice_individual_s>().to_json(j);
      break;
    case types::cell_type_choice_group:
      j.write_fieldname("cellType-Choice-Group");
      c.get<event_trigger_cell_info_item_choice_group_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
  }
  j.end_obj();
}
SRSASN_CODE event_trigger_cell_info_item_s::cell_type_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::cell_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_cell_info_item_choice_individual_s>().pack(bref));
      break;
    case types::cell_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_cell_info_item_choice_group_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_cell_info_item_s::cell_type_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::cell_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_cell_info_item_choice_individual_s>().unpack(bref));
      break;
    case types::cell_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_cell_info_item_choice_group_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_cell_info_item_s::cell_type_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* event_trigger_cell_info_item_s::cell_type_c_::types_opts::to_string() const
{
  static const char* names[] = {"cellType-Choice-Individual", "cellType-Choice-Group"};
  return convert_enum_idx(names, 2, value, "event_trigger_cell_info_item_s::cell_type_c_::types");
}

// EventTrigger-UEevent-Info-Item ::= SEQUENCE
SRSASN_CODE event_trigger_ue_event_info_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ue_event_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_event_info_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ue_event_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void event_trigger_ue_event_info_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ueEventID", ue_event_id);
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// EventTrigger-UE-Info-Item ::= SEQUENCE
SRSASN_CODE event_trigger_ue_info_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, event_trigger_ue_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_type.pack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_info_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(event_trigger_ue_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_type.unpack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void event_trigger_ue_info_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("eventTriggerUEID", event_trigger_ue_id);
  j.write_fieldname("ueType");
  ue_type.to_json(j);
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

void event_trigger_ue_info_item_s::ue_type_c_::destroy_()
{
  switch (type_) {
    case types::ue_type_choice_individual:
      c.destroy<event_trigger_ue_info_item_choice_individual_s>();
      break;
    case types::ue_type_choice_group:
      c.destroy<event_trigger_ue_info_item_choice_group_s>();
      break;
    default:
      break;
  }
}
void event_trigger_ue_info_item_s::ue_type_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ue_type_choice_individual:
      c.init<event_trigger_ue_info_item_choice_individual_s>();
      break;
    case types::ue_type_choice_group:
      c.init<event_trigger_ue_info_item_choice_group_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
  }
}
event_trigger_ue_info_item_s::ue_type_c_::ue_type_c_(const event_trigger_ue_info_item_s::ue_type_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ue_type_choice_individual:
      c.init(other.c.get<event_trigger_ue_info_item_choice_individual_s>());
      break;
    case types::ue_type_choice_group:
      c.init(other.c.get<event_trigger_ue_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
  }
}
event_trigger_ue_info_item_s::ue_type_c_&
event_trigger_ue_info_item_s::ue_type_c_::operator=(const event_trigger_ue_info_item_s::ue_type_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ue_type_choice_individual:
      c.set(other.c.get<event_trigger_ue_info_item_choice_individual_s>());
      break;
    case types::ue_type_choice_group:
      c.set(other.c.get<event_trigger_ue_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
  }

  return *this;
}
event_trigger_ue_info_item_choice_individual_s&
event_trigger_ue_info_item_s::ue_type_c_::set_ue_type_choice_individual()
{
  set(types::ue_type_choice_individual);
  return c.get<event_trigger_ue_info_item_choice_individual_s>();
}
event_trigger_ue_info_item_choice_group_s& event_trigger_ue_info_item_s::ue_type_c_::set_ue_type_choice_group()
{
  set(types::ue_type_choice_group);
  return c.get<event_trigger_ue_info_item_choice_group_s>();
}
void event_trigger_ue_info_item_s::ue_type_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ue_type_choice_individual:
      j.write_fieldname("ueType-Choice-Individual");
      c.get<event_trigger_ue_info_item_choice_individual_s>().to_json(j);
      break;
    case types::ue_type_choice_group:
      j.write_fieldname("ueType-Choice-Group");
      c.get<event_trigger_ue_info_item_choice_group_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
  }
  j.end_obj();
}
SRSASN_CODE event_trigger_ue_info_item_s::ue_type_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ue_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_individual_s>().pack(bref));
      break;
    case types::ue_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_group_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_info_item_s::ue_type_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ue_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_individual_s>().unpack(bref));
      break;
    case types::ue_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_group_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "event_trigger_ue_info_item_s::ue_type_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* event_trigger_ue_info_item_s::ue_type_c_::types_opts::to_string() const
{
  static const char* names[] = {"ueType-Choice-Individual", "ueType-Choice-Group"};
  return convert_enum_idx(names, 2, value, "event_trigger_ue_info_item_s::ue_type_c_::types");
}

// InsertIndication-RANParameter-Item ::= SEQUENCE
SRSASN_CODE insert_ind_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE insert_ind_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void insert_ind_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// MessageType-Choice-NI ::= SEQUENCE
SRSASN_CODE msg_type_choice_ni_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ni_id_present, 1));
  HANDLE_CODE(bref.pack(ni_msg_present, 1));

  HANDLE_CODE(ni_type.pack(bref));
  if (ni_id_present) {
    HANDLE_CODE(ni_id.pack(bref));
  }
  if (ni_msg_present) {
    HANDLE_CODE(ni_msg.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE msg_type_choice_ni_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ni_id_present, 1));
  HANDLE_CODE(bref.unpack(ni_msg_present, 1));

  HANDLE_CODE(ni_type.unpack(bref));
  if (ni_id_present) {
    HANDLE_CODE(ni_id.unpack(bref));
  }
  if (ni_msg_present) {
    HANDLE_CODE(ni_msg.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void msg_type_choice_ni_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_str("nI-Type", ni_type.to_string());
  if (ni_id_present) {
    j.write_fieldname("nI-Identifier");
    ni_id.to_json(j);
  }
  if (ni_msg_present) {
    j.write_fieldname("nI-Message");
    ni_msg.to_json(j);
  }
  j.end_obj();
}

// MessageType-Choice-RRC ::= SEQUENCE
SRSASN_CODE msg_type_choice_rrc_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(rrc_msg.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE msg_type_choice_rrc_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(rrc_msg.unpack(bref));

  return SRSASN_SUCCESS;
}
void msg_type_choice_rrc_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("rRC-Message");
  rrc_msg.to_json(j);
  j.end_obj();
}

// PolicyAction-RANParameter-Item ::= SEQUENCE
SRSASN_CODE policy_action_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE policy_action_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void policy_action_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// PolicyCondition-RANParameter-Item ::= SEQUENCE
SRSASN_CODE policy_condition_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE policy_condition_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void policy_condition_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// RIC-PolicyAction-RANParameter-Item ::= SEQUENCE
SRSASN_CODE ric_policy_action_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ric_policy_action_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void ric_policy_action_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
}

// TriggerType-Choice-L2MACschChg ::= SEQUENCE
SRSASN_CODE trigger_type_choice_l2_ma_csch_chg_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(l2_ma_csch_chg_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_l2_ma_csch_chg_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(l2_ma_csch_chg_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_l2_ma_csch_chg_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("l2MACschChgType");
  l2_ma_csch_chg_type.to_json(j);
  j.end_obj();
}

// TriggerType-Choice-L2state ::= SEQUENCE
SRSASN_CODE trigger_type_choice_l2state_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, associated_l2variables, 1, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_l2state_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(associated_l2variables, bref, 1, 255, true));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_l2state_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("associatedL2variables");
  for (const auto& e1 : associated_l2variables) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// TriggerType-Choice-RRCstate ::= SEQUENCE
SRSASN_CODE trigger_type_choice_rrc_state_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, rrc_state_list, 1, 8, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_rrc_state_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(rrc_state_list, bref, 1, 8, true));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_rrc_state_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("rrcState-List");
  for (const auto& e1 : rrc_state_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// TriggerType-Choice-UEcontext ::= SEQUENCE
SRSASN_CODE trigger_type_choice_ue_context_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, associated_ue_ctxt_variables, 1, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_ue_context_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(associated_ue_ctxt_variables, bref, 1, 255, true));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_ue_context_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("associatedUECtxtVariables");
  for (const auto& e1 : associated_ue_ctxt_variables) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// TriggerType-Choice-UEID ::= SEQUENCE
SRSASN_CODE trigger_type_choice_ue_id_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ue_id_change_id, (uint16_t)1u, (uint16_t)512u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_ue_id_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ue_id_change_id, bref, (uint16_t)1u, (uint16_t)512u, true, true));

  return SRSASN_SUCCESS;
}
void trigger_type_choice_ue_id_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ueIDchange-ID", ue_id_change_id);
  j.end_obj();
}

// Associated-UE-Info-Item ::= SEQUENCE
SRSASN_CODE associated_ue_info_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ue_filt_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_type.pack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE associated_ue_info_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ue_filt_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_type.unpack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void associated_ue_info_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ueFilterID", ue_filt_id);
  j.write_fieldname("ueType");
  ue_type.to_json(j);
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

void associated_ue_info_item_s::ue_type_c_::destroy_()
{
  switch (type_) {
    case types::ue_type_choice_individual:
      c.destroy<event_trigger_ue_info_item_choice_individual_s>();
      break;
    case types::ue_type_choice_group:
      c.destroy<event_trigger_ue_info_item_choice_group_s>();
      break;
    default:
      break;
  }
}
void associated_ue_info_item_s::ue_type_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ue_type_choice_individual:
      c.init<event_trigger_ue_info_item_choice_individual_s>();
      break;
    case types::ue_type_choice_group:
      c.init<event_trigger_ue_info_item_choice_group_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
  }
}
associated_ue_info_item_s::ue_type_c_::ue_type_c_(const associated_ue_info_item_s::ue_type_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ue_type_choice_individual:
      c.init(other.c.get<event_trigger_ue_info_item_choice_individual_s>());
      break;
    case types::ue_type_choice_group:
      c.init(other.c.get<event_trigger_ue_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
  }
}
associated_ue_info_item_s::ue_type_c_&
associated_ue_info_item_s::ue_type_c_::operator=(const associated_ue_info_item_s::ue_type_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ue_type_choice_individual:
      c.set(other.c.get<event_trigger_ue_info_item_choice_individual_s>());
      break;
    case types::ue_type_choice_group:
      c.set(other.c.get<event_trigger_ue_info_item_choice_group_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
  }

  return *this;
}
event_trigger_ue_info_item_choice_individual_s& associated_ue_info_item_s::ue_type_c_::set_ue_type_choice_individual()
{
  set(types::ue_type_choice_individual);
  return c.get<event_trigger_ue_info_item_choice_individual_s>();
}
event_trigger_ue_info_item_choice_group_s& associated_ue_info_item_s::ue_type_c_::set_ue_type_choice_group()
{
  set(types::ue_type_choice_group);
  return c.get<event_trigger_ue_info_item_choice_group_s>();
}
void associated_ue_info_item_s::ue_type_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ue_type_choice_individual:
      j.write_fieldname("ueType-Choice-Individual");
      c.get<event_trigger_ue_info_item_choice_individual_s>().to_json(j);
      break;
    case types::ue_type_choice_group:
      j.write_fieldname("ueType-Choice-Group");
      c.get<event_trigger_ue_info_item_choice_group_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
  }
  j.end_obj();
}
SRSASN_CODE associated_ue_info_item_s::ue_type_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ue_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_individual_s>().pack(bref));
      break;
    case types::ue_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_group_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE associated_ue_info_item_s::ue_type_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ue_type_choice_individual:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_individual_s>().unpack(bref));
      break;
    case types::ue_type_choice_group:
      HANDLE_CODE(c.get<event_trigger_ue_info_item_choice_group_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "associated_ue_info_item_s::ue_type_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* associated_ue_info_item_s::ue_type_c_::types_opts::to_string() const
{
  static const char* names[] = {"ueType-Choice-Individual", "ueType-Choice-Group"};
  return convert_enum_idx(names, 2, value, "associated_ue_info_item_s::ue_type_c_::types");
}

// ControlOutcome-RANParameter-Item ::= SEQUENCE
SRSASN_CODE ctrl_outcome_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ctrl_outcome_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void ctrl_outcome_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format4-Indication-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format4_ind_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ric_insert_ind_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_insert_ind_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format4_ind_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ric_insert_ind_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_insert_ind_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format4_ind_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-InsertIndication-ID", ric_insert_ind_id);
  j.start_array("ranP-InsertIndication-List");
  for (const auto& e1 : ran_p_insert_ind_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ControlMessage-Format2-ControlAction-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format2_ctrl_action_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ric_ctrl_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ran_p_list.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format2_ctrl_action_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ric_ctrl_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ran_p_list.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format2_ctrl_action_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format2-ControlAction-Item");
  j.write_int("ric-ControlAction-ID", ric_ctrl_action_id);
  j.write_fieldname("ranP-List");
  ran_p_list.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-ControlOutcome-Format2-ControlOutcome-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_ctrl_outcome_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ric_ctrl_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_ctrl_outcome_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ric_ctrl_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format2_ctrl_outcome_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-ControlAction-ID", ric_ctrl_action_id);
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-IndicationMessage-Format2-RANParameter-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format2_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format2_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format2_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format2-RANParameter-Item");
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format6-Indication-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format6_ind_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ric_insert_ind_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_insert_ind_list, 0, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format6_ind_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ric_insert_ind_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_insert_ind_list, bref, 0, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format6_ind_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format6-Indication-Item");
  j.write_int("ric-InsertIndication-ID", ric_insert_ind_id);
  j.start_array("ranP-InsertIndication-List");
  for (const auto& e1 : ran_p_insert_ind_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-QueryOutcome-Format1-ItemParameters ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format1_item_params_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_value_type_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_value_type_present) {
    HANDLE_CODE(ran_param_value_type.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format1_item_params_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_value_type_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_value_type_present) {
    HANDLE_CODE(ran_param_value_type.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format1_item_params_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ran_param_value_type_present) {
    j.write_fieldname("ranParameter-valueType");
    ran_param_value_type.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-QueryOutcome-Format2-ItemParameters ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format2_item_params_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_value_type_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_value_type_present) {
    HANDLE_CODE(ran_param_value_type.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format2_item_params_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_value_type_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_value_type_present) {
    HANDLE_CODE(ran_param_value_type.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format2_item_params_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ran_param_value_type_present) {
    j.write_fieldname("ranParameter-valueType");
    ran_param_value_type.to_json(j);
  }
  j.end_obj();
}

// EntitySpecific-ranP-ControlParameters ::= SEQUENCE
SRSASN_CODE entity_specific_ran_p_ctrl_params_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE entity_specific_ran_p_ctrl_params_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void entity_specific_ran_p_ctrl_params_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
}

// EventTrigger-Cell-Info ::= SEQUENCE
SRSASN_CODE event_trigger_cell_info_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, cell_info_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_cell_info_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(cell_info_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void event_trigger_cell_info_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("cellInfo-List");
  for (const auto& e1 : cell_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// EventTrigger-UEevent-Info ::= SEQUENCE
SRSASN_CODE event_trigger_ue_event_info_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_event_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_event_info_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_event_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void event_trigger_ue_event_info_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ueEvent-List");
  for (const auto& e1 : ue_event_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// EventTrigger-UE-Info ::= SEQUENCE
SRSASN_CODE event_trigger_ue_info_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_info_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE event_trigger_ue_info_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_info_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void event_trigger_ue_info_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ueInfo-List");
  for (const auto& e1 : ue_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// MessageType-Choice ::= CHOICE
void msg_type_choice_c::destroy_()
{
  switch (type_) {
    case types::msg_type_choice_ni:
      c.destroy<msg_type_choice_ni_s>();
      break;
    case types::msg_type_choice_rrc:
      c.destroy<msg_type_choice_rrc_s>();
      break;
    default:
      break;
  }
}
void msg_type_choice_c::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::msg_type_choice_ni:
      c.init<msg_type_choice_ni_s>();
      break;
    case types::msg_type_choice_rrc:
      c.init<msg_type_choice_rrc_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
  }
}
msg_type_choice_c::msg_type_choice_c(const msg_type_choice_c& other)
{
  type_ = other.type();
  switch (type_) {
    case types::msg_type_choice_ni:
      c.init(other.c.get<msg_type_choice_ni_s>());
      break;
    case types::msg_type_choice_rrc:
      c.init(other.c.get<msg_type_choice_rrc_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
  }
}
msg_type_choice_c& msg_type_choice_c::operator=(const msg_type_choice_c& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::msg_type_choice_ni:
      c.set(other.c.get<msg_type_choice_ni_s>());
      break;
    case types::msg_type_choice_rrc:
      c.set(other.c.get<msg_type_choice_rrc_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
  }

  return *this;
}
msg_type_choice_ni_s& msg_type_choice_c::set_msg_type_choice_ni()
{
  set(types::msg_type_choice_ni);
  return c.get<msg_type_choice_ni_s>();
}
msg_type_choice_rrc_s& msg_type_choice_c::set_msg_type_choice_rrc()
{
  set(types::msg_type_choice_rrc);
  return c.get<msg_type_choice_rrc_s>();
}
void msg_type_choice_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::msg_type_choice_ni:
      j.write_fieldname("messageType-Choice-NI");
      c.get<msg_type_choice_ni_s>().to_json(j);
      break;
    case types::msg_type_choice_rrc:
      j.write_fieldname("messageType-Choice-RRC");
      c.get<msg_type_choice_rrc_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
  }
  j.end_obj();
}
SRSASN_CODE msg_type_choice_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::msg_type_choice_ni:
      HANDLE_CODE(c.get<msg_type_choice_ni_s>().pack(bref));
      break;
    case types::msg_type_choice_rrc:
      HANDLE_CODE(c.get<msg_type_choice_rrc_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE msg_type_choice_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::msg_type_choice_ni:
      HANDLE_CODE(c.get<msg_type_choice_ni_s>().unpack(bref));
      break;
    case types::msg_type_choice_rrc:
      HANDLE_CODE(c.get<msg_type_choice_rrc_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "msg_type_choice_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* msg_type_choice_c::types_opts::to_string() const
{
  static const char* names[] = {"messageType-Choice-NI", "messageType-Choice-RRC"};
  return convert_enum_idx(names, 2, value, "msg_type_choice_c::types");
}

// NeighborRelation-Info ::= SEQUENCE
SRSASN_CODE neighbor_relation_info_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(serving_cell_pci.pack(bref));
  HANDLE_CODE(serving_cell_arfcn.pack(bref));
  HANDLE_CODE(pack_dyn_seq_of(bref, neighbor_cell_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE neighbor_relation_info_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(serving_cell_pci.unpack(bref));
  HANDLE_CODE(serving_cell_arfcn.unpack(bref));
  HANDLE_CODE(unpack_dyn_seq_of(neighbor_cell_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void neighbor_relation_info_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("servingCellPCI");
  serving_cell_pci.to_json(j);
  j.write_fieldname("servingCellARFCN");
  serving_cell_arfcn.to_json(j);
  j.start_array("neighborCell-List");
  for (const auto& e1 : neighbor_cell_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// Query-RANParameter-Item ::= SEQUENCE
SRSASN_CODE query_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_definition_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE query_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_definition_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void query_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ran_param_definition_present) {
    j.write_fieldname("ranParameter-Definition");
    ran_param_definition.to_json(j);
  }
  j.end_obj();
}

// RANFunctionDefinition-Control-Action-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_ctrl_action_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_ctrl_action_params_list.size() > 0, 1));

  HANDLE_CODE(pack_integer(bref, ric_ctrl_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_ctrl_action_name.pack(bref));
  if (ran_ctrl_action_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_ctrl_action_params_list, 1, 65535, true));
  }

  if (ext) {
    HANDLE_CODE(ue_group_ctrl_action_supported.pack(bref));
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_ctrl_action_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_ctrl_action_params_list_present;
  HANDLE_CODE(bref.unpack(ran_ctrl_action_params_list_present, 1));

  HANDLE_CODE(unpack_integer(ric_ctrl_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_ctrl_action_name.unpack(bref));
  if (ran_ctrl_action_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_ctrl_action_params_list, bref, 1, 65535, true));
  }

  if (ext) {
    HANDLE_CODE(ue_group_ctrl_action_supported.unpack(bref));
  }
  return SRSASN_SUCCESS;
}
void ran_function_definition_ctrl_action_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-ControlAction-ID", ric_ctrl_action_id);
  j.write_str("ric-ControlAction-Name", ric_ctrl_action_name.to_string());
  if (ran_ctrl_action_params_list.size() > 0) {
    j.start_array("ran-ControlActionParameters-List");
    for (const auto& e1 : ran_ctrl_action_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ext) {
    j.write_str("ueGroup-ControlAction-Supported", ue_group_ctrl_action_supported.to_string());
  }
  j.end_obj();
}

const char* ran_function_definition_ctrl_action_item_s::ue_group_ctrl_action_supported_opts::to_string() const
{
  static const char* names[] = {"true", "false"};
  return convert_enum_idx(
      names, 2, value, "ran_function_definition_ctrl_action_item_s::ue_group_ctrl_action_supported_e_");
}

// RANFunctionDefinition-EventTrigger-Breakpoint-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_event_trigger_breakpoint_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_call_process_breakpoint_params_list.size() > 0, 1));

  HANDLE_CODE(pack_integer(bref, call_process_breakpoint_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(call_process_breakpoint_name.pack(bref));
  if (ran_call_process_breakpoint_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_call_process_breakpoint_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_event_trigger_breakpoint_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_call_process_breakpoint_params_list_present;
  HANDLE_CODE(bref.unpack(ran_call_process_breakpoint_params_list_present, 1));

  HANDLE_CODE(unpack_integer(call_process_breakpoint_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(call_process_breakpoint_name.unpack(bref));
  if (ran_call_process_breakpoint_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_call_process_breakpoint_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_event_trigger_breakpoint_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("callProcessBreakpoint-ID", call_process_breakpoint_id);
  j.write_str("callProcessBreakpoint-Name", call_process_breakpoint_name.to_string());
  if (ran_call_process_breakpoint_params_list.size() > 0) {
    j.start_array("ran-CallProcessBreakpointParameters-List");
    for (const auto& e1 : ran_call_process_breakpoint_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-Insert-Indication-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_insert_ind_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_insert_ind_params_list.size() > 0, 1));

  HANDLE_CODE(pack_integer(bref, ric_insert_ind_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_insert_ind_name.pack(bref));
  if (ran_insert_ind_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_insert_ind_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_insert_ind_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_insert_ind_params_list_present;
  HANDLE_CODE(bref.unpack(ran_insert_ind_params_list_present, 1));

  HANDLE_CODE(unpack_integer(ric_insert_ind_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_insert_ind_name.unpack(bref));
  if (ran_insert_ind_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_insert_ind_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_insert_ind_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-InsertIndication-ID", ric_insert_ind_id);
  j.write_str("ric-InsertIndication-Name", ric_insert_ind_name.to_string());
  if (ran_insert_ind_params_list.size() > 0) {
    j.start_array("ran-InsertIndicationParameters-List");
    for (const auto& e1 : ran_insert_ind_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-Policy-Action-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_policy_action_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_policy_action_params_list.size() > 0, 1));
  HANDLE_CODE(bref.pack(ran_policy_condition_params_list.size() > 0, 1));

  HANDLE_CODE(pack_integer(bref, ric_policy_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_policy_action_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_action_definition_format_type, false, true));
  if (ran_policy_action_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_policy_action_params_list, 1, 65535, true));
  }
  if (ran_policy_condition_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_policy_condition_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_policy_action_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_policy_action_params_list_present;
  HANDLE_CODE(bref.unpack(ran_policy_action_params_list_present, 1));
  bool ran_policy_condition_params_list_present;
  HANDLE_CODE(bref.unpack(ran_policy_condition_params_list_present, 1));

  HANDLE_CODE(unpack_integer(ric_policy_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ric_policy_action_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_action_definition_format_type, bref, false, true));
  if (ran_policy_action_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_policy_action_params_list, bref, 1, 65535, true));
  }
  if (ran_policy_condition_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_policy_condition_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_policy_action_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-PolicyAction-ID", ric_policy_action_id);
  j.write_str("ric-PolicyAction-Name", ric_policy_action_name.to_string());
  j.write_int("ric-ActionDefinitionFormat-Type", ric_action_definition_format_type);
  if (ran_policy_action_params_list.size() > 0) {
    j.start_array("ran-PolicyActionParameters-List");
    for (const auto& e1 : ran_policy_action_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ran_policy_condition_params_list.size() > 0) {
    j.start_array("ran-PolicyConditionParameters-List");
    for (const auto& e1 : ran_policy_condition_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANParameter-STRUCTURE-Item ::= SEQUENCE
SRSASN_CODE ran_param_structure_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_structure_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_structure_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
}

// Report-RANParameter-Item ::= SEQUENCE
SRSASN_CODE report_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE report_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void report_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// RIC-PolicyAction ::= SEQUENCE
SRSASN_CODE ric_policy_action_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_params_list.size() > 0, 1));

  HANDLE_CODE(pack_integer(bref, ric_policy_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (ran_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_params_list, 1, 65535, true));
  }

  if (ext) {
    HANDLE_CODE(bref.pack(ric_policy_decision_present, 1));

    if (ric_policy_decision_present) {
      HANDLE_CODE(ric_policy_decision.pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ric_policy_action_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_params_list_present;
  HANDLE_CODE(bref.unpack(ran_params_list_present, 1));

  HANDLE_CODE(unpack_integer(ric_policy_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (ran_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_params_list, bref, 1, 65535, true));
  }

  if (ext) {
    HANDLE_CODE(bref.unpack(ric_policy_decision_present, 1));

    if (ric_policy_decision_present) {
      HANDLE_CODE(ric_policy_decision.unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void ric_policy_action_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-PolicyAction-ID", ric_policy_action_id);
  if (ran_params_list.size() > 0) {
    j.start_array("ranParameters-List");
    for (const auto& e1 : ran_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ext) {
    if (ric_policy_decision_present) {
      j.write_str("ric-PolicyDecision", ric_policy_decision.to_string());
    }
  }
  j.end_obj();
}

const char* ric_policy_action_s::ric_policy_decision_opts::to_string() const
{
  static const char* names[] = {"accept", "reject"};
  return convert_enum_idx(names, 2, value, "ric_policy_action_s::ric_policy_decision_e_");
}

// TriggerType-Choice ::= CHOICE
void trigger_type_choice_c::destroy_()
{
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      c.destroy<trigger_type_choice_rrc_state_s>();
      break;
    case types::trigger_type_choice_ue_id:
      c.destroy<trigger_type_choice_ue_id_s>();
      break;
    case types::trigger_type_choice_l2state:
      c.destroy<trigger_type_choice_l2state_s>();
      break;
    case types::trigger_type_choice_ue_context:
      c.destroy<trigger_type_choice_ue_context_s>();
      break;
    case types::trigger_type_choice_l2_ma_csch_chg:
      c.destroy<trigger_type_choice_l2_ma_csch_chg_s>();
      break;
    default:
      break;
  }
}
void trigger_type_choice_c::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      c.init<trigger_type_choice_rrc_state_s>();
      break;
    case types::trigger_type_choice_ue_id:
      c.init<trigger_type_choice_ue_id_s>();
      break;
    case types::trigger_type_choice_l2state:
      c.init<trigger_type_choice_l2state_s>();
      break;
    case types::trigger_type_choice_ue_context:
      c.init<trigger_type_choice_ue_context_s>();
      break;
    case types::trigger_type_choice_l2_ma_csch_chg:
      c.init<trigger_type_choice_l2_ma_csch_chg_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
  }
}
trigger_type_choice_c::trigger_type_choice_c(const trigger_type_choice_c& other)
{
  type_ = other.type();
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      c.init(other.c.get<trigger_type_choice_rrc_state_s>());
      break;
    case types::trigger_type_choice_ue_id:
      c.init(other.c.get<trigger_type_choice_ue_id_s>());
      break;
    case types::trigger_type_choice_l2state:
      c.init(other.c.get<trigger_type_choice_l2state_s>());
      break;
    case types::trigger_type_choice_ue_context:
      c.init(other.c.get<trigger_type_choice_ue_context_s>());
      break;
    case types::trigger_type_choice_l2_ma_csch_chg:
      c.init(other.c.get<trigger_type_choice_l2_ma_csch_chg_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
  }
}
trigger_type_choice_c& trigger_type_choice_c::operator=(const trigger_type_choice_c& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      c.set(other.c.get<trigger_type_choice_rrc_state_s>());
      break;
    case types::trigger_type_choice_ue_id:
      c.set(other.c.get<trigger_type_choice_ue_id_s>());
      break;
    case types::trigger_type_choice_l2state:
      c.set(other.c.get<trigger_type_choice_l2state_s>());
      break;
    case types::trigger_type_choice_ue_context:
      c.set(other.c.get<trigger_type_choice_ue_context_s>());
      break;
    case types::trigger_type_choice_l2_ma_csch_chg:
      c.set(other.c.get<trigger_type_choice_l2_ma_csch_chg_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
  }

  return *this;
}
trigger_type_choice_rrc_state_s& trigger_type_choice_c::set_trigger_type_choice_rrc_state()
{
  set(types::trigger_type_choice_rrc_state);
  return c.get<trigger_type_choice_rrc_state_s>();
}
trigger_type_choice_ue_id_s& trigger_type_choice_c::set_trigger_type_choice_ue_id()
{
  set(types::trigger_type_choice_ue_id);
  return c.get<trigger_type_choice_ue_id_s>();
}
trigger_type_choice_l2state_s& trigger_type_choice_c::set_trigger_type_choice_l2state()
{
  set(types::trigger_type_choice_l2state);
  return c.get<trigger_type_choice_l2state_s>();
}
trigger_type_choice_ue_context_s& trigger_type_choice_c::set_trigger_type_choice_ue_context()
{
  set(types::trigger_type_choice_ue_context);
  return c.get<trigger_type_choice_ue_context_s>();
}
trigger_type_choice_l2_ma_csch_chg_s& trigger_type_choice_c::set_trigger_type_choice_l2_ma_csch_chg()
{
  set(types::trigger_type_choice_l2_ma_csch_chg);
  return c.get<trigger_type_choice_l2_ma_csch_chg_s>();
}
void trigger_type_choice_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      j.write_fieldname("triggerType-Choice-RRCstate");
      c.get<trigger_type_choice_rrc_state_s>().to_json(j);
      break;
    case types::trigger_type_choice_ue_id:
      j.write_fieldname("triggerType-Choice-UEID");
      c.get<trigger_type_choice_ue_id_s>().to_json(j);
      break;
    case types::trigger_type_choice_l2state:
      j.write_fieldname("triggerType-Choice-L2state");
      c.get<trigger_type_choice_l2state_s>().to_json(j);
      break;
    case types::trigger_type_choice_ue_context:
      j.write_fieldname("triggerType-Choice-UEcontext");
      c.get<trigger_type_choice_ue_context_s>().to_json(j);
      break;
    case types::trigger_type_choice_l2_ma_csch_chg:
      j.write_fieldname("triggerType-Choice-L2MACschChg");
      c.get<trigger_type_choice_l2_ma_csch_chg_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
  }
  j.end_obj();
}
SRSASN_CODE trigger_type_choice_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      HANDLE_CODE(c.get<trigger_type_choice_rrc_state_s>().pack(bref));
      break;
    case types::trigger_type_choice_ue_id:
      HANDLE_CODE(c.get<trigger_type_choice_ue_id_s>().pack(bref));
      break;
    case types::trigger_type_choice_l2state:
      HANDLE_CODE(c.get<trigger_type_choice_l2state_s>().pack(bref));
      break;
    case types::trigger_type_choice_ue_context: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<trigger_type_choice_ue_context_s>().pack(bref));
    } break;
    case types::trigger_type_choice_l2_ma_csch_chg: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<trigger_type_choice_l2_ma_csch_chg_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE trigger_type_choice_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::trigger_type_choice_rrc_state:
      HANDLE_CODE(c.get<trigger_type_choice_rrc_state_s>().unpack(bref));
      break;
    case types::trigger_type_choice_ue_id:
      HANDLE_CODE(c.get<trigger_type_choice_ue_id_s>().unpack(bref));
      break;
    case types::trigger_type_choice_l2state:
      HANDLE_CODE(c.get<trigger_type_choice_l2state_s>().unpack(bref));
      break;
    case types::trigger_type_choice_ue_context: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<trigger_type_choice_ue_context_s>().unpack(bref));
    } break;
    case types::trigger_type_choice_l2_ma_csch_chg: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<trigger_type_choice_l2_ma_csch_chg_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "trigger_type_choice_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* trigger_type_choice_c::types_opts::to_string() const
{
  static const char* names[] = {"triggerType-Choice-RRCstate",
                                "triggerType-Choice-UEID",
                                "triggerType-Choice-L2state",
                                "triggerType-Choice-UEcontext",
                                "triggerType-Choice-L2MACschChg"};
  return convert_enum_idx(names, 5, value, "trigger_type_choice_c::types");
}

// UEGroupDefinitionIdentifier-Item ::= SEQUENCE
SRSASN_CODE ue_group_definition_id_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ue_group_definition_id_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void ue_group_definition_id_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// Associated-UE-Info ::= SEQUENCE
SRSASN_CODE associated_ue_info_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, associated_ue_info_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE associated_ue_info_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(associated_ue_info_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void associated_ue_info_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("associatedUEInfo-List");
  for (const auto& e1 : associated_ue_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// CellIdentification-RANParameter-Item ::= SEQUENCE
SRSASN_CODE cell_identif_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE cell_identif_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void cell_identif_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format1_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format2-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format2_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_policy_condition_definition.size() > 0, 1));

  HANDLE_CODE(ric_policy_action.pack(bref));
  if (ric_policy_condition_definition.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ric_policy_condition_definition, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format2_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ric_policy_condition_definition_present;
  HANDLE_CODE(bref.unpack(ric_policy_condition_definition_present, 1));

  HANDLE_CODE(ric_policy_action.unpack(bref));
  if (ric_policy_condition_definition_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ric_policy_condition_definition, bref, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format2_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-PolicyAction");
  ric_policy_action.to_json(j);
  if (ric_policy_condition_definition.size() > 0) {
    j.start_array("ric-PolicyConditionDefinition");
    for (const auto& e1 : ric_policy_condition_definition) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format3-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format3_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format3_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format3_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format4-Style-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format4_style_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, requested_insert_style_type, false, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_ind_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format4_style_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(requested_insert_style_type, bref, false, true));
  HANDLE_CODE(unpack_dyn_seq_of(ric_insert_ind_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format4_style_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("requested-Insert-Style-Type", requested_insert_style_type);
  j.start_array("ric-InsertIndication-List");
  for (const auto& e1 : ric_insert_ind_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ControlMessage-Format2-Style-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format2_style_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, indicated_ctrl_style_type, false, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_action_list, 1, 63, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format2_style_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(indicated_ctrl_style_type, bref, false, true));
  HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_action_list, bref, 1, 63, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format2_style_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format2-Style-Item");
  j.write_int("indicated-Control-Style-Type", indicated_ctrl_style_type);
  j.start_array("ric-ControlAction-List");
  for (const auto& e1 : ric_ctrl_action_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-ControlOutcome-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format1_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-value");
  ran_param_value.to_json(j);
  j.end_obj();
}

// E2SM-RC-ControlOutcome-Format2-Style-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_style_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, indicated_ctrl_style_type, false, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_outcome_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_style_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(indicated_ctrl_style_type, bref, false, true));
  HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_outcome_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format2_style_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("indicated-Control-Style-Type", indicated_ctrl_style_type);
  j.start_array("ric-ControlOutcome-List");
  for (const auto& e1 : ric_ctrl_outcome_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ControlOutcome-Format3-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format3_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format3_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format3_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
}

// E2SM-RC-EntityFilter ::= SEQUENCE
SRSASN_CODE e2sm_rc_entity_filt_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, entity_filt_id, (uint16_t)1u, (uint16_t)255u, true, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, entity_filt_definition, 1, 255, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, entity_specific_ctrl_ran_p_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_entity_filt_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(entity_filt_id, bref, (uint16_t)1u, (uint16_t)255u, true, true));
  HANDLE_CODE(unpack_dyn_seq_of(entity_filt_definition, bref, 1, 255, true));
  HANDLE_CODE(unpack_dyn_seq_of(entity_specific_ctrl_ran_p_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_entity_filt_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("entityFilter-ID", entity_filt_id);
  j.start_array("entityFilter-Definition");
  for (const auto& e1 : entity_filt_definition) {
    e1.to_json(j);
  }
  j.end_array();
  j.start_array("entitySpecificControlRanP-List");
  for (const auto& e1 : entity_specific_ctrl_ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(msg_direction_present, 1));
  HANDLE_CODE(bref.pack(associated_ue_info_present, 1));
  HANDLE_CODE(bref.pack(associated_ue_event_present, 1));
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ric_event_trigger_condition_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(msg_type.pack(bref));
  if (msg_direction_present) {
    HANDLE_CODE(msg_direction.pack(bref));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.pack(bref));
  }
  if (associated_ue_event_present) {
    HANDLE_CODE(associated_ue_event.pack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(msg_direction_present, 1));
  HANDLE_CODE(bref.unpack(associated_ue_info_present, 1));
  HANDLE_CODE(bref.unpack(associated_ue_event_present, 1));
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ric_event_trigger_condition_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(msg_type.unpack(bref));
  if (msg_direction_present) {
    HANDLE_CODE(msg_direction.unpack(bref));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.unpack(bref));
  }
  if (associated_ue_event_present) {
    HANDLE_CODE(associated_ue_event.unpack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format1_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-eventTriggerCondition-ID", ric_event_trigger_condition_id);
  j.write_fieldname("messageType");
  msg_type.to_json(j);
  if (msg_direction_present) {
    j.write_str("messageDirection", msg_direction.to_string());
  }
  if (associated_ue_info_present) {
    j.write_fieldname("associatedUEInfo");
    associated_ue_info.to_json(j);
  }
  if (associated_ue_event_present) {
    j.write_fieldname("associatedUEEvent");
    associated_ue_event.to_json(j);
  }
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

const char* e2sm_rc_event_trigger_format1_item_s::msg_direction_opts::to_string() const
{
  static const char* names[] = {"incoming", "outgoing"};
  return convert_enum_idx(names, 2, value, "e2sm_rc_event_trigger_format1_item_s::msg_direction_e_");
}

// E2SM-RC-EventTrigger-Format3-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format3_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(associated_cell_info_present, 1));
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ric_event_trigger_condition_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_integer(bref, e2_node_info_change_id, (uint16_t)1u, (uint16_t)512u, true, true));
  if (associated_cell_info_present) {
    HANDLE_CODE(associated_cell_info.pack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format3_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(associated_cell_info_present, 1));
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ric_event_trigger_condition_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_integer(e2_node_info_change_id, bref, (uint16_t)1u, (uint16_t)512u, true, true));
  if (associated_cell_info_present) {
    HANDLE_CODE(associated_cell_info.unpack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format3_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-eventTriggerCondition-ID", ric_event_trigger_condition_id);
  j.write_int("e2NodeInfoChange-ID", e2_node_info_change_id);
  if (associated_cell_info_present) {
    j.write_fieldname("associatedCellInfo");
    associated_cell_info.to_json(j);
  }
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format4-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format4_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(associated_ue_info_present, 1));
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(pack_integer(bref, ric_event_trigger_condition_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(trigger_type.pack(bref));
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.pack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format4_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(associated_ue_info_present, 1));
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(unpack_integer(ric_event_trigger_condition_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(trigger_type.unpack(bref));
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.unpack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format4_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-eventTriggerCondition-ID", ric_event_trigger_condition_id);
  j.write_fieldname("triggerType");
  trigger_type.to_json(j);
  if (associated_ue_info_present) {
    j.write_fieldname("associatedUEInfo");
    associated_ue_info.to_json(j);
  }
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// E2SM-RC-IndicationMessage-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format1_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format1-Item");
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format2-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format2_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ue_id.pack(bref));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 1, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format2_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ue_id.unpack(bref));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 1, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format2_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format2-Item");
  j.write_fieldname("ueID");
  ue_id.to_json(j);
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format3-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format3_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(cell_context_info.size() > 0, 1));
  HANDLE_CODE(bref.pack(cell_deleted_present, 1));
  HANDLE_CODE(bref.pack(neighbor_relation_table_present, 1));

  HANDLE_CODE(cell_global_id.pack(bref));
  if (cell_context_info.size() > 0) {
    HANDLE_CODE(cell_context_info.pack(bref));
  }
  if (cell_deleted_present) {
    HANDLE_CODE(bref.pack(cell_deleted, 1));
  }
  if (neighbor_relation_table_present) {
    HANDLE_CODE(neighbor_relation_table.pack(bref));
  }

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format3_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool cell_context_info_present;
  HANDLE_CODE(bref.unpack(cell_context_info_present, 1));
  HANDLE_CODE(bref.unpack(cell_deleted_present, 1));
  HANDLE_CODE(bref.unpack(neighbor_relation_table_present, 1));

  HANDLE_CODE(cell_global_id.unpack(bref));
  if (cell_context_info_present) {
    HANDLE_CODE(cell_context_info.unpack(bref));
  }
  if (cell_deleted_present) {
    HANDLE_CODE(bref.unpack(cell_deleted, 1));
  }
  if (neighbor_relation_table_present) {
    HANDLE_CODE(neighbor_relation_table.unpack(bref));
  }

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format3_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format3-Item");
  j.write_fieldname("cellGlobal-ID");
  cell_global_id.to_json(j);
  if (cell_context_info.size() > 0) {
    j.write_str("cellContextInfo", cell_context_info.to_string());
  }
  if (cell_deleted_present) {
    j.write_bool("cellDeleted", cell_deleted);
  }
  if (neighbor_relation_table_present) {
    j.write_fieldname("neighborRelation-Table");
    neighbor_relation_table.to_json(j);
  }
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format5-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format5_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format5_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format5_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format5-Item");
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format6-Style-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format6_style_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, indicated_insert_style_type, false, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_ind_list, 1, 63, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format6_style_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(indicated_insert_style_type, bref, false, true));
  HANDLE_CODE(unpack_dyn_seq_of(ric_insert_ind_list, bref, 1, 63, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format6_style_item_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format6-Style-Item");
  j.write_int("indicated-Insert-Style-Type", indicated_insert_style_type);
  j.start_array("ric-InsertIndication-List");
  for (const auto& e1 : ric_insert_ind_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-QueryDefinition-Format1-Item ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_definition_format1_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_definition_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_definition_format1_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_definition_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_definition_format1_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  if (ran_param_definition_present) {
    j.write_fieldname("ranParameter-Definition");
    ran_param_definition.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-QueryOutcome-Format1-ItemCell ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format1_item_cell_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(neighbor_relation_table_present, 1));

  HANDLE_CODE(cell_global_id.pack(bref));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 0, 65535, true));
  if (neighbor_relation_table_present) {
    HANDLE_CODE(neighbor_relation_table.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format1_item_cell_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(neighbor_relation_table_present, 1));

  HANDLE_CODE(cell_global_id.unpack(bref));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 0, 65535, true));
  if (neighbor_relation_table_present) {
    HANDLE_CODE(neighbor_relation_table.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format1_item_cell_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("cellGlobal-ID");
  cell_global_id.to_json(j);
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (neighbor_relation_table_present) {
    j.write_fieldname("neighborRelation-Table");
    neighbor_relation_table.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-QueryOutcome-Format2-ItemUE ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format2_item_ue_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ue_filt_id_present, 1));

  HANDLE_CODE(ue_id.pack(bref));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 0, 65535, true));
  if (ue_filt_id_present) {
    HANDLE_CODE(pack_integer(bref, ue_filt_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format2_item_ue_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ue_filt_id_present, 1));

  HANDLE_CODE(ue_id.unpack(bref));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 0, 65535, true));
  if (ue_filt_id_present) {
    HANDLE_CODE(unpack_integer(ue_filt_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format2_item_ue_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ueID");
  ue_id.to_json(j);
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (ue_filt_id_present) {
    j.write_int("ueFilterID", ue_filt_id);
  }
  j.end_obj();
}

// EntityAgnostic-ranP-ControlParameters ::= SEQUENCE
SRSASN_CODE entity_agnostic_ran_p_ctrl_params_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE entity_agnostic_ran_p_ctrl_params_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_value_type.unpack(bref));

  return SRSASN_SUCCESS;
}
void entity_agnostic_ran_p_ctrl_params_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_fieldname("ranParameter-valueType");
  ran_param_value_type.to_json(j);
  j.end_obj();
}

// L2Parameters-RANParameter-Item ::= SEQUENCE
SRSASN_CODE l2_params_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE l2_params_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void l2_params_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// RANFunctionDefinition-Control-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_ctrl_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_ctrl_action_list.size() > 0, 1));
  HANDLE_CODE(bref.pack(ric_call_process_id_format_type_present, 1));
  HANDLE_CODE(bref.pack(ran_ctrl_outcome_params_list.size() > 0, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_style_type, false, true));
  HANDLE_CODE(ric_ctrl_style_name.pack(bref));
  if (ric_ctrl_action_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_action_list, 1, 65535, true));
  }
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_hdr_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_msg_format_type, false, true));
  if (ric_call_process_id_format_type_present) {
    HANDLE_CODE(pack_unconstrained_integer(bref, ric_call_process_id_format_type, false, true));
  }
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ctrl_outcome_format_type, false, true));
  if (ran_ctrl_outcome_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_ctrl_outcome_params_list, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_ctrl_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ric_ctrl_action_list_present;
  HANDLE_CODE(bref.unpack(ric_ctrl_action_list_present, 1));
  HANDLE_CODE(bref.unpack(ric_call_process_id_format_type_present, 1));
  bool ran_ctrl_outcome_params_list_present;
  HANDLE_CODE(bref.unpack(ran_ctrl_outcome_params_list_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_style_type, bref, false, true));
  HANDLE_CODE(ric_ctrl_style_name.unpack(bref));
  if (ric_ctrl_action_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_action_list, bref, 1, 65535, true));
  }
  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_hdr_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_msg_format_type, bref, false, true));
  if (ric_call_process_id_format_type_present) {
    HANDLE_CODE(unpack_unconstrained_integer(ric_call_process_id_format_type, bref, false, true));
  }
  HANDLE_CODE(unpack_unconstrained_integer(ric_ctrl_outcome_format_type, bref, false, true));
  if (ran_ctrl_outcome_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_ctrl_outcome_params_list, bref, 1, 255, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_ctrl_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-ControlStyle-Type", ric_ctrl_style_type);
  j.write_str("ric-ControlStyle-Name", ric_ctrl_style_name.to_string());
  if (ric_ctrl_action_list.size() > 0) {
    j.start_array("ric-ControlAction-List");
    for (const auto& e1 : ric_ctrl_action_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.write_int("ric-ControlHeaderFormat-Type", ric_ctrl_hdr_format_type);
  j.write_int("ric-ControlMessageFormat-Type", ric_ctrl_msg_format_type);
  if (ric_call_process_id_format_type_present) {
    j.write_int("ric-CallProcessIDFormat-Type", ric_call_process_id_format_type);
  }
  j.write_int("ric-ControlOutcomeFormat-Type", ric_ctrl_outcome_format_type);
  if (ran_ctrl_outcome_params_list.size() > 0) {
    j.start_array("ran-ControlOutcomeParameters-List");
    for (const auto& e1 : ran_ctrl_outcome_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-EventTrigger-CallProcess-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_event_trigger_call_process_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, call_process_type_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(call_process_type_name.pack(bref));
  HANDLE_CODE(pack_dyn_seq_of(bref, call_process_breakpoints_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_event_trigger_call_process_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(call_process_type_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(call_process_type_name.unpack(bref));
  HANDLE_CODE(unpack_dyn_seq_of(call_process_breakpoints_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_event_trigger_call_process_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("callProcessType-ID", call_process_type_id);
  j.write_str("callProcessType-Name", call_process_type_name.to_string());
  j.start_array("callProcessBreakpoints-List");
  for (const auto& e1 : call_process_breakpoints_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-EventTrigger-Style-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_event_trigger_style_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_event_trigger_style_type, false, true));
  HANDLE_CODE(ric_event_trigger_style_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_event_trigger_format_type, false, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_event_trigger_style_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(ric_event_trigger_style_type, bref, false, true));
  HANDLE_CODE(ric_event_trigger_style_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_event_trigger_format_type, bref, false, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_event_trigger_style_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-EventTriggerStyle-Type", ric_event_trigger_style_type);
  j.write_str("ric-EventTriggerStyle-Name", ric_event_trigger_style_name.to_string());
  j.write_int("ric-EventTriggerFormat-Type", ric_event_trigger_format_type);
  j.end_obj();
}

// RANFunctionDefinition-Insert-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_insert_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_insert_ind_list.size() > 0, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_insert_style_type, false, true));
  HANDLE_CODE(ric_insert_style_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_supported_event_trigger_style_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_action_definition_format_type, false, true));
  if (ric_insert_ind_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_ind_list, 1, 65535, true));
  }
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ind_hdr_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ind_msg_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_call_process_id_format_type, false, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_insert_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ric_insert_ind_list_present;
  HANDLE_CODE(bref.unpack(ric_insert_ind_list_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_insert_style_type, bref, false, true));
  HANDLE_CODE(ric_insert_style_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_supported_event_trigger_style_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_action_definition_format_type, bref, false, true));
  if (ric_insert_ind_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ric_insert_ind_list, bref, 1, 65535, true));
  }
  HANDLE_CODE(unpack_unconstrained_integer(ric_ind_hdr_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_ind_msg_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_call_process_id_format_type, bref, false, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_insert_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-InsertStyle-Type", ric_insert_style_type);
  j.write_str("ric-InsertStyle-Name", ric_insert_style_name.to_string());
  j.write_int("ric-SupportedEventTriggerStyle-Type", ric_supported_event_trigger_style_type);
  j.write_int("ric-ActionDefinitionFormat-Type", ric_action_definition_format_type);
  if (ric_insert_ind_list.size() > 0) {
    j.start_array("ric-InsertIndication-List");
    for (const auto& e1 : ric_insert_ind_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.write_int("ric-IndicationHeaderFormat-Type", ric_ind_hdr_format_type);
  j.write_int("ric-IndicationMessageFormat-Type", ric_ind_msg_format_type);
  j.write_int("ric-CallProcessIDFormat-Type", ric_call_process_id_format_type);
  j.end_obj();
}

// RANFunctionDefinition-Policy-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_policy_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_policy_action_list.size() > 0, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_policy_style_type, false, true));
  HANDLE_CODE(ric_policy_style_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_supported_event_trigger_style_type, false, true));
  if (ric_policy_action_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ric_policy_action_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_policy_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ric_policy_action_list_present;
  HANDLE_CODE(bref.unpack(ric_policy_action_list_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_policy_style_type, bref, false, true));
  HANDLE_CODE(ric_policy_style_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_supported_event_trigger_style_type, bref, false, true));
  if (ric_policy_action_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ric_policy_action_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_policy_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-PolicyStyle-Type", ric_policy_style_type);
  j.write_str("ric-PolicyStyle-Name", ric_policy_style_name.to_string());
  j.write_int("ric-SupportedEventTriggerStyle-Type", ric_supported_event_trigger_style_type);
  if (ric_policy_action_list.size() > 0) {
    j.start_array("ric-PolicyAction-List");
    for (const auto& e1 : ric_policy_action_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-Query-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_query_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_query_params_list.size() > 0, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_query_style_type, false, true));
  HANDLE_CODE(ric_query_style_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_query_hdr_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_query_definition_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_query_outcome_format_type, false, true));
  if (ran_query_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_query_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_query_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_query_params_list_present;
  HANDLE_CODE(bref.unpack(ran_query_params_list_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_query_style_type, bref, false, true));
  HANDLE_CODE(ric_query_style_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_query_hdr_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_query_definition_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_query_outcome_format_type, bref, false, true));
  if (ran_query_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_query_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_query_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-QueryStyle-Type", ric_query_style_type);
  j.write_str("ric-QueryStyle-Name", ric_query_style_name.to_string());
  j.write_int("ric-QueryHeaderFormat-Type", ric_query_hdr_format_type);
  j.write_int("ric-QueryDefinitionFormat-Type", ric_query_definition_format_type);
  j.write_int("ric-QueryOutcomeFormat-Type", ric_query_outcome_format_type);
  if (ran_query_params_list.size() > 0) {
    j.start_array("ran-QueryParameters-List");
    for (const auto& e1 : ran_query_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-Report-Item ::= SEQUENCE
SRSASN_CODE ran_function_definition_report_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_report_params_list.size() > 0, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_report_style_type, false, true));
  HANDLE_CODE(ric_report_style_name.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_supported_event_trigger_style_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_report_action_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ind_hdr_format_type, false, true));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_ind_msg_format_type, false, true));
  if (ran_report_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_report_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_report_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_report_params_list_present;
  HANDLE_CODE(bref.unpack(ran_report_params_list_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_report_style_type, bref, false, true));
  HANDLE_CODE(ric_report_style_name.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_supported_event_trigger_style_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_report_action_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_ind_hdr_format_type, bref, false, true));
  HANDLE_CODE(unpack_unconstrained_integer(ric_ind_msg_format_type, bref, false, true));
  if (ran_report_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_report_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_report_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-ReportStyle-Type", ric_report_style_type);
  j.write_str("ric-ReportStyle-Name", ric_report_style_name.to_string());
  j.write_int("ric-SupportedEventTriggerStyle-Type", ric_supported_event_trigger_style_type);
  j.write_int("ric-ReportActionFormat-Type", ric_report_action_format_type);
  j.write_int("ric-IndicationHeaderFormat-Type", ric_ind_hdr_format_type);
  j.write_int("ric-IndicationMessageFormat-Type", ric_ind_msg_format_type);
  if (ran_report_params_list.size() > 0) {
    j.start_array("ran-ReportParameters-List");
    for (const auto& e1 : ran_report_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANParameter-STRUCTURE ::= SEQUENCE
SRSASN_CODE ran_param_structure_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(seq_of_ran_params.size() > 0, 1));

  if (seq_of_ran_params.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, seq_of_ran_params, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_structure_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool seq_of_ran_params_present;
  HANDLE_CODE(bref.unpack(seq_of_ran_params_present, 1));

  if (seq_of_ran_params_present) {
    HANDLE_CODE(unpack_dyn_seq_of(seq_of_ran_params, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_param_structure_s::to_json(json_writer& j) const
{
  j.start_obj();
  if (seq_of_ran_params.size() > 0) {
    j.start_array("sequence-of-ranParameters");
    for (const auto& e1 : seq_of_ran_params) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// UE-Group-Definition ::= SEQUENCE
SRSASN_CODE ue_group_definition_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_group_definition_id_list, 1, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ue_group_definition_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_group_definition_id_list, bref, 1, 255, true));

  return SRSASN_SUCCESS;
}
void ue_group_definition_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ueGroupDefinitionIdentifier-LIST");
  for (const auto& e1 : ue_group_definition_id_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// UEIdentification-RANParameter-Item ::= SEQUENCE
SRSASN_CODE ue_identif_ran_param_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));

  if (ext) {
    HANDLE_CODE(bref.pack(ran_param_definition.is_present(), 1));

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ue_identif_ran_param_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));

  if (ext) {
    unpack_presence_flag(ran_param_definition, bref);

    if (ran_param_definition.is_present()) {
      HANDLE_CODE(ran_param_definition->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void ue_identif_ran_param_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ext) {
    if (ran_param_definition.is_present()) {
      j.write_fieldname("ranParameter-Definition");
      ran_param_definition->to_json(j);
    }
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_to_be_reported_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_to_be_reported_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranP-ToBeReported-List");
  for (const auto& e1 : ran_p_to_be_reported_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_policy_conditions_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_policy_conditions_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-PolicyConditions-List");
  for (const auto& e1 : ric_policy_conditions_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ue_id_present, 1));

  HANDLE_CODE(pack_integer(bref, ric_insert_ind_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_insert_ind_list, 1, 65535, true));
  if (ue_id_present) {
    HANDLE_CODE(ue_id.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ue_id_present, 1));

  HANDLE_CODE(unpack_integer(ric_insert_ind_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_insert_ind_list, bref, 1, 65535, true));
  if (ue_id_present) {
    HANDLE_CODE(ue_id.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format3_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-InsertIndication-ID", ric_insert_ind_id);
  j.start_array("ranP-InsertIndication-List");
  for (const auto& e1 : ran_p_insert_ind_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (ue_id_present) {
    j.write_fieldname("ueID");
    ue_id.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-ActionDefinition-Format4 ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_format4_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ue_id_present, 1));

  HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_style_list, 1, 63, true));
  if (ue_id_present) {
    HANDLE_CODE(ue_id.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_format4_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ue_id_present, 1));

  HANDLE_CODE(unpack_dyn_seq_of(ric_insert_style_list, bref, 1, 63, true));
  if (ue_id_present) {
    HANDLE_CODE(ue_id.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_format4_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-InsertStyle-List");
  for (const auto& e1 : ric_insert_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (ue_id_present) {
    j.write_fieldname("ueID");
    ue_id.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-CallProcessID-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_call_process_id_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ric_call_process_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_call_process_id_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ric_call_process_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_call_process_id_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-callProcess-ID", ric_call_process_id);
  j.end_obj();
}

// E2SM-RC-ControlHeader-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_hdr_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_ctrl_decision_present, 1));

  HANDLE_CODE(ue_id.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_style_type, false, true));
  HANDLE_CODE(pack_integer(bref, ric_ctrl_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (ric_ctrl_decision_present) {
    HANDLE_CODE(ric_ctrl_decision.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_hdr_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ric_ctrl_decision_present, 1));

  HANDLE_CODE(ue_id.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_style_type, bref, false, true));
  HANDLE_CODE(unpack_integer(ric_ctrl_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (ric_ctrl_decision_present) {
    HANDLE_CODE(ric_ctrl_decision.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_hdr_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ueID");
  ue_id.to_json(j);
  j.write_int("ric-Style-Type", ric_style_type);
  j.write_int("ric-ControlAction-ID", ric_ctrl_action_id);
  if (ric_ctrl_decision_present) {
    j.write_str("ric-ControlDecision", ric_ctrl_decision.to_string());
  }
  j.end_obj();
}

const char* e2sm_rc_ctrl_hdr_format1_s::ric_ctrl_decision_opts::to_string() const
{
  static const char* names[] = {"accept", "reject"};
  return convert_enum_idx(names, 2, value, "e2sm_rc_ctrl_hdr_format1_s::ric_ctrl_decision_e_");
}

// E2SM-RC-ControlHeader-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_hdr_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ue_id_present, 1));
  HANDLE_CODE(bref.pack(ric_ctrl_decision_present, 1));

  if (ue_id_present) {
    HANDLE_CODE(ue_id.pack(bref));
  }
  if (ric_ctrl_decision_present) {
    HANDLE_CODE(ric_ctrl_decision.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_hdr_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ue_id_present, 1));
  HANDLE_CODE(bref.unpack(ric_ctrl_decision_present, 1));

  if (ue_id_present) {
    HANDLE_CODE(ue_id.unpack(bref));
  }
  if (ric_ctrl_decision_present) {
    HANDLE_CODE(ric_ctrl_decision.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_hdr_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  if (ue_id_present) {
    j.write_fieldname("ueID");
    ue_id.to_json(j);
  }
  if (ric_ctrl_decision_present) {
    j.write_str("ric-ControlDecision", ric_ctrl_decision.to_string());
  }
  j.end_obj();
}

const char* e2sm_rc_ctrl_hdr_format2_s::ric_ctrl_decision_opts::to_string() const
{
  static const char* names[] = {"accept", "reject"};
  return convert_enum_idx(names, 2, value, "e2sm_rc_ctrl_hdr_format2_s::ric_ctrl_decision_e_");
}

// E2SM-RC-ControlHeader-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_hdr_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_integer(bref, ue_group_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_group_definition.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_style_type, false, true));
  HANDLE_CODE(pack_integer(bref, ric_ctrl_action_id, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_hdr_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_integer(ue_group_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(ue_group_definition.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_style_type, bref, false, true));
  HANDLE_CODE(unpack_integer(ric_ctrl_action_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_hdr_format3_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ue-Group-ID", ue_group_id);
  j.write_fieldname("ue-Group-Definition");
  ue_group_definition.to_json(j);
  j.write_int("ric-Style-Type", ric_style_type);
  j.write_int("ric-ControlAction-ID", ric_ctrl_action_id);
  j.end_obj();
}

// E2SM-RC-ControlMessage-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_style_list, 1, 63, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_style_list, bref, 1, 63, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format2_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format2");
  j.start_array("ric-ControlStyle-List");
  for (const auto& e1 : ric_ctrl_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-ControlMessage-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(list_of_entity_filts_present, 1));
  HANDLE_CODE(bref.pack(entity_agnostic_ctrl_ran_p_list_present, 1));

  if (list_of_entity_filts_present) {
    HANDLE_CODE(pack_dyn_seq_of(bref, list_of_entity_filts, 0, 255, true));
  }
  if (entity_agnostic_ctrl_ran_p_list_present) {
    HANDLE_CODE(pack_dyn_seq_of(bref, entity_agnostic_ctrl_ran_p_list, 0, 65535, true));
  }

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(list_of_entity_filts_present, 1));
  HANDLE_CODE(bref.unpack(entity_agnostic_ctrl_ran_p_list_present, 1));

  if (list_of_entity_filts_present) {
    HANDLE_CODE(unpack_dyn_seq_of(list_of_entity_filts, bref, 0, 255, true));
  }
  if (entity_agnostic_ctrl_ran_p_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(entity_agnostic_ctrl_ran_p_list, bref, 0, 65535, true));
  }

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_format3_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage-Format3");
  if (list_of_entity_filts_present) {
    j.start_array("listOfEntityFilters");
    for (const auto& e1 : list_of_entity_filts) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (entity_agnostic_ctrl_ran_p_list_present) {
    j.start_array("entityAgnosticControlRanP-List");
    for (const auto& e1 : entity_agnostic_ctrl_ran_p_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-ControlOutcome-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 0, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 0, 255, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ControlOutcome-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-ControlStyle-List");
  for (const auto& e1 : ric_ctrl_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-ControlOutcome-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 0, 255, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 0, 255, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_format3_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(global_associated_ue_info_present, 1));

  HANDLE_CODE(pack_dyn_seq_of(bref, msg_list, 1, 65535, true));
  if (global_associated_ue_info_present) {
    HANDLE_CODE(global_associated_ue_info.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(global_associated_ue_info_present, 1));

  HANDLE_CODE(unpack_dyn_seq_of(msg_list, bref, 1, 65535, true));
  if (global_associated_ue_info_present) {
    HANDLE_CODE(global_associated_ue_info.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("message-List");
  for (const auto& e1 : msg_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (global_associated_ue_info_present) {
    j.write_fieldname("globalAssociatedUEInfo");
    global_associated_ue_info.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(associated_e2_node_info.size() > 0, 1));
  HANDLE_CODE(bref.pack(associated_ue_info_present, 1));

  HANDLE_CODE(pack_integer(bref, ric_call_process_type_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(pack_integer(bref, ric_call_process_breakpoint_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (associated_e2_node_info.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, associated_e2_node_info, 1, 255, true));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool associated_e2_node_info_present;
  HANDLE_CODE(bref.unpack(associated_e2_node_info_present, 1));
  HANDLE_CODE(bref.unpack(associated_ue_info_present, 1));

  HANDLE_CODE(unpack_integer(ric_call_process_type_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  HANDLE_CODE(unpack_integer(ric_call_process_breakpoint_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  if (associated_e2_node_info_present) {
    HANDLE_CODE(unpack_dyn_seq_of(associated_e2_node_info, bref, 1, 255, true));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-callProcessType-ID", ric_call_process_type_id);
  j.write_int("ric-callProcessBreakpoint-ID", ric_call_process_breakpoint_id);
  if (associated_e2_node_info.size() > 0) {
    j.start_array("associatedE2NodeInfo");
    for (const auto& e1 : associated_e2_node_info) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (associated_ue_info_present) {
    j.write_fieldname("associatedUEInfo");
    associated_ue_info.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, e2_node_info_change_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(e2_node_info_change_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format3_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("e2NodeInfoChange-List");
  for (const auto& e1 : e2_node_info_change_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-EventTrigger-Format4 ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_format4_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_info_change_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_format4_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_info_change_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_format4_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("uEInfoChange-List");
  for (const auto& e1 : ue_info_change_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-IndicationHeader-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_hdr_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_event_trigger_condition_id_present, 1));

  if (ric_event_trigger_condition_id_present) {
    HANDLE_CODE(pack_integer(bref, ric_event_trigger_condition_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_hdr_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ric_event_trigger_condition_id_present, 1));

  if (ric_event_trigger_condition_id_present) {
    HANDLE_CODE(unpack_integer(ric_event_trigger_condition_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_hdr_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  if (ric_event_trigger_condition_id_present) {
    j.write_int("ric-eventTriggerCondition-ID", ric_event_trigger_condition_id);
  }
  j.end_obj();
}

// E2SM-RC-IndicationHeader-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_hdr_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ue_id.pack(bref));
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_insert_style_type, false, true));
  HANDLE_CODE(pack_integer(bref, ric_insert_ind_id, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_hdr_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ue_id.unpack(bref));
  HANDLE_CODE(unpack_unconstrained_integer(ric_insert_style_type, bref, false, true));
  HANDLE_CODE(unpack_integer(ric_insert_ind_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_hdr_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ueID");
  ue_id.to_json(j);
  j.write_int("ric-InsertStyle-Type", ric_insert_style_type);
  j.write_int("ric-InsertIndication-ID", ric_insert_ind_id);
  j.end_obj();
}

// E2SM-RC-IndicationHeader-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_hdr_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ric_event_trigger_condition_id_present, 1));
  HANDLE_CODE(bref.pack(ue_id_present, 1));

  if (ric_event_trigger_condition_id_present) {
    HANDLE_CODE(pack_integer(bref, ric_event_trigger_condition_id, (uint32_t)1u, (uint32_t)65535u, true, true));
  }
  if (ue_id_present) {
    HANDLE_CODE(ue_id.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_hdr_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ric_event_trigger_condition_id_present, 1));
  HANDLE_CODE(bref.unpack(ue_id_present, 1));

  if (ric_event_trigger_condition_id_present) {
    HANDLE_CODE(unpack_integer(ric_event_trigger_condition_id, bref, (uint32_t)1u, (uint32_t)65535u, true, true));
  }
  if (ue_id_present) {
    HANDLE_CODE(ue_id.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_hdr_format3_s::to_json(json_writer& j) const
{
  j.start_obj();
  if (ric_event_trigger_condition_id_present) {
    j.write_int("ric-eventTriggerCondition-ID", ric_event_trigger_condition_id);
  }
  if (ue_id_present) {
    j.write_fieldname("ueID");
    ue_id.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-IndicationMessage-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_reported_list, 1, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_reported_list, bref, 1, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format1_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format1");
  j.start_array("ranP-Reported-List");
  for (const auto& e1 : ran_p_reported_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_param_list, 1, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_param_list, bref, 1, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format2_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format2");
  j.start_array("ueParameter-List");
  for (const auto& e1 : ue_param_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format3 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format3_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, cell_info_list, 1, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format3_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(cell_info_list, bref, 1, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format3_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format3");
  j.start_array("cellInfo-List");
  for (const auto& e1 : cell_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format5 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format5_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_requested_list, 0, 65535, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format5_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_requested_list, bref, 0, 65535, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format5_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format5");
  j.start_array("ranP-Requested-List");
  for (const auto& e1 : ran_p_requested_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-IndicationMessage-Format6 ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_format6_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_style_list, 1, 63, true));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_format6_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_insert_style_list, bref, 1, 63, true));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_format6_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage-Format6");
  j.start_array("ric-InsertStyle-List");
  for (const auto& e1 : ric_insert_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
  j.end_obj();
  j.end_array();
}

// E2SM-RC-QueryDefinition-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_definition_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_p_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_definition_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_p_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_definition_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranP-List");
  for (const auto& e1 : ran_p_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-QueryHeader-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_hdr_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(associated_e2_node_info.size() > 0, 1));
  HANDLE_CODE(bref.pack(associated_ue_info_present, 1));

  HANDLE_CODE(pack_unconstrained_integer(bref, ric_style_type, false, true));
  if (associated_e2_node_info.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, associated_e2_node_info, 1, 255, true));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_hdr_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool associated_e2_node_info_present;
  HANDLE_CODE(bref.unpack(associated_e2_node_info_present, 1));
  HANDLE_CODE(bref.unpack(associated_ue_info_present, 1));

  HANDLE_CODE(unpack_unconstrained_integer(ric_style_type, bref, false, true));
  if (associated_e2_node_info_present) {
    HANDLE_CODE(unpack_dyn_seq_of(associated_e2_node_info, bref, 1, 255, true));
  }
  if (associated_ue_info_present) {
    HANDLE_CODE(associated_ue_info.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_hdr_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-Style-Type", ric_style_type);
  if (associated_e2_node_info.size() > 0) {
    j.start_array("associatedE2NodeInfo");
    for (const auto& e1 : associated_e2_node_info) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (associated_ue_info_present) {
    j.write_fieldname("associatedUEInfo");
    associated_ue_info.to_json(j);
  }
  j.end_obj();
}

// E2SM-RC-QueryOutcome-Format1 ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format1_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, cell_info_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format1_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(cell_info_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format1_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("cellInfo-List");
  for (const auto& e1 : cell_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// E2SM-RC-QueryOutcome-Format2 ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_format2_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ue_info_list, 0, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_format2_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ue_info_list, bref, 0, 65535, true));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_format2_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ueInfo-List");
  for (const auto& e1 : ue_info_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-Control ::= SEQUENCE
SRSASN_CODE ran_function_definition_ctrl_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_ctrl_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_ctrl_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_ctrl_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_ctrl_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-ControlStyle-List");
  for (const auto& e1 : ric_ctrl_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-EventTrigger ::= SEQUENCE
SRSASN_CODE ran_function_definition_event_trigger_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_l2_params_list.size() > 0, 1));
  HANDLE_CODE(bref.pack(ran_call_process_types_list.size() > 0, 1));
  HANDLE_CODE(bref.pack(ran_ue_identif_params_list.size() > 0, 1));
  HANDLE_CODE(bref.pack(ran_cell_identif_params_list.size() > 0, 1));

  HANDLE_CODE(pack_dyn_seq_of(bref, ric_event_trigger_style_list, 1, 63, true));
  if (ran_l2_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_l2_params_list, 1, 65535, true));
  }
  if (ran_call_process_types_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_call_process_types_list, 1, 65535, true));
  }
  if (ran_ue_identif_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_ue_identif_params_list, 1, 65535, true));
  }
  if (ran_cell_identif_params_list.size() > 0) {
    HANDLE_CODE(pack_dyn_seq_of(bref, ran_cell_identif_params_list, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_event_trigger_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  bool ran_l2_params_list_present;
  HANDLE_CODE(bref.unpack(ran_l2_params_list_present, 1));
  bool ran_call_process_types_list_present;
  HANDLE_CODE(bref.unpack(ran_call_process_types_list_present, 1));
  bool ran_ue_identif_params_list_present;
  HANDLE_CODE(bref.unpack(ran_ue_identif_params_list_present, 1));
  bool ran_cell_identif_params_list_present;
  HANDLE_CODE(bref.unpack(ran_cell_identif_params_list_present, 1));

  HANDLE_CODE(unpack_dyn_seq_of(ric_event_trigger_style_list, bref, 1, 63, true));
  if (ran_l2_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_l2_params_list, bref, 1, 65535, true));
  }
  if (ran_call_process_types_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_call_process_types_list, bref, 1, 65535, true));
  }
  if (ran_ue_identif_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_ue_identif_params_list, bref, 1, 65535, true));
  }
  if (ran_cell_identif_params_list_present) {
    HANDLE_CODE(unpack_dyn_seq_of(ran_cell_identif_params_list, bref, 1, 65535, true));
  }

  return SRSASN_SUCCESS;
}
void ran_function_definition_event_trigger_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-EventTriggerStyle-List");
  for (const auto& e1 : ric_event_trigger_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  if (ran_l2_params_list.size() > 0) {
    j.start_array("ran-L2Parameters-List");
    for (const auto& e1 : ran_l2_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ran_call_process_types_list.size() > 0) {
    j.start_array("ran-CallProcessTypes-List");
    for (const auto& e1 : ran_call_process_types_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ran_ue_identif_params_list.size() > 0) {
    j.start_array("ran-UEIdentificationParameters-List");
    for (const auto& e1 : ran_ue_identif_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  if (ran_cell_identif_params_list.size() > 0) {
    j.start_array("ran-CellIdentificationParameters-List");
    for (const auto& e1 : ran_cell_identif_params_list) {
      e1.to_json(j);
    }
    j.end_array();
  }
  j.end_obj();
}

// RANFunctionDefinition-Insert ::= SEQUENCE
SRSASN_CODE ran_function_definition_insert_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_insert_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_insert_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_insert_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_insert_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-InsertStyle-List");
  for (const auto& e1 : ric_insert_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-Policy ::= SEQUENCE
SRSASN_CODE ran_function_definition_policy_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_policy_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_policy_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_policy_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_policy_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-PolicyStyle-List");
  for (const auto& e1 : ric_policy_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-Query ::= SEQUENCE
SRSASN_CODE ran_function_definition_query_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_query_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_query_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_query_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_query_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-QueryStyle-List");
  for (const auto& e1 : ric_query_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANFunctionDefinition-Report ::= SEQUENCE
SRSASN_CODE ran_function_definition_report_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ric_report_style_list, 1, 63, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_function_definition_report_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ric_report_style_list, bref, 1, 63, true));

  return SRSASN_SUCCESS;
}
void ran_function_definition_report_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ric-ReportStyle-List");
  for (const auto& e1 : ric_report_style_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-Definition-Choice-LIST-Item ::= SEQUENCE
SRSASN_CODE ran_param_definition_choice_list_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_definition_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_choice_list_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_definition_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void ran_param_definition_choice_list_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ran_param_definition_present) {
    j.write_fieldname("ranParameter-Definition");
    ran_param_definition.to_json(j);
  }
  j.end_obj();
}

// RANParameter-Definition-Choice-STRUCTURE-Item ::= SEQUENCE
SRSASN_CODE ran_param_definition_choice_structure_item_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_definition_present, 1));

  HANDLE_CODE(pack_integer(bref, ran_param_id, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.pack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_choice_structure_item_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_definition_present, 1));

  HANDLE_CODE(unpack_integer(ran_param_id, bref, (uint64_t)1u, (uint64_t)4294967295u, true, true));
  HANDLE_CODE(ran_param_name.unpack(bref));
  if (ran_param_definition_present) {
    HANDLE_CODE(ran_param_definition.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void ran_param_definition_choice_structure_item_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ranParameter-ID", ran_param_id);
  j.write_str("ranParameter-name", ran_param_name.to_string());
  if (ran_param_definition_present) {
    j.write_fieldname("ranParameter-Definition");
    ran_param_definition.to_json(j);
  }
  j.end_obj();
}

// RANParameter-LIST ::= SEQUENCE
SRSASN_CODE ran_param_list_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, list_of_ran_param, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_list_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(list_of_ran_param, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_param_list_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("list-of-ranParameter");
  for (const auto& e1 : list_of_ran_param) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-TestingCondition ::= CHOICE
void ran_param_testing_condition_c::destroy_() {}
void ran_param_testing_condition_c::set(types::options e)
{
  destroy_();
  type_ = e;
}
ran_param_testing_condition_c::ran_param_testing_condition_c(const ran_param_testing_condition_c& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ran_p_choice_comparison:
      c.init(other.c.get<ran_p_choice_comparison_e_>());
      break;
    case types::ran_p_choice_presence:
      c.init(other.c.get<ran_p_choice_presence_e_>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_condition_c");
  }
}
ran_param_testing_condition_c& ran_param_testing_condition_c::operator=(const ran_param_testing_condition_c& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ran_p_choice_comparison:
      c.set(other.c.get<ran_p_choice_comparison_e_>());
      break;
    case types::ran_p_choice_presence:
      c.set(other.c.get<ran_p_choice_presence_e_>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_condition_c");
  }

  return *this;
}
ran_param_testing_condition_c::ran_p_choice_comparison_e_& ran_param_testing_condition_c::set_ran_p_choice_comparison()
{
  set(types::ran_p_choice_comparison);
  return c.get<ran_p_choice_comparison_e_>();
}
ran_param_testing_condition_c::ran_p_choice_presence_e_& ran_param_testing_condition_c::set_ran_p_choice_presence()
{
  set(types::ran_p_choice_presence);
  return c.get<ran_p_choice_presence_e_>();
}
void ran_param_testing_condition_c::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ran_p_choice_comparison:
      j.write_str("ranP-Choice-comparison", c.get<ran_p_choice_comparison_e_>().to_string());
      break;
    case types::ran_p_choice_presence:
      j.write_str("ranP-Choice-presence", c.get<ran_p_choice_presence_e_>().to_string());
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_condition_c");
  }
  j.end_obj();
}
SRSASN_CODE ran_param_testing_condition_c::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ran_p_choice_comparison:
      HANDLE_CODE(c.get<ran_p_choice_comparison_e_>().pack(bref));
      break;
    case types::ran_p_choice_presence:
      HANDLE_CODE(c.get<ran_p_choice_presence_e_>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_condition_c");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_condition_c::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ran_p_choice_comparison:
      HANDLE_CODE(c.get<ran_p_choice_comparison_e_>().unpack(bref));
      break;
    case types::ran_p_choice_presence:
      HANDLE_CODE(c.get<ran_p_choice_presence_e_>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "ran_param_testing_condition_c");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* ran_param_testing_condition_c::ran_p_choice_comparison_opts::to_string() const
{
  static const char* names[] = {"equal", "difference", "greaterthan", "lessthan", "contains", "starts-with"};
  return convert_enum_idx(names, 6, value, "ran_param_testing_condition_c::ran_p_choice_comparison_e_");
}

const char* ran_param_testing_condition_c::ran_p_choice_presence_opts::to_string() const
{
  static const char* names[] = {"present", "configured", "rollover", "non-zero", "value-change"};
  return convert_enum_idx(names, 5, value, "ran_param_testing_condition_c::ran_p_choice_presence_e_");
}
uint8_t ran_param_testing_condition_c::ran_p_choice_presence_opts::to_number() const
{
  if (value == non_zero) {
    return 0;
  }
  invalid_enum_number(value, "ran_param_testing_condition_c::ran_p_choice_presence_e_");
  return 0;
}

const char* ran_param_testing_condition_c::types_opts::to_string() const
{
  static const char* names[] = {"ranP-Choice-comparison", "ranP-Choice-presence"};
  return convert_enum_idx(names, 2, value, "ran_param_testing_condition_c::types");
}

// E2SM-RC-ActionDefinition ::= SEQUENCE
SRSASN_CODE e2sm_rc_action_definition_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_unconstrained_integer(bref, ric_style_type, false, true));
  HANDLE_CODE(ric_action_definition_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_unconstrained_integer(ric_style_type, bref, false, true));
  HANDLE_CODE(ric_action_definition_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_action_definition_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_int("ric-Style-Type", ric_style_type);
  j.write_fieldname("ric-actionDefinition-formats");
  ric_action_definition_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_action_definition_s::ric_action_definition_formats_c_::destroy_()
{
  switch (type_) {
    case types::action_definition_format1:
      c.destroy<e2sm_rc_action_definition_format1_s>();
      break;
    case types::action_definition_format2:
      c.destroy<e2sm_rc_action_definition_format2_s>();
      break;
    case types::action_definition_format3:
      c.destroy<e2sm_rc_action_definition_format3_s>();
      break;
    case types::action_definition_format4:
      c.destroy<e2sm_rc_action_definition_format4_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_action_definition_s::ric_action_definition_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::action_definition_format1:
      c.init<e2sm_rc_action_definition_format1_s>();
      break;
    case types::action_definition_format2:
      c.init<e2sm_rc_action_definition_format2_s>();
      break;
    case types::action_definition_format3:
      c.init<e2sm_rc_action_definition_format3_s>();
      break;
    case types::action_definition_format4:
      c.init<e2sm_rc_action_definition_format4_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
  }
}
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::ric_action_definition_formats_c_(
    const e2sm_rc_action_definition_s::ric_action_definition_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::action_definition_format1:
      c.init(other.c.get<e2sm_rc_action_definition_format1_s>());
      break;
    case types::action_definition_format2:
      c.init(other.c.get<e2sm_rc_action_definition_format2_s>());
      break;
    case types::action_definition_format3:
      c.init(other.c.get<e2sm_rc_action_definition_format3_s>());
      break;
    case types::action_definition_format4:
      c.init(other.c.get<e2sm_rc_action_definition_format4_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
  }
}
e2sm_rc_action_definition_s::ric_action_definition_formats_c_&
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::operator=(
    const e2sm_rc_action_definition_s::ric_action_definition_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::action_definition_format1:
      c.set(other.c.get<e2sm_rc_action_definition_format1_s>());
      break;
    case types::action_definition_format2:
      c.set(other.c.get<e2sm_rc_action_definition_format2_s>());
      break;
    case types::action_definition_format3:
      c.set(other.c.get<e2sm_rc_action_definition_format3_s>());
      break;
    case types::action_definition_format4:
      c.set(other.c.get<e2sm_rc_action_definition_format4_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
  }

  return *this;
}
e2sm_rc_action_definition_format1_s&
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::set_action_definition_format1()
{
  set(types::action_definition_format1);
  return c.get<e2sm_rc_action_definition_format1_s>();
}
e2sm_rc_action_definition_format2_s&
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::set_action_definition_format2()
{
  set(types::action_definition_format2);
  return c.get<e2sm_rc_action_definition_format2_s>();
}
e2sm_rc_action_definition_format3_s&
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::set_action_definition_format3()
{
  set(types::action_definition_format3);
  return c.get<e2sm_rc_action_definition_format3_s>();
}
e2sm_rc_action_definition_format4_s&
e2sm_rc_action_definition_s::ric_action_definition_formats_c_::set_action_definition_format4()
{
  set(types::action_definition_format4);
  return c.get<e2sm_rc_action_definition_format4_s>();
}
void e2sm_rc_action_definition_s::ric_action_definition_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::action_definition_format1:
      j.write_fieldname("actionDefinition-Format1");
      c.get<e2sm_rc_action_definition_format1_s>().to_json(j);
      break;
    case types::action_definition_format2:
      j.write_fieldname("actionDefinition-Format2");
      c.get<e2sm_rc_action_definition_format2_s>().to_json(j);
      break;
    case types::action_definition_format3:
      j.write_fieldname("actionDefinition-Format3");
      c.get<e2sm_rc_action_definition_format3_s>().to_json(j);
      break;
    case types::action_definition_format4:
      j.write_fieldname("actionDefinition-Format4");
      c.get<e2sm_rc_action_definition_format4_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_action_definition_s::ric_action_definition_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::action_definition_format1:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format1_s>().pack(bref));
      break;
    case types::action_definition_format2:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format2_s>().pack(bref));
      break;
    case types::action_definition_format3:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format3_s>().pack(bref));
      break;
    case types::action_definition_format4: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format4_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_action_definition_s::ric_action_definition_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::action_definition_format1:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format1_s>().unpack(bref));
      break;
    case types::action_definition_format2:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format2_s>().unpack(bref));
      break;
    case types::action_definition_format3:
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format3_s>().unpack(bref));
      break;
    case types::action_definition_format4: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_action_definition_format4_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_action_definition_s::ric_action_definition_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {
      "actionDefinition-Format1", "actionDefinition-Format2", "actionDefinition-Format3", "actionDefinition-Format4"};
  return convert_enum_idx(names, 4, value, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_::types");
}
uint8_t e2sm_rc_action_definition_s::ric_action_definition_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3, 4};
  return map_enum_number(numbers, 4, value, "e2sm_rc_action_definition_s::ric_action_definition_formats_c_::types");
}

// E2SM-RC-CallProcessID ::= SEQUENCE
SRSASN_CODE e2sm_rc_call_process_id_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_call_process_id_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_call_process_id_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_call_process_id_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_call_process_id_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-callProcessID-formats");
  ric_call_process_id_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("callProcessID-Format1");
  c.to_json(j);
  j.end_obj();
}
SRSASN_CODE e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::pack(bit_ref& bref) const
{
  pack_enum(bref, type());
  HANDLE_CODE(c.pack(bref));
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  unpack_enum(e, bref);
  if (e != type()) {
    log_invalid_choice_id(e, "e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_");
    return SRSASN_ERROR_DECODE_FAIL;
  }
  HANDLE_CODE(c.unpack(bref));
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"callProcessID-Format1"};
  return convert_enum_idx(names, 1, value, "e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::types");
}
uint8_t e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1};
  return map_enum_number(numbers, 1, value, "e2sm_rc_call_process_id_s::ric_call_process_id_formats_c_::types");
}

// E2SM-RC-ControlHeader ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_hdr_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_ctrl_hdr_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_hdr_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_ctrl_hdr_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_hdr_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-controlHeader-formats");
  ric_ctrl_hdr_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::destroy_()
{
  switch (type_) {
    case types::ctrl_hdr_format1:
      c.destroy<e2sm_rc_ctrl_hdr_format1_s>();
      break;
    case types::ctrl_hdr_format2:
      c.destroy<e2sm_rc_ctrl_hdr_format2_s>();
      break;
    case types::ctrl_hdr_format3:
      c.destroy<e2sm_rc_ctrl_hdr_format3_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ctrl_hdr_format1:
      c.init<e2sm_rc_ctrl_hdr_format1_s>();
      break;
    case types::ctrl_hdr_format2:
      c.init<e2sm_rc_ctrl_hdr_format2_s>();
      break;
    case types::ctrl_hdr_format3:
      c.init<e2sm_rc_ctrl_hdr_format3_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
  }
}
e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::ric_ctrl_hdr_formats_c_(
    const e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ctrl_hdr_format1:
      c.init(other.c.get<e2sm_rc_ctrl_hdr_format1_s>());
      break;
    case types::ctrl_hdr_format2:
      c.init(other.c.get<e2sm_rc_ctrl_hdr_format2_s>());
      break;
    case types::ctrl_hdr_format3:
      c.init(other.c.get<e2sm_rc_ctrl_hdr_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
  }
}
e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_&
e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::operator=(const e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ctrl_hdr_format1:
      c.set(other.c.get<e2sm_rc_ctrl_hdr_format1_s>());
      break;
    case types::ctrl_hdr_format2:
      c.set(other.c.get<e2sm_rc_ctrl_hdr_format2_s>());
      break;
    case types::ctrl_hdr_format3:
      c.set(other.c.get<e2sm_rc_ctrl_hdr_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
  }

  return *this;
}
e2sm_rc_ctrl_hdr_format1_s& e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::set_ctrl_hdr_format1()
{
  set(types::ctrl_hdr_format1);
  return c.get<e2sm_rc_ctrl_hdr_format1_s>();
}
e2sm_rc_ctrl_hdr_format2_s& e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::set_ctrl_hdr_format2()
{
  set(types::ctrl_hdr_format2);
  return c.get<e2sm_rc_ctrl_hdr_format2_s>();
}
e2sm_rc_ctrl_hdr_format3_s& e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::set_ctrl_hdr_format3()
{
  set(types::ctrl_hdr_format3);
  return c.get<e2sm_rc_ctrl_hdr_format3_s>();
}
void e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ctrl_hdr_format1:
      j.write_fieldname("controlHeader-Format1");
      c.get<e2sm_rc_ctrl_hdr_format1_s>().to_json(j);
      break;
    case types::ctrl_hdr_format2:
      j.write_fieldname("controlHeader-Format2");
      c.get<e2sm_rc_ctrl_hdr_format2_s>().to_json(j);
      break;
    case types::ctrl_hdr_format3:
      j.write_fieldname("controlHeader-Format3");
      c.get<e2sm_rc_ctrl_hdr_format3_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ctrl_hdr_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format1_s>().pack(bref));
      break;
    case types::ctrl_hdr_format2: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format2_s>().pack(bref));
    } break;
    case types::ctrl_hdr_format3: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format3_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ctrl_hdr_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format1_s>().unpack(bref));
      break;
    case types::ctrl_hdr_format2: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format2_s>().unpack(bref));
    } break;
    case types::ctrl_hdr_format3: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_hdr_format3_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"controlHeader-Format1", "controlHeader-Format2", "controlHeader-Format3"};
  return convert_enum_idx(names, 3, value, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::types");
}
uint8_t e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3};
  return map_enum_number(numbers, 3, value, "e2sm_rc_ctrl_hdr_s::ric_ctrl_hdr_formats_c_::types");
}

// E2SM-RC-ControlMessage ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_msg_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_ctrl_msg_formats.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_ctrl_msg_formats.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_msg_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-ControlMessage");
  j.write_fieldname("ric-controlMessage-formats");
  ric_ctrl_msg_formats.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

void e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::destroy_()
{
  switch (type_) {
    case types::ctrl_msg_format1:
      c.destroy<e2sm_rc_ctrl_msg_format1_s>();
      break;
    case types::ctrl_msg_format2:
      c.destroy<e2sm_rc_ctrl_msg_format2_s>();
      break;
    case types::ctrl_msg_format3:
      c.destroy<e2sm_rc_ctrl_msg_format3_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ctrl_msg_format1:
      c.init<e2sm_rc_ctrl_msg_format1_s>();
      break;
    case types::ctrl_msg_format2:
      c.init<e2sm_rc_ctrl_msg_format2_s>();
      break;
    case types::ctrl_msg_format3:
      c.init<e2sm_rc_ctrl_msg_format3_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
  }
}
e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::ric_ctrl_msg_formats_c_(
    const e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ctrl_msg_format1:
      c.init(other.c.get<e2sm_rc_ctrl_msg_format1_s>());
      break;
    case types::ctrl_msg_format2:
      c.init(other.c.get<e2sm_rc_ctrl_msg_format2_s>());
      break;
    case types::ctrl_msg_format3:
      c.init(other.c.get<e2sm_rc_ctrl_msg_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
  }
}
e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_&
e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::operator=(const e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ctrl_msg_format1:
      c.set(other.c.get<e2sm_rc_ctrl_msg_format1_s>());
      break;
    case types::ctrl_msg_format2:
      c.set(other.c.get<e2sm_rc_ctrl_msg_format2_s>());
      break;
    case types::ctrl_msg_format3:
      c.set(other.c.get<e2sm_rc_ctrl_msg_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
  }

  return *this;
}
e2sm_rc_ctrl_msg_format1_s& e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::set_ctrl_msg_format1()
{
  set(types::ctrl_msg_format1);
  return c.get<e2sm_rc_ctrl_msg_format1_s>();
}
e2sm_rc_ctrl_msg_format2_s& e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::set_ctrl_msg_format2()
{
  set(types::ctrl_msg_format2);
  return c.get<e2sm_rc_ctrl_msg_format2_s>();
}
e2sm_rc_ctrl_msg_format3_s& e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::set_ctrl_msg_format3()
{
  set(types::ctrl_msg_format3);
  return c.get<e2sm_rc_ctrl_msg_format3_s>();
}
void e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ctrl_msg_format1:
      j.write_fieldname("controlMessage-Format1");
      c.get<e2sm_rc_ctrl_msg_format1_s>().to_json(j);
      break;
    case types::ctrl_msg_format2:
      j.write_fieldname("controlMessage-Format2");
      c.get<e2sm_rc_ctrl_msg_format2_s>().to_json(j);
      break;
    case types::ctrl_msg_format3:
      j.write_fieldname("controlMessage-Format3");
      c.get<e2sm_rc_ctrl_msg_format3_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ctrl_msg_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format1_s>().pack(bref));
      break;
    case types::ctrl_msg_format2: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format2_s>().pack(bref));
    } break;
    case types::ctrl_msg_format3: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format3_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ctrl_msg_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format1_s>().unpack(bref));
      break;
    case types::ctrl_msg_format2: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format2_s>().unpack(bref));
    } break;
    case types::ctrl_msg_format3: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_msg_format3_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"controlMessage-Format1", "controlMessage-Format2", "controlMessage-Format3"};
  return convert_enum_idx(names, 3, value, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::types");
}
uint8_t e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3};
  return map_enum_number(numbers, 3, value, "e2sm_rc_ctrl_msg_s::ric_ctrl_msg_formats_c_::types");
}

// E2SM-RC-ControlOutcome ::= SEQUENCE
SRSASN_CODE e2sm_rc_ctrl_outcome_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_ctrl_outcome_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_ctrl_outcome_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ctrl_outcome_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-controlOutcome-formats");
  ric_ctrl_outcome_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::destroy_()
{
  switch (type_) {
    case types::ctrl_outcome_format1:
      c.destroy<e2sm_rc_ctrl_outcome_format1_s>();
      break;
    case types::ctrl_outcome_format2:
      c.destroy<e2sm_rc_ctrl_outcome_format2_s>();
      break;
    case types::ctrl_outcome_format3:
      c.destroy<e2sm_rc_ctrl_outcome_format3_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ctrl_outcome_format1:
      c.init<e2sm_rc_ctrl_outcome_format1_s>();
      break;
    case types::ctrl_outcome_format2:
      c.init<e2sm_rc_ctrl_outcome_format2_s>();
      break;
    case types::ctrl_outcome_format3:
      c.init<e2sm_rc_ctrl_outcome_format3_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
  }
}
e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::ric_ctrl_outcome_formats_c_(
    const e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ctrl_outcome_format1:
      c.init(other.c.get<e2sm_rc_ctrl_outcome_format1_s>());
      break;
    case types::ctrl_outcome_format2:
      c.init(other.c.get<e2sm_rc_ctrl_outcome_format2_s>());
      break;
    case types::ctrl_outcome_format3:
      c.init(other.c.get<e2sm_rc_ctrl_outcome_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
  }
}
e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_& e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::operator=(
    const e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ctrl_outcome_format1:
      c.set(other.c.get<e2sm_rc_ctrl_outcome_format1_s>());
      break;
    case types::ctrl_outcome_format2:
      c.set(other.c.get<e2sm_rc_ctrl_outcome_format2_s>());
      break;
    case types::ctrl_outcome_format3:
      c.set(other.c.get<e2sm_rc_ctrl_outcome_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
  }

  return *this;
}
e2sm_rc_ctrl_outcome_format1_s& e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::set_ctrl_outcome_format1()
{
  set(types::ctrl_outcome_format1);
  return c.get<e2sm_rc_ctrl_outcome_format1_s>();
}
e2sm_rc_ctrl_outcome_format2_s& e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::set_ctrl_outcome_format2()
{
  set(types::ctrl_outcome_format2);
  return c.get<e2sm_rc_ctrl_outcome_format2_s>();
}
e2sm_rc_ctrl_outcome_format3_s& e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::set_ctrl_outcome_format3()
{
  set(types::ctrl_outcome_format3);
  return c.get<e2sm_rc_ctrl_outcome_format3_s>();
}
void e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ctrl_outcome_format1:
      j.write_fieldname("controlOutcome-Format1");
      c.get<e2sm_rc_ctrl_outcome_format1_s>().to_json(j);
      break;
    case types::ctrl_outcome_format2:
      j.write_fieldname("controlOutcome-Format2");
      c.get<e2sm_rc_ctrl_outcome_format2_s>().to_json(j);
      break;
    case types::ctrl_outcome_format3:
      j.write_fieldname("controlOutcome-Format3");
      c.get<e2sm_rc_ctrl_outcome_format3_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ctrl_outcome_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format1_s>().pack(bref));
      break;
    case types::ctrl_outcome_format2: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format2_s>().pack(bref));
    } break;
    case types::ctrl_outcome_format3: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format3_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ctrl_outcome_format1:
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format1_s>().unpack(bref));
      break;
    case types::ctrl_outcome_format2: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format2_s>().unpack(bref));
    } break;
    case types::ctrl_outcome_format3: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ctrl_outcome_format3_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"controlOutcome-Format1", "controlOutcome-Format2", "controlOutcome-Format3"};
  return convert_enum_idx(names, 3, value, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::types");
}
uint8_t e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3};
  return map_enum_number(numbers, 3, value, "e2sm_rc_ctrl_outcome_s::ric_ctrl_outcome_formats_c_::types");
}

// E2SM-RC-EventTrigger ::= SEQUENCE
SRSASN_CODE e2sm_rc_event_trigger_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_event_trigger_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_event_trigger_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_event_trigger_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-eventTrigger-formats");
  ric_event_trigger_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::destroy_()
{
  switch (type_) {
    case types::event_trigger_format1:
      c.destroy<e2sm_rc_event_trigger_format1_s>();
      break;
    case types::event_trigger_format2:
      c.destroy<e2sm_rc_event_trigger_format2_s>();
      break;
    case types::event_trigger_format3:
      c.destroy<e2sm_rc_event_trigger_format3_s>();
      break;
    case types::event_trigger_format4:
      c.destroy<e2sm_rc_event_trigger_format4_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::event_trigger_format1:
      c.init<e2sm_rc_event_trigger_format1_s>();
      break;
    case types::event_trigger_format2:
      c.init<e2sm_rc_event_trigger_format2_s>();
      break;
    case types::event_trigger_format3:
      c.init<e2sm_rc_event_trigger_format3_s>();
      break;
    case types::event_trigger_format4:
      c.init<e2sm_rc_event_trigger_format4_s>();
      break;
    case types::event_trigger_format5:
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
  }
}
e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::ric_event_trigger_formats_c_(
    const e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::event_trigger_format1:
      c.init(other.c.get<e2sm_rc_event_trigger_format1_s>());
      break;
    case types::event_trigger_format2:
      c.init(other.c.get<e2sm_rc_event_trigger_format2_s>());
      break;
    case types::event_trigger_format3:
      c.init(other.c.get<e2sm_rc_event_trigger_format3_s>());
      break;
    case types::event_trigger_format4:
      c.init(other.c.get<e2sm_rc_event_trigger_format4_s>());
      break;
    case types::event_trigger_format5:
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
  }
}
e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_& e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::operator=(
    const e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::event_trigger_format1:
      c.set(other.c.get<e2sm_rc_event_trigger_format1_s>());
      break;
    case types::event_trigger_format2:
      c.set(other.c.get<e2sm_rc_event_trigger_format2_s>());
      break;
    case types::event_trigger_format3:
      c.set(other.c.get<e2sm_rc_event_trigger_format3_s>());
      break;
    case types::event_trigger_format4:
      c.set(other.c.get<e2sm_rc_event_trigger_format4_s>());
      break;
    case types::event_trigger_format5:
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
  }

  return *this;
}
e2sm_rc_event_trigger_format1_s& e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set_event_trigger_format1()
{
  set(types::event_trigger_format1);
  return c.get<e2sm_rc_event_trigger_format1_s>();
}
e2sm_rc_event_trigger_format2_s& e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set_event_trigger_format2()
{
  set(types::event_trigger_format2);
  return c.get<e2sm_rc_event_trigger_format2_s>();
}
e2sm_rc_event_trigger_format3_s& e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set_event_trigger_format3()
{
  set(types::event_trigger_format3);
  return c.get<e2sm_rc_event_trigger_format3_s>();
}
e2sm_rc_event_trigger_format4_s& e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set_event_trigger_format4()
{
  set(types::event_trigger_format4);
  return c.get<e2sm_rc_event_trigger_format4_s>();
}
void e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::set_event_trigger_format5()
{
  set(types::event_trigger_format5);
}
void e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::event_trigger_format1:
      j.write_fieldname("eventTrigger-Format1");
      c.get<e2sm_rc_event_trigger_format1_s>().to_json(j);
      break;
    case types::event_trigger_format2:
      j.write_fieldname("eventTrigger-Format2");
      c.get<e2sm_rc_event_trigger_format2_s>().to_json(j);
      break;
    case types::event_trigger_format3:
      j.write_fieldname("eventTrigger-Format3");
      c.get<e2sm_rc_event_trigger_format3_s>().to_json(j);
      break;
    case types::event_trigger_format4:
      j.write_fieldname("eventTrigger-Format4");
      c.get<e2sm_rc_event_trigger_format4_s>().to_json(j);
      break;
    case types::event_trigger_format5:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::event_trigger_format1:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format1_s>().pack(bref));
      break;
    case types::event_trigger_format2:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format2_s>().pack(bref));
      break;
    case types::event_trigger_format3:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format3_s>().pack(bref));
      break;
    case types::event_trigger_format4:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format4_s>().pack(bref));
      break;
    case types::event_trigger_format5:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::event_trigger_format1:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format1_s>().unpack(bref));
      break;
    case types::event_trigger_format2:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format2_s>().unpack(bref));
      break;
    case types::event_trigger_format3:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format3_s>().unpack(bref));
      break;
    case types::event_trigger_format4:
      HANDLE_CODE(c.get<e2sm_rc_event_trigger_format4_s>().unpack(bref));
      break;
    case types::event_trigger_format5:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"eventTrigger-Format1",
                                "eventTrigger-Format2",
                                "eventTrigger-Format3",
                                "eventTrigger-Format4",
                                "eventTrigger-Format5"};
  return convert_enum_idx(names, 5, value, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::types");
}
uint8_t e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3, 4, 5};
  return map_enum_number(numbers, 5, value, "e2sm_rc_event_trigger_s::ric_event_trigger_formats_c_::types");
}

// E2SM-RC-IndicationHeader ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_hdr_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_ind_hdr_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_hdr_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_ind_hdr_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_hdr_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-indicationHeader-formats");
  ric_ind_hdr_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::destroy_()
{
  switch (type_) {
    case types::ind_hdr_format1:
      c.destroy<e2sm_rc_ind_hdr_format1_s>();
      break;
    case types::ind_hdr_format2:
      c.destroy<e2sm_rc_ind_hdr_format2_s>();
      break;
    case types::ind_hdr_format3:
      c.destroy<e2sm_rc_ind_hdr_format3_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ind_hdr_format1:
      c.init<e2sm_rc_ind_hdr_format1_s>();
      break;
    case types::ind_hdr_format2:
      c.init<e2sm_rc_ind_hdr_format2_s>();
      break;
    case types::ind_hdr_format3:
      c.init<e2sm_rc_ind_hdr_format3_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
  }
}
e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::ric_ind_hdr_formats_c_(
    const e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ind_hdr_format1:
      c.init(other.c.get<e2sm_rc_ind_hdr_format1_s>());
      break;
    case types::ind_hdr_format2:
      c.init(other.c.get<e2sm_rc_ind_hdr_format2_s>());
      break;
    case types::ind_hdr_format3:
      c.init(other.c.get<e2sm_rc_ind_hdr_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
  }
}
e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_&
e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::operator=(const e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ind_hdr_format1:
      c.set(other.c.get<e2sm_rc_ind_hdr_format1_s>());
      break;
    case types::ind_hdr_format2:
      c.set(other.c.get<e2sm_rc_ind_hdr_format2_s>());
      break;
    case types::ind_hdr_format3:
      c.set(other.c.get<e2sm_rc_ind_hdr_format3_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
  }

  return *this;
}
e2sm_rc_ind_hdr_format1_s& e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::set_ind_hdr_format1()
{
  set(types::ind_hdr_format1);
  return c.get<e2sm_rc_ind_hdr_format1_s>();
}
e2sm_rc_ind_hdr_format2_s& e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::set_ind_hdr_format2()
{
  set(types::ind_hdr_format2);
  return c.get<e2sm_rc_ind_hdr_format2_s>();
}
e2sm_rc_ind_hdr_format3_s& e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::set_ind_hdr_format3()
{
  set(types::ind_hdr_format3);
  return c.get<e2sm_rc_ind_hdr_format3_s>();
}
void e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ind_hdr_format1:
      j.write_fieldname("indicationHeader-Format1");
      c.get<e2sm_rc_ind_hdr_format1_s>().to_json(j);
      break;
    case types::ind_hdr_format2:
      j.write_fieldname("indicationHeader-Format2");
      c.get<e2sm_rc_ind_hdr_format2_s>().to_json(j);
      break;
    case types::ind_hdr_format3:
      j.write_fieldname("indicationHeader-Format3");
      c.get<e2sm_rc_ind_hdr_format3_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ind_hdr_format1:
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format1_s>().pack(bref));
      break;
    case types::ind_hdr_format2:
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format2_s>().pack(bref));
      break;
    case types::ind_hdr_format3: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format3_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ind_hdr_format1:
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format1_s>().unpack(bref));
      break;
    case types::ind_hdr_format2:
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format2_s>().unpack(bref));
      break;
    case types::ind_hdr_format3: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ind_hdr_format3_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"indicationHeader-Format1", "indicationHeader-Format2", "indicationHeader-Format3"};
  return convert_enum_idx(names, 3, value, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::types");
}
uint8_t e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3};
  return map_enum_number(numbers, 3, value, "e2sm_rc_ind_hdr_s::ric_ind_hdr_formats_c_::types");
}

// E2SM-RC-IndicationMessage ::= SEQUENCE
SRSASN_CODE e2sm_rc_ind_msg_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_ind_msg_formats.pack(bref));

  bref.align_bytes_zero();

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_ind_msg_formats.unpack(bref));

  bref.align_bytes();

  return SRSASN_SUCCESS;
}
void e2sm_rc_ind_msg_s::to_json(json_writer& j) const
{
  j.start_array();
  j.start_obj();
  j.start_obj("E2SM-RC-IndicationMessage");
  j.write_fieldname("ric-indicationMessage-formats");
  ric_ind_msg_formats.to_json(j);
  j.end_obj();
  j.end_obj();
  j.end_array();
}

void e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::destroy_()
{
  switch (type_) {
    case types::ind_msg_format1:
      c.destroy<e2sm_rc_ind_msg_format1_s>();
      break;
    case types::ind_msg_format2:
      c.destroy<e2sm_rc_ind_msg_format2_s>();
      break;
    case types::ind_msg_format3:
      c.destroy<e2sm_rc_ind_msg_format3_s>();
      break;
    case types::ind_msg_format5:
      c.destroy<e2sm_rc_ind_msg_format5_s>();
      break;
    case types::ind_msg_format6:
      c.destroy<e2sm_rc_ind_msg_format6_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::ind_msg_format1:
      c.init<e2sm_rc_ind_msg_format1_s>();
      break;
    case types::ind_msg_format2:
      c.init<e2sm_rc_ind_msg_format2_s>();
      break;
    case types::ind_msg_format3:
      c.init<e2sm_rc_ind_msg_format3_s>();
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      c.init<e2sm_rc_ind_msg_format5_s>();
      break;
    case types::ind_msg_format6:
      c.init<e2sm_rc_ind_msg_format6_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
  }
}
e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::ric_ind_msg_formats_c_(
    const e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::ind_msg_format1:
      c.init(other.c.get<e2sm_rc_ind_msg_format1_s>());
      break;
    case types::ind_msg_format2:
      c.init(other.c.get<e2sm_rc_ind_msg_format2_s>());
      break;
    case types::ind_msg_format3:
      c.init(other.c.get<e2sm_rc_ind_msg_format3_s>());
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      c.init(other.c.get<e2sm_rc_ind_msg_format5_s>());
      break;
    case types::ind_msg_format6:
      c.init(other.c.get<e2sm_rc_ind_msg_format6_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
  }
}
e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_&
e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::operator=(const e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::ind_msg_format1:
      c.set(other.c.get<e2sm_rc_ind_msg_format1_s>());
      break;
    case types::ind_msg_format2:
      c.set(other.c.get<e2sm_rc_ind_msg_format2_s>());
      break;
    case types::ind_msg_format3:
      c.set(other.c.get<e2sm_rc_ind_msg_format3_s>());
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      c.set(other.c.get<e2sm_rc_ind_msg_format5_s>());
      break;
    case types::ind_msg_format6:
      c.set(other.c.get<e2sm_rc_ind_msg_format6_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
  }

  return *this;
}
e2sm_rc_ind_msg_format1_s& e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format1()
{
  set(types::ind_msg_format1);
  return c.get<e2sm_rc_ind_msg_format1_s>();
}
e2sm_rc_ind_msg_format2_s& e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format2()
{
  set(types::ind_msg_format2);
  return c.get<e2sm_rc_ind_msg_format2_s>();
}
e2sm_rc_ind_msg_format3_s& e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format3()
{
  set(types::ind_msg_format3);
  return c.get<e2sm_rc_ind_msg_format3_s>();
}
void e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format4()
{
  set(types::ind_msg_format4);
}
e2sm_rc_ind_msg_format5_s& e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format5()
{
  set(types::ind_msg_format5);
  return c.get<e2sm_rc_ind_msg_format5_s>();
}
e2sm_rc_ind_msg_format6_s& e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::set_ind_msg_format6()
{
  set(types::ind_msg_format6);
  return c.get<e2sm_rc_ind_msg_format6_s>();
}
void e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::ind_msg_format1:
      j.write_fieldname("indicationMessage-Format1");
      c.get<e2sm_rc_ind_msg_format1_s>().to_json(j);
      break;
    case types::ind_msg_format2:
      j.write_fieldname("indicationMessage-Format2");
      c.get<e2sm_rc_ind_msg_format2_s>().to_json(j);
      break;
    case types::ind_msg_format3:
      j.write_fieldname("indicationMessage-Format3");
      c.get<e2sm_rc_ind_msg_format3_s>().to_json(j);
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      j.write_fieldname("indicationMessage-Format5");
      c.get<e2sm_rc_ind_msg_format5_s>().to_json(j);
      break;
    case types::ind_msg_format6:
      j.write_fieldname("indicationMessage-Format6");
      c.get<e2sm_rc_ind_msg_format6_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::ind_msg_format1:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format1_s>().pack(bref));
      break;
    case types::ind_msg_format2:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format2_s>().pack(bref));
      break;
    case types::ind_msg_format3:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format3_s>().pack(bref));
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format5_s>().pack(bref));
      break;
    case types::ind_msg_format6: {
      varlength_field_pack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format6_s>().pack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::ind_msg_format1:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format1_s>().unpack(bref));
      break;
    case types::ind_msg_format2:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format2_s>().unpack(bref));
      break;
    case types::ind_msg_format3:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format3_s>().unpack(bref));
      break;
    case types::ind_msg_format4:
      break;
    case types::ind_msg_format5:
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format5_s>().unpack(bref));
      break;
    case types::ind_msg_format6: {
      varlength_field_unpack_guard varlen_scope(bref, true);
      HANDLE_CODE(c.get<e2sm_rc_ind_msg_format6_s>().unpack(bref));
    } break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"indicationMessage-Format1",
                                "indicationMessage-Format2",
                                "indicationMessage-Format3",
                                "indicationMessage-Format4",
                                "indicationMessage-Format5",
                                "indicationMessage-Format6"};
  return convert_enum_idx(names, 6, value, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::types");
}
uint8_t e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2, 3, 4, 5, 6};
  return map_enum_number(numbers, 6, value, "e2sm_rc_ind_msg_s::ric_ind_msg_formats_c_::types");
}

// E2SM-RC-QueryDefinition ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_definition_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_query_definition_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_definition_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_query_definition_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_definition_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-queryDefinition-formats");
  ric_query_definition_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_query_definition_s::ric_query_definition_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("queryRequest-Format1");
  c.to_json(j);
  j.end_obj();
}
SRSASN_CODE e2sm_rc_query_definition_s::ric_query_definition_formats_c_::pack(bit_ref& bref) const
{
  pack_enum(bref, type());
  HANDLE_CODE(c.pack(bref));
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_definition_s::ric_query_definition_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  unpack_enum(e, bref);
  if (e != type()) {
    log_invalid_choice_id(e, "e2sm_rc_query_definition_s::ric_query_definition_formats_c_");
    return SRSASN_ERROR_DECODE_FAIL;
  }
  HANDLE_CODE(c.unpack(bref));
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_query_definition_s::ric_query_definition_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"queryRequest-Format1"};
  return convert_enum_idx(names, 1, value, "e2sm_rc_query_definition_s::ric_query_definition_formats_c_::types");
}
uint8_t e2sm_rc_query_definition_s::ric_query_definition_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1};
  return map_enum_number(numbers, 1, value, "e2sm_rc_query_definition_s::ric_query_definition_formats_c_::types");
}

// E2SM-RC-QueryHeader ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_hdr_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_query_hdr_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_hdr_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_query_hdr_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_hdr_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-queryHeader-formats");
  ric_query_hdr_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("queryHeader-Format1");
  c.to_json(j);
  j.end_obj();
}
SRSASN_CODE e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::pack(bit_ref& bref) const
{
  pack_enum(bref, type());
  HANDLE_CODE(c.pack(bref));
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  unpack_enum(e, bref);
  if (e != type()) {
    log_invalid_choice_id(e, "e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_");
    return SRSASN_ERROR_DECODE_FAIL;
  }
  HANDLE_CODE(c.unpack(bref));
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"queryHeader-Format1"};
  return convert_enum_idx(names, 1, value, "e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::types");
}
uint8_t e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1};
  return map_enum_number(numbers, 1, value, "e2sm_rc_query_hdr_s::ric_query_hdr_formats_c_::types");
}

// E2SM-RC-QueryOutcome ::= SEQUENCE
SRSASN_CODE e2sm_rc_query_outcome_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ric_query_outcome_formats.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ric_query_outcome_formats.unpack(bref));

  return SRSASN_SUCCESS;
}
void e2sm_rc_query_outcome_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ric-queryOutcome-formats");
  ric_query_outcome_formats.to_json(j);
  j.end_obj();
}

void e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::destroy_()
{
  switch (type_) {
    case types::query_outcome_format1:
      c.destroy<e2sm_rc_query_outcome_format1_s>();
      break;
    case types::query_outcome_format2:
      c.destroy<e2sm_rc_query_outcome_format2_s>();
      break;
    default:
      break;
  }
}
void e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::set(types::options e)
{
  destroy_();
  type_ = e;
  switch (type_) {
    case types::query_outcome_format1:
      c.init<e2sm_rc_query_outcome_format1_s>();
      break;
    case types::query_outcome_format2:
      c.init<e2sm_rc_query_outcome_format2_s>();
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
  }
}
e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::ric_query_outcome_formats_c_(
    const e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_& other)
{
  type_ = other.type();
  switch (type_) {
    case types::query_outcome_format1:
      c.init(other.c.get<e2sm_rc_query_outcome_format1_s>());
      break;
    case types::query_outcome_format2:
      c.init(other.c.get<e2sm_rc_query_outcome_format2_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
  }
}
e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_& e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::operator=(
    const e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_& other)
{
  if (this == &other) {
    return *this;
  }
  set(other.type());
  switch (type_) {
    case types::query_outcome_format1:
      c.set(other.c.get<e2sm_rc_query_outcome_format1_s>());
      break;
    case types::query_outcome_format2:
      c.set(other.c.get<e2sm_rc_query_outcome_format2_s>());
      break;
    case types::nulltype:
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
  }

  return *this;
}
e2sm_rc_query_outcome_format1_s& e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::set_query_outcome_format1()
{
  set(types::query_outcome_format1);
  return c.get<e2sm_rc_query_outcome_format1_s>();
}
e2sm_rc_query_outcome_format2_s& e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::set_query_outcome_format2()
{
  set(types::query_outcome_format2);
  return c.get<e2sm_rc_query_outcome_format2_s>();
}
void e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::to_json(json_writer& j) const
{
  j.start_obj();
  switch (type_) {
    case types::query_outcome_format1:
      j.write_fieldname("queryOutcome-Format1");
      c.get<e2sm_rc_query_outcome_format1_s>().to_json(j);
      break;
    case types::query_outcome_format2:
      j.write_fieldname("queryOutcome-Format2");
      c.get<e2sm_rc_query_outcome_format2_s>().to_json(j);
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
  }
  j.end_obj();
}
SRSASN_CODE e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::pack(bit_ref& bref) const
{
  type_.pack(bref);
  switch (type_) {
    case types::query_outcome_format1:
      HANDLE_CODE(c.get<e2sm_rc_query_outcome_format1_s>().pack(bref));
      break;
    case types::query_outcome_format2:
      HANDLE_CODE(c.get<e2sm_rc_query_outcome_format2_s>().pack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
      return SRSASN_ERROR_ENCODE_FAIL;
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::unpack(cbit_ref& bref)
{
  types e;
  e.unpack(bref);
  set(e);
  switch (type_) {
    case types::query_outcome_format1:
      HANDLE_CODE(c.get<e2sm_rc_query_outcome_format1_s>().unpack(bref));
      break;
    case types::query_outcome_format2:
      HANDLE_CODE(c.get<e2sm_rc_query_outcome_format2_s>().unpack(bref));
      break;
    default:
      log_invalid_choice_id(type_, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_");
      return SRSASN_ERROR_DECODE_FAIL;
  }
  return SRSASN_SUCCESS;
}

const char* e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::types_opts::to_string() const
{
  static const char* names[] = {"queryOutcome-Format1", "queryOutcome-Format2"};
  return convert_enum_idx(names, 2, value, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::types");
}
uint8_t e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::types_opts::to_number() const
{
  static const uint8_t numbers[] = {1, 2};
  return map_enum_number(numbers, 2, value, "e2sm_rc_query_outcome_s::ric_query_outcome_formats_c_::types");
}

// E2SM-RC-RANFunctionDefinition ::= SEQUENCE
SRSASN_CODE e2sm_rc_ran_function_definition_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_function_definition_event_trigger_present, 1));
  HANDLE_CODE(bref.pack(ran_function_definition_report_present, 1));
  HANDLE_CODE(bref.pack(ran_function_definition_insert_present, 1));
  HANDLE_CODE(bref.pack(ran_function_definition_ctrl_present, 1));
  HANDLE_CODE(bref.pack(ran_function_definition_policy_present, 1));

  HANDLE_CODE(ran_function_name.pack(bref));
  if (ran_function_definition_event_trigger_present) {
    HANDLE_CODE(ran_function_definition_event_trigger.pack(bref));
  }
  if (ran_function_definition_report_present) {
    HANDLE_CODE(ran_function_definition_report.pack(bref));
  }
  if (ran_function_definition_insert_present) {
    HANDLE_CODE(ran_function_definition_insert.pack(bref));
  }
  if (ran_function_definition_ctrl_present) {
    HANDLE_CODE(ran_function_definition_ctrl.pack(bref));
  }
  if (ran_function_definition_policy_present) {
    HANDLE_CODE(ran_function_definition_policy.pack(bref));
  }

  if (ext) {
    HANDLE_CODE(bref.pack(ran_function_definition_query.is_present(), 1));

    if (ran_function_definition_query.is_present()) {
      HANDLE_CODE(ran_function_definition_query->pack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
SRSASN_CODE e2sm_rc_ran_function_definition_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_function_definition_event_trigger_present, 1));
  HANDLE_CODE(bref.unpack(ran_function_definition_report_present, 1));
  HANDLE_CODE(bref.unpack(ran_function_definition_insert_present, 1));
  HANDLE_CODE(bref.unpack(ran_function_definition_ctrl_present, 1));
  HANDLE_CODE(bref.unpack(ran_function_definition_policy_present, 1));

  HANDLE_CODE(ran_function_name.unpack(bref));
  if (ran_function_definition_event_trigger_present) {
    HANDLE_CODE(ran_function_definition_event_trigger.unpack(bref));
  }
  if (ran_function_definition_report_present) {
    HANDLE_CODE(ran_function_definition_report.unpack(bref));
  }
  if (ran_function_definition_insert_present) {
    HANDLE_CODE(ran_function_definition_insert.unpack(bref));
  }
  if (ran_function_definition_ctrl_present) {
    HANDLE_CODE(ran_function_definition_ctrl.unpack(bref));
  }
  if (ran_function_definition_policy_present) {
    HANDLE_CODE(ran_function_definition_policy.unpack(bref));
  }

  if (ext) {
    unpack_presence_flag(ran_function_definition_query, bref);

    if (ran_function_definition_query.is_present()) {
      HANDLE_CODE(ran_function_definition_query->unpack(bref));
    }
  }
  return SRSASN_SUCCESS;
}
void e2sm_rc_ran_function_definition_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranFunction-Name");
  ran_function_name.to_json(j);
  if (ran_function_definition_event_trigger_present) {
    j.write_fieldname("ranFunctionDefinition-EventTrigger");
    ran_function_definition_event_trigger.to_json(j);
  }
  if (ran_function_definition_report_present) {
    j.write_fieldname("ranFunctionDefinition-Report");
    ran_function_definition_report.to_json(j);
  }
  if (ran_function_definition_insert_present) {
    j.write_fieldname("ranFunctionDefinition-Insert");
    ran_function_definition_insert.to_json(j);
  }
  if (ran_function_definition_ctrl_present) {
    j.write_fieldname("ranFunctionDefinition-Control");
    ran_function_definition_ctrl.to_json(j);
  }
  if (ran_function_definition_policy_present) {
    j.write_fieldname("ranFunctionDefinition-Policy");
    ran_function_definition_policy.to_json(j);
  }
  if (ext) {
    if (ran_function_definition_query.is_present()) {
      j.write_fieldname("ranFunctionDefinition-Query");
      ran_function_definition_query->to_json(j);
    }
  }
  j.end_obj();
}

// RANParameter-Definition-Choice-LIST ::= SEQUENCE
SRSASN_CODE ran_param_definition_choice_list_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_choice_list_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_param_definition_choice_list_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameter-List");
  for (const auto& e1 : ran_param_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-Definition-Choice-STRUCTURE ::= SEQUENCE
SRSASN_CODE ran_param_definition_choice_structure_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_structure, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_definition_choice_structure_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_structure, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_param_definition_choice_structure_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameter-STRUCTURE");
  for (const auto& e1 : ran_param_structure) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-Testing-Item-Choice-ElementFalse ::= SEQUENCE
SRSASN_CODE ran_param_testing_item_choice_elem_false_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_value_present, 1));
  HANDLE_CODE(bref.pack(lc_or_present, 1));

  HANDLE_CODE(ran_param_test_condition.pack(bref));
  if (ran_param_value_present) {
    HANDLE_CODE(ran_param_value.pack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_choice_elem_false_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_value_present, 1));
  HANDLE_CODE(bref.unpack(lc_or_present, 1));

  HANDLE_CODE(ran_param_test_condition.unpack(bref));
  if (ran_param_value_present) {
    HANDLE_CODE(ran_param_value.unpack(bref));
  }
  if (lc_or_present) {
    HANDLE_CODE(lc_or.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void ran_param_testing_item_choice_elem_false_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-TestCondition");
  ran_param_test_condition.to_json(j);
  if (ran_param_value_present) {
    j.write_fieldname("ranParameter-Value");
    ran_param_value.to_json(j);
  }
  if (lc_or_present) {
    j.write_str("logicalOR", lc_or.to_string());
  }
  j.end_obj();
}

// RANParameter-Testing-Item-Choice-ElementTrue ::= SEQUENCE
SRSASN_CODE ran_param_testing_item_choice_elem_true_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ran_param_value.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_choice_elem_true_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ran_param_value.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_testing_item_choice_elem_true_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-value");
  ran_param_value.to_json(j);
  j.end_obj();
}

// RANParameter-Testing-Item-Choice-List ::= SEQUENCE
SRSASN_CODE ran_param_testing_item_choice_list_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_list, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_choice_list_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_list, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_param_testing_item_choice_list_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameter-List");
  for (const auto& e1 : ran_param_list) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-Testing-Item-Choice-Structure ::= SEQUENCE
SRSASN_CODE ran_param_testing_item_choice_structure_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(pack_dyn_seq_of(bref, ran_param_structure, 1, 65535, true));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_testing_item_choice_structure_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(unpack_dyn_seq_of(ran_param_structure, bref, 1, 65535, true));

  return SRSASN_SUCCESS;
}
void ran_param_testing_item_choice_structure_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.start_array("ranParameter-Structure");
  for (const auto& e1 : ran_param_structure) {
    e1.to_json(j);
  }
  j.end_array();
  j.end_obj();
}

// RANParameter-ValueType-Choice-ElementFalse ::= SEQUENCE
SRSASN_CODE ran_param_value_type_choice_elem_false_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(bref.pack(ran_param_value_present, 1));

  if (ran_param_value_present) {
    HANDLE_CODE(ran_param_value.pack(bref));
  }

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_type_choice_elem_false_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(bref.unpack(ran_param_value_present, 1));

  if (ran_param_value_present) {
    HANDLE_CODE(ran_param_value.unpack(bref));
  }

  return SRSASN_SUCCESS;
}
void ran_param_value_type_choice_elem_false_s::to_json(json_writer& j) const
{
  j.start_obj();
  if (ran_param_value_present) {
    j.write_fieldname("ranParameter-value");
    ran_param_value.to_json(j);
  }
  j.end_obj();
}

// RANParameter-ValueType-Choice-ElementTrue ::= SEQUENCE
SRSASN_CODE ran_param_value_type_choice_elem_true_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ran_param_value.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_type_choice_elem_true_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ran_param_value.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_value_type_choice_elem_true_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-value");
  ran_param_value.to_json(j);
  j.end_obj();
}

// RANParameter-ValueType-Choice-List ::= SEQUENCE
SRSASN_CODE ran_param_value_type_choice_list_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ran_param_list.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_type_choice_list_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ran_param_list.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_value_type_choice_list_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-List");
  ran_param_list.to_json(j);
  j.end_obj();
}

// RANParameter-ValueType-Choice-Structure ::= SEQUENCE
SRSASN_CODE ran_param_value_type_choice_structure_s::pack(bit_ref& bref) const
{
  bref.pack(ext, 1);
  HANDLE_CODE(ran_param_structure.pack(bref));

  return SRSASN_SUCCESS;
}
SRSASN_CODE ran_param_value_type_choice_structure_s::unpack(cbit_ref& bref)
{
  bref.unpack(ext, 1);
  HANDLE_CODE(ran_param_structure.unpack(bref));

  return SRSASN_SUCCESS;
}
void ran_param_value_type_choice_structure_s::to_json(json_writer& j) const
{
  j.start_obj();
  j.write_fieldname("ranParameter-Structure");
  ran_param_structure.to_json(j);
  j.end_obj();
}
