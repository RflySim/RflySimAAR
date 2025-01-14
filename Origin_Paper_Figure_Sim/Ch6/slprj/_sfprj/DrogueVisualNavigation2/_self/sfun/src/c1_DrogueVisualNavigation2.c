/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DrogueVisualNavigation2_sfun.h"
#include "c1_DrogueVisualNavigation2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DrogueVisualNavigation2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[16] = { "L", "N", "dX", "dY", "k", "r",
  "c", "m", "cX", "cY", "cR", "nargin", "nargout", "u1", "u2", "yy" };

/* Function Declarations */
static void initialize_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void initialize_params_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void enable_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void disable_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void set_sim_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void sf_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void c1_chartstep_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void initSimStructsc1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void registerMessagesc1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_yy, const char_T *c1_identifier, real_T
  c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[345600], int32_T c1_inData_sizes[1]);
static void c1_e_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[345600], int32_T c1_y_sizes[1]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[345600],
  int32_T c1_outData_sizes[1]);
static uint32_T c1_f_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_h_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[345600]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[201]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[201]);
static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[201]);
static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[201]);
static void c1_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_eml_find(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, boolean_T c1_x[345600], int32_T c1_i_data[345600], int32_T
  c1_i_sizes[1], int32_T c1_j_data[345600], int32_T c1_j_sizes[1]);
static void c1_eml_scalar_eg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance);
static real_T c1_mean(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T c1_x_data[345600], int32_T c1_x_sizes[1]);
static void c1_b_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_power(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                     real_T c1_a[10], real_T c1_y[10]);
static void c1_b_eml_scalar_eg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance);
static void c1_mldivide(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_A[30], real_T c1_B[10], real_T c1_Y[3]);
static void c1_eps(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static real_T c1_sqrt(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T c1_x);
static void c1_eml_error(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance);
static real_T c1_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0);
static void c1_realmin(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance);
static int32_T c1_eml_ixamax(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T c1_ix0);
static void c1_eml_xswap(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0, int32_T c1_iy0, real_T
  c1_b_x[30]);
static void c1_below_threshold(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance);
static void c1_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_alpha1, real_T c1_x[30], int32_T
  c1_ix0, real_T *c1_b_alpha1, real_T c1_b_x[30], real_T *c1_tau);
static real_T c1_b_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[30], int32_T c1_ix0);
static void c1_eml_xscal(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[30], int32_T c1_ix0,
  real_T c1_b_x[30]);
static void c1_eml_matlab_zlarf(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[30], int32_T c1_ic0, real_T c1_work[3], real_T c1_b_C[30], real_T
  c1_b_work[3]);
static void c1_eml_xgemv(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[30], int32_T c1_ia0,
  real_T c1_x[30], int32_T c1_ix0, real_T c1_y[3], real_T c1_b_y[3]);
static void c1_eml_xger(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A[30], int32_T c1_ia0, real_T c1_b_A[30]);
static real_T c1_c_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[30], int32_T c1_ix0);
static void c1_eml_warning(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14]);
static real_T c1_mpower(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_a);
static void c1_i_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14]);
static void c1_j_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14]);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_k_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_l_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_DrogueVisualNavigation2, const
  char_T *c1_identifier);
static uint8_T c1_m_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T *c1_x);
static void c1_b_eml_xswap(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0, int32_T c1_iy0);
static real_T c1_b_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, int32_T c1_n, real_T *c1_alpha1, real_T c1_x[30], int32_T
  c1_ix0);
static void c1_b_eml_xscal(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[30], int32_T c1_ix0);
static void c1_b_eml_matlab_zlarf(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[30], int32_T c1_ic0, real_T c1_work[3]);
static void c1_b_eml_xgemv(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[30], int32_T c1_ia0,
  real_T c1_x[30], int32_T c1_ix0, real_T c1_y[3]);
static void c1_b_eml_xger(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A[30], int32_T c1_ia0);
static void init_dsm_address_info(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_DrogueVisualNavigation2 = 0U;
}

static void initialize_params_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static void enable_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[3];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_yy)[3];
  c1_yy = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_u[c1_i0] = (*c1_yy)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_DrogueVisualNavigation2;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i1;
  real_T (*c1_yy)[3];
  c1_yy = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "yy",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    (*c1_yy)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_DrogueVisualNavigation2 = c1_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_DrogueVisualNavigation2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DrogueVisualNavigation2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static void sf_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  uint32_T *c1_u2;
  real_T (*c1_yy)[3];
  uint32_T (*c1_u1)[345600];
  c1_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_yy = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u1 = (uint32_T (*)[345600])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 345600; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_u1)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_yy)[c1_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c1_u2, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_DrogueVisualNavigation2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DrogueVisualNavigation2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
  uint32_T c1_hoistedGlobal;
  int32_T c1_i4;
  static uint32_T c1_u1[345600];
  uint32_T c1_u2;
  uint32_T c1_debug_family_var_map[16];
  static uint32_T c1_L[345600];
  uint32_T c1_N;
  real_T c1_dX[10];
  real_T c1_dY[10];
  uint32_T c1_k;
  int32_T c1_r_sizes;
  static real_T c1_r_data[345600];
  int32_T c1_c_sizes;
  static real_T c1_c_data[345600];
  real_T c1_m[3];
  real_T c1_cX;
  real_T c1_cY;
  real_T c1_cR;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_yy[3];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  uint32_T c1_b_N;
  uint32_T c1_b;
  uint32_T c1_b_b;
  boolean_T c1_overflow;
  uint32_T c1_b_k;
  int32_T c1_i8;
  static boolean_T c1_x[345600];
  int32_T c1_i9;
  static boolean_T c1_b_x[345600];
  int32_T c1_jj_sizes;
  static int32_T c1_jj_data[345600];
  int32_T c1_ii_sizes;
  static int32_T c1_ii_data[345600];
  int32_T c1_b_r_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i10;
  static real_T c1_b_r_data[345600];
  int32_T c1_b_c_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i11;
  static real_T c1_b_c_data[345600];
  int32_T c1_c_loop_ub;
  int32_T c1_i12;
  int32_T c1_d_loop_ub;
  int32_T c1_i13;
  int32_T c1_c_r_sizes;
  int32_T c1_e_loop_ub;
  int32_T c1_i14;
  static real_T c1_c_r_data[345600];
  int32_T c1_c_c_sizes;
  int32_T c1_f_loop_ub;
  int32_T c1_i15;
  static real_T c1_c_c_data[345600];
  int32_T c1_i16;
  real_T c1_dv1[10];
  int32_T c1_i17;
  real_T c1_b_dY[10];
  real_T c1_dv2[10];
  int32_T c1_i18;
  real_T c1_b_dX[10];
  real_T c1_dv3[10];
  int32_T c1_i19;
  real_T c1_c_dX[30];
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_dv4[10];
  real_T c1_dv5[3];
  int32_T c1_i23;
  real_T c1_c_b;
  real_T c1_d_b;
  real_T c1_A;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_y;
  real_T c1_b_A[3];
  int32_T c1_i24;
  int32_T c1_i25;
  uint32_T *c1_b_u2;
  real_T (*c1_b_yy)[3];
  uint32_T (*c1_b_u1)[345600];
  c1_b_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_yy = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_u1 = (uint32_T (*)[345600])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_u2;
  for (c1_i4 = 0; c1_i4 < 345600; c1_i4++) {
    c1_u1[c1_i4] = (*c1_b_u1)[c1_i4];
  }

  c1_u2 = c1_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_L, 0U, c1_c_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_N, 1U, c1_b_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dX, 2U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dY, 3U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k, 4U, c1_b_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_r_data, (const int32_T *)
    &c1_r_sizes, NULL, 0, 5, (void *)c1_f_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_c_data, (const int32_T *)
    &c1_c_sizes, NULL, 0, 6, (void *)c1_f_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_m, 7U, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cX, 8U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cY, 9U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cR, 10U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 11U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 12U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u1, 13U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_u2, 14U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_yy, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i5 = 0; c1_i5 < 345600; c1_i5++) {
    c1_L[c1_i5] = c1_u1[c1_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_N = c1_u2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i6 = 0; c1_i6 < 10; c1_i6++) {
    c1_dX[c1_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  for (c1_i7 = 0; c1_i7 < 10; c1_i7++) {
    c1_dY[c1_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_b_N = c1_N;
  c1_b = c1_b_N;
  c1_b_b = c1_b;
  if (1U > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 4294967294U);
  }

  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, TRUE);
  }

  c1_k = 1U;
  c1_b_k = 1U;
  while (c1_b_k <= c1_b_N) {
    c1_k = c1_b_k;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    for (c1_i8 = 0; c1_i8 < 345600; c1_i8++) {
      c1_x[c1_i8] = (c1_L[c1_i8] == c1_k);
    }

    for (c1_i9 = 0; c1_i9 < 345600; c1_i9++) {
      c1_b_x[c1_i9] = c1_x[c1_i9];
    }

    c1_eml_find(chartInstance, c1_b_x, c1_ii_data, *(int32_T (*)[1])&c1_ii_sizes,
                c1_jj_data, *(int32_T (*)[1])&c1_jj_sizes);
    c1_b_r_sizes = c1_ii_sizes;
    c1_loop_ub = c1_ii_sizes - 1;
    for (c1_i10 = 0; c1_i10 <= c1_loop_ub; c1_i10++) {
      c1_b_r_data[c1_i10] = (real_T)c1_ii_data[c1_i10];
    }

    c1_b_c_sizes = c1_jj_sizes;
    c1_b_loop_ub = c1_jj_sizes - 1;
    for (c1_i11 = 0; c1_i11 <= c1_b_loop_ub; c1_i11++) {
      c1_b_c_data[c1_i11] = (real_T)c1_jj_data[c1_i11];
    }

    c1_r_sizes = c1_b_r_sizes;
    c1_c_loop_ub = c1_b_r_sizes - 1;
    for (c1_i12 = 0; c1_i12 <= c1_c_loop_ub; c1_i12++) {
      c1_r_data[c1_i12] = c1_b_r_data[c1_i12];
    }

    c1_c_sizes = c1_b_c_sizes;
    c1_d_loop_ub = c1_b_c_sizes - 1;
    for (c1_i13 = 0; c1_i13 <= c1_d_loop_ub; c1_i13++) {
      c1_c_data[c1_i13] = c1_b_c_data[c1_i13];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    c1_c_r_sizes = c1_r_sizes;
    c1_e_loop_ub = c1_r_sizes - 1;
    for (c1_i14 = 0; c1_i14 <= c1_e_loop_ub; c1_i14++) {
      c1_c_r_data[c1_i14] = c1_r_data[c1_i14];
    }

    c1_dX[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c1_k, 1,
      10, 1, 0) - 1] = c1_mean(chartInstance, c1_c_r_data, *(int32_T (*)[1])&
      c1_c_r_sizes);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    c1_c_c_sizes = c1_c_sizes;
    c1_f_loop_ub = c1_c_sizes - 1;
    for (c1_i15 = 0; c1_i15 <= c1_f_loop_ub; c1_i15++) {
      c1_c_c_data[c1_i15] = c1_c_data[c1_i15];
    }

    c1_dY[(int32_T)c1_k - 1] = c1_mean(chartInstance, c1_c_c_data, *(int32_T (*)
      [1])&c1_c_c_sizes);
    c1_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  for (c1_i16 = 0; c1_i16 < 10; c1_i16++) {
    c1_dv1[c1_i16] = 1.0;
  }

  for (c1_i17 = 0; c1_i17 < 10; c1_i17++) {
    c1_b_dY[c1_i17] = c1_dY[c1_i17];
  }

  c1_power(chartInstance, c1_b_dY, c1_dv2);
  for (c1_i18 = 0; c1_i18 < 10; c1_i18++) {
    c1_b_dX[c1_i18] = c1_dX[c1_i18];
  }

  c1_power(chartInstance, c1_b_dX, c1_dv3);
  for (c1_i19 = 0; c1_i19 < 10; c1_i19++) {
    c1_c_dX[c1_i19] = c1_dX[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 10; c1_i20++) {
    c1_c_dX[c1_i20 + 10] = c1_dY[c1_i20];
  }

  for (c1_i21 = 0; c1_i21 < 10; c1_i21++) {
    c1_c_dX[c1_i21 + 20] = c1_dv1[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 10; c1_i22++) {
    c1_dv4[c1_i22] = -(c1_dv3[c1_i22] + c1_dv2[c1_i22]);
  }

  c1_mldivide(chartInstance, c1_c_dX, c1_dv4, c1_dv5);
  for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
    c1_m[c1_i23] = c1_dv5[c1_i23];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_c_b = c1_m[0];
  c1_cX = -0.5 * c1_c_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_d_b = c1_m[1];
  c1_cY = -0.5 * c1_d_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_A = c1_mpower(chartInstance, c1_m[0]) + c1_mpower(chartInstance, c1_m[1]);
  c1_c_x = c1_A;
  c1_d_x = c1_c_x;
  c1_y = c1_d_x / 4.0;
  c1_cR = c1_y - c1_m[2];
  c1_b_sqrt(chartInstance, &c1_cR);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  c1_b_A[0] = c1_cX;
  c1_b_A[1] = c1_cY;
  c1_b_A[2] = c1_cR;
  for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
    c1_yy[c1_i24] = c1_b_A[c1_i24] / 480.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i25 = 0; c1_i25 < 3; c1_i25++) {
    (*c1_b_yy)[c1_i25] = c1_yy[c1_i25];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static void registerMessagesc1_DrogueVisualNavigation2
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i26;
  real_T c1_b_inData[3];
  int32_T c1_i27;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i26 = 0; c1_i26 < 3; c1_i26++) {
    c1_b_inData[c1_i26] = (*(real_T (*)[3])c1_inData)[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 3; c1_i27++) {
    c1_u[c1_i27] = c1_b_inData[c1_i27];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_yy, const char_T *c1_identifier, real_T
  c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_yy), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_yy);
}

static void c1_b_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv6[3];
  int32_T c1_i28;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c1_i28 = 0; c1_i28 < 3; c1_i28++) {
    c1_y[c1_i28] = c1_dv6[c1_i28];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_yy;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i29;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_yy = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_yy), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_yy);
  for (c1_i29 = 0; c1_i29 < 3; c1_i29++) {
    (*(real_T (*)[3])c1_outData)[c1_i29] = c1_y[c1_i29];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  static uint32_T c1_b_inData[345600];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  static uint32_T c1_u[345600];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 720; c1_i31++) {
    for (c1_i32 = 0; c1_i32 < 480; c1_i32++) {
      c1_b_inData[c1_i32 + c1_i30] = (*(uint32_T (*)[345600])c1_inData)[c1_i32 +
        c1_i30];
    }

    c1_i30 += 480;
  }

  c1_i33 = 0;
  for (c1_i34 = 0; c1_i34 < 720; c1_i34++) {
    for (c1_i35 = 0; c1_i35 < 480; c1_i35++) {
      c1_u[c1_i35 + c1_i33] = c1_b_inData[c1_i35 + c1_i33];
    }

    c1_i33 += 480;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 7, 0U, 1U, 0U, 2, 480, 720),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i36;
  real_T c1_b_inData[3];
  int32_T c1_i37;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_b_inData[c1_i36] = (*(real_T (*)[3])c1_inData)[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 3; c1_i37++) {
    c1_u[c1_i37] = c1_b_inData[c1_i37];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv7[3];
  int32_T c1_i38;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i38 = 0; c1_i38 < 3; c1_i38++) {
    c1_y[c1_i38] = c1_dv7[c1_i38];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_m;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i39;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_m = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_m), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_m);
  for (c1_i39 = 0; c1_i39 < 3; c1_i39++) {
    (*(real_T (*)[3])c1_outData)[c1_i39] = c1_y[c1_i39];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[345600], int32_T c1_inData_sizes[1])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i40;
  static real_T c1_b_inData_data[345600];
  int32_T c1_u_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i41;
  static real_T c1_u_data[345600];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes = c1_inData_sizes[0];
  c1_loop_ub = c1_inData_sizes[0] - 1;
  for (c1_i40 = 0; c1_i40 <= c1_loop_ub; c1_i40++) {
    c1_b_inData_data[c1_i40] = c1_inData_data[c1_i40];
  }

  c1_u_sizes = c1_b_inData_sizes;
  c1_b_loop_ub = c1_b_inData_sizes - 1;
  for (c1_i41 = 0; c1_i41 <= c1_b_loop_ub; c1_i41++) {
    c1_u_data[c1_i41] = c1_b_inData_data[c1_i41];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_sizes), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[345600], int32_T c1_y_sizes[1])
{
  static uint32_T c1_uv0[1] = { 345600U };

  uint32_T c1_uv1[1];
  static boolean_T c1_bv0[1] = { TRUE };

  boolean_T c1_bv1[1];
  int32_T c1_tmp_sizes;
  static real_T c1_tmp_data[345600];
  int32_T c1_loop_ub;
  int32_T c1_i42;
  c1_uv1[0] = c1_uv0[0];
  c1_bv1[0] = c1_bv0[0];
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c1_bv1, c1_uv1, &c1_tmp_sizes);
  c1_y_sizes[0] = c1_tmp_sizes;
  c1_loop_ub = c1_tmp_sizes - 1;
  for (c1_i42 = 0; c1_i42 <= c1_loop_ub; c1_i42++) {
    c1_y_data[c1_i42] = c1_tmp_data[c1_i42];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[345600],
  int32_T c1_outData_sizes[1])
{
  const mxArray *c1_c;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes;
  static real_T c1_y_data[345600];
  int32_T c1_loop_ub;
  int32_T c1_i43;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_c = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c), &c1_thisId, c1_y_data, *
                        (int32_T (*)[1])&c1_y_sizes);
  sf_mex_destroy(&c1_c);
  c1_outData_sizes[0] = c1_y_sizes;
  c1_loop_ub = c1_y_sizes - 1;
  for (c1_i43 = 0; c1_i43 <= c1_loop_ub; c1_i43++) {
    c1_outData_data[c1_i43] = c1_y_data[c1_i43];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_f_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_k;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_k = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_k), &c1_thisId);
  sf_mex_destroy(&c1_k);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i44;
  real_T c1_b_inData[10];
  int32_T c1_i45;
  real_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i44 = 0; c1_i44 < 10; c1_i44++) {
    c1_b_inData[c1_i44] = (*(real_T (*)[10])c1_inData)[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 10; c1_i45++) {
    c1_u[c1_i45] = c1_b_inData[c1_i45];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10])
{
  real_T c1_dv8[10];
  int32_T c1_i46;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 1, 10);
  for (c1_i46 = 0; c1_i46 < 10; c1_i46++) {
    c1_y[c1_i46] = c1_dv8[c1_i46];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dY;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[10];
  int32_T c1_i47;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_dY = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dY), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dY);
  for (c1_i47 = 0; c1_i47 < 10; c1_i47++) {
    (*(real_T (*)[10])c1_outData)[c1_i47] = c1_y[c1_i47];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_h_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[345600])
{
  static uint32_T c1_uv2[345600];
  int32_T c1_i48;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv2, 1, 7, 0U, 1, 0U, 2, 480,
                720);
  for (c1_i48 = 0; c1_i48 < 345600; c1_i48++) {
    c1_y[c1_i48] = c1_uv2[c1_i48];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_L;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  static uint32_T c1_y[345600];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_L = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_L), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_L);
  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 720; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 480; c1_i51++) {
      (*(uint32_T (*)[345600])c1_outData)[c1_i51 + c1_i49] = c1_y[c1_i51 +
        c1_i49];
    }

    c1_i49 += 480;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DrogueVisualNavigation2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[201];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i52;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  c1_c_info_helper(c1_info);
  c1_d_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 201), FALSE);
  for (c1_i52 = 0; c1_i52 < 201; c1_i52++) {
    c1_r0 = &c1_info[c1_i52];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i52);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[201])
{
  c1_info[0].context = "";
  c1_info[0].name = "eml_int_forloop_overflow_check";
  c1_info[0].dominantType = "";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[0].fileTimeLo = 1346488740U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[1].name = "intmax";
  c1_info[1].dominantType = "char";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[1].fileTimeLo = 1311233716U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "find";
  c1_info[2].dominantType = "logical";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c1_info[2].fileTimeLo = 1303124606U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[3].name = "eml_index_class";
  c1_info[3].dominantType = "";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[3].fileTimeLo = 1323145378U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[4].name = "eml_scalar_eg";
  c1_info[4].dominantType = "logical";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[4].fileTimeLo = 1286797196U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c1_info[5].name = "eml_index_plus";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[5].fileTimeLo = 1286797178U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[6].name = "eml_index_class";
  c1_info[6].dominantType = "";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[6].fileTimeLo = 1323145378U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "";
  c1_info[7].name = "mean";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c1_info[7].fileTimeLo = 1286797094U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c1_info[8].name = "isequal";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[8].fileTimeLo = 1286797158U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[9].name = "eml_isequal_core";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[9].fileTimeLo = 1286797186U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c1_info[10].name = "eml_const_nonsingleton_dim";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[10].fileTimeLo = 1286797096U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c1_info[11].name = "sum";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[11].fileTimeLo = 1314715012U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[12].name = "eml_assert_valid_dim";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[12].fileTimeLo = 1286797094U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[13].name = "eml_scalar_floor";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[13].fileTimeLo = 1286797126U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[14].name = "eml_index_class";
  c1_info[14].dominantType = "";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[14].fileTimeLo = 1323145378U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[15].name = "intmax";
  c1_info[15].dominantType = "char";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[15].fileTimeLo = 1311233716U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323145378U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[17].name = "eml_scalar_eg";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[17].fileTimeLo = 1286797196U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c1_info[18].name = "eml_int_forloop_overflow_check";
  c1_info[18].dominantType = "";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[18].fileTimeLo = 1346488740U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c1_info[19].name = "rdivide";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[19].fileTimeLo = 1346488788U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[20].name = "eml_scalexp_compatible";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[20].fileTimeLo = 1286797196U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[21].name = "eml_div";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[21].fileTimeLo = 1313326210U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context = "";
  c1_info[22].name = "power";
  c1_info[22].dominantType = "double";
  c1_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[22].fileTimeLo = 1348170330U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[23].name = "eml_scalar_eg";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[23].fileTimeLo = 1286797196U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[24].name = "eml_scalexp_alloc";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[24].fileTimeLo = 1352399660U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[25].name = "floor";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[25].fileTimeLo = 1343808780U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[26].name = "eml_scalar_floor";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[26].fileTimeLo = 1286797126U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[27].name = "eml_scalar_eg";
  c1_info[27].dominantType = "double";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[27].fileTimeLo = 1286797196U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[28].name = "mtimes";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[28].fileTimeLo = 1289494492U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context = "";
  c1_info[29].name = "mldivide";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[29].fileTimeLo = 1357926348U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 1319708366U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[30].name = "eml_qrsolve";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[30].fileTimeLo = 1307629644U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[31].name = "min";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[31].fileTimeLo = 1311233718U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[32].name = "eml_min_or_max";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[32].fileTimeLo = 1334049890U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[33].name = "eml_scalar_eg";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[33].fileTimeLo = 1286797196U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[34].name = "eml_scalexp_alloc";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[34].fileTimeLo = 1352399660U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[35].name = "eml_index_class";
  c1_info[35].dominantType = "";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[35].fileTimeLo = 1323145378U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[36].name = "eml_scalar_eg";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[36].fileTimeLo = 1286797196U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[37].name = "eml_xgeqp3";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[37].fileTimeLo = 1286797204U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[38].name = "eml_lapack_xgeqp3";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[38].fileTimeLo = 1286797208U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[39].name = "eml_matlab_zgeqp3";
  c1_info[39].dominantType = "double";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[39].fileTimeLo = 1289974166U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[40].name = "eml_index_class";
  c1_info[40].dominantType = "";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[40].fileTimeLo = 1323145378U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[41].name = "min";
  c1_info[41].dominantType = "coder.internal.indexInt";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[41].fileTimeLo = 1311233718U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[42].name = "eml_scalar_eg";
  c1_info[42].dominantType = "coder.internal.indexInt";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[42].fileTimeLo = 1286797196U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[43].name = "eml_scalexp_alloc";
  c1_info[43].dominantType = "coder.internal.indexInt";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[43].fileTimeLo = 1352399660U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[44].name = "eml_scalar_eg";
  c1_info[44].dominantType = "coder.internal.indexInt";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[44].fileTimeLo = 1286797196U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[45].name = "eml_scalar_eg";
  c1_info[45].dominantType = "double";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[45].fileTimeLo = 1286797196U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[46].name = "colon";
  c1_info[46].dominantType = "coder.internal.indexInt";
  c1_info[46].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[46].fileTimeLo = 1348170328U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[47].name = "colon";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[47].fileTimeLo = 1348170328U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[48].name = "floor";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[48].fileTimeLo = 1343808780U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[49].name = "intmin";
  c1_info[49].dominantType = "char";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[49].fileTimeLo = 1311233718U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[50].name = "intmax";
  c1_info[50].dominantType = "char";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[50].fileTimeLo = 1311233716U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[51].name = "intmin";
  c1_info[51].dominantType = "char";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[51].fileTimeLo = 1311233718U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[52].name = "intmax";
  c1_info[52].dominantType = "char";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[52].fileTimeLo = 1311233716U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[53].name = "eml_isa_uint";
  c1_info[53].dominantType = "coder.internal.indexInt";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[53].fileTimeLo = 1286797184U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[54].name = "eml_unsigned_class";
  c1_info[54].dominantType = "char";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[54].fileTimeLo = 1323145380U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[55].name = "eml_index_class";
  c1_info[55].dominantType = "";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[55].fileTimeLo = 1323145378U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[56].name = "eml_index_class";
  c1_info[56].dominantType = "";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[56].fileTimeLo = 1323145378U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[57].name = "intmax";
  c1_info[57].dominantType = "char";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[57].fileTimeLo = 1311233716U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[58].name = "eml_isa_uint";
  c1_info[58].dominantType = "coder.internal.indexInt";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[58].fileTimeLo = 1286797184U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[59].name = "eml_index_plus";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[59].fileTimeLo = 1286797178U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c1_info[60].name = "eml_int_forloop_overflow_check";
  c1_info[60].dominantType = "";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[60].fileTimeLo = 1346488740U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[61].name = "eps";
  c1_info[61].dominantType = "char";
  c1_info[61].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[61].fileTimeLo = 1326702796U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[62].name = "eml_is_float_class";
  c1_info[62].dominantType = "char";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[62].fileTimeLo = 1286797182U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[63].name = "eml_eps";
  c1_info[63].dominantType = "char";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[63].fileTimeLo = 1326702796U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[201])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[64].name = "eml_float_model";
  c1_info[64].dominantType = "char";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[64].fileTimeLo = 1326702796U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[65].name = "sqrt";
  c1_info[65].dominantType = "double";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[65].fileTimeLo = 1343808786U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[66].name = "eml_error";
  c1_info[66].dominantType = "char";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[66].fileTimeLo = 1343808758U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[67].name = "eml_scalar_sqrt";
  c1_info[67].dominantType = "double";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[67].fileTimeLo = 1286797138U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[68].name = "eml_int_forloop_overflow_check";
  c1_info[68].dominantType = "";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[68].fileTimeLo = 1346488740U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[69].name = "eml_xnrm2";
  c1_info[69].dominantType = "double";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[69].fileTimeLo = 1299051576U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[70].name = "eml_blas_inline";
  c1_info[70].dominantType = "";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[70].fileTimeLo = 1299051568U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[71].name = "eml_index_class";
  c1_info[71].dominantType = "";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[71].fileTimeLo = 1323145378U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[72].name = "eml_refblas_xnrm2";
  c1_info[72].dominantType = "double";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[72].fileTimeLo = 1299051584U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[73].name = "realmin";
  c1_info[73].dominantType = "char";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[73].fileTimeLo = 1307629642U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[74].name = "eml_realmin";
  c1_info[74].dominantType = "char";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[74].fileTimeLo = 1307629644U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[75].name = "eml_float_model";
  c1_info[75].dominantType = "char";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[75].fileTimeLo = 1326702796U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[76].name = "eml_index_class";
  c1_info[76].dominantType = "";
  c1_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[76].fileTimeLo = 1323145378U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[77].name = "eml_index_minus";
  c1_info[77].dominantType = "double";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[77].fileTimeLo = 1286797178U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[78].name = "eml_index_class";
  c1_info[78].dominantType = "";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[78].fileTimeLo = 1323145378U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[79].name = "eml_index_times";
  c1_info[79].dominantType = "coder.internal.indexInt";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[79].fileTimeLo = 1286797180U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[80].name = "eml_index_class";
  c1_info[80].dominantType = "";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[80].fileTimeLo = 1323145378U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[81].name = "eml_index_plus";
  c1_info[81].dominantType = "coder.internal.indexInt";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[81].fileTimeLo = 1286797178U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[82].name = "eml_int_forloop_overflow_check";
  c1_info[82].dominantType = "";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[82].fileTimeLo = 1346488740U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[83].name = "abs";
  c1_info[83].dominantType = "double";
  c1_info[83].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[83].fileTimeLo = 1343808766U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[84].name = "eml_scalar_abs";
  c1_info[84].dominantType = "double";
  c1_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[84].fileTimeLo = 1286797112U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[85].name = "eml_index_plus";
  c1_info[85].dominantType = "coder.internal.indexInt";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[85].fileTimeLo = 1286797178U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[86].name = "eml_index_minus";
  c1_info[86].dominantType = "double";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[86].fileTimeLo = 1286797178U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[87].name = "eml_index_plus";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[87].fileTimeLo = 1286797178U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[88].name = "eml_index_times";
  c1_info[88].dominantType = "coder.internal.indexInt";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[88].fileTimeLo = 1286797180U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[89].name = "eml_index_minus";
  c1_info[89].dominantType = "coder.internal.indexInt";
  c1_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[89].fileTimeLo = 1286797178U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 0U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[90].name = "eml_ixamax";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[90].fileTimeLo = 1299051570U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[91].name = "eml_blas_inline";
  c1_info[91].dominantType = "";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[91].fileTimeLo = 1299051568U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c1_info[92].name = "length";
  c1_info[92].dominantType = "double";
  c1_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[92].fileTimeLo = 1303124606U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[93].name = "eml_index_class";
  c1_info[93].dominantType = "";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[93].fileTimeLo = 1323145378U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[94].name = "eml_refblas_ixamax";
  c1_info[94].dominantType = "double";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[94].fileTimeLo = 1299051570U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[95].name = "eml_index_class";
  c1_info[95].dominantType = "";
  c1_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[95].fileTimeLo = 1323145378U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[96].name = "eml_xcabs1";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[96].fileTimeLo = 1286797106U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[97].name = "abs";
  c1_info[97].dominantType = "double";
  c1_info[97].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[97].fileTimeLo = 1343808766U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[98].name = "eml_int_forloop_overflow_check";
  c1_info[98].dominantType = "";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[98].fileTimeLo = 1346488740U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[99].name = "eml_index_plus";
  c1_info[99].dominantType = "coder.internal.indexInt";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[99].fileTimeLo = 1286797178U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[100].name = "eml_xswap";
  c1_info[100].dominantType = "double";
  c1_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[100].fileTimeLo = 1299051578U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[101].name = "eml_blas_inline";
  c1_info[101].dominantType = "";
  c1_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[101].fileTimeLo = 1299051568U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[102].name = "eml_index_class";
  c1_info[102].dominantType = "";
  c1_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[102].fileTimeLo = 1323145378U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[103].name = "eml_refblas_xswap";
  c1_info[103].dominantType = "double";
  c1_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[103].fileTimeLo = 1299051586U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[104].name = "eml_index_class";
  c1_info[104].dominantType = "";
  c1_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[104].fileTimeLo = 1323145378U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[105].name = "abs";
  c1_info[105].dominantType = "coder.internal.indexInt";
  c1_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[105].fileTimeLo = 1343808766U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[106].name = "eml_scalar_abs";
  c1_info[106].dominantType = "coder.internal.indexInt";
  c1_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[106].fileTimeLo = 1286797112U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[107].name = "eml_int_forloop_overflow_check";
  c1_info[107].dominantType = "";
  c1_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[107].fileTimeLo = 1346488740U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[108].name = "eml_index_plus";
  c1_info[108].dominantType = "coder.internal.indexInt";
  c1_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[108].fileTimeLo = 1286797178U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[109].name = "eml_matlab_zlarfg";
  c1_info[109].dominantType = "double";
  c1_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[109].fileTimeLo = 1286797222U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
  c1_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[110].name = "eml_scalar_eg";
  c1_info[110].dominantType = "double";
  c1_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[110].fileTimeLo = 1286797196U;
  c1_info[110].fileTimeHi = 0U;
  c1_info[110].mFileTimeLo = 0U;
  c1_info[110].mFileTimeHi = 0U;
  c1_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[111].name = "eml_xnrm2";
  c1_info[111].dominantType = "double";
  c1_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[111].fileTimeLo = 1299051576U;
  c1_info[111].fileTimeHi = 0U;
  c1_info[111].mFileTimeLo = 0U;
  c1_info[111].mFileTimeHi = 0U;
  c1_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c1_info[112].name = "length";
  c1_info[112].dominantType = "double";
  c1_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[112].fileTimeLo = 1303124606U;
  c1_info[112].fileTimeHi = 0U;
  c1_info[112].mFileTimeLo = 0U;
  c1_info[112].mFileTimeHi = 0U;
  c1_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c1_info[113].name = "eml_index_class";
  c1_info[113].dominantType = "";
  c1_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[113].fileTimeLo = 1323145378U;
  c1_info[113].fileTimeHi = 0U;
  c1_info[113].mFileTimeLo = 0U;
  c1_info[113].mFileTimeHi = 0U;
  c1_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[114].name = "eml_dlapy2";
  c1_info[114].dominantType = "double";
  c1_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[114].fileTimeLo = 1350389054U;
  c1_info[114].fileTimeHi = 0U;
  c1_info[114].mFileTimeLo = 0U;
  c1_info[114].mFileTimeHi = 0U;
  c1_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[115].name = "realmin";
  c1_info[115].dominantType = "char";
  c1_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[115].fileTimeLo = 1307629642U;
  c1_info[115].fileTimeHi = 0U;
  c1_info[115].mFileTimeLo = 0U;
  c1_info[115].mFileTimeHi = 0U;
  c1_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[116].name = "eps";
  c1_info[116].dominantType = "char";
  c1_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[116].fileTimeLo = 1326702796U;
  c1_info[116].fileTimeHi = 0U;
  c1_info[116].mFileTimeLo = 0U;
  c1_info[116].mFileTimeHi = 0U;
  c1_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[117].name = "abs";
  c1_info[117].dominantType = "double";
  c1_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[117].fileTimeLo = 1343808766U;
  c1_info[117].fileTimeHi = 0U;
  c1_info[117].mFileTimeLo = 0U;
  c1_info[117].mFileTimeHi = 0U;
  c1_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[118].name = "eml_index_class";
  c1_info[118].dominantType = "";
  c1_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[118].fileTimeLo = 1323145378U;
  c1_info[118].fileTimeHi = 0U;
  c1_info[118].mFileTimeLo = 0U;
  c1_info[118].mFileTimeHi = 0U;
  c1_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[119].name = "eml_index_plus";
  c1_info[119].dominantType = "double";
  c1_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[119].fileTimeLo = 1286797178U;
  c1_info[119].fileTimeHi = 0U;
  c1_info[119].mFileTimeLo = 0U;
  c1_info[119].mFileTimeHi = 0U;
  c1_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[120].name = "eml_xscal";
  c1_info[120].dominantType = "double";
  c1_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[120].fileTimeLo = 1299051576U;
  c1_info[120].fileTimeHi = 0U;
  c1_info[120].mFileTimeLo = 0U;
  c1_info[120].mFileTimeHi = 0U;
  c1_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[121].name = "eml_blas_inline";
  c1_info[121].dominantType = "";
  c1_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[121].fileTimeLo = 1299051568U;
  c1_info[121].fileTimeHi = 0U;
  c1_info[121].mFileTimeLo = 0U;
  c1_info[121].mFileTimeHi = 0U;
  c1_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c1_info[122].name = "length";
  c1_info[122].dominantType = "double";
  c1_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[122].fileTimeLo = 1303124606U;
  c1_info[122].fileTimeHi = 0U;
  c1_info[122].mFileTimeLo = 0U;
  c1_info[122].mFileTimeHi = 0U;
  c1_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[123].name = "eml_index_class";
  c1_info[123].dominantType = "";
  c1_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[123].fileTimeLo = 1323145378U;
  c1_info[123].fileTimeHi = 0U;
  c1_info[123].mFileTimeLo = 0U;
  c1_info[123].mFileTimeHi = 0U;
  c1_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[124].name = "eml_scalar_eg";
  c1_info[124].dominantType = "double";
  c1_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[124].fileTimeLo = 1286797196U;
  c1_info[124].fileTimeHi = 0U;
  c1_info[124].mFileTimeLo = 0U;
  c1_info[124].mFileTimeHi = 0U;
  c1_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[125].name = "eml_refblas_xscal";
  c1_info[125].dominantType = "double";
  c1_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[125].fileTimeLo = 1299051584U;
  c1_info[125].fileTimeHi = 0U;
  c1_info[125].mFileTimeLo = 0U;
  c1_info[125].mFileTimeHi = 0U;
  c1_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[126].name = "eml_index_class";
  c1_info[126].dominantType = "";
  c1_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[126].fileTimeLo = 1323145378U;
  c1_info[126].fileTimeHi = 0U;
  c1_info[126].mFileTimeLo = 0U;
  c1_info[126].mFileTimeHi = 0U;
  c1_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[127].name = "eml_index_minus";
  c1_info[127].dominantType = "double";
  c1_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[127].fileTimeLo = 1286797178U;
  c1_info[127].fileTimeHi = 0U;
  c1_info[127].mFileTimeLo = 0U;
  c1_info[127].mFileTimeHi = 0U;
}

static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[201])
{
  c1_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[128].name = "eml_index_times";
  c1_info[128].dominantType = "coder.internal.indexInt";
  c1_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[128].fileTimeLo = 1286797180U;
  c1_info[128].fileTimeHi = 0U;
  c1_info[128].mFileTimeLo = 0U;
  c1_info[128].mFileTimeHi = 0U;
  c1_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[129].name = "eml_index_plus";
  c1_info[129].dominantType = "coder.internal.indexInt";
  c1_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[129].fileTimeLo = 1286797178U;
  c1_info[129].fileTimeHi = 0U;
  c1_info[129].mFileTimeLo = 0U;
  c1_info[129].mFileTimeHi = 0U;
  c1_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[130].name = "eml_int_forloop_overflow_check";
  c1_info[130].dominantType = "";
  c1_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[130].fileTimeLo = 1346488740U;
  c1_info[130].fileTimeHi = 0U;
  c1_info[130].mFileTimeLo = 0U;
  c1_info[130].mFileTimeHi = 0U;
  c1_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[131].name = "mtimes";
  c1_info[131].dominantType = "double";
  c1_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[131].fileTimeLo = 1289494492U;
  c1_info[131].fileTimeHi = 0U;
  c1_info[131].mFileTimeLo = 0U;
  c1_info[131].mFileTimeHi = 0U;
  c1_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[132].name = "eml_div";
  c1_info[132].dominantType = "double";
  c1_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[132].fileTimeLo = 1313326210U;
  c1_info[132].fileTimeHi = 0U;
  c1_info[132].mFileTimeLo = 0U;
  c1_info[132].mFileTimeHi = 0U;
  c1_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[133].name = "eml_int_forloop_overflow_check";
  c1_info[133].dominantType = "";
  c1_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[133].fileTimeLo = 1346488740U;
  c1_info[133].fileTimeHi = 0U;
  c1_info[133].mFileTimeLo = 0U;
  c1_info[133].mFileTimeHi = 0U;
  c1_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[134].name = "eml_matlab_zlarf";
  c1_info[134].dominantType = "char";
  c1_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[134].fileTimeLo = 1286797222U;
  c1_info[134].fileTimeHi = 0U;
  c1_info[134].mFileTimeLo = 0U;
  c1_info[134].mFileTimeHi = 0U;
  c1_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[135].name = "eml_scalar_eg";
  c1_info[135].dominantType = "double";
  c1_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[135].fileTimeLo = 1286797196U;
  c1_info[135].fileTimeHi = 0U;
  c1_info[135].mFileTimeLo = 0U;
  c1_info[135].mFileTimeHi = 0U;
  c1_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[136].name = "eml_index_class";
  c1_info[136].dominantType = "";
  c1_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[136].fileTimeLo = 1323145378U;
  c1_info[136].fileTimeHi = 0U;
  c1_info[136].mFileTimeLo = 0U;
  c1_info[136].mFileTimeHi = 0U;
  c1_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[137].name = "isequal";
  c1_info[137].dominantType = "double";
  c1_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[137].fileTimeLo = 1286797158U;
  c1_info[137].fileTimeHi = 0U;
  c1_info[137].mFileTimeLo = 0U;
  c1_info[137].mFileTimeHi = 0U;
  c1_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[138].name = "coder.internal.indexIntRelop";
  c1_info[138].dominantType = "";
  c1_info[138].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c1_info[138].fileTimeLo = 1326703122U;
  c1_info[138].fileTimeHi = 0U;
  c1_info[138].mFileTimeLo = 0U;
  c1_info[138].mFileTimeHi = 0U;
  c1_info[139].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c1_info[139].name = "eml_float_model";
  c1_info[139].dominantType = "char";
  c1_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[139].fileTimeLo = 1326702796U;
  c1_info[139].fileTimeHi = 0U;
  c1_info[139].mFileTimeLo = 0U;
  c1_info[139].mFileTimeHi = 0U;
  c1_info[140].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c1_info[140].name = "intmin";
  c1_info[140].dominantType = "char";
  c1_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[140].fileTimeLo = 1311233718U;
  c1_info[140].fileTimeHi = 0U;
  c1_info[140].mFileTimeLo = 0U;
  c1_info[140].mFileTimeHi = 0U;
  c1_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[141].name = "eml_index_minus";
  c1_info[141].dominantType = "double";
  c1_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[141].fileTimeLo = 1286797178U;
  c1_info[141].fileTimeHi = 0U;
  c1_info[141].mFileTimeLo = 0U;
  c1_info[141].mFileTimeHi = 0U;
  c1_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[142].name = "eml_index_times";
  c1_info[142].dominantType = "double";
  c1_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[142].fileTimeLo = 1286797180U;
  c1_info[142].fileTimeHi = 0U;
  c1_info[142].mFileTimeLo = 0U;
  c1_info[142].mFileTimeHi = 0U;
  c1_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[143].name = "eml_index_plus";
  c1_info[143].dominantType = "coder.internal.indexInt";
  c1_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[143].fileTimeLo = 1286797178U;
  c1_info[143].fileTimeHi = 0U;
  c1_info[143].mFileTimeLo = 0U;
  c1_info[143].mFileTimeHi = 0U;
  c1_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[144].name = "eml_index_class";
  c1_info[144].dominantType = "";
  c1_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[144].fileTimeLo = 1323145378U;
  c1_info[144].fileTimeHi = 0U;
  c1_info[144].mFileTimeLo = 0U;
  c1_info[144].mFileTimeHi = 0U;
  c1_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[145].name = "eml_index_minus";
  c1_info[145].dominantType = "double";
  c1_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[145].fileTimeLo = 1286797178U;
  c1_info[145].fileTimeHi = 0U;
  c1_info[145].mFileTimeLo = 0U;
  c1_info[145].mFileTimeHi = 0U;
  c1_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[146].name = "eml_index_times";
  c1_info[146].dominantType = "coder.internal.indexInt";
  c1_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[146].fileTimeLo = 1286797180U;
  c1_info[146].fileTimeHi = 0U;
  c1_info[146].mFileTimeLo = 0U;
  c1_info[146].mFileTimeHi = 0U;
  c1_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[147].name = "eml_index_plus";
  c1_info[147].dominantType = "coder.internal.indexInt";
  c1_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[147].fileTimeLo = 1286797178U;
  c1_info[147].fileTimeHi = 0U;
  c1_info[147].mFileTimeLo = 0U;
  c1_info[147].mFileTimeHi = 0U;
  c1_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[148].name = "eml_int_forloop_overflow_check";
  c1_info[148].dominantType = "";
  c1_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[148].fileTimeLo = 1346488740U;
  c1_info[148].fileTimeHi = 0U;
  c1_info[148].mFileTimeLo = 0U;
  c1_info[148].mFileTimeHi = 0U;
  c1_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[149].name = "eml_xgemv";
  c1_info[149].dominantType = "char";
  c1_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c1_info[149].fileTimeLo = 1299051574U;
  c1_info[149].fileTimeHi = 0U;
  c1_info[149].mFileTimeLo = 0U;
  c1_info[149].mFileTimeHi = 0U;
  c1_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c1_info[150].name = "eml_blas_inline";
  c1_info[150].dominantType = "";
  c1_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[150].fileTimeLo = 1299051568U;
  c1_info[150].fileTimeHi = 0U;
  c1_info[150].mFileTimeLo = 0U;
  c1_info[150].mFileTimeHi = 0U;
  c1_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold";
  c1_info[151].name = "length";
  c1_info[151].dominantType = "double";
  c1_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[151].fileTimeLo = 1303124606U;
  c1_info[151].fileTimeHi = 0U;
  c1_info[151].mFileTimeLo = 0U;
  c1_info[151].mFileTimeHi = 0U;
  c1_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold";
  c1_info[152].name = "min";
  c1_info[152].dominantType = "double";
  c1_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[152].fileTimeLo = 1311233718U;
  c1_info[152].fileTimeHi = 0U;
  c1_info[152].mFileTimeLo = 0U;
  c1_info[152].mFileTimeHi = 0U;
  c1_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m!below_threshold";
  c1_info[153].name = "mtimes";
  c1_info[153].dominantType = "double";
  c1_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[153].fileTimeLo = 1289494492U;
  c1_info[153].fileTimeHi = 0U;
  c1_info[153].mFileTimeLo = 0U;
  c1_info[153].mFileTimeHi = 0U;
  c1_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[154].name = "eml_index_class";
  c1_info[154].dominantType = "";
  c1_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[154].fileTimeLo = 1323145378U;
  c1_info[154].fileTimeHi = 0U;
  c1_info[154].mFileTimeLo = 0U;
  c1_info[154].mFileTimeHi = 0U;
  c1_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[155].name = "eml_scalar_eg";
  c1_info[155].dominantType = "double";
  c1_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[155].fileTimeLo = 1286797196U;
  c1_info[155].fileTimeHi = 0U;
  c1_info[155].mFileTimeLo = 0U;
  c1_info[155].mFileTimeHi = 0U;
  c1_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[156].name = "eml_refblas_xgemv";
  c1_info[156].dominantType = "char";
  c1_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[156].fileTimeLo = 1299051576U;
  c1_info[156].fileTimeHi = 0U;
  c1_info[156].mFileTimeLo = 0U;
  c1_info[156].mFileTimeHi = 0U;
  c1_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[157].name = "eml_index_minus";
  c1_info[157].dominantType = "double";
  c1_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[157].fileTimeLo = 1286797178U;
  c1_info[157].fileTimeHi = 0U;
  c1_info[157].mFileTimeLo = 0U;
  c1_info[157].mFileTimeHi = 0U;
  c1_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[158].name = "eml_index_class";
  c1_info[158].dominantType = "";
  c1_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[158].fileTimeLo = 1323145378U;
  c1_info[158].fileTimeHi = 0U;
  c1_info[158].mFileTimeLo = 0U;
  c1_info[158].mFileTimeHi = 0U;
  c1_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[159].name = "eml_index_times";
  c1_info[159].dominantType = "coder.internal.indexInt";
  c1_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[159].fileTimeLo = 1286797180U;
  c1_info[159].fileTimeHi = 0U;
  c1_info[159].mFileTimeLo = 0U;
  c1_info[159].mFileTimeHi = 0U;
  c1_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[160].name = "eml_index_plus";
  c1_info[160].dominantType = "coder.internal.indexInt";
  c1_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[160].fileTimeLo = 1286797178U;
  c1_info[160].fileTimeHi = 0U;
  c1_info[160].mFileTimeLo = 0U;
  c1_info[160].mFileTimeHi = 0U;
  c1_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[161].name = "eml_int_forloop_overflow_check";
  c1_info[161].dominantType = "";
  c1_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[161].fileTimeLo = 1346488740U;
  c1_info[161].fileTimeHi = 0U;
  c1_info[161].mFileTimeLo = 0U;
  c1_info[161].mFileTimeHi = 0U;
  c1_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[162].name = "eml_scalar_eg";
  c1_info[162].dominantType = "double";
  c1_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[162].fileTimeLo = 1286797196U;
  c1_info[162].fileTimeHi = 0U;
  c1_info[162].mFileTimeLo = 0U;
  c1_info[162].mFileTimeHi = 0U;
  c1_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[163].name = "eml_conjtimes";
  c1_info[163].dominantType = "double";
  c1_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c1_info[163].fileTimeLo = 1286797096U;
  c1_info[163].fileTimeHi = 0U;
  c1_info[163].mFileTimeLo = 0U;
  c1_info[163].mFileTimeHi = 0U;
  c1_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[164].name = "eml_xgerc";
  c1_info[164].dominantType = "double";
  c1_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[164].fileTimeLo = 1299051574U;
  c1_info[164].fileTimeHi = 0U;
  c1_info[164].mFileTimeLo = 0U;
  c1_info[164].mFileTimeHi = 0U;
  c1_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[165].name = "eml_blas_inline";
  c1_info[165].dominantType = "";
  c1_info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[165].fileTimeLo = 1299051568U;
  c1_info[165].fileTimeHi = 0U;
  c1_info[165].mFileTimeLo = 0U;
  c1_info[165].mFileTimeHi = 0U;
  c1_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[166].name = "eml_xger";
  c1_info[166].dominantType = "double";
  c1_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[166].fileTimeLo = 1299051574U;
  c1_info[166].fileTimeHi = 0U;
  c1_info[166].mFileTimeLo = 0U;
  c1_info[166].mFileTimeHi = 0U;
  c1_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[167].name = "eml_blas_inline";
  c1_info[167].dominantType = "";
  c1_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[167].fileTimeLo = 1299051568U;
  c1_info[167].fileTimeHi = 0U;
  c1_info[167].mFileTimeLo = 0U;
  c1_info[167].mFileTimeHi = 0U;
  c1_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[168].name = "intmax";
  c1_info[168].dominantType = "char";
  c1_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[168].fileTimeLo = 1311233716U;
  c1_info[168].fileTimeHi = 0U;
  c1_info[168].mFileTimeLo = 0U;
  c1_info[168].mFileTimeHi = 0U;
  c1_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[169].name = "min";
  c1_info[169].dominantType = "double";
  c1_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[169].fileTimeLo = 1311233718U;
  c1_info[169].fileTimeHi = 0U;
  c1_info[169].mFileTimeLo = 0U;
  c1_info[169].mFileTimeHi = 0U;
  c1_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[170].name = "length";
  c1_info[170].dominantType = "double";
  c1_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[170].fileTimeLo = 1303124606U;
  c1_info[170].fileTimeHi = 0U;
  c1_info[170].mFileTimeLo = 0U;
  c1_info[170].mFileTimeHi = 0U;
  c1_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[171].name = "mtimes";
  c1_info[171].dominantType = "double";
  c1_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[171].fileTimeLo = 1289494492U;
  c1_info[171].fileTimeHi = 0U;
  c1_info[171].mFileTimeLo = 0U;
  c1_info[171].mFileTimeHi = 0U;
  c1_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[172].name = "eml_index_class";
  c1_info[172].dominantType = "";
  c1_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[172].fileTimeLo = 1323145378U;
  c1_info[172].fileTimeHi = 0U;
  c1_info[172].mFileTimeLo = 0U;
  c1_info[172].mFileTimeHi = 0U;
  c1_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[173].name = "eml_refblas_xger";
  c1_info[173].dominantType = "double";
  c1_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[173].fileTimeLo = 1299051576U;
  c1_info[173].fileTimeHi = 0U;
  c1_info[173].mFileTimeLo = 0U;
  c1_info[173].mFileTimeHi = 0U;
  c1_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[174].name = "eml_refblas_xgerx";
  c1_info[174].dominantType = "char";
  c1_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[174].fileTimeLo = 1299051578U;
  c1_info[174].fileTimeHi = 0U;
  c1_info[174].mFileTimeLo = 0U;
  c1_info[174].mFileTimeHi = 0U;
  c1_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[175].name = "eml_index_class";
  c1_info[175].dominantType = "";
  c1_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[175].fileTimeLo = 1323145378U;
  c1_info[175].fileTimeHi = 0U;
  c1_info[175].mFileTimeLo = 0U;
  c1_info[175].mFileTimeHi = 0U;
  c1_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[176].name = "abs";
  c1_info[176].dominantType = "coder.internal.indexInt";
  c1_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[176].fileTimeLo = 1343808766U;
  c1_info[176].fileTimeHi = 0U;
  c1_info[176].mFileTimeLo = 0U;
  c1_info[176].mFileTimeHi = 0U;
  c1_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[177].name = "eml_index_minus";
  c1_info[177].dominantType = "double";
  c1_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[177].fileTimeLo = 1286797178U;
  c1_info[177].fileTimeHi = 0U;
  c1_info[177].mFileTimeLo = 0U;
  c1_info[177].mFileTimeHi = 0U;
  c1_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[178].name = "eml_int_forloop_overflow_check";
  c1_info[178].dominantType = "";
  c1_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[178].fileTimeLo = 1346488740U;
  c1_info[178].fileTimeHi = 0U;
  c1_info[178].mFileTimeLo = 0U;
  c1_info[178].mFileTimeHi = 0U;
  c1_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[179].name = "eml_index_plus";
  c1_info[179].dominantType = "double";
  c1_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[179].fileTimeLo = 1286797178U;
  c1_info[179].fileTimeHi = 0U;
  c1_info[179].mFileTimeLo = 0U;
  c1_info[179].mFileTimeHi = 0U;
  c1_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[180].name = "eml_index_plus";
  c1_info[180].dominantType = "coder.internal.indexInt";
  c1_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[180].fileTimeLo = 1286797178U;
  c1_info[180].fileTimeHi = 0U;
  c1_info[180].mFileTimeLo = 0U;
  c1_info[180].mFileTimeHi = 0U;
  c1_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[181].name = "abs";
  c1_info[181].dominantType = "double";
  c1_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[181].fileTimeLo = 1343808766U;
  c1_info[181].fileTimeHi = 0U;
  c1_info[181].mFileTimeLo = 0U;
  c1_info[181].mFileTimeHi = 0U;
  c1_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[182].name = "mtimes";
  c1_info[182].dominantType = "double";
  c1_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[182].fileTimeLo = 1289494492U;
  c1_info[182].fileTimeHi = 0U;
  c1_info[182].mFileTimeLo = 0U;
  c1_info[182].mFileTimeHi = 0U;
  c1_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[183].name = "max";
  c1_info[183].dominantType = "double";
  c1_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[183].fileTimeLo = 1311233716U;
  c1_info[183].fileTimeHi = 0U;
  c1_info[183].mFileTimeLo = 0U;
  c1_info[183].mFileTimeHi = 0U;
  c1_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[184].name = "eml_min_or_max";
  c1_info[184].dominantType = "char";
  c1_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[184].fileTimeLo = 1334049890U;
  c1_info[184].fileTimeHi = 0U;
  c1_info[184].mFileTimeLo = 0U;
  c1_info[184].mFileTimeHi = 0U;
  c1_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[185].name = "eml_xcabs1";
  c1_info[185].dominantType = "double";
  c1_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[185].fileTimeLo = 1286797106U;
  c1_info[185].fileTimeHi = 0U;
  c1_info[185].mFileTimeLo = 0U;
  c1_info[185].mFileTimeHi = 0U;
  c1_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[186].name = "mtimes";
  c1_info[186].dominantType = "double";
  c1_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[186].fileTimeLo = 1289494492U;
  c1_info[186].fileTimeHi = 0U;
  c1_info[186].mFileTimeLo = 0U;
  c1_info[186].mFileTimeHi = 0U;
  c1_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[187].name = "eps";
  c1_info[187].dominantType = "char";
  c1_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[187].fileTimeLo = 1326702796U;
  c1_info[187].fileTimeHi = 0U;
  c1_info[187].mFileTimeLo = 0U;
  c1_info[187].mFileTimeHi = 0U;
  c1_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[188].name = "eml_flt2str";
  c1_info[188].dominantType = "double";
  c1_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[188].fileTimeLo = 1309429596U;
  c1_info[188].fileTimeHi = 0U;
  c1_info[188].mFileTimeLo = 0U;
  c1_info[188].mFileTimeHi = 0U;
  c1_info[189].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[189].name = "char";
  c1_info[189].dominantType = "double";
  c1_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[189].fileTimeLo = 1319708368U;
  c1_info[189].fileTimeHi = 0U;
  c1_info[189].mFileTimeLo = 0U;
  c1_info[189].mFileTimeHi = 0U;
  c1_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[190].name = "eml_warning";
  c1_info[190].dominantType = "char";
  c1_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[190].fileTimeLo = 1286797202U;
  c1_info[190].fileTimeHi = 0U;
  c1_info[190].mFileTimeLo = 0U;
  c1_info[190].mFileTimeHi = 0U;
  c1_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[191].name = "eml_scalar_eg";
  c1_info[191].dominantType = "double";
  c1_info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[191].fileTimeLo = 1286797196U;
  c1_info[191].fileTimeHi = 0U;
  c1_info[191].mFileTimeLo = 0U;
  c1_info[191].mFileTimeHi = 0U;
}

static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[201])
{
  c1_info[192].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[192].name = "eml_conjtimes";
  c1_info[192].dominantType = "double";
  c1_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c1_info[192].fileTimeLo = 1286797096U;
  c1_info[192].fileTimeHi = 0U;
  c1_info[192].mFileTimeLo = 0U;
  c1_info[192].mFileTimeHi = 0U;
  c1_info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[193].name = "eml_div";
  c1_info[193].dominantType = "double";
  c1_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[193].fileTimeLo = 1313326210U;
  c1_info[193].fileTimeHi = 0U;
  c1_info[193].mFileTimeLo = 0U;
  c1_info[193].mFileTimeHi = 0U;
  c1_info[194].context = "";
  c1_info[194].name = "mtimes";
  c1_info[194].dominantType = "double";
  c1_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[194].fileTimeLo = 1289494492U;
  c1_info[194].fileTimeHi = 0U;
  c1_info[194].mFileTimeLo = 0U;
  c1_info[194].mFileTimeHi = 0U;
  c1_info[195].context = "";
  c1_info[195].name = "mpower";
  c1_info[195].dominantType = "double";
  c1_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[195].fileTimeLo = 1286797242U;
  c1_info[195].fileTimeHi = 0U;
  c1_info[195].mFileTimeLo = 0U;
  c1_info[195].mFileTimeHi = 0U;
  c1_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[196].name = "power";
  c1_info[196].dominantType = "double";
  c1_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[196].fileTimeLo = 1348170330U;
  c1_info[196].fileTimeHi = 0U;
  c1_info[196].mFileTimeLo = 0U;
  c1_info[196].mFileTimeHi = 0U;
  c1_info[197].context = "";
  c1_info[197].name = "mrdivide";
  c1_info[197].dominantType = "double";
  c1_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[197].fileTimeLo = 1357926348U;
  c1_info[197].fileTimeHi = 0U;
  c1_info[197].mFileTimeLo = 1319708366U;
  c1_info[197].mFileTimeHi = 0U;
  c1_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[198].name = "rdivide";
  c1_info[198].dominantType = "double";
  c1_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[198].fileTimeLo = 1346488788U;
  c1_info[198].fileTimeHi = 0U;
  c1_info[198].mFileTimeLo = 0U;
  c1_info[198].mFileTimeHi = 0U;
  c1_info[199].context = "";
  c1_info[199].name = "sqrt";
  c1_info[199].dominantType = "double";
  c1_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[199].fileTimeLo = 1343808786U;
  c1_info[199].fileTimeHi = 0U;
  c1_info[199].mFileTimeLo = 0U;
  c1_info[199].mFileTimeHi = 0U;
  c1_info[200].context = "";
  c1_info[200].name = "length";
  c1_info[200].dominantType = "uint32";
  c1_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[200].fileTimeLo = 1303124606U;
  c1_info[200].fileTimeHi = 0U;
  c1_info[200].mFileTimeLo = 0U;
  c1_info[200].mFileTimeHi = 0U;
}

static void c1_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i53;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i54;
  static char_T c1_cv1[6] = { 'u', 'i', 'n', 't', '3', '2' };

  char_T c1_b_u[6];
  const mxArray *c1_b_y = NULL;
  for (c1_i53 = 0; c1_i53 < 34; c1_i53++) {
    c1_u[c1_i53] = c1_cv0[c1_i53];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  for (c1_i54 = 0; c1_i54 < 6; c1_i54++) {
    c1_b_u[c1_i54] = c1_cv1[c1_i54];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static void c1_eml_find(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, boolean_T c1_x[345600], int32_T c1_i_data[345600], int32_T
  c1_i_sizes[1], int32_T c1_j_data[345600], int32_T c1_j_sizes[1])
{
  int32_T c1_idx;
  static int32_T c1_iv0[1] = { 345600 };

  int32_T c1_ii;
  int32_T c1_jj;
  int32_T c1_a;
  int32_T c1_b_a;
  int32_T c1_c_a;
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  int32_T c1_i55;
  int32_T c1_tmp_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i56;
  static int32_T c1_tmp_data[345600];
  int32_T c1_b_i_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i57;
  static int32_T c1_b_i_data[345600];
  int32_T c1_c_loop_ub;
  int32_T c1_i58;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  int32_T c1_i59;
  int32_T c1_d_loop_ub;
  int32_T c1_i60;
  int32_T c1_b_j_sizes;
  int32_T c1_e_loop_ub;
  int32_T c1_i61;
  static int32_T c1_b_j_data[345600];
  int32_T c1_f_loop_ub;
  int32_T c1_i62;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  int32_T c1_i63;
  int32_T c1_g_loop_ub;
  int32_T c1_i64;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  c1_eml_scalar_eg(chartInstance);
  c1_idx = 0;
  c1_i_sizes[0] = c1_iv0[0];
  c1_j_sizes[0] = c1_iv0[0];
  c1_ii = 1;
  c1_jj = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_jj <= 720)) {
    guard1 = FALSE;
    if (c1_x[(c1_ii + 480 * (c1_jj - 1)) - 1]) {
      c1_a = c1_idx + 1;
      c1_idx = c1_a;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 345600) {
        exitg1 = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      c1_b_a = c1_ii + 1;
      c1_ii = c1_b_a;
      if (c1_ii > 480) {
        c1_ii = 1;
        c1_c_a = c1_jj + 1;
        c1_jj = c1_c_a;
      }
    }
  }

  c1_b0 = (1 > c1_idx);
  c1_b1 = c1_b0;
  c1_b2 = c1_b1;
  if (c1_b2) {
    c1_i55 = 0;
  } else {
    c1_i55 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 345600, 0, 0);
  }

  c1_tmp_sizes = c1_i55;
  c1_loop_ub = c1_i55 - 1;
  for (c1_i56 = 0; c1_i56 <= c1_loop_ub; c1_i56++) {
    c1_tmp_data[c1_i56] = 1 + c1_i56;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(345600, 1, 1, c1_tmp_sizes);
  c1_b_i_sizes = c1_tmp_sizes;
  c1_b_loop_ub = c1_tmp_sizes - 1;
  for (c1_i57 = 0; c1_i57 <= c1_b_loop_ub; c1_i57++) {
    c1_b_i_data[c1_i57] = c1_i_data[c1_tmp_data[c1_i57] - 1];
  }

  c1_i_sizes[0] = c1_b_i_sizes;
  c1_c_loop_ub = c1_b_i_sizes - 1;
  for (c1_i58 = 0; c1_i58 <= c1_c_loop_ub; c1_i58++) {
    c1_i_data[c1_i58] = c1_b_i_data[c1_i58];
  }

  c1_b3 = (1 > c1_idx);
  c1_b4 = c1_b3;
  c1_b5 = c1_b4;
  if (c1_b5) {
    c1_i59 = 0;
  } else {
    c1_i59 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 345600, 0, 0);
  }

  c1_tmp_sizes = c1_i59;
  c1_d_loop_ub = c1_i59 - 1;
  for (c1_i60 = 0; c1_i60 <= c1_d_loop_ub; c1_i60++) {
    c1_tmp_data[c1_i60] = 1 + c1_i60;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(345600, 1, 1, c1_tmp_sizes);
  c1_b_j_sizes = c1_tmp_sizes;
  c1_e_loop_ub = c1_tmp_sizes - 1;
  for (c1_i61 = 0; c1_i61 <= c1_e_loop_ub; c1_i61++) {
    c1_b_j_data[c1_i61] = c1_j_data[c1_tmp_data[c1_i61] - 1];
  }

  c1_j_sizes[0] = c1_b_j_sizes;
  c1_f_loop_ub = c1_b_j_sizes - 1;
  for (c1_i62 = 0; c1_i62 <= c1_f_loop_ub; c1_i62++) {
    c1_j_data[c1_i62] = c1_b_j_data[c1_i62];
  }

  c1_b6 = (1 > c1_idx);
  c1_b7 = c1_b6;
  c1_b8 = c1_b7;
  if (c1_b8) {
    c1_i63 = 0;
  } else {
    c1_i63 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 345600, 0, 0);
  }

  c1_tmp_sizes = c1_i63;
  c1_g_loop_ub = c1_i63 - 1;
  for (c1_i64 = 0; c1_i64 <= c1_g_loop_ub; c1_i64++) {
    c1_tmp_data[c1_i64] = 1 + c1_i64;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(345600, 1, 1, c1_tmp_sizes);
}

static void c1_eml_scalar_eg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance)
{
}

static real_T c1_mean(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T c1_x_data[345600], int32_T c1_x_sizes[1])
{
  boolean_T c1_p;
  boolean_T c1_b_p;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_d1;
  real_T c1_d2;
  boolean_T c1_b9;
  boolean_T c1_c_p;
  boolean_T c1_b10;
  int32_T c1_i65;
  static char_T c1_cv2[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  char_T c1_u[31];
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b11;
  int32_T c1_i66;
  static char_T c1_cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  char_T c1_b_u[36];
  const mxArray *c1_c_y = NULL;
  real_T c1_d_y;
  int32_T c1_vlen;
  int32_T c1_b_vlen;
  int32_T c1_b;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_c_k;
  int32_T c1_d_k;
  real_T c1_x;
  real_T c1_e_y;
  real_T c1_b_x;
  real_T c1_f_y;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  c1_p = FALSE;
  c1_b_p = FALSE;
  c1_k = 0;
  do {
    exitg1 = 0;
    if (c1_k < 2) {
      c1_b_k = 1.0 + (real_T)c1_k;
      c1_d1 = c1_b_k;
      if (c1_d1 <= 1.0) {
        c1_d2 = (real_T)c1_x_sizes[0];
      } else {
        c1_d2 = 1.0;
      }

      if (c1_d2 != 0.0) {
        exitg1 = 1;
      } else {
        c1_k++;
      }
    } else {
      c1_b_p = TRUE;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  c1_b9 = c1_b_p;
  c1_c_p = c1_b9;
  if (!c1_c_p) {
  } else {
    c1_p = TRUE;
  }

  c1_b10 = !c1_p;
  if (c1_b10) {
  } else {
    for (c1_i65 = 0; c1_i65 < 31; c1_i65++) {
      c1_u[c1_i65] = c1_cv2[c1_i65];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 31),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c1_b_y));
  }

  guard1 = FALSE;
  if (c1_x_sizes[0] == 1) {
    guard1 = TRUE;
  } else if ((real_T)c1_x_sizes[0] != 1.0) {
    guard1 = TRUE;
  } else {
    c1_b11 = FALSE;
  }

  if (guard1 == TRUE) {
    c1_b11 = TRUE;
  }

  if (c1_b11) {
  } else {
    for (c1_i66 = 0; c1_i66 < 36; c1_i66++) {
      c1_b_u[c1_i66] = c1_cv3[c1_i66];
    }

    c1_c_y = NULL;
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c1_c_y));
  }

  if (c1_x_sizes[0] == 0) {
    c1_d_y = 0.0;
  } else {
    c1_vlen = (int32_T)(real_T)c1_x_sizes[0];
    c1_d_y = c1_x_data[0];
    c1_b_vlen = c1_vlen;
    c1_b = c1_b_vlen;
    c1_b_b = c1_b;
    if (2 > c1_b_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_c_k = 2; c1_c_k <= c1_b_vlen; c1_c_k++) {
      c1_d_k = c1_c_k;
      c1_d_y += c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_d_k, 1, c1_x_sizes
        [0], 1, 0) - 1];
    }
  }

  c1_x = c1_d_y;
  c1_e_y = (real_T)c1_x_sizes[0];
  c1_b_x = c1_x;
  c1_f_y = c1_e_y;
  return c1_b_x / c1_f_y;
}

static void c1_b_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i67;
  static char_T c1_cv4[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i68;
  static char_T c1_cv5[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c1_b_u[23];
  const mxArray *c1_b_y = NULL;
  for (c1_i67 = 0; c1_i67 < 34; c1_i67++) {
    c1_u[c1_i67] = c1_cv4[c1_i67];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  for (c1_i68 = 0; c1_i68 < 23; c1_i68++) {
    c1_b_u[c1_i68] = c1_cv5[c1_i68];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static void c1_power(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                     real_T c1_a[10], real_T c1_y[10])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_ak;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_b;
  real_T c1_b_y;
  for (c1_k = 0; c1_k < 10; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_ak = c1_a[(int32_T)c1_b_k - 1];
    c1_b_a = c1_ak;
    c1_b_eml_scalar_eg(chartInstance);
    c1_c_a = c1_b_a;
    c1_b = c1_b_a;
    c1_b_y = c1_c_a * c1_b;
    c1_y[(int32_T)c1_b_k - 1] = c1_b_y;
  }
}

static void c1_b_eml_scalar_eg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance)
{
}

static void c1_mldivide(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_A[30], real_T c1_B[10], real_T c1_Y[3])
{
  int32_T c1_i69;
  real_T c1_b_A[30];
  int32_T c1_i70;
  real_T c1_b_B[10];
  int32_T c1_i71;
  int32_T c1_jpvt[3];
  int32_T c1_i72;
  real_T c1_work[3];
  int32_T c1_k;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_i73;
  real_T c1_c_A[30];
  real_T c1_vn1[3];
  real_T c1_vn2[3];
  int32_T c1_a;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_b_a;
  int32_T c1_im1;
  int32_T c1_c_a;
  int32_T c1_ip1;
  int32_T c1_d_a;
  int32_T c1_c;
  int32_T c1_e_a;
  int32_T c1_b;
  int32_T c1_i_i;
  int32_T c1_b_b;
  int32_T c1_nmi;
  int32_T c1_c_b;
  int32_T c1_mmi;
  int32_T c1_d_b;
  int32_T c1_mmip1;
  int32_T c1_e_b;
  int32_T c1_nmip1;
  int32_T c1_f_a;
  int32_T c1_i74;
  real_T c1_b_vn1[3];
  int32_T c1_f_b;
  int32_T c1_pvt;
  int32_T c1_g_a;
  int32_T c1_b_c;
  int32_T c1_g_b;
  int32_T c1_c_c;
  int32_T c1_h_b;
  int32_T c1_pvtcol;
  int32_T c1_i_b;
  int32_T c1_d_c;
  int32_T c1_j_b;
  int32_T c1_mcol;
  int32_T c1_itemp;
  real_T c1_atmp;
  int32_T c1_h_a;
  int32_T c1_e_c;
  real_T c1_b_atmp;
  real_T c1_d3;
  real_T c1_tau[3];
  int32_T c1_i_a;
  int32_T c1_f_c;
  int32_T c1_j_a;
  int32_T c1_k_b;
  int32_T c1_i_ip1;
  int32_T c1_b_ip1;
  int32_T c1_c_j;
  int32_T c1_k_a;
  int32_T c1_g_c;
  int32_T c1_l_b;
  int32_T c1_h_c;
  int32_T c1_l_a;
  int32_T c1_m_b;
  int32_T c1_i_j;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_temp1;
  real_T c1_m_a;
  real_T c1_n_b;
  real_T c1_b_y;
  real_T c1_temp2;
  real_T c1_n_a;
  real_T c1_o_b;
  real_T c1_c_y;
  real_T c1_o_a;
  real_T c1_p_b;
  int32_T c1_p_a;
  int32_T c1_i_c;
  int32_T c1_i75;
  real_T c1_d_A[30];
  real_T c1_q_a;
  real_T c1_q_b;
  real_T c1_d_y;
  real_T c1_rankR;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_e_y;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_f_y;
  real_T c1_d;
  real_T c1_r_b;
  real_T c1_g_y;
  real_T c1_r_a;
  real_T c1_tol;
  int32_T c1_b_k;
  real_T c1_c_k;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_h_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_i_y;
  real_T c1_b_d;
  real_T c1_m_x;
  int32_T c1_i76;
  static char_T c1_cv6[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_u[8];
  const mxArray *c1_j_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_m_y = NULL;
  char_T c1_str[14];
  int32_T c1_i77;
  char_T c1_b_str[14];
  int32_T c1_i78;
  int32_T c1_d_j;
  real_T c1_e_j;
  real_T c1_tauj;
  real_T c1_wj;
  real_T c1_d4;
  int32_T c1_i79;
  int32_T c1_c_i;
  real_T c1_d_i;
  real_T c1_s_a;
  real_T c1_s_b;
  real_T c1_z;
  real_T c1_t_a;
  real_T c1_t_b;
  real_T c1_d5;
  int32_T c1_i80;
  int32_T c1_e_i;
  real_T c1_u_a;
  real_T c1_u_b;
  real_T c1_n_y;
  real_T c1_rr;
  real_T c1_b_rr;
  int32_T c1_i81;
  int32_T c1_f_i;
  real_T c1_c_rr;
  int32_T c1_i82;
  int32_T c1_f_j;
  int32_T c1_pj;
  real_T c1_n_x;
  real_T c1_o_y;
  real_T c1_b_z;
  real_T c1_d6;
  int32_T c1_i83;
  int32_T c1_g_i;
  real_T c1_v_a;
  real_T c1_v_b;
  real_T c1_p_y;
  boolean_T exitg1;
  for (c1_i69 = 0; c1_i69 < 30; c1_i69++) {
    c1_b_A[c1_i69] = c1_A[c1_i69];
  }

  for (c1_i70 = 0; c1_i70 < 10; c1_i70++) {
    c1_b_B[c1_i70] = c1_B[c1_i70];
  }

  for (c1_i71 = 0; c1_i71 < 3; c1_i71++) {
    c1_jpvt[c1_i71] = 1 + c1_i71;
  }

  for (c1_i72 = 0; c1_i72 < 3; c1_i72++) {
    c1_work[c1_i72] = 0.0;
  }

  c1_eps(chartInstance);
  c1_k = 1;
  for (c1_j = 1; c1_j < 4; c1_j++) {
    c1_b_j = c1_j - 1;
    for (c1_i73 = 0; c1_i73 < 30; c1_i73++) {
      c1_c_A[c1_i73] = c1_b_A[c1_i73];
    }

    c1_vn1[c1_b_j] = c1_eml_xnrm2(chartInstance, c1_c_A, c1_k);
    c1_vn2[c1_b_j] = c1_vn1[c1_b_j];
    c1_a = c1_k + 10;
    c1_k = c1_a;
  }

  for (c1_i = 1; c1_i < 4; c1_i++) {
    c1_b_i = c1_i;
    c1_b_a = c1_b_i - 1;
    c1_im1 = c1_b_a;
    c1_c_a = c1_b_i + 1;
    c1_ip1 = c1_c_a;
    c1_d_a = c1_im1;
    c1_c = c1_d_a * 10;
    c1_e_a = c1_b_i;
    c1_b = c1_c;
    c1_i_i = (c1_e_a + c1_b) - 1;
    c1_b_b = c1_b_i;
    c1_nmi = 3 - c1_b_b;
    c1_c_b = c1_b_i;
    c1_mmi = 10 - c1_c_b;
    c1_d_b = c1_mmi + 1;
    c1_mmip1 = c1_d_b;
    c1_e_b = c1_nmi + 1;
    c1_nmip1 = c1_e_b;
    c1_f_a = c1_im1;
    for (c1_i74 = 0; c1_i74 < 3; c1_i74++) {
      c1_b_vn1[c1_i74] = c1_vn1[c1_i74];
    }

    c1_f_b = c1_eml_ixamax(chartInstance, c1_nmip1, c1_b_vn1, c1_b_i);
    c1_pvt = c1_f_a + c1_f_b;
    if (c1_pvt != c1_b_i) {
      c1_g_a = c1_pvt - 1;
      c1_b_c = c1_g_a;
      c1_g_b = c1_b_c;
      c1_c_c = 10 * c1_g_b;
      c1_h_b = c1_c_c + 1;
      c1_pvtcol = c1_h_b;
      c1_i_b = c1_im1;
      c1_d_c = 10 * c1_i_b;
      c1_j_b = c1_d_c + 1;
      c1_mcol = c1_j_b;
      c1_b_eml_xswap(chartInstance, c1_b_A, c1_pvtcol, c1_mcol);
      c1_itemp = c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_pvt, 1, 3, 1, 0) - 1];
      c1_jpvt[c1_pvt - 1] = c1_jpvt[c1_b_i - 1];
      c1_jpvt[c1_b_i - 1] = c1_itemp;
      c1_vn1[c1_pvt - 1] = c1_vn1[c1_b_i - 1];
      c1_vn2[c1_pvt - 1] = c1_vn2[c1_b_i - 1];
    }

    c1_atmp = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i + 1, 1, 30, 1, 0) -
      1];
    c1_h_a = c1_i_i + 2;
    c1_e_c = c1_h_a;
    c1_b_atmp = c1_atmp;
    c1_d3 = c1_b_eml_matlab_zlarfg(chartInstance, c1_mmip1, &c1_b_atmp, c1_b_A,
      c1_e_c);
    c1_atmp = c1_b_atmp;
    c1_tau[c1_b_i - 1] = c1_d3;
    c1_b_A[c1_i_i] = c1_atmp;
    if (c1_b_i < 3) {
      c1_atmp = c1_b_A[c1_i_i];
      c1_b_A[c1_i_i] = 1.0;
      c1_i_a = c1_b_i;
      c1_f_c = c1_i_a * 10;
      c1_j_a = c1_b_i;
      c1_k_b = c1_f_c;
      c1_i_ip1 = c1_j_a + c1_k_b;
      c1_b_eml_matlab_zlarf(chartInstance, c1_mmip1, c1_nmi, c1_i_i + 1,
                            c1_tau[c1_b_i - 1], c1_b_A, c1_i_ip1, c1_work);
      c1_b_A[c1_i_i] = c1_atmp;
    }

    c1_b_ip1 = c1_ip1;
    for (c1_c_j = c1_b_ip1; c1_c_j < 4; c1_c_j++) {
      c1_b_j = c1_c_j - 1;
      c1_k_a = c1_b_j;
      c1_g_c = c1_k_a;
      c1_l_b = c1_g_c;
      c1_h_c = 10 * c1_l_b;
      c1_l_a = c1_b_i;
      c1_m_b = c1_h_c;
      c1_i_j = c1_l_a + c1_m_b;
      if (c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_j + 1, 1, 3, 1, 0) - 1] !=
          0.0) {
        c1_x = c1_b_A[(c1_b_i + 10 * c1_b_j) - 1];
        c1_b_x = c1_x;
        c1_y = muDoubleScalarAbs(c1_b_x);
        c1_temp1 = c1_y / c1_vn1[c1_b_j];
        c1_m_a = c1_temp1;
        c1_n_b = c1_temp1;
        c1_b_y = c1_m_a * c1_n_b;
        c1_temp1 = 1.0 - c1_b_y;
        if (c1_temp1 < 0.0) {
          c1_temp1 = 0.0;
        }

        c1_temp2 = c1_vn1[c1_b_j] / c1_vn2[c1_b_j];
        c1_n_a = c1_temp2;
        c1_o_b = c1_temp2;
        c1_c_y = c1_n_a * c1_o_b;
        c1_o_a = c1_temp1;
        c1_p_b = c1_c_y;
        c1_temp2 = c1_o_a * c1_p_b;
        if (c1_temp2 <= 1.4901161193847656E-8) {
          c1_p_a = c1_i_j + 1;
          c1_i_c = c1_p_a;
          for (c1_i75 = 0; c1_i75 < 30; c1_i75++) {
            c1_d_A[c1_i75] = c1_b_A[c1_i75];
          }

          c1_vn1[c1_b_j] = c1_c_eml_xnrm2(chartInstance, c1_mmi, c1_d_A, c1_i_c);
          c1_vn2[c1_b_j] = c1_vn1[c1_b_j];
        } else {
          c1_q_a = c1_vn1[c1_b_j];
          c1_q_b = c1_temp1;
          c1_b_sqrt(chartInstance, &c1_q_b);
          c1_d_y = c1_q_a * c1_q_b;
          c1_vn1[c1_b_j] = c1_d_y;
        }
      }
    }
  }

  c1_rankR = 0.0;
  c1_eps(chartInstance);
  c1_c_x = c1_b_A[0];
  c1_d_x = c1_c_x;
  c1_e_x = c1_d_x;
  c1_e_y = muDoubleScalarAbs(c1_e_x);
  c1_f_x = 0.0;
  c1_g_x = c1_f_x;
  c1_f_y = muDoubleScalarAbs(c1_g_x);
  c1_d = c1_e_y + c1_f_y;
  c1_r_b = c1_d;
  c1_g_y = 10.0 * c1_r_b;
  c1_r_a = c1_g_y;
  c1_tol = c1_r_a * 2.2204460492503131E-16;
  c1_b_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_b_k < 3)) {
    c1_c_k = 1.0 + (real_T)c1_b_k;
    c1_h_x = c1_b_A[((int32_T)c1_c_k + 10 * ((int32_T)c1_c_k - 1)) - 1];
    c1_i_x = c1_h_x;
    c1_j_x = c1_i_x;
    c1_h_y = muDoubleScalarAbs(c1_j_x);
    c1_k_x = 0.0;
    c1_l_x = c1_k_x;
    c1_i_y = muDoubleScalarAbs(c1_l_x);
    c1_b_d = c1_h_y + c1_i_y;
    if (c1_b_d <= c1_tol) {
      c1_m_x = c1_tol;
      for (c1_i76 = 0; c1_i76 < 8; c1_i76++) {
        c1_u[c1_i76] = c1_cv6[c1_i76];
      }

      c1_j_y = NULL;
      sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c1_b_u = 14.0;
      c1_k_y = NULL;
      sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_c_u = 6.0;
      c1_l_y = NULL;
      sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_d_u = c1_m_x;
      c1_m_y = NULL;
      sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_j_y, 14, c1_k_y, 14,
        c1_l_y), 14, c1_m_y), "sprintf", c1_str);
      for (c1_i77 = 0; c1_i77 < 14; c1_i77++) {
        c1_b_str[c1_i77] = c1_str[c1_i77];
      }

      c1_eml_warning(chartInstance, c1_rankR, c1_b_str);
      exitg1 = TRUE;
    } else {
      c1_rankR++;
      c1_b_k++;
    }
  }

  for (c1_i78 = 0; c1_i78 < 3; c1_i78++) {
    c1_Y[c1_i78] = 0.0;
  }

  for (c1_d_j = 0; c1_d_j < 3; c1_d_j++) {
    c1_e_j = 1.0 + (real_T)c1_d_j;
    c1_tauj = c1_tau[(int32_T)c1_e_j - 1];
    if (c1_tauj != 0.0) {
      c1_wj = c1_b_B[(int32_T)c1_e_j - 1];
      c1_d4 = c1_e_j + 1.0;
      c1_i79 = (int32_T)(10.0 + (1.0 - c1_d4)) - 1;
      for (c1_c_i = 0; c1_c_i <= c1_i79; c1_c_i++) {
        c1_d_i = c1_d4 + (real_T)c1_c_i;
        c1_s_a = c1_b_A[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)c1_d_i, 1, 10, 1, 0) + 10 * ((int32_T)c1_e_j - 1)) - 1];
        c1_s_b = c1_b_B[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)c1_d_i, 1, 10, 1, 0) - 1];
        c1_z = c1_s_a * c1_s_b;
        c1_wj += c1_z;
      }

      c1_t_a = c1_tauj;
      c1_t_b = c1_wj;
      c1_wj = c1_t_a * c1_t_b;
      if (c1_wj != 0.0) {
        c1_b_B[(int32_T)c1_e_j - 1] -= c1_wj;
        c1_d5 = c1_e_j + 1.0;
        c1_i80 = (int32_T)(10.0 + (1.0 - c1_d5)) - 1;
        for (c1_e_i = 0; c1_e_i <= c1_i80; c1_e_i++) {
          c1_d_i = c1_d5 + (real_T)c1_e_i;
          c1_u_a = c1_b_A[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)c1_d_i, 1, 10, 1, 0) + 10 * ((int32_T)c1_e_j - 1)) - 1];
          c1_u_b = c1_wj;
          c1_n_y = c1_u_a * c1_u_b;
          c1_b_B[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            c1_d_i, 1, 10, 1, 0) - 1] = c1_b_B[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_d_i, 1, 10, 1, 0) - 1] -
            c1_n_y;
        }
      }
    }
  }

  c1_rr = c1_rankR;
  c1_b_rr = c1_rr;
  c1_i81 = (int32_T)c1_b_rr;
  _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_b_rr, mxDOUBLE_CLASS, c1_i81);
  for (c1_f_i = 0; c1_f_i < c1_i81; c1_f_i++) {
    c1_d_i = 1.0 + (real_T)c1_f_i;
    c1_Y[c1_jpvt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      c1_d_i, 1, 3, 1, 0) - 1] - 1] = c1_b_B[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_d_i, 1, 10, 1, 0) - 1];
  }

  c1_c_rr = c1_rr;
  c1_i82 = (int32_T)-(1.0 + (-1.0 - c1_c_rr));
  _SFD_FOR_LOOP_VECTOR_CHECK(c1_c_rr, -1.0, 1.0, mxDOUBLE_CLASS, c1_i82);
  for (c1_f_j = 0; c1_f_j < c1_i82; c1_f_j++) {
    c1_e_j = c1_c_rr + -(real_T)c1_f_j;
    c1_pj = c1_jpvt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      c1_e_j, 1, 3, 1, 0) - 1] - 1;
    c1_n_x = c1_Y[c1_pj];
    c1_o_y = c1_b_A[((int32_T)c1_e_j + 10 * ((int32_T)c1_e_j - 1)) - 1];
    c1_b_z = c1_n_x / c1_o_y;
    c1_Y[c1_pj] = c1_b_z;
    c1_d6 = c1_e_j - 1.0;
    c1_i83 = (int32_T)c1_d6 - 1;
    for (c1_g_i = 0; c1_g_i <= c1_i83; c1_g_i++) {
      c1_d_i = 1.0 + (real_T)c1_g_i;
      c1_v_a = c1_Y[c1_pj];
      c1_v_b = c1_b_A[((int32_T)c1_d_i + 10 * ((int32_T)c1_e_j - 1)) - 1];
      c1_p_y = c1_v_a * c1_v_b;
      c1_Y[c1_jpvt[(int32_T)c1_d_i - 1] - 1] -= c1_p_y;
    }
  }
}

static void c1_eps(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static real_T c1_sqrt(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_error(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance)
{
  int32_T c1_i84;
  static char_T c1_cv7[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i85;
  static char_T c1_cv8[4] = { 's', 'q', 'r', 't' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  for (c1_i84 = 0; c1_i84 < 30; c1_i84++) {
    c1_u[c1_i84] = c1_cv7[c1_i84];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c1_i85 = 0; c1_i85 < 4; c1_i85++) {
    c1_b_u[c1_i85] = c1_cv8[c1_i85];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static real_T c1_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0)
{
  real_T c1_y;
  int32_T c1_b_ix0;
  int32_T c1_c_ix0;
  real_T c1_scale;
  int32_T c1_kstart;
  int32_T c1_a;
  int32_T c1_kend;
  int32_T c1_b_kstart;
  int32_T c1_b_kend;
  int32_T c1_b_a;
  int32_T c1_b;
  int32_T c1_c_a;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_absxk;
  real_T c1_t;
  c1_b_ix0 = c1_ix0;
  c1_c_ix0 = c1_b_ix0;
  c1_y = 0.0;
  c1_realmin(chartInstance);
  c1_scale = 2.2250738585072014E-308;
  c1_kstart = c1_c_ix0;
  c1_a = c1_kstart;
  c1_kend = c1_a;
  c1_b_kstart = c1_kstart;
  c1_b_kend = c1_kend + 9;
  c1_b_a = c1_b_kstart;
  c1_b = c1_b_kend;
  c1_c_a = c1_b_a;
  c1_b_b = c1_b;
  if (c1_c_a > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_b_check_forloop_overflow_error(chartInstance, TRUE);
  }

  for (c1_k = c1_b_kstart; c1_k <= c1_b_kend; c1_k++) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, 30, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_absxk = muDoubleScalarAbs(c1_c_x);
    if (c1_absxk > c1_scale) {
      c1_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_t * c1_t;
      c1_scale = c1_absxk;
    } else {
      c1_t = c1_absxk / c1_scale;
      c1_y += c1_t * c1_t;
    }
  }

  return c1_scale * muDoubleScalarSqrt(c1_y);
}

static void c1_realmin(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance)
{
}

static int32_T c1_eml_ixamax(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T c1_ix0)
{
  int32_T c1_idxmax;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_ix;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_y;
  real_T c1_smax;
  int32_T c1_d_n;
  int32_T c1_b;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_a;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_c_y;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_d_y;
  real_T c1_s;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_c_n = c1_b_n;
  c1_c_ix0 = c1_b_ix0;
  if (c1_c_n < 1) {
    c1_idxmax = 0;
  } else {
    c1_idxmax = 1;
    if (c1_c_n > 1) {
      c1_ix = c1_c_ix0;
      c1_b_x = c1_x[c1_ix - 1];
      c1_c_x = c1_b_x;
      c1_d_x = c1_c_x;
      c1_y = muDoubleScalarAbs(c1_d_x);
      c1_e_x = 0.0;
      c1_f_x = c1_e_x;
      c1_b_y = muDoubleScalarAbs(c1_f_x);
      c1_smax = c1_y + c1_b_y;
      c1_d_n = c1_c_n;
      c1_b = c1_d_n;
      c1_b_b = c1_b;
      if (2 > c1_b_b) {
        c1_overflow = FALSE;
      } else {
        c1_overflow = (c1_b_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      for (c1_k = 2; c1_k <= c1_d_n; c1_k++) {
        c1_b_k = c1_k;
        c1_a = c1_ix + 1;
        c1_ix = c1_a;
        c1_g_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, 3, 1, 0) - 1];
        c1_h_x = c1_g_x;
        c1_i_x = c1_h_x;
        c1_c_y = muDoubleScalarAbs(c1_i_x);
        c1_j_x = 0.0;
        c1_k_x = c1_j_x;
        c1_d_y = muDoubleScalarAbs(c1_k_x);
        c1_s = c1_c_y + c1_d_y;
        if (c1_s > c1_smax) {
          c1_idxmax = c1_b_k;
          c1_smax = c1_s;
        }
      }
    }
  }

  return c1_idxmax;
}

static void c1_eml_xswap(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0, int32_T c1_iy0, real_T
  c1_b_x[30])
{
  int32_T c1_i86;
  for (c1_i86 = 0; c1_i86 < 30; c1_i86++) {
    c1_b_x[c1_i86] = c1_x[c1_i86];
  }

  c1_b_eml_xswap(chartInstance, c1_b_x, c1_ix0, c1_iy0);
}

static void c1_below_threshold(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance)
{
}

static void c1_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_alpha1, real_T c1_x[30], int32_T
  c1_ix0, real_T *c1_b_alpha1, real_T c1_b_x[30], real_T *c1_tau)
{
  int32_T c1_i87;
  *c1_b_alpha1 = c1_alpha1;
  for (c1_i87 = 0; c1_i87 < 30; c1_i87++) {
    c1_b_x[c1_i87] = c1_x[c1_i87];
  }

  *c1_tau = c1_b_eml_matlab_zlarfg(chartInstance, c1_n, c1_b_alpha1, c1_b_x,
    c1_ix0);
}

static real_T c1_b_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[30], int32_T c1_ix0)
{
  real_T c1_y;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_scale;
  int32_T c1_kstart;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_c_a;
  int32_T c1_b;
  int32_T c1_kend;
  int32_T c1_b_kstart;
  int32_T c1_b_kend;
  int32_T c1_d_a;
  int32_T c1_b_b;
  int32_T c1_e_a;
  int32_T c1_c_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_absxk;
  real_T c1_t;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_below_threshold(chartInstance);
  c1_c_n = c1_b_n;
  c1_c_ix0 = c1_b_ix0;
  c1_y = 0.0;
  if (c1_c_n < 1) {
  } else if (c1_c_n == 1) {
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0, 1, 30, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_y = muDoubleScalarAbs(c1_c_x);
  } else {
    c1_realmin(chartInstance);
    c1_scale = 2.2250738585072014E-308;
    c1_kstart = c1_c_ix0;
    c1_a = c1_c_n;
    c1_c = c1_a;
    c1_b_a = c1_c - 1;
    c1_b_c = c1_b_a;
    c1_c_a = c1_kstart;
    c1_b = c1_b_c;
    c1_kend = c1_c_a + c1_b;
    c1_b_kstart = c1_kstart;
    c1_b_kend = c1_kend;
    c1_d_a = c1_b_kstart;
    c1_b_b = c1_b_kend;
    c1_e_a = c1_d_a;
    c1_c_b = c1_b_b;
    if (c1_e_a > c1_c_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_k = c1_b_kstart; c1_k <= c1_b_kend; c1_k++) {
      c1_b_k = c1_k;
      c1_d_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, 30, 1, 0) - 1];
      c1_e_x = c1_d_x;
      c1_absxk = muDoubleScalarAbs(c1_e_x);
      if (c1_absxk > c1_scale) {
        c1_t = c1_scale / c1_absxk;
        c1_y = 1.0 + c1_y * c1_t * c1_t;
        c1_scale = c1_absxk;
      } else {
        c1_t = c1_absxk / c1_scale;
        c1_y += c1_t * c1_t;
      }
    }

    c1_y = c1_scale * muDoubleScalarSqrt(c1_y);
  }

  return c1_y;
}

static void c1_eml_xscal(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[30], int32_T c1_ix0,
  real_T c1_b_x[30])
{
  int32_T c1_i88;
  for (c1_i88 = 0; c1_i88 < 30; c1_i88++) {
    c1_b_x[c1_i88] = c1_x[c1_i88];
  }

  c1_b_eml_xscal(chartInstance, c1_n, c1_a, c1_b_x, c1_ix0);
}

static void c1_eml_matlab_zlarf(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[30], int32_T c1_ic0, real_T c1_work[3], real_T c1_b_C[30], real_T
  c1_b_work[3])
{
  int32_T c1_i89;
  int32_T c1_i90;
  for (c1_i89 = 0; c1_i89 < 30; c1_i89++) {
    c1_b_C[c1_i89] = c1_C[c1_i89];
  }

  for (c1_i90 = 0; c1_i90 < 3; c1_i90++) {
    c1_b_work[c1_i90] = c1_work[c1_i90];
  }

  c1_b_eml_matlab_zlarf(chartInstance, c1_m, c1_n, c1_iv0, c1_tau, c1_b_C,
                        c1_ic0, c1_b_work);
}

static void c1_eml_xgemv(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[30], int32_T c1_ia0,
  real_T c1_x[30], int32_T c1_ix0, real_T c1_y[3], real_T c1_b_y[3])
{
  int32_T c1_i91;
  int32_T c1_i92;
  real_T c1_b_A[30];
  int32_T c1_i93;
  real_T c1_b_x[30];
  for (c1_i91 = 0; c1_i91 < 3; c1_i91++) {
    c1_b_y[c1_i91] = c1_y[c1_i91];
  }

  for (c1_i92 = 0; c1_i92 < 30; c1_i92++) {
    c1_b_A[c1_i92] = c1_A[c1_i92];
  }

  for (c1_i93 = 0; c1_i93 < 30; c1_i93++) {
    c1_b_x[c1_i93] = c1_x[c1_i93];
  }

  c1_b_eml_xgemv(chartInstance, c1_m, c1_n, c1_b_A, c1_ia0, c1_b_x, c1_ix0,
                 c1_b_y);
}

static void c1_eml_xger(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A[30], int32_T c1_ia0, real_T c1_b_A[30])
{
  int32_T c1_i94;
  int32_T c1_i95;
  real_T c1_b_y[3];
  for (c1_i94 = 0; c1_i94 < 30; c1_i94++) {
    c1_b_A[c1_i94] = c1_A[c1_i94];
  }

  for (c1_i95 = 0; c1_i95 < 3; c1_i95++) {
    c1_b_y[c1_i95] = c1_y[c1_i95];
  }

  c1_b_eml_xger(chartInstance, c1_m, c1_n, c1_alpha1, c1_ix0, c1_b_y, c1_b_A,
                c1_ia0);
}

static real_T c1_c_eml_xnrm2(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[30], int32_T c1_ix0)
{
  real_T c1_y;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_scale;
  int32_T c1_kstart;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_c_a;
  int32_T c1_b;
  int32_T c1_kend;
  int32_T c1_b_kstart;
  int32_T c1_b_kend;
  int32_T c1_d_a;
  int32_T c1_b_b;
  int32_T c1_e_a;
  int32_T c1_c_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_absxk;
  real_T c1_t;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_below_threshold(chartInstance);
  c1_c_n = c1_b_n;
  c1_c_ix0 = c1_b_ix0;
  c1_y = 0.0;
  if (c1_c_n < 1) {
  } else if (c1_c_n == 1) {
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0, 1, 30, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_y = muDoubleScalarAbs(c1_c_x);
  } else {
    c1_realmin(chartInstance);
    c1_scale = 2.2250738585072014E-308;
    c1_kstart = c1_c_ix0;
    c1_a = c1_c_n;
    c1_c = c1_a;
    c1_b_a = c1_c - 1;
    c1_b_c = c1_b_a;
    c1_c_a = c1_kstart;
    c1_b = c1_b_c;
    c1_kend = c1_c_a + c1_b;
    c1_b_kstart = c1_kstart;
    c1_b_kend = c1_kend;
    c1_d_a = c1_b_kstart;
    c1_b_b = c1_b_kend;
    c1_e_a = c1_d_a;
    c1_c_b = c1_b_b;
    if (c1_e_a > c1_c_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_k = c1_b_kstart; c1_k <= c1_b_kend; c1_k++) {
      c1_b_k = c1_k;
      c1_d_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, 30, 1, 0) - 1];
      c1_e_x = c1_d_x;
      c1_absxk = muDoubleScalarAbs(c1_e_x);
      if (c1_absxk > c1_scale) {
        c1_t = c1_scale / c1_absxk;
        c1_y = 1.0 + c1_y * c1_t * c1_t;
        c1_scale = c1_absxk;
      } else {
        c1_t = c1_absxk / c1_scale;
        c1_y += c1_t * c1_t;
      }
    }

    c1_y = c1_scale * muDoubleScalarSqrt(c1_y);
  }

  return c1_y;
}

static void c1_eml_warning(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14])
{
  int32_T c1_i96;
  static char_T c1_varargin_1[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i',
    'e', 'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i97;
  char_T c1_c_u[14];
  const mxArray *c1_c_y = NULL;
  for (c1_i96 = 0; c1_i96 < 32; c1_i96++) {
    c1_u[c1_i96] = c1_varargin_1[c1_i96];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 32), FALSE);
  c1_b_u = c1_varargin_2;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c1_i97 = 0; c1_i97 < 14; c1_i97++) {
    c1_c_u[c1_i97] = c1_varargin_3[c1_i97];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 3U,
    14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static real_T c1_mpower(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_b;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_b_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_b_eml_scalar_eg(chartInstance);
  c1_e_a = c1_d_a;
  c1_b = c1_d_a;
  return c1_e_a * c1_b;
}

static void c1_i_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_j_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14])
{
  char_T c1_cv9[14];
  int32_T c1_i98;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv9, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i98 = 0; c1_i98 < 14; c1_i98++) {
    c1_y[c1_i98] = c1_cv9[c1_i98];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_k_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i99;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i99, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i99;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_l_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_DrogueVisualNavigation2, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_DrogueVisualNavigation2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_DrogueVisualNavigation2);
  return c1_y;
}

static uint8_T c1_m_emlrt_marshallIn(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sqrt(SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance,
                      real_T *c1_x)
{
  if (*c1_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void c1_b_eml_xswap(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, real_T c1_x[30], int32_T c1_ix0, int32_T c1_iy0)
{
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_k;
  real_T c1_temp;
  int32_T c1_a;
  int32_T c1_b_a;
  c1_b_ix0 = c1_ix0;
  c1_b_iy0 = c1_iy0;
  c1_c_ix0 = c1_b_ix0;
  c1_c_iy0 = c1_b_iy0;
  c1_ix = c1_c_ix0;
  c1_iy = c1_c_iy0;
  for (c1_k = 1; c1_k < 11; c1_k++) {
    c1_temp = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, 30, 1, 0) - 1];
    c1_x[c1_ix - 1] = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_iy, 1, 30, 1, 0) -
      1];
    c1_x[c1_iy - 1] = c1_temp;
    c1_a = c1_ix + 1;
    c1_ix = c1_a;
    c1_b_a = c1_iy + 1;
    c1_iy = c1_b_a;
  }
}

static real_T c1_b_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation2InstanceStruct *
  chartInstance, int32_T c1_n, real_T *c1_alpha1, real_T c1_x[30], int32_T
  c1_ix0)
{
  real_T c1_tau;
  int32_T c1_nm1;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  real_T c1_b_x[30];
  real_T c1_xnorm;
  real_T c1_x1;
  real_T c1_x2;
  real_T c1_a;
  real_T c1_b;
  real_T c1_beta1;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_y;
  int32_T c1_knt;
  int32_T c1_b_a;
  real_T c1_d7;
  real_T c1_c_a;
  real_T c1_d_a;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_y;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  real_T c1_g_x[30];
  real_T c1_b_x1;
  real_T c1_b_x2;
  real_T c1_e_a;
  real_T c1_b_b;
  real_T c1_h_x;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b_knt;
  int32_T c1_c_b;
  int32_T c1_d_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  real_T c1_f_a;
  real_T c1_i_x;
  real_T c1_e_y;
  real_T c1_f_y;
  c1_tau = 0.0;
  if (c1_n <= 0) {
  } else {
    c1_nm1 = c1_n - 1;
    c1_i100 = 0;
    for (c1_i101 = 0; c1_i101 < 3; c1_i101++) {
      for (c1_i102 = 0; c1_i102 < 10; c1_i102++) {
        c1_b_x[c1_i102 + c1_i100] = c1_x[c1_i102 + c1_i100];
      }

      c1_i100 += 10;
    }

    c1_xnorm = c1_b_eml_xnrm2(chartInstance, c1_nm1, c1_b_x, c1_ix0);
    if (c1_xnorm != 0.0) {
      c1_x1 = *c1_alpha1;
      c1_x2 = c1_xnorm;
      c1_a = c1_x1;
      c1_b = c1_x2;
      c1_beta1 = muDoubleScalarHypot(c1_a, c1_b);
      if (*c1_alpha1 >= 0.0) {
        c1_beta1 = -c1_beta1;
      }

      c1_realmin(chartInstance);
      c1_eps(chartInstance);
      c1_c_x = c1_beta1;
      c1_d_x = c1_c_x;
      c1_y = muDoubleScalarAbs(c1_d_x);
      if (c1_y < 1.0020841800044864E-292) {
        c1_knt = 0;
        do {
          c1_b_a = c1_knt + 1;
          c1_knt = c1_b_a;
          c1_d7 = 9.9792015476736E+291;
          c1_b_eml_xscal(chartInstance, c1_nm1, c1_d7, c1_x, c1_ix0);
          c1_c_a = c1_beta1;
          c1_beta1 = c1_c_a * 9.9792015476736E+291;
          c1_d_a = *c1_alpha1;
          *c1_alpha1 = c1_d_a * 9.9792015476736E+291;
          c1_e_x = c1_beta1;
          c1_f_x = c1_e_x;
          c1_b_y = muDoubleScalarAbs(c1_f_x);
        } while (!(c1_b_y >= 1.0020841800044864E-292));

        c1_i103 = 0;
        for (c1_i104 = 0; c1_i104 < 3; c1_i104++) {
          for (c1_i105 = 0; c1_i105 < 10; c1_i105++) {
            c1_g_x[c1_i105 + c1_i103] = c1_x[c1_i105 + c1_i103];
          }

          c1_i103 += 10;
        }

        c1_xnorm = c1_b_eml_xnrm2(chartInstance, c1_nm1, c1_g_x, c1_ix0);
        c1_b_x1 = *c1_alpha1;
        c1_b_x2 = c1_xnorm;
        c1_e_a = c1_b_x1;
        c1_b_b = c1_b_x2;
        c1_beta1 = muDoubleScalarHypot(c1_e_a, c1_b_b);
        if (*c1_alpha1 >= 0.0) {
          c1_beta1 = -c1_beta1;
        }

        c1_h_x = c1_beta1 - *c1_alpha1;
        c1_c_y = c1_beta1;
        c1_tau = c1_h_x / c1_c_y;
        c1_d_y = *c1_alpha1 - c1_beta1;
        *c1_alpha1 = 1.0 / c1_d_y;
        c1_b_eml_xscal(chartInstance, c1_nm1, *c1_alpha1, c1_x, c1_ix0);
        c1_b_knt = c1_knt;
        c1_c_b = c1_b_knt;
        c1_d_b = c1_c_b;
        if (1 > c1_d_b) {
          c1_overflow = FALSE;
        } else {
          c1_overflow = (c1_d_b > 2147483646);
        }

        if (c1_overflow) {
          c1_b_check_forloop_overflow_error(chartInstance, TRUE);
        }

        for (c1_k = 1; c1_k <= c1_b_knt; c1_k++) {
          c1_f_a = c1_beta1;
          c1_beta1 = c1_f_a * 1.0020841800044864E-292;
        }

        *c1_alpha1 = c1_beta1;
      } else {
        c1_i_x = c1_beta1 - *c1_alpha1;
        c1_e_y = c1_beta1;
        c1_tau = c1_i_x / c1_e_y;
        c1_f_y = *c1_alpha1 - c1_beta1;
        *c1_alpha1 = 1.0 / c1_f_y;
        c1_b_eml_xscal(chartInstance, c1_nm1, *c1_alpha1, c1_x, c1_ix0);
        *c1_alpha1 = c1_beta1;
      }
    }
  }

  return c1_tau;
}

static void c1_b_eml_xscal(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x[30], int32_T c1_ix0)
{
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  real_T c1_c_a;
  int32_T c1_c_ix0;
  int32_T c1_d_ix0;
  int32_T c1_d_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_e_a;
  int32_T c1_b_b;
  int32_T c1_i106;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_g_a;
  int32_T c1_d_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_b_k;
  c1_b_n = c1_n;
  c1_b_a = c1_a;
  c1_b_ix0 = c1_ix0;
  c1_c_n = c1_b_n;
  c1_c_a = c1_b_a;
  c1_c_ix0 = c1_b_ix0;
  c1_d_ix0 = c1_c_ix0;
  c1_d_a = c1_c_n;
  c1_c = c1_d_a;
  c1_b = c1_c - 1;
  c1_b_c = c1_b;
  c1_e_a = c1_c_ix0;
  c1_b_b = c1_b_c;
  c1_i106 = c1_e_a + c1_b_b;
  c1_f_a = c1_d_ix0;
  c1_c_b = c1_i106;
  c1_g_a = c1_f_a;
  c1_d_b = c1_c_b;
  if (c1_g_a > c1_d_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_d_b > 2147483646);
  }

  if (c1_overflow) {
    c1_b_check_forloop_overflow_error(chartInstance, TRUE);
  }

  for (c1_k = c1_d_ix0; c1_k <= c1_i106; c1_k++) {
    c1_b_k = c1_k;
    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, 30, 1, 0) - 1] = c1_c_a *
      c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, 30, 1, 0) - 1];
  }
}

static void c1_b_eml_matlab_zlarf(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C[30], int32_T c1_ic0, real_T c1_work[3])
{
  int32_T c1_lastv;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_a;
  int32_T c1_b_b;
  int32_T c1_i;
  int32_T c1_c_a;
  int32_T c1_d_a;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_ia0;
  int32_T c1_lastc;
  int32_T c1_e_a;
  int32_T c1_c_c;
  int32_T c1_f_a;
  int32_T c1_d_c;
  int32_T c1_g_a;
  int32_T c1_c_b;
  int32_T c1_coltop;
  int32_T c1_h_a;
  int32_T c1_e_c;
  int32_T c1_i_a;
  int32_T c1_d_b;
  int32_T c1_colbottom;
  int32_T c1_b_coltop;
  int32_T c1_b_colbottom;
  int32_T c1_j_a;
  int32_T c1_e_b;
  int32_T c1_k_a;
  int32_T c1_f_b;
  boolean_T c1_overflow;
  int32_T c1_ia;
  int32_T c1_b_ia;
  int32_T c1_l_a;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  real_T c1_b_C[30];
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  real_T c1_c_C[30];
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_alpha1;
  int32_T c1_ix0;
  int32_T c1_b_ia0;
  int32_T c1_i113;
  real_T c1_b_work[3];
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  if (c1_tau != 0.0) {
    c1_lastv = c1_m;
    c1_a = c1_lastv;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = c1_b;
    c1_b_a = c1_iv0;
    c1_b_b = c1_b_c;
    c1_i = c1_b_a + c1_b_b;
    exitg3 = FALSE;
    while ((exitg3 == FALSE) && (c1_lastv > 0)) {
      if (c1_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i, 1, 30, 1, 0) - 1] == 0.0) {
        c1_c_a = c1_lastv - 1;
        c1_lastv = c1_c_a;
        c1_d_a = c1_i - 1;
        c1_i = c1_d_a;
      } else {
        exitg3 = TRUE;
      }
    }

    c1_b_m = c1_lastv;
    c1_b_n = c1_n;
    c1_ia0 = c1_ic0;
    c1_lastc = c1_b_n;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (c1_lastc > 0)) {
      c1_e_a = c1_lastc;
      c1_c_c = c1_e_a;
      c1_f_a = c1_c_c - 1;
      c1_d_c = c1_f_a * 10;
      c1_g_a = c1_ia0;
      c1_c_b = c1_d_c;
      c1_coltop = c1_g_a + c1_c_b;
      c1_h_a = c1_b_m;
      c1_e_c = c1_h_a;
      c1_i_a = c1_coltop;
      c1_d_b = c1_e_c - 1;
      c1_colbottom = c1_i_a + c1_d_b;
      c1_b_coltop = c1_coltop;
      c1_b_colbottom = c1_colbottom;
      c1_j_a = c1_b_coltop;
      c1_e_b = c1_b_colbottom;
      c1_k_a = c1_j_a;
      c1_f_b = c1_e_b;
      if (c1_k_a > c1_f_b) {
        c1_overflow = FALSE;
      } else {
        c1_overflow = (c1_f_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      c1_ia = c1_b_coltop;
      do {
        exitg1 = 0;
        if (c1_ia <= c1_b_colbottom) {
          c1_b_ia = c1_ia;
          if (c1_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_ia, 1, 30, 1, 0) - 1] !=
              0.0) {
            exitg1 = 1;
          } else {
            c1_ia++;
          }
        } else {
          c1_l_a = c1_lastc - 1;
          c1_lastc = c1_l_a;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = TRUE;
      }
    }
  } else {
    c1_lastv = 0;
    c1_lastc = 0;
  }

  if (c1_lastv > 0) {
    c1_i107 = 0;
    for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
      for (c1_i109 = 0; c1_i109 < 10; c1_i109++) {
        c1_b_C[c1_i109 + c1_i107] = c1_C[c1_i109 + c1_i107];
      }

      c1_i107 += 10;
    }

    c1_i110 = 0;
    for (c1_i111 = 0; c1_i111 < 3; c1_i111++) {
      for (c1_i112 = 0; c1_i112 < 10; c1_i112++) {
        c1_c_C[c1_i112 + c1_i110] = c1_C[c1_i112 + c1_i110];
      }

      c1_i110 += 10;
    }

    c1_b_eml_xgemv(chartInstance, c1_lastv, c1_lastc, c1_b_C, c1_ic0, c1_c_C,
                   c1_iv0, c1_work);
    c1_c_m = c1_lastv;
    c1_c_n = c1_lastc;
    c1_alpha1 = -c1_tau;
    c1_ix0 = c1_iv0;
    c1_b_ia0 = c1_ic0;
    for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
      c1_b_work[c1_i113] = c1_work[c1_i113];
    }

    c1_b_eml_xger(chartInstance, c1_c_m, c1_c_n, c1_alpha1, c1_ix0, c1_b_work,
                  c1_C, c1_b_ia0);
  }
}

static void c1_b_eml_xgemv(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A[30], int32_T c1_ia0,
  real_T c1_x[30], int32_T c1_ix0, real_T c1_y[3])
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_b_ia0;
  int32_T c1_b_ix0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  int32_T c1_c_ia0;
  int32_T c1_c_ix0;
  int32_T c1_a;
  int32_T c1_mm1;
  int32_T c1_b_a;
  int32_T c1_nm1;
  int32_T c1_b;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_iyend;
  int32_T c1_b_iyend;
  int32_T c1_c_b;
  int32_T c1_d_b;
  boolean_T c1_overflow;
  int32_T c1_iy;
  int32_T c1_b_iy;
  int32_T c1_d_ia0;
  int32_T c1_e_b;
  int32_T c1_b_c;
  int32_T c1_c_a;
  int32_T c1_f_b;
  int32_T c1_i114;
  int32_T c1_d_a;
  int32_T c1_g_b;
  int32_T c1_e_a;
  int32_T c1_h_b;
  boolean_T c1_b_overflow;
  int32_T c1_iac;
  int32_T c1_b_iac;
  int32_T c1_ix;
  real_T c1_c_c;
  int32_T c1_c_iac;
  int32_T c1_f_a;
  int32_T c1_i_b;
  int32_T c1_i115;
  int32_T c1_g_a;
  int32_T c1_j_b;
  int32_T c1_h_a;
  int32_T c1_k_b;
  boolean_T c1_c_overflow;
  int32_T c1_ia;
  int32_T c1_b_ia;
  real_T c1_i_a;
  real_T c1_l_b;
  real_T c1_z;
  int32_T c1_j_a;
  int32_T c1_k_a;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_ia0 = c1_ia0;
  c1_b_ix0 = c1_ix0;
  c1_c_m = c1_b_m;
  c1_c_n = c1_b_n;
  c1_c_ia0 = c1_b_ia0;
  c1_c_ix0 = c1_b_ix0;
  if (c1_c_n == 0) {
  } else {
    c1_a = c1_c_m;
    c1_mm1 = c1_a;
    c1_b_a = c1_c_n - 1;
    c1_nm1 = c1_b_a;
    c1_b = c1_nm1;
    c1_c = c1_b;
    c1_b_b = c1_c;
    c1_iyend = c1_b_b;
    c1_b_iyend = c1_iyend + 1;
    c1_c_b = c1_b_iyend;
    c1_d_b = c1_c_b;
    if (1 > c1_d_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_d_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_iy = 1; c1_iy <= c1_b_iyend; c1_iy++) {
      c1_b_iy = c1_iy;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_iy, 1, 3, 1, 0) - 1] = 0.0;
    }

    c1_b_iy = 1;
    c1_d_ia0 = c1_c_ia0;
    c1_e_b = c1_nm1;
    c1_b_c = 10 * c1_e_b;
    c1_c_a = c1_c_ia0;
    c1_f_b = c1_b_c;
    c1_i114 = c1_c_a + c1_f_b;
    c1_d_a = c1_d_ia0;
    c1_g_b = c1_i114;
    c1_e_a = c1_d_a;
    c1_h_b = c1_g_b;
    if (c1_e_a > c1_h_b) {
      c1_b_overflow = FALSE;
    } else {
      c1_b_overflow = (c1_h_b > 2147483637);
    }

    if (c1_b_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_iac = c1_d_ia0; c1_iac <= c1_i114; c1_iac += 10) {
      c1_b_iac = c1_iac;
      c1_ix = c1_c_ix0;
      c1_c_c = 0.0;
      c1_c_iac = c1_b_iac;
      c1_f_a = c1_b_iac;
      c1_i_b = c1_mm1 - 1;
      c1_i115 = c1_f_a + c1_i_b;
      c1_g_a = c1_c_iac;
      c1_j_b = c1_i115;
      c1_h_a = c1_g_a;
      c1_k_b = c1_j_b;
      if (c1_h_a > c1_k_b) {
        c1_c_overflow = FALSE;
      } else {
        c1_c_overflow = (c1_k_b > 2147483646);
      }

      if (c1_c_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      for (c1_ia = c1_c_iac; c1_ia <= c1_i115; c1_ia++) {
        c1_b_ia = c1_ia;
        c1_i_a = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_ia, 1, 30, 1, 0) - 1];
        c1_l_b = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, 30, 1, 0) - 1];
        c1_z = c1_i_a * c1_l_b;
        c1_c_c += c1_z;
        c1_j_a = c1_ix + 1;
        c1_ix = c1_j_a;
      }

      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_iy, 1, 3, 1, 0) - 1] =
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_iy, 1, 3, 1, 0) - 1] + c1_c_c;
      c1_k_a = c1_b_iy + 1;
      c1_b_iy = c1_k_a;
    }
  }
}

static void c1_b_eml_xger(SFc1_DrogueVisualNavigation2InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A[30], int32_T c1_ia0)
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  real_T c1_b_alpha1;
  int32_T c1_b_ix0;
  int32_T c1_b_ia0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_c_alpha1;
  int32_T c1_c_ix0;
  int32_T c1_c_ia0;
  int32_T c1_d_m;
  int32_T c1_d_n;
  real_T c1_d_alpha1;
  int32_T c1_d_ix0;
  int32_T c1_d_ia0;
  int32_T c1_ixstart;
  int32_T c1_a;
  int32_T c1_jA;
  int32_T c1_jy;
  int32_T c1_e_n;
  int32_T c1_b;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_j;
  real_T c1_yjy;
  real_T c1_temp;
  int32_T c1_ix;
  int32_T c1_c_b;
  int32_T c1_i116;
  int32_T c1_b_a;
  int32_T c1_d_b;
  int32_T c1_i117;
  int32_T c1_c_a;
  int32_T c1_e_b;
  int32_T c1_d_a;
  int32_T c1_f_b;
  boolean_T c1_b_overflow;
  int32_T c1_ijA;
  int32_T c1_b_ijA;
  int32_T c1_e_a;
  int32_T c1_f_a;
  int32_T c1_g_a;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_alpha1 = c1_alpha1;
  c1_b_ix0 = c1_ix0;
  c1_b_ia0 = c1_ia0;
  c1_c_m = c1_b_m;
  c1_c_n = c1_b_n;
  c1_c_alpha1 = c1_b_alpha1;
  c1_c_ix0 = c1_b_ix0;
  c1_c_ia0 = c1_b_ia0;
  c1_d_m = c1_c_m;
  c1_d_n = c1_c_n;
  c1_d_alpha1 = c1_c_alpha1;
  c1_d_ix0 = c1_c_ix0;
  c1_d_ia0 = c1_c_ia0;
  if (c1_d_alpha1 == 0.0) {
  } else {
    c1_ixstart = c1_d_ix0;
    c1_a = c1_d_ia0 - 1;
    c1_jA = c1_a;
    c1_jy = 1;
    c1_e_n = c1_d_n;
    c1_b = c1_e_n;
    c1_b_b = c1_b;
    if (1 > c1_b_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_b_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_j = 1; c1_j <= c1_e_n; c1_j++) {
      c1_yjy = c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_jy, 1, 3, 1, 0) - 1];
      if (c1_yjy != 0.0) {
        c1_temp = c1_yjy * c1_d_alpha1;
        c1_ix = c1_ixstart;
        c1_c_b = c1_jA + 1;
        c1_i116 = c1_c_b;
        c1_b_a = c1_d_m;
        c1_d_b = c1_jA;
        c1_i117 = c1_b_a + c1_d_b;
        c1_c_a = c1_i116;
        c1_e_b = c1_i117;
        c1_d_a = c1_c_a;
        c1_f_b = c1_e_b;
        if (c1_d_a > c1_f_b) {
          c1_b_overflow = FALSE;
        } else {
          c1_b_overflow = (c1_f_b > 2147483646);
        }

        if (c1_b_overflow) {
          c1_b_check_forloop_overflow_error(chartInstance, TRUE);
        }

        for (c1_ijA = c1_i116; c1_ijA <= c1_i117; c1_ijA++) {
          c1_b_ijA = c1_ijA;
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_ijA, 1, 30, 1, 0) - 1] =
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_ijA, 1, 30, 1, 0) - 1] +
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, 30, 1, 0) - 1] *
            c1_temp;
          c1_e_a = c1_ix + 1;
          c1_ix = c1_e_a;
        }
      }

      c1_f_a = c1_jy + 1;
      c1_jy = c1_f_a;
      c1_g_a = c1_jA + 10;
      c1_jA = c1_g_a;
    }
  }
}

static void init_dsm_address_info(SFc1_DrogueVisualNavigation2InstanceStruct
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

void sf_c1_DrogueVisualNavigation2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2825970620U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2805308778U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(274087393U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(944415705U);
}

mxArray *sf_c1_DrogueVisualNavigation2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rwR438W4Y9DLkEmSdVOUCF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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
      pr[0] = (double)(1);
      pr[1] = (double)(3);
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

mxArray *sf_c1_DrogueVisualNavigation2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_DrogueVisualNavigation2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"yy\",},{M[8],M[0],T\"is_active_c1_DrogueVisualNavigation2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DrogueVisualNavigation2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
    chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DrogueVisualNavigation2MachineNumber_,
           1,
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
          init_script_number_translation(_DrogueVisualNavigation2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DrogueVisualNavigation2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DrogueVisualNavigation2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"yy");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,441);
        _SFD_CV_INIT_EML_FOR(0,1,0,96,106,180);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 720;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint32_T *c1_u2;
          uint32_T (*c1_u1)[345600];
          real_T (*c1_yy)[3];
          c1_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_yy = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_u1 = (uint32_T (*)[345600])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_yy);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_u2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DrogueVisualNavigation2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ApvRbXGo59B2Aow58XtulH";
}

static void sf_opaque_initialize_c1_DrogueVisualNavigation2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DrogueVisualNavigation2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DrogueVisualNavigation2
    ((SFc1_DrogueVisualNavigation2InstanceStruct*) chartInstanceVar);
  initialize_c1_DrogueVisualNavigation2
    ((SFc1_DrogueVisualNavigation2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DrogueVisualNavigation2(void *chartInstanceVar)
{
  enable_c1_DrogueVisualNavigation2((SFc1_DrogueVisualNavigation2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_DrogueVisualNavigation2(void *chartInstanceVar)
{
  disable_c1_DrogueVisualNavigation2((SFc1_DrogueVisualNavigation2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_DrogueVisualNavigation2(void *chartInstanceVar)
{
  sf_c1_DrogueVisualNavigation2((SFc1_DrogueVisualNavigation2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_DrogueVisualNavigation2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DrogueVisualNavigation2
    ((SFc1_DrogueVisualNavigation2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DrogueVisualNavigation2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_DrogueVisualNavigation2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DrogueVisualNavigation2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DrogueVisualNavigation2
    ((SFc1_DrogueVisualNavigation2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_DrogueVisualNavigation2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DrogueVisualNavigation2(S);
}

static void sf_opaque_set_sim_state_c1_DrogueVisualNavigation2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_DrogueVisualNavigation2(S, st);
}

static void sf_opaque_terminate_c1_DrogueVisualNavigation2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DrogueVisualNavigation2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DrogueVisualNavigation2_optimization_info();
    }

    finalize_c1_DrogueVisualNavigation2
      ((SFc1_DrogueVisualNavigation2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DrogueVisualNavigation2
    ((SFc1_DrogueVisualNavigation2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DrogueVisualNavigation2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DrogueVisualNavigation2
      ((SFc1_DrogueVisualNavigation2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DrogueVisualNavigation2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DrogueVisualNavigation2_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
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
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(893519444U));
  ssSetChecksum1(S,(307063577U));
  ssSetChecksum2(S,(3909388414U));
  ssSetChecksum3(S,(1788806472U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DrogueVisualNavigation2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DrogueVisualNavigation2(SimStruct *S)
{
  SFc1_DrogueVisualNavigation2InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation2InstanceStruct *)utMalloc(sizeof
    (SFc1_DrogueVisualNavigation2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DrogueVisualNavigation2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DrogueVisualNavigation2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_DrogueVisualNavigation2;
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

void c1_DrogueVisualNavigation2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DrogueVisualNavigation2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DrogueVisualNavigation2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DrogueVisualNavigation2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DrogueVisualNavigation2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
