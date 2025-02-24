/* Include files */

#include <stddef.h>
#include "blas.h"
#include "F16_Real6_prb_method_data4liuying_sfun.h"
#include "c7_F16_Real6_prb_method_data4liuying.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "F16_Real6_prb_method_data4liuying_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[9] = { "u", "V", "a", "b", "nargin",
  "nargout", "u1", "u2", "y" };

/* Function Declarations */
static void initialize_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void initialize_params_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void enable_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void disable_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void set_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_st);
static void finalize_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void sf_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void initSimStructsc7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void registerMessagesc7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_y, const char_T *c7_identifier, real_T c7_b_y[3]);
static void c7_b_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[20]);
static real_T c7_mpower(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct
  *chartInstance, real_T c7_a);
static void c7_eml_scalar_eg
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);
static void c7_eml_error(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct
  *chartInstance);
static void c7_b_eml_error(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *
  chartInstance);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_b_is_active_c7_F16_Real6_prb_method_data4liuying, const char_T
   *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_F16_Real6_prb_method_data4liuying = 0U;
}

static void initialize_params_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static void enable_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[3];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T (*c7_d_y)[3];
  c7_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_u[c7_i0] = (*c7_d_y)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal =
    chartInstance->c7_is_active_c7_F16_Real6_prb_method_data4liuying;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[3];
  int32_T c7_i1;
  real_T (*c7_y)[3];
  c7_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "y",
                      c7_dv0);
  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    (*c7_y)[c7_i1] = c7_dv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_F16_Real6_prb_method_data4liuying =
    c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "is_active_c7_F16_Real6_prb_method_data4liuying");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_F16_Real6_prb_method_data4liuying(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static void sf_c7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  real_T c7_u1[3];
  int32_T c7_i6;
  real_T c7_u2[3];
  uint32_T c7_debug_family_var_map[9];
  real_T c7_u[3];
  real_T c7_V;
  real_T c7_a;
  real_T c7_b;
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 1.0;
  real_T c7_y[3];
  int32_T c7_i7;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_A;
  real_T c7_B;
  real_T c7_c_x;
  real_T c7_b_y;
  real_T c7_d_x;
  real_T c7_c_y;
  real_T c7_d_y;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_b_A;
  real_T c7_b_B;
  real_T c7_g_x;
  real_T c7_e_y;
  real_T c7_h_x;
  real_T c7_f_y;
  real_T c7_g_y;
  real_T c7_i_x;
  real_T c7_j_x;
  int32_T c7_i8;
  real_T (*c7_h_y)[3];
  real_T (*c7_b_u2)[3];
  real_T (*c7_b_u1)[3];
  boolean_T guard1 = FALSE;
  c7_b_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c7_h_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 3; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_u1)[c7_i2], 0U);
  }

  for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*c7_h_y)[c7_i3], 1U);
  }

  for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_u2)[c7_i4], 2U);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i5 = 0; c7_i5 < 3; c7_i5++) {
    c7_u1[c7_i5] = (*c7_b_u1)[c7_i5];
  }

  for (c7_i6 = 0; c7_i6 < 3; c7_i6++) {
    c7_u2[c7_i6] = (*c7_b_u2)[c7_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_u, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_V, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_a, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 5U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_u1, 6U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_u2, 7U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_y, 8U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  for (c7_i7 = 0; c7_i7 < 3; c7_i7++) {
    c7_u[c7_i7] = c7_u1[c7_i7] - c7_u2[c7_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  c7_x = (c7_mpower(chartInstance, c7_u[0]) + c7_mpower(chartInstance, c7_u[1]))
    + c7_mpower(chartInstance, c7_u[2]);
  c7_V = c7_x;
  if (c7_V < 0.0) {
    c7_eml_error(chartInstance);
  }

  c7_b_x = c7_V;
  c7_V = c7_b_x;
  c7_V = muDoubleScalarSqrt(c7_V);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_A = c7_u[2];
  c7_B = c7_u[0];
  c7_c_x = c7_A;
  c7_b_y = c7_B;
  c7_d_x = c7_c_x;
  c7_c_y = c7_b_y;
  c7_d_y = c7_d_x / c7_c_y;
  c7_e_x = c7_d_y;
  c7_a = c7_e_x;
  c7_f_x = c7_a;
  c7_a = c7_f_x;
  c7_a = muDoubleScalarAtan(c7_a);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 7);
  c7_b_A = c7_u[1];
  c7_b_B = c7_V;
  c7_g_x = c7_b_A;
  c7_e_y = c7_b_B;
  c7_h_x = c7_g_x;
  c7_f_y = c7_e_y;
  c7_g_y = c7_h_x / c7_f_y;
  c7_i_x = c7_g_y;
  c7_b = c7_i_x;
  guard1 = FALSE;
  if (c7_b < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < c7_b) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c7_b_eml_error(chartInstance);
  }

  c7_j_x = c7_b;
  c7_b = c7_j_x;
  c7_b = muDoubleScalarAsin(c7_b);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 8);
  c7_y[0] = c7_V;
  c7_y[1] = c7_a;
  c7_y[2] = c7_b;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c7_i8 = 0; c7_i8 < 3; c7_i8++) {
    (*c7_h_y)[c7_i8] = c7_y[c7_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_F16_Real6_prb_method_data4liuyingMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static void registerMessagesc7_F16_Real6_prb_method_data4liuying
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i9;
  real_T c7_b_inData[3];
  int32_T c7_i10;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    c7_b_inData[c7_i9] = (*(real_T (*)[3])c7_inData)[c7_i9];
  }

  for (c7_i10 = 0; c7_i10 < 3; c7_i10++) {
    c7_u[c7_i10] = c7_b_inData[c7_i10];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_y, const char_T *c7_identifier, real_T c7_b_y[3])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
}

static void c7_b_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv1[3];
  int32_T c7_i11;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    c7_y[c7_i11] = c7_dv1[c7_i11];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_y;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y[3];
  int32_T c7_i12;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_y = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
  for (c7_i12 = 0; c7_i12 < 3; c7_i12++) {
    (*(real_T (*)[3])c7_outData)[c7_i12] = c7_b_y[c7_i12];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray
  *sf_c7_F16_Real6_prb_method_data4liuying_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[20];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i13;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c7_i13 = 0; c7_i13 < 20; c7_i13++) {
    c7_r0 = &c7_info[c7_i13];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i13);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i13);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[20])
{
  c7_info[0].context = "";
  c7_info[0].name = "mpower";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[0].fileTimeLo = 1286797242U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[1].name = "power";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[1].fileTimeLo = 1348170330U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[2].name = "eml_scalar_eg";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[2].fileTimeLo = 1286797196U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[3].name = "eml_scalexp_alloc";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[3].fileTimeLo = 1352399660U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c7_info[4].name = "floor";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[4].fileTimeLo = 1343808780U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[5].name = "eml_scalar_floor";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c7_info[5].fileTimeLo = 1286797126U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c7_info[6].name = "eml_scalar_eg";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[6].fileTimeLo = 1286797196U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c7_info[7].name = "mtimes";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[7].fileTimeLo = 1289494492U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context = "";
  c7_info[8].name = "sqrt";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[8].fileTimeLo = 1343808786U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[9].name = "eml_error";
  c7_info[9].dominantType = "char";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[9].fileTimeLo = 1343808758U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[10].name = "eml_scalar_sqrt";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[10].fileTimeLo = 1286797138U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context = "";
  c7_info[11].name = "mrdivide";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[11].fileTimeLo = 1357926348U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 1319708366U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[12].name = "rdivide";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[12].fileTimeLo = 1346488788U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[13].name = "eml_scalexp_compatible";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c7_info[13].fileTimeLo = 1286797196U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
  c7_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[14].name = "eml_div";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[14].fileTimeLo = 1313326210U;
  c7_info[14].fileTimeHi = 0U;
  c7_info[14].mFileTimeLo = 0U;
  c7_info[14].mFileTimeHi = 0U;
  c7_info[15].context = "";
  c7_info[15].name = "atan";
  c7_info[15].dominantType = "double";
  c7_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c7_info[15].fileTimeLo = 1343808772U;
  c7_info[15].fileTimeHi = 0U;
  c7_info[15].mFileTimeLo = 0U;
  c7_info[15].mFileTimeHi = 0U;
  c7_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c7_info[16].name = "eml_scalar_atan";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c7_info[16].fileTimeLo = 1286797118U;
  c7_info[16].fileTimeHi = 0U;
  c7_info[16].mFileTimeLo = 0U;
  c7_info[16].mFileTimeHi = 0U;
  c7_info[17].context = "";
  c7_info[17].name = "asin";
  c7_info[17].dominantType = "double";
  c7_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c7_info[17].fileTimeLo = 1343808770U;
  c7_info[17].fileTimeHi = 0U;
  c7_info[17].mFileTimeLo = 0U;
  c7_info[17].mFileTimeHi = 0U;
  c7_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c7_info[18].name = "eml_error";
  c7_info[18].dominantType = "char";
  c7_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[18].fileTimeLo = 1343808758U;
  c7_info[18].fileTimeHi = 0U;
  c7_info[18].mFileTimeLo = 0U;
  c7_info[18].mFileTimeHi = 0U;
  c7_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c7_info[19].name = "eml_scalar_asin";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c7_info[19].fileTimeLo = 1343808776U;
  c7_info[19].fileTimeHi = 0U;
  c7_info[19].mFileTimeLo = 0U;
  c7_info[19].mFileTimeHi = 0U;
}

static real_T c7_mpower(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct
  *chartInstance, real_T c7_a)
{
  real_T c7_b_a;
  real_T c7_c_a;
  real_T c7_ak;
  real_T c7_d_a;
  real_T c7_e_a;
  real_T c7_b;
  c7_b_a = c7_a;
  c7_c_a = c7_b_a;
  c7_eml_scalar_eg(chartInstance);
  c7_ak = c7_c_a;
  c7_d_a = c7_ak;
  c7_eml_scalar_eg(chartInstance);
  c7_e_a = c7_d_a;
  c7_b = c7_d_a;
  return c7_e_a * c7_b;
}

static void c7_eml_scalar_eg
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

static void c7_eml_error(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct
  *chartInstance)
{
  int32_T c7_i14;
  static char_T c7_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  int32_T c7_i15;
  static char_T c7_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  for (c7_i14 = 0; c7_i14 < 30; c7_i14++) {
    c7_u[c7_i14] = c7_cv0[c7_i14];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c7_i15 = 0; c7_i15 < 4; c7_i15++) {
    c7_b_u[c7_i15] = c7_cv1[c7_i15];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c7_y, 14, c7_b_y));
}

static void c7_b_eml_error(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *
  chartInstance)
{
  int32_T c7_i16;
  static char_T c7_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  int32_T c7_i17;
  static char_T c7_cv3[4] = { 'a', 's', 'i', 'n' };

  char_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  for (c7_i16 = 0; c7_i16 < 30; c7_i16++) {
    c7_u[c7_i16] = c7_cv2[c7_i16];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c7_i17 = 0; c7_i17 < 4; c7_i17++) {
    c7_b_u[c7_i17] = c7_cv3[c7_i17];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c7_y, 14, c7_b_y));
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i18;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i18, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i18;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_b_is_active_c7_F16_Real6_prb_method_data4liuying, const char_T
   *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_F16_Real6_prb_method_data4liuying), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_F16_Real6_prb_method_data4liuying);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance, const
   mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info
  (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c7_F16_Real6_prb_method_data4liuying_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2082748797U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4188327070U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(504905053U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1933431847U);
}

mxArray *sf_c7_F16_Real6_prb_method_data4liuying_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ymBPK9XfTpJuhw4hZ63DEG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_F16_Real6_prb_method_data4liuying_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_F16_Real6_prb_method_data4liuying
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c7_F16_Real6_prb_method_data4liuying\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_F16_Real6_prb_method_data4liuying_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
    chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _F16_Real6_prb_method_data4liuyingMachineNumber_,
           7,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_F16_Real6_prb_method_data4liuyingMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _F16_Real6_prb_method_data4liuyingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _F16_Real6_prb_method_data4liuyingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u2");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,121);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c7_u1)[3];
          real_T (*c7_y)[3];
          real_T (*c7_u2)[3];
          c7_u2 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c7_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c7_u2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _F16_Real6_prb_method_data4liuyingMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "WSKRozi3mDZdXKmrDdTtKC";
}

static void sf_opaque_initialize_c7_F16_Real6_prb_method_data4liuying(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
  initialize_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_F16_Real6_prb_method_data4liuying(void
  *chartInstanceVar)
{
  enable_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_F16_Real6_prb_method_data4liuying(void
  *chartInstanceVar)
{
  disable_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_F16_Real6_prb_method_data4liuying(void
  *chartInstanceVar)
{
  sf_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c7_F16_Real6_prb_method_data4liuying(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c7_F16_Real6_prb_method_data4liuying();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c7_F16_Real6_prb_method_data4liuying();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c7_F16_Real6_prb_method_data4liuying(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_F16_Real6_prb_method_data4liuying(S);
}

static void sf_opaque_set_sim_state_c7_F16_Real6_prb_method_data4liuying
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_F16_Real6_prb_method_data4liuying(S, st);
}

static void sf_opaque_terminate_c7_F16_Real6_prb_method_data4liuying(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_F16_Real6_prb_method_data4liuying_optimization_info();
    }

    finalize_c7_F16_Real6_prb_method_data4liuying
      ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_F16_Real6_prb_method_data4liuying
    ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_F16_Real6_prb_method_data4liuying(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_F16_Real6_prb_method_data4liuying
      ((SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_F16_Real6_prb_method_data4liuying(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_F16_Real6_prb_method_data4liuying_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(409856718U));
  ssSetChecksum1(S,(451642930U));
  ssSetChecksum2(S,(3424252687U));
  ssSetChecksum3(S,(1996050978U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_F16_Real6_prb_method_data4liuying(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_F16_Real6_prb_method_data4liuying(SimStruct *S)
{
  SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *chartInstance;
  chartInstance = (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct *)
    utMalloc(sizeof(SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc7_F16_Real6_prb_method_data4liuyingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_F16_Real6_prb_method_data4liuying;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c7_F16_Real6_prb_method_data4liuying_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_F16_Real6_prb_method_data4liuying(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_F16_Real6_prb_method_data4liuying(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_F16_Real6_prb_method_data4liuying(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_F16_Real6_prb_method_data4liuying_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
