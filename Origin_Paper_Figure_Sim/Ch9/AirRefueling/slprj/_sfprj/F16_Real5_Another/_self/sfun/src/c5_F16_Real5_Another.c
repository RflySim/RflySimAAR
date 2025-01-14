/* Include files */

#include <stddef.h>
#include "blas.h"
#include "F16_Real5_Another_sfun.h"
#include "c5_F16_Real5_Another.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "F16_Real5_Another_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[18] = { "c_lat", "c_lon", "u1", "u2",
  "yy1", "yy2", "yp", "u3", "u4", "yy3", "yy4", "yq", "yr", "y_uvw", "nargin",
  "nargout", "u", "y" };

static const char * c5_b_debug_family_names[73] = { "airDensity1", "airSpeed1",
  "wingSpan1", "tankerWeight1", "gravity1", "vortexStrength", "wingTipLeftPos",
  "wingTipRightPos", "tailTipLeftPos", "tailTipRightPos", "tankerMassPos",
  "receiverPos", "rVorL", "tVorL", "TVorL", "vVorL", "rVorCoreL", "WVorL",
  "thetaVorL", "WVorLVector", "rVorR", "tVorR", "TVorR", "vVorR", "rVorCoreR",
  "WVorR", "thetaVorR", "WVorRVector", "rVorW", "tVorW", "LVorLength",
  "RVorLength", "gamaLCos", "gamaRCos", "TVorW", "vVorW", "rVorCoreW", "WVorW",
  "thetaVorW", "WVorWVector", "rVorLT", "tVorLT", "TVorLT", "vVorLT",
  "rVorCoreLT", "WVorLT", "thetaVorLT", "WVorLTVector", "rVorRT", "tVorRT",
  "TVorRT", "vVorRT", "rVorCoreRT", "WVorRT", "thetaVorRT", "WVorRTVector",
  "rVorT", "tVorT", "LVorLengthT", "RVorLengthT", "gamaLCosT", "gamaRCosT",
  "TVorT", "vVorT", "rVorCoreT", "WVorT", "thetaVorT", "WVorTVector",
  "WTotalVector", "nargin", "nargout", "PosReceiver", "y" };

/* Function Declarations */
static void initialize_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);
static void initialize_params_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static void enable_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);
static void disable_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static void set_sim_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);
static void sf_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);
static void initSimStructsc5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static void registerMessagesc5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static void c5_TankerVortexWindField(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, real_T c5_PosReceiver[3], real_T c5_y[3]);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier, real_T
  c5_b_y[6]);
static void c5_b_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_d_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[28]);
static real_T c5_mpower(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
  real_T c5_a);
static void c5_eml_scalar_eg(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static real_T c5_sqrt(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
                      real_T c5_x);
static void c5_eml_error(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance);
static real_T c5_abs(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance, real_T
                     c5_x);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_F16_Real5_Another, const
  char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sqrt(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
                      real_T *c5_x);
static void init_dsm_address_info(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_F16_Real5_Another = 0U;
}

static void initialize_params_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
}

static void enable_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[6];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_d_y)[6];
  c5_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 6; c5_i0++) {
    c5_u[c5_i0] = (*c5_d_y)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_F16_Real5_Another;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[6];
  int32_T c5_i1;
  real_T (*c5_y)[6];
  c5_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "y",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 6; c5_i1++) {
    (*c5_y)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_F16_Real5_Another = c5_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_F16_Real5_Another");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_F16_Real5_Another(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance)
{
}

static void sf_c5_F16_Real5_Another(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  real_T c5_u[3];
  uint32_T c5_debug_family_var_map[18];
  real_T c5_c_lat;
  real_T c5_c_lon;
  real_T c5_u1[3];
  real_T c5_u2[3];
  real_T c5_yy1[3];
  real_T c5_yy2[3];
  real_T c5_yp;
  real_T c5_u3[3];
  real_T c5_u4[3];
  real_T c5_yy3[3];
  real_T c5_yy4[3];
  real_T c5_yq;
  real_T c5_yr;
  real_T c5_y_uvw[3];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  real_T c5_y[6];
  real_T c5_dv1[3];
  int32_T c5_i5;
  real_T c5_dv2[3];
  int32_T c5_i6;
  int32_T c5_i7;
  real_T c5_b_u1[3];
  real_T c5_dv3[3];
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_b_u2[3];
  real_T c5_dv4[3];
  int32_T c5_i10;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_b_A;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_b_c_lon[3];
  int32_T c5_i11;
  real_T c5_c_c_lon[3];
  int32_T c5_i12;
  int32_T c5_i13;
  real_T c5_b_u3[3];
  real_T c5_dv5[3];
  int32_T c5_i14;
  int32_T c5_i15;
  real_T c5_b_u4[3];
  real_T c5_dv6[3];
  int32_T c5_i16;
  real_T c5_c_A;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_c_y;
  real_T c5_d_A;
  real_T c5_g_x;
  real_T c5_h_x;
  int32_T c5_i17;
  real_T c5_b_u[3];
  real_T c5_dv7[3];
  int32_T c5_i18;
  int32_T c5_i19;
  real_T (*c5_d_y)[6];
  real_T (*c5_c_u)[3];
  c5_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_c_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_u)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 6; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_d_y)[c5_i3], 1U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  for (c5_i4 = 0; c5_i4 < 3; c5_i4++) {
    c5_u[c5_i4] = (*c5_c_u)[c5_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_c_lat, 0U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_c_lon, 1U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_u1, 2U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_u2, 3U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_yy1, 4U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_yy2, 5U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_yp, 6U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_u3, 7U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_u4, 8U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_yy3, 9U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_yy4, 10U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_yq, 11U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_yr, 12U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_y_uvw, 13U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 14U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 15U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_u, 16U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_y, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_c_lat = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_c_lon = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_dv1[0] = 0.0;
  c5_dv1[1] = c5_c_lat;
  c5_dv1[2] = 0.0;
  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    c5_u1[c5_i5] = c5_u[c5_i5] + c5_dv1[c5_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_dv2[0] = 0.0;
  c5_dv2[1] = -c5_c_lat;
  c5_dv2[2] = 0.0;
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_u2[c5_i6] = c5_u[c5_i6] + c5_dv2[c5_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  for (c5_i7 = 0; c5_i7 < 3; c5_i7++) {
    c5_b_u1[c5_i7] = c5_u1[c5_i7];
  }

  c5_TankerVortexWindField(chartInstance, c5_b_u1, c5_dv3);
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    c5_yy1[c5_i8] = c5_dv3[c5_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
    c5_b_u2[c5_i9] = c5_u2[c5_i9];
  }

  c5_TankerVortexWindField(chartInstance, c5_b_u2, c5_dv4);
  for (c5_i10 = 0; c5_i10 < 3; c5_i10++) {
    c5_yy2[c5_i10] = c5_dv4[c5_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_A = c5_yy1[2] - c5_yy2[2];
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_b_y = c5_b_x / 4.0;
  c5_b_A = c5_b_y;
  c5_c_x = c5_b_A;
  c5_d_x = c5_c_x;
  c5_yp = c5_d_x / 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_b_c_lon[0] = c5_c_lon;
  c5_b_c_lon[1] = 0.0;
  c5_b_c_lon[2] = 0.0;
  for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
    c5_u3[c5_i11] = c5_u[c5_i11] + c5_b_c_lon[c5_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_c_c_lon[0] = -c5_c_lon;
  c5_c_c_lon[1] = 0.0;
  c5_c_c_lon[2] = 0.0;
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_u4[c5_i12] = c5_u[c5_i12] + c5_c_c_lon[c5_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  for (c5_i13 = 0; c5_i13 < 3; c5_i13++) {
    c5_b_u3[c5_i13] = c5_u3[c5_i13];
  }

  c5_TankerVortexWindField(chartInstance, c5_b_u3, c5_dv5);
  for (c5_i14 = 0; c5_i14 < 3; c5_i14++) {
    c5_yy3[c5_i14] = c5_dv5[c5_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    c5_b_u4[c5_i15] = c5_u4[c5_i15];
  }

  c5_TankerVortexWindField(chartInstance, c5_b_u4, c5_dv6);
  for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
    c5_yy4[c5_i16] = c5_dv6[c5_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_c_A = -(c5_yy3[2] - c5_yy4[2]);
  c5_e_x = c5_c_A;
  c5_f_x = c5_e_x;
  c5_c_y = c5_f_x / 4.0;
  c5_d_A = c5_c_y;
  c5_g_x = c5_d_A;
  c5_h_x = c5_g_x;
  c5_yq = c5_h_x / 4.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_yr = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
  for (c5_i17 = 0; c5_i17 < 3; c5_i17++) {
    c5_b_u[c5_i17] = c5_u[c5_i17];
  }

  c5_TankerVortexWindField(chartInstance, c5_b_u, c5_dv7);
  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_y_uvw[c5_i18] = c5_dv7[c5_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
  c5_y[0] = c5_y_uvw[0];
  c5_y[1] = c5_y_uvw[1];
  c5_y[2] = c5_y_uvw[2];
  c5_y[3] = -c5_yp;
  c5_y[4] = -c5_yq;
  c5_y[5] = -c5_yr;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i19 = 0; c5_i19 < 6; c5_i19++) {
    (*c5_d_y)[c5_i19] = c5_y[c5_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_F16_Real5_AnotherMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
}

static void registerMessagesc5_F16_Real5_Another
  (SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
}

static void c5_TankerVortexWindField(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, real_T c5_PosReceiver[3], real_T c5_y[3])
{
  uint32_T c5_debug_family_var_map[73];
  real_T c5_airDensity1;
  real_T c5_airSpeed1;
  real_T c5_wingSpan1;
  real_T c5_tankerWeight1;
  real_T c5_gravity1;
  real_T c5_vortexStrength;
  real_T c5_wingTipLeftPos[3];
  real_T c5_wingTipRightPos[3];
  real_T c5_tailTipLeftPos[3];
  real_T c5_tailTipRightPos[3];
  real_T c5_tankerMassPos[3];
  real_T c5_receiverPos[3];
  real_T c5_rVorL;
  real_T c5_tVorL;
  real_T c5_TVorL;
  real_T c5_vVorL;
  real_T c5_rVorCoreL;
  real_T c5_WVorL;
  real_T c5_thetaVorL;
  real_T c5_WVorLVector[3];
  real_T c5_rVorR;
  real_T c5_tVorR;
  real_T c5_TVorR;
  real_T c5_vVorR;
  real_T c5_rVorCoreR;
  real_T c5_WVorR;
  real_T c5_thetaVorR;
  real_T c5_WVorRVector[3];
  real_T c5_rVorW;
  real_T c5_tVorW;
  real_T c5_LVorLength;
  real_T c5_RVorLength;
  real_T c5_gamaLCos;
  real_T c5_gamaRCos;
  real_T c5_TVorW;
  real_T c5_vVorW;
  real_T c5_rVorCoreW;
  real_T c5_WVorW;
  real_T c5_thetaVorW;
  real_T c5_WVorWVector[3];
  real_T c5_rVorLT;
  real_T c5_tVorLT;
  real_T c5_TVorLT;
  real_T c5_vVorLT;
  real_T c5_rVorCoreLT;
  real_T c5_WVorLT;
  real_T c5_thetaVorLT;
  real_T c5_WVorLTVector[3];
  real_T c5_rVorRT;
  real_T c5_tVorRT;
  real_T c5_TVorRT;
  real_T c5_vVorRT;
  real_T c5_rVorCoreRT;
  real_T c5_WVorRT;
  real_T c5_thetaVorRT;
  real_T c5_WVorRTVector[3];
  real_T c5_rVorT;
  real_T c5_tVorT;
  real_T c5_LVorLengthT;
  real_T c5_RVorLengthT;
  real_T c5_gamaLCosT;
  real_T c5_gamaRCosT;
  real_T c5_TVorT;
  real_T c5_vVorT;
  real_T c5_rVorCoreT;
  real_T c5_WVorT;
  real_T c5_thetaVorT;
  real_T c5_WVorTVector[3];
  real_T c5_WTotalVector[3];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i20;
  static real_T c5_dv8[3] = { 0.0, -20.0, 0.0 };

  int32_T c5_i21;
  static real_T c5_dv9[3] = { 0.0, 20.0, 0.0 };

  int32_T c5_i22;
  static real_T c5_dv10[3] = { -12.44, -6.515, -1.27 };

  int32_T c5_i23;
  static real_T c5_dv11[3] = { -12.44, 6.515, -1.27 };

  int32_T c5_i24;
  int32_T c5_i25;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b;
  real_T c5_b_y;
  real_T c5_b_b;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_d_b;
  real_T c5_d_y;
  real_T c5_b_A;
  real_T c5_B;
  real_T c5_c_x;
  real_T c5_e_y;
  real_T c5_d_x;
  real_T c5_f_y;
  real_T c5_g_y;
  real_T c5_e_b;
  real_T c5_h_y;
  real_T c5_c_A;
  real_T c5_b_B;
  real_T c5_e_x;
  real_T c5_i_y;
  real_T c5_f_x;
  real_T c5_j_y;
  real_T c5_k_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_a;
  real_T c5_f_b;
  real_T c5_d_A;
  real_T c5_c_B;
  real_T c5_i_x;
  real_T c5_l_y;
  real_T c5_j_x;
  real_T c5_m_y;
  real_T c5_n_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_b_a;
  real_T c5_g_b;
  real_T c5_o_y;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_c_a;
  real_T c5_h_b;
  real_T c5_p_y;
  real_T c5_dv12[3];
  int32_T c5_i26;
  real_T c5_e_A;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_i_b;
  real_T c5_q_y;
  real_T c5_j_b;
  real_T c5_k_b;
  real_T c5_r_y;
  real_T c5_l_b;
  real_T c5_s_y;
  real_T c5_f_A;
  real_T c5_d_B;
  real_T c5_s_x;
  real_T c5_t_y;
  real_T c5_t_x;
  real_T c5_u_y;
  real_T c5_v_y;
  real_T c5_m_b;
  real_T c5_w_y;
  real_T c5_g_A;
  real_T c5_e_B;
  real_T c5_u_x;
  real_T c5_x_y;
  real_T c5_v_x;
  real_T c5_y_y;
  real_T c5_ab_y;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_d_a;
  real_T c5_n_b;
  real_T c5_h_A;
  real_T c5_f_B;
  real_T c5_y_x;
  real_T c5_bb_y;
  real_T c5_ab_x;
  real_T c5_cb_y;
  real_T c5_db_y;
  real_T c5_bb_x;
  real_T c5_cb_x;
  real_T c5_db_x;
  real_T c5_eb_x;
  real_T c5_e_a;
  real_T c5_o_b;
  real_T c5_eb_y;
  real_T c5_fb_x;
  real_T c5_gb_x;
  real_T c5_f_a;
  real_T c5_p_b;
  real_T c5_fb_y;
  real_T c5_dv13[3];
  int32_T c5_i27;
  real_T c5_i_A;
  real_T c5_hb_x;
  real_T c5_ib_x;
  real_T c5_j_A;
  real_T c5_g_B;
  real_T c5_jb_x;
  real_T c5_gb_y;
  real_T c5_kb_x;
  real_T c5_hb_y;
  real_T c5_k_A;
  real_T c5_h_B;
  real_T c5_lb_x;
  real_T c5_ib_y;
  real_T c5_mb_x;
  real_T c5_jb_y;
  real_T c5_q_b;
  real_T c5_kb_y;
  real_T c5_l_A;
  real_T c5_nb_x;
  real_T c5_ob_x;
  real_T c5_lb_y;
  real_T c5_g_a;
  real_T c5_mb_y;
  real_T c5_m_A;
  real_T c5_pb_x;
  real_T c5_qb_x;
  real_T c5_r_b;
  real_T c5_h_a;
  real_T c5_s_b;
  real_T c5_nb_y;
  real_T c5_t_b;
  real_T c5_i_a;
  real_T c5_u_b;
  real_T c5_ob_y;
  real_T c5_v_b;
  real_T c5_pb_y;
  real_T c5_n_A;
  real_T c5_i_B;
  real_T c5_rb_x;
  real_T c5_qb_y;
  real_T c5_sb_x;
  real_T c5_rb_y;
  real_T c5_sb_y;
  real_T c5_w_b;
  real_T c5_tb_y;
  real_T c5_j_a;
  real_T c5_x_b;
  real_T c5_ub_y;
  real_T c5_o_A;
  real_T c5_j_B;
  real_T c5_tb_x;
  real_T c5_vb_y;
  real_T c5_ub_x;
  real_T c5_wb_y;
  real_T c5_xb_y;
  real_T c5_vb_x;
  real_T c5_wb_x;
  real_T c5_k_a;
  real_T c5_y_b;
  real_T c5_p_A;
  real_T c5_k_B;
  real_T c5_xb_x;
  real_T c5_yb_y;
  real_T c5_yb_x;
  real_T c5_ac_y;
  real_T c5_bc_y;
  real_T c5_ac_x;
  real_T c5_bc_x;
  real_T c5_cc_x;
  real_T c5_dc_x;
  real_T c5_l_a;
  real_T c5_ab_b;
  real_T c5_cc_y;
  real_T c5_ec_x;
  real_T c5_fc_x;
  real_T c5_m_a;
  real_T c5_bb_b;
  real_T c5_dc_y;
  real_T c5_ec_y[3];
  int32_T c5_i28;
  real_T c5_q_A;
  real_T c5_gc_x;
  real_T c5_hc_x;
  real_T c5_cb_b;
  real_T c5_fc_y;
  real_T c5_db_b;
  real_T c5_eb_b;
  real_T c5_gc_y;
  real_T c5_fb_b;
  real_T c5_hc_y;
  real_T c5_r_A;
  real_T c5_l_B;
  real_T c5_ic_x;
  real_T c5_ic_y;
  real_T c5_jc_x;
  real_T c5_jc_y;
  real_T c5_kc_y;
  real_T c5_gb_b;
  real_T c5_lc_y;
  real_T c5_s_A;
  real_T c5_m_B;
  real_T c5_kc_x;
  real_T c5_mc_y;
  real_T c5_lc_x;
  real_T c5_nc_y;
  real_T c5_oc_y;
  real_T c5_mc_x;
  real_T c5_nc_x;
  real_T c5_n_a;
  real_T c5_hb_b;
  real_T c5_t_A;
  real_T c5_n_B;
  real_T c5_oc_x;
  real_T c5_pc_y;
  real_T c5_pc_x;
  real_T c5_qc_y;
  real_T c5_rc_y;
  real_T c5_qc_x;
  real_T c5_rc_x;
  real_T c5_sc_x;
  real_T c5_tc_x;
  real_T c5_o_a;
  real_T c5_ib_b;
  real_T c5_sc_y;
  real_T c5_uc_x;
  real_T c5_vc_x;
  real_T c5_p_a;
  real_T c5_jb_b;
  real_T c5_tc_y;
  real_T c5_dv14[3];
  int32_T c5_i29;
  real_T c5_u_A;
  real_T c5_wc_x;
  real_T c5_xc_x;
  real_T c5_kb_b;
  real_T c5_uc_y;
  real_T c5_lb_b;
  real_T c5_mb_b;
  real_T c5_vc_y;
  real_T c5_nb_b;
  real_T c5_wc_y;
  real_T c5_v_A;
  real_T c5_o_B;
  real_T c5_yc_x;
  real_T c5_xc_y;
  real_T c5_ad_x;
  real_T c5_yc_y;
  real_T c5_ad_y;
  real_T c5_ob_b;
  real_T c5_bd_y;
  real_T c5_w_A;
  real_T c5_p_B;
  real_T c5_bd_x;
  real_T c5_cd_y;
  real_T c5_cd_x;
  real_T c5_dd_y;
  real_T c5_ed_y;
  real_T c5_dd_x;
  real_T c5_ed_x;
  real_T c5_q_a;
  real_T c5_pb_b;
  real_T c5_x_A;
  real_T c5_q_B;
  real_T c5_fd_x;
  real_T c5_fd_y;
  real_T c5_gd_x;
  real_T c5_gd_y;
  real_T c5_hd_y;
  real_T c5_hd_x;
  real_T c5_id_x;
  real_T c5_jd_x;
  real_T c5_kd_x;
  real_T c5_r_a;
  real_T c5_qb_b;
  real_T c5_id_y;
  real_T c5_ld_x;
  real_T c5_md_x;
  real_T c5_s_a;
  real_T c5_rb_b;
  real_T c5_jd_y;
  real_T c5_dv15[3];
  int32_T c5_i30;
  real_T c5_y_A;
  real_T c5_nd_x;
  real_T c5_od_x;
  real_T c5_ab_A;
  real_T c5_r_B;
  real_T c5_pd_x;
  real_T c5_kd_y;
  real_T c5_qd_x;
  real_T c5_ld_y;
  real_T c5_bb_A;
  real_T c5_s_B;
  real_T c5_rd_x;
  real_T c5_md_y;
  real_T c5_sd_x;
  real_T c5_nd_y;
  real_T c5_sb_b;
  real_T c5_od_y;
  real_T c5_cb_A;
  real_T c5_td_x;
  real_T c5_ud_x;
  real_T c5_pd_y;
  real_T c5_t_a;
  real_T c5_qd_y;
  real_T c5_db_A;
  real_T c5_vd_x;
  real_T c5_wd_x;
  real_T c5_tb_b;
  real_T c5_u_a;
  real_T c5_ub_b;
  real_T c5_rd_y;
  real_T c5_vb_b;
  real_T c5_v_a;
  real_T c5_wb_b;
  real_T c5_sd_y;
  real_T c5_xb_b;
  real_T c5_td_y;
  real_T c5_eb_A;
  real_T c5_t_B;
  real_T c5_xd_x;
  real_T c5_ud_y;
  real_T c5_yd_x;
  real_T c5_vd_y;
  real_T c5_wd_y;
  real_T c5_yb_b;
  real_T c5_xd_y;
  real_T c5_w_a;
  real_T c5_ac_b;
  real_T c5_yd_y;
  real_T c5_fb_A;
  real_T c5_u_B;
  real_T c5_ae_x;
  real_T c5_ae_y;
  real_T c5_be_x;
  real_T c5_be_y;
  real_T c5_ce_y;
  real_T c5_ce_x;
  real_T c5_de_x;
  real_T c5_x_a;
  real_T c5_bc_b;
  real_T c5_gb_A;
  real_T c5_v_B;
  real_T c5_ee_x;
  real_T c5_de_y;
  real_T c5_fe_x;
  real_T c5_ee_y;
  real_T c5_fe_y;
  real_T c5_ge_x;
  real_T c5_he_x;
  real_T c5_ie_x;
  real_T c5_je_x;
  real_T c5_y_a;
  real_T c5_cc_b;
  real_T c5_ge_y;
  real_T c5_ke_x;
  real_T c5_le_x;
  real_T c5_ab_a;
  real_T c5_dc_b;
  real_T c5_he_y;
  real_T c5_ie_y[3];
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 73U, 73U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_airDensity1, 0U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_airSpeed1, 1U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_wingSpan1, 2U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_tankerWeight1, 3U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_gravity1, 4U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_vortexStrength, 5U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_wingTipLeftPos, 6U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_wingTipRightPos, 7U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_tailTipLeftPos, 8U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_tailTipRightPos, 9U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_tankerMassPos, 10U,
    c5_b_sf_marshallOut, c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_receiverPos, 11U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorL, 12U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorL, 13U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_TVorL, 14U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_vVorL, 15U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreL, 16U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorL, 17U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorL, 18U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorLVector, 19U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorR, 20U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorR, 21U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_TVorR, 22U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_vVorR, 23U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreR, 24U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorR, 25U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorR, 26U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorRVector, 27U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorW, 28U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorW, 29U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_LVorLength, 30U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_RVorLength, 31U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_gamaLCos, 32U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_gamaRCos, 33U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_TVorW, 34U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_vVorW, 35U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreW, 36U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorW, 37U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorW, 38U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorWVector, 39U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorLT, 40U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorLT, 41U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_TVorLT, 42U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_vVorLT, 43U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreLT, 44U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorLT, 45U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorLT, 46U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorLTVector, 47U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorRT, 48U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorRT, 49U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_TVorRT, 50U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_vVorRT, 51U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreRT, 52U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorRT, 53U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorRT, 54U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorRTVector, 55U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorT, 56U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_tVorT, 57U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_LVorLengthT, 58U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_RVorLengthT, 59U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_gamaLCosT, 60U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_gamaRCosT, 61U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_TVorT, 62U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_vVorT, 63U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_rVorCoreT, 64U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_WVorT, 65U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_thetaVorT, 66U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WVorTVector, 67U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_WTotalVector, 68U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 69U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 70U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_PosReceiver, 71U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_y, 72U, c5_b_sf_marshallOut,
    c5_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_airDensity1 = 0.5895;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_airSpeed1 = 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_wingSpan1 = 40.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_tankerWeight1 = 80000.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_gravity1 = 9.79434;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_vortexStrength = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 19);
  for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
    c5_wingTipLeftPos[c5_i20] = c5_dv8[c5_i20];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 20);
  for (c5_i21 = 0; c5_i21 < 3; c5_i21++) {
    c5_wingTipRightPos[c5_i21] = c5_dv9[c5_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 23);
  for (c5_i22 = 0; c5_i22 < 3; c5_i22++) {
    c5_tailTipLeftPos[c5_i22] = c5_dv10[c5_i22];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 24);
  for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
    c5_tailTipRightPos[c5_i23] = c5_dv11[c5_i23];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 27);
  for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
    c5_tankerMassPos[c5_i24] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 30);
  for (c5_i25 = 0; c5_i25 < 3; c5_i25++) {
    c5_receiverPos[c5_i25] = c5_PosReceiver[c5_i25] + c5_tankerMassPos[c5_i25];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 33);
  c5_rVorL = c5_mpower(chartInstance, c5_receiverPos[1] - c5_wingTipLeftPos[1])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_wingTipLeftPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorL);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 34);
  c5_A = -c5_receiverPos[0];
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_tVorL = c5_b_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 35);
  c5_TVorL = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 36);
  c5_vVorL = 13.360697471628653;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 37);
  c5_b = c5_tVorL;
  c5_b_y = 13.360697471628653 * c5_b;
  c5_b_b = c5_abs(chartInstance, c5_b_y);
  c5_b_sqrt(chartInstance, &c5_b_b);
  c5_rVorCoreL = 2.24 * c5_b_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 40);
  c5_c_b = c5_rVorL;
  c5_c_y = 222.67829119381088 * c5_c_b;
  c5_d_b = c5_mpower(chartInstance, c5_rVorL) + c5_mpower(chartInstance,
    c5_rVorCoreL);
  c5_d_y = 6.2831853071795862 * c5_d_b;
  c5_b_A = c5_c_y;
  c5_B = c5_d_y;
  c5_c_x = c5_b_A;
  c5_e_y = c5_B;
  c5_d_x = c5_c_x;
  c5_f_y = c5_e_y;
  c5_g_y = c5_d_x / c5_f_y;
  c5_e_b = c5_tVorL;
  c5_h_y = 53.44278988651461 * c5_e_b;
  c5_c_A = -c5_mpower(chartInstance, c5_rVorL);
  c5_b_B = c5_h_y;
  c5_e_x = c5_c_A;
  c5_i_y = c5_b_B;
  c5_f_x = c5_e_x;
  c5_j_y = c5_i_y;
  c5_k_y = c5_f_x / c5_j_y;
  c5_g_x = c5_k_y;
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarExp(c5_h_x);
  c5_a = c5_g_y;
  c5_f_b = 1.0 - c5_h_x;
  c5_WVorL = c5_a * c5_f_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 41);
  c5_d_A = c5_receiverPos[2] - c5_wingTipLeftPos[2];
  c5_c_B = c5_receiverPos[1] - c5_wingTipLeftPos[1];
  c5_i_x = c5_d_A;
  c5_l_y = c5_c_B;
  c5_j_x = c5_i_x;
  c5_m_y = c5_l_y;
  c5_n_y = c5_j_x / c5_m_y;
  c5_k_x = c5_n_y;
  c5_thetaVorL = c5_k_x;
  c5_l_x = c5_thetaVorL;
  c5_thetaVorL = c5_l_x;
  c5_thetaVorL = muDoubleScalarAtan(c5_thetaVorL);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 42);
  if (CV_SCRIPT_IF(0, 0, c5_thetaVorL < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 43);
    c5_thetaVorL += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 46);
  c5_m_x = c5_thetaVorL;
  c5_n_x = c5_m_x;
  c5_n_x = muDoubleScalarSin(c5_n_x);
  c5_b_a = -c5_WVorL;
  c5_g_b = c5_n_x;
  c5_o_y = c5_b_a * c5_g_b;
  c5_o_x = c5_thetaVorL;
  c5_p_x = c5_o_x;
  c5_p_x = muDoubleScalarCos(c5_p_x);
  c5_c_a = c5_WVorL;
  c5_h_b = c5_p_x;
  c5_p_y = c5_c_a * c5_h_b;
  c5_dv12[0] = 0.0;
  c5_dv12[1] = c5_o_y;
  c5_dv12[2] = c5_p_y;
  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_WVorLVector[c5_i26] = c5_dv12[c5_i26];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 50);
  c5_rVorR = c5_mpower(chartInstance, c5_receiverPos[1] - c5_wingTipRightPos[1])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_wingTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorR);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 51);
  c5_e_A = -c5_receiverPos[0];
  c5_q_x = c5_e_A;
  c5_r_x = c5_q_x;
  c5_tVorR = c5_r_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 52);
  c5_TVorR = 222.67829119381088;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 53);
  c5_vVorR = 13.360697471628653;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 54);
  c5_i_b = c5_tVorR;
  c5_q_y = 13.360697471628653 * c5_i_b;
  c5_j_b = c5_abs(chartInstance, c5_q_y);
  c5_b_sqrt(chartInstance, &c5_j_b);
  c5_rVorCoreR = 2.24 * c5_j_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 56);
  c5_k_b = c5_rVorR;
  c5_r_y = 222.67829119381088 * c5_k_b;
  c5_l_b = c5_mpower(chartInstance, c5_rVorR) + c5_mpower(chartInstance,
    c5_rVorCoreR);
  c5_s_y = 6.2831853071795862 * c5_l_b;
  c5_f_A = c5_r_y;
  c5_d_B = c5_s_y;
  c5_s_x = c5_f_A;
  c5_t_y = c5_d_B;
  c5_t_x = c5_s_x;
  c5_u_y = c5_t_y;
  c5_v_y = c5_t_x / c5_u_y;
  c5_m_b = c5_tVorR;
  c5_w_y = 53.44278988651461 * c5_m_b;
  c5_g_A = -c5_mpower(chartInstance, c5_rVorR);
  c5_e_B = c5_w_y;
  c5_u_x = c5_g_A;
  c5_x_y = c5_e_B;
  c5_v_x = c5_u_x;
  c5_y_y = c5_x_y;
  c5_ab_y = c5_v_x / c5_y_y;
  c5_w_x = c5_ab_y;
  c5_x_x = c5_w_x;
  c5_x_x = muDoubleScalarExp(c5_x_x);
  c5_d_a = c5_v_y;
  c5_n_b = 1.0 - c5_x_x;
  c5_WVorR = c5_d_a * c5_n_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 57);
  c5_h_A = c5_receiverPos[2] - c5_wingTipRightPos[2];
  c5_f_B = -c5_receiverPos[1] + c5_wingTipRightPos[1];
  c5_y_x = c5_h_A;
  c5_bb_y = c5_f_B;
  c5_ab_x = c5_y_x;
  c5_cb_y = c5_bb_y;
  c5_db_y = c5_ab_x / c5_cb_y;
  c5_bb_x = c5_db_y;
  c5_thetaVorR = c5_bb_x;
  c5_cb_x = c5_thetaVorR;
  c5_thetaVorR = c5_cb_x;
  c5_thetaVorR = muDoubleScalarAtan(c5_thetaVorR);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 58);
  if (CV_SCRIPT_IF(0, 1, -c5_receiverPos[1] + c5_wingTipRightPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 59);
    c5_thetaVorR += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 62);
  c5_db_x = c5_thetaVorR;
  c5_eb_x = c5_db_x;
  c5_eb_x = muDoubleScalarSin(c5_eb_x);
  c5_e_a = c5_WVorR;
  c5_o_b = c5_eb_x;
  c5_eb_y = c5_e_a * c5_o_b;
  c5_fb_x = c5_thetaVorR;
  c5_gb_x = c5_fb_x;
  c5_gb_x = muDoubleScalarCos(c5_gb_x);
  c5_f_a = c5_WVorR;
  c5_p_b = c5_gb_x;
  c5_fb_y = c5_f_a * c5_p_b;
  c5_dv13[0] = 0.0;
  c5_dv13[1] = c5_eb_y;
  c5_dv13[2] = c5_fb_y;
  for (c5_i27 = 0; c5_i27 < 3; c5_i27++) {
    c5_WVorRVector[c5_i27] = c5_dv13[c5_i27];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 66);
  c5_rVorW = c5_mpower(chartInstance, c5_receiverPos[0] - c5_wingTipRightPos[0])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_wingTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorW);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 67);
  c5_i_A = -c5_receiverPos[0];
  c5_hb_x = c5_i_A;
  c5_ib_x = c5_hb_x;
  c5_tVorW = c5_ib_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 69);
  c5_LVorLength = (c5_mpower(chartInstance, c5_receiverPos[0] -
    c5_wingTipLeftPos[0]) + c5_mpower(chartInstance, c5_receiverPos[1] -
    -15.707963267948966)) + c5_mpower(chartInstance, c5_receiverPos[2] -
    c5_wingTipLeftPos[2]);
  c5_b_sqrt(chartInstance, &c5_LVorLength);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 70);
  c5_RVorLength = (c5_mpower(chartInstance, c5_receiverPos[0] -
    c5_wingTipRightPos[0]) + c5_mpower(chartInstance, c5_receiverPos[1] -
    15.707963267948966)) + c5_mpower(chartInstance, c5_receiverPos[2] -
    c5_wingTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_RVorLength);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 72);
  c5_j_A = c5_receiverPos[1] - -15.707963267948966;
  c5_g_B = c5_LVorLength;
  c5_jb_x = c5_j_A;
  c5_gb_y = c5_g_B;
  c5_kb_x = c5_jb_x;
  c5_hb_y = c5_gb_y;
  c5_gamaLCos = c5_kb_x / c5_hb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 73);
  c5_k_A = -c5_receiverPos[1] + 15.707963267948966;
  c5_h_B = c5_RVorLength;
  c5_lb_x = c5_k_A;
  c5_ib_y = c5_h_B;
  c5_mb_x = c5_lb_x;
  c5_jb_y = c5_ib_y;
  c5_gamaRCos = c5_mb_x / c5_jb_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 75);
  c5_q_b = c5_gamaLCos + c5_gamaRCos;
  c5_kb_y = 222.67829119381088 * c5_q_b;
  c5_l_A = c5_kb_y;
  c5_nb_x = c5_l_A;
  c5_ob_x = c5_nb_x;
  c5_lb_y = c5_ob_x / 2.0;
  c5_g_a = c5_lb_y;
  c5_mb_y = c5_g_a * 4.0;
  c5_m_A = c5_mb_y;
  c5_pb_x = c5_m_A;
  c5_qb_x = c5_pb_x;
  c5_TVorW = c5_qb_x / 3.1415926535897931;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 76);
  c5_r_b = c5_TVorW;
  c5_vVorW = 0.06 * c5_r_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 77);
  c5_h_a = c5_vVorW;
  c5_s_b = c5_tVorW;
  c5_nb_y = c5_h_a * c5_s_b;
  c5_t_b = c5_abs(chartInstance, c5_nb_y);
  c5_b_sqrt(chartInstance, &c5_t_b);
  c5_rVorCoreW = 2.24 * c5_t_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_i_a = c5_TVorW;
  c5_u_b = c5_rVorW;
  c5_ob_y = c5_i_a * c5_u_b;
  c5_v_b = c5_mpower(chartInstance, c5_rVorW) + c5_mpower(chartInstance,
    c5_rVorCoreW);
  c5_pb_y = 6.2831853071795862 * c5_v_b;
  c5_n_A = c5_ob_y;
  c5_i_B = c5_pb_y;
  c5_rb_x = c5_n_A;
  c5_qb_y = c5_i_B;
  c5_sb_x = c5_rb_x;
  c5_rb_y = c5_qb_y;
  c5_sb_y = c5_sb_x / c5_rb_y;
  c5_w_b = c5_vVorW;
  c5_tb_y = 4.0 * c5_w_b;
  c5_j_a = c5_tb_y;
  c5_x_b = c5_tVorW;
  c5_ub_y = c5_j_a * c5_x_b;
  c5_o_A = -c5_mpower(chartInstance, c5_rVorW);
  c5_j_B = c5_ub_y;
  c5_tb_x = c5_o_A;
  c5_vb_y = c5_j_B;
  c5_ub_x = c5_tb_x;
  c5_wb_y = c5_vb_y;
  c5_xb_y = c5_ub_x / c5_wb_y;
  c5_vb_x = c5_xb_y;
  c5_wb_x = c5_vb_x;
  c5_wb_x = muDoubleScalarExp(c5_wb_x);
  c5_k_a = c5_sb_y;
  c5_y_b = 1.0 - c5_wb_x;
  c5_WVorW = c5_k_a * c5_y_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_p_A = c5_receiverPos[2] - c5_wingTipRightPos[2];
  c5_k_B = -c5_receiverPos[0] + c5_wingTipRightPos[0];
  c5_xb_x = c5_p_A;
  c5_yb_y = c5_k_B;
  c5_yb_x = c5_xb_x;
  c5_ac_y = c5_yb_y;
  c5_bc_y = c5_yb_x / c5_ac_y;
  c5_ac_x = c5_bc_y;
  c5_thetaVorW = c5_ac_x;
  c5_bc_x = c5_thetaVorW;
  c5_thetaVorW = c5_bc_x;
  c5_thetaVorW = muDoubleScalarAtan(c5_thetaVorW);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 81);
  if (CV_SCRIPT_IF(0, 2, -c5_receiverPos[0] + c5_wingTipRightPos[0] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 82);
    c5_thetaVorW += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_cc_x = c5_thetaVorW;
  c5_dc_x = c5_cc_x;
  c5_dc_x = muDoubleScalarSin(c5_dc_x);
  c5_l_a = c5_WVorW;
  c5_ab_b = c5_dc_x;
  c5_cc_y = c5_l_a * c5_ab_b;
  c5_ec_x = c5_thetaVorW;
  c5_fc_x = c5_ec_x;
  c5_fc_x = muDoubleScalarCos(c5_fc_x);
  c5_m_a = c5_WVorW;
  c5_bb_b = c5_fc_x;
  c5_dc_y = c5_m_a * c5_bb_b;
  c5_ec_y[0] = c5_cc_y;
  c5_ec_y[1] = 0.0;
  c5_ec_y[2] = c5_dc_y;
  for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
    c5_WVorWVector[c5_i28] = c5_ec_y[c5_i28];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_rVorLT = c5_mpower(chartInstance, c5_receiverPos[1] - c5_wingTipLeftPos[1])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_wingTipLeftPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorLT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_q_A = -(c5_receiverPos[0] - c5_wingTipLeftPos[0]);
  c5_gc_x = c5_q_A;
  c5_hc_x = c5_gc_x;
  c5_tVorLT = c5_hc_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_TVorLT = 7.4226097064603627;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_vVorLT = 0.44535658238762177;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 93);
  c5_cb_b = c5_tVorLT;
  c5_fc_y = 0.44535658238762177 * c5_cb_b;
  c5_db_b = c5_abs(chartInstance, c5_fc_y);
  c5_b_sqrt(chartInstance, &c5_db_b);
  c5_rVorCoreLT = 2.24 * c5_db_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_eb_b = c5_rVorLT;
  c5_gc_y = 7.4226097064603627 * c5_eb_b;
  c5_fb_b = c5_mpower(chartInstance, c5_rVorLT) + c5_mpower(chartInstance,
    c5_rVorCoreLT);
  c5_hc_y = 6.2831853071795862 * c5_fb_b;
  c5_r_A = c5_gc_y;
  c5_l_B = c5_hc_y;
  c5_ic_x = c5_r_A;
  c5_ic_y = c5_l_B;
  c5_jc_x = c5_ic_x;
  c5_jc_y = c5_ic_y;
  c5_kc_y = c5_jc_x / c5_jc_y;
  c5_gb_b = c5_tVorLT;
  c5_lc_y = 1.7814263295504871 * c5_gb_b;
  c5_s_A = -c5_mpower(chartInstance, c5_rVorLT);
  c5_m_B = c5_lc_y;
  c5_kc_x = c5_s_A;
  c5_mc_y = c5_m_B;
  c5_lc_x = c5_kc_x;
  c5_nc_y = c5_mc_y;
  c5_oc_y = c5_lc_x / c5_nc_y;
  c5_mc_x = c5_oc_y;
  c5_nc_x = c5_mc_x;
  c5_nc_x = muDoubleScalarExp(c5_nc_x);
  c5_n_a = c5_kc_y;
  c5_hb_b = 1.0 - c5_nc_x;
  c5_WVorLT = c5_n_a * c5_hb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_t_A = c5_receiverPos[2] - c5_wingTipLeftPos[2];
  c5_n_B = c5_receiverPos[1] - c5_wingTipLeftPos[1];
  c5_oc_x = c5_t_A;
  c5_pc_y = c5_n_B;
  c5_pc_x = c5_oc_x;
  c5_qc_y = c5_pc_y;
  c5_rc_y = c5_pc_x / c5_qc_y;
  c5_qc_x = c5_rc_y;
  c5_thetaVorLT = c5_qc_x;
  c5_rc_x = c5_thetaVorLT;
  c5_thetaVorLT = c5_rc_x;
  c5_thetaVorLT = muDoubleScalarAtan(c5_thetaVorLT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 97);
  if (CV_SCRIPT_IF(0, 3, c5_receiverPos[1] - c5_wingTipLeftPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 98);
    c5_thetaVorLT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_sc_x = c5_thetaVorLT;
  c5_tc_x = c5_sc_x;
  c5_tc_x = muDoubleScalarSin(c5_tc_x);
  c5_o_a = c5_WVorLT;
  c5_ib_b = c5_tc_x;
  c5_sc_y = c5_o_a * c5_ib_b;
  c5_uc_x = c5_thetaVorLT;
  c5_vc_x = c5_uc_x;
  c5_vc_x = muDoubleScalarCos(c5_vc_x);
  c5_p_a = -c5_WVorLT;
  c5_jb_b = c5_vc_x;
  c5_tc_y = c5_p_a * c5_jb_b;
  c5_dv14[0] = 0.0;
  c5_dv14[1] = c5_sc_y;
  c5_dv14[2] = c5_tc_y;
  for (c5_i29 = 0; c5_i29 < 3; c5_i29++) {
    c5_WVorLTVector[c5_i29] = c5_dv14[c5_i29];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_rVorRT = c5_mpower(chartInstance, c5_receiverPos[1] - c5_tailTipRightPos[1])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_tailTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorRT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_u_A = -(c5_receiverPos[0] - c5_wingTipLeftPos[0]);
  c5_wc_x = c5_u_A;
  c5_xc_x = c5_wc_x;
  c5_tVorRT = c5_xc_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 107);
  c5_TVorRT = 7.4226097064603627;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 108);
  c5_vVorRT = 0.44535658238762177;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 109);
  c5_kb_b = c5_tVorRT;
  c5_uc_y = 0.44535658238762177 * c5_kb_b;
  c5_lb_b = c5_abs(chartInstance, c5_uc_y);
  c5_b_sqrt(chartInstance, &c5_lb_b);
  c5_rVorCoreRT = 2.24 * c5_lb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 111);
  c5_mb_b = c5_rVorRT;
  c5_vc_y = 7.4226097064603627 * c5_mb_b;
  c5_nb_b = c5_mpower(chartInstance, c5_rVorRT) + c5_mpower(chartInstance,
    c5_rVorCoreRT);
  c5_wc_y = 6.2831853071795862 * c5_nb_b;
  c5_v_A = c5_vc_y;
  c5_o_B = c5_wc_y;
  c5_yc_x = c5_v_A;
  c5_xc_y = c5_o_B;
  c5_ad_x = c5_yc_x;
  c5_yc_y = c5_xc_y;
  c5_ad_y = c5_ad_x / c5_yc_y;
  c5_ob_b = c5_tVorRT;
  c5_bd_y = 1.7814263295504871 * c5_ob_b;
  c5_w_A = -c5_mpower(chartInstance, c5_rVorRT);
  c5_p_B = c5_bd_y;
  c5_bd_x = c5_w_A;
  c5_cd_y = c5_p_B;
  c5_cd_x = c5_bd_x;
  c5_dd_y = c5_cd_y;
  c5_ed_y = c5_cd_x / c5_dd_y;
  c5_dd_x = c5_ed_y;
  c5_ed_x = c5_dd_x;
  c5_ed_x = muDoubleScalarExp(c5_ed_x);
  c5_q_a = c5_ad_y;
  c5_pb_b = 1.0 - c5_ed_x;
  c5_WVorRT = c5_q_a * c5_pb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 112);
  c5_x_A = c5_receiverPos[2] - c5_tailTipRightPos[2];
  c5_q_B = -c5_receiverPos[1] + c5_tailTipRightPos[1];
  c5_fd_x = c5_x_A;
  c5_fd_y = c5_q_B;
  c5_gd_x = c5_fd_x;
  c5_gd_y = c5_fd_y;
  c5_hd_y = c5_gd_x / c5_gd_y;
  c5_hd_x = c5_hd_y;
  c5_thetaVorRT = c5_hd_x;
  c5_id_x = c5_thetaVorRT;
  c5_thetaVorRT = c5_id_x;
  c5_thetaVorRT = muDoubleScalarAtan(c5_thetaVorRT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 113);
  if (CV_SCRIPT_IF(0, 4, -c5_receiverPos[1] + c5_tailTipRightPos[1] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 114);
    c5_thetaVorRT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 117);
  c5_jd_x = c5_thetaVorRT;
  c5_kd_x = c5_jd_x;
  c5_kd_x = muDoubleScalarSin(c5_kd_x);
  c5_r_a = -c5_WVorRT;
  c5_qb_b = c5_kd_x;
  c5_id_y = c5_r_a * c5_qb_b;
  c5_ld_x = c5_thetaVorRT;
  c5_md_x = c5_ld_x;
  c5_md_x = muDoubleScalarCos(c5_md_x);
  c5_s_a = -c5_WVorRT;
  c5_rb_b = c5_md_x;
  c5_jd_y = c5_s_a * c5_rb_b;
  c5_dv15[0] = 0.0;
  c5_dv15[1] = c5_id_y;
  c5_dv15[2] = c5_jd_y;
  for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
    c5_WVorRTVector[c5_i30] = c5_dv15[c5_i30];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 120);
  c5_rVorT = c5_mpower(chartInstance, c5_receiverPos[0] - c5_tailTipRightPos[0])
    + c5_mpower(chartInstance, c5_receiverPos[2] - c5_tailTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_rVorT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 121);
  c5_y_A = -(c5_receiverPos[0] - c5_wingTipLeftPos[0]);
  c5_nd_x = c5_y_A;
  c5_od_x = c5_nd_x;
  c5_tVorT = c5_od_x / 190.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 123);
  c5_LVorLengthT = (c5_mpower(chartInstance, c5_receiverPos[0] -
    c5_tailTipLeftPos[0]) + c5_mpower(chartInstance, c5_receiverPos[1] -
    -5.1168690345343757)) + c5_mpower(chartInstance, c5_receiverPos[2] -
    c5_tailTipLeftPos[2]);
  c5_b_sqrt(chartInstance, &c5_LVorLengthT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 124);
  c5_RVorLengthT = (c5_mpower(chartInstance, c5_receiverPos[0] -
    c5_tailTipRightPos[0]) + c5_mpower(chartInstance, c5_receiverPos[1] -
    5.1168690345343757)) + c5_mpower(chartInstance, c5_receiverPos[2] -
    c5_tailTipRightPos[2]);
  c5_b_sqrt(chartInstance, &c5_RVorLengthT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 126);
  c5_ab_A = c5_receiverPos[1] - -5.1168690345343757;
  c5_r_B = c5_LVorLengthT;
  c5_pd_x = c5_ab_A;
  c5_kd_y = c5_r_B;
  c5_qd_x = c5_pd_x;
  c5_ld_y = c5_kd_y;
  c5_gamaLCosT = c5_qd_x / c5_ld_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, MAX_int8_T);
  c5_bb_A = -c5_receiverPos[1] + 5.1168690345343757;
  c5_s_B = c5_RVorLengthT;
  c5_rd_x = c5_bb_A;
  c5_md_y = c5_s_B;
  c5_sd_x = c5_rd_x;
  c5_nd_y = c5_md_y;
  c5_gamaRCosT = c5_sd_x / c5_nd_y;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 129U);
  c5_sb_b = c5_gamaLCosT + c5_gamaRCosT;
  c5_od_y = 7.4226097064603627 * c5_sb_b;
  c5_cb_A = c5_od_y;
  c5_td_x = c5_cb_A;
  c5_ud_x = c5_td_x;
  c5_pd_y = c5_ud_x / 2.0;
  c5_t_a = c5_pd_y;
  c5_qd_y = c5_t_a * 4.0;
  c5_db_A = c5_qd_y;
  c5_vd_x = c5_db_A;
  c5_wd_x = c5_vd_x;
  c5_TVorT = c5_wd_x / 3.1415926535897931;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 130U);
  c5_tb_b = c5_TVorT;
  c5_vVorT = 0.06 * c5_tb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 131U);
  c5_u_a = c5_vVorT;
  c5_ub_b = c5_tVorT;
  c5_rd_y = c5_u_a * c5_ub_b;
  c5_vb_b = c5_abs(chartInstance, c5_rd_y);
  c5_b_sqrt(chartInstance, &c5_vb_b);
  c5_rVorCoreT = 2.24 * c5_vb_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 133U);
  c5_v_a = c5_TVorT;
  c5_wb_b = c5_rVorT;
  c5_sd_y = c5_v_a * c5_wb_b;
  c5_xb_b = c5_mpower(chartInstance, c5_rVorT) + c5_mpower(chartInstance,
    c5_rVorCoreT);
  c5_td_y = 6.2831853071795862 * c5_xb_b;
  c5_eb_A = c5_sd_y;
  c5_t_B = c5_td_y;
  c5_xd_x = c5_eb_A;
  c5_ud_y = c5_t_B;
  c5_yd_x = c5_xd_x;
  c5_vd_y = c5_ud_y;
  c5_wd_y = c5_yd_x / c5_vd_y;
  c5_yb_b = c5_vVorT;
  c5_xd_y = 4.0 * c5_yb_b;
  c5_w_a = c5_xd_y;
  c5_ac_b = c5_tVorT;
  c5_yd_y = c5_w_a * c5_ac_b;
  c5_fb_A = -c5_mpower(chartInstance, c5_rVorT);
  c5_u_B = c5_yd_y;
  c5_ae_x = c5_fb_A;
  c5_ae_y = c5_u_B;
  c5_be_x = c5_ae_x;
  c5_be_y = c5_ae_y;
  c5_ce_y = c5_be_x / c5_be_y;
  c5_ce_x = c5_ce_y;
  c5_de_x = c5_ce_x;
  c5_de_x = muDoubleScalarExp(c5_de_x);
  c5_x_a = c5_wd_y;
  c5_bc_b = 1.0 - c5_de_x;
  c5_WVorT = c5_x_a * c5_bc_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 134U);
  c5_gb_A = c5_receiverPos[2] - c5_tailTipRightPos[2];
  c5_v_B = -c5_receiverPos[0] + c5_tailTipRightPos[0];
  c5_ee_x = c5_gb_A;
  c5_de_y = c5_v_B;
  c5_fe_x = c5_ee_x;
  c5_ee_y = c5_de_y;
  c5_fe_y = c5_fe_x / c5_ee_y;
  c5_ge_x = c5_fe_y;
  c5_thetaVorT = c5_ge_x;
  c5_he_x = c5_thetaVorT;
  c5_thetaVorT = c5_he_x;
  c5_thetaVorT = muDoubleScalarAtan(c5_thetaVorT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 135U);
  if (CV_SCRIPT_IF(0, 5, -c5_receiverPos[0] + c5_tailTipRightPos[0] < 0.0)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 136U);
    c5_thetaVorT += 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 139U);
  c5_ie_x = c5_thetaVorT;
  c5_je_x = c5_ie_x;
  c5_je_x = muDoubleScalarSin(c5_je_x);
  c5_y_a = -c5_WVorT;
  c5_cc_b = c5_je_x;
  c5_ge_y = c5_y_a * c5_cc_b;
  c5_ke_x = c5_thetaVorT;
  c5_le_x = c5_ke_x;
  c5_le_x = muDoubleScalarCos(c5_le_x);
  c5_ab_a = -c5_WVorT;
  c5_dc_b = c5_le_x;
  c5_he_y = c5_ab_a * c5_dc_b;
  c5_ie_y[0] = c5_ge_y;
  c5_ie_y[1] = 0.0;
  c5_ie_y[2] = c5_he_y;
  for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
    c5_WVorTVector[c5_i31] = c5_ie_y[c5_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 142U);
  for (c5_i32 = 0; c5_i32 < 3; c5_i32++) {
    c5_WTotalVector[c5_i32] = ((((c5_WVorLVector[c5_i32] + c5_WVorRVector[c5_i32])
      + c5_WVorWVector[c5_i32]) + c5_WVorLTVector[c5_i32]) +
      c5_WVorRTVector[c5_i32]) + c5_WVorTVector[c5_i32];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 146U);
  for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
    c5_y[c5_i33] = c5_WTotalVector[c5_i33];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -146);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, 0U, sf_debug_get_script_id(
    "D:/360Cloud/\xbf\xd5\xd6\xd0\xbc\xd3\xd3\xcd/Program/AirRefueling/TankerVortexWindField.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i34;
  real_T c5_b_inData[6];
  int32_T c5_i35;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i34 = 0; c5_i34 < 6; c5_i34++) {
    c5_b_inData[c5_i34] = (*(real_T (*)[6])c5_inData)[c5_i34];
  }

  for (c5_i35 = 0; c5_i35 < 6; c5_i35++) {
    c5_u[c5_i35] = c5_b_inData[c5_i35];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier, real_T
  c5_b_y[6])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
}

static void c5_b_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6])
{
  real_T c5_dv16[6];
  int32_T c5_i36;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv16, 1, 0, 0U, 1, 0U, 1, 6);
  for (c5_i36 = 0; c5_i36 < 6; c5_i36++) {
    c5_y[c5_i36] = c5_dv16[c5_i36];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[6];
  int32_T c5_i37;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
  for (c5_i37 = 0; c5_i37 < 6; c5_i37++) {
    (*(real_T (*)[6])c5_outData)[c5_i37] = c5_b_y[c5_i37];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i38;
  real_T c5_b_inData[3];
  int32_T c5_i39;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i38 = 0; c5_i38 < 3; c5_i38++) {
    c5_b_inData[c5_i38] = (*(real_T (*)[3])c5_inData)[c5_i38];
  }

  for (c5_i39 = 0; c5_i39 < 3; c5_i39++) {
    c5_u[c5_i39] = c5_b_inData[c5_i39];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_d_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv17[3];
  int32_T c5_i40;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv17, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
    c5_y[c5_i40] = c5_dv17[c5_i40];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_y_uvw;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i41;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_y_uvw = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y_uvw), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_y_uvw);
  for (c5_i41 = 0; c5_i41 < 3; c5_i41++) {
    (*(real_T (*)[3])c5_outData)[c5_i41] = c5_y[c5_i41];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_F16_Real5_Another_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[28];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i42;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 28), FALSE);
  for (c5_i42 = 0; c5_i42 < 28; c5_i42++) {
    c5_r0 = &c5_info[c5_i42];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i42);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i42);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[28])
{
  c5_info[0].context = "";
  c5_info[0].name = "TankerVortexWindField";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[0].fileTimeLo = 1411826324U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[1].name = "mtimes";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[1].fileTimeLo = 1289494492U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[2].name = "mrdivide";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[2].fileTimeLo = 1357926348U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 1319708366U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[3].name = "rdivide";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[3].fileTimeLo = 1346488788U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[4].name = "eml_scalexp_compatible";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c5_info[4].fileTimeLo = 1286797196U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[5].name = "eml_div";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[5].fileTimeLo = 1313326210U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[6].name = "mpower";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[6].fileTimeLo = 1286797242U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[7].name = "power";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[7].fileTimeLo = 1348170330U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[8].name = "eml_scalar_eg";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[8].fileTimeLo = 1286797196U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[9].name = "eml_scalexp_alloc";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[9].fileTimeLo = 1352399660U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[10].name = "floor";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[10].fileTimeLo = 1343808780U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[11].name = "eml_scalar_floor";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[11].fileTimeLo = 1286797126U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[12].name = "eml_scalar_eg";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[12].fileTimeLo = 1286797196U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[13].name = "mtimes";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[13].fileTimeLo = 1289494492U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[14].name = "sqrt";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[14].fileTimeLo = 1343808786U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[15].name = "eml_error";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[15].fileTimeLo = 1343808758U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c5_info[16].name = "eml_scalar_sqrt";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c5_info[16].fileTimeLo = 1286797138U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[17].name = "abs";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[17].fileTimeLo = 1343808766U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[18].name = "eml_scalar_abs";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[18].fileTimeLo = 1286797112U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[19].name = "exp";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c5_info[19].fileTimeLo = 1343808780U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c5_info[20].name = "eml_scalar_exp";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c5_info[20].fileTimeLo = 1301306864U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[21].name = "atan";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[21].fileTimeLo = 1343808772U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  c5_info[22].name = "eml_scalar_atan";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  c5_info[22].fileTimeLo = 1286797118U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[23].name = "sin";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[23].fileTimeLo = 1343808786U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[24].name = "eml_scalar_sin";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[24].fileTimeLo = 1286797136U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context =
    "[EW]D:/360Cloud/\\xe7\\xa9\\xba\\xe4\\xb8\\xad\\xe5\\x8a\\xa0\\xe6\\xb2\\xb9/Program/AirRefueling/TankerVortexWindField.m";
  c5_info[25].name = "cos";
  c5_info[25].dominantType = "double";
  c5_info[25].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[25].fileTimeLo = 1343808772U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 0U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[26].name = "eml_scalar_cos";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[26].fileTimeLo = 1286797122U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context = "";
  c5_info[27].name = "mrdivide";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[27].fileTimeLo = 1357926348U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 1319708366U;
  c5_info[27].mFileTimeHi = 0U;
}

static real_T c5_mpower(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
  real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  real_T c5_e_a;
  real_T c5_b;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_eml_scalar_eg(chartInstance);
  c5_e_a = c5_d_a;
  c5_b = c5_d_a;
  return c5_e_a * c5_b;
}

static void c5_eml_scalar_eg(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
}

static real_T c5_sqrt(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
                      real_T c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  c5_b_sqrt(chartInstance, &c5_b_x);
  return c5_b_x;
}

static void c5_eml_error(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance)
{
  int32_T c5_i43;
  static char_T c5_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[30];
  const mxArray *c5_y = NULL;
  int32_T c5_i44;
  static char_T c5_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c5_b_u[4];
  const mxArray *c5_b_y = NULL;
  for (c5_i43 = 0; c5_i43 < 30; c5_i43++) {
    c5_u[c5_i43] = c5_cv0[c5_i43];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c5_i44 = 0; c5_i44 < 4; c5_i44++) {
    c5_b_u[c5_i44] = c5_cv1[c5_i44];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c5_y, 14, c5_b_y));
}

static real_T c5_abs(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance, real_T
                     c5_x)
{
  real_T c5_b_x;
  c5_b_x = c5_x;
  return muDoubleScalarAbs(c5_b_x);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i45;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i45, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i45;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_F16_Real5_Another, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_F16_Real5_Another), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_F16_Real5_Another);
  return c5_y;
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_F16_Real5_AnotherInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sqrt(SFc5_F16_Real5_AnotherInstanceStruct *chartInstance,
                      real_T *c5_x)
{
  if (*c5_x < 0.0) {
    c5_eml_error(chartInstance);
  }

  *c5_x = muDoubleScalarSqrt(*c5_x);
}

static void init_dsm_address_info(SFc5_F16_Real5_AnotherInstanceStruct
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

void sf_c5_F16_Real5_Another_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2982146248U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(826180707U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(951169276U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3396213464U);
}

mxArray *sf_c5_F16_Real5_Another_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Zrwn5407zJpAcwAAAVeZbC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(6);
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

mxArray *sf_c5_F16_Real5_Another_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_F16_Real5_Another(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_F16_Real5_Another\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_F16_Real5_Another_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
    chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _F16_Real5_AnotherMachineNumber_,
           5,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_F16_Real5_AnotherMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_F16_Real5_AnotherMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _F16_Real5_AnotherMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,605);
        _SFD_CV_INIT_SCRIPT(0,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"TankerVortexWindField",0,-1,7134);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1724,1740,-1,1775);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2367,2410,-1,2445);
        _SFD_CV_INIT_SCRIPT_IF(0,2,3749,3792,-1,3827);
        _SFD_CV_INIT_SCRIPT_IF(0,3,4711,4752,-1,4789);
        _SFD_CV_INIT_SCRIPT_IF(0,4,5428,5471,-1,5508);
        _SFD_CV_INIT_SCRIPT_IF(0,5,6835,6878,-1,6913);
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
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          real_T (*c5_u)[3];
          real_T (*c5_y)[6];
          c5_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _F16_Real5_AnotherMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "r2SpHRUVODNFfL4JBqfXAB";
}

static void sf_opaque_initialize_c5_F16_Real5_Another(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
  initialize_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_F16_Real5_Another(void *chartInstanceVar)
{
  enable_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_F16_Real5_Another(void *chartInstanceVar)
{
  disable_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_F16_Real5_Another(void *chartInstanceVar)
{
  sf_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_F16_Real5_Another(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_F16_Real5_Another
    ((SFc5_F16_Real5_AnotherInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_F16_Real5_Another();/* state var info */
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

extern void sf_internal_set_sim_state_c5_F16_Real5_Another(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_F16_Real5_Another();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_F16_Real5_Another(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_F16_Real5_Another(S);
}

static void sf_opaque_set_sim_state_c5_F16_Real5_Another(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_F16_Real5_Another(S, st);
}

static void sf_opaque_terminate_c5_F16_Real5_Another(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_F16_Real5_AnotherInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_F16_Real5_Another_optimization_info();
    }

    finalize_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_F16_Real5_Another(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_F16_Real5_Another((SFc5_F16_Real5_AnotherInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_F16_Real5_Another(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_F16_Real5_Another_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2973932599U));
  ssSetChecksum1(S,(1046186364U));
  ssSetChecksum2(S,(3911636369U));
  ssSetChecksum3(S,(299471972U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_F16_Real5_Another(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_F16_Real5_Another(SimStruct *S)
{
  SFc5_F16_Real5_AnotherInstanceStruct *chartInstance;
  chartInstance = (SFc5_F16_Real5_AnotherInstanceStruct *)utMalloc(sizeof
    (SFc5_F16_Real5_AnotherInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_F16_Real5_AnotherInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_F16_Real5_Another;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_F16_Real5_Another;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_F16_Real5_Another;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_F16_Real5_Another;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_F16_Real5_Another;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_F16_Real5_Another;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_F16_Real5_Another;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_F16_Real5_Another;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_F16_Real5_Another;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_F16_Real5_Another;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_F16_Real5_Another;
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

void c5_F16_Real5_Another_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_F16_Real5_Another(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_F16_Real5_Another(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_F16_Real5_Another(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_F16_Real5_Another_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
