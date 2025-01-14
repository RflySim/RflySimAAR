/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DrogueVisualNavigation4_biaoding_sfun.h"
#include "c4_DrogueVisualNavigation4_biaoding.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DrogueVisualNavigation4_biaoding_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[9] = { "Ir", "S", "Iin", "i", "j",
  "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void initialize_params_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void enable_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void disable_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void set_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void sf_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void c4_chartstep_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void initSimStructsc4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void registerMessagesc4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier, real_T c4_b_y[412800]);
static void c4_b_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[412800]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint8_T c4_y[412800]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_DrogueVisualNavigation4_biaoding, const char_T
   *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_DrogueVisualNavigation4_biaoding = 0U;
}

static void initialize_params_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
}

static void enable_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  static real_T c4_u[412800];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_d_y)[412800];
  c4_d_y = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 412800; c4_i0++) {
    c4_u[c4_i0] = (*c4_d_y)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal =
    chartInstance->c4_is_active_c4_DrogueVisualNavigation4_biaoding;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  static real_T c4_dv0[412800];
  int32_T c4_i1;
  real_T (*c4_y)[412800];
  c4_y = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "y",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 412800; c4_i1++) {
    (*c4_y)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_DrogueVisualNavigation4_biaoding =
    c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "is_active_c4_DrogueVisualNavigation4_biaoding");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_DrogueVisualNavigation4_biaoding(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
}

static void sf_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real_T (*c4_y)[412800];
  uint8_T (*c4_u)[1238400];
  c4_y = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = (uint8_T (*)[1238400])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 1238400; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c4_u)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 412800; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_y)[c4_i3], 1U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_DrogueVisualNavigation4_biaoding(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_DrogueVisualNavigation4_biaodingMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c4_chartstep_c4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
  int32_T c4_i4;
  static uint8_T c4_u[1238400];
  uint32_T c4_debug_family_var_map[9];
  static uint8_T c4_Ir[412800];
  real_T c4_S[2];
  static real_T c4_Iin[412800];
  real_T c4_i;
  real_T c4_j;
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  static real_T c4_y[412800];
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  static uint8_T c4_a[412800];
  int32_T c4_i8;
  uint8_T c4_u0;
  uint8_T c4_u1;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  static uint8_T c4_b_a[412800];
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  static uint8_T c4_c_a[412800];
  int32_T c4_i15;
  uint32_T c4_q0;
  uint32_T c4_qY;
  uint32_T c4_u2;
  uint32_T c4_b_q0;
  uint32_T c4_b_qY;
  uint32_T c4_u3;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_b_i;
  int32_T c4_b_j;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_b_y;
  int32_T c4_i18;
  int32_T c4_i19;
  real_T (*c4_c_y)[412800];
  uint8_T (*c4_b_u)[1238400];
  c4_c_y = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u = (uint8_T (*)[1238400])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 1238400; c4_i4++) {
    c4_u[c4_i4] = (*c4_b_u)[c4_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Ir, 0U, c4_e_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_S, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Iin, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_i, 3U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j, 4U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 5U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 6U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_u, 7U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_y, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_i5 = 0;
  for (c4_i6 = 0; c4_i6 < 860; c4_i6++) {
    for (c4_i7 = 0; c4_i7 < 480; c4_i7++) {
      c4_a[c4_i7 + c4_i5] = c4_u[(c4_i7 + c4_i5) + 412800];
    }

    c4_i5 += 480;
  }

  for (c4_i8 = 0; c4_i8 < 412800; c4_i8++) {
    c4_u0 = c4_a[c4_i8];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c4_u0 > 127)) {
      c4_u1 = MAX_uint8_T;
    } else {
      c4_u1 = (uint8_T)(c4_u0 << 1);
    }

    c4_a[c4_i8] = c4_u1;
  }

  c4_i9 = 0;
  for (c4_i10 = 0; c4_i10 < 860; c4_i10++) {
    for (c4_i11 = 0; c4_i11 < 480; c4_i11++) {
      c4_b_a[c4_i11 + c4_i9] = c4_u[c4_i11 + c4_i9];
    }

    c4_i9 += 480;
  }

  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 860; c4_i13++) {
    for (c4_i14 = 0; c4_i14 < 480; c4_i14++) {
      c4_c_a[c4_i14 + c4_i12] = c4_u[(c4_i14 + c4_i12) + 825600];
    }

    c4_i12 += 480;
  }

  for (c4_i15 = 0; c4_i15 < 412800; c4_i15++) {
    c4_q0 = c4_a[c4_i15];
    c4_qY = c4_q0 - (uint32_T)c4_b_a[c4_i15];
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c4_qY > c4_q0)) {
      c4_qY = 0U;
    }

    c4_u2 = c4_qY;
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c4_u2 > 255U)) {
      c4_u2 = 255U;
    }

    c4_b_q0 = (uint8_T)c4_u2;
    c4_b_qY = c4_b_q0 - (uint32_T)c4_c_a[c4_i15];
    if (CV_SATURATION_EVAL(4, 0, 2, 0, c4_b_qY > c4_b_q0)) {
      c4_b_qY = 0U;
    }

    c4_u3 = c4_b_qY;
    if (CV_SATURATION_EVAL(4, 0, 2, 0, c4_u3 > 255U)) {
      c4_u3 = 255U;
    }

    c4_Ir[c4_i15] = (uint8_T)c4_u3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
    c4_S[c4_i16] = 480.0 + 380.0 * (real_T)c4_i16;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  for (c4_i17 = 0; c4_i17 < 412800; c4_i17++) {
    c4_Iin[c4_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_i = 1.0;
  c4_b_i = 0;
  while (c4_b_i < 480) {
    c4_i = 1.0 + (real_T)c4_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
    c4_j = 1.0;
    c4_b_j = 0;
    while (c4_b_j < 860) {
      c4_j = 1.0 + (real_T)c4_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
      if (CV_EML_IF(0, 1, 0, (real_T)c4_Ir[((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)_SFD_INTEGER_CHECK("i",
              c4_i), 1, 480, 1, 0) + 480 * ((int32_T)(real_T)
             _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)_SFD_INTEGER_CHECK("j",
               c4_j), 1, 860, 2, 0) - 1)) - 1] < 50.0)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
        c4_Iin[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                 _SFD_INTEGER_CHECK("i", c4_i), 1, 480, 1, 0) + 480 * ((int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                  _SFD_INTEGER_CHECK("j", c4_j), 1, 860, 2, 0) - 1)) - 1] = 0.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
        c4_Iin[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                 _SFD_INTEGER_CHECK("i", c4_i), 1, 480, 1, 0) + 480 * ((int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                  _SFD_INTEGER_CHECK("j", c4_j), 1, 860, 2, 0) - 1)) - 1] = 1.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
      c4_A = c4_i;
      c4_x = c4_A;
      c4_b_x = c4_x;
      c4_b_y = c4_b_x / 480.0;
      if (CV_EML_IF(0, 1, 1, c4_b_y > 0.8)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
        c4_Iin[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                 _SFD_INTEGER_CHECK("i", c4_i), 1, 480, 1, 0) + 480 * ((int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Iin", (int32_T)
                  _SFD_INTEGER_CHECK("j", c4_j), 1, 860, 2, 0) - 1)) - 1] = 0.0;
      }

      c4_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    c4_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  for (c4_i18 = 0; c4_i18 < 412800; c4_i18++) {
    c4_y[c4_i18] = c4_Iin[c4_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i19 = 0; c4_i19 < 412800; c4_i19++) {
    (*c4_c_y)[c4_i19] = c4_y[c4_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
}

static void registerMessagesc4_DrogueVisualNavigation4_biaoding
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  static real_T c4_b_inData[412800];
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  static real_T c4_u[412800];
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i20 = 0;
  for (c4_i21 = 0; c4_i21 < 860; c4_i21++) {
    for (c4_i22 = 0; c4_i22 < 480; c4_i22++) {
      c4_b_inData[c4_i22 + c4_i20] = (*(real_T (*)[412800])c4_inData)[c4_i22 +
        c4_i20];
    }

    c4_i20 += 480;
  }

  c4_i23 = 0;
  for (c4_i24 = 0; c4_i24 < 860; c4_i24++) {
    for (c4_i25 = 0; c4_i25 < 480; c4_i25++) {
      c4_u[c4_i25 + c4_i23] = c4_b_inData[c4_i25 + c4_i23];
    }

    c4_i23 += 480;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_y, const char_T *c4_identifier, real_T c4_b_y[412800])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
}

static void c4_b_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[412800])
{
  static real_T c4_dv1[412800];
  int32_T c4_i26;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 480,
                860);
  for (c4_i26 = 0; c4_i26 < 412800; c4_i26++) {
    c4_y[c4_i26] = c4_dv1[c4_i26];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_y;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  static real_T c4_b_y[412800];
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_y = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
  c4_i27 = 0;
  for (c4_i28 = 0; c4_i28 < 860; c4_i28++) {
    for (c4_i29 = 0; c4_i29 < 480; c4_i29++) {
      (*(real_T (*)[412800])c4_outData)[c4_i29 + c4_i27] = c4_b_y[c4_i29 +
        c4_i27];
    }

    c4_i27 += 480;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  static uint8_T c4_b_inData[1238400];
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  static uint8_T c4_u[1238400];
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i30 = 0;
  for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
    c4_i32 = 0;
    for (c4_i33 = 0; c4_i33 < 860; c4_i33++) {
      for (c4_i34 = 0; c4_i34 < 480; c4_i34++) {
        c4_b_inData[(c4_i34 + c4_i32) + c4_i30] = (*(uint8_T (*)[1238400])
          c4_inData)[(c4_i34 + c4_i32) + c4_i30];
      }

      c4_i32 += 480;
    }

    c4_i30 += 412800;
  }

  c4_i35 = 0;
  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    c4_i37 = 0;
    for (c4_i38 = 0; c4_i38 < 860; c4_i38++) {
      for (c4_i39 = 0; c4_i39 < 480; c4_i39++) {
        c4_u[(c4_i39 + c4_i37) + c4_i35] = c4_b_inData[(c4_i39 + c4_i37) +
          c4_i35];
      }

      c4_i37 += 480;
    }

    c4_i35 += 412800;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 3, 480, 860, 3),
                FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i40;
  real_T c4_b_inData[2];
  int32_T c4_i41;
  real_T c4_u[2];
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i40 = 0; c4_i40 < 2; c4_i40++) {
    c4_b_inData[c4_i40] = (*(real_T (*)[2])c4_inData)[c4_i40];
  }

  for (c4_i41 = 0; c4_i41 < 2; c4_i41++) {
    c4_u[c4_i41] = c4_b_inData[c4_i41];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  static uint8_T c4_b_inData[412800];
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  static uint8_T c4_u[412800];
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i42 = 0;
  for (c4_i43 = 0; c4_i43 < 860; c4_i43++) {
    for (c4_i44 = 0; c4_i44 < 480; c4_i44++) {
      c4_b_inData[c4_i44 + c4_i42] = (*(uint8_T (*)[412800])c4_inData)[c4_i44 +
        c4_i42];
    }

    c4_i42 += 480;
  }

  c4_i45 = 0;
  for (c4_i46 = 0; c4_i46 < 860; c4_i46++) {
    for (c4_i47 = 0; c4_i47 < 480; c4_i47++) {
      c4_u[c4_i47 + c4_i45] = c4_b_inData[c4_i47 + c4_i45];
    }

    c4_i45 += 480;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 3, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, uint8_T c4_y[412800])
{
  static uint8_T c4_uv0[412800];
  int32_T c4_i48;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_uv0, 1, 3, 0U, 1, 0U, 2, 480,
                860);
  for (c4_i48 = 0; c4_i48 < 412800; c4_i48++) {
    c4_y[c4_i48] = c4_uv0[c4_i48];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Ir;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  static uint8_T c4_y[412800];
  int32_T c4_i49;
  int32_T c4_i50;
  int32_T c4_i51;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_Ir = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Ir), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_Ir);
  c4_i49 = 0;
  for (c4_i50 = 0; c4_i50 < 860; c4_i50++) {
    for (c4_i51 = 0; c4_i51 < 480; c4_i51++) {
      (*(uint8_T (*)[412800])c4_outData)[c4_i51 + c4_i49] = c4_y[c4_i51 + c4_i49];
    }

    c4_i49 += 480;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_DrogueVisualNavigation4_biaoding_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[5];
  c4_ResolvedFunctionInfo (*c4_b_info)[5];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i52;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[5])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mtimes";
  (*c4_b_info)[0].dominantType = "uint8";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[0].fileTimeLo = 1289494492U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "mrdivide";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].fileTimeLo = 1357926348U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 1319708366U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[2].name = "rdivide";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].fileTimeLo = 1346488788U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[3].name = "eml_scalexp_compatible";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c4_b_info)[3].fileTimeLo = 1286797196U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[4].name = "eml_div";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[4].fileTimeLo = 1313326210U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c4_i52 = 0; c4_i52 < 5; c4_i52++) {
    c4_r0 = &c4_info[c4_i52];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i52);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i52);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i53;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i53, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i53;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_b_is_active_c4_DrogueVisualNavigation4_biaoding, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_DrogueVisualNavigation4_biaoding), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_DrogueVisualNavigation4_biaoding);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u4;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u4, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u4;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance)
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

void sf_c4_DrogueVisualNavigation4_biaoding_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3915433171U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2011444518U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(265414858U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2655071811U);
}

mxArray *sf_c4_DrogueVisualNavigation4_biaoding_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JUxTAzCi0g5yhBpzyZUs7E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(860);
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
      pr[1] = (double)(860);
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

mxArray *sf_c4_DrogueVisualNavigation4_biaoding_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_DrogueVisualNavigation4_biaoding
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_DrogueVisualNavigation4_biaoding\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_DrogueVisualNavigation4_biaoding_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
    chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DrogueVisualNavigation4_biaodingMachineNumber_,
           4,
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
          init_script_number_translation
            (_DrogueVisualNavigation4_biaodingMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _DrogueVisualNavigation4_biaodingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DrogueVisualNavigation4_biaodingMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,2,0,3,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,321);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,34,-1,44);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,34,-1,55);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,34,-1,66);
        _SFD_CV_INIT_EML_IF(0,1,0,140,153,186,225);
        _SFD_CV_INIT_EML_IF(0,1,1,242,255,-1,289);
        _SFD_CV_INIT_EML_FOR(0,1,0,103,116,309);
        _SFD_CV_INIT_EML_FOR(0,1,1,120,133,305);
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
          dimVector[1]= 860;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          uint8_T (*c4_u)[1238400];
          real_T (*c4_y)[412800];
          c4_y = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u = (uint8_T (*)[1238400])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DrogueVisualNavigation4_biaodingMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "NoEKKbDIYZmr6qGwwJJKLC";
}

static void sf_opaque_initialize_c4_DrogueVisualNavigation4_biaoding(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar)
     ->S,0);
  initialize_params_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
  initialize_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_DrogueVisualNavigation4_biaoding(void
  *chartInstanceVar)
{
  enable_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_DrogueVisualNavigation4_biaoding(void
  *chartInstanceVar)
{
  disable_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_DrogueVisualNavigation4_biaoding(void
  *chartInstanceVar)
{
  sf_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c4_DrogueVisualNavigation4_biaoding(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_DrogueVisualNavigation4_biaoding
    ();                                /* state var info */
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

extern void sf_internal_set_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_DrogueVisualNavigation4_biaoding
    ();                                /* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c4_DrogueVisualNavigation4_biaoding(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_DrogueVisualNavigation4_biaoding(S);
}

static void sf_opaque_set_sim_state_c4_DrogueVisualNavigation4_biaoding
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_DrogueVisualNavigation4_biaoding(S, st);
}

static void sf_opaque_terminate_c4_DrogueVisualNavigation4_biaoding(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DrogueVisualNavigation4_biaoding_optimization_info();
    }

    finalize_c4_DrogueVisualNavigation4_biaoding
      ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_DrogueVisualNavigation4_biaoding
    ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_DrogueVisualNavigation4_biaoding(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_DrogueVisualNavigation4_biaoding
      ((SFc4_DrogueVisualNavigation4_biaodingInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_DrogueVisualNavigation4_biaoding(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_DrogueVisualNavigation4_biaoding_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3273931749U));
  ssSetChecksum1(S,(3915546250U));
  ssSetChecksum2(S,(2490614150U));
  ssSetChecksum3(S,(1040000760U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_DrogueVisualNavigation4_biaoding(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_DrogueVisualNavigation4_biaoding(SimStruct *S)
{
  SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *chartInstance;
  chartInstance = (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct *)
    utMalloc(sizeof(SFc4_DrogueVisualNavigation4_biaodingInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_DrogueVisualNavigation4_biaodingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c4_DrogueVisualNavigation4_biaoding;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_DrogueVisualNavigation4_biaoding;
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

void c4_DrogueVisualNavigation4_biaoding_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_DrogueVisualNavigation4_biaoding(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_DrogueVisualNavigation4_biaoding(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_DrogueVisualNavigation4_biaoding(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_DrogueVisualNavigation4_biaoding_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
