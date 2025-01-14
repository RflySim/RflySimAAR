/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DrogueVisualNavigation3_sfun.h"
#include "c5_DrogueVisualNavigation3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DrogueVisualNavigation3_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[22] = { "L", "N", "Ir", "dX", "dY",
  "k", "r", "c", "mm", "nn", "dX_up", "I", "i", "j", "i1", "j1", "nargin",
  "nargout", "u1", "u2", "u3", "yy" };

/* Function Declarations */
static void initialize_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void initialize_params_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void enable_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void disable_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void set_sim_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance, const mxArray
   *c5_st);
static void finalize_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void sf_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c5_chartstep_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void initSimStructsc5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void registerMessagesc5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_yy, const char_T *c5_identifier, real_T
  c5_y[412800]);
static void c5_b_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[412800]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c5_inData_data[412800], int32_T c5_inData_sizes[1]);
static void c5_d_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y_data[412800], int32_T c5_y_sizes[1]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, real_T c5_outData_data[412800],
  int32_T c5_outData_sizes[1]);
static uint32_T c5_e_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[10]);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_g_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[412800]);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[37]);
static void c5_check_forloop_overflow_error
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c5_overflow);
static void c5_eml_find(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, boolean_T c5_x[412800], int32_T c5_i_data[412800], int32_T
  c5_i_sizes[1], int32_T c5_j_data[412800], int32_T c5_j_sizes[1]);
static void c5_eml_scalar_eg(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static real_T c5_mean(SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c5_x_data[412800], int32_T c5_x_sizes[1]);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_h_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_i_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_b_is_active_c5_DrogueVisualNavigation3, const
  char_T *c5_identifier);
static uint8_T c5_j_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_DrogueVisualNavigation3 = 0U;
}

static void initialize_params_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void enable_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  static real_T c5_u[412800];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_yy)[412800];
  c5_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 412800; c5_i0++) {
    c5_u[c5_i0] = (*c5_yy)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_DrogueVisualNavigation3;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance, const mxArray
   *c5_st)
{
  const mxArray *c5_u;
  static real_T c5_dv0[412800];
  int32_T c5_i1;
  real_T (*c5_yy)[412800];
  c5_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "yy",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 412800; c5_i1++) {
    (*c5_yy)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_DrogueVisualNavigation3 = c5_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_DrogueVisualNavigation3");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_DrogueVisualNavigation3(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void sf_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  uint32_T *c5_u2;
  real_T (*c5_u3)[412800];
  real_T (*c5_yy)[412800];
  uint32_T (*c5_u1)[412800];
  c5_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
  c5_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 412800; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c5_u1)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 412800; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_yy)[c5_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c5_u2, 2U);
  for (c5_i4 = 0; c5_i4 < 412800; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_u3)[c5_i4], 3U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_DrogueVisualNavigation3(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DrogueVisualNavigation3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  uint32_T c5_hoistedGlobal;
  int32_T c5_i5;
  static uint32_T c5_u1[412800];
  uint32_T c5_u2;
  int32_T c5_i6;
  static real_T c5_u3[412800];
  uint32_T c5_debug_family_var_map[22];
  static uint32_T c5_L[412800];
  uint32_T c5_N;
  static real_T c5_Ir[412800];
  real_T c5_dX[10];
  real_T c5_dY[10];
  uint32_T c5_k;
  int32_T c5_r_sizes;
  static real_T c5_r_data[412800];
  int32_T c5_c_sizes;
  static real_T c5_c_data[412800];
  real_T c5_mm;
  real_T c5_nn;
  real_T c5_dX_up;
  real_T c5_I;
  real_T c5_i;
  real_T c5_j;
  real_T c5_i1;
  real_T c5_j1;
  real_T c5_b_N;
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  static real_T c5_yy[412800];
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  uint32_T c5_c_N;
  uint32_T c5_b;
  uint32_T c5_b_b;
  boolean_T c5_overflow;
  uint32_T c5_b_k;
  int32_T c5_i11;
  static boolean_T c5_x[412800];
  int32_T c5_i12;
  static boolean_T c5_b_x[412800];
  int32_T c5_jj_sizes;
  static int32_T c5_jj_data[412800];
  int32_T c5_ii_sizes;
  static int32_T c5_ii_data[412800];
  int32_T c5_b_r_sizes;
  int32_T c5_loop_ub;
  int32_T c5_i13;
  static real_T c5_b_r_data[412800];
  int32_T c5_b_c_sizes;
  int32_T c5_b_loop_ub;
  int32_T c5_i14;
  static real_T c5_b_c_data[412800];
  int32_T c5_c_loop_ub;
  int32_T c5_i15;
  int32_T c5_d_loop_ub;
  int32_T c5_i16;
  int32_T c5_c_r_sizes;
  int32_T c5_e_loop_ub;
  int32_T c5_i17;
  static real_T c5_c_r_data[412800];
  int32_T c5_c_c_sizes;
  int32_T c5_f_loop_ub;
  int32_T c5_i18;
  static real_T c5_c_c_data[412800];
  int32_T c5_i19;
  real_T c5_varargin_1[6];
  int32_T c5_ixstart;
  real_T c5_mtmp;
  int32_T c5_itmp;
  real_T c5_c_x;
  boolean_T c5_c_b;
  int32_T c5_ix;
  int32_T c5_b_ix;
  real_T c5_d_x;
  boolean_T c5_d_b;
  int32_T c5_a;
  int32_T c5_i20;
  int32_T c5_c_ix;
  real_T c5_b_a;
  real_T c5_e_b;
  boolean_T c5_p;
  real_T c5_b_mtmp;
  int32_T c5_b_itmp;
  real_T c5_extremum;
  int32_T c5_iindx;
  real_T c5_minval;
  int32_T c5_b_iindx;
  real_T c5_indx;
  real_T c5_b_dX_up;
  real_T c5_b_I;
  int32_T c5_b_i;
  int32_T c5_b_j;
  real_T c5_A;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_y;
  real_T c5_c_a;
  real_T c5_f_b;
  real_T c5_b_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_b_A;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_c_y;
  real_T c5_d_a;
  real_T c5_g_b;
  real_T c5_d_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_d0;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_tmp_sizes;
  int32_T c5_g_loop_ub;
  int32_T c5_i23;
  int32_T c5_tmp_data[9];
  int32_T c5_b_tmp_sizes;
  int32_T c5_h_loop_ub;
  int32_T c5_i24;
  int32_T c5_b_tmp_data[9];
  int32_T c5_c_tmp_sizes[2];
  int32_T c5_iv0[2];
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i_loop_ub;
  int32_T c5_i27;
  real_T c5_c_tmp_data[9];
  int32_T c5_j_loop_ub;
  int32_T c5_i28;
  real_T c5_d1;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_k_loop_ub;
  int32_T c5_i31;
  int32_T c5_d_tmp_sizes;
  int32_T c5_l_loop_ub;
  int32_T c5_i32;
  int32_T c5_d_tmp_data[9];
  int32_T c5_iv1[2];
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_m_loop_ub;
  int32_T c5_i35;
  int32_T c5_n_loop_ub;
  int32_T c5_i36;
  int32_T c5_c_i;
  int32_T c5_c_j;
  real_T c5_c_A;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_e_y;
  real_T c5_e_a;
  real_T c5_h_b;
  real_T c5_f_y;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_d_A;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_g_y;
  real_T c5_f_a;
  real_T c5_i_b;
  real_T c5_h_y;
  real_T c5_s_x;
  real_T c5_t_x;
  int32_T c5_i37;
  int32_T c5_i38;
  uint32_T *c5_b_u2;
  real_T (*c5_b_yy)[412800];
  real_T (*c5_b_u3)[412800];
  uint32_T (*c5_b_u1)[412800];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T exitg1;
  c5_b_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_u2;
  for (c5_i5 = 0; c5_i5 < 412800; c5_i5++) {
    c5_u1[c5_i5] = (*c5_b_u1)[c5_i5];
  }

  c5_u2 = c5_hoistedGlobal;
  for (c5_i6 = 0; c5_i6 < 412800; c5_i6++) {
    c5_u3[c5_i6] = (*c5_b_u3)[c5_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 23U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_L, 0U, c5_c_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_N, MAX_uint32_T, c5_b_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Ir, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dX, 3U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dY, 4U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_k, 5U, c5_b_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c5_r_data, (const int32_T *)
    &c5_r_sizes, NULL, 0, 6, (void *)c5_e_sf_marshallOut, (void *)
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c5_c_data, (const int32_T *)
    &c5_c_sizes, NULL, 0, 7, (void *)c5_e_sf_marshallOut, (void *)
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_mm, 8U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nn, 9U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dX_up, 10U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_I, 11U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 12U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 13U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i1, 14U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j1, 15U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_N, MAX_uint32_T,
    c5_d_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 16U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 17U, c5_d_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_u1, 18U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_u2, 19U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_u3, 20U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_yy, 21U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  for (c5_i7 = 0; c5_i7 < 412800; c5_i7++) {
    c5_L[c5_i7] = c5_u1[c5_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_N = c5_u2;
  _SFD_SYMBOL_SWITCH(1U, 1U);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  for (c5_i8 = 0; c5_i8 < 412800; c5_i8++) {
    c5_Ir[c5_i8] = c5_u3[c5_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  for (c5_i9 = 0; c5_i9 < 10; c5_i9++) {
    c5_dX[c5_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  for (c5_i10 = 0; c5_i10 < 10; c5_i10++) {
    c5_dY[c5_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_c_N = c5_N;
  c5_b = c5_c_N;
  c5_b_b = c5_b;
  if (1U > c5_b_b) {
    c5_overflow = FALSE;
  } else {
    c5_overflow = (c5_b_b > 4294967294U);
  }

  if (c5_overflow) {
    c5_check_forloop_overflow_error(chartInstance, TRUE);
  }

  c5_k = 1U;
  c5_b_k = 1U;
  while (c5_b_k <= c5_c_N) {
    c5_k = c5_b_k;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
    for (c5_i11 = 0; c5_i11 < 412800; c5_i11++) {
      c5_x[c5_i11] = (c5_L[c5_i11] == c5_k);
    }

    for (c5_i12 = 0; c5_i12 < 412800; c5_i12++) {
      c5_b_x[c5_i12] = c5_x[c5_i12];
    }

    c5_eml_find(chartInstance, c5_b_x, c5_ii_data, *(int32_T (*)[1])&c5_ii_sizes,
                c5_jj_data, *(int32_T (*)[1])&c5_jj_sizes);
    c5_b_r_sizes = c5_ii_sizes;
    c5_loop_ub = c5_ii_sizes - 1;
    for (c5_i13 = 0; c5_i13 <= c5_loop_ub; c5_i13++) {
      c5_b_r_data[c5_i13] = (real_T)c5_ii_data[c5_i13];
    }

    c5_b_c_sizes = c5_jj_sizes;
    c5_b_loop_ub = c5_jj_sizes - 1;
    for (c5_i14 = 0; c5_i14 <= c5_b_loop_ub; c5_i14++) {
      c5_b_c_data[c5_i14] = (real_T)c5_jj_data[c5_i14];
    }

    c5_r_sizes = c5_b_r_sizes;
    c5_c_loop_ub = c5_b_r_sizes - 1;
    for (c5_i15 = 0; c5_i15 <= c5_c_loop_ub; c5_i15++) {
      c5_r_data[c5_i15] = c5_b_r_data[c5_i15];
    }

    c5_c_sizes = c5_b_c_sizes;
    c5_d_loop_ub = c5_b_c_sizes - 1;
    for (c5_i16 = 0; c5_i16 <= c5_d_loop_ub; c5_i16++) {
      c5_c_data[c5_i16] = c5_b_c_data[c5_i16];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
    c5_c_r_sizes = c5_r_sizes;
    c5_e_loop_ub = c5_r_sizes - 1;
    for (c5_i17 = 0; c5_i17 <= c5_e_loop_ub; c5_i17++) {
      c5_c_r_data[c5_i17] = c5_r_data[c5_i17];
    }

    c5_dX[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c5_k, 1,
      10, 1, 0) - 1] = c5_mean(chartInstance, c5_c_r_data, *(int32_T (*)[1])&
      c5_c_r_sizes);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
    c5_c_c_sizes = c5_c_sizes;
    c5_f_loop_ub = c5_c_sizes - 1;
    for (c5_i18 = 0; c5_i18 <= c5_f_loop_ub; c5_i18++) {
      c5_c_c_data[c5_i18] = c5_c_data[c5_i18];
    }

    c5_dY[(int32_T)c5_k - 1] = c5_mean(chartInstance, c5_c_c_data, *(int32_T (*)
      [1])&c5_c_c_sizes);
    c5_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_mm = 480.0;
  c5_nn = 860.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
  if (CV_EML_IF(0, 1, 0, (real_T)c5_N == 6.0)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
    for (c5_i19 = 0; c5_i19 < 6; c5_i19++) {
      c5_varargin_1[c5_i19] = c5_dX[c5_i19];
    }

    c5_ixstart = 1;
    c5_mtmp = c5_varargin_1[0];
    c5_itmp = 1;
    c5_c_x = c5_mtmp;
    c5_c_b = muDoubleScalarIsNaN(c5_c_x);
    if (c5_c_b) {
      c5_ix = 2;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (c5_ix < 7)) {
        c5_b_ix = c5_ix;
        c5_ixstart = c5_b_ix;
        c5_d_x = c5_varargin_1[c5_b_ix - 1];
        c5_d_b = muDoubleScalarIsNaN(c5_d_x);
        if (!c5_d_b) {
          c5_mtmp = c5_varargin_1[c5_b_ix - 1];
          c5_itmp = c5_b_ix;
          exitg1 = TRUE;
        } else {
          c5_ix++;
        }
      }
    }

    if (c5_ixstart < 6) {
      c5_a = c5_ixstart + 1;
      c5_i20 = c5_a;
      for (c5_c_ix = c5_i20; c5_c_ix < 7; c5_c_ix++) {
        c5_b_ix = c5_c_ix - 1;
        c5_b_a = c5_varargin_1[c5_b_ix];
        c5_e_b = c5_mtmp;
        c5_p = (c5_b_a < c5_e_b);
        if (c5_p) {
          c5_mtmp = c5_varargin_1[c5_b_ix];
          c5_itmp = c5_b_ix + 1;
        }
      }
    }

    c5_b_mtmp = c5_mtmp;
    c5_b_itmp = c5_itmp;
    c5_extremum = c5_b_mtmp;
    c5_iindx = c5_b_itmp;
    c5_minval = c5_extremum;
    c5_b_iindx = c5_iindx;
    c5_indx = (real_T)c5_b_iindx;
    c5_b_dX_up = c5_minval;
    c5_b_I = c5_indx;
    c5_dX_up = c5_b_dX_up;
    c5_I = c5_b_I;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
    c5_i = 1.0;
    c5_b_i = 0;
    while (c5_b_i < 6) {
      c5_i = 1.0 + (real_T)c5_b_i;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
      if (CV_EML_IF(0, 1, 1, c5_i != c5_I)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 28);
        c5_j = 1.0;
        c5_b_j = 0;
        while (c5_b_j < 29) {
          c5_j = 1.0 + (real_T)c5_b_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
          c5_A = c5_dX[(int32_T)c5_i - 1] - c5_dX[(int32_T)c5_I - 1];
          c5_e_x = c5_A;
          c5_f_x = c5_e_x;
          c5_y = c5_f_x / 30.0;
          c5_c_a = c5_y;
          c5_f_b = c5_j;
          c5_b_y = c5_c_a * c5_f_b;
          c5_g_x = c5_dX[(int32_T)c5_I - 1] + c5_b_y;
          c5_i1 = c5_g_x;
          c5_h_x = c5_i1;
          c5_i1 = c5_h_x;
          c5_i1 = muDoubleScalarFloor(c5_i1);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
          c5_b_A = c5_dY[(int32_T)c5_i - 1] - c5_dY[(int32_T)c5_I - 1];
          c5_i_x = c5_b_A;
          c5_j_x = c5_i_x;
          c5_c_y = c5_j_x / 30.0;
          c5_d_a = c5_c_y;
          c5_g_b = c5_j;
          c5_d_y = c5_d_a * c5_g_b;
          c5_k_x = c5_dY[(int32_T)c5_I - 1] + c5_d_y;
          c5_j1 = c5_k_x;
          c5_l_x = c5_j1;
          c5_j1 = c5_l_x;
          c5_j1 = muDoubleScalarFloor(c5_j1);
          _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
          guard4 = FALSE;
          guard5 = FALSE;
          guard6 = FALSE;
          if (CV_EML_COND(0, 1, 0, c5_i1 >= 1.0)) {
            if (CV_EML_COND(0, 1, 1, c5_j1 >= 1.0)) {
              if (CV_EML_COND(0, 1, 2, c5_i1 <= 480.0)) {
                if (CV_EML_COND(0, 1, 3, c5_j1 <= 860.0)) {
                  CV_EML_MCDC(0, 1, 0, TRUE);
                  CV_EML_IF(0, 1, 2, TRUE);
                  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
                  c5_Ir[((int32_T)c5_i1 + 480 * ((int32_T)c5_j1 - 1)) - 1] = 1.0;
                } else {
                  guard4 = TRUE;
                }
              } else {
                guard5 = TRUE;
              }
            } else {
              guard6 = TRUE;
            }
          } else {
            guard6 = TRUE;
          }

          if (guard6 == TRUE) {
            guard5 = TRUE;
          }

          if (guard5 == TRUE) {
            guard4 = TRUE;
          }

          if (guard4 == TRUE) {
            CV_EML_MCDC(0, 1, 0, FALSE);
            CV_EML_IF(0, 1, 2, FALSE);
          }

          c5_b_j++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
      }

      c5_b_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
    c5_d0 = c5_I + 1.0;
    c5_i21 = (int32_T)c5_d0;
    c5_i22 = (int32_T)c5_I;
    c5_tmp_sizes = 10 - c5_i22;
    c5_g_loop_ub = 9 - c5_i22;
    for (c5_i23 = 0; c5_i23 <= c5_g_loop_ub; c5_i23++) {
      c5_tmp_data[c5_i23] = c5_i22 + c5_i23;
    }

    c5_b_tmp_sizes = 11 - c5_i21;
    c5_h_loop_ub = 10 - c5_i21;
    for (c5_i24 = 0; c5_i24 <= c5_h_loop_ub; c5_i24++) {
      c5_b_tmp_data[c5_i24] = c5_i21 + c5_i24;
    }

    c5_c_tmp_sizes[0] = 1;
    c5_iv0[0] = 1;
    c5_iv0[1] = c5_b_tmp_sizes;
    c5_c_tmp_sizes[1] = c5_iv0[1];
    c5_i25 = c5_c_tmp_sizes[0];
    c5_i26 = c5_c_tmp_sizes[1];
    c5_i_loop_ub = c5_b_tmp_sizes - 1;
    for (c5_i27 = 0; c5_i27 <= c5_i_loop_ub; c5_i27++) {
      c5_c_tmp_data[c5_i27] = c5_dX[c5_b_tmp_data[c5_i27] - 1];
    }

    _SFD_SIZE_EQ_CHECK_1D(c5_tmp_sizes, c5_c_tmp_sizes[1]);
    c5_j_loop_ub = c5_c_tmp_sizes[0] * c5_c_tmp_sizes[1] - 1;
    for (c5_i28 = 0; c5_i28 <= c5_j_loop_ub; c5_i28++) {
      c5_dX[c5_tmp_data[c5_i28] - 1] = c5_c_tmp_data[c5_i28];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 38);
    c5_d1 = c5_I + 1.0;
    c5_i29 = (int32_T)c5_d1;
    c5_i30 = (int32_T)c5_I;
    c5_tmp_sizes = 10 - c5_i30;
    c5_k_loop_ub = 9 - c5_i30;
    for (c5_i31 = 0; c5_i31 <= c5_k_loop_ub; c5_i31++) {
      c5_tmp_data[c5_i31] = c5_i30 + c5_i31;
    }

    c5_d_tmp_sizes = 11 - c5_i29;
    c5_l_loop_ub = 10 - c5_i29;
    for (c5_i32 = 0; c5_i32 <= c5_l_loop_ub; c5_i32++) {
      c5_d_tmp_data[c5_i32] = c5_i29 + c5_i32;
    }

    c5_c_tmp_sizes[0] = 1;
    c5_iv1[0] = 1;
    c5_iv1[1] = c5_d_tmp_sizes;
    c5_c_tmp_sizes[1] = c5_iv1[1];
    c5_i33 = c5_c_tmp_sizes[0];
    c5_i34 = c5_c_tmp_sizes[1];
    c5_m_loop_ub = c5_d_tmp_sizes - 1;
    for (c5_i35 = 0; c5_i35 <= c5_m_loop_ub; c5_i35++) {
      c5_c_tmp_data[c5_i35] = c5_dY[c5_d_tmp_data[c5_i35] - 1];
    }

    _SFD_SIZE_EQ_CHECK_1D(c5_tmp_sizes, c5_c_tmp_sizes[1]);
    c5_n_loop_ub = c5_c_tmp_sizes[0] * c5_c_tmp_sizes[1] - 1;
    for (c5_i36 = 0; c5_i36 <= c5_n_loop_ub; c5_i36++) {
      c5_dY[c5_tmp_data[c5_i36] - 1] = c5_c_tmp_data[c5_i36];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
    c5_b_N = 5.0;
    _SFD_SYMBOL_SWITCH(1U, 16U);
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
  c5_i = 1.0;
  c5_c_i = 0;
  while (c5_c_i < 4) {
    c5_i = 1.0 + (real_T)c5_c_i;
    CV_EML_FOR(0, 1, 3, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 44);
    c5_j = 1.0;
    c5_c_j = 0;
    while (c5_c_j < 19) {
      c5_j = 1.0 + (real_T)c5_c_j;
      CV_EML_FOR(0, 1, 4, 1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 45);
      c5_c_A = c5_dX[(int32_T)(c5_i + 1.0) - 1] - c5_dX[(int32_T)c5_i - 1];
      c5_m_x = c5_c_A;
      c5_n_x = c5_m_x;
      c5_e_y = c5_n_x / 20.0;
      c5_e_a = c5_e_y;
      c5_h_b = c5_j;
      c5_f_y = c5_e_a * c5_h_b;
      c5_o_x = c5_dX[(int32_T)c5_i - 1] + c5_f_y;
      c5_i1 = c5_o_x;
      c5_p_x = c5_i1;
      c5_i1 = c5_p_x;
      c5_i1 = muDoubleScalarFloor(c5_i1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 46);
      c5_d_A = c5_dY[(int32_T)(c5_i + 1.0) - 1] - c5_dY[(int32_T)c5_i - 1];
      c5_q_x = c5_d_A;
      c5_r_x = c5_q_x;
      c5_g_y = c5_r_x / 20.0;
      c5_f_a = c5_g_y;
      c5_i_b = c5_j;
      c5_h_y = c5_f_a * c5_i_b;
      c5_s_x = c5_dY[(int32_T)c5_i - 1] + c5_h_y;
      c5_j1 = c5_s_x;
      c5_t_x = c5_j1;
      c5_j1 = c5_t_x;
      c5_j1 = muDoubleScalarFloor(c5_j1);
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 47);
      guard1 = FALSE;
      guard2 = FALSE;
      guard3 = FALSE;
      if (CV_EML_COND(0, 1, 4, c5_i1 >= 1.0)) {
        if (CV_EML_COND(0, 1, 5, c5_j1 >= 1.0)) {
          if (CV_EML_COND(0, 1, 6, c5_i1 <= 480.0)) {
            if (CV_EML_COND(0, 1, 7, c5_j1 <= 860.0)) {
              CV_EML_MCDC(0, 1, 1, TRUE);
              CV_EML_IF(0, 1, 3, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 48);
              c5_Ir[((int32_T)c5_i1 + 480 * ((int32_T)c5_j1 - 1)) - 1] = 1.0;
            } else {
              guard1 = TRUE;
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
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 3, FALSE);
      }

      c5_c_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 4, 0);
    c5_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 3, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 100);
  for (c5_i37 = 0; c5_i37 < 412800; c5_i37++) {
    c5_yy[c5_i37] = c5_Ir[c5_i37];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -100);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i38 = 0; c5_i38 < 412800; c5_i38++) {
    (*c5_b_yy)[c5_i38] = c5_yy[c5_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void registerMessagesc5_DrogueVisualNavigation3
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  static real_T c5_b_inData[412800];
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  static real_T c5_u[412800];
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i39 = 0;
  for (c5_i40 = 0; c5_i40 < 860; c5_i40++) {
    for (c5_i41 = 0; c5_i41 < 480; c5_i41++) {
      c5_b_inData[c5_i41 + c5_i39] = (*(real_T (*)[412800])c5_inData)[c5_i41 +
        c5_i39];
    }

    c5_i39 += 480;
  }

  c5_i42 = 0;
  for (c5_i43 = 0; c5_i43 < 860; c5_i43++) {
    for (c5_i44 = 0; c5_i44 < 480; c5_i44++) {
      c5_u[c5_i44 + c5_i42] = c5_b_inData[c5_i44 + c5_i42];
    }

    c5_i42 += 480;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_yy, const char_T *c5_identifier, real_T
  c5_y[412800])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_yy), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_yy);
}

static void c5_b_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[412800])
{
  static real_T c5_dv1[412800];
  int32_T c5_i45;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 480,
                860);
  for (c5_i45 = 0; c5_i45 < 412800; c5_i45++) {
    c5_y[c5_i45] = c5_dv1[c5_i45];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_yy;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  static real_T c5_y[412800];
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_yy = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_yy), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_yy);
  c5_i46 = 0;
  for (c5_i47 = 0; c5_i47 < 860; c5_i47++) {
    for (c5_i48 = 0; c5_i48 < 480; c5_i48++) {
      (*(real_T (*)[412800])c5_outData)[c5_i48 + c5_i46] = c5_y[c5_i48 + c5_i46];
    }

    c5_i46 += 480;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  uint32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(uint32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  static uint32_T c5_b_inData[412800];
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  static uint32_T c5_u[412800];
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i49 = 0;
  for (c5_i50 = 0; c5_i50 < 860; c5_i50++) {
    for (c5_i51 = 0; c5_i51 < 480; c5_i51++) {
      c5_b_inData[c5_i51 + c5_i49] = (*(uint32_T (*)[412800])c5_inData)[c5_i51 +
        c5_i49];
    }

    c5_i49 += 480;
  }

  c5_i52 = 0;
  for (c5_i53 = 0; c5_i53 < 860; c5_i53++) {
    for (c5_i54 = 0; c5_i54 < 480; c5_i54++) {
      c5_u[c5_i54 + c5_i52] = c5_b_inData[c5_i54 + c5_i52];
    }

    c5_i52 += 480;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 7, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d2;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d2;
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
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, real_T
  c5_inData_data[412800], int32_T c5_inData_sizes[1])
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_b_inData_sizes;
  int32_T c5_loop_ub;
  int32_T c5_i55;
  static real_T c5_b_inData_data[412800];
  int32_T c5_u_sizes;
  int32_T c5_b_loop_ub;
  int32_T c5_i56;
  static real_T c5_u_data[412800];
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_inData_sizes = c5_inData_sizes[0];
  c5_loop_ub = c5_inData_sizes[0] - 1;
  for (c5_i55 = 0; c5_i55 <= c5_loop_ub; c5_i55++) {
    c5_b_inData_data[c5_i55] = c5_inData_data[c5_i55];
  }

  c5_u_sizes = c5_b_inData_sizes;
  c5_b_loop_ub = c5_b_inData_sizes - 1;
  for (c5_i56 = 0; c5_i56 <= c5_b_loop_ub; c5_i56++) {
    c5_u_data[c5_i56] = c5_b_inData_data[c5_i56];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u_data, 0, 0U, 1U, 0U, 1,
    c5_u_sizes), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y_data[412800], int32_T c5_y_sizes[1])
{
  static uint32_T c5_uv0[1] = { 412800U };

  uint32_T c5_uv1[1];
  static boolean_T c5_bv0[1] = { TRUE };

  boolean_T c5_bv1[1];
  int32_T c5_tmp_sizes;
  static real_T c5_tmp_data[412800];
  int32_T c5_loop_ub;
  int32_T c5_i57;
  c5_uv1[0] = c5_uv0[0];
  c5_bv1[0] = c5_bv0[0];
  sf_mex_import_vs(c5_parentId, sf_mex_dup(c5_u), c5_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c5_bv1, c5_uv1, &c5_tmp_sizes);
  c5_y_sizes[0] = c5_tmp_sizes;
  c5_loop_ub = c5_tmp_sizes - 1;
  for (c5_i57 = 0; c5_i57 <= c5_loop_ub; c5_i57++) {
    c5_y_data[c5_i57] = c5_tmp_data[c5_i57];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, real_T c5_outData_data[412800],
  int32_T c5_outData_sizes[1])
{
  const mxArray *c5_c;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y_sizes;
  static real_T c5_y_data[412800];
  int32_T c5_loop_ub;
  int32_T c5_i58;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_c = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c), &c5_thisId, c5_y_data, *
                        (int32_T (*)[1])&c5_y_sizes);
  sf_mex_destroy(&c5_c);
  c5_outData_sizes[0] = c5_y_sizes;
  c5_loop_ub = c5_y_sizes - 1;
  for (c5_i58 = 0; c5_i58 <= c5_loop_ub; c5_i58++) {
    c5_outData_data[c5_i58] = c5_y_data[c5_i58];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static uint32_T c5_e_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint32_T c5_y;
  uint32_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 7, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_k;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  uint32_T c5_y;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_k = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_k), &c5_thisId);
  sf_mex_destroy(&c5_k);
  *(uint32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i59;
  real_T c5_b_inData[10];
  int32_T c5_i60;
  real_T c5_u[10];
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i59 = 0; c5_i59 < 10; c5_i59++) {
    c5_b_inData[c5_i59] = (*(real_T (*)[10])c5_inData)[c5_i59];
  }

  for (c5_i60 = 0; c5_i60 < 10; c5_i60++) {
    c5_u[c5_i60] = c5_b_inData[c5_i60];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[10])
{
  real_T c5_dv2[10];
  int32_T c5_i61;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 1, 10);
  for (c5_i61 = 0; c5_i61 < 10; c5_i61++) {
    c5_y[c5_i61] = c5_dv2[c5_i61];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_dY;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[10];
  int32_T c5_i62;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_dY = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_dY), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_dY);
  for (c5_i62 = 0; c5_i62 < 10; c5_i62++) {
    (*(real_T (*)[10])c5_outData)[c5_i62] = c5_y[c5_i62];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_g_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  uint32_T c5_y[412800])
{
  static uint32_T c5_uv2[412800];
  int32_T c5_i63;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_uv2, 1, 7, 0U, 1, 0U, 2, 480,
                860);
  for (c5_i63 = 0; c5_i63 < 412800; c5_i63++) {
    c5_y[c5_i63] = c5_uv2[c5_i63];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_L;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  static uint32_T c5_y[412800];
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_L = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_L), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_L);
  c5_i64 = 0;
  for (c5_i65 = 0; c5_i65 < 860; c5_i65++) {
    for (c5_i66 = 0; c5_i66 < 480; c5_i66++) {
      (*(uint32_T (*)[412800])c5_outData)[c5_i66 + c5_i64] = c5_y[c5_i66 +
        c5_i64];
    }

    c5_i64 += 480;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_DrogueVisualNavigation3_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[37];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i67;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 37), FALSE);
  for (c5_i67 = 0; c5_i67 < 37; c5_i67++) {
    c5_r0 = &c5_info[c5_i67];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i67);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i67);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[37])
{
  c5_info[0].context = "";
  c5_info[0].name = "eml_int_forloop_overflow_check";
  c5_info[0].dominantType = "";
  c5_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[0].fileTimeLo = 1346488740U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c5_info[1].name = "intmax";
  c5_info[1].dominantType = "char";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[1].fileTimeLo = 1311233716U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "";
  c5_info[2].name = "find";
  c5_info[2].dominantType = "logical";
  c5_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c5_info[2].fileTimeLo = 1303124606U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c5_info[3].name = "eml_index_class";
  c5_info[3].dominantType = "";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[3].fileTimeLo = 1323145378U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c5_info[4].name = "eml_scalar_eg";
  c5_info[4].dominantType = "logical";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[4].fileTimeLo = 1286797196U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  c5_info[5].name = "eml_index_plus";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[5].fileTimeLo = 1286797178U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[6].name = "eml_index_class";
  c5_info[6].dominantType = "";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[6].fileTimeLo = 1323145378U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "";
  c5_info[7].name = "mean";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c5_info[7].fileTimeLo = 1286797094U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c5_info[8].name = "isequal";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c5_info[8].fileTimeLo = 1286797158U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c5_info[9].name = "eml_isequal_core";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c5_info[9].fileTimeLo = 1286797186U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c5_info[10].name = "eml_const_nonsingleton_dim";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c5_info[10].fileTimeLo = 1286797096U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c5_info[11].name = "sum";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c5_info[11].fileTimeLo = 1314715012U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c5_info[12].name = "eml_assert_valid_dim";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c5_info[12].fileTimeLo = 1286797094U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c5_info[13].name = "eml_scalar_floor";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[13].fileTimeLo = 1286797126U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c5_info[14].name = "eml_index_class";
  c5_info[14].dominantType = "";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[14].fileTimeLo = 1323145378U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c5_info[15].name = "intmax";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[15].fileTimeLo = 1311233716U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c5_info[16].name = "eml_index_class";
  c5_info[16].dominantType = "";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[16].fileTimeLo = 1323145378U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c5_info[17].name = "eml_scalar_eg";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[17].fileTimeLo = 1286797196U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c5_info[18].name = "eml_int_forloop_overflow_check";
  c5_info[18].dominantType = "";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[18].fileTimeLo = 1346488740U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m";
  c5_info[19].name = "rdivide";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[19].fileTimeLo = 1346488788U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[20].name = "eml_scalexp_compatible";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c5_info[20].fileTimeLo = 1286797196U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[21].name = "eml_div";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[21].fileTimeLo = 1313326210U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context = "";
  c5_info[22].name = "min";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[22].fileTimeLo = 1311233718U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[23].name = "eml_min_or_max";
  c5_info[23].dominantType = "char";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[23].fileTimeLo = 1334049890U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c5_info[24].name = "eml_const_nonsingleton_dim";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c5_info[24].fileTimeLo = 1286797096U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c5_info[25].name = "eml_scalar_eg";
  c5_info[25].dominantType = "double";
  c5_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[25].fileTimeLo = 1286797196U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 0U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c5_info[26].name = "eml_index_class";
  c5_info[26].dominantType = "";
  c5_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[26].fileTimeLo = 1323145378U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c5_info[27].name = "eml_index_class";
  c5_info[27].dominantType = "";
  c5_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[27].fileTimeLo = 1323145378U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 0U;
  c5_info[27].mFileTimeHi = 0U;
  c5_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c5_info[28].name = "isnan";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[28].fileTimeLo = 1286797160U;
  c5_info[28].fileTimeHi = 0U;
  c5_info[28].mFileTimeLo = 0U;
  c5_info[28].mFileTimeHi = 0U;
  c5_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c5_info[29].name = "eml_index_plus";
  c5_info[29].dominantType = "coder.internal.indexInt";
  c5_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[29].fileTimeLo = 1286797178U;
  c5_info[29].fileTimeHi = 0U;
  c5_info[29].mFileTimeLo = 0U;
  c5_info[29].mFileTimeHi = 0U;
  c5_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c5_info[30].name = "eml_int_forloop_overflow_check";
  c5_info[30].dominantType = "";
  c5_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[30].fileTimeLo = 1346488740U;
  c5_info[30].fileTimeHi = 0U;
  c5_info[30].mFileTimeLo = 0U;
  c5_info[30].mFileTimeHi = 0U;
  c5_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c5_info[31].name = "eml_relop";
  c5_info[31].dominantType = "function_handle";
  c5_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c5_info[31].fileTimeLo = 1342429582U;
  c5_info[31].fileTimeHi = 0U;
  c5_info[31].mFileTimeLo = 0U;
  c5_info[31].mFileTimeHi = 0U;
  c5_info[32].context = "";
  c5_info[32].name = "mrdivide";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[32].fileTimeLo = 1357926348U;
  c5_info[32].fileTimeHi = 0U;
  c5_info[32].mFileTimeLo = 1319708366U;
  c5_info[32].mFileTimeHi = 0U;
  c5_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[33].name = "rdivide";
  c5_info[33].dominantType = "double";
  c5_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[33].fileTimeLo = 1346488788U;
  c5_info[33].fileTimeHi = 0U;
  c5_info[33].mFileTimeLo = 0U;
  c5_info[33].mFileTimeHi = 0U;
  c5_info[34].context = "";
  c5_info[34].name = "mtimes";
  c5_info[34].dominantType = "double";
  c5_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[34].fileTimeLo = 1289494492U;
  c5_info[34].fileTimeHi = 0U;
  c5_info[34].mFileTimeLo = 0U;
  c5_info[34].mFileTimeHi = 0U;
  c5_info[35].context = "";
  c5_info[35].name = "floor";
  c5_info[35].dominantType = "double";
  c5_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[35].fileTimeLo = 1343808780U;
  c5_info[35].fileTimeHi = 0U;
  c5_info[35].mFileTimeLo = 0U;
  c5_info[35].mFileTimeHi = 0U;
  c5_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[36].name = "eml_scalar_floor";
  c5_info[36].dominantType = "double";
  c5_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[36].fileTimeLo = 1286797126U;
  c5_info[36].fileTimeHi = 0U;
  c5_info[36].mFileTimeLo = 0U;
  c5_info[36].mFileTimeHi = 0U;
}

static void c5_check_forloop_overflow_error
  (SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c5_overflow)
{
  int32_T c5_i68;
  static char_T c5_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c5_u[34];
  const mxArray *c5_y = NULL;
  int32_T c5_i69;
  static char_T c5_cv1[6] = { 'u', 'i', 'n', 't', '3', '2' };

  char_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  for (c5_i68 = 0; c5_i68 < 34; c5_i68++) {
    c5_u[c5_i68] = c5_cv0[c5_i68];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  for (c5_i69 = 0; c5_i69 < 6; c5_i69++) {
    c5_b_u[c5_i69] = c5_cv1[c5_i69];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c5_y, 14, c5_b_y));
}

static void c5_eml_find(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance, boolean_T c5_x[412800], int32_T c5_i_data[412800], int32_T
  c5_i_sizes[1], int32_T c5_j_data[412800], int32_T c5_j_sizes[1])
{
  int32_T c5_idx;
  static int32_T c5_iv2[1] = { 412800 };

  int32_T c5_ii;
  int32_T c5_jj;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_c_a;
  boolean_T c5_b0;
  boolean_T c5_b1;
  boolean_T c5_b2;
  int32_T c5_i70;
  int32_T c5_tmp_sizes;
  int32_T c5_loop_ub;
  int32_T c5_i71;
  static int32_T c5_tmp_data[412800];
  int32_T c5_b_i_sizes;
  int32_T c5_b_loop_ub;
  int32_T c5_i72;
  static int32_T c5_b_i_data[412800];
  int32_T c5_c_loop_ub;
  int32_T c5_i73;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  int32_T c5_i74;
  int32_T c5_d_loop_ub;
  int32_T c5_i75;
  int32_T c5_b_j_sizes;
  int32_T c5_e_loop_ub;
  int32_T c5_i76;
  static int32_T c5_b_j_data[412800];
  int32_T c5_f_loop_ub;
  int32_T c5_i77;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  int32_T c5_i78;
  int32_T c5_g_loop_ub;
  int32_T c5_i79;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  c5_eml_scalar_eg(chartInstance);
  c5_idx = 0;
  c5_i_sizes[0] = c5_iv2[0];
  c5_j_sizes[0] = c5_iv2[0];
  c5_ii = 1;
  c5_jj = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c5_jj <= 860)) {
    guard1 = FALSE;
    if (c5_x[(c5_ii + 480 * (c5_jj - 1)) - 1]) {
      c5_a = c5_idx + 1;
      c5_idx = c5_a;
      c5_i_data[c5_idx - 1] = c5_ii;
      c5_j_data[c5_idx - 1] = c5_jj;
      if (c5_idx >= 412800) {
        exitg1 = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      c5_b_a = c5_ii + 1;
      c5_ii = c5_b_a;
      if (c5_ii > 480) {
        c5_ii = 1;
        c5_c_a = c5_jj + 1;
        c5_jj = c5_c_a;
      }
    }
  }

  c5_b0 = (1 > c5_idx);
  c5_b1 = c5_b0;
  c5_b2 = c5_b1;
  if (c5_b2) {
    c5_i70 = 0;
  } else {
    c5_i70 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c5_idx, 1, 412800, 0, 0);
  }

  c5_tmp_sizes = c5_i70;
  c5_loop_ub = c5_i70 - 1;
  for (c5_i71 = 0; c5_i71 <= c5_loop_ub; c5_i71++) {
    c5_tmp_data[c5_i71] = 1 + c5_i71;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c5_tmp_sizes);
  c5_b_i_sizes = c5_tmp_sizes;
  c5_b_loop_ub = c5_tmp_sizes - 1;
  for (c5_i72 = 0; c5_i72 <= c5_b_loop_ub; c5_i72++) {
    c5_b_i_data[c5_i72] = c5_i_data[c5_tmp_data[c5_i72] - 1];
  }

  c5_i_sizes[0] = c5_b_i_sizes;
  c5_c_loop_ub = c5_b_i_sizes - 1;
  for (c5_i73 = 0; c5_i73 <= c5_c_loop_ub; c5_i73++) {
    c5_i_data[c5_i73] = c5_b_i_data[c5_i73];
  }

  c5_b3 = (1 > c5_idx);
  c5_b4 = c5_b3;
  c5_b5 = c5_b4;
  if (c5_b5) {
    c5_i74 = 0;
  } else {
    c5_i74 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c5_idx, 1, 412800, 0, 0);
  }

  c5_tmp_sizes = c5_i74;
  c5_d_loop_ub = c5_i74 - 1;
  for (c5_i75 = 0; c5_i75 <= c5_d_loop_ub; c5_i75++) {
    c5_tmp_data[c5_i75] = 1 + c5_i75;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c5_tmp_sizes);
  c5_b_j_sizes = c5_tmp_sizes;
  c5_e_loop_ub = c5_tmp_sizes - 1;
  for (c5_i76 = 0; c5_i76 <= c5_e_loop_ub; c5_i76++) {
    c5_b_j_data[c5_i76] = c5_j_data[c5_tmp_data[c5_i76] - 1];
  }

  c5_j_sizes[0] = c5_b_j_sizes;
  c5_f_loop_ub = c5_b_j_sizes - 1;
  for (c5_i77 = 0; c5_i77 <= c5_f_loop_ub; c5_i77++) {
    c5_j_data[c5_i77] = c5_b_j_data[c5_i77];
  }

  c5_b6 = (1 > c5_idx);
  c5_b7 = c5_b6;
  c5_b8 = c5_b7;
  if (c5_b8) {
    c5_i78 = 0;
  } else {
    c5_i78 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c5_idx, 1, 412800, 0, 0);
  }

  c5_tmp_sizes = c5_i78;
  c5_g_loop_ub = c5_i78 - 1;
  for (c5_i79 = 0; c5_i79 <= c5_g_loop_ub; c5_i79++) {
    c5_tmp_data[c5_i79] = 1 + c5_i79;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c5_tmp_sizes);
}

static void c5_eml_scalar_eg(SFc5_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static real_T c5_mean(SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c5_x_data[412800], int32_T c5_x_sizes[1])
{
  boolean_T c5_p;
  boolean_T c5_b_p;
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_d3;
  real_T c5_d4;
  boolean_T c5_b9;
  boolean_T c5_c_p;
  boolean_T c5_b10;
  int32_T c5_i80;
  static char_T c5_cv2[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  char_T c5_u[31];
  const mxArray *c5_b_y = NULL;
  boolean_T c5_b11;
  int32_T c5_i81;
  static char_T c5_cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  char_T c5_b_u[36];
  const mxArray *c5_c_y = NULL;
  real_T c5_d_y;
  int32_T c5_vlen;
  int32_T c5_b_vlen;
  int32_T c5_c_k;
  int32_T c5_d_k;
  real_T c5_x;
  real_T c5_e_y;
  real_T c5_b_x;
  real_T c5_f_y;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  c5_p = FALSE;
  c5_b_p = FALSE;
  c5_k = 0;
  do {
    exitg1 = 0;
    if (c5_k < 2) {
      c5_b_k = 1.0 + (real_T)c5_k;
      c5_d3 = c5_b_k;
      if (c5_d3 <= 1.0) {
        c5_d4 = (real_T)c5_x_sizes[0];
      } else {
        c5_d4 = 1.0;
      }

      if (c5_d4 != 0.0) {
        exitg1 = 1;
      } else {
        c5_k++;
      }
    } else {
      c5_b_p = TRUE;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  c5_b9 = c5_b_p;
  c5_c_p = c5_b9;
  if (!c5_c_p) {
  } else {
    c5_p = TRUE;
  }

  c5_b10 = !c5_p;
  if (c5_b10) {
  } else {
    for (c5_i80 = 0; c5_i80 < 31; c5_i80++) {
      c5_u[c5_i80] = c5_cv2[c5_i80];
    }

    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 31),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c5_b_y));
  }

  guard1 = FALSE;
  if (c5_x_sizes[0] == 1) {
    guard1 = TRUE;
  } else if ((real_T)c5_x_sizes[0] != 1.0) {
    guard1 = TRUE;
  } else {
    c5_b11 = FALSE;
  }

  if (guard1 == TRUE) {
    c5_b11 = TRUE;
  }

  if (c5_b11) {
  } else {
    for (c5_i81 = 0; c5_i81 < 36; c5_i81++) {
      c5_b_u[c5_i81] = c5_cv3[c5_i81];
    }

    c5_c_y = NULL;
    sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c5_c_y));
  }

  if (c5_x_sizes[0] == 0) {
    c5_d_y = 0.0;
  } else {
    c5_vlen = (int32_T)(real_T)c5_x_sizes[0];
    c5_d_y = c5_x_data[0];
    c5_b_vlen = c5_vlen;
    for (c5_c_k = 2; c5_c_k <= c5_b_vlen; c5_c_k++) {
      c5_d_k = c5_c_k;
      c5_d_y += c5_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_d_k, 1, c5_x_sizes
        [0], 1, 0) - 1];
    }
  }

  c5_x = c5_d_y;
  c5_e_y = (real_T)c5_x_sizes[0];
  c5_b_x = c5_x;
  c5_f_y = c5_e_y;
  return c5_b_x / c5_f_y;
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_h_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i82;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i82, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i82;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_b_is_active_c5_DrogueVisualNavigation3, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_DrogueVisualNavigation3), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_DrogueVisualNavigation3);
  return c5_y;
}

static uint8_T c5_j_emlrt_marshallIn(SFc5_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u1;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u1, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_DrogueVisualNavigation3InstanceStruct
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

void sf_c5_DrogueVisualNavigation3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2761887973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2934885141U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4121709655U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(680849349U);
}

mxArray *sf_c5_DrogueVisualNavigation3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("31k868OoeRytdsTWxtDbqG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(860);
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

mxArray *sf_c5_DrogueVisualNavigation3_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_DrogueVisualNavigation3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"yy\",},{M[8],M[0],T\"is_active_c5_DrogueVisualNavigation3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_DrogueVisualNavigation3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
    chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DrogueVisualNavigation3MachineNumber_,
           5,
           1,
           1,
           4,
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
          init_script_number_translation(_DrogueVisualNavigation3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DrogueVisualNavigation3MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DrogueVisualNavigation3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"yy");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u3");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,5,0,8,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1738);
        _SFD_CV_INIT_EML_IF(0,1,0,333,340,-1,769);
        _SFD_CV_INIT_EML_IF(0,1,1,388,396,-1,693);
        _SFD_CV_INIT_EML_IF(0,1,2,538,570,-1,650);
        _SFD_CV_INIT_EML_IF(0,1,3,895,927,-1,991);
        _SFD_CV_INIT_EML_FOR(0,1,0,107,117,191);
        _SFD_CV_INIT_EML_FOR(0,1,1,371,381,707);
        _SFD_CV_INIT_EML_FOR(0,1,2,408,419,678);
        _SFD_CV_INIT_EML_FOR(0,1,3,772,782,1025);
        _SFD_CV_INIT_EML_FOR(0,1,4,785,796,1011);

        {
          static int condStart[] = { 541, 548, 555, 563 };

          static int condEnd[] = { 546, 553, 561, 569 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,541,569,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 898, 905, 912, 920 };

          static int condEnd[] = { 903, 910, 918, 926 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,898,926,4,4,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
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
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint32_T *c5_u2;
          uint32_T (*c5_u1)[412800];
          real_T (*c5_yy)[412800];
          real_T (*c5_u3)[412800];
          c5_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
          c5_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_yy);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_u3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DrogueVisualNavigation3MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tZxbOb5eSOBxwTvpyC2BYF";
}

static void sf_opaque_initialize_c5_DrogueVisualNavigation3(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_DrogueVisualNavigation3
    ((SFc5_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
  initialize_c5_DrogueVisualNavigation3
    ((SFc5_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_DrogueVisualNavigation3(void *chartInstanceVar)
{
  enable_c5_DrogueVisualNavigation3((SFc5_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_DrogueVisualNavigation3(void *chartInstanceVar)
{
  disable_c5_DrogueVisualNavigation3((SFc5_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_DrogueVisualNavigation3(void *chartInstanceVar)
{
  sf_c5_DrogueVisualNavigation3((SFc5_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_DrogueVisualNavigation3
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_DrogueVisualNavigation3
    ((SFc5_DrogueVisualNavigation3InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_DrogueVisualNavigation3();/* state var info */
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

extern void sf_internal_set_sim_state_c5_DrogueVisualNavigation3(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_DrogueVisualNavigation3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_DrogueVisualNavigation3
    ((SFc5_DrogueVisualNavigation3InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_DrogueVisualNavigation3
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c5_DrogueVisualNavigation3(S);
}

static void sf_opaque_set_sim_state_c5_DrogueVisualNavigation3(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c5_DrogueVisualNavigation3(S, st);
}

static void sf_opaque_terminate_c5_DrogueVisualNavigation3(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_DrogueVisualNavigation3InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DrogueVisualNavigation3_optimization_info();
    }

    finalize_c5_DrogueVisualNavigation3
      ((SFc5_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_DrogueVisualNavigation3
    ((SFc5_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_DrogueVisualNavigation3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_DrogueVisualNavigation3
      ((SFc5_DrogueVisualNavigation3InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_DrogueVisualNavigation3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DrogueVisualNavigation3_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,3);
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
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3382919253U));
  ssSetChecksum1(S,(523669634U));
  ssSetChecksum2(S,(1406609211U));
  ssSetChecksum3(S,(3769173753U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_DrogueVisualNavigation3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_DrogueVisualNavigation3(SimStruct *S)
{
  SFc5_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc5_DrogueVisualNavigation3InstanceStruct *)utMalloc(sizeof
    (SFc5_DrogueVisualNavigation3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_DrogueVisualNavigation3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_DrogueVisualNavigation3;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_DrogueVisualNavigation3;
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

void c5_DrogueVisualNavigation3_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_DrogueVisualNavigation3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_DrogueVisualNavigation3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_DrogueVisualNavigation3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_DrogueVisualNavigation3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
