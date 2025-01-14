/* Include files */

#include <stddef.h>
#include "blas.h"
#include "F16_Real5_nn_1_sfun.h"
#include "c1_F16_Real5_nn_1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "F16_Real5_nn_1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[15] = { "t1", "deltaX", "nz", "ny",
  "nargin", "nargout", "dd", "dx", "t", "y", "tt", "aa", "nn", "mm", "imax" };

/* Function Declarations */
static void initialize_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void initialize_params_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance);
static void enable_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void disable_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance);
static void set_sim_state_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void sf_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void initSimStructsc1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);
static void registerMessagesc1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_b_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_mm, const char_T *c1_identifier, real_T
  c1_y[3]);
static void c1_c_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_d_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15]);
static real_T c1_mpower(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
  c1_a);
static void c1_eml_scalar_eg(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_F16_Real5_nn_1, const char_T *
  c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static real_T c1_get_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c);
static real_T *c1_access_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static real_T c1_get_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void c1_set_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c);
static real_T *c1_access_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b);
static void init_dsm_address_info(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_F16_Real5_nn_1 = 0U;
}

static void initialize_params_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static void enable_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_F16_Real5_nn_1
  (SFc1_F16_Real5_nn_1InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_d_y)[3];
  c1_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_d_y)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_F16_Real5_nn_1;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i1;
  real_T (*c1_y)[3];
  c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "y",
                        c1_dv0);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    (*c1_y)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_F16_Real5_nn_1 = c1_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_F16_Real5_nn_1");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_F16_Real5_nn_1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
}

static void sf_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_t;
  real_T (*c1_y)[3];
  real_T (*c1_dx)[3];
  real_T (*c1_dd)[3];
  c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_dx = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_dd = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_dd)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_dx)[c1_i3], 1U);
  }

  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_y)[c1_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_t, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_F16_Real5_nn_1(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_F16_Real5_nn_1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  int32_T c1_i5;
  real_T c1_dd[3];
  int32_T c1_i6;
  real_T c1_dx[3];
  real_T c1_t;
  uint32_T c1_debug_family_var_map[15];
  real_T c1_t1;
  real_T c1_deltaX;
  real_T c1_nz;
  real_T c1_ny;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_y[3];
  int32_T c1_i7;
  static real_T c1_dv1[3] = { 0.0, -2.0, 6.0 };

  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_b_hoistedGlobal[3];
  int32_T c1_i10;
  int32_T c1_i11;
  real_T c1_c_hoistedGlobal[3];
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  static real_T c1_dv2[3] = { 2.0, 0.0, 6.0 };

  real_T c1_b;
  real_T c1_b_b;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  real_T c1_d_hoistedGlobal[3];
  int32_T c1_i18;
  real_T c1_e_hoistedGlobal[3];
  real_T c1_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_c_y;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  real_T c1_c_a;
  real_T c1_e_b;
  real_T c1_d_y;
  real_T c1_d_a;
  real_T c1_f_b;
  real_T c1_e_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_f_y;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_f_hoistedGlobal[2];
  int32_T c1_i25;
  real_T c1_g_hoistedGlobal[2];
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_g_y;
  int32_T c1_i33;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_h_y;
  int32_T c1_i34;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_y;
  int32_T c1_i35;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_j_y;
  int32_T c1_i36;
  real_T *c1_b_t;
  real_T (*c1_k_y)[3];
  real_T (*c1_b_dx)[3];
  real_T (*c1_b_dd)[3];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c1_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_k_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_dx = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_dd = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_t;
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    c1_dd[c1_i5] = (*c1_b_dd)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    c1_dx[c1_i6] = (*c1_b_dx)[c1_i6];
  }

  c1_t = c1_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_t1, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_deltaX, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nz, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ny, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_dd, 6U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_dx, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_t, 8U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_tt_address, 10U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c1_aa_address, 11U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c1_nn_address, 12U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c1_mm_address, 13U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c1_imax_address, 14U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_t1 = c1_t - c1_get_tt(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, c1_t1 < 20.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
    for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
      c1_y[c1_i7] = c1_dv1[c1_i7];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    if (CV_EML_IF(0, 1, 1, c1_t1 < 50.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
      c1_y[0] = 4.0;
      c1_y[1] = c1_dx[1];
      c1_y[2] = c1_dx[2];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      guard4 = FALSE;
      if (CV_EML_COND(0, 1, 0, c1_t1 > 44.0)) {
        if (CV_EML_COND(0, 1, 1, c1_t1 < 45.0)) {
          CV_EML_MCDC(0, 1, 0, TRUE);
          CV_EML_IF(0, 1, 2, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
          for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
            c1_set_aa(chartInstance, c1_i8, c1_y[c1_i8]);
          }

          ssUpdateDataStoreLog(chartInstance->S, 0);
        } else {
          guard4 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(0, 1, 0, FALSE);
        CV_EML_IF(0, 1, 2, FALSE);
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
      if (CV_EML_IF(0, 1, 3, c1_t1 > 45.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
        for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
          c1_b_hoistedGlobal[c1_i9] = c1_get_aa(chartInstance, c1_i9);
        }

        for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
          c1_b_hoistedGlobal[c1_i10] *= 0.33333333333333331;
        }

        for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
          c1_c_hoistedGlobal[c1_i11] = c1_y[c1_i11];
        }

        for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
          c1_c_hoistedGlobal[c1_i12] *= 0.66666666666666663;
        }

        for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
          c1_set_aa(chartInstance, c1_i13, c1_b_hoistedGlobal[c1_i13] +
                    c1_c_hoistedGlobal[c1_i13]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 0);
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
      guard2 = FALSE;
      guard3 = FALSE;
      if (CV_EML_COND(0, 1, 2, c1_t > 50.0)) {
        if (CV_EML_COND(0, 1, 3, c1_t1 > 20.0)) {
          if (CV_EML_COND(0, 1, 4, c1_t1 < 23.0)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 4, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
            for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
              c1_y[c1_i14] = c1_dv2[c1_i14];
            }
          } else {
            guard2 = TRUE;
          }
        } else {
          guard3 = TRUE;
        }
      } else {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 4, FALSE);
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
      c1_deltaX = c1_dd[0] - c1_dx[0];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
      guard1 = FALSE;
      if (CV_EML_COND(0, 1, 5, c1_deltaX < -1.0)) {
        guard1 = TRUE;
      } else if (CV_EML_COND(0, 1, 6, c1_deltaX > 0.0)) {
        guard1 = TRUE;
      } else {
        CV_EML_MCDC(0, 1, 2, FALSE);
        CV_EML_IF(0, 1, 5, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
        c1_b = 1.0 - c1_mpower(chartInstance, c1_deltaX);
        c1_nz = c1_b;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
        c1_b_b = 1.0 - c1_mpower(chartInstance, c1_deltaX);
        c1_ny = c1_b_b;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(0, 1, 2, TRUE);
        CV_EML_IF(0, 1, 5, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
        c1_nz = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
        c1_ny = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
      for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
        c1_b_hoistedGlobal[c1_i15] = c1_get_nn(chartInstance, c1_i15);
      }

      for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
        c1_c_hoistedGlobal[c1_i16] = c1_get_aa(chartInstance, c1_i16);
      }

      for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
        c1_d_hoistedGlobal[c1_i17] = c1_get_mm(chartInstance, c1_i17);
      }

      for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
        c1_e_hoistedGlobal[c1_i18] = c1_get_nn(chartInstance, c1_i18);
      }

      c1_a = 1.0 - c1_ny;
      c1_c_b = (c1_c_hoistedGlobal[1] + c1_d_hoistedGlobal[1]) +
        c1_e_hoistedGlobal[1];
      c1_b_y = c1_a * c1_c_b;
      c1_b_a = c1_ny;
      c1_d_b = c1_dx[1];
      c1_c_y = c1_b_a * c1_d_b;
      for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
        c1_c_hoistedGlobal[c1_i19] = c1_get_aa(chartInstance, c1_i19);
      }

      for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
        c1_d_hoistedGlobal[c1_i20] = c1_get_mm(chartInstance, c1_i20);
      }

      for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
        c1_e_hoistedGlobal[c1_i21] = c1_get_nn(chartInstance, c1_i21);
      }

      c1_c_a = 1.0 - c1_nz;
      c1_e_b = (c1_c_hoistedGlobal[2] + c1_d_hoistedGlobal[2]) +
        c1_e_hoistedGlobal[2];
      c1_d_y = c1_c_a * c1_e_b;
      c1_d_a = c1_nz;
      c1_f_b = c1_dx[2];
      c1_e_y = c1_d_a * c1_f_b;
      c1_y[0] = c1_dx[0] + c1_b_hoistedGlobal[0];
      c1_y[1] = c1_b_y + c1_c_y;
      c1_y[2] = c1_d_y + c1_e_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
      c1_x = c1_dd[0] - c1_dx[0];
      c1_b_x = c1_x;
      c1_f_y = muDoubleScalarAbs(c1_b_x);
      if (CV_EML_IF(0, 1, 6, c1_f_y < 0.01)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
        c1_set_tt(chartInstance, 0, c1_t - 21.0);
        ssUpdateDataStoreLog(chartInstance->S, 4);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
        for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
          c1_b_hoistedGlobal[c1_i22] = c1_get_mm(chartInstance, c1_i22);
        }

        for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
          c1_b_hoistedGlobal[c1_i23] *= 0.5;
        }

        for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
          c1_f_hoistedGlobal[c1_i24] = c1_get_imax(chartInstance, c1_i24);
        }

        for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
          c1_g_hoistedGlobal[c1_i25] = c1_get_imax(chartInstance, c1_i25);
        }

        c1_c_hoistedGlobal[0] = 0.0;
        c1_c_hoistedGlobal[1] = c1_f_hoistedGlobal[0];
        c1_c_hoistedGlobal[2] = c1_g_hoistedGlobal[1];
        for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
          c1_c_hoistedGlobal[c1_i26] *= 0.5;
        }

        for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
          c1_set_mm(chartInstance, c1_i27, c1_b_hoistedGlobal[c1_i27] +
                    c1_c_hoistedGlobal[c1_i27]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 2);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
        for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
          c1_b_hoistedGlobal[c1_i28] = c1_get_nn(chartInstance, c1_i28);
        }

        c1_c_hoistedGlobal[0] = 0.0;
        c1_c_hoistedGlobal[1] = c1_dx[1] - c1_dd[1];
        c1_c_hoistedGlobal[2] = c1_dx[2] - c1_dd[2];
        for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
          c1_c_hoistedGlobal[c1_i29] *= 0.75;
        }

        for (c1_i30 = 0; c1_i30 < 3; c1_i30++) {
          c1_set_nn(chartInstance, c1_i30, c1_b_hoistedGlobal[c1_i30] +
                    c1_c_hoistedGlobal[c1_i30]);
        }

        ssUpdateDataStoreLog(chartInstance->S, 3);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
        for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
          c1_set_imax(chartInstance, c1_i31, 0.0);
        }

        ssUpdateDataStoreLog(chartInstance->S, 1);
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
        for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
          c1_b_hoistedGlobal[c1_i32] = c1_get_aa(chartInstance, c1_i32);
        }

        c1_c_x = c1_dx[1] - c1_b_hoistedGlobal[1];
        c1_d_x = c1_c_x;
        c1_g_y = muDoubleScalarAbs(c1_d_x);
        for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
          c1_f_hoistedGlobal[c1_i33] = c1_get_imax(chartInstance, c1_i33);
        }

        c1_e_x = c1_f_hoistedGlobal[0];
        c1_f_x = c1_e_x;
        c1_h_y = muDoubleScalarAbs(c1_f_x);
        if (CV_EML_IF(0, 1, 7, c1_g_y > c1_h_y)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
          c1_set_nn(chartInstance, 1, c1_dx[1] - c1_get_aa(chartInstance, 1));
          ssUpdateDataStoreLog(chartInstance->S, 3);
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
        for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
          c1_b_hoistedGlobal[c1_i34] = c1_get_aa(chartInstance, c1_i34);
        }

        c1_g_x = c1_dx[2] - c1_b_hoistedGlobal[2];
        c1_h_x = c1_g_x;
        c1_i_y = muDoubleScalarAbs(c1_h_x);
        for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
          c1_f_hoistedGlobal[c1_i35] = c1_get_imax(chartInstance, c1_i35);
        }

        c1_i_x = c1_f_hoistedGlobal[1];
        c1_j_x = c1_i_x;
        c1_j_y = muDoubleScalarAbs(c1_j_x);
        if (CV_EML_IF(0, 1, 8, c1_i_y > c1_j_y)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
          c1_set_imax(chartInstance, 1, c1_dx[2] - c1_get_aa(chartInstance, 2));
          ssUpdateDataStoreLog(chartInstance->S, 1);
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -54);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    (*c1_k_y)[c1_i36] = c1_y[c1_i36];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_F16_Real5_nn_1(SFc1_F16_Real5_nn_1InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i37;
  real_T c1_b_inData[2];
  int32_T c1_i38;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
    c1_b_inData[c1_i37] = (*(real_T (*)[2])c1_inData)[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    c1_u[c1_i38] = c1_b_inData[c1_i38];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i39;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
    c1_y[c1_i39] = c1_dv3[c1_i39];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_imax;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i40;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_imax = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_imax), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_imax);
  for (c1_i40 = 0; c1_i40 < 2; c1_i40++) {
    (*(real_T (*)[2])c1_outData)[c1_i40] = c1_y[c1_i40];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i41;
  real_T c1_b_inData[3];
  int32_T c1_i42;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
    c1_b_inData[c1_i41] = (*(real_T (*)[3])c1_inData)[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
    c1_u[c1_i42] = c1_b_inData[c1_i42];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_b_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_mm, const char_T *c1_identifier, real_T
  c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mm), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_mm);
}

static void c1_c_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv4[3];
  int32_T c1_i43;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
    c1_y[c1_i43] = c1_dv4[c1_i43];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_mm;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i44;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_mm = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mm), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_mm);
  for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
    (*(real_T (*)[3])c1_outData)[c1_i44] = c1_y[c1_i44];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_d_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_tt;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_tt = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_tt), &c1_thisId);
  sf_mex_destroy(&c1_tt);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_F16_Real5_nn_1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[15];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i45;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c1_i45 = 0; c1_i45 < 15; c1_i45++) {
    c1_r0 = &c1_info[c1_i45];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i45);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i45);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 1357926348U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 1319708366U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 1346488788U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_scalexp_compatible";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[2].fileTimeLo = 1286797196U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[3].name = "eml_div";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[3].fileTimeLo = 1313326210U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "mtimes";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].fileTimeLo = 1289494492U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "";
  c1_info[5].name = "mpower";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[5].fileTimeLo = 1286797242U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[6].name = "power";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[6].fileTimeLo = 1348170330U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[7].name = "eml_scalar_eg";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[7].fileTimeLo = 1286797196U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[8].name = "eml_scalexp_alloc";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[8].fileTimeLo = 1352399660U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[9].name = "floor";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[9].fileTimeLo = 1343808780U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[10].name = "eml_scalar_floor";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[10].fileTimeLo = 1286797126U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286797196U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[12].name = "mtimes";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].fileTimeLo = 1289494492U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "";
  c1_info[13].name = "abs";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[13].fileTimeLo = 1343808766U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[14].name = "eml_scalar_abs";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[14].fileTimeLo = 1286797112U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
}

static real_T c1_mpower(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, real_T
  c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_b;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  c1_e_a = c1_d_a;
  c1_b = c1_d_a;
  return c1_e_a * c1_b;
}

static void c1_eml_scalar_eg(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance)
{
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i46;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i46, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i46;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_F16_Real5_nn_1, const char_T *
  c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_F16_Real5_nn_1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_F16_Real5_nn_1);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static real_T c1_get_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_aa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'aa\' (#30) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_aa_address)[c1_b];
}

static void c1_set_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c1_b);
  if (chartInstance->c1_aa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'aa\' (#30) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_aa_address)[c1_b] = c1_c;
}

static real_T *c1_access_aa(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c1_aa_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'aa\' (#30) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_aa_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c1_c;
}

static real_T c1_get_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_imax_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'imax\' (#71) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_imax_address)[c1_b];
}

static void c1_set_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c1_b);
  if (chartInstance->c1_imax_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'imax\' (#71) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_imax_address)[c1_b] = c1_c;
}

static real_T *c1_access_imax(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c1_imax_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'imax\' (#71) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_imax_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c1_c;
}

static real_T c1_get_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_mm_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mm\' (#32) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_mm_address)[c1_b];
}

static void c1_set_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c1_b);
  if (chartInstance->c1_mm_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mm\' (#32) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_mm_address)[c1_b] = c1_c;
}

static real_T *c1_access_mm(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c1_mm_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'mm\' (#32) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_mm_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c1_c;
}

static real_T c1_get_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_nn_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'nn\' (#33) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c1_nn_address)[c1_b];
}

static void c1_set_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c1_b);
  if (chartInstance->c1_nn_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'nn\' (#33) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c1_nn_address)[c1_b] = c1_c;
}

static real_T *c1_access_nn(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c1_nn_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'nn\' (#33) in the initialization routine of the chart.\n");
  }

  c1_c = *chartInstance->c1_nn_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c1_c;
}

static real_T c1_get_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_tt_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tt\' (#31) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c1_tt_address;
}

static void c1_set_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance, uint32_T
                      c1_b, real_T c1_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 4, NULL, c1_b);
  if (chartInstance->c1_tt_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tt\' (#31) in the initialization routine of the chart.\n");
  }

  *chartInstance->c1_tt_address = c1_c;
}

static real_T *c1_access_tt(SFc1_F16_Real5_nn_1InstanceStruct *chartInstance,
  uint32_T c1_b)
{
  real_T *c1_c;
  ssReadFromDataStore(chartInstance->S, 4, NULL);
  if (chartInstance->c1_tt_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tt\' (#31) in the initialization routine of the chart.\n");
  }

  c1_c = chartInstance->c1_tt_address;
  if (c1_b == 0) {
    ssWriteToDataStore(chartInstance->S, 4, NULL);
  }

  return c1_c;
}

static void init_dsm_address_info(SFc1_F16_Real5_nn_1InstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "aa", (void **)
    &chartInstance->c1_aa_address, &chartInstance->c1_aa_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "imax", (void **)
    &chartInstance->c1_imax_address, &chartInstance->c1_imax_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "mm", (void **)
    &chartInstance->c1_mm_address, &chartInstance->c1_mm_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "nn", (void **)
    &chartInstance->c1_nn_address, &chartInstance->c1_nn_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "tt", (void **)
    &chartInstance->c1_tt_address, &chartInstance->c1_tt_index);
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

void sf_c1_F16_Real5_nn_1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4186468688U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(128337943U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3633216687U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2796949709U);
}

mxArray *sf_c1_F16_Real5_nn_1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("A5LWhOK2eWJZhtm8aErelE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c1_F16_Real5_nn_1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_F16_Real5_nn_1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_F16_Real5_nn_1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_F16_Real5_nn_1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
    chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _F16_Real5_nn_1MachineNumber_,
           1,
           1,
           1,
           9,
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
          init_script_number_translation(_F16_Real5_nn_1MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_F16_Real5_nn_1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _F16_Real5_nn_1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dd");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dx");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
          _SFD_SET_DATA_PROPS(4,11,0,0,"aa");
          _SFD_SET_DATA_PROPS(5,11,0,0,"tt");
          _SFD_SET_DATA_PROPS(6,11,0,0,"mm");
          _SFD_SET_DATA_PROPS(7,11,0,0,"nn");
          _SFD_SET_DATA_PROPS(8,11,0,0,"imax");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,0,7,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3005);
        _SFD_CV_INIT_EML_IF(0,1,0,136,144,161,1196);
        _SFD_CV_INIT_EML_IF(0,1,1,161,173,405,1196);
        _SFD_CV_INIT_EML_IF(0,1,2,205,220,-1,244);
        _SFD_CV_INIT_EML_IF(0,1,3,250,258,-1,336);
        _SFD_CV_INIT_EML_IF(0,1,4,343,364,-1,393);
        _SFD_CV_INIT_EML_IF(0,1,5,438,462,495,561);
        _SFD_CV_INIT_EML_IF(0,1,6,746,770,1006,1191);
        _SFD_CV_INIT_EML_IF(0,1,7,1018,1050,-1,1092);
        _SFD_CV_INIT_EML_IF(0,1,8,1100,1132,-1,1176);

        {
          static int condStart[] = { 208, 215 };

          static int condEnd[] = { 213, 220 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,208,220,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 346, 352, 359 };

          static int condEnd[] = { 350, 357, 364 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,346,364,3,2,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 441, 454 };

          static int condEnd[] = { 450, 462 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,441,462,2,5,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

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
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T *c1_t;
          real_T (*c1_dd)[3];
          real_T (*c1_dx)[3];
          real_T (*c1_y)[3];
          c1_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_dx = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c1_dd = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_dd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_dx);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c1_aa_address);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_tt_address);
          _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c1_mm_address);
          _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c1_nn_address);
          _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c1_imax_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _F16_Real5_nn_1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "M9t4i4B7oSZk6BS8lnCNuG";
}

static void sf_opaque_initialize_c1_F16_Real5_nn_1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
  initialize_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_F16_Real5_nn_1(void *chartInstanceVar)
{
  enable_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_F16_Real5_nn_1(void *chartInstanceVar)
{
  disable_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_F16_Real5_nn_1(void *chartInstanceVar)
{
  sf_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_F16_Real5_nn_1(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_F16_Real5_nn_1
    ((SFc1_F16_Real5_nn_1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_F16_Real5_nn_1();/* state var info */
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

extern void sf_internal_set_sim_state_c1_F16_Real5_nn_1(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_F16_Real5_nn_1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_F16_Real5_nn_1(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_F16_Real5_nn_1(S);
}

static void sf_opaque_set_sim_state_c1_F16_Real5_nn_1(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_F16_Real5_nn_1(S, st);
}

static void sf_opaque_terminate_c1_F16_Real5_nn_1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_F16_Real5_nn_1InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_F16_Real5_nn_1_optimization_info();
    }

    finalize_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_F16_Real5_nn_1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_F16_Real5_nn_1((SFc1_F16_Real5_nn_1InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_F16_Real5_nn_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_F16_Real5_nn_1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3334236539U));
  ssSetChecksum1(S,(3344235222U));
  ssSetChecksum2(S,(12816082U));
  ssSetChecksum3(S,(3599418411U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_F16_Real5_nn_1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_F16_Real5_nn_1(SimStruct *S)
{
  SFc1_F16_Real5_nn_1InstanceStruct *chartInstance;
  chartInstance = (SFc1_F16_Real5_nn_1InstanceStruct *)utMalloc(sizeof
    (SFc1_F16_Real5_nn_1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_F16_Real5_nn_1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_F16_Real5_nn_1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_F16_Real5_nn_1;
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

void c1_F16_Real5_nn_1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_F16_Real5_nn_1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_F16_Real5_nn_1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_F16_Real5_nn_1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_F16_Real5_nn_1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
