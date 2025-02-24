/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DrogueVisualNavigation_sfun.h"
#include "c2_DrogueVisualNavigation.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DrogueVisualNavigation_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[9] = { "Ir", "s", "Iin", "i", "j",
  "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void initialize_params_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void enable_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void disable_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void set_sim_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void sf_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void c2_chartstep_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void initSimStructsc2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void registerMessagesc2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[345600]);
static void c2_b_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[345600]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[345600]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DrogueVisualNavigation, const
  char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_DrogueVisualNavigation = 0U;
}

static void initialize_params_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
}

static void enable_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  static real_T c2_u[345600];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_d_y)[345600];
  c2_d_y = (real_T (*)[345600])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 345600; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 480, 720),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_DrogueVisualNavigation;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  static real_T c2_dv0[345600];
  int32_T c2_i1;
  real_T (*c2_y)[345600];
  c2_y = (real_T (*)[345600])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 345600; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_DrogueVisualNavigation = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_DrogueVisualNavigation");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_DrogueVisualNavigation(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
}

static void sf_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T (*c2_y)[345600];
  uint8_T (*c2_u)[1036800];
  c2_y = (real_T (*)[345600])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = (uint8_T (*)[1036800])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 1036800; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_u)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 345600; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_y)[c2_i3], 1U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_DrogueVisualNavigation(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DrogueVisualNavigationMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  static uint8_T c2_u[1036800];
  uint32_T c2_debug_family_var_map[9];
  static uint8_T c2_Ir[345600];
  real_T c2_s[2];
  static real_T c2_Iin[345600];
  real_T c2_i;
  real_T c2_j;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  static real_T c2_y[345600];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  static uint8_T c2_a[345600];
  int32_T c2_i8;
  uint8_T c2_u0;
  uint8_T c2_u1;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  static uint8_T c2_b_a[345600];
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  static uint8_T c2_c_a[345600];
  int32_T c2_i15;
  uint32_T c2_q0;
  uint32_T c2_qY;
  uint32_T c2_u2;
  uint32_T c2_b_q0;
  uint32_T c2_b_qY;
  uint32_T c2_u3;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_b_i;
  int32_T c2_b_j;
  int32_T c2_i18;
  int32_T c2_i19;
  real_T (*c2_b_y)[345600];
  uint8_T (*c2_b_u)[1036800];
  c2_b_y = (real_T (*)[345600])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (uint8_T (*)[1036800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 1036800; c2_i4++) {
    c2_u[c2_i4] = (*c2_b_u)[c2_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Ir, 0U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_s, 1U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Iin, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_j, 4U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 5U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 6U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_u, 7U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 720; c2_i6++) {
    for (c2_i7 = 0; c2_i7 < 480; c2_i7++) {
      c2_a[c2_i7 + c2_i5] = c2_u[c2_i7 + c2_i5];
    }

    c2_i5 += 480;
  }

  for (c2_i8 = 0; c2_i8 < 345600; c2_i8++) {
    c2_u0 = c2_a[c2_i8];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c2_u0 > 127)) {
      c2_u1 = MAX_uint8_T;
    } else {
      c2_u1 = (uint8_T)(c2_u0 << 1);
    }

    c2_a[c2_i8] = c2_u1;
  }

  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 720; c2_i10++) {
    for (c2_i11 = 0; c2_i11 < 480; c2_i11++) {
      c2_b_a[c2_i11 + c2_i9] = c2_u[(c2_i11 + c2_i9) + 345600];
    }

    c2_i9 += 480;
  }

  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 720; c2_i13++) {
    for (c2_i14 = 0; c2_i14 < 480; c2_i14++) {
      c2_c_a[c2_i14 + c2_i12] = c2_u[(c2_i14 + c2_i12) + 691200];
    }

    c2_i12 += 480;
  }

  for (c2_i15 = 0; c2_i15 < 345600; c2_i15++) {
    c2_q0 = c2_a[c2_i15];
    c2_qY = c2_q0 - (uint32_T)c2_b_a[c2_i15];
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c2_qY > c2_q0)) {
      c2_qY = 0U;
    }

    c2_u2 = c2_qY;
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c2_u2 > 255U)) {
      c2_u2 = 255U;
    }

    c2_b_q0 = (uint8_T)c2_u2;
    c2_b_qY = c2_b_q0 - (uint32_T)c2_c_a[c2_i15];
    if (CV_SATURATION_EVAL(4, 0, 2, 0, c2_b_qY > c2_b_q0)) {
      c2_b_qY = 0U;
    }

    c2_u3 = c2_b_qY;
    if (CV_SATURATION_EVAL(4, 0, 2, 0, c2_u3 > 255U)) {
      c2_u3 = 255U;
    }

    c2_Ir[c2_i15] = (uint8_T)c2_u3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i16 = 0; c2_i16 < 2; c2_i16++) {
    c2_s[c2_i16] = 480.0 + 240.0 * (real_T)c2_i16;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i17 = 0; c2_i17 < 345600; c2_i17++) {
    c2_Iin[c2_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_i = 1.0;
  c2_b_i = 0;
  while (c2_b_i < 480) {
    c2_i = 1.0 + (real_T)c2_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
    c2_j = 1.0;
    c2_b_j = 0;
    while (c2_b_j < 720) {
      c2_j = 1.0 + (real_T)c2_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
      if (CV_EML_IF(0, 1, 0, (real_T)c2_Ir[((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)_SFD_INTEGER_CHECK("i",
              c2_i), 1, 480, 1, 0) + 480 * ((int32_T)(real_T)
             _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)_SFD_INTEGER_CHECK("j",
               c2_j), 1, 720, 2, 0) - 1)) - 1] < 50.0)) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
        c2_Iin[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                 _SFD_INTEGER_CHECK("i", c2_i), 1, 480, 1, 0) + 480 * ((int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                  _SFD_INTEGER_CHECK("j", c2_j), 1, 720, 2, 0) - 1)) - 1] = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
        c2_Iin[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                 _SFD_INTEGER_CHECK("i", c2_i), 1, 480, 1, 0) + 480 * ((int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                  _SFD_INTEGER_CHECK("j", c2_j), 1, 720, 2, 0) - 1)) - 1] = 1.0;
      }

      c2_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    c2_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  for (c2_i18 = 0; c2_i18 < 345600; c2_i18++) {
    c2_y[c2_i18] = c2_Iin[c2_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i19 = 0; c2_i19 < 345600; c2_i19++) {
    (*c2_b_y)[c2_i19] = c2_y[c2_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_DrogueVisualNavigation
  (SFc2_DrogueVisualNavigationInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  static real_T c2_b_inData[345600];
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  static real_T c2_u[345600];
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 720; c2_i21++) {
    for (c2_i22 = 0; c2_i22 < 480; c2_i22++) {
      c2_b_inData[c2_i22 + c2_i20] = (*(real_T (*)[345600])c2_inData)[c2_i22 +
        c2_i20];
    }

    c2_i20 += 480;
  }

  c2_i23 = 0;
  for (c2_i24 = 0; c2_i24 < 720; c2_i24++) {
    for (c2_i25 = 0; c2_i25 < 480; c2_i25++) {
      c2_u[c2_i25 + c2_i23] = c2_b_inData[c2_i25 + c2_i23];
    }

    c2_i23 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 480, 720),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[345600])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[345600])
{
  static real_T c2_dv1[345600];
  int32_T c2_i26;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 480,
                720);
  for (c2_i26 = 0; c2_i26 < 345600; c2_i26++) {
    c2_y[c2_i26] = c2_dv1[c2_i26];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static real_T c2_b_y[345600];
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  c2_i27 = 0;
  for (c2_i28 = 0; c2_i28 < 720; c2_i28++) {
    for (c2_i29 = 0; c2_i29 < 480; c2_i29++) {
      (*(real_T (*)[345600])c2_outData)[c2_i29 + c2_i27] = c2_b_y[c2_i29 +
        c2_i27];
    }

    c2_i27 += 480;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  static uint8_T c2_b_inData[1036800];
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  static uint8_T c2_u[1036800];
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i30 = 0;
  for (c2_i31 = 0; c2_i31 < 3; c2_i31++) {
    c2_i32 = 0;
    for (c2_i33 = 0; c2_i33 < 720; c2_i33++) {
      for (c2_i34 = 0; c2_i34 < 480; c2_i34++) {
        c2_b_inData[(c2_i34 + c2_i32) + c2_i30] = (*(uint8_T (*)[1036800])
          c2_inData)[(c2_i34 + c2_i32) + c2_i30];
      }

      c2_i32 += 480;
    }

    c2_i30 += 345600;
  }

  c2_i35 = 0;
  for (c2_i36 = 0; c2_i36 < 3; c2_i36++) {
    c2_i37 = 0;
    for (c2_i38 = 0; c2_i38 < 720; c2_i38++) {
      for (c2_i39 = 0; c2_i39 < 480; c2_i39++) {
        c2_u[(c2_i39 + c2_i37) + c2_i35] = c2_b_inData[(c2_i39 + c2_i37) +
          c2_i35];
      }

      c2_i37 += 480;
    }

    c2_i35 += 345600;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 3, 480, 720, 3),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i40;
  real_T c2_b_inData[2];
  int32_T c2_i41;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    c2_b_inData[c2_i40] = (*(real_T (*)[2])c2_inData)[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 2; c2_i41++) {
    c2_u[c2_i41] = c2_b_inData[c2_i41];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  static uint8_T c2_b_inData[345600];
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  static uint8_T c2_u[345600];
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 720; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 480; c2_i44++) {
      c2_b_inData[c2_i44 + c2_i42] = (*(uint8_T (*)[345600])c2_inData)[c2_i44 +
        c2_i42];
    }

    c2_i42 += 480;
  }

  c2_i45 = 0;
  for (c2_i46 = 0; c2_i46 < 720; c2_i46++) {
    for (c2_i47 = 0; c2_i47 < 480; c2_i47++) {
      c2_u[c2_i47 + c2_i45] = c2_b_inData[c2_i47 + c2_i45];
    }

    c2_i45 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 2, 480, 720),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[345600])
{
  static uint8_T c2_uv0[345600];
  int32_T c2_i48;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv0, 1, 3, 0U, 1, 0U, 2, 480,
                720);
  for (c2_i48 = 0; c2_i48 < 345600; c2_i48++) {
    c2_y[c2_i48] = c2_uv0[c2_i48];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Ir;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static uint8_T c2_y[345600];
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_Ir = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Ir), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Ir);
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 720; c2_i50++) {
    for (c2_i51 = 0; c2_i51 < 480; c2_i51++) {
      (*(uint8_T (*)[345600])c2_outData)[c2_i51 + c2_i49] = c2_y[c2_i51 + c2_i49];
    }

    c2_i49 += 480;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_DrogueVisualNavigation_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[1];
  c2_ResolvedFunctionInfo (*c2_b_info)[1];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i52;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[1])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mtimes";
  (*c2_b_info)[0].dominantType = "uint8";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[0].fileTimeLo = 1289494492U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c2_i52 = 0; c2_i52 < 1; c2_i52++) {
    c2_r0 = &c2_info[c2_i52];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i52);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i52);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i53;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i53, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i53;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DrogueVisualNavigation, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_DrogueVisualNavigation), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_DrogueVisualNavigation);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u4, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u4;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_DrogueVisualNavigationInstanceStruct
  *chartInstance)
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

void sf_c2_DrogueVisualNavigation_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2494214871U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2750315445U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1618186565U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(107172909U);
}

mxArray *sf_c2_DrogueVisualNavigation_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BDL396qPxvUkoRWjbSoVzF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(720);
      pr[2] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(480);
      pr[1] = (double)(720);
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

mxArray *sf_c2_DrogueVisualNavigation_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_DrogueVisualNavigation(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_DrogueVisualNavigation\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_DrogueVisualNavigation_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
    chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DrogueVisualNavigationMachineNumber_,
           2,
           1,
           1,
           2,
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
          init_script_number_translation(_DrogueVisualNavigationMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DrogueVisualNavigationMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DrogueVisualNavigationMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,3,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,248);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,34,-1,44);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,34,-1,55);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,34,-1,66);
        _SFD_CV_INIT_EML_IF(0,1,0,141,154,187,227);
        _SFD_CV_INIT_EML_FOR(0,1,0,104,117,239);
        _SFD_CV_INIT_EML_FOR(0,1,1,121,134,235);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 720;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 720;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          uint8_T (*c2_u)[1036800];
          real_T (*c2_y)[345600];
          c2_y = (real_T (*)[345600])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (uint8_T (*)[1036800])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DrogueVisualNavigationMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3v0QdKBuk3RW4AiIahEukC";
}

static void sf_opaque_initialize_c2_DrogueVisualNavigation(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_DrogueVisualNavigationInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_DrogueVisualNavigation
    ((SFc2_DrogueVisualNavigationInstanceStruct*) chartInstanceVar);
  initialize_c2_DrogueVisualNavigation
    ((SFc2_DrogueVisualNavigationInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_DrogueVisualNavigation(void *chartInstanceVar)
{
  enable_c2_DrogueVisualNavigation((SFc2_DrogueVisualNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_DrogueVisualNavigation(void *chartInstanceVar)
{
  disable_c2_DrogueVisualNavigation((SFc2_DrogueVisualNavigationInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_DrogueVisualNavigation(void *chartInstanceVar)
{
  sf_c2_DrogueVisualNavigation((SFc2_DrogueVisualNavigationInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_DrogueVisualNavigation
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_DrogueVisualNavigation
    ((SFc2_DrogueVisualNavigationInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_DrogueVisualNavigation();/* state var info */
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

extern void sf_internal_set_sim_state_c2_DrogueVisualNavigation(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_DrogueVisualNavigation();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_DrogueVisualNavigation
    ((SFc2_DrogueVisualNavigationInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_DrogueVisualNavigation
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_DrogueVisualNavigation(S);
}

static void sf_opaque_set_sim_state_c2_DrogueVisualNavigation(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_DrogueVisualNavigation(S, st);
}

static void sf_opaque_terminate_c2_DrogueVisualNavigation(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_DrogueVisualNavigationInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DrogueVisualNavigation_optimization_info();
    }

    finalize_c2_DrogueVisualNavigation
      ((SFc2_DrogueVisualNavigationInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_DrogueVisualNavigation
    ((SFc2_DrogueVisualNavigationInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_DrogueVisualNavigation(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_DrogueVisualNavigation
      ((SFc2_DrogueVisualNavigationInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_DrogueVisualNavigation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DrogueVisualNavigation_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(277629297U));
  ssSetChecksum1(S,(2104946336U));
  ssSetChecksum2(S,(1758420005U));
  ssSetChecksum3(S,(2171485372U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_DrogueVisualNavigation(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_DrogueVisualNavigation(SimStruct *S)
{
  SFc2_DrogueVisualNavigationInstanceStruct *chartInstance;
  chartInstance = (SFc2_DrogueVisualNavigationInstanceStruct *)utMalloc(sizeof
    (SFc2_DrogueVisualNavigationInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_DrogueVisualNavigationInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_DrogueVisualNavigation;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_DrogueVisualNavigation;
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

void c2_DrogueVisualNavigation_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_DrogueVisualNavigation(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_DrogueVisualNavigation(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_DrogueVisualNavigation(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_DrogueVisualNavigation_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
