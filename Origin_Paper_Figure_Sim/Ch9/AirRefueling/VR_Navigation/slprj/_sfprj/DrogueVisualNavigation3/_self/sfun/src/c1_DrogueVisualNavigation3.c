/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DrogueVisualNavigation3_sfun.h"
#include "c1_DrogueVisualNavigation3.h"
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
static const char * c1_debug_family_names[25] = { "L", "N", "Ir", "dX", "dY",
  "k", "r", "c", "m", "cX", "cY", "cR", "alpha", "x", "y", "mm", "nn", "i", "j",
  "nargin", "nargout", "u1", "u2", "u3", "yy" };

/* Function Declarations */
static void initialize_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void initialize_params_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void enable_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void disable_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void set_sim_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void sf_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c1_chartstep_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void initSimStructsc1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void registerMessagesc1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_yy, const char_T *c1_identifier, real_T
  c1_y[412800]);
static void c1_b_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[412800]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[201]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[10], int32_T c1_inData_sizes[1]);
static void c1_e_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[10], int32_T c1_y_sizes[1]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[10],
  int32_T c1_outData_sizes[1]);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[412800], int32_T c1_inData_sizes[1]);
static void c1_f_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[412800], int32_T c1_y_sizes[1]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[412800],
  int32_T c1_outData_sizes[1]);
static uint32_T c1_g_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_i_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[412800]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[270]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[270]);
static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[270]);
static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[270]);
static void c1_e_info_helper(c1_ResolvedFunctionInfo c1_info[270]);
static void c1_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_eml_find(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, boolean_T c1_x[412800], int32_T c1_i_data[412800], int32_T
  c1_i_sizes[1], int32_T c1_j_data[412800], int32_T c1_j_sizes[1]);
static void c1_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static real_T c1_mean(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c1_x_data[412800], int32_T c1_x_sizes[1]);
static void c1_b_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_power(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                     real_T c1_a_data[10], int32_T c1_a_sizes[1], real_T
                     c1_y_data[10], int32_T c1_y_sizes[1]);
static void c1_b_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_mldivide(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[30], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_Y_data[10], int32_T c1_Y_sizes[1]);
static void c1_c_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_realmin(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c1_eps(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance);
static void c1_d_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_eml_matlab_zgetrf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T
  c1_b_A_data[9], int32_T c1_b_A_sizes[2], int32_T c1_ipiv[3], int32_T *c1_info);
static int32_T c1_eml_ixamax(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[9], int32_T c1_x_sizes[2],
  int32_T c1_ix0);
static void c1_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_iy0, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ia0,
  real_T c1_b_A_data[9], int32_T c1_b_A_sizes[2]);
static void c1_eml_warning(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_b_B_data[10], int32_T c1_b_B_sizes[1]);
static void c1_below_threshold(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_e_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static void c1_b_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_b_B_data[10], int32_T c1_b_B_sizes[1]);
static void c1_eml_qrsolve(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[30], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_Y[3]);
static void c1_f_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static real_T c1_sqrt(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c1_x);
static void c1_eml_error(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static real_T c1_eml_xnrm2(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0);
static int32_T c1_b_eml_ixamax(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[3], int32_T c1_ix0);
static void c1_eml_xswap(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0, int32_T c1_iy0, real_T c1_b_x_data[30], int32_T c1_b_x_sizes[2]);
static void c1_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_alpha1, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T *c1_b_alpha1, real_T c1_b_x_data[30],
  int32_T c1_b_x_sizes[2], real_T *c1_tau);
static void c1_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_b_x_data[30], int32_T c1_b_x_sizes[2]);
static void c1_b_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_x, real_T *c1_b_alpha1, real_T
  *c1_b_x, real_T *c1_tau);
static void c1_b_eml_xnrm2(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);
static real_T c1_b_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_x);
static void c1_eml_matlab_zlarf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C_data[30], int32_T c1_C_sizes[2], int32_T c1_ic0, int32_T c1_ldc,
  real_T c1_work[3], real_T c1_b_C_data[30], int32_T c1_b_C_sizes[2], real_T
  c1_b_work[3]);
static void c1_eml_xgemv(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A_data[30], int32_T
  c1_A_sizes[2], int32_T c1_ia0, int32_T c1_lda, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_y[3], real_T c1_b_y[3]);
static void c1_b_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A_data[30], int32_T c1_A_sizes[2], int32_T c1_ia0,
  int32_T c1_lda, real_T c1_b_A_data[30], int32_T c1_b_A_sizes[2]);
static void c1_b_eml_warning(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14]);
static real_T c1_mpower(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_a);
static void c1_j_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14]);
static void c1_k_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14]);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_l_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_m_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_DrogueVisualNavigation3, const
  char_T *c1_identifier);
static uint8_T c1_n_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_eml_matlab_zgetrf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ipiv[3],
  int32_T *c1_info);
static void c1_c_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_iy0, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ia0);
static void c1_c_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1]);
static void c1_d_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1]);
static void c1_b_sqrt(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T *c1_x);
static void c1_b_eml_xswap(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0, int32_T c1_iy0);
static real_T c1_c_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, int32_T c1_n, real_T *c1_alpha1, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0);
static void c1_c_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0);
static real_T c1_d_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, real_T *c1_alpha1, real_T *c1_x);
static void c1_d_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T *c1_x);
static void c1_b_eml_matlab_zlarf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C_data[30], int32_T c1_C_sizes[2], int32_T c1_ic0, int32_T c1_ldc,
  real_T c1_work[3]);
static void c1_b_eml_xgemv(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A_data[30], int32_T
  c1_A_sizes[2], int32_T c1_ia0, int32_T c1_lda, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_y[3]);
static void c1_d_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A_data[30], int32_T c1_A_sizes[2], int32_T c1_ia0,
  int32_T c1_lda);
static void init_dsm_address_info(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_DrogueVisualNavigation3 = 0U;
}

static void initialize_params_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void enable_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  static real_T c1_u[412800];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_yy)[412800];
  c1_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 412800; c1_i0++) {
    c1_u[c1_i0] = (*c1_yy)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_DrogueVisualNavigation3;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  static real_T c1_dv0[412800];
  int32_T c1_i1;
  real_T (*c1_yy)[412800];
  c1_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "yy",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 412800; c1_i1++) {
    (*c1_yy)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_DrogueVisualNavigation3 = c1_m_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_DrogueVisualNavigation3");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DrogueVisualNavigation3(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void sf_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  uint32_T *c1_u2;
  real_T (*c1_u3)[412800];
  real_T (*c1_yy)[412800];
  uint32_T (*c1_u1)[412800];
  c1_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
  c1_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 412800; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_u1)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 412800; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_yy)[c1_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c1_u2, 2U);
  for (c1_i4 = 0; c1_i4 < 412800; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_u3)[c1_i4], 3U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_DrogueVisualNavigation3(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DrogueVisualNavigation3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
  uint32_T c1_hoistedGlobal;
  int32_T c1_i5;
  static uint32_T c1_u1[412800];
  uint32_T c1_u2;
  int32_T c1_i6;
  static real_T c1_u3[412800];
  uint32_T c1_debug_family_var_map[25];
  static uint32_T c1_L[412800];
  uint32_T c1_N;
  static real_T c1_Ir[412800];
  real_T c1_dX[10];
  real_T c1_dY[10];
  uint32_T c1_k;
  int32_T c1_r_sizes;
  static real_T c1_r_data[412800];
  int32_T c1_c_sizes;
  static real_T c1_c_data[412800];
  int32_T c1_m_sizes;
  real_T c1_m_data[10];
  real_T c1_cX;
  real_T c1_cY;
  real_T c1_cR;
  real_T c1_alpha[201];
  real_T c1_x[201];
  real_T c1_y[201];
  real_T c1_mm;
  real_T c1_nn;
  real_T c1_i;
  real_T c1_j;
  real_T c1_b_k;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  static real_T c1_yy[412800];
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  uint32_T c1_b_N;
  uint32_T c1_b;
  uint32_T c1_b_b;
  boolean_T c1_overflow;
  uint32_T c1_c_k;
  int32_T c1_i11;
  static boolean_T c1_b_x[412800];
  int32_T c1_i12;
  static boolean_T c1_c_x[412800];
  int32_T c1_jj_sizes;
  static int32_T c1_jj_data[412800];
  int32_T c1_ii_sizes;
  static int32_T c1_ii_data[412800];
  int32_T c1_b_r_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i13;
  static real_T c1_b_r_data[412800];
  int32_T c1_b_c_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i14;
  static real_T c1_b_c_data[412800];
  int32_T c1_c_loop_ub;
  int32_T c1_i15;
  int32_T c1_d_loop_ub;
  int32_T c1_i16;
  int32_T c1_c_r_sizes;
  int32_T c1_e_loop_ub;
  int32_T c1_i17;
  static real_T c1_c_r_data[412800];
  int32_T c1_c_c_sizes;
  int32_T c1_f_loop_ub;
  int32_T c1_i18;
  static real_T c1_c_c_data[412800];
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  int32_T c1_i19;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  int32_T c1_i20;
  boolean_T c1_b6;
  boolean_T c1_b7;
  boolean_T c1_b8;
  int32_T c1_i21;
  int32_T c1_tmp_sizes;
  int32_T c1_g_loop_ub;
  int32_T c1_i22;
  real_T c1_tmp_data[10];
  real_T c1_dv1[2];
  int32_T c1_h_loop_ub;
  int32_T c1_i23;
  int32_T c1_b_tmp_sizes;
  int32_T c1_i_loop_ub;
  int32_T c1_i24;
  real_T c1_b_tmp_data[10];
  int32_T c1_c_tmp_sizes;
  int32_T c1_j_loop_ub;
  int32_T c1_i25;
  real_T c1_c_tmp_data[10];
  int32_T c1_iv0[2];
  int32_T c1_d_tmp_sizes[2];
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_k_loop_ub;
  int32_T c1_i28;
  real_T c1_d_tmp_data[10];
  int32_T c1_i29;
  int32_T c1_iv1[2];
  int32_T c1_e_tmp_sizes[2];
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_l_loop_ub;
  int32_T c1_i32;
  real_T c1_e_tmp_data[10];
  int32_T c1_iv2[2];
  int32_T c1_f_tmp_sizes[2];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_m_loop_ub;
  int32_T c1_i35;
  real_T c1_f_tmp_data[10];
  boolean_T c1_b9;
  boolean_T c1_b10;
  boolean_T c1_b11;
  int32_T c1_i36;
  boolean_T c1_b12;
  boolean_T c1_b13;
  boolean_T c1_b14;
  int32_T c1_i37;
  int32_T c1_dX_sizes;
  int32_T c1_n_loop_ub;
  int32_T c1_i38;
  real_T c1_dX_data[10];
  int32_T c1_dY_sizes;
  int32_T c1_o_loop_ub;
  int32_T c1_i39;
  real_T c1_dY_data[10];
  int32_T c1_g_tmp_sizes[2];
  int32_T c1_p_loop_ub;
  int32_T c1_i40;
  real_T c1_g_tmp_data[30];
  int32_T c1_q_loop_ub;
  int32_T c1_i41;
  int32_T c1_r_loop_ub;
  int32_T c1_i42;
  int32_T c1_h_tmp_sizes;
  int32_T c1_s_loop_ub;
  int32_T c1_i43;
  real_T c1_h_tmp_data[10];
  int32_T c1_i_tmp_sizes;
  real_T c1_i_tmp_data[10];
  int32_T c1_t_loop_ub;
  int32_T c1_i44;
  real_T c1_c_b;
  real_T c1_d_b;
  real_T c1_A;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_b_y;
  int32_T c1_i45;
  static real_T c1_dv2[201] = { 0.0, 0.031415926535897934, 0.062831853071795868,
    0.0942477796076938, 0.12566370614359174, 0.15707963267948966,
    0.1884955592153876, 0.21991148575128555, 0.25132741228718347,
    0.28274333882308139, 0.31415926535897931, 0.34557519189487729,
    0.37699111843077521, 0.40840704496667313, 0.4398229715025711,
    0.471238898038469, 0.50265482457436694, 0.53407075111026492,
    0.56548667764616278, 0.59690260418206076, 0.62831853071795862,
    0.6597344572538566, 0.69115038378975457, 0.72256631032565244,
    0.75398223686155041, 0.78539816339744839, 0.81681408993334625,
    0.84823001646924423, 0.87964594300514221, 0.91106186954104007,
    0.942477796076938, 0.97389372261283591, 1.0053096491487339,
    1.0367255756846319, 1.0681415022205298, 1.0995574287564276,
    1.1309733552923256, 1.1623892818282235, 1.1938052083641215,
    1.2252211349000195, 1.2566370614359172, 1.2880529879718152,
    1.3194689145077132, 1.3508848410436112, 1.3823007675795091,
    1.4137166941154071, 1.4451326206513049, 1.4765485471872029,
    1.5079644737231008, 1.5393804002589988, 1.5707963267948968,
    1.6022122533307945, 1.6336281798666925, 1.6650441064025905,
    1.6964600329384885, 1.7278759594743864, 1.7592918860102844,
    1.7907078125461822, 1.8221237390820801, 1.8535396656179781,
    1.8849555921538761, 1.9163715186897741, 1.9477874452256718,
    1.9792033717615698, 2.0106192982974678, 2.0420352248333655,
    2.0734511513692637, 2.1048670779051615, 2.1362830044410597,
    2.1676989309769574, 2.1991148575128552, 2.2305307840487534,
    2.2619467105846511, 2.2933626371205493, 2.3247785636564471,
    2.3561944901923448, 2.387610416728243, 2.4190263432641408, 2.450442269800039,
    2.4818581963359367, 2.5132741228718345, 2.5446900494077327,
    2.5761059759436304, 2.6075219024795286, 2.6389378290154264,
    2.6703537555513246, 2.7017696820872223, 2.73318560862312, 2.7646015351590183,
    2.7960174616949161, 2.8274333882308142, 2.858849314766712,
    2.8902652413026098, 2.921681167838508, 2.9530970943744057,
    2.9845130209103039, 3.0159289474462017, 3.0473448739820994,
    3.0787608005179976, 3.1101767270538954, 3.1415926535897931,
    3.1730085801256909, 3.2044245066615886, 3.2358404331974868,
    3.2672563597333846, 3.2986722862692823, 3.3300882128051805,
    3.3615041393410783, 3.3929200658769765, 3.4243359924128742,
    3.455751918948772, 3.48716784548467, 3.5185837720205679, 3.5499996985564661,
    3.5814156250923639, 3.6128315516282616, 3.64424747816416, 3.6756634047000576,
    3.7070793312359558, 3.7384952577718535, 3.7699111843077517,
    3.8013271108436495, 3.8327430373795472, 3.8641589639154454,
    3.8955748904513432, 3.9269908169872414, 3.9584067435231391,
    3.9898226700590369, 4.0212385965949355, 4.0526545231308333,
    4.0840704496667311, 4.1154863762026288, 4.1469023027385266,
    4.1783182292744243, 4.2097341558103221, 4.2411500823462207,
    4.2725660088821185, 4.3039819354180162, 4.3353978619539149,
    4.3668137884898126, 4.39822971502571, 4.4296456415616081, 4.4610615680975059,
    4.4924774946334036, 4.5238934211693014, 4.5553093477052, 4.5867252742410978,
    4.6181412007769955, 4.6495571273128942, 4.6809730538487919, 4.71238898038469,
    4.7438049069205874, 4.7752208334564852, 4.8066367599923829,
    4.8380526865282816, 4.8694686130641793, 4.9008845396000771,
    4.9323004661359748, 4.9637163926718735, 4.9951323192077712,
    5.026548245743669, 5.0579641722795667, 5.0893800988154645,
    5.1207960253513622, 5.1522119518872609, 5.1836278784231586,
    5.2150438049590564, 5.2464597314949541, 5.2778756580308528,
    5.3092915845667505, 5.3407075111026483, 5.3721234376385461,
    5.4035393641744438, 5.4349552907103416, 5.46637121724624, 5.497787143782138,
    5.5292030703180357, 5.5606189968539335, 5.5920349233898321, 5.62345084992573,
    5.6548667764616276, 5.6862827029975254, 5.7176986295334231,
    5.7491145560693209, 5.7805304826052195, 5.8119464091411173,
    5.843362335677015, 5.8747782622129128, 5.9061941887488114,
    5.9376101152847092, 5.9690260418206069, 6.0004419683565047,
    6.0318578948924024, 6.0632738214283011, 6.0946897479641988,
    6.1261056745000966, 6.1575216010359943, 6.1889375275718921,
    6.2203534541077907, 6.2517693806436885, 6.2831853071795862 };

  real_T c1_a;
  int32_T c1_i46;
  static real_T c1_e_b[201] = { 1.0, 0.9995065603657316, 0.99802672842827156,
    0.99556196460308, 0.99211470131447788, 0.98768834059513777,
    0.98228725072868872, 0.97591676193874743, 0.96858316112863108,
    0.96029368567694307, 0.95105651629515353, 0.94088076895422545,
    0.92977648588825135, 0.91775462568398114, 0.90482705246601947,
    0.8910065241883679, 0.87630668004386358, 0.86074202700394364,
    0.84432792550201508, 0.82708057427456183, 0.80901699437494745,
    0.79015501237569041, 0.77051324277578914, 0.75011106963045948,
    0.72896862742141155, 0.70710678118654746, 0.68454710592868873,
    0.66131186532365183, 0.63742398974868963, 0.61290705365297649,
    0.587785252292473, 0.56208337785213058, 0.53582679497899655,
    0.50904141575037121, 0.48175367410171516, 0.45399049973954686,
    0.42577929156507266, 0.39714789063478056, 0.36812455268467786,
    0.33873792024529126, 0.30901699437494745, 0.27899110603922928,
    0.24868988716485474, 0.21814324139654248, 0.18738131458572452,
    0.1564344650402307, 0.12533323356430426, 0.094108313318514283,
    0.0627905195293133, 0.031410759078128174, -1.6081226496766366E-16,
    -0.031410759078128278, -0.0627905195293134, -0.094108313318514381,
    -0.12533323356430437, -0.15643446504023104, -0.18738131458572482,
    -0.21814324139654256, -0.24868988716485485, -0.27899110603922933,
    -0.30901699437494756, -0.33873792024529153, -0.368124552684678,
    -0.39714789063478068, -0.42577929156507272, -0.45399049973954675,
    -0.48175367410171543, -0.50904141575037132, -0.53582679497899688,
    -0.56208337785213069, -0.587785252292473, -0.6129070536529766,
    -0.63742398974868975, -0.661311865323652, -0.68454710592868873,
    -0.70710678118654746, -0.72896862742141166, -0.75011106963045948,
    -0.77051324277578936, -0.79015501237569041, -0.80901699437494734,
    -0.82708057427456194, -0.84432792550201508, -0.86074202700394375,
    -0.87630668004386358, -0.891006524188368, -0.90482705246601958,
    -0.91775462568398114, -0.92977648588825146, -0.94088076895422545,
    -0.95105651629515364, -0.96029368567694307, -0.96858316112863108,
    -0.97591676193874743, -0.98228725072868872, -0.98768834059513777,
    -0.99211470131447788, -0.99556196460308, -0.99802672842827156,
    -0.9995065603657316, -1.0, -0.9995065603657316, -0.99802672842827156,
    -0.99556196460308, -0.99211470131447788, -0.98768834059513777,
    -0.98228725072868872, -0.97591676193874755, -0.96858316112863119,
    -0.96029368567694318, -0.95105651629515375, -0.94088076895422557,
    -0.92977648588825157, -0.91775462568398125, -0.90482705246601969,
    -0.89100652418836812, -0.87630668004386369, -0.86074202700394387,
    -0.84432792550201519, -0.827080574274562, -0.80901699437494745,
    -0.79015501237569064, -0.77051324277578959, -0.7501110696304597,
    -0.72896862742141177, -0.70710678118654768, -0.684547105928689,
    -0.66131186532365227, -0.63742398974868952, -0.61290705365297649,
    -0.58778525229247325, -0.56208337785213092, -0.5358267949789971,
    -0.50904141575037187, -0.48175367410171605, -0.45399049973954692,
    -0.42577929156507294, -0.39714789063478112, -0.36812455268467781,
    -0.33873792024529137, -0.30901699437494756, -0.27899110603922961,
    -0.24868988716485529, -0.21814324139654323, -0.18738131458572549,
    -0.15643446504023104, -0.12533323356430459, -0.094108313318514852,
    -0.062790519529313207, -0.0314107590781283, -1.8369701987210297E-16,
    0.031410759078127931, 0.062790519529312833, 0.0941083133185136,
    0.12533323356430423, 0.15643446504023067, 0.18738131458572427,
    0.218143241396542, 0.24868988716485493, 0.27899110603922922,
    0.30901699437494723, 0.33873792024529104, 0.36812455268467742,
    0.39714789063477995, 0.4257792915650726, 0.45399049973954664,
    0.48175367410171493, 0.50904141575037087, 0.53582679497899677,
    0.56208337785213058, 0.58778525229247292, 0.61290705365297615,
    0.6374239897486893, 0.66131186532365127, 0.68454710592868862,
    0.70710678118654735, 0.72896862742141122, 0.75011106963045915,
    0.77051324277578936, 0.7901550123756903, 0.80901699437494734,
    0.82708057427456161, 0.84432792550201474, 0.86074202700394331,
    0.87630668004386358, 0.89100652418836779, 0.90482705246601935,
    0.91775462568398092, 0.92977648588825146, 0.94088076895422545,
    0.95105651629515353, 0.960293685676943, 0.968583161128631,
    0.97591676193874743, 0.98228725072868872, 0.98768834059513766,
    0.99211470131447776, 0.99556196460308, 0.99802672842827156,
    0.9995065603657316, 1.0 };

  real_T c1_c_y[201];
  int32_T c1_i47;
  real_T c1_b_a;
  int32_T c1_i48;
  static real_T c1_f_b[201] = { 0.0, 0.031410759078128292, 0.062790519529313374,
    0.094108313318514325, 0.12533323356430426, 0.15643446504023087,
    0.18738131458572463, 0.21814324139654256, 0.24868988716485479,
    0.27899110603922928, 0.3090169943749474, 0.33873792024529142,
    0.368124552684678, 0.39714789063478062, 0.42577929156507272,
    0.4539904997395468, 0.48175367410171532, 0.50904141575037132,
    0.53582679497899666, 0.56208337785213058, 0.58778525229247314,
    0.61290705365297649, 0.63742398974868975, 0.66131186532365183,
    0.68454710592868873, 0.70710678118654757, 0.72896862742141155,
    0.75011106963045959, 0.77051324277578925, 0.79015501237569041,
    0.80901699437494745, 0.82708057427456183, 0.84432792550201508,
    0.86074202700394364, 0.87630668004386369, 0.89100652418836779,
    0.90482705246601958, 0.91775462568398114, 0.92977648588825146,
    0.94088076895422557, 0.95105651629515353, 0.96029368567694307,
    0.96858316112863108, 0.97591676193874743, 0.98228725072868872,
    0.98768834059513777, 0.99211470131447788, 0.99556196460308,
    0.99802672842827156, 0.9995065603657316, 1.0, 0.9995065603657316,
    0.99802672842827156, 0.99556196460308, 0.99211470131447776,
    0.98768834059513766, 0.98228725072868861, 0.97591676193874743,
    0.96858316112863108, 0.96029368567694307, 0.95105651629515353,
    0.94088076895422545, 0.92977648588825146, 0.91775462568398114,
    0.90482705246601947, 0.8910065241883679, 0.87630668004386347,
    0.86074202700394364, 0.844327925502015, 0.82708057427456172,
    0.80901699437494745, 0.7901550123756903, 0.77051324277578925,
    0.75011106963045937, 0.72896862742141144, 0.70710678118654757,
    0.6845471059286885, 0.66131186532365183, 0.63742398974868952,
    0.61290705365297637, 0.58778525229247325, 0.56208337785213047,
    0.53582679497899666, 0.5090414157503711, 0.48175367410171521,
    0.45399049973954647, 0.42577929156507249, 0.39714789063478062,
    0.36812455268467775, 0.33873792024529131, 0.30901699437494712,
    0.27899110603922911, 0.24868988716485482, 0.21814324139654231,
    0.18738131458572457, 0.15643446504023054, 0.12533323356430409,
    0.094108313318514353, 0.062790519529313138, 0.031410759078128236,
    1.2246467991473532E-16, -0.031410759078127994, -0.0627905195293129,
    -0.0941083133185141, -0.12533323356430384, -0.15643446504023031,
    -0.18738131458572432, -0.21814324139654206, -0.24868988716485457,
    -0.27899110603922889, -0.3090169943749469, -0.33873792024529109,
    -0.36812455268467748, -0.3971478906347804, -0.42577929156507227,
    -0.45399049973954625, -0.481753674101715, -0.50904141575037087,
    -0.53582679497899643, -0.56208337785213025, -0.587785252292473,
    -0.61290705365297626, -0.6374239897486893, -0.66131186532365172,
    -0.68454710592868839, -0.70710678118654746, -0.72896862742141133,
    -0.75011106963045915, -0.77051324277578936, -0.79015501237569041,
    -0.80901699437494734, -0.82708057427456161, -0.84432792550201485,
    -0.86074202700394331, -0.87630668004386314, -0.89100652418836779,
    -0.90482705246601935, -0.91775462568398092, -0.92977648588825146,
    -0.94088076895422545, -0.95105651629515353, -0.960293685676943,
    -0.968583161128631, -0.97591676193874721, -0.9822872507286885,
    -0.98768834059513766, -0.99211470131447776, -0.99556196460308,
    -0.99802672842827156, -0.9995065603657316, -1.0, -0.9995065603657316,
    -0.99802672842827156, -0.99556196460308011, -0.99211470131447788,
    -0.98768834059513777, -0.98228725072868872, -0.97591676193874755,
    -0.96858316112863108, -0.96029368567694307, -0.95105651629515364,
    -0.94088076895422557, -0.92977648588825157, -0.91775462568398147,
    -0.90482705246601958, -0.891006524188368, -0.87630668004386381,
    -0.86074202700394387, -0.844327925502015, -0.82708057427456183,
    -0.80901699437494756, -0.79015501237569064, -0.77051324277578959,
    -0.75011106963046, -0.72896862742141155, -0.70710678118654768,
    -0.684547105928689, -0.66131186532365227, -0.63742398974868963,
    -0.61290705365297649, -0.58778525229247336, -0.56208337785213092,
    -0.5358267949789971, -0.509041415750372, -0.48175367410171532,
    -0.45399049973954697, -0.425779291565073, -0.39714789063478118,
    -0.36812455268467786, -0.33873792024529142, -0.30901699437494762,
    -0.27899110603922966, -0.24868988716485535, -0.21814324139654243,
    -0.18738131458572468, -0.15643446504023112, -0.12533323356430465,
    -0.094108313318514908, -0.062790519529313263, -0.031410759078128361,
    -2.4492935982947064E-16 };

  int32_T c1_i49;
  int32_T c1_d_k;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  uint32_T *c1_b_u2;
  real_T (*c1_b_yy)[412800];
  real_T (*c1_b_u3)[412800];
  uint32_T (*c1_b_u1)[412800];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  c1_b_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_u2;
  for (c1_i5 = 0; c1_i5 < 412800; c1_i5++) {
    c1_u1[c1_i5] = (*c1_b_u1)[c1_i5];
  }

  c1_u2 = c1_hoistedGlobal;
  for (c1_i6 = 0; c1_i6 < 412800; c1_i6++) {
    c1_u3[c1_i6] = (*c1_b_u3)[c1_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 26U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_L, 0U, c1_c_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_N, 1U, c1_b_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Ir, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dX, 3U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dY, 4U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k, MAX_uint32_T, c1_b_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_r_data, (const int32_T *)
    &c1_r_sizes, NULL, 0, 6, (void *)c1_g_sf_marshallOut, (void *)
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_c_data, (const int32_T *)
    &c1_c_sizes, NULL, 0, 7, (void *)c1_g_sf_marshallOut, (void *)
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_m_data, (const int32_T *)
    &c1_m_sizes, NULL, 0, 8, (void *)c1_f_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cX, 9U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cY, 10U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_cR, 11U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_alpha, 12U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_x, 13U, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_y, 14U, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_mm, 15U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nn, 16U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 17U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j, 18U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_k, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 19U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 20U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u1, 21U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_u2, 22U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u3, 23U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_yy, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i7 = 0; c1_i7 < 412800; c1_i7++) {
    c1_L[c1_i7] = c1_u1[c1_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_N = c1_u2;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i8 = 0; c1_i8 < 412800; c1_i8++) {
    c1_Ir[c1_i8] = c1_u3[c1_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i9 = 0; c1_i9 < 10; c1_i9++) {
    c1_dX[c1_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  for (c1_i10 = 0; c1_i10 < 10; c1_i10++) {
    c1_dY[c1_i10] = 0.0;
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
  _SFD_SYMBOL_SWITCH(5U, 5U);
  c1_c_k = 1U;
  while (c1_c_k <= c1_b_N) {
    c1_k = c1_c_k;
    _SFD_SYMBOL_SWITCH(5U, 5U);
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    for (c1_i11 = 0; c1_i11 < 412800; c1_i11++) {
      c1_b_x[c1_i11] = (c1_L[c1_i11] == c1_k);
    }

    for (c1_i12 = 0; c1_i12 < 412800; c1_i12++) {
      c1_c_x[c1_i12] = c1_b_x[c1_i12];
    }

    c1_eml_find(chartInstance, c1_c_x, c1_ii_data, *(int32_T (*)[1])&c1_ii_sizes,
                c1_jj_data, *(int32_T (*)[1])&c1_jj_sizes);
    c1_b_r_sizes = c1_ii_sizes;
    c1_loop_ub = c1_ii_sizes - 1;
    for (c1_i13 = 0; c1_i13 <= c1_loop_ub; c1_i13++) {
      c1_b_r_data[c1_i13] = (real_T)c1_ii_data[c1_i13];
    }

    c1_b_c_sizes = c1_jj_sizes;
    c1_b_loop_ub = c1_jj_sizes - 1;
    for (c1_i14 = 0; c1_i14 <= c1_b_loop_ub; c1_i14++) {
      c1_b_c_data[c1_i14] = (real_T)c1_jj_data[c1_i14];
    }

    c1_r_sizes = c1_b_r_sizes;
    c1_c_loop_ub = c1_b_r_sizes - 1;
    for (c1_i15 = 0; c1_i15 <= c1_c_loop_ub; c1_i15++) {
      c1_r_data[c1_i15] = c1_b_r_data[c1_i15];
    }

    c1_c_sizes = c1_b_c_sizes;
    c1_d_loop_ub = c1_b_c_sizes - 1;
    for (c1_i16 = 0; c1_i16 <= c1_d_loop_ub; c1_i16++) {
      c1_c_data[c1_i16] = c1_b_c_data[c1_i16];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    c1_c_r_sizes = c1_r_sizes;
    c1_e_loop_ub = c1_r_sizes - 1;
    for (c1_i17 = 0; c1_i17 <= c1_e_loop_ub; c1_i17++) {
      c1_c_r_data[c1_i17] = c1_r_data[c1_i17];
    }

    c1_dX[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c1_k, 1,
      10, 1, 0) - 1] = c1_mean(chartInstance, c1_c_r_data, *(int32_T (*)[1])&
      c1_c_r_sizes);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    c1_c_c_sizes = c1_c_sizes;
    c1_f_loop_ub = c1_c_sizes - 1;
    for (c1_i18 = 0; c1_i18 <= c1_f_loop_ub; c1_i18++) {
      c1_c_c_data[c1_i18] = c1_c_data[c1_i18];
    }

    c1_dY[(int32_T)c1_k - 1] = c1_mean(chartInstance, c1_c_c_data, *(int32_T (*)
      [1])&c1_c_c_sizes);
    c1_c_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_b0 = (1U > c1_N);
  c1_b1 = c1_b0;
  c1_b2 = c1_b1;
  if (c1_b2) {
    c1_i19 = 0;
  } else {
    c1_i19 = (int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c1_N,
      1, 10, 0, 0);
  }

  c1_b3 = (1U > c1_N);
  c1_b4 = c1_b3;
  c1_b5 = c1_b4;
  if (c1_b5) {
    c1_i20 = 0;
  } else {
    c1_i20 = (int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dY", (int32_T)c1_N,
      1, 10, 0, 0);
  }

  c1_b6 = (1U > c1_N);
  c1_b7 = c1_b6;
  c1_b8 = c1_b7;
  if (c1_b8) {
    c1_i21 = 0;
  } else {
    c1_i21 = (int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c1_N,
      1, 10, 0, 0);
  }

  c1_tmp_sizes = c1_i21;
  c1_g_loop_ub = c1_i21 - 1;
  for (c1_i22 = 0; c1_i22 <= c1_g_loop_ub; c1_i22++) {
    c1_tmp_data[c1_i22] = c1_dX[c1_i22];
  }

  c1_dv1[0] = (real_T)c1_tmp_sizes;
  c1_dv1[1] = 1.0;
  c1_tmp_sizes = c1_i19;
  c1_h_loop_ub = c1_i19 - 1;
  for (c1_i23 = 0; c1_i23 <= c1_h_loop_ub; c1_i23++) {
    c1_tmp_data[c1_i23] = c1_dX[c1_i23];
  }

  c1_b_tmp_sizes = c1_i20;
  c1_i_loop_ub = c1_i20 - 1;
  for (c1_i24 = 0; c1_i24 <= c1_i_loop_ub; c1_i24++) {
    c1_b_tmp_data[c1_i24] = c1_dY[c1_i24];
  }

  c1_c_tmp_sizes = (int32_T)c1_dv1[0];
  c1_j_loop_ub = (int32_T)c1_dv1[0] - 1;
  for (c1_i25 = 0; c1_i25 <= c1_j_loop_ub; c1_i25++) {
    c1_c_tmp_data[c1_i25] = 1.0;
  }

  c1_iv0[0] = c1_tmp_sizes;
  c1_iv0[1] = 1;
  c1_d_tmp_sizes[0] = c1_iv0[0];
  c1_d_tmp_sizes[1] = 1;
  c1_i26 = c1_d_tmp_sizes[0];
  c1_i27 = c1_d_tmp_sizes[1];
  c1_k_loop_ub = c1_tmp_sizes - 1;
  for (c1_i28 = 0; c1_i28 <= c1_k_loop_ub; c1_i28++) {
    c1_d_tmp_data[c1_i28] = c1_tmp_data[c1_i28];
  }

  c1_i29 = c1_d_tmp_sizes[0];
  c1_iv1[0] = c1_b_tmp_sizes;
  c1_iv1[1] = 1;
  c1_e_tmp_sizes[0] = c1_iv1[0];
  c1_e_tmp_sizes[1] = 1;
  c1_i30 = c1_e_tmp_sizes[0];
  c1_i31 = c1_e_tmp_sizes[1];
  c1_l_loop_ub = c1_b_tmp_sizes - 1;
  for (c1_i32 = 0; c1_i32 <= c1_l_loop_ub; c1_i32++) {
    c1_e_tmp_data[c1_i32] = c1_b_tmp_data[c1_i32];
  }

  _SFD_DIM_SIZE_EQ_CHECK(c1_i29, c1_e_tmp_sizes[0], 1);
  c1_iv2[0] = c1_c_tmp_sizes;
  c1_iv2[1] = 1;
  c1_f_tmp_sizes[0] = c1_iv2[0];
  c1_f_tmp_sizes[1] = 1;
  c1_i33 = c1_f_tmp_sizes[0];
  c1_i34 = c1_f_tmp_sizes[1];
  c1_m_loop_ub = c1_c_tmp_sizes - 1;
  for (c1_i35 = 0; c1_i35 <= c1_m_loop_ub; c1_i35++) {
    c1_f_tmp_data[c1_i35] = c1_c_tmp_data[c1_i35];
  }

  _SFD_DIM_SIZE_EQ_CHECK(c1_i29, c1_f_tmp_sizes[0], 1);
  c1_b9 = (1U > c1_N);
  c1_b10 = c1_b9;
  c1_b11 = c1_b10;
  if (c1_b11) {
    c1_i36 = 0;
  } else {
    c1_i36 = (int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dX", (int32_T)c1_N,
      1, 10, 0, 0);
  }

  c1_b12 = (1U > c1_N);
  c1_b13 = c1_b12;
  c1_b14 = c1_b13;
  if (c1_b14) {
    c1_i37 = 0;
  } else {
    c1_i37 = (int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("dY", (int32_T)c1_N,
      1, 10, 0, 0);
  }

  c1_dX_sizes = c1_i36;
  c1_n_loop_ub = c1_i36 - 1;
  for (c1_i38 = 0; c1_i38 <= c1_n_loop_ub; c1_i38++) {
    c1_dX_data[c1_i38] = c1_dX[c1_i38];
  }

  c1_power(chartInstance, c1_dX_data, *(int32_T (*)[1])&c1_dX_sizes, c1_tmp_data,
           *(int32_T (*)[1])&c1_tmp_sizes);
  c1_dY_sizes = c1_i37;
  c1_o_loop_ub = c1_i37 - 1;
  for (c1_i39 = 0; c1_i39 <= c1_o_loop_ub; c1_i39++) {
    c1_dY_data[c1_i39] = c1_dY[c1_i39];
  }

  c1_power(chartInstance, c1_dY_data, *(int32_T (*)[1])&c1_dY_sizes,
           c1_b_tmp_data, *(int32_T (*)[1])&c1_b_tmp_sizes);
  _SFD_SIZE_EQ_CHECK_1D(c1_tmp_sizes, c1_b_tmp_sizes);
  c1_g_tmp_sizes[0] = c1_d_tmp_sizes[0];
  c1_g_tmp_sizes[1] = 3;
  c1_p_loop_ub = c1_d_tmp_sizes[0] - 1;
  for (c1_i40 = 0; c1_i40 <= c1_p_loop_ub; c1_i40++) {
    c1_g_tmp_data[c1_i40] = c1_d_tmp_data[c1_i40];
  }

  c1_q_loop_ub = c1_e_tmp_sizes[0] - 1;
  for (c1_i41 = 0; c1_i41 <= c1_q_loop_ub; c1_i41++) {
    c1_g_tmp_data[c1_i41 + c1_g_tmp_sizes[0]] = c1_e_tmp_data[c1_i41];
  }

  c1_r_loop_ub = c1_f_tmp_sizes[0] - 1;
  for (c1_i42 = 0; c1_i42 <= c1_r_loop_ub; c1_i42++) {
    c1_g_tmp_data[c1_i42 + (c1_g_tmp_sizes[0] << 1)] = c1_f_tmp_data[c1_i42];
  }

  c1_h_tmp_sizes = c1_tmp_sizes;
  c1_s_loop_ub = c1_tmp_sizes - 1;
  for (c1_i43 = 0; c1_i43 <= c1_s_loop_ub; c1_i43++) {
    c1_h_tmp_data[c1_i43] = -(c1_tmp_data[c1_i43] + c1_b_tmp_data[c1_i43]);
  }

  c1_mldivide(chartInstance, c1_g_tmp_data, c1_g_tmp_sizes, c1_h_tmp_data,
              *(int32_T (*)[1])&c1_h_tmp_sizes, c1_i_tmp_data, *(int32_T (*)[1])
              &c1_i_tmp_sizes);
  c1_m_sizes = c1_i_tmp_sizes;
  c1_t_loop_ub = c1_i_tmp_sizes - 1;
  for (c1_i44 = 0; c1_i44 <= c1_t_loop_ub; c1_i44++) {
    c1_m_data[c1_i44] = c1_i_tmp_data[c1_i44];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_c_b = c1_m_data[0];
  c1_cX = -0.5 * c1_c_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("m", 2, 1, c1_m_sizes, 1, 0);
  c1_d_b = c1_m_data[1];
  c1_cY = -0.5 * c1_d_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("m", 2, 1, c1_m_sizes, 1, 0);
  (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("m", 3, 1, c1_m_sizes, 1, 0);
  c1_A = c1_mpower(chartInstance, c1_m_data[0]) + c1_mpower(chartInstance,
    c1_m_data[1]);
  c1_d_x = c1_A;
  c1_e_x = c1_d_x;
  c1_b_y = c1_e_x / 4.0;
  c1_cR = c1_b_y - c1_m_data[2];
  c1_b_sqrt(chartInstance, &c1_cR);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  for (c1_i45 = 0; c1_i45 < 201; c1_i45++) {
    c1_alpha[c1_i45] = c1_dv2[c1_i45];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_a = c1_cR;
  for (c1_i46 = 0; c1_i46 < 201; c1_i46++) {
    c1_c_y[c1_i46] = c1_a * c1_e_b[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 201; c1_i47++) {
    c1_x[c1_i47] = c1_c_y[c1_i47] + c1_cX;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_b_a = c1_cR;
  for (c1_i48 = 0; c1_i48 < 201; c1_i48++) {
    c1_c_y[c1_i48] = c1_b_a * c1_f_b[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 201; c1_i49++) {
    c1_y[c1_i49] = c1_c_y[c1_i49] + c1_cY;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  c1_mm = 480.0;
  c1_nn = 860.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  c1_b_k = 1.0;
  _SFD_SYMBOL_SWITCH(5U, 19U);
  c1_d_k = 0;
  while (c1_d_k < 201) {
    c1_b_k = 1.0 + (real_T)c1_d_k;
    _SFD_SYMBOL_SWITCH(5U, 19U);
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
    c1_f_x = c1_x[(int32_T)c1_b_k - 1];
    c1_i = c1_f_x;
    c1_g_x = c1_i;
    c1_i = c1_g_x;
    c1_i = muDoubleScalarFloor(c1_i);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
    c1_h_x = c1_y[(int32_T)c1_b_k - 1];
    c1_j = c1_h_x;
    c1_i_x = c1_j;
    c1_j = c1_i_x;
    c1_j = muDoubleScalarFloor(c1_j);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
    guard4 = FALSE;
    guard5 = FALSE;
    guard6 = FALSE;
    if (CV_EML_COND(0, 1, 0, c1_i >= 1.0)) {
      if (CV_EML_COND(0, 1, 1, c1_j >= 1.0)) {
        if (CV_EML_COND(0, 1, 2, c1_i <= 480.0)) {
          if (CV_EML_COND(0, 1, 3, c1_j <= 860.0)) {
            CV_EML_MCDC(0, 1, 0, TRUE);
            CV_EML_IF(0, 1, 0, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
            c1_Ir[((int32_T)c1_i + 480 * ((int32_T)c1_j - 1)) - 1] = 1.0;
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
      CV_EML_IF(0, 1, 0, FALSE);
    }

    c1_d_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
  c1_j_x = c1_cX;
  c1_i = c1_j_x;
  c1_k_x = c1_i;
  c1_i = c1_k_x;
  c1_i = muDoubleScalarFloor(c1_i);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
  c1_l_x = c1_cY;
  c1_j = c1_l_x;
  c1_m_x = c1_j;
  c1_j = c1_m_x;
  c1_j = muDoubleScalarFloor(c1_j);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 4, c1_i - 3.0 >= 1.0)) {
    if (CV_EML_COND(0, 1, 5, c1_j - 3.0 >= 1.0)) {
      if (CV_EML_COND(0, 1, 6, c1_i + 4.0 <= 480.0)) {
        if (CV_EML_COND(0, 1, 7, c1_j + 4.0 <= 860.0)) {
          CV_EML_MCDC(0, 1, 1, TRUE);
          CV_EML_IF(0, 1, 1, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
          for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
            for (c1_i51 = 0; c1_i51 < 8; c1_i51++) {
              c1_Ir[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)
                      _SFD_INTEGER_CHECK("i-3:i+4", c1_i + (-3.0 + (real_T)
                        c1_i51)), 1, 480, 1, 0) + 480 * ((int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)
                       _SFD_INTEGER_CHECK("j:j+1", c1_j + (real_T)c1_i50), 1,
                       860, 2, 0) - 1)) - 1] = 1.0;
            }
          }

          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
          for (c1_i52 = 0; c1_i52 < 8; c1_i52++) {
            for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
              c1_Ir[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)
                      _SFD_INTEGER_CHECK("i:i+1", c1_i + (real_T)c1_i53), 1, 480,
                      1, 0) + 480 * ((int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("Ir", (int32_T)
                       _SFD_INTEGER_CHECK("j-3:j+4", c1_j + (-3.0 + (real_T)
                         c1_i52)), 1, 860, 2, 0) - 1)) - 1] = 1.0;
            }
          }
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
    CV_EML_IF(0, 1, 1, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 64);
  for (c1_i54 = 0; c1_i54 < 412800; c1_i54++) {
    c1_yy[c1_i54] = c1_Ir[c1_i54];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -64);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i55 = 0; c1_i55 < 412800; c1_i55++) {
    (*c1_b_yy)[c1_i55] = c1_yy[c1_i55];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void registerMessagesc1_DrogueVisualNavigation3
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  static real_T c1_b_inData[412800];
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  static real_T c1_u[412800];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i56 = 0;
  for (c1_i57 = 0; c1_i57 < 860; c1_i57++) {
    for (c1_i58 = 0; c1_i58 < 480; c1_i58++) {
      c1_b_inData[c1_i58 + c1_i56] = (*(real_T (*)[412800])c1_inData)[c1_i58 +
        c1_i56];
    }

    c1_i56 += 480;
  }

  c1_i59 = 0;
  for (c1_i60 = 0; c1_i60 < 860; c1_i60++) {
    for (c1_i61 = 0; c1_i61 < 480; c1_i61++) {
      c1_u[c1_i61 + c1_i59] = c1_b_inData[c1_i61 + c1_i59];
    }

    c1_i59 += 480;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 480, 860),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_yy, const char_T *c1_identifier, real_T
  c1_y[412800])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_yy), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_yy);
}

static void c1_b_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[412800])
{
  static real_T c1_dv3[412800];
  int32_T c1_i62;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 480,
                860);
  for (c1_i62 = 0; c1_i62 < 412800; c1_i62++) {
    c1_y[c1_i62] = c1_dv3[c1_i62];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_yy;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  static real_T c1_y[412800];
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_yy = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_yy), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_yy);
  c1_i63 = 0;
  for (c1_i64 = 0; c1_i64 < 860; c1_i64++) {
    for (c1_i65 = 0; c1_i65 < 480; c1_i65++) {
      (*(real_T (*)[412800])c1_outData)[c1_i65 + c1_i63] = c1_y[c1_i65 + c1_i63];
    }

    c1_i63 += 480;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
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
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  static uint32_T c1_b_inData[412800];
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  static uint32_T c1_u[412800];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i66 = 0;
  for (c1_i67 = 0; c1_i67 < 860; c1_i67++) {
    for (c1_i68 = 0; c1_i68 < 480; c1_i68++) {
      c1_b_inData[c1_i68 + c1_i66] = (*(uint32_T (*)[412800])c1_inData)[c1_i68 +
        c1_i66];
    }

    c1_i66 += 480;
  }

  c1_i69 = 0;
  for (c1_i70 = 0; c1_i70 < 860; c1_i70++) {
    for (c1_i71 = 0; c1_i71 < 480; c1_i71++) {
      c1_u[c1_i71 + c1_i69] = c1_b_inData[c1_i71 + c1_i69];
    }

    c1_i69 += 480;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 7, 0U, 1U, 0U, 2, 480, 860),
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
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
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
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
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
  int32_T c1_i72;
  real_T c1_b_inData[201];
  int32_T c1_i73;
  real_T c1_u[201];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i72 = 0; c1_i72 < 201; c1_i72++) {
    c1_b_inData[c1_i72] = (*(real_T (*)[201])c1_inData)[c1_i72];
  }

  for (c1_i73 = 0; c1_i73 < 201; c1_i73++) {
    c1_u[c1_i73] = c1_b_inData[c1_i73];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 201), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[201])
{
  real_T c1_dv4[201];
  int32_T c1_i74;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                201);
  for (c1_i74 = 0; c1_i74 < 201; c1_i74++) {
    c1_y[c1_i74] = c1_dv4[c1_i74];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y[201];
  int32_T c1_i75;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y), &c1_thisId, c1_b_y);
  sf_mex_destroy(&c1_y);
  for (c1_i75 = 0; c1_i75 < 201; c1_i75++) {
    (*(real_T (*)[201])c1_outData)[c1_i75] = c1_b_y[c1_i75];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[10], int32_T c1_inData_sizes[1])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i76;
  real_T c1_b_inData_data[10];
  int32_T c1_u_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i77;
  real_T c1_u_data[10];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes = c1_inData_sizes[0];
  c1_loop_ub = c1_inData_sizes[0] - 1;
  for (c1_i76 = 0; c1_i76 <= c1_loop_ub; c1_i76++) {
    c1_b_inData_data[c1_i76] = c1_inData_data[c1_i76];
  }

  c1_u_sizes = c1_b_inData_sizes;
  c1_b_loop_ub = c1_b_inData_sizes - 1;
  for (c1_i77 = 0; c1_i77 <= c1_b_loop_ub; c1_i77++) {
    c1_u_data[c1_i77] = c1_b_inData_data[c1_i77];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_sizes), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[10], int32_T c1_y_sizes[1])
{
  static uint32_T c1_uv0[1] = { 10U };

  uint32_T c1_uv1[1];
  static boolean_T c1_bv0[1] = { TRUE };

  boolean_T c1_bv1[1];
  int32_T c1_tmp_sizes;
  real_T c1_tmp_data[10];
  int32_T c1_loop_ub;
  int32_T c1_i78;
  c1_uv1[0] = c1_uv0[0];
  c1_bv1[0] = c1_bv0[0];
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c1_bv1, c1_uv1, &c1_tmp_sizes);
  c1_y_sizes[0] = c1_tmp_sizes;
  c1_loop_ub = c1_tmp_sizes - 1;
  for (c1_i78 = 0; c1_i78 <= c1_loop_ub; c1_i78++) {
    c1_y_data[c1_i78] = c1_tmp_data[c1_i78];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[10],
  int32_T c1_outData_sizes[1])
{
  const mxArray *c1_m;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes;
  real_T c1_y_data[10];
  int32_T c1_loop_ub;
  int32_T c1_i79;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_m = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_m), &c1_thisId, c1_y_data, *
                        (int32_T (*)[1])&c1_y_sizes);
  sf_mex_destroy(&c1_m);
  c1_outData_sizes[0] = c1_y_sizes;
  c1_loop_ub = c1_y_sizes - 1;
  for (c1_i79 = 0; c1_i79 <= c1_loop_ub; c1_i79++) {
    c1_outData_data[c1_i79] = c1_y_data[c1_i79];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[412800], int32_T c1_inData_sizes[1])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i80;
  static real_T c1_b_inData_data[412800];
  int32_T c1_u_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i81;
  static real_T c1_u_data[412800];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes = c1_inData_sizes[0];
  c1_loop_ub = c1_inData_sizes[0] - 1;
  for (c1_i80 = 0; c1_i80 <= c1_loop_ub; c1_i80++) {
    c1_b_inData_data[c1_i80] = c1_inData_data[c1_i80];
  }

  c1_u_sizes = c1_b_inData_sizes;
  c1_b_loop_ub = c1_b_inData_sizes - 1;
  for (c1_i81 = 0; c1_i81 <= c1_b_loop_ub; c1_i81++) {
    c1_u_data[c1_i81] = c1_b_inData_data[c1_i81];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_sizes), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y_data[412800], int32_T c1_y_sizes[1])
{
  static uint32_T c1_uv2[1] = { 412800U };

  uint32_T c1_uv3[1];
  static boolean_T c1_bv2[1] = { TRUE };

  boolean_T c1_bv3[1];
  int32_T c1_tmp_sizes;
  static real_T c1_tmp_data[412800];
  int32_T c1_loop_ub;
  int32_T c1_i82;
  c1_uv3[0] = c1_uv2[0];
  c1_bv3[0] = c1_bv2[0];
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c1_bv3, c1_uv3, &c1_tmp_sizes);
  c1_y_sizes[0] = c1_tmp_sizes;
  c1_loop_ub = c1_tmp_sizes - 1;
  for (c1_i82 = 0; c1_i82 <= c1_loop_ub; c1_i82++) {
    c1_y_data[c1_i82] = c1_tmp_data[c1_i82];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[412800],
  int32_T c1_outData_sizes[1])
{
  const mxArray *c1_c;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes;
  static real_T c1_y_data[412800];
  int32_T c1_loop_ub;
  int32_T c1_i83;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_c = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_c), &c1_thisId, c1_y_data, *
                        (int32_T (*)[1])&c1_y_sizes);
  sf_mex_destroy(&c1_c);
  c1_outData_sizes[0] = c1_y_sizes;
  c1_loop_ub = c1_y_sizes - 1;
  for (c1_i83 = 0; c1_i83 <= c1_loop_ub; c1_i83++) {
    c1_outData_data[c1_i83] = c1_y_data[c1_i83];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static uint32_T c1_g_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_k;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_k = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_k), &c1_thisId);
  sf_mex_destroy(&c1_k);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i84;
  real_T c1_b_inData[10];
  int32_T c1_i85;
  real_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i84 = 0; c1_i84 < 10; c1_i84++) {
    c1_b_inData[c1_i84] = (*(real_T (*)[10])c1_inData)[c1_i84];
  }

  for (c1_i85 = 0; c1_i85 < 10; c1_i85++) {
    c1_u[c1_i85] = c1_b_inData[c1_i85];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10])
{
  real_T c1_dv5[10];
  int32_T c1_i86;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 1, 10);
  for (c1_i86 = 0; c1_i86 < 10; c1_i86++) {
    c1_y[c1_i86] = c1_dv5[c1_i86];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dY;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[10];
  int32_T c1_i87;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_dY = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dY), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dY);
  for (c1_i87 = 0; c1_i87 < 10; c1_i87++) {
    (*(real_T (*)[10])c1_outData)[c1_i87] = c1_y[c1_i87];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_i_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  uint32_T c1_y[412800])
{
  static uint32_T c1_uv4[412800];
  int32_T c1_i88;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_uv4, 1, 7, 0U, 1, 0U, 2, 480,
                860);
  for (c1_i88 = 0; c1_i88 < 412800; c1_i88++) {
    c1_y[c1_i88] = c1_uv4[c1_i88];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_L;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  static uint32_T c1_y[412800];
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_L = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_L), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_L);
  c1_i89 = 0;
  for (c1_i90 = 0; c1_i90 < 860; c1_i90++) {
    for (c1_i91 = 0; c1_i91 < 480; c1_i91++) {
      (*(uint32_T (*)[412800])c1_outData)[c1_i91 + c1_i89] = c1_y[c1_i91 +
        c1_i89];
    }

    c1_i89 += 480;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DrogueVisualNavigation3_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[270];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i92;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  c1_c_info_helper(c1_info);
  c1_d_info_helper(c1_info);
  c1_e_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 270), FALSE);
  for (c1_i92 = 0; c1_i92 < 270; c1_i92++) {
    c1_r0 = &c1_info[c1_i92];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i92);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i92);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[270])
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
  c1_info[30].name = "eml_scalar_eg";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[30].fileTimeLo = 1286797196U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[31].name = "eml_lusolve";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[31].fileTimeLo = 1309429596U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[32].name = "eml_index_class";
  c1_info[32].dominantType = "";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[32].fileTimeLo = 1323145378U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[33].name = "eml_index_class";
  c1_info[33].dominantType = "";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[33].fileTimeLo = 1323145378U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[34].name = "eml_xgetrf";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[34].fileTimeLo = 1286797206U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[35].name = "eml_lapack_xgetrf";
  c1_info[35].dominantType = "double";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[35].fileTimeLo = 1286797210U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[36].name = "eml_matlab_zgetrf";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[36].fileTimeLo = 1302667394U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[37].name = "realmin";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[37].fileTimeLo = 1307629642U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[38].name = "eml_realmin";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[38].fileTimeLo = 1307629644U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[39].name = "eml_float_model";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[39].fileTimeLo = 1326702796U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[40].name = "eps";
  c1_info[40].dominantType = "char";
  c1_info[40].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[40].fileTimeLo = 1326702796U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[41].name = "eml_is_float_class";
  c1_info[41].dominantType = "char";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[41].fileTimeLo = 1286797182U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[42].name = "eml_eps";
  c1_info[42].dominantType = "char";
  c1_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[42].fileTimeLo = 1326702796U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[43].name = "eml_float_model";
  c1_info[43].dominantType = "char";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[43].fileTimeLo = 1326702796U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[44].name = "min";
  c1_info[44].dominantType = "coder.internal.indexInt";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[44].fileTimeLo = 1311233718U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[45].name = "eml_min_or_max";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[45].fileTimeLo = 1334049890U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[46].name = "eml_scalar_eg";
  c1_info[46].dominantType = "coder.internal.indexInt";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[46].fileTimeLo = 1286797196U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[47].name = "eml_scalexp_alloc";
  c1_info[47].dominantType = "coder.internal.indexInt";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[47].fileTimeLo = 1352399660U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[48].name = "eml_index_class";
  c1_info[48].dominantType = "";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[48].fileTimeLo = 1323145378U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[49].name = "eml_scalar_eg";
  c1_info[49].dominantType = "coder.internal.indexInt";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[49].fileTimeLo = 1286797196U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[50].name = "colon";
  c1_info[50].dominantType = "double";
  c1_info[50].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[50].fileTimeLo = 1348170328U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[51].name = "colon";
  c1_info[51].dominantType = "double";
  c1_info[51].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[51].fileTimeLo = 1348170328U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[52].name = "floor";
  c1_info[52].dominantType = "double";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[52].fileTimeLo = 1343808780U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[53].name = "intmin";
  c1_info[53].dominantType = "char";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[53].fileTimeLo = 1311233718U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[54].name = "intmax";
  c1_info[54].dominantType = "char";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[54].fileTimeLo = 1311233716U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[55].name = "intmin";
  c1_info[55].dominantType = "char";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[55].fileTimeLo = 1311233718U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[56].name = "intmax";
  c1_info[56].dominantType = "char";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[56].fileTimeLo = 1311233716U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[57].name = "eml_isa_uint";
  c1_info[57].dominantType = "coder.internal.indexInt";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[57].fileTimeLo = 1286797184U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[58].name = "eml_unsigned_class";
  c1_info[58].dominantType = "char";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[58].fileTimeLo = 1323145380U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[59].name = "eml_index_class";
  c1_info[59].dominantType = "";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[59].fileTimeLo = 1323145378U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[60].name = "eml_index_class";
  c1_info[60].dominantType = "";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[60].fileTimeLo = 1323145378U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[61].name = "intmax";
  c1_info[61].dominantType = "char";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[61].fileTimeLo = 1311233716U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[62].name = "eml_isa_uint";
  c1_info[62].dominantType = "coder.internal.indexInt";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[62].fileTimeLo = 1286797184U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[63].name = "eml_index_plus";
  c1_info[63].dominantType = "double";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[63].fileTimeLo = 1286797178U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[270])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c1_info[64].name = "eml_int_forloop_overflow_check";
  c1_info[64].dominantType = "";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[64].fileTimeLo = 1346488740U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[65].name = "eml_index_class";
  c1_info[65].dominantType = "";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[65].fileTimeLo = 1323145378U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[66].name = "eml_index_plus";
  c1_info[66].dominantType = "double";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[66].fileTimeLo = 1286797178U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[67].name = "eml_int_forloop_overflow_check";
  c1_info[67].dominantType = "";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[67].fileTimeLo = 1346488740U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[68].name = "eml_index_minus";
  c1_info[68].dominantType = "double";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[68].fileTimeLo = 1286797178U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[69].name = "eml_index_class";
  c1_info[69].dominantType = "";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[69].fileTimeLo = 1323145378U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[70].name = "eml_index_minus";
  c1_info[70].dominantType = "coder.internal.indexInt";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[70].fileTimeLo = 1286797178U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[71].name = "eml_index_times";
  c1_info[71].dominantType = "coder.internal.indexInt";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[71].fileTimeLo = 1286797180U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[72].name = "eml_index_class";
  c1_info[72].dominantType = "";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[72].fileTimeLo = 1323145378U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[73].name = "eml_index_plus";
  c1_info[73].dominantType = "coder.internal.indexInt";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[73].fileTimeLo = 1286797178U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[74].name = "eml_ixamax";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[74].fileTimeLo = 1299051570U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[75].name = "eml_blas_inline";
  c1_info[75].dominantType = "";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[75].fileTimeLo = 1299051568U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[76].name = "eml_index_class";
  c1_info[76].dominantType = "";
  c1_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[76].fileTimeLo = 1323145378U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[77].name = "eml_refblas_ixamax";
  c1_info[77].dominantType = "double";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[77].fileTimeLo = 1299051570U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[78].name = "eml_index_class";
  c1_info[78].dominantType = "";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[78].fileTimeLo = 1323145378U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[79].name = "eml_xcabs1";
  c1_info[79].dominantType = "double";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[79].fileTimeLo = 1286797106U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[80].name = "abs";
  c1_info[80].dominantType = "double";
  c1_info[80].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[80].fileTimeLo = 1343808766U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[81].name = "eml_scalar_abs";
  c1_info[81].dominantType = "double";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[81].fileTimeLo = 1286797112U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[82].name = "eml_int_forloop_overflow_check";
  c1_info[82].dominantType = "";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[82].fileTimeLo = 1346488740U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[83].name = "eml_index_plus";
  c1_info[83].dominantType = "coder.internal.indexInt";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[83].fileTimeLo = 1286797178U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[84].name = "eml_xswap";
  c1_info[84].dominantType = "double";
  c1_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[84].fileTimeLo = 1299051578U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[85].name = "eml_blas_inline";
  c1_info[85].dominantType = "";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[85].fileTimeLo = 1299051568U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[86].name = "eml_index_class";
  c1_info[86].dominantType = "";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[86].fileTimeLo = 1323145378U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[87].name = "eml_refblas_xswap";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[87].fileTimeLo = 1299051586U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[88].name = "eml_index_class";
  c1_info[88].dominantType = "";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[88].fileTimeLo = 1323145378U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[89].name = "abs";
  c1_info[89].dominantType = "coder.internal.indexInt";
  c1_info[89].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[89].fileTimeLo = 1343808766U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 0U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[90].name = "eml_scalar_abs";
  c1_info[90].dominantType = "coder.internal.indexInt";
  c1_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[90].fileTimeLo = 1286797112U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[91].name = "eml_int_forloop_overflow_check";
  c1_info[91].dominantType = "";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[91].fileTimeLo = 1346488740U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[92].name = "eml_index_plus";
  c1_info[92].dominantType = "coder.internal.indexInt";
  c1_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[92].fileTimeLo = 1286797178U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[93].name = "eml_div";
  c1_info[93].dominantType = "double";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[93].fileTimeLo = 1313326210U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[94].name = "eml_xgeru";
  c1_info[94].dominantType = "double";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[94].fileTimeLo = 1299051574U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[95].name = "eml_blas_inline";
  c1_info[95].dominantType = "";
  c1_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[95].fileTimeLo = 1299051568U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[96].name = "eml_xger";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[96].fileTimeLo = 1299051574U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[97].name = "eml_blas_inline";
  c1_info[97].dominantType = "";
  c1_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[97].fileTimeLo = 1299051568U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[98].name = "intmax";
  c1_info[98].dominantType = "char";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[98].fileTimeLo = 1311233716U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[99].name = "min";
  c1_info[99].dominantType = "double";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[99].fileTimeLo = 1311233718U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[100].name = "eml_scalar_eg";
  c1_info[100].dominantType = "double";
  c1_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[100].fileTimeLo = 1286797196U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[101].name = "eml_scalexp_alloc";
  c1_info[101].dominantType = "double";
  c1_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[101].fileTimeLo = 1352399660U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[102].name = "eml_scalar_eg";
  c1_info[102].dominantType = "double";
  c1_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[102].fileTimeLo = 1286797196U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[103].name = "mtimes";
  c1_info[103].dominantType = "double";
  c1_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[103].fileTimeLo = 1289494492U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[104].name = "eml_index_class";
  c1_info[104].dominantType = "";
  c1_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[104].fileTimeLo = 1323145378U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[105].name = "eml_refblas_xger";
  c1_info[105].dominantType = "double";
  c1_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[105].fileTimeLo = 1299051576U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[106].name = "eml_refblas_xgerx";
  c1_info[106].dominantType = "char";
  c1_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[106].fileTimeLo = 1299051578U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[107].name = "eml_index_class";
  c1_info[107].dominantType = "";
  c1_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[107].fileTimeLo = 1323145378U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[108].name = "abs";
  c1_info[108].dominantType = "coder.internal.indexInt";
  c1_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[108].fileTimeLo = 1343808766U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[109].name = "eml_index_minus";
  c1_info[109].dominantType = "double";
  c1_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[109].fileTimeLo = 1286797178U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
  c1_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[110].name = "eml_int_forloop_overflow_check";
  c1_info[110].dominantType = "";
  c1_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[110].fileTimeLo = 1346488740U;
  c1_info[110].fileTimeHi = 0U;
  c1_info[110].mFileTimeLo = 0U;
  c1_info[110].mFileTimeHi = 0U;
  c1_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[111].name = "eml_index_plus";
  c1_info[111].dominantType = "double";
  c1_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[111].fileTimeLo = 1286797178U;
  c1_info[111].fileTimeHi = 0U;
  c1_info[111].mFileTimeLo = 0U;
  c1_info[111].mFileTimeHi = 0U;
  c1_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[112].name = "eml_index_plus";
  c1_info[112].dominantType = "coder.internal.indexInt";
  c1_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[112].fileTimeLo = 1286797178U;
  c1_info[112].fileTimeHi = 0U;
  c1_info[112].mFileTimeLo = 0U;
  c1_info[112].mFileTimeHi = 0U;
  c1_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c1_info[113].name = "eml_warning";
  c1_info[113].dominantType = "char";
  c1_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[113].fileTimeLo = 1286797202U;
  c1_info[113].fileTimeHi = 0U;
  c1_info[113].mFileTimeLo = 0U;
  c1_info[113].mFileTimeHi = 0U;
  c1_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[114].name = "eml_scalar_eg";
  c1_info[114].dominantType = "double";
  c1_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[114].fileTimeLo = 1286797196U;
  c1_info[114].fileTimeHi = 0U;
  c1_info[114].mFileTimeLo = 0U;
  c1_info[114].mFileTimeHi = 0U;
  c1_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[115].name = "eml_int_forloop_overflow_check";
  c1_info[115].dominantType = "";
  c1_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[115].fileTimeLo = 1346488740U;
  c1_info[115].fileTimeHi = 0U;
  c1_info[115].mFileTimeLo = 0U;
  c1_info[115].mFileTimeHi = 0U;
  c1_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[116].name = "eml_xtrsm";
  c1_info[116].dominantType = "char";
  c1_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[116].fileTimeLo = 1299051578U;
  c1_info[116].fileTimeHi = 0U;
  c1_info[116].mFileTimeLo = 0U;
  c1_info[116].mFileTimeHi = 0U;
  c1_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[117].name = "eml_blas_inline";
  c1_info[117].dominantType = "";
  c1_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[117].fileTimeLo = 1299051568U;
  c1_info[117].fileTimeHi = 0U;
  c1_info[117].mFileTimeLo = 0U;
  c1_info[117].mFileTimeHi = 0U;
  c1_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c1_info[118].name = "mtimes";
  c1_info[118].dominantType = "double";
  c1_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[118].fileTimeLo = 1289494492U;
  c1_info[118].fileTimeHi = 0U;
  c1_info[118].mFileTimeLo = 0U;
  c1_info[118].mFileTimeHi = 0U;
  c1_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[119].name = "eml_index_class";
  c1_info[119].dominantType = "";
  c1_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[119].fileTimeLo = 1323145378U;
  c1_info[119].fileTimeHi = 0U;
  c1_info[119].mFileTimeLo = 0U;
  c1_info[119].mFileTimeHi = 0U;
  c1_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[120].name = "eml_scalar_eg";
  c1_info[120].dominantType = "double";
  c1_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[120].fileTimeLo = 1286797196U;
  c1_info[120].fileTimeHi = 0U;
  c1_info[120].mFileTimeLo = 0U;
  c1_info[120].mFileTimeHi = 0U;
  c1_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[121].name = "eml_refblas_xtrsm";
  c1_info[121].dominantType = "char";
  c1_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[121].fileTimeLo = 1299051586U;
  c1_info[121].fileTimeHi = 0U;
  c1_info[121].mFileTimeLo = 0U;
  c1_info[121].mFileTimeHi = 0U;
  c1_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[122].name = "eml_scalar_eg";
  c1_info[122].dominantType = "double";
  c1_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[122].fileTimeLo = 1286797196U;
  c1_info[122].fileTimeHi = 0U;
  c1_info[122].mFileTimeLo = 0U;
  c1_info[122].mFileTimeHi = 0U;
  c1_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[123].name = "eml_index_minus";
  c1_info[123].dominantType = "double";
  c1_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[123].fileTimeLo = 1286797178U;
  c1_info[123].fileTimeHi = 0U;
  c1_info[123].mFileTimeLo = 0U;
  c1_info[123].mFileTimeHi = 0U;
  c1_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[124].name = "eml_index_class";
  c1_info[124].dominantType = "";
  c1_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[124].fileTimeLo = 1323145378U;
  c1_info[124].fileTimeHi = 0U;
  c1_info[124].mFileTimeLo = 0U;
  c1_info[124].mFileTimeHi = 0U;
  c1_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[125].name = "eml_index_times";
  c1_info[125].dominantType = "coder.internal.indexInt";
  c1_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[125].fileTimeLo = 1286797180U;
  c1_info[125].fileTimeHi = 0U;
  c1_info[125].mFileTimeLo = 0U;
  c1_info[125].mFileTimeHi = 0U;
  c1_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[126].name = "eml_index_plus";
  c1_info[126].dominantType = "coder.internal.indexInt";
  c1_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[126].fileTimeLo = 1286797178U;
  c1_info[126].fileTimeHi = 0U;
  c1_info[126].mFileTimeLo = 0U;
  c1_info[126].mFileTimeHi = 0U;
  c1_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[127].name = "eml_int_forloop_overflow_check";
  c1_info[127].dominantType = "";
  c1_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[127].fileTimeLo = 1346488740U;
  c1_info[127].fileTimeHi = 0U;
  c1_info[127].mFileTimeLo = 0U;
  c1_info[127].mFileTimeHi = 0U;
}

static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[270])
{
  c1_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[128].name = "eml_index_plus";
  c1_info[128].dominantType = "double";
  c1_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[128].fileTimeLo = 1286797178U;
  c1_info[128].fileTimeHi = 0U;
  c1_info[128].mFileTimeLo = 0U;
  c1_info[128].mFileTimeHi = 0U;
  c1_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[129].name = "intmin";
  c1_info[129].dominantType = "char";
  c1_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[129].fileTimeLo = 1311233718U;
  c1_info[129].fileTimeHi = 0U;
  c1_info[129].mFileTimeLo = 0U;
  c1_info[129].mFileTimeHi = 0U;
  c1_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[130].name = "eml_div";
  c1_info[130].dominantType = "double";
  c1_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[130].fileTimeLo = 1313326210U;
  c1_info[130].fileTimeHi = 0U;
  c1_info[130].mFileTimeLo = 0U;
  c1_info[130].mFileTimeHi = 0U;
  c1_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[131].name = "eml_qrsolve";
  c1_info[131].dominantType = "double";
  c1_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[131].fileTimeLo = 1307629644U;
  c1_info[131].fileTimeHi = 0U;
  c1_info[131].mFileTimeLo = 0U;
  c1_info[131].mFileTimeHi = 0U;
  c1_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[132].name = "min";
  c1_info[132].dominantType = "double";
  c1_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[132].fileTimeLo = 1311233718U;
  c1_info[132].fileTimeHi = 0U;
  c1_info[132].mFileTimeLo = 0U;
  c1_info[132].mFileTimeHi = 0U;
  c1_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[133].name = "eml_xgeqp3";
  c1_info[133].dominantType = "double";
  c1_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[133].fileTimeLo = 1286797204U;
  c1_info[133].fileTimeHi = 0U;
  c1_info[133].mFileTimeLo = 0U;
  c1_info[133].mFileTimeHi = 0U;
  c1_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgeqp3.m";
  c1_info[134].name = "eml_lapack_xgeqp3";
  c1_info[134].dominantType = "double";
  c1_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[134].fileTimeLo = 1286797208U;
  c1_info[134].fileTimeHi = 0U;
  c1_info[134].mFileTimeLo = 0U;
  c1_info[134].mFileTimeHi = 0U;
  c1_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeqp3.m";
  c1_info[135].name = "eml_matlab_zgeqp3";
  c1_info[135].dominantType = "double";
  c1_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[135].fileTimeLo = 1289974166U;
  c1_info[135].fileTimeHi = 0U;
  c1_info[135].mFileTimeLo = 0U;
  c1_info[135].mFileTimeHi = 0U;
  c1_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[136].name = "eml_index_class";
  c1_info[136].dominantType = "";
  c1_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[136].fileTimeLo = 1323145378U;
  c1_info[136].fileTimeHi = 0U;
  c1_info[136].mFileTimeLo = 0U;
  c1_info[136].mFileTimeHi = 0U;
  c1_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[137].name = "min";
  c1_info[137].dominantType = "coder.internal.indexInt";
  c1_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[137].fileTimeLo = 1311233718U;
  c1_info[137].fileTimeHi = 0U;
  c1_info[137].mFileTimeLo = 0U;
  c1_info[137].mFileTimeHi = 0U;
  c1_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[138].name = "eml_scalar_eg";
  c1_info[138].dominantType = "double";
  c1_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[138].fileTimeLo = 1286797196U;
  c1_info[138].fileTimeHi = 0U;
  c1_info[138].mFileTimeLo = 0U;
  c1_info[138].mFileTimeHi = 0U;
  c1_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[139].name = "colon";
  c1_info[139].dominantType = "coder.internal.indexInt";
  c1_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[139].fileTimeLo = 1348170328U;
  c1_info[139].fileTimeHi = 0U;
  c1_info[139].mFileTimeLo = 0U;
  c1_info[139].mFileTimeHi = 0U;
  c1_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[140].name = "eps";
  c1_info[140].dominantType = "char";
  c1_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[140].fileTimeLo = 1326702796U;
  c1_info[140].fileTimeHi = 0U;
  c1_info[140].mFileTimeLo = 0U;
  c1_info[140].mFileTimeHi = 0U;
  c1_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[141].name = "sqrt";
  c1_info[141].dominantType = "double";
  c1_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[141].fileTimeLo = 1343808786U;
  c1_info[141].fileTimeHi = 0U;
  c1_info[141].mFileTimeLo = 0U;
  c1_info[141].mFileTimeHi = 0U;
  c1_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[142].name = "eml_error";
  c1_info[142].dominantType = "char";
  c1_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[142].fileTimeLo = 1343808758U;
  c1_info[142].fileTimeHi = 0U;
  c1_info[142].mFileTimeLo = 0U;
  c1_info[142].mFileTimeHi = 0U;
  c1_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[143].name = "eml_scalar_sqrt";
  c1_info[143].dominantType = "double";
  c1_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[143].fileTimeLo = 1286797138U;
  c1_info[143].fileTimeHi = 0U;
  c1_info[143].mFileTimeLo = 0U;
  c1_info[143].mFileTimeHi = 0U;
  c1_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[144].name = "eml_int_forloop_overflow_check";
  c1_info[144].dominantType = "";
  c1_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[144].fileTimeLo = 1346488740U;
  c1_info[144].fileTimeHi = 0U;
  c1_info[144].mFileTimeLo = 0U;
  c1_info[144].mFileTimeHi = 0U;
  c1_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[145].name = "eml_xnrm2";
  c1_info[145].dominantType = "double";
  c1_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[145].fileTimeLo = 1299051576U;
  c1_info[145].fileTimeHi = 0U;
  c1_info[145].mFileTimeLo = 0U;
  c1_info[145].mFileTimeHi = 0U;
  c1_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[146].name = "eml_blas_inline";
  c1_info[146].dominantType = "";
  c1_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[146].fileTimeLo = 1299051568U;
  c1_info[146].fileTimeHi = 0U;
  c1_info[146].mFileTimeLo = 0U;
  c1_info[146].mFileTimeHi = 0U;
  c1_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[147].name = "eml_index_class";
  c1_info[147].dominantType = "";
  c1_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[147].fileTimeLo = 1323145378U;
  c1_info[147].fileTimeHi = 0U;
  c1_info[147].mFileTimeLo = 0U;
  c1_info[147].mFileTimeHi = 0U;
  c1_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[148].name = "eml_refblas_xnrm2";
  c1_info[148].dominantType = "double";
  c1_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[148].fileTimeLo = 1299051584U;
  c1_info[148].fileTimeHi = 0U;
  c1_info[148].mFileTimeLo = 0U;
  c1_info[148].mFileTimeHi = 0U;
  c1_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[149].name = "abs";
  c1_info[149].dominantType = "double";
  c1_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[149].fileTimeLo = 1343808766U;
  c1_info[149].fileTimeHi = 0U;
  c1_info[149].mFileTimeLo = 0U;
  c1_info[149].mFileTimeHi = 0U;
  c1_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[150].name = "realmin";
  c1_info[150].dominantType = "char";
  c1_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[150].fileTimeLo = 1307629642U;
  c1_info[150].fileTimeHi = 0U;
  c1_info[150].mFileTimeLo = 0U;
  c1_info[150].mFileTimeHi = 0U;
  c1_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[151].name = "eml_index_class";
  c1_info[151].dominantType = "";
  c1_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[151].fileTimeLo = 1323145378U;
  c1_info[151].fileTimeHi = 0U;
  c1_info[151].mFileTimeLo = 0U;
  c1_info[151].mFileTimeHi = 0U;
  c1_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[152].name = "eml_index_minus";
  c1_info[152].dominantType = "double";
  c1_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[152].fileTimeLo = 1286797178U;
  c1_info[152].fileTimeHi = 0U;
  c1_info[152].mFileTimeLo = 0U;
  c1_info[152].mFileTimeHi = 0U;
  c1_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[153].name = "eml_index_times";
  c1_info[153].dominantType = "coder.internal.indexInt";
  c1_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[153].fileTimeLo = 1286797180U;
  c1_info[153].fileTimeHi = 0U;
  c1_info[153].mFileTimeLo = 0U;
  c1_info[153].mFileTimeHi = 0U;
  c1_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[154].name = "eml_index_plus";
  c1_info[154].dominantType = "coder.internal.indexInt";
  c1_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[154].fileTimeLo = 1286797178U;
  c1_info[154].fileTimeHi = 0U;
  c1_info[154].mFileTimeLo = 0U;
  c1_info[154].mFileTimeHi = 0U;
  c1_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[155].name = "eml_int_forloop_overflow_check";
  c1_info[155].dominantType = "";
  c1_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[155].fileTimeLo = 1346488740U;
  c1_info[155].fileTimeHi = 0U;
  c1_info[155].mFileTimeLo = 0U;
  c1_info[155].mFileTimeHi = 0U;
  c1_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[156].name = "eml_index_plus";
  c1_info[156].dominantType = "coder.internal.indexInt";
  c1_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[156].fileTimeLo = 1286797178U;
  c1_info[156].fileTimeHi = 0U;
  c1_info[156].mFileTimeLo = 0U;
  c1_info[156].mFileTimeHi = 0U;
  c1_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[157].name = "eml_index_minus";
  c1_info[157].dominantType = "double";
  c1_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[157].fileTimeLo = 1286797178U;
  c1_info[157].fileTimeHi = 0U;
  c1_info[157].mFileTimeLo = 0U;
  c1_info[157].mFileTimeHi = 0U;
  c1_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[158].name = "eml_index_plus";
  c1_info[158].dominantType = "double";
  c1_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[158].fileTimeLo = 1286797178U;
  c1_info[158].fileTimeHi = 0U;
  c1_info[158].mFileTimeLo = 0U;
  c1_info[158].mFileTimeHi = 0U;
  c1_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[159].name = "eml_index_times";
  c1_info[159].dominantType = "coder.internal.indexInt";
  c1_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[159].fileTimeLo = 1286797180U;
  c1_info[159].fileTimeHi = 0U;
  c1_info[159].mFileTimeLo = 0U;
  c1_info[159].mFileTimeHi = 0U;
  c1_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[160].name = "eml_index_minus";
  c1_info[160].dominantType = "coder.internal.indexInt";
  c1_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[160].fileTimeLo = 1286797178U;
  c1_info[160].fileTimeHi = 0U;
  c1_info[160].mFileTimeLo = 0U;
  c1_info[160].mFileTimeHi = 0U;
  c1_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[161].name = "eml_ixamax";
  c1_info[161].dominantType = "double";
  c1_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[161].fileTimeLo = 1299051570U;
  c1_info[161].fileTimeHi = 0U;
  c1_info[161].mFileTimeLo = 0U;
  c1_info[161].mFileTimeHi = 0U;
  c1_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c1_info[162].name = "length";
  c1_info[162].dominantType = "double";
  c1_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[162].fileTimeLo = 1303124606U;
  c1_info[162].fileTimeHi = 0U;
  c1_info[162].mFileTimeLo = 0U;
  c1_info[162].mFileTimeHi = 0U;
  c1_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[163].name = "eml_xswap";
  c1_info[163].dominantType = "double";
  c1_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[163].fileTimeLo = 1299051578U;
  c1_info[163].fileTimeHi = 0U;
  c1_info[163].mFileTimeLo = 0U;
  c1_info[163].mFileTimeHi = 0U;
  c1_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[164].name = "eml_matlab_zlarfg";
  c1_info[164].dominantType = "double";
  c1_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[164].fileTimeLo = 1286797222U;
  c1_info[164].fileTimeHi = 0U;
  c1_info[164].mFileTimeLo = 0U;
  c1_info[164].mFileTimeHi = 0U;
  c1_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[165].name = "eml_scalar_eg";
  c1_info[165].dominantType = "double";
  c1_info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[165].fileTimeLo = 1286797196U;
  c1_info[165].fileTimeHi = 0U;
  c1_info[165].mFileTimeLo = 0U;
  c1_info[165].mFileTimeHi = 0U;
  c1_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[166].name = "eml_xnrm2";
  c1_info[166].dominantType = "double";
  c1_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[166].fileTimeLo = 1299051576U;
  c1_info[166].fileTimeHi = 0U;
  c1_info[166].mFileTimeLo = 0U;
  c1_info[166].mFileTimeHi = 0U;
  c1_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[167].name = "eml_dlapy2";
  c1_info[167].dominantType = "double";
  c1_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[167].fileTimeLo = 1350389054U;
  c1_info[167].fileTimeHi = 0U;
  c1_info[167].mFileTimeLo = 0U;
  c1_info[167].mFileTimeHi = 0U;
  c1_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[168].name = "realmin";
  c1_info[168].dominantType = "char";
  c1_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[168].fileTimeLo = 1307629642U;
  c1_info[168].fileTimeHi = 0U;
  c1_info[168].mFileTimeLo = 0U;
  c1_info[168].mFileTimeHi = 0U;
  c1_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[169].name = "eps";
  c1_info[169].dominantType = "char";
  c1_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[169].fileTimeLo = 1326702796U;
  c1_info[169].fileTimeHi = 0U;
  c1_info[169].mFileTimeLo = 0U;
  c1_info[169].mFileTimeHi = 0U;
  c1_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[170].name = "abs";
  c1_info[170].dominantType = "double";
  c1_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[170].fileTimeLo = 1343808766U;
  c1_info[170].fileTimeHi = 0U;
  c1_info[170].mFileTimeLo = 0U;
  c1_info[170].mFileTimeHi = 0U;
  c1_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[171].name = "eml_index_class";
  c1_info[171].dominantType = "";
  c1_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[171].fileTimeLo = 1323145378U;
  c1_info[171].fileTimeHi = 0U;
  c1_info[171].mFileTimeLo = 0U;
  c1_info[171].mFileTimeHi = 0U;
  c1_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[172].name = "eml_index_plus";
  c1_info[172].dominantType = "double";
  c1_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[172].fileTimeLo = 1286797178U;
  c1_info[172].fileTimeHi = 0U;
  c1_info[172].mFileTimeLo = 0U;
  c1_info[172].mFileTimeHi = 0U;
  c1_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[173].name = "eml_xscal";
  c1_info[173].dominantType = "double";
  c1_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[173].fileTimeLo = 1299051576U;
  c1_info[173].fileTimeHi = 0U;
  c1_info[173].mFileTimeLo = 0U;
  c1_info[173].mFileTimeHi = 0U;
  c1_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c1_info[174].name = "eml_blas_inline";
  c1_info[174].dominantType = "";
  c1_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[174].fileTimeLo = 1299051568U;
  c1_info[174].fileTimeHi = 0U;
  c1_info[174].mFileTimeLo = 0U;
  c1_info[174].mFileTimeHi = 0U;
  c1_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[175].name = "eml_index_class";
  c1_info[175].dominantType = "";
  c1_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[175].fileTimeLo = 1323145378U;
  c1_info[175].fileTimeHi = 0U;
  c1_info[175].mFileTimeLo = 0U;
  c1_info[175].mFileTimeHi = 0U;
  c1_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[176].name = "eml_scalar_eg";
  c1_info[176].dominantType = "double";
  c1_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[176].fileTimeLo = 1286797196U;
  c1_info[176].fileTimeHi = 0U;
  c1_info[176].mFileTimeLo = 0U;
  c1_info[176].mFileTimeHi = 0U;
  c1_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c1_info[177].name = "eml_refblas_xscal";
  c1_info[177].dominantType = "double";
  c1_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[177].fileTimeLo = 1299051584U;
  c1_info[177].fileTimeHi = 0U;
  c1_info[177].mFileTimeLo = 0U;
  c1_info[177].mFileTimeHi = 0U;
  c1_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[178].name = "eml_index_class";
  c1_info[178].dominantType = "";
  c1_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[178].fileTimeLo = 1323145378U;
  c1_info[178].fileTimeHi = 0U;
  c1_info[178].mFileTimeLo = 0U;
  c1_info[178].mFileTimeHi = 0U;
  c1_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[179].name = "eml_index_minus";
  c1_info[179].dominantType = "double";
  c1_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[179].fileTimeLo = 1286797178U;
  c1_info[179].fileTimeHi = 0U;
  c1_info[179].mFileTimeLo = 0U;
  c1_info[179].mFileTimeHi = 0U;
  c1_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[180].name = "eml_index_times";
  c1_info[180].dominantType = "coder.internal.indexInt";
  c1_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[180].fileTimeLo = 1286797180U;
  c1_info[180].fileTimeHi = 0U;
  c1_info[180].mFileTimeLo = 0U;
  c1_info[180].mFileTimeHi = 0U;
  c1_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[181].name = "eml_index_plus";
  c1_info[181].dominantType = "coder.internal.indexInt";
  c1_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[181].fileTimeLo = 1286797178U;
  c1_info[181].fileTimeHi = 0U;
  c1_info[181].mFileTimeLo = 0U;
  c1_info[181].mFileTimeHi = 0U;
  c1_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c1_info[182].name = "eml_int_forloop_overflow_check";
  c1_info[182].dominantType = "";
  c1_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[182].fileTimeLo = 1346488740U;
  c1_info[182].fileTimeHi = 0U;
  c1_info[182].mFileTimeLo = 0U;
  c1_info[182].mFileTimeHi = 0U;
  c1_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[183].name = "mtimes";
  c1_info[183].dominantType = "double";
  c1_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[183].fileTimeLo = 1289494492U;
  c1_info[183].fileTimeHi = 0U;
  c1_info[183].mFileTimeLo = 0U;
  c1_info[183].mFileTimeHi = 0U;
  c1_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[184].name = "eml_div";
  c1_info[184].dominantType = "double";
  c1_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[184].fileTimeLo = 1313326210U;
  c1_info[184].fileTimeHi = 0U;
  c1_info[184].mFileTimeLo = 0U;
  c1_info[184].mFileTimeHi = 0U;
  c1_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarfg.m";
  c1_info[185].name = "eml_int_forloop_overflow_check";
  c1_info[185].dominantType = "";
  c1_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[185].fileTimeLo = 1346488740U;
  c1_info[185].fileTimeHi = 0U;
  c1_info[185].mFileTimeLo = 0U;
  c1_info[185].mFileTimeHi = 0U;
  c1_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c1_info[186].name = "length";
  c1_info[186].dominantType = "double";
  c1_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[186].fileTimeLo = 1303124606U;
  c1_info[186].fileTimeHi = 0U;
  c1_info[186].mFileTimeLo = 0U;
  c1_info[186].mFileTimeHi = 0U;
  c1_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[187].name = "eml_matlab_zlarf";
  c1_info[187].dominantType = "char";
  c1_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[187].fileTimeLo = 1286797222U;
  c1_info[187].fileTimeHi = 0U;
  c1_info[187].mFileTimeLo = 0U;
  c1_info[187].mFileTimeHi = 0U;
  c1_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[188].name = "eml_scalar_eg";
  c1_info[188].dominantType = "double";
  c1_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[188].fileTimeLo = 1286797196U;
  c1_info[188].fileTimeHi = 0U;
  c1_info[188].mFileTimeLo = 0U;
  c1_info[188].mFileTimeHi = 0U;
  c1_info[189].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[189].name = "eml_index_class";
  c1_info[189].dominantType = "";
  c1_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[189].fileTimeLo = 1323145378U;
  c1_info[189].fileTimeHi = 0U;
  c1_info[189].mFileTimeLo = 0U;
  c1_info[189].mFileTimeHi = 0U;
  c1_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[190].name = "isequal";
  c1_info[190].dominantType = "double";
  c1_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[190].fileTimeLo = 1286797158U;
  c1_info[190].fileTimeHi = 0U;
  c1_info[190].mFileTimeLo = 0U;
  c1_info[190].mFileTimeHi = 0U;
  c1_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[191].name = "coder.internal.indexIntRelop";
  c1_info[191].dominantType = "";
  c1_info[191].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c1_info[191].fileTimeLo = 1326703122U;
  c1_info[191].fileTimeHi = 0U;
  c1_info[191].mFileTimeLo = 0U;
  c1_info[191].mFileTimeHi = 0U;
}

static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[270])
{
  c1_info[192].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c1_info[192].name = "eml_float_model";
  c1_info[192].dominantType = "char";
  c1_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[192].fileTimeLo = 1326702796U;
  c1_info[192].fileTimeHi = 0U;
  c1_info[192].mFileTimeLo = 0U;
  c1_info[192].mFileTimeHi = 0U;
  c1_info[193].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c1_info[193].name = "intmin";
  c1_info[193].dominantType = "char";
  c1_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[193].fileTimeLo = 1311233718U;
  c1_info[193].fileTimeHi = 0U;
  c1_info[193].mFileTimeLo = 0U;
  c1_info[193].mFileTimeHi = 0U;
  c1_info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[194].name = "eml_index_minus";
  c1_info[194].dominantType = "double";
  c1_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[194].fileTimeLo = 1286797178U;
  c1_info[194].fileTimeHi = 0U;
  c1_info[194].mFileTimeLo = 0U;
  c1_info[194].mFileTimeHi = 0U;
  c1_info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[195].name = "eml_index_times";
  c1_info[195].dominantType = "double";
  c1_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[195].fileTimeLo = 1286797180U;
  c1_info[195].fileTimeHi = 0U;
  c1_info[195].mFileTimeLo = 0U;
  c1_info[195].mFileTimeHi = 0U;
  c1_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[196].name = "eml_index_plus";
  c1_info[196].dominantType = "coder.internal.indexInt";
  c1_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[196].fileTimeLo = 1286797178U;
  c1_info[196].fileTimeHi = 0U;
  c1_info[196].mFileTimeLo = 0U;
  c1_info[196].mFileTimeHi = 0U;
  c1_info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[197].name = "eml_index_class";
  c1_info[197].dominantType = "";
  c1_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[197].fileTimeLo = 1323145378U;
  c1_info[197].fileTimeHi = 0U;
  c1_info[197].mFileTimeLo = 0U;
  c1_info[197].mFileTimeHi = 0U;
  c1_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[198].name = "eml_index_minus";
  c1_info[198].dominantType = "double";
  c1_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[198].fileTimeLo = 1286797178U;
  c1_info[198].fileTimeHi = 0U;
  c1_info[198].mFileTimeLo = 0U;
  c1_info[198].mFileTimeHi = 0U;
  c1_info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[199].name = "eml_index_times";
  c1_info[199].dominantType = "coder.internal.indexInt";
  c1_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[199].fileTimeLo = 1286797180U;
  c1_info[199].fileTimeHi = 0U;
  c1_info[199].mFileTimeLo = 0U;
  c1_info[199].mFileTimeHi = 0U;
  c1_info[200].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[200].name = "eml_index_plus";
  c1_info[200].dominantType = "coder.internal.indexInt";
  c1_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[200].fileTimeLo = 1286797178U;
  c1_info[200].fileTimeHi = 0U;
  c1_info[200].mFileTimeLo = 0U;
  c1_info[200].mFileTimeHi = 0U;
  c1_info[201].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m!ilazlc";
  c1_info[201].name = "eml_int_forloop_overflow_check";
  c1_info[201].dominantType = "";
  c1_info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[201].fileTimeLo = 1346488740U;
  c1_info[201].fileTimeHi = 0U;
  c1_info[201].mFileTimeLo = 0U;
  c1_info[201].mFileTimeHi = 0U;
  c1_info[202].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[202].name = "eml_xgemv";
  c1_info[202].dominantType = "char";
  c1_info[202].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c1_info[202].fileTimeLo = 1299051574U;
  c1_info[202].fileTimeHi = 0U;
  c1_info[202].mFileTimeLo = 0U;
  c1_info[202].mFileTimeHi = 0U;
  c1_info[203].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemv.m";
  c1_info[203].name = "eml_blas_inline";
  c1_info[203].dominantType = "";
  c1_info[203].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[203].fileTimeLo = 1299051568U;
  c1_info[203].fileTimeHi = 0U;
  c1_info[203].mFileTimeLo = 0U;
  c1_info[203].mFileTimeHi = 0U;
  c1_info[204].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[204].name = "eml_index_class";
  c1_info[204].dominantType = "";
  c1_info[204].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[204].fileTimeLo = 1323145378U;
  c1_info[204].fileTimeHi = 0U;
  c1_info[204].mFileTimeLo = 0U;
  c1_info[204].mFileTimeHi = 0U;
  c1_info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[205].name = "eml_scalar_eg";
  c1_info[205].dominantType = "double";
  c1_info[205].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[205].fileTimeLo = 1286797196U;
  c1_info[205].fileTimeHi = 0U;
  c1_info[205].mFileTimeLo = 0U;
  c1_info[205].mFileTimeHi = 0U;
  c1_info[206].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemv.m";
  c1_info[206].name = "eml_refblas_xgemv";
  c1_info[206].dominantType = "char";
  c1_info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[206].fileTimeLo = 1299051576U;
  c1_info[206].fileTimeHi = 0U;
  c1_info[206].mFileTimeLo = 0U;
  c1_info[206].mFileTimeHi = 0U;
  c1_info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[207].name = "eml_index_minus";
  c1_info[207].dominantType = "double";
  c1_info[207].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[207].fileTimeLo = 1286797178U;
  c1_info[207].fileTimeHi = 0U;
  c1_info[207].mFileTimeLo = 0U;
  c1_info[207].mFileTimeHi = 0U;
  c1_info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[208].name = "eml_index_class";
  c1_info[208].dominantType = "";
  c1_info[208].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[208].fileTimeLo = 1323145378U;
  c1_info[208].fileTimeHi = 0U;
  c1_info[208].mFileTimeLo = 0U;
  c1_info[208].mFileTimeHi = 0U;
  c1_info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[209].name = "eml_index_times";
  c1_info[209].dominantType = "coder.internal.indexInt";
  c1_info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[209].fileTimeLo = 1286797180U;
  c1_info[209].fileTimeHi = 0U;
  c1_info[209].mFileTimeLo = 0U;
  c1_info[209].mFileTimeHi = 0U;
  c1_info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[210].name = "eml_index_plus";
  c1_info[210].dominantType = "coder.internal.indexInt";
  c1_info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[210].fileTimeLo = 1286797178U;
  c1_info[210].fileTimeHi = 0U;
  c1_info[210].mFileTimeLo = 0U;
  c1_info[210].mFileTimeHi = 0U;
  c1_info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[211].name = "eml_int_forloop_overflow_check";
  c1_info[211].dominantType = "";
  c1_info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[211].fileTimeLo = 1346488740U;
  c1_info[211].fileTimeHi = 0U;
  c1_info[211].mFileTimeLo = 0U;
  c1_info[211].mFileTimeHi = 0U;
  c1_info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[212].name = "eml_scalar_eg";
  c1_info[212].dominantType = "double";
  c1_info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[212].fileTimeLo = 1286797196U;
  c1_info[212].fileTimeHi = 0U;
  c1_info[212].mFileTimeLo = 0U;
  c1_info[212].mFileTimeHi = 0U;
  c1_info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemv.m";
  c1_info[213].name = "eml_conjtimes";
  c1_info[213].dominantType = "double";
  c1_info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c1_info[213].fileTimeLo = 1286797096U;
  c1_info[213].fileTimeHi = 0U;
  c1_info[213].mFileTimeLo = 0U;
  c1_info[213].mFileTimeHi = 0U;
  c1_info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlarf.m";
  c1_info[214].name = "eml_xgerc";
  c1_info[214].dominantType = "double";
  c1_info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[214].fileTimeLo = 1299051574U;
  c1_info[214].fileTimeHi = 0U;
  c1_info[214].mFileTimeLo = 0U;
  c1_info[214].mFileTimeHi = 0U;
  c1_info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[215].name = "eml_blas_inline";
  c1_info[215].dominantType = "";
  c1_info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[215].fileTimeLo = 1299051568U;
  c1_info[215].fileTimeHi = 0U;
  c1_info[215].mFileTimeLo = 0U;
  c1_info[215].mFileTimeHi = 0U;
  c1_info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgerc.m";
  c1_info[216].name = "eml_xger";
  c1_info[216].dominantType = "double";
  c1_info[216].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[216].fileTimeLo = 1299051574U;
  c1_info[216].fileTimeHi = 0U;
  c1_info[216].mFileTimeLo = 0U;
  c1_info[216].mFileTimeHi = 0U;
  c1_info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[217].name = "length";
  c1_info[217].dominantType = "double";
  c1_info[217].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[217].fileTimeLo = 1303124606U;
  c1_info[217].fileTimeHi = 0U;
  c1_info[217].mFileTimeLo = 0U;
  c1_info[217].mFileTimeHi = 0U;
  c1_info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[218].name = "abs";
  c1_info[218].dominantType = "double";
  c1_info[218].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[218].fileTimeLo = 1343808766U;
  c1_info[218].fileTimeHi = 0U;
  c1_info[218].mFileTimeLo = 0U;
  c1_info[218].mFileTimeHi = 0U;
  c1_info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgeqp3.m";
  c1_info[219].name = "mtimes";
  c1_info[219].dominantType = "double";
  c1_info[219].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[219].fileTimeLo = 1289494492U;
  c1_info[219].fileTimeHi = 0U;
  c1_info[219].mFileTimeLo = 0U;
  c1_info[219].mFileTimeHi = 0U;
  c1_info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[220].name = "max";
  c1_info[220].dominantType = "double";
  c1_info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[220].fileTimeLo = 1311233716U;
  c1_info[220].fileTimeHi = 0U;
  c1_info[220].mFileTimeLo = 0U;
  c1_info[220].mFileTimeHi = 0U;
  c1_info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[221].name = "eml_min_or_max";
  c1_info[221].dominantType = "char";
  c1_info[221].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[221].fileTimeLo = 1334049890U;
  c1_info[221].fileTimeHi = 0U;
  c1_info[221].mFileTimeLo = 0U;
  c1_info[221].mFileTimeHi = 0U;
  c1_info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[222].name = "eml_xcabs1";
  c1_info[222].dominantType = "double";
  c1_info[222].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[222].fileTimeLo = 1286797106U;
  c1_info[222].fileTimeHi = 0U;
  c1_info[222].mFileTimeLo = 0U;
  c1_info[222].mFileTimeHi = 0U;
  c1_info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[223].name = "mtimes";
  c1_info[223].dominantType = "double";
  c1_info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[223].fileTimeLo = 1289494492U;
  c1_info[223].fileTimeHi = 0U;
  c1_info[223].mFileTimeLo = 0U;
  c1_info[223].mFileTimeHi = 0U;
  c1_info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[224].name = "eps";
  c1_info[224].dominantType = "char";
  c1_info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[224].fileTimeLo = 1326702796U;
  c1_info[224].fileTimeHi = 0U;
  c1_info[224].mFileTimeLo = 0U;
  c1_info[224].mFileTimeHi = 0U;
  c1_info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[225].name = "eml_flt2str";
  c1_info[225].dominantType = "double";
  c1_info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[225].fileTimeLo = 1309429596U;
  c1_info[225].fileTimeHi = 0U;
  c1_info[225].mFileTimeLo = 0U;
  c1_info[225].mFileTimeHi = 0U;
  c1_info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c1_info[226].name = "char";
  c1_info[226].dominantType = "double";
  c1_info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c1_info[226].fileTimeLo = 1319708368U;
  c1_info[226].fileTimeHi = 0U;
  c1_info[226].mFileTimeLo = 0U;
  c1_info[226].mFileTimeHi = 0U;
  c1_info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[227].name = "eml_warning";
  c1_info[227].dominantType = "char";
  c1_info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[227].fileTimeLo = 1286797202U;
  c1_info[227].fileTimeHi = 0U;
  c1_info[227].mFileTimeLo = 0U;
  c1_info[227].mFileTimeHi = 0U;
  c1_info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[228].name = "eml_scalar_eg";
  c1_info[228].dominantType = "double";
  c1_info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[228].fileTimeLo = 1286797196U;
  c1_info[228].fileTimeHi = 0U;
  c1_info[228].mFileTimeLo = 0U;
  c1_info[228].mFileTimeHi = 0U;
  c1_info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[229].name = "eml_conjtimes";
  c1_info[229].dominantType = "double";
  c1_info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_conjtimes.m";
  c1_info[229].fileTimeLo = 1286797096U;
  c1_info[229].fileTimeHi = 0U;
  c1_info[229].mFileTimeLo = 0U;
  c1_info[229].mFileTimeHi = 0U;
  c1_info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_qrsolve.m";
  c1_info[230].name = "eml_div";
  c1_info[230].dominantType = "double";
  c1_info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[230].fileTimeLo = 1313326210U;
  c1_info[230].fileTimeHi = 0U;
  c1_info[230].mFileTimeLo = 0U;
  c1_info[230].mFileTimeHi = 0U;
  c1_info[231].context = "";
  c1_info[231].name = "mtimes";
  c1_info[231].dominantType = "double";
  c1_info[231].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[231].fileTimeLo = 1289494492U;
  c1_info[231].fileTimeHi = 0U;
  c1_info[231].mFileTimeLo = 0U;
  c1_info[231].mFileTimeHi = 0U;
  c1_info[232].context = "";
  c1_info[232].name = "mpower";
  c1_info[232].dominantType = "double";
  c1_info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[232].fileTimeLo = 1286797242U;
  c1_info[232].fileTimeHi = 0U;
  c1_info[232].mFileTimeLo = 0U;
  c1_info[232].mFileTimeHi = 0U;
  c1_info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[233].name = "power";
  c1_info[233].dominantType = "double";
  c1_info[233].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[233].fileTimeLo = 1348170330U;
  c1_info[233].fileTimeHi = 0U;
  c1_info[233].mFileTimeLo = 0U;
  c1_info[233].mFileTimeHi = 0U;
  c1_info[234].context = "";
  c1_info[234].name = "mrdivide";
  c1_info[234].dominantType = "double";
  c1_info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[234].fileTimeLo = 1357926348U;
  c1_info[234].fileTimeHi = 0U;
  c1_info[234].mFileTimeLo = 1319708366U;
  c1_info[234].mFileTimeHi = 0U;
  c1_info[235].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[235].name = "rdivide";
  c1_info[235].dominantType = "double";
  c1_info[235].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[235].fileTimeLo = 1346488788U;
  c1_info[235].fileTimeHi = 0U;
  c1_info[235].mFileTimeLo = 0U;
  c1_info[235].mFileTimeHi = 0U;
  c1_info[236].context = "";
  c1_info[236].name = "sqrt";
  c1_info[236].dominantType = "double";
  c1_info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[236].fileTimeLo = 1343808786U;
  c1_info[236].fileTimeHi = 0U;
  c1_info[236].mFileTimeLo = 0U;
  c1_info[236].mFileTimeHi = 0U;
  c1_info[237].context = "";
  c1_info[237].name = "colon";
  c1_info[237].dominantType = "double";
  c1_info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[237].fileTimeLo = 1348170328U;
  c1_info[237].fileTimeHi = 0U;
  c1_info[237].mFileTimeLo = 0U;
  c1_info[237].mFileTimeHi = 0U;
  c1_info[238].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c1_info[238].name = "isfinite";
  c1_info[238].dominantType = "double";
  c1_info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[238].fileTimeLo = 1286797158U;
  c1_info[238].fileTimeHi = 0U;
  c1_info[238].mFileTimeLo = 0U;
  c1_info[238].mFileTimeHi = 0U;
  c1_info[239].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[239].name = "isinf";
  c1_info[239].dominantType = "double";
  c1_info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[239].fileTimeLo = 1286797160U;
  c1_info[239].fileTimeHi = 0U;
  c1_info[239].mFileTimeLo = 0U;
  c1_info[239].mFileTimeHi = 0U;
  c1_info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[240].name = "isnan";
  c1_info[240].dominantType = "double";
  c1_info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[240].fileTimeLo = 1286797160U;
  c1_info[240].fileTimeHi = 0U;
  c1_info[240].mFileTimeLo = 0U;
  c1_info[240].mFileTimeHi = 0U;
  c1_info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c1_info[241].name = "floor";
  c1_info[241].dominantType = "double";
  c1_info[241].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[241].fileTimeLo = 1343808780U;
  c1_info[241].fileTimeHi = 0U;
  c1_info[241].mFileTimeLo = 0U;
  c1_info[241].mFileTimeHi = 0U;
  c1_info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[242].name = "realmax";
  c1_info[242].dominantType = "char";
  c1_info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[242].fileTimeLo = 1307629642U;
  c1_info[242].fileTimeHi = 0U;
  c1_info[242].mFileTimeLo = 0U;
  c1_info[242].mFileTimeHi = 0U;
  c1_info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[243].name = "eml_realmax";
  c1_info[243].dominantType = "char";
  c1_info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[243].fileTimeLo = 1326702796U;
  c1_info[243].fileTimeHi = 0U;
  c1_info[243].mFileTimeLo = 0U;
  c1_info[243].mFileTimeHi = 0U;
  c1_info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[244].name = "eml_float_model";
  c1_info[244].dominantType = "char";
  c1_info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[244].fileTimeLo = 1326702796U;
  c1_info[244].fileTimeHi = 0U;
  c1_info[244].mFileTimeLo = 0U;
  c1_info[244].mFileTimeHi = 0U;
  c1_info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[245].name = "mtimes";
  c1_info[245].dominantType = "double";
  c1_info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[245].fileTimeLo = 1289494492U;
  c1_info[245].fileTimeHi = 0U;
  c1_info[245].mFileTimeLo = 0U;
  c1_info[245].mFileTimeHi = 0U;
  c1_info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[246].name = "isnan";
  c1_info[246].dominantType = "double";
  c1_info[246].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[246].fileTimeLo = 1286797160U;
  c1_info[246].fileTimeHi = 0U;
  c1_info[246].mFileTimeLo = 0U;
  c1_info[246].mFileTimeHi = 0U;
  c1_info[247].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[247].name = "isinf";
  c1_info[247].dominantType = "double";
  c1_info[247].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[247].fileTimeLo = 1286797160U;
  c1_info[247].fileTimeHi = 0U;
  c1_info[247].mFileTimeLo = 0U;
  c1_info[247].mFileTimeHi = 0U;
  c1_info[248].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[248].name = "floor";
  c1_info[248].dominantType = "double";
  c1_info[248].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[248].fileTimeLo = 1343808780U;
  c1_info[248].fileTimeHi = 0U;
  c1_info[248].mFileTimeLo = 0U;
  c1_info[248].mFileTimeHi = 0U;
  c1_info[249].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[249].name = "mtimes";
  c1_info[249].dominantType = "double";
  c1_info[249].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[249].fileTimeLo = 1289494492U;
  c1_info[249].fileTimeHi = 0U;
  c1_info[249].mFileTimeLo = 0U;
  c1_info[249].mFileTimeHi = 0U;
  c1_info[250].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[250].name = "abs";
  c1_info[250].dominantType = "double";
  c1_info[250].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[250].fileTimeLo = 1343808766U;
  c1_info[250].fileTimeHi = 0U;
  c1_info[250].mFileTimeLo = 0U;
  c1_info[250].mFileTimeHi = 0U;
  c1_info[251].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[251].name = "eps";
  c1_info[251].dominantType = "char";
  c1_info[251].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[251].fileTimeLo = 1326702796U;
  c1_info[251].fileTimeHi = 0U;
  c1_info[251].mFileTimeLo = 0U;
  c1_info[251].mFileTimeHi = 0U;
  c1_info[252].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c1_info[252].name = "abs";
  c1_info[252].dominantType = "double";
  c1_info[252].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[252].fileTimeLo = 1343808766U;
  c1_info[252].fileTimeHi = 0U;
  c1_info[252].mFileTimeLo = 0U;
  c1_info[252].mFileTimeHi = 0U;
  c1_info[253].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[253].name = "eml_index_class";
  c1_info[253].dominantType = "";
  c1_info[253].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[253].fileTimeLo = 1323145378U;
  c1_info[253].fileTimeHi = 0U;
  c1_info[253].mFileTimeLo = 0U;
  c1_info[253].mFileTimeHi = 0U;
  c1_info[254].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[254].name = "intmax";
  c1_info[254].dominantType = "char";
  c1_info[254].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[254].fileTimeLo = 1311233716U;
  c1_info[254].fileTimeHi = 0U;
  c1_info[254].mFileTimeLo = 0U;
  c1_info[254].mFileTimeHi = 0U;
  c1_info[255].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length";
  c1_info[255].name = "coder.internal.indexIntRelop";
  c1_info[255].dominantType = "";
  c1_info[255].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c1_info[255].fileTimeLo = 1326703122U;
  c1_info[255].fileTimeHi = 0U;
  c1_info[255].mFileTimeLo = 0U;
  c1_info[255].mFileTimeHi = 0U;
}

static void c1_e_info_helper(c1_ResolvedFunctionInfo c1_info[270])
{
  c1_info[256].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[256].name = "eml_index_minus";
  c1_info[256].dominantType = "double";
  c1_info[256].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[256].fileTimeLo = 1286797178U;
  c1_info[256].fileTimeHi = 0U;
  c1_info[256].mFileTimeLo = 0U;
  c1_info[256].mFileTimeHi = 0U;
  c1_info[257].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[257].name = "eml_index_rdivide";
  c1_info[257].dominantType = "double";
  c1_info[257].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[257].fileTimeLo = 1286797180U;
  c1_info[257].fileTimeHi = 0U;
  c1_info[257].mFileTimeLo = 0U;
  c1_info[257].mFileTimeHi = 0U;
  c1_info[258].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[258].name = "eml_index_class";
  c1_info[258].dominantType = "";
  c1_info[258].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[258].fileTimeLo = 1323145378U;
  c1_info[258].fileTimeHi = 0U;
  c1_info[258].mFileTimeLo = 0U;
  c1_info[258].mFileTimeHi = 0U;
  c1_info[259].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[259].name = "eml_int_forloop_overflow_check";
  c1_info[259].dominantType = "";
  c1_info[259].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[259].fileTimeLo = 1346488740U;
  c1_info[259].fileTimeHi = 0U;
  c1_info[259].mFileTimeLo = 0U;
  c1_info[259].mFileTimeHi = 0U;
  c1_info[260].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[260].name = "mtimes";
  c1_info[260].dominantType = "double";
  c1_info[260].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[260].fileTimeLo = 1289494492U;
  c1_info[260].fileTimeHi = 0U;
  c1_info[260].mFileTimeLo = 0U;
  c1_info[260].mFileTimeHi = 0U;
  c1_info[261].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[261].name = "eml_index_times";
  c1_info[261].dominantType = "double";
  c1_info[261].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[261].fileTimeLo = 1286797180U;
  c1_info[261].fileTimeHi = 0U;
  c1_info[261].mFileTimeLo = 0U;
  c1_info[261].mFileTimeHi = 0U;
  c1_info[262].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[262].name = "eml_index_plus";
  c1_info[262].dominantType = "double";
  c1_info[262].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[262].fileTimeLo = 1286797178U;
  c1_info[262].fileTimeHi = 0U;
  c1_info[262].mFileTimeLo = 0U;
  c1_info[262].mFileTimeHi = 0U;
  c1_info[263].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon";
  c1_info[263].name = "eml_index_minus";
  c1_info[263].dominantType = "coder.internal.indexInt";
  c1_info[263].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[263].fileTimeLo = 1286797178U;
  c1_info[263].fileTimeHi = 0U;
  c1_info[263].mFileTimeLo = 0U;
  c1_info[263].mFileTimeHi = 0U;
  c1_info[264].context = "";
  c1_info[264].name = "cos";
  c1_info[264].dominantType = "double";
  c1_info[264].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[264].fileTimeLo = 1343808772U;
  c1_info[264].fileTimeHi = 0U;
  c1_info[264].mFileTimeLo = 0U;
  c1_info[264].mFileTimeHi = 0U;
  c1_info[265].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[265].name = "eml_scalar_cos";
  c1_info[265].dominantType = "double";
  c1_info[265].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[265].fileTimeLo = 1286797122U;
  c1_info[265].fileTimeHi = 0U;
  c1_info[265].mFileTimeLo = 0U;
  c1_info[265].mFileTimeHi = 0U;
  c1_info[266].context = "";
  c1_info[266].name = "sin";
  c1_info[266].dominantType = "double";
  c1_info[266].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[266].fileTimeLo = 1343808786U;
  c1_info[266].fileTimeHi = 0U;
  c1_info[266].mFileTimeLo = 0U;
  c1_info[266].mFileTimeHi = 0U;
  c1_info[267].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[267].name = "eml_scalar_sin";
  c1_info[267].dominantType = "double";
  c1_info[267].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[267].fileTimeLo = 1286797136U;
  c1_info[267].fileTimeHi = 0U;
  c1_info[267].mFileTimeLo = 0U;
  c1_info[267].mFileTimeHi = 0U;
  c1_info[268].context = "";
  c1_info[268].name = "length";
  c1_info[268].dominantType = "double";
  c1_info[268].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[268].fileTimeLo = 1303124606U;
  c1_info[268].fileTimeHi = 0U;
  c1_info[268].mFileTimeLo = 0U;
  c1_info[268].mFileTimeHi = 0U;
  c1_info[269].context = "";
  c1_info[269].name = "floor";
  c1_info[269].dominantType = "double";
  c1_info[269].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[269].fileTimeLo = 1343808780U;
  c1_info[269].fileTimeHi = 0U;
  c1_info[269].mFileTimeLo = 0U;
  c1_info[269].mFileTimeHi = 0U;
}

static void c1_check_forloop_overflow_error
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i93;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i94;
  static char_T c1_cv1[6] = { 'u', 'i', 'n', 't', '3', '2' };

  char_T c1_b_u[6];
  const mxArray *c1_b_y = NULL;
  for (c1_i93 = 0; c1_i93 < 34; c1_i93++) {
    c1_u[c1_i93] = c1_cv0[c1_i93];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  for (c1_i94 = 0; c1_i94 < 6; c1_i94++) {
    c1_b_u[c1_i94] = c1_cv1[c1_i94];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static void c1_eml_find(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, boolean_T c1_x[412800], int32_T c1_i_data[412800], int32_T
  c1_i_sizes[1], int32_T c1_j_data[412800], int32_T c1_j_sizes[1])
{
  int32_T c1_idx;
  static int32_T c1_iv3[1] = { 412800 };

  int32_T c1_ii;
  int32_T c1_jj;
  int32_T c1_a;
  int32_T c1_b_a;
  int32_T c1_c_a;
  boolean_T c1_b15;
  boolean_T c1_b16;
  boolean_T c1_b17;
  int32_T c1_i95;
  int32_T c1_tmp_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i96;
  static int32_T c1_tmp_data[412800];
  int32_T c1_b_i_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i97;
  static int32_T c1_b_i_data[412800];
  int32_T c1_c_loop_ub;
  int32_T c1_i98;
  boolean_T c1_b18;
  boolean_T c1_b19;
  boolean_T c1_b20;
  int32_T c1_i99;
  int32_T c1_d_loop_ub;
  int32_T c1_i100;
  int32_T c1_b_j_sizes;
  int32_T c1_e_loop_ub;
  int32_T c1_i101;
  static int32_T c1_b_j_data[412800];
  int32_T c1_f_loop_ub;
  int32_T c1_i102;
  boolean_T c1_b21;
  boolean_T c1_b22;
  boolean_T c1_b23;
  int32_T c1_i103;
  int32_T c1_g_loop_ub;
  int32_T c1_i104;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  c1_eml_scalar_eg(chartInstance);
  c1_idx = 0;
  c1_i_sizes[0] = c1_iv3[0];
  c1_j_sizes[0] = c1_iv3[0];
  c1_ii = 1;
  c1_jj = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c1_jj <= 860)) {
    guard1 = FALSE;
    if (c1_x[(c1_ii + 480 * (c1_jj - 1)) - 1]) {
      c1_a = c1_idx + 1;
      c1_idx = c1_a;
      c1_i_data[c1_idx - 1] = c1_ii;
      c1_j_data[c1_idx - 1] = c1_jj;
      if (c1_idx >= 412800) {
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

  c1_b15 = (1 > c1_idx);
  c1_b16 = c1_b15;
  c1_b17 = c1_b16;
  if (c1_b17) {
    c1_i95 = 0;
  } else {
    c1_i95 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 412800, 0, 0);
  }

  c1_tmp_sizes = c1_i95;
  c1_loop_ub = c1_i95 - 1;
  for (c1_i96 = 0; c1_i96 <= c1_loop_ub; c1_i96++) {
    c1_tmp_data[c1_i96] = 1 + c1_i96;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c1_tmp_sizes);
  c1_b_i_sizes = c1_tmp_sizes;
  c1_b_loop_ub = c1_tmp_sizes - 1;
  for (c1_i97 = 0; c1_i97 <= c1_b_loop_ub; c1_i97++) {
    c1_b_i_data[c1_i97] = c1_i_data[c1_tmp_data[c1_i97] - 1];
  }

  c1_i_sizes[0] = c1_b_i_sizes;
  c1_c_loop_ub = c1_b_i_sizes - 1;
  for (c1_i98 = 0; c1_i98 <= c1_c_loop_ub; c1_i98++) {
    c1_i_data[c1_i98] = c1_b_i_data[c1_i98];
  }

  c1_b18 = (1 > c1_idx);
  c1_b19 = c1_b18;
  c1_b20 = c1_b19;
  if (c1_b20) {
    c1_i99 = 0;
  } else {
    c1_i99 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 412800, 0, 0);
  }

  c1_tmp_sizes = c1_i99;
  c1_d_loop_ub = c1_i99 - 1;
  for (c1_i100 = 0; c1_i100 <= c1_d_loop_ub; c1_i100++) {
    c1_tmp_data[c1_i100] = 1 + c1_i100;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c1_tmp_sizes);
  c1_b_j_sizes = c1_tmp_sizes;
  c1_e_loop_ub = c1_tmp_sizes - 1;
  for (c1_i101 = 0; c1_i101 <= c1_e_loop_ub; c1_i101++) {
    c1_b_j_data[c1_i101] = c1_j_data[c1_tmp_data[c1_i101] - 1];
  }

  c1_j_sizes[0] = c1_b_j_sizes;
  c1_f_loop_ub = c1_b_j_sizes - 1;
  for (c1_i102 = 0; c1_i102 <= c1_f_loop_ub; c1_i102++) {
    c1_j_data[c1_i102] = c1_b_j_data[c1_i102];
  }

  c1_b21 = (1 > c1_idx);
  c1_b22 = c1_b21;
  c1_b23 = c1_b22;
  if (c1_b23) {
    c1_i103 = 0;
  } else {
    c1_i103 = _SFD_EML_ARRAY_BOUNDS_CHECK("", c1_idx, 1, 412800, 0, 0);
  }

  c1_tmp_sizes = c1_i103;
  c1_g_loop_ub = c1_i103 - 1;
  for (c1_i104 = 0; c1_i104 <= c1_g_loop_ub; c1_i104++) {
    c1_tmp_data[c1_i104] = 1 + c1_i104;
  }

  _SFD_VECTOR_VECTOR_INDEX_CHECK(412800, 1, 1, c1_tmp_sizes);
}

static void c1_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static real_T c1_mean(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c1_x_data[412800], int32_T c1_x_sizes[1])
{
  boolean_T c1_p;
  boolean_T c1_b_p;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_d1;
  real_T c1_d2;
  boolean_T c1_b24;
  boolean_T c1_c_p;
  boolean_T c1_b25;
  int32_T c1_i105;
  static char_T c1_cv2[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'm', 'e', 'a', 'n', '_', 's', 'p', 'e', 'c', 'i', 'a',
    'l', 'E', 'm', 'p', 't', 'y' };

  char_T c1_u[31];
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b26;
  int32_T c1_i106;
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

  c1_b24 = c1_b_p;
  c1_c_p = c1_b24;
  if (!c1_c_p) {
  } else {
    c1_p = TRUE;
  }

  c1_b25 = !c1_p;
  if (c1_b25) {
  } else {
    for (c1_i105 = 0; c1_i105 < 31; c1_i105++) {
      c1_u[c1_i105] = c1_cv2[c1_i105];
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
    c1_b26 = FALSE;
  }

  if (guard1 == TRUE) {
    c1_b26 = TRUE;
  }

  if (c1_b26) {
  } else {
    for (c1_i106 = 0; c1_i106 < 36; c1_i106++) {
      c1_b_u[c1_i106] = c1_cv3[c1_i106];
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
  (SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i107;
  static char_T c1_cv4[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i108;
  static char_T c1_cv5[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c1_b_u[23];
  const mxArray *c1_b_y = NULL;
  for (c1_i107 = 0; c1_i107 < 34; c1_i107++) {
    c1_u[c1_i107] = c1_cv4[c1_i107];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  for (c1_i108 = 0; c1_i108 < 23; c1_i108++) {
    c1_b_u[c1_i108] = c1_cv5[c1_i108];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static void c1_power(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                     real_T c1_a_data[10], int32_T c1_a_sizes[1], real_T
                     c1_y_data[10], int32_T c1_y_sizes[1])
{
  real_T c1_dv6[2];
  int32_T c1_tmp_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i109;
  real_T c1_temp;
  real_T c1_tmp_data[10];
  real_T c1_d3;
  int32_T c1_i110;
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_ak;
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_b;
  real_T c1_y;
  c1_dv6[0] = (real_T)c1_a_sizes[0];
  c1_dv6[1] = 1.0;
  c1_tmp_sizes = (int32_T)c1_dv6[0];
  c1_loop_ub = (int32_T)c1_dv6[0] - 1;
  for (c1_i109 = 0; c1_i109 <= c1_loop_ub; c1_i109++) {
    c1_tmp_data[c1_i109] = c1_temp;
  }

  c1_y_sizes[0] = c1_tmp_sizes;
  c1_d3 = (real_T)c1_y_sizes[0];
  c1_i110 = (int32_T)c1_d3 - 1;
  for (c1_k = 0; c1_k <= c1_i110; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_ak = c1_a_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      c1_b_k, 1, c1_a_sizes[0], 1, 0) - 1];
    c1_a = c1_ak;
    c1_b_eml_scalar_eg(chartInstance);
    c1_b_a = c1_a;
    c1_b = c1_a;
    c1_y = c1_b_a * c1_b;
    c1_y_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_b_k,
      1, c1_y_sizes[0], 1, 0) - 1] = c1_y;
  }
}

static void c1_b_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static void c1_mldivide(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[30], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_Y_data[10], int32_T c1_Y_sizes[1])
{
  int32_T c1_i111;
  static char_T c1_cv6[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'd', 'i', 'm', 'a', 'g', 'r', 'e', 'e' };

  char_T c1_u[21];
  const mxArray *c1_y = NULL;
  boolean_T c1_b27;
  int32_T c1_i112;
  real_T c1_dv7[3];
  int32_T c1_i113;
  int32_T c1_b_A_sizes[2];
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i114;
  real_T c1_b_A_data[9];
  int32_T c1_info;
  int32_T c1_ipiv[3];
  int32_T c1_b_info;
  int32_T c1_c_info;
  int32_T c1_d_info;
  int32_T c1_b_loop_ub;
  int32_T c1_i115;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_ip;
  int32_T c1_Y[2];
  real_T c1_temp;
  int32_T c1_b_Y[2];
  int32_T c1_c_Y[2];
  int32_T c1_tmp_sizes[2];
  int32_T c1_d_Y[2];
  int32_T c1_b_tmp_sizes[2];
  int32_T c1_c_A_sizes[2];
  int32_T c1_c_A;
  int32_T c1_d_A;
  int32_T c1_c_loop_ub;
  int32_T c1_i116;
  real_T c1_c_A_data[9];
  int32_T c1_d_A_sizes[2];
  int32_T c1_e_A;
  int32_T c1_f_A;
  int32_T c1_d_loop_ub;
  int32_T c1_i117;
  real_T c1_d_A_data[9];
  int32_T c1_e_A_sizes[2];
  int32_T c1_g_A;
  int32_T c1_h_A;
  int32_T c1_e_loop_ub;
  int32_T c1_i118;
  real_T c1_e_A_data[30];
  int32_T c1_b_B_sizes;
  int32_T c1_f_loop_ub;
  int32_T c1_i119;
  real_T c1_b_B_data[10];
  int32_T c1_i120;
  boolean_T guard1 = FALSE;
  if ((real_T)c1_B_sizes[0] == (real_T)c1_A_sizes[0]) {
  } else {
    for (c1_i111 = 0; c1_i111 < 21; c1_i111++) {
      c1_u[c1_i111] = c1_cv6[c1_i111];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 21),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c1_y));
  }

  c1_b27 = (c1_A_sizes[0] == 0);
  guard1 = FALSE;
  if (c1_b27) {
    guard1 = TRUE;
  } else if (c1_B_sizes[0] == 0) {
    guard1 = TRUE;
  } else if ((real_T)c1_A_sizes[0] == 3.0) {
    c1_b_A_sizes[0] = c1_A_sizes[0];
    c1_b_A_sizes[1] = 3;
    c1_A = c1_b_A_sizes[0];
    c1_b_A = c1_b_A_sizes[1];
    c1_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
    for (c1_i114 = 0; c1_i114 <= c1_loop_ub; c1_i114++) {
      c1_b_A_data[c1_i114] = c1_A_data[c1_i114];
    }

    c1_b_eml_matlab_zgetrf(chartInstance, c1_b_A_data, c1_b_A_sizes, c1_ipiv,
      &c1_info);
    c1_b_info = c1_info;
    c1_c_info = c1_b_info;
    c1_d_info = c1_c_info;
    if (c1_d_info > 0) {
      c1_eml_warning(chartInstance);
    }

    c1_c_eml_scalar_eg(chartInstance);
    c1_Y_sizes[0] = c1_B_sizes[0];
    c1_b_loop_ub = c1_B_sizes[0] - 1;
    for (c1_i115 = 0; c1_i115 <= c1_b_loop_ub; c1_i115++) {
      c1_Y_data[c1_i115] = c1_B_data[c1_i115];
    }

    for (c1_i = 1; c1_i < 4; c1_i++) {
      c1_b_i = c1_i;
      if (c1_ipiv[c1_b_i - 1] != c1_b_i) {
        c1_ip = c1_ipiv[c1_b_i - 1];
        c1_Y[0] = c1_Y_sizes[0];
        c1_Y[1] = 1;
        c1_temp = c1_Y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1,
          c1_Y_sizes[0], 1, 0) - 1];
        c1_b_Y[0] = c1_Y_sizes[0];
        c1_b_Y[1] = 1;
        c1_c_Y[0] = c1_Y_sizes[0];
        c1_c_Y[1] = 1;
        c1_tmp_sizes[0] = c1_b_Y[0];
        c1_tmp_sizes[1] = c1_b_Y[1];
        c1_Y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1, c1_Y_sizes[0], 1, 0)
          - 1] = c1_Y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ip, 1, c1_Y_sizes
          [0], 1, 0) - 1];
        c1_d_Y[0] = c1_Y_sizes[0];
        c1_d_Y[1] = 1;
        c1_b_tmp_sizes[0] = c1_d_Y[0];
        c1_b_tmp_sizes[1] = c1_d_Y[1];
        c1_Y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ip, 1, c1_Y_sizes[0], 1, 0)
          - 1] = c1_temp;
      }
    }

    c1_c_A_sizes[0] = 3;
    c1_c_A_sizes[1] = 3;
    c1_c_A = c1_c_A_sizes[0];
    c1_d_A = c1_c_A_sizes[1];
    c1_c_loop_ub = c1_b_A_sizes[0] * c1_b_A_sizes[1] - 1;
    for (c1_i116 = 0; c1_i116 <= c1_c_loop_ub; c1_i116++) {
      c1_c_A_data[c1_i116] = c1_b_A_data[c1_i116];
    }

    c1_c_eml_xtrsm(chartInstance, c1_c_A_data, c1_c_A_sizes, c1_Y_data,
                   c1_Y_sizes);
    c1_d_A_sizes[0] = 3;
    c1_d_A_sizes[1] = 3;
    c1_e_A = c1_d_A_sizes[0];
    c1_f_A = c1_d_A_sizes[1];
    c1_d_loop_ub = c1_b_A_sizes[0] * c1_b_A_sizes[1] - 1;
    for (c1_i117 = 0; c1_i117 <= c1_d_loop_ub; c1_i117++) {
      c1_d_A_data[c1_i117] = c1_b_A_data[c1_i117];
    }

    c1_d_eml_xtrsm(chartInstance, c1_d_A_data, c1_d_A_sizes, c1_Y_data,
                   c1_Y_sizes);
  } else {
    c1_e_A_sizes[0] = c1_A_sizes[0];
    c1_e_A_sizes[1] = 3;
    c1_g_A = c1_e_A_sizes[0];
    c1_h_A = c1_e_A_sizes[1];
    c1_e_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
    for (c1_i118 = 0; c1_i118 <= c1_e_loop_ub; c1_i118++) {
      c1_e_A_data[c1_i118] = c1_A_data[c1_i118];
    }

    c1_b_B_sizes = c1_B_sizes[0];
    c1_f_loop_ub = c1_B_sizes[0] - 1;
    for (c1_i119 = 0; c1_i119 <= c1_f_loop_ub; c1_i119++) {
      c1_b_B_data[c1_i119] = c1_B_data[c1_i119];
    }

    c1_eml_qrsolve(chartInstance, c1_e_A_data, c1_e_A_sizes, c1_b_B_data,
                   *(int32_T (*)[1])&c1_b_B_sizes, c1_dv7);
    c1_Y_sizes[0] = 3;
    for (c1_i120 = 0; c1_i120 < 3; c1_i120++) {
      c1_Y_data[c1_i120] = c1_dv7[c1_i120];
    }
  }

  if (guard1 == TRUE) {
    c1_c_eml_scalar_eg(chartInstance);
    for (c1_i112 = 0; c1_i112 < 3; c1_i112++) {
      c1_dv7[c1_i112] = 0.0;
    }

    c1_Y_sizes[0] = 3;
    for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
      c1_Y_data[c1_i113] = c1_dv7[c1_i113];
    }
  }
}

static void c1_c_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static void c1_realmin(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void c1_eps(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance)
{
}

static void c1_d_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static void c1_eml_matlab_zgetrf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T
  c1_b_A_data[9], int32_T c1_b_A_sizes[2], int32_T c1_ipiv[3], int32_T *c1_info)
{
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i121;
  c1_b_A_sizes[0] = 3;
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i121 = 0; c1_i121 <= c1_loop_ub; c1_i121++) {
    c1_b_A_data[c1_i121] = c1_A_data[c1_i121];
  }

  c1_b_eml_matlab_zgetrf(chartInstance, c1_b_A_data, c1_b_A_sizes, c1_ipiv,
    c1_info);
}

static int32_T c1_eml_ixamax(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[9], int32_T c1_x_sizes[2],
  int32_T c1_ix0)
{
  int32_T c1_idxmax;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  double * c1_xix0_t;
  ptrdiff_t c1_idxmax_t;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  if (c1_b_n < 1) {
    c1_idxmax = 0;
  } else {
    c1_c_n = c1_b_n;
    c1_c_ix0 = c1_b_ix0;
    c1_var = c1_c_n;
    c1_n_t = (ptrdiff_t)(c1_var);
    c1_incx_t = (ptrdiff_t)(1);
    c1_xix0_t = (double *)(&c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0,
      1, 9, 1, 0) - 1]);
    c1_idxmax_t = idamax(&c1_n_t, c1_xix0_t, &c1_incx_t);
    c1_idxmax = (int32_T)(c1_idxmax_t);
  }

  return c1_idxmax;
}

static void c1_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_iy0, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ia0,
  real_T c1_b_A_data[9], int32_T c1_b_A_sizes[2])
{
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i122;
  c1_b_A_sizes[0] = 3;
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i122 = 0; c1_i122 <= c1_loop_ub; c1_i122++) {
    c1_b_A_data[c1_i122] = c1_A_data[c1_i122];
  }

  c1_c_eml_xger(chartInstance, c1_m, c1_n, c1_alpha1, c1_ix0, c1_iy0,
                c1_b_A_data, c1_b_A_sizes, c1_ia0);
}

static void c1_eml_warning(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
  int32_T c1_i123;
  static char_T c1_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  for (c1_i123 = 0; c1_i123 < 27; c1_i123++) {
    c1_u[c1_i123] = c1_varargin_1[c1_i123];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c1_y));
}

static void c1_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_b_B_data[10], int32_T c1_b_B_sizes[1])
{
  int32_T c1_loop_ub;
  int32_T c1_i124;
  int32_T c1_b_A_sizes[2];
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_b_loop_ub;
  int32_T c1_i125;
  real_T c1_b_A_data[9];
  c1_b_B_sizes[0] = c1_B_sizes[0];
  c1_loop_ub = c1_B_sizes[0] - 1;
  for (c1_i124 = 0; c1_i124 <= c1_loop_ub; c1_i124++) {
    c1_b_B_data[c1_i124] = c1_B_data[c1_i124];
  }

  c1_b_A_sizes[0] = 3;
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_b_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i125 = 0; c1_i125 <= c1_b_loop_ub; c1_i125++) {
    c1_b_A_data[c1_i125] = c1_A_data[c1_i125];
  }

  c1_c_eml_xtrsm(chartInstance, c1_b_A_data, c1_b_A_sizes, c1_b_B_data,
                 c1_b_B_sizes);
}

static void c1_below_threshold(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static void c1_e_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static void c1_b_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_b_B_data[10], int32_T c1_b_B_sizes[1])
{
  int32_T c1_loop_ub;
  int32_T c1_i126;
  int32_T c1_b_A_sizes[2];
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_b_loop_ub;
  int32_T c1_i127;
  real_T c1_b_A_data[9];
  c1_b_B_sizes[0] = c1_B_sizes[0];
  c1_loop_ub = c1_B_sizes[0] - 1;
  for (c1_i126 = 0; c1_i126 <= c1_loop_ub; c1_i126++) {
    c1_b_B_data[c1_i126] = c1_B_data[c1_i126];
  }

  c1_b_A_sizes[0] = 3;
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_b_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i127 = 0; c1_i127 <= c1_b_loop_ub; c1_i127++) {
    c1_b_A_data[c1_i127] = c1_A_data[c1_i127];
  }

  c1_d_eml_xtrsm(chartInstance, c1_b_A_data, c1_b_A_sizes, c1_b_B_data,
                 c1_b_B_sizes);
}

static void c1_eml_qrsolve(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[30], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1], real_T c1_Y[3])
{
  real_T c1_m;
  real_T c1_varargin_1;
  real_T c1_varargin_2;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_xk;
  real_T c1_c_x;
  real_T c1_mn;
  int32_T c1_b_m;
  int32_T c1_b_varargin_1;
  int32_T c1_b_varargin_2;
  int32_T c1_d_x;
  int32_T c1_e_x;
  int32_T c1_b_xk;
  int32_T c1_f_x;
  int32_T c1_b_mn;
  int32_T c1_iv4[2];
  int32_T c1_tmp_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i128;
  real_T c1_tmp_data[3];
  int32_T c1_tau_sizes;
  int32_T c1_i129;
  int32_T c1_jpvt[3];
  boolean_T c1_b28;
  int32_T c1_i130;
  real_T c1_work[3];
  int32_T c1_k;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_b_A_sizes[2];
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_b_loop_ub;
  int32_T c1_i131;
  real_T c1_b_A_data[30];
  real_T c1_vn1[3];
  real_T c1_vn2[3];
  int32_T c1_a;
  int32_T c1_b;
  int32_T c1_c_mn;
  int32_T c1_b_b;
  int32_T c1_c_b;
  boolean_T c1_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_b_a;
  int32_T c1_im1;
  int32_T c1_c_a;
  int32_T c1_ip1;
  int32_T c1_d_a;
  int32_T c1_d_b;
  int32_T c1_c;
  int32_T c1_e_a;
  int32_T c1_e_b;
  int32_T c1_i_i;
  int32_T c1_f_b;
  int32_T c1_nmi;
  int32_T c1_f_a;
  int32_T c1_g_b;
  int32_T c1_mmi;
  int32_T c1_h_b;
  int32_T c1_mmip1;
  int32_T c1_i_b;
  int32_T c1_nmip1;
  int32_T c1_g_a;
  int32_T c1_i132;
  real_T c1_b_vn1[3];
  int32_T c1_j_b;
  int32_T c1_pvt;
  int32_T c1_h_a;
  int32_T c1_b_c;
  int32_T c1_i_a;
  int32_T c1_k_b;
  int32_T c1_c_c;
  int32_T c1_l_b;
  int32_T c1_pvtcol;
  int32_T c1_j_a;
  int32_T c1_m_b;
  int32_T c1_d_c;
  int32_T c1_n_b;
  int32_T c1_mcol;
  int32_T c1_itemp;
  real_T c1_atmp;
  int32_T c1_k_a;
  int32_T c1_e_c;
  real_T c1_b_atmp;
  real_T c1_d4;
  real_T c1_tau_data[3];
  real_T c1_c_atmp;
  real_T c1_d5;
  real_T c1_d6;
  int32_T c1_l_a;
  int32_T c1_o_b;
  int32_T c1_f_c;
  int32_T c1_m_a;
  int32_T c1_p_b;
  int32_T c1_i_ip1;
  int32_T c1_b_ip1;
  int32_T c1_c_j;
  int32_T c1_n_a;
  int32_T c1_g_c;
  int32_T c1_o_a;
  int32_T c1_q_b;
  int32_T c1_h_c;
  int32_T c1_p_a;
  int32_T c1_r_b;
  int32_T c1_i_j;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_y;
  real_T c1_temp1;
  real_T c1_q_a;
  real_T c1_s_b;
  real_T c1_b_y;
  real_T c1_temp2;
  real_T c1_r_a;
  real_T c1_t_b;
  real_T c1_c_y;
  real_T c1_s_a;
  real_T c1_u_b;
  int32_T c1_t_a;
  int32_T c1_i_c;
  int32_T c1_n;
  int32_T c1_ix0;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  real_T c1_d_y;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  double * c1_xix0_t;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_u_a;
  real_T c1_v_b;
  real_T c1_e_y;
  real_T c1_rankR;
  real_T c1_c_varargin_1;
  real_T c1_c_varargin_2;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_c_xk;
  real_T c1_m_x;
  real_T c1_maxval;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_f_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_g_y;
  real_T c1_d;
  real_T c1_v_a;
  real_T c1_w_b;
  real_T c1_h_y;
  real_T c1_w_a;
  real_T c1_tol;
  real_T c1_d_mn;
  int32_T c1_i133;
  int32_T c1_b_k;
  real_T c1_c_k;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_i_y;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_j_y;
  real_T c1_b_d;
  real_T c1_x_x;
  int32_T c1_i134;
  static char_T c1_cv7[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c1_u[8];
  const mxArray *c1_k_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_m_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_n_y = NULL;
  char_T c1_str[14];
  int32_T c1_i135;
  char_T c1_b_str[14];
  int32_T c1_i136;
  real_T c1_e_mn;
  int32_T c1_i137;
  int32_T c1_d_j;
  real_T c1_e_j;
  real_T c1_tauj;
  int32_T c1_B[2];
  real_T c1_wj;
  real_T c1_d7;
  real_T c1_c_m;
  int32_T c1_i138;
  int32_T c1_c_i;
  real_T c1_d_i;
  real_T c1_x_a;
  int32_T c1_b_B[2];
  real_T c1_x_b;
  real_T c1_z;
  real_T c1_y_a;
  real_T c1_y_b;
  int32_T c1_c_B[2];
  int32_T c1_d_B[2];
  int32_T c1_b_tmp_sizes[2];
  real_T c1_d8;
  real_T c1_d_m;
  int32_T c1_i139;
  int32_T c1_e_i;
  real_T c1_ab_a;
  real_T c1_ab_b;
  real_T c1_o_y;
  int32_T c1_e_B[2];
  int32_T c1_f_B[2];
  int32_T c1_c_tmp_sizes[2];
  real_T c1_rr;
  real_T c1_b_rr;
  int32_T c1_i140;
  int32_T c1_f_i;
  int32_T c1_g_B[2];
  real_T c1_c_rr;
  int32_T c1_i141;
  int32_T c1_f_j;
  int32_T c1_pj;
  real_T c1_y_x;
  real_T c1_p_y;
  real_T c1_b_z;
  real_T c1_d9;
  int32_T c1_i142;
  int32_T c1_g_i;
  real_T c1_bb_a;
  real_T c1_bb_b;
  real_T c1_q_y;
  boolean_T exitg1;
  c1_m = (real_T)c1_A_sizes[0];
  c1_varargin_1 = c1_m;
  c1_varargin_2 = c1_varargin_1;
  c1_x = c1_varargin_2;
  c1_b_x = c1_x;
  c1_b_eml_scalar_eg(chartInstance);
  c1_xk = c1_b_x;
  c1_c_x = c1_xk;
  c1_b_eml_scalar_eg(chartInstance);
  c1_mn = muDoubleScalarMin(c1_c_x, 3.0);
  c1_b_m = (int32_T)(real_T)c1_A_sizes[0];
  c1_b_varargin_1 = c1_b_m;
  c1_b_varargin_2 = c1_b_varargin_1;
  c1_d_x = c1_b_varargin_2;
  c1_e_x = c1_d_x;
  c1_d_eml_scalar_eg(chartInstance);
  c1_b_xk = c1_e_x;
  c1_f_x = c1_b_xk;
  c1_d_eml_scalar_eg(chartInstance);
  c1_b_mn = muIntScalarMin_sint32(c1_f_x, 3);
  c1_f_eml_scalar_eg(chartInstance);
  c1_iv4[0] = c1_b_mn;
  c1_iv4[1] = 1;
  c1_tmp_sizes = c1_iv4[0];
  c1_loop_ub = c1_iv4[0] - 1;
  for (c1_i128 = 0; c1_i128 <= c1_loop_ub; c1_i128++) {
    c1_tmp_data[c1_i128] = 0.0;
  }

  c1_tau_sizes = c1_tmp_sizes;
  for (c1_i129 = 0; c1_i129 < 3; c1_i129++) {
    c1_jpvt[c1_i129] = 1 + c1_i129;
  }

  c1_b28 = (c1_A_sizes[0] == 0);
  if (c1_b28) {
  } else {
    c1_f_eml_scalar_eg(chartInstance);
    for (c1_i130 = 0; c1_i130 < 3; c1_i130++) {
      c1_work[c1_i130] = 0.0;
    }

    c1_eps(chartInstance);
    c1_sqrt(chartInstance, 2.2204460492503131E-16);
    c1_f_eml_scalar_eg(chartInstance);
    c1_k = 1;
    for (c1_j = 1; c1_j < 4; c1_j++) {
      c1_b_j = c1_j - 1;
      c1_b_A_sizes[0] = c1_A_sizes[0];
      c1_b_A_sizes[1] = 3;
      c1_A = c1_b_A_sizes[0];
      c1_b_A = c1_b_A_sizes[1];
      c1_b_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
      for (c1_i131 = 0; c1_i131 <= c1_b_loop_ub; c1_i131++) {
        c1_b_A_data[c1_i131] = c1_A_data[c1_i131];
      }

      c1_vn1[c1_b_j] = c1_eml_xnrm2(chartInstance, c1_b_m, c1_b_A_data,
        c1_b_A_sizes, c1_k);
      c1_vn2[c1_b_j] = c1_vn1[c1_b_j];
      c1_a = c1_k;
      c1_b = c1_b_m;
      c1_k = c1_a + c1_b;
    }

    c1_c_mn = c1_b_mn;
    c1_b_b = c1_c_mn;
    c1_c_b = c1_b_b;
    if (1 > c1_c_b) {
      c1_overflow = FALSE;
    } else {
      c1_overflow = (c1_c_b > 2147483646);
    }

    if (c1_overflow) {
      c1_b_check_forloop_overflow_error(chartInstance, TRUE);
    }

    for (c1_i = 1; c1_i <= c1_c_mn; c1_i++) {
      c1_b_i = c1_i;
      c1_b_a = c1_b_i - 1;
      c1_im1 = c1_b_a;
      c1_c_a = c1_b_i;
      c1_ip1 = c1_c_a;
      c1_d_a = c1_im1;
      c1_d_b = c1_b_m;
      c1_c = c1_d_a * c1_d_b;
      c1_e_a = c1_b_i;
      c1_e_b = c1_c;
      c1_i_i = c1_e_a + c1_e_b;
      c1_f_b = c1_b_i;
      c1_nmi = 3 - c1_f_b;
      c1_f_a = c1_b_m;
      c1_g_b = c1_b_i;
      c1_mmi = c1_f_a - c1_g_b;
      c1_h_b = c1_mmi + 1;
      c1_mmip1 = c1_h_b;
      c1_i_b = c1_nmi;
      c1_nmip1 = c1_i_b;
      c1_g_a = c1_im1;
      for (c1_i132 = 0; c1_i132 < 3; c1_i132++) {
        c1_b_vn1[c1_i132] = c1_vn1[c1_i132];
      }

      c1_j_b = c1_b_eml_ixamax(chartInstance, c1_nmip1 + 1, c1_b_vn1, c1_b_i);
      c1_pvt = c1_g_a + c1_j_b;
      if (c1_pvt != c1_b_i) {
        c1_h_a = c1_pvt;
        c1_b_c = c1_h_a;
        c1_i_a = c1_b_m;
        c1_k_b = c1_b_c - 1;
        c1_c_c = c1_i_a * c1_k_b;
        c1_l_b = c1_c_c;
        c1_pvtcol = c1_l_b;
        c1_j_a = c1_b_m;
        c1_m_b = c1_im1;
        c1_d_c = c1_j_a * c1_m_b;
        c1_n_b = c1_d_c;
        c1_mcol = c1_n_b;
        c1_b_eml_xswap(chartInstance, c1_b_m, c1_A_data, c1_A_sizes, c1_pvtcol +
                       1, c1_mcol + 1);
        c1_itemp = c1_jpvt[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_pvt, 1, 3, 1, 0) -
          1];
        c1_jpvt[c1_pvt - 1] = c1_jpvt[c1_b_i - 1];
        c1_jpvt[c1_b_i - 1] = c1_itemp;
        c1_vn1[c1_pvt - 1] = c1_vn1[c1_b_i - 1];
        c1_vn2[c1_pvt - 1] = c1_vn2[c1_b_i - 1];
      }

      c1_atmp = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes
        [0] * 3, 1, 0) - 1];
      if (c1_b_i < c1_b_m) {
        c1_k_a = c1_i_i;
        c1_e_c = c1_k_a;
        c1_b_atmp = c1_atmp;
        c1_d4 = c1_c_eml_matlab_zlarfg(chartInstance, c1_mmip1, &c1_b_atmp,
          c1_A_data, c1_A_sizes, c1_e_c + 1);
        c1_atmp = c1_b_atmp;
        c1_tau_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1, c1_tau_sizes, 1,
          0) - 1] = c1_d4;
      } else {
        c1_c_atmp = c1_atmp;
        c1_d5 = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes
          [0] * 3, 1, 0) - 1];
        c1_d6 = c1_d_eml_matlab_zlarfg(chartInstance, &c1_c_atmp, &c1_d5);
        c1_atmp = c1_c_atmp;
        c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes[0] * 3,
          1, 0) - 1] = c1_d5;
        c1_tau_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1, c1_tau_sizes, 1,
          0) - 1] = c1_d6;
      }

      c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes[0] * 3, 1,
        0) - 1] = c1_atmp;
      if (c1_b_i < 3) {
        c1_atmp = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1,
          c1_A_sizes[0] * 3, 1, 0) - 1];
        c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes[0] * 3,
          1, 0) - 1] = 1.0;
        c1_l_a = c1_b_i;
        c1_o_b = c1_b_m;
        c1_f_c = c1_l_a * c1_o_b;
        c1_m_a = c1_b_i;
        c1_p_b = c1_f_c;
        c1_i_ip1 = c1_m_a + c1_p_b;
        c1_b_eml_matlab_zlarf(chartInstance, c1_mmip1, c1_nmi, c1_i_i,
                              c1_tau_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i,
          1, c1_tau_sizes, 1, 0) - 1], c1_A_data, c1_A_sizes, c1_i_ip1, c1_b_m,
                              c1_work);
        c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_i, 1, c1_A_sizes[0] * 3,
          1, 0) - 1] = c1_atmp;
      }

      c1_b_ip1 = c1_ip1 + 1;
      for (c1_c_j = c1_b_ip1; c1_c_j < 4; c1_c_j++) {
        c1_b_j = c1_c_j - 1;
        c1_n_a = c1_b_j + 1;
        c1_g_c = c1_n_a;
        c1_o_a = c1_b_m;
        c1_q_b = c1_g_c - 1;
        c1_h_c = c1_o_a * c1_q_b;
        c1_p_a = c1_b_i;
        c1_r_b = c1_h_c;
        c1_i_j = c1_p_a + c1_r_b;
        if (c1_vn1[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_j + 1, 1, 3, 1, 0) - 1]
            != 0.0) {
          c1_g_x = c1_A_data[(_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1,
            c1_A_sizes[0], 1, 0) + c1_A_sizes[0] * c1_b_j) - 1];
          c1_h_x = c1_g_x;
          c1_y = muDoubleScalarAbs(c1_h_x);
          c1_temp1 = c1_y / c1_vn1[c1_b_j];
          c1_q_a = c1_temp1;
          c1_s_b = c1_temp1;
          c1_b_y = c1_q_a * c1_s_b;
          c1_temp1 = 1.0 - c1_b_y;
          if (c1_temp1 < 0.0) {
            c1_temp1 = 0.0;
          }

          c1_temp2 = c1_vn1[c1_b_j] / c1_vn2[c1_b_j];
          c1_r_a = c1_temp2;
          c1_t_b = c1_temp2;
          c1_c_y = c1_r_a * c1_t_b;
          c1_s_a = c1_temp1;
          c1_u_b = c1_c_y;
          c1_temp2 = c1_s_a * c1_u_b;
          if (c1_temp2 <= 1.4901161193847656E-8) {
            if (c1_b_i < c1_b_m) {
              c1_t_a = c1_i_j;
              c1_i_c = c1_t_a;
              c1_n = c1_mmi;
              c1_ix0 = c1_i_c + 1;
              c1_b_n = c1_n;
              c1_b_ix0 = c1_ix0;
              if (c1_b_n < 1) {
                c1_d_y = 0.0;
              } else {
                c1_c_n = c1_b_n;
                c1_c_ix0 = c1_b_ix0;
                c1_var = c1_c_n;
                c1_n_t = (ptrdiff_t)(c1_var);
                c1_incx_t = (ptrdiff_t)(1);
                c1_xix0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                  c1_c_ix0, 1, c1_A_sizes[0] * 3, 1, 0) - 1]);
                c1_d_y = dnrm2(&c1_n_t, c1_xix0_t, &c1_incx_t);
              }

              c1_vn1[c1_b_j] = c1_d_y;
              c1_vn2[c1_b_j] = c1_vn1[c1_b_j];
            } else {
              c1_vn1[c1_b_j] = 0.0;
              c1_vn2[c1_b_j] = 0.0;
            }
          } else {
            c1_i_x = c1_temp1;
            c1_j_x = c1_i_x;
            if (c1_j_x < 0.0) {
              c1_eml_error(chartInstance);
            }

            c1_j_x = muDoubleScalarSqrt(c1_j_x);
            c1_u_a = c1_vn1[c1_b_j];
            c1_v_b = c1_j_x;
            c1_e_y = c1_u_a * c1_v_b;
            c1_vn1[c1_b_j] = c1_e_y;
          }
        }
      }
    }
  }

  c1_rankR = 0.0;
  if (c1_mn > 0.0) {
    c1_eps(chartInstance);
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c1_A_sizes[0], 1, 0);
    c1_c_varargin_1 = c1_m;
    c1_c_varargin_2 = c1_c_varargin_1;
    c1_k_x = c1_c_varargin_2;
    c1_l_x = c1_k_x;
    c1_b_eml_scalar_eg(chartInstance);
    c1_c_xk = c1_l_x;
    c1_m_x = c1_c_xk;
    c1_b_eml_scalar_eg(chartInstance);
    c1_maxval = muDoubleScalarMax(c1_m_x, 3.0);
    c1_n_x = c1_A_data[0];
    c1_o_x = c1_n_x;
    c1_p_x = c1_o_x;
    c1_f_y = muDoubleScalarAbs(c1_p_x);
    c1_q_x = 0.0;
    c1_r_x = c1_q_x;
    c1_g_y = muDoubleScalarAbs(c1_r_x);
    c1_d = c1_f_y + c1_g_y;
    c1_v_a = c1_maxval;
    c1_w_b = c1_d;
    c1_h_y = c1_v_a * c1_w_b;
    c1_w_a = c1_h_y;
    c1_tol = c1_w_a * 2.2204460492503131E-16;
    c1_d_mn = c1_mn;
    c1_i133 = (int32_T)c1_d_mn - 1;
    c1_b_k = 0;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c1_b_k <= c1_i133)) {
      c1_c_k = 1.0 + (real_T)c1_b_k;
      c1_s_x = c1_A_data[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c1_c_k, 1, c1_A_sizes[0], 1, 0) + c1_A_sizes[0] * ((int32_T)
        c1_c_k - 1)) - 1];
      c1_t_x = c1_s_x;
      c1_u_x = c1_t_x;
      c1_i_y = muDoubleScalarAbs(c1_u_x);
      c1_v_x = 0.0;
      c1_w_x = c1_v_x;
      c1_j_y = muDoubleScalarAbs(c1_w_x);
      c1_b_d = c1_i_y + c1_j_y;
      if (c1_b_d <= c1_tol) {
        c1_x_x = c1_tol;
        for (c1_i134 = 0; c1_i134 < 8; c1_i134++) {
          c1_u[c1_i134] = c1_cv7[c1_i134];
        }

        c1_k_y = NULL;
        sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 8),
                      FALSE);
        c1_b_u = 14.0;
        c1_l_y = NULL;
        sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        c1_c_u = 6.0;
        c1_m_y = NULL;
        sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        c1_d_u = c1_x_x;
        c1_n_y = NULL;
        sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        c1_j_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
          14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c1_k_y, 14, c1_l_y, 14,
          c1_m_y), 14, c1_n_y), "sprintf", c1_str);
        for (c1_i135 = 0; c1_i135 < 14; c1_i135++) {
          c1_b_str[c1_i135] = c1_str[c1_i135];
        }

        c1_b_eml_warning(chartInstance, c1_rankR, c1_b_str);
        exitg1 = TRUE;
      } else {
        c1_rankR++;
        c1_b_k++;
      }
    }
  }

  c1_c_eml_scalar_eg(chartInstance);
  for (c1_i136 = 0; c1_i136 < 3; c1_i136++) {
    c1_Y[c1_i136] = 0.0;
  }

  c1_e_mn = c1_mn;
  c1_i137 = (int32_T)c1_e_mn - 1;
  for (c1_d_j = 0; c1_d_j <= c1_i137; c1_d_j++) {
    c1_e_j = 1.0 + (real_T)c1_d_j;
    c1_tauj = c1_tau_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)c1_e_j, 1, c1_tau_sizes, 1, 0) - 1];
    if (c1_tauj != 0.0) {
      c1_B[0] = c1_B_sizes[0];
      c1_B[1] = 1;
      c1_wj = c1_B_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c1_e_j, 1, c1_B_sizes[0], 1, 0) - 1];
      c1_d7 = c1_e_j + 1.0;
      c1_c_m = c1_m;
      c1_i138 = (int32_T)(c1_c_m + (1.0 - c1_d7)) - 1;
      for (c1_c_i = 0; c1_c_i <= c1_i138; c1_c_i++) {
        c1_d_i = c1_d7 + (real_T)c1_c_i;
        c1_x_a = c1_A_data[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)c1_d_i, 1, c1_A_sizes[0], 1, 0) + c1_A_sizes[0] * ((int32_T)
          c1_e_j - 1)) - 1];
        c1_b_B[0] = c1_B_sizes[0];
        c1_b_B[1] = 1;
        c1_x_b = c1_B_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)c1_d_i, 1, c1_B_sizes[0], 1, 0) - 1];
        c1_z = c1_x_a * c1_x_b;
        c1_wj += c1_z;
      }

      c1_y_a = c1_tauj;
      c1_y_b = c1_wj;
      c1_wj = c1_y_a * c1_y_b;
      if (c1_wj != 0.0) {
        c1_c_B[0] = c1_B_sizes[0];
        c1_c_B[1] = 1;
        c1_d_B[0] = c1_B_sizes[0];
        c1_d_B[1] = 1;
        c1_b_tmp_sizes[0] = c1_c_B[0];
        c1_b_tmp_sizes[1] = c1_c_B[1];
        c1_B_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          c1_e_j, 1, c1_B_sizes[0], 1, 0) - 1] = c1_B_data[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_e_j, 1, c1_B_sizes[0], 1,
          0) - 1] - c1_wj;
        c1_d8 = c1_e_j + 1.0;
        c1_d_m = c1_m;
        c1_i139 = (int32_T)(c1_d_m + (1.0 - c1_d8)) - 1;
        for (c1_e_i = 0; c1_e_i <= c1_i139; c1_e_i++) {
          c1_d_i = c1_d8 + (real_T)c1_e_i;
          c1_ab_a = c1_A_data[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
                                (int32_T)c1_d_i, 1, c1_A_sizes[0], 1, 0) +
                               c1_A_sizes[0] * ((int32_T)c1_e_j - 1)) - 1];
          c1_ab_b = c1_wj;
          c1_o_y = c1_ab_a * c1_ab_b;
          c1_e_B[0] = c1_B_sizes[0];
          c1_e_B[1] = 1;
          c1_f_B[0] = c1_B_sizes[0];
          c1_f_B[1] = 1;
          c1_c_tmp_sizes[0] = c1_e_B[0];
          c1_c_tmp_sizes[1] = c1_e_B[1];
          c1_B_data[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            c1_d_i, 1, c1_B_sizes[0], 1, 0) - 1] = c1_B_data[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_d_i, 1, c1_B_sizes[0], 1,
            0) - 1] - c1_o_y;
        }
      }
    }
  }

  c1_rr = c1_rankR;
  c1_b_rr = c1_rr;
  c1_i140 = (int32_T)c1_b_rr;
  _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_b_rr, mxDOUBLE_CLASS, c1_i140);
  for (c1_f_i = 0; c1_f_i < c1_i140; c1_f_i++) {
    c1_d_i = 1.0 + (real_T)c1_f_i;
    c1_g_B[0] = c1_B_sizes[0];
    c1_g_B[1] = 1;
    c1_Y[c1_jpvt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      c1_d_i, 1, 3, 1, 0) - 1] - 1] = c1_B_data[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c1_d_i, 1, c1_B_sizes[0], 1, 0) -
      1];
  }

  c1_c_rr = c1_rr;
  c1_i141 = (int32_T)-(1.0 + (-1.0 - c1_c_rr));
  _SFD_FOR_LOOP_VECTOR_CHECK(c1_c_rr, -1.0, 1.0, mxDOUBLE_CLASS, c1_i141);
  for (c1_f_j = 0; c1_f_j < c1_i141; c1_f_j++) {
    c1_e_j = c1_c_rr + -(real_T)c1_f_j;
    c1_pj = c1_jpvt[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      c1_e_j, 1, 3, 1, 0) - 1] - 1;
    c1_y_x = c1_Y[c1_pj];
    c1_p_y = c1_A_data[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)c1_e_j, 1, c1_A_sizes[0], 1, 0) + c1_A_sizes[0] * ((int32_T)
      c1_e_j - 1)) - 1];
    c1_b_z = c1_y_x / c1_p_y;
    c1_Y[c1_pj] = c1_b_z;
    c1_d9 = c1_e_j - 1.0;
    c1_i142 = (int32_T)c1_d9 - 1;
    for (c1_g_i = 0; c1_g_i <= c1_i142; c1_g_i++) {
      c1_d_i = 1.0 + (real_T)c1_g_i;
      c1_bb_a = c1_Y[c1_pj];
      c1_bb_b = c1_A_data[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c1_d_i, 1, c1_A_sizes[0], 1, 0) + c1_A_sizes[0] * ((int32_T)
        c1_e_j - 1)) - 1];
      c1_q_y = c1_bb_a * c1_bb_b;
      c1_Y[c1_jpvt[(int32_T)c1_d_i - 1] - 1] -= c1_q_y;
    }
  }
}

static void c1_f_eml_scalar_eg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static real_T c1_sqrt(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_error(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
  int32_T c1_i143;
  static char_T c1_cv8[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i144;
  static char_T c1_cv9[4] = { 's', 'q', 'r', 't' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  for (c1_i143 = 0; c1_i143 < 30; c1_i143++) {
    c1_u[c1_i143] = c1_cv8[c1_i143];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c1_i144 = 0; c1_i144 < 4; c1_i144++) {
    c1_b_u[c1_i144] = c1_cv9[c1_i144];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static real_T c1_eml_xnrm2(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0)
{
  real_T c1_y;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  double * c1_xix0_t;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  if (c1_b_n < 1) {
    c1_y = 0.0;
  } else {
    c1_c_n = c1_b_n;
    c1_c_ix0 = c1_b_ix0;
    c1_var = c1_c_n;
    c1_n_t = (ptrdiff_t)(c1_var);
    c1_incx_t = (ptrdiff_t)(1);
    c1_xix0_t = (double *)(&c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0,
      1, c1_x_sizes[0] * 3, 1, 0) - 1]);
    c1_y = dnrm2(&c1_n_t, c1_xix0_t, &c1_incx_t);
  }

  return c1_y;
}

static int32_T c1_b_eml_ixamax(SFc1_DrogueVisualNavigation3InstanceStruct
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

static void c1_eml_xswap(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0, int32_T c1_iy0, real_T c1_b_x_data[30], int32_T c1_b_x_sizes[2])
{
  int32_T c1_x;
  int32_T c1_b_x;
  int32_T c1_loop_ub;
  int32_T c1_i145;
  c1_b_x_sizes[0] = c1_x_sizes[0];
  c1_b_x_sizes[1] = 3;
  c1_x = c1_b_x_sizes[0];
  c1_b_x = c1_b_x_sizes[1];
  c1_loop_ub = c1_x_sizes[0] * c1_x_sizes[1] - 1;
  for (c1_i145 = 0; c1_i145 <= c1_loop_ub; c1_i145++) {
    c1_b_x_data[c1_i145] = c1_x_data[c1_i145];
  }

  c1_b_eml_xswap(chartInstance, c1_n, c1_b_x_data, c1_b_x_sizes, c1_ix0, c1_iy0);
}

static void c1_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_alpha1, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T *c1_b_alpha1, real_T c1_b_x_data[30],
  int32_T c1_b_x_sizes[2], real_T *c1_tau)
{
  int32_T c1_x;
  int32_T c1_b_x;
  int32_T c1_loop_ub;
  int32_T c1_i146;
  *c1_b_alpha1 = c1_alpha1;
  c1_b_x_sizes[0] = c1_x_sizes[0];
  c1_b_x_sizes[1] = 3;
  c1_x = c1_b_x_sizes[0];
  c1_b_x = c1_b_x_sizes[1];
  c1_loop_ub = c1_x_sizes[0] * c1_x_sizes[1] - 1;
  for (c1_i146 = 0; c1_i146 <= c1_loop_ub; c1_i146++) {
    c1_b_x_data[c1_i146] = c1_x_data[c1_i146];
  }

  *c1_tau = c1_c_eml_matlab_zlarfg(chartInstance, c1_n, c1_b_alpha1, c1_b_x_data,
    c1_b_x_sizes, c1_ix0);
}

static void c1_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_b_x_data[30], int32_T c1_b_x_sizes[2])
{
  int32_T c1_x;
  int32_T c1_b_x;
  int32_T c1_loop_ub;
  int32_T c1_i147;
  c1_b_x_sizes[0] = c1_x_sizes[0];
  c1_b_x_sizes[1] = 3;
  c1_x = c1_b_x_sizes[0];
  c1_b_x = c1_b_x_sizes[1];
  c1_loop_ub = c1_x_sizes[0] * c1_x_sizes[1] - 1;
  for (c1_i147 = 0; c1_i147 <= c1_loop_ub; c1_i147++) {
    c1_b_x_data[c1_i147] = c1_x_data[c1_i147];
  }

  c1_c_eml_xscal(chartInstance, c1_n, c1_a, c1_b_x_data, c1_b_x_sizes, c1_ix0);
}

static void c1_b_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_x, real_T *c1_b_alpha1, real_T
  *c1_b_x, real_T *c1_tau)
{
  *c1_b_alpha1 = c1_alpha1;
  *c1_b_x = c1_x;
  *c1_tau = c1_d_eml_matlab_zlarfg(chartInstance, c1_b_alpha1, c1_b_x);
}

static void c1_b_eml_xnrm2(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance)
{
}

static real_T c1_b_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_d_eml_xscal(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_matlab_zlarf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C_data[30], int32_T c1_C_sizes[2], int32_T c1_ic0, int32_T c1_ldc,
  real_T c1_work[3], real_T c1_b_C_data[30], int32_T c1_b_C_sizes[2], real_T
  c1_b_work[3])
{
  int32_T c1_C;
  int32_T c1_b_C;
  int32_T c1_loop_ub;
  int32_T c1_i148;
  int32_T c1_i149;
  c1_b_C_sizes[0] = c1_C_sizes[0];
  c1_b_C_sizes[1] = 3;
  c1_C = c1_b_C_sizes[0];
  c1_b_C = c1_b_C_sizes[1];
  c1_loop_ub = c1_C_sizes[0] * c1_C_sizes[1] - 1;
  for (c1_i148 = 0; c1_i148 <= c1_loop_ub; c1_i148++) {
    c1_b_C_data[c1_i148] = c1_C_data[c1_i148];
  }

  for (c1_i149 = 0; c1_i149 < 3; c1_i149++) {
    c1_b_work[c1_i149] = c1_work[c1_i149];
  }

  c1_b_eml_matlab_zlarf(chartInstance, c1_m, c1_n, c1_iv0, c1_tau, c1_b_C_data,
                        c1_b_C_sizes, c1_ic0, c1_ldc, c1_b_work);
}

static void c1_eml_xgemv(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A_data[30], int32_T
  c1_A_sizes[2], int32_T c1_ia0, int32_T c1_lda, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_y[3], real_T c1_b_y[3])
{
  int32_T c1_i150;
  int32_T c1_b_A_sizes[2];
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i151;
  real_T c1_b_A_data[30];
  int32_T c1_b_x_sizes[2];
  int32_T c1_x;
  int32_T c1_b_x;
  int32_T c1_b_loop_ub;
  int32_T c1_i152;
  real_T c1_b_x_data[30];
  for (c1_i150 = 0; c1_i150 < 3; c1_i150++) {
    c1_b_y[c1_i150] = c1_y[c1_i150];
  }

  c1_b_A_sizes[0] = c1_A_sizes[0];
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i151 = 0; c1_i151 <= c1_loop_ub; c1_i151++) {
    c1_b_A_data[c1_i151] = c1_A_data[c1_i151];
  }

  c1_b_x_sizes[0] = c1_x_sizes[0];
  c1_b_x_sizes[1] = 3;
  c1_x = c1_b_x_sizes[0];
  c1_b_x = c1_b_x_sizes[1];
  c1_b_loop_ub = c1_x_sizes[0] * c1_x_sizes[1] - 1;
  for (c1_i152 = 0; c1_i152 <= c1_b_loop_ub; c1_i152++) {
    c1_b_x_data[c1_i152] = c1_x_data[c1_i152];
  }

  c1_b_eml_xgemv(chartInstance, c1_m, c1_n, c1_b_A_data, c1_b_A_sizes, c1_ia0,
                 c1_lda, c1_b_x_data, c1_b_x_sizes, c1_ix0, c1_b_y);
}

static void c1_b_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A_data[30], int32_T c1_A_sizes[2], int32_T c1_ia0,
  int32_T c1_lda, real_T c1_b_A_data[30], int32_T c1_b_A_sizes[2])
{
  int32_T c1_A;
  int32_T c1_b_A;
  int32_T c1_loop_ub;
  int32_T c1_i153;
  int32_T c1_i154;
  real_T c1_b_y[3];
  c1_b_A_sizes[0] = c1_A_sizes[0];
  c1_b_A_sizes[1] = 3;
  c1_A = c1_b_A_sizes[0];
  c1_b_A = c1_b_A_sizes[1];
  c1_loop_ub = c1_A_sizes[0] * c1_A_sizes[1] - 1;
  for (c1_i153 = 0; c1_i153 <= c1_loop_ub; c1_i153++) {
    c1_b_A_data[c1_i153] = c1_A_data[c1_i153];
  }

  for (c1_i154 = 0; c1_i154 < 3; c1_i154++) {
    c1_b_y[c1_i154] = c1_y[c1_i154];
  }

  c1_d_eml_xger(chartInstance, c1_m, c1_n, c1_alpha1, c1_ix0, c1_b_y,
                c1_b_A_data, c1_b_A_sizes, c1_ia0, c1_lda);
}

static void c1_b_eml_warning(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_varargin_2, char_T c1_varargin_3[14])
{
  int32_T c1_i155;
  static char_T c1_varargin_1[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i',
    'e', 'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c1_u[32];
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i156;
  char_T c1_c_u[14];
  const mxArray *c1_c_y = NULL;
  for (c1_i155 = 0; c1_i155 < 32; c1_i155++) {
    c1_u[c1_i155] = c1_varargin_1[c1_i155];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 32), FALSE);
  c1_b_u = c1_varargin_2;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  for (c1_i156 = 0; c1_i156 < 14; c1_i156++) {
    c1_c_u[c1_i156] = c1_varargin_3[c1_i156];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 3U,
    14, c1_y, 14, c1_b_y, 14, c1_c_y));
}

static real_T c1_mpower(SFc1_DrogueVisualNavigation3InstanceStruct
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

static void c1_j_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_sprintf, const char_T *c1_identifier, char_T
  c1_y[14])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sprintf), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_sprintf);
}

static void c1_k_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[14])
{
  char_T c1_cv10[14];
  int32_T c1_i157;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv10, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c1_i157 = 0; c1_i157 < 14; c1_i157++) {
    c1_y[c1_i157] = c1_cv10[c1_i157];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_l_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i158;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i158, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i158;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_m_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_b_is_active_c1_DrogueVisualNavigation3, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_DrogueVisualNavigation3), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_DrogueVisualNavigation3);
  return c1_y;
}

static uint8_T c1_n_emlrt_marshallIn(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_eml_matlab_zgetrf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ipiv[3],
  int32_T *c1_info)
{
  int32_T c1_i159;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_jm1;
  int32_T c1_b;
  int32_T c1_mmj;
  int32_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_jj;
  int32_T c1_c_a;
  int32_T c1_jp1j;
  int32_T c1_d_a;
  int32_T c1_b_c;
  int32_T c1_b_A_sizes[2];
  int32_T c1_i160;
  int32_T c1_i161;
  real_T c1_b_A_data[9];
  int32_T c1_e_a;
  int32_T c1_jpiv_offset;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_jpiv;
  int32_T c1_g_a;
  int32_T c1_d_b;
  int32_T c1_c_c;
  int32_T c1_e_b;
  int32_T c1_jrow;
  int32_T c1_h_a;
  int32_T c1_f_b;
  int32_T c1_jprow;
  int32_T c1_ix0;
  int32_T c1_iy0;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_k;
  real_T c1_temp;
  int32_T c1_i_a;
  int32_T c1_j_a;
  int32_T c1_b_jp1j;
  int32_T c1_k_a;
  int32_T c1_d_c;
  int32_T c1_l_a;
  int32_T c1_g_b;
  int32_T c1_i162;
  int32_T c1_m_a;
  int32_T c1_h_b;
  int32_T c1_n_a;
  int32_T c1_i_b;
  boolean_T c1_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_x;
  real_T c1_y;
  real_T c1_z;
  int32_T c1_j_b;
  int32_T c1_e_c;
  int32_T c1_o_a;
  int32_T c1_f_c;
  int32_T c1_p_a;
  int32_T c1_g_c;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_d_ix0;
  int32_T c1_d_iy0;
  int32_T c1_ia0;
  real_T c1_d10;
  c1_realmin(chartInstance);
  c1_eps(chartInstance);
  for (c1_i159 = 0; c1_i159 < 3; c1_i159++) {
    c1_ipiv[c1_i159] = 1 + c1_i159;
  }

  *c1_info = 0;
  for (c1_j = 1; c1_j < 3; c1_j++) {
    c1_b_j = c1_j;
    c1_a = c1_b_j - 1;
    c1_jm1 = c1_a;
    c1_b = c1_b_j;
    c1_mmj = 3 - c1_b;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a << 2;
    c1_b_b = c1_c + 1;
    c1_jj = c1_b_b;
    c1_c_a = c1_jj + 1;
    c1_jp1j = c1_c_a;
    c1_d_a = c1_mmj + 1;
    c1_b_c = c1_d_a;
    c1_b_A_sizes[0] = 3;
    c1_b_A_sizes[1] = 3;
    for (c1_i160 = 0; c1_i160 < 3; c1_i160++) {
      for (c1_i161 = 0; c1_i161 < 3; c1_i161++) {
        c1_b_A_data[c1_i161 + c1_b_A_sizes[0] * c1_i160] = c1_A_data[c1_i161 +
          c1_A_sizes[0] * c1_i160];
      }
    }

    c1_e_a = c1_eml_ixamax(chartInstance, c1_b_c, c1_b_A_data, c1_b_A_sizes,
      c1_jj) - 1;
    c1_jpiv_offset = c1_e_a;
    c1_f_a = c1_jj;
    c1_c_b = c1_jpiv_offset;
    c1_jpiv = c1_f_a + c1_c_b;
    if (c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_jpiv, 1, 9, 1, 0) - 1] !=
        0.0) {
      if (c1_jpiv_offset != 0) {
        c1_g_a = c1_b_j;
        c1_d_b = c1_jpiv_offset;
        c1_c_c = c1_g_a + c1_d_b;
        c1_ipiv[c1_b_j - 1] = c1_c_c;
        c1_e_b = c1_jm1 + 1;
        c1_jrow = c1_e_b;
        c1_h_a = c1_jrow;
        c1_f_b = c1_jpiv_offset;
        c1_jprow = c1_h_a + c1_f_b;
        c1_ix0 = c1_jrow;
        c1_iy0 = c1_jprow;
        c1_b_ix0 = c1_ix0;
        c1_b_iy0 = c1_iy0;
        c1_c_ix0 = c1_b_ix0;
        c1_c_iy0 = c1_b_iy0;
        c1_ix = c1_c_ix0;
        c1_iy = c1_c_iy0;
        for (c1_k = 1; c1_k < 4; c1_k++) {
          c1_temp = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, 9, 1, 0)
            - 1];
          c1_A_data[c1_ix - 1] = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_iy,
            1, 9, 1, 0) - 1];
          c1_A_data[c1_iy - 1] = c1_temp;
          c1_i_a = c1_ix + 3;
          c1_ix = c1_i_a;
          c1_j_a = c1_iy + 3;
          c1_iy = c1_j_a;
        }
      }

      c1_b_jp1j = c1_jp1j;
      c1_k_a = c1_mmj - 1;
      c1_d_c = c1_k_a;
      c1_l_a = c1_jp1j;
      c1_g_b = c1_d_c;
      c1_i162 = c1_l_a + c1_g_b;
      c1_m_a = c1_b_jp1j;
      c1_h_b = c1_i162;
      c1_n_a = c1_m_a;
      c1_i_b = c1_h_b;
      if (c1_n_a > c1_i_b) {
        c1_overflow = FALSE;
      } else {
        c1_overflow = (c1_i_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      for (c1_i = c1_b_jp1j; c1_i <= c1_i162; c1_i++) {
        c1_b_i = c1_i;
        c1_x = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1, 9, 1, 0) - 1];
        c1_y = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_jj, 1, 9, 1, 0) - 1];
        c1_z = c1_x / c1_y;
        c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_i, 1, 9, 1, 0) - 1] =
          c1_z;
      }
    } else {
      *c1_info = c1_b_j;
    }

    c1_j_b = c1_b_j;
    c1_e_c = 3 - c1_j_b;
    c1_o_a = c1_jj + 3;
    c1_f_c = c1_o_a;
    c1_p_a = c1_jj + 4;
    c1_g_c = c1_p_a;
    c1_m = c1_mmj;
    c1_n = c1_e_c;
    c1_d_ix0 = c1_jp1j;
    c1_d_iy0 = c1_f_c;
    c1_ia0 = c1_g_c;
    c1_d10 = -1.0;
    c1_c_eml_xger(chartInstance, c1_m, c1_n, c1_d10, c1_d_ix0, c1_d_iy0,
                  c1_A_data, c1_A_sizes, c1_ia0);
  }

  if (*c1_info == 0) {
    if (!(c1_A_data[2 + (c1_A_sizes[0] << 1)] != 0.0)) {
      *c1_info = 3;
    }
  }
}

static void c1_c_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  int32_T c1_iy0, real_T c1_A_data[9], int32_T c1_A_sizes[2], int32_T c1_ia0)
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_b_ia0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_b_alpha1;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_c_ia0;
  int32_T c1_var;
  ptrdiff_t c1_m_t;
  int32_T c1_b_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  ptrdiff_t c1_incy_t;
  ptrdiff_t c1_lda_t;
  double * c1_alpha1_t;
  double * c1_Aia0_t;
  double * c1_Aix0_t;
  double * c1_Aiy0_t;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_b_iy0 = c1_iy0;
  c1_b_ia0 = c1_ia0;
  c1_c_m = c1_b_m;
  c1_c_n = c1_b_n;
  c1_b_alpha1 = -1.0;
  c1_c_ix0 = c1_b_ix0;
  c1_c_iy0 = c1_b_iy0;
  c1_c_ia0 = c1_b_ia0;
  c1_var = c1_c_m;
  c1_m_t = (ptrdiff_t)(c1_var);
  c1_b_var = c1_c_n;
  c1_n_t = (ptrdiff_t)(c1_b_var);
  c1_incx_t = (ptrdiff_t)(1);
  c1_incy_t = (ptrdiff_t)(3);
  c1_lda_t = (ptrdiff_t)(3);
  c1_alpha1_t = (double *)(&c1_b_alpha1);
  c1_Aia0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ia0, 1,
    9, 1, 0) - 1]);
  c1_Aix0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0, 1,
    9, 1, 0) - 1]);
  c1_Aiy0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_iy0, 1,
    9, 1, 0) - 1]);
  dger(&c1_m_t, &c1_n_t, c1_alpha1_t, c1_Aix0_t, &c1_incx_t, c1_Aiy0_t,
       &c1_incy_t, c1_Aia0_t, &c1_lda_t);
}

static void c1_c_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1])
{
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_b;
  int32_T c1_kAcol;
  int32_T c1_b_a;
  int32_T c1_c_c;
  int32_T c1_c_a;
  int32_T c1_i163;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_d_a;
  int32_T c1_d_c;
  int32_T c1_e_a;
  int32_T c1_e_c;
  int32_T c1_f_a;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_c_b;
  int32_T c1_g_c;
  c1_below_threshold(chartInstance);
  c1_e_eml_scalar_eg(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_a = c1_b_k;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = 3 * c1_b;
    c1_b_b = c1_b_c;
    c1_kAcol = c1_b_b;
    c1_b_a = c1_b_k;
    c1_c_c = c1_b_a;
    if (c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_c, 1, c1_B_sizes[0], 1, 0)
        - 1] != 0.0) {
      c1_c_a = c1_b_k;
      c1_i163 = c1_c_a;
      for (c1_i = c1_i163 + 1; c1_i < 4; c1_i++) {
        c1_b_i = c1_i;
        c1_d_a = c1_b_i;
        c1_d_c = c1_d_a;
        c1_e_a = c1_b_i;
        c1_e_c = c1_e_a;
        c1_f_a = c1_b_k;
        c1_f_c = c1_f_a;
        c1_g_a = c1_b_i;
        c1_c_b = c1_kAcol;
        c1_g_c = c1_g_a + c1_c_b;
        c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_d_c, 1, c1_B_sizes[0], 1, 0)
          - 1] = c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_c, 1,
          c1_B_sizes[0], 1, 0) - 1] - c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c1_f_c, 1, c1_B_sizes[0], 1, 0) - 1] *
          c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_g_c, 1, 9, 1, 0) - 1];
      }
    }
  }
}

static void c1_d_eml_xtrsm(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T c1_A_data[9], int32_T c1_A_sizes[2], real_T c1_B_data
  [10], int32_T c1_B_sizes[1])
{
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_b;
  int32_T c1_kAcol;
  int32_T c1_b_a;
  int32_T c1_c_c;
  int32_T c1_c_a;
  int32_T c1_d_c;
  int32_T c1_d_a;
  int32_T c1_e_c;
  int32_T c1_e_a;
  int32_T c1_c_b;
  int32_T c1_f_c;
  real_T c1_x;
  real_T c1_y;
  real_T c1_z;
  int32_T c1_f_a;
  int32_T c1_i164;
  int32_T c1_d_b;
  int32_T c1_e_b;
  boolean_T c1_overflow;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_h_c;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_j_a;
  int32_T c1_f_b;
  int32_T c1_j_c;
  c1_below_threshold(chartInstance);
  c1_e_eml_scalar_eg(chartInstance);
  for (c1_k = 3; c1_k > 0; c1_k--) {
    c1_b_k = c1_k;
    c1_a = c1_b_k;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = 3 * c1_b;
    c1_b_b = c1_b_c;
    c1_kAcol = c1_b_b;
    c1_b_a = c1_b_k;
    c1_c_c = c1_b_a;
    if (c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_c, 1, c1_B_sizes[0], 1, 0)
        - 1] != 0.0) {
      c1_c_a = c1_b_k;
      c1_d_c = c1_c_a;
      c1_d_a = c1_b_k;
      c1_e_c = c1_d_a;
      c1_e_a = c1_b_k;
      c1_c_b = c1_kAcol;
      c1_f_c = c1_e_a + c1_c_b;
      c1_x = c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_c, 1, c1_B_sizes[0],
        1, 0) - 1];
      c1_y = c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_f_c, 1, 9, 1, 0) - 1];
      c1_z = c1_x / c1_y;
      c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_d_c, 1, c1_B_sizes[0], 1, 0)
        - 1] = c1_z;
      c1_f_a = c1_b_k - 1;
      c1_i164 = c1_f_a;
      c1_d_b = c1_i164;
      c1_e_b = c1_d_b;
      if (1 > c1_e_b) {
        c1_overflow = FALSE;
      } else {
        c1_overflow = (c1_e_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      for (c1_i = 1; c1_i <= c1_i164; c1_i++) {
        c1_b_i = c1_i;
        c1_g_a = c1_b_i;
        c1_g_c = c1_g_a;
        c1_h_a = c1_b_i;
        c1_h_c = c1_h_a;
        c1_i_a = c1_b_k;
        c1_i_c = c1_i_a;
        c1_j_a = c1_b_i;
        c1_f_b = c1_kAcol;
        c1_j_c = c1_j_a + c1_f_b;
        c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_g_c, 1, c1_B_sizes[0], 1, 0)
          - 1] = c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_h_c, 1,
          c1_B_sizes[0], 1, 0) - 1] - c1_B_data[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c1_i_c, 1, c1_B_sizes[0], 1, 0) - 1] *
          c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_j_c, 1, 9, 1, 0) - 1];
      }
    }
  }
}

static void c1_b_sqrt(SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance,
                      real_T *c1_x)
{
  if (*c1_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void c1_b_eml_xswap(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x_data[30], int32_T c1_x_sizes[2],
  int32_T c1_ix0, int32_T c1_iy0)
{
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_d_n;
  int32_T c1_b;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  int32_T c1_x[1];
  real_T c1_temp;
  int32_T c1_b_x[1];
  int32_T c1_c_x[1];
  int32_T c1_d_x[1];
  int32_T c1_a;
  int32_T c1_b_a;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_b_iy0 = c1_iy0;
  c1_c_n = c1_b_n;
  c1_c_ix0 = c1_b_ix0;
  c1_c_iy0 = c1_b_iy0;
  c1_ix = c1_c_ix0;
  c1_iy = c1_c_iy0;
  c1_d_n = c1_c_n;
  c1_b = c1_d_n;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  if (c1_overflow) {
    c1_b_check_forloop_overflow_error(chartInstance, TRUE);
  }

  for (c1_k = 1; c1_k <= c1_d_n; c1_k++) {
    c1_x[0] = c1_x_sizes[0] * 3;
    c1_temp = c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, c1_x_sizes[0] *
      3, 1, 0) - 1];
    c1_b_x[0] = c1_x_sizes[0] * 3;
    c1_c_x[0] = c1_x_sizes[0] * 3;
    c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_ix, 1, c1_x_sizes[0] * 3, 1, 0)
      - 1] = c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_iy, 1, c1_x_sizes[0] *
      3, 1, 0) - 1];
    c1_d_x[0] = c1_x_sizes[0] * 3;
    c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_iy, 1, c1_x_sizes[0] * 3, 1, 0)
      - 1] = c1_temp;
    c1_a = c1_ix + 1;
    c1_ix = c1_a;
    c1_b_a = c1_iy + 1;
    c1_iy = c1_b_a;
  }
}

static real_T c1_c_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, int32_T c1_n, real_T *c1_alpha1, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0)
{
  real_T c1_tau;
  int32_T c1_nm1;
  int32_T c1_b_x_sizes[2];
  int32_T c1_i165;
  int32_T c1_loop_ub;
  int32_T c1_i166;
  real_T c1_b_x_data[30];
  real_T c1_xnorm;
  real_T c1_x1;
  real_T c1_x2;
  real_T c1_a;
  real_T c1_b;
  real_T c1_beta1;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_y;
  int32_T c1_knt;
  int32_T c1_b_a;
  real_T c1_d11;
  real_T c1_c_a;
  real_T c1_d_a;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_b_y;
  int32_T c1_c_x_sizes[2];
  int32_T c1_i167;
  int32_T c1_b_loop_ub;
  int32_T c1_i168;
  real_T c1_c_x_data[30];
  real_T c1_b_x1;
  real_T c1_b_x2;
  real_T c1_e_a;
  real_T c1_b_b;
  real_T c1_e_x;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b_knt;
  int32_T c1_c_b;
  int32_T c1_d_b;
  boolean_T c1_overflow;
  int32_T c1_k;
  real_T c1_f_a;
  real_T c1_f_x;
  real_T c1_e_y;
  real_T c1_f_y;
  c1_tau = 0.0;
  if (c1_n <= 0) {
  } else {
    c1_nm1 = c1_n - 1;
    c1_b_x_sizes[0] = c1_x_sizes[0];
    c1_b_x_sizes[1] = 3;
    for (c1_i165 = 0; c1_i165 < 3; c1_i165++) {
      c1_loop_ub = c1_x_sizes[0] - 1;
      for (c1_i166 = 0; c1_i166 <= c1_loop_ub; c1_i166++) {
        c1_b_x_data[c1_i166 + c1_b_x_sizes[0] * c1_i165] = c1_x_data[c1_i166 +
          c1_x_sizes[0] * c1_i165];
      }
    }

    c1_xnorm = c1_eml_xnrm2(chartInstance, c1_nm1, c1_b_x_data, c1_b_x_sizes,
      c1_ix0);
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
      c1_x = c1_beta1;
      c1_b_x = c1_x;
      c1_y = muDoubleScalarAbs(c1_b_x);
      if (c1_y < 1.0020841800044864E-292) {
        c1_knt = 0;
        do {
          c1_b_a = c1_knt + 1;
          c1_knt = c1_b_a;
          c1_d11 = 9.9792015476736E+291;
          c1_c_eml_xscal(chartInstance, c1_nm1, c1_d11, c1_x_data, c1_x_sizes,
                         c1_ix0);
          c1_c_a = c1_beta1;
          c1_beta1 = c1_c_a * 9.9792015476736E+291;
          c1_d_a = *c1_alpha1;
          *c1_alpha1 = c1_d_a * 9.9792015476736E+291;
          c1_c_x = c1_beta1;
          c1_d_x = c1_c_x;
          c1_b_y = muDoubleScalarAbs(c1_d_x);
        } while (!(c1_b_y >= 1.0020841800044864E-292));

        c1_c_x_sizes[0] = c1_x_sizes[0];
        c1_c_x_sizes[1] = 3;
        for (c1_i167 = 0; c1_i167 < 3; c1_i167++) {
          c1_b_loop_ub = c1_x_sizes[0] - 1;
          for (c1_i168 = 0; c1_i168 <= c1_b_loop_ub; c1_i168++) {
            c1_c_x_data[c1_i168 + c1_c_x_sizes[0] * c1_i167] = c1_x_data[c1_i168
              + c1_x_sizes[0] * c1_i167];
          }
        }

        c1_xnorm = c1_eml_xnrm2(chartInstance, c1_nm1, c1_c_x_data, c1_c_x_sizes,
          c1_ix0);
        c1_b_x1 = *c1_alpha1;
        c1_b_x2 = c1_xnorm;
        c1_e_a = c1_b_x1;
        c1_b_b = c1_b_x2;
        c1_beta1 = muDoubleScalarHypot(c1_e_a, c1_b_b);
        if (*c1_alpha1 >= 0.0) {
          c1_beta1 = -c1_beta1;
        }

        c1_e_x = c1_beta1 - *c1_alpha1;
        c1_c_y = c1_beta1;
        c1_tau = c1_e_x / c1_c_y;
        c1_d_y = *c1_alpha1 - c1_beta1;
        *c1_alpha1 = 1.0 / c1_d_y;
        c1_c_eml_xscal(chartInstance, c1_nm1, *c1_alpha1, c1_x_data, c1_x_sizes,
                       c1_ix0);
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
        c1_f_x = c1_beta1 - *c1_alpha1;
        c1_e_y = c1_beta1;
        c1_tau = c1_f_x / c1_e_y;
        c1_f_y = *c1_alpha1 - c1_beta1;
        *c1_alpha1 = 1.0 / c1_f_y;
        c1_c_eml_xscal(chartInstance, c1_nm1, *c1_alpha1, c1_x_data, c1_x_sizes,
                       c1_ix0);
        *c1_alpha1 = c1_beta1;
      }
    }
  }

  return c1_tau;
}

static void c1_c_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_a, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0)
{
  int32_T c1_b_n;
  real_T c1_b_a;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  real_T c1_c_a;
  int32_T c1_c_ix0;
  int32_T c1_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  int32_T c1_x[1];
  double * c1_xix0_t;
  double * c1_a_t;
  c1_b_n = c1_n;
  c1_b_a = c1_a;
  c1_b_ix0 = c1_ix0;
  if (c1_b_n < 1) {
  } else {
    c1_c_n = c1_b_n;
    c1_c_a = c1_b_a;
    c1_c_ix0 = c1_b_ix0;
    c1_var = c1_c_n;
    c1_n_t = (ptrdiff_t)(c1_var);
    c1_incx_t = (ptrdiff_t)(1);
    c1_x[0] = c1_x_sizes[0] * 3;
    c1_xix0_t = (double *)(&c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0,
      1, c1_x_sizes[0] * 3, 1, 0) - 1]);
    c1_a_t = (double *)(&c1_c_a);
    dscal(&c1_n_t, c1_a_t, c1_xix0_t, &c1_incx_t);
  }
}

static real_T c1_d_eml_matlab_zlarfg(SFc1_DrogueVisualNavigation3InstanceStruct *
  chartInstance, real_T *c1_alpha1, real_T *c1_x)
{
  real_T c1_tau;
  c1_tau = 0.0;
  c1_b_eml_xnrm2(chartInstance);
  return c1_tau;
}

static void c1_d_eml_xscal(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, real_T *c1_x)
{
}

static void c1_b_eml_matlab_zlarf(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, int32_T c1_iv0, real_T c1_tau,
  real_T c1_C_data[30], int32_T c1_C_sizes[2], int32_T c1_ic0, int32_T c1_ldc,
  real_T c1_work[3])
{
  int32_T c1_lastv;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_a;
  int32_T c1_b_b;
  int32_T c1_i;
  int32_T c1_C[1];
  int32_T c1_c_a;
  int32_T c1_d_a;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_ia0;
  int32_T c1_lda;
  int32_T c1_lastc;
  int32_T c1_e_a;
  int32_T c1_c_c;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_d_c;
  int32_T c1_g_a;
  int32_T c1_d_b;
  int32_T c1_coltop;
  int32_T c1_h_a;
  int32_T c1_e_c;
  int32_T c1_i_a;
  int32_T c1_e_b;
  int32_T c1_colbottom;
  int32_T c1_b_coltop;
  int32_T c1_b_colbottom;
  int32_T c1_j_a;
  int32_T c1_f_b;
  int32_T c1_k_a;
  int32_T c1_g_b;
  boolean_T c1_overflow;
  int32_T c1_ia;
  int32_T c1_b_ia;
  int32_T c1_b_C[1];
  int32_T c1_l_a;
  int32_T c1_b_C_sizes[2];
  int32_T c1_i169;
  int32_T c1_loop_ub;
  int32_T c1_i170;
  real_T c1_b_C_data[30];
  int32_T c1_c_C_sizes[2];
  int32_T c1_i171;
  int32_T c1_b_loop_ub;
  int32_T c1_i172;
  real_T c1_c_C_data[30];
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_alpha1;
  int32_T c1_ix0;
  int32_T c1_b_ia0;
  int32_T c1_b_lda;
  int32_T c1_i173;
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
      c1_C[0] = c1_C_sizes[0] * 3;
      if (c1_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i, 1, c1_C_sizes[0] * 3,
           1, 0) - 1] == 0.0) {
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
    c1_lda = c1_ldc;
    c1_lastc = c1_b_n;
    exitg2 = FALSE;
    while ((exitg2 == FALSE) && (c1_lastc > 0)) {
      c1_e_a = c1_lastc;
      c1_c_c = c1_e_a;
      c1_f_a = c1_c_c - 1;
      c1_c_b = c1_lda;
      c1_d_c = c1_f_a * c1_c_b;
      c1_g_a = c1_ia0;
      c1_d_b = c1_d_c;
      c1_coltop = c1_g_a + c1_d_b;
      c1_h_a = c1_b_m;
      c1_e_c = c1_h_a;
      c1_i_a = c1_coltop;
      c1_e_b = c1_e_c - 1;
      c1_colbottom = c1_i_a + c1_e_b;
      c1_b_coltop = c1_coltop;
      c1_b_colbottom = c1_colbottom;
      c1_j_a = c1_b_coltop;
      c1_f_b = c1_b_colbottom;
      c1_k_a = c1_j_a;
      c1_g_b = c1_f_b;
      if (c1_k_a > c1_g_b) {
        c1_overflow = FALSE;
      } else {
        c1_overflow = (c1_g_b > 2147483646);
      }

      if (c1_overflow) {
        c1_b_check_forloop_overflow_error(chartInstance, TRUE);
      }

      c1_ia = c1_b_coltop;
      do {
        exitg1 = 0;
        if (c1_ia <= c1_b_colbottom) {
          c1_b_ia = c1_ia;
          c1_b_C[0] = c1_C_sizes[0] * 3;
          if (c1_C_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_ia, 1, c1_C_sizes[0]
               * 3, 1, 0) - 1] != 0.0) {
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
    c1_b_C_sizes[0] = c1_C_sizes[0];
    c1_b_C_sizes[1] = 3;
    for (c1_i169 = 0; c1_i169 < 3; c1_i169++) {
      c1_loop_ub = c1_C_sizes[0] - 1;
      for (c1_i170 = 0; c1_i170 <= c1_loop_ub; c1_i170++) {
        c1_b_C_data[c1_i170 + c1_b_C_sizes[0] * c1_i169] = c1_C_data[c1_i170 +
          c1_C_sizes[0] * c1_i169];
      }
    }

    c1_c_C_sizes[0] = c1_C_sizes[0];
    c1_c_C_sizes[1] = 3;
    for (c1_i171 = 0; c1_i171 < 3; c1_i171++) {
      c1_b_loop_ub = c1_C_sizes[0] - 1;
      for (c1_i172 = 0; c1_i172 <= c1_b_loop_ub; c1_i172++) {
        c1_c_C_data[c1_i172 + c1_c_C_sizes[0] * c1_i171] = c1_C_data[c1_i172 +
          c1_C_sizes[0] * c1_i171];
      }
    }

    c1_b_eml_xgemv(chartInstance, c1_lastv, c1_lastc, c1_b_C_data, c1_b_C_sizes,
                   c1_ic0, c1_ldc, c1_c_C_data, c1_c_C_sizes, c1_iv0, c1_work);
    c1_c_m = c1_lastv;
    c1_c_n = c1_lastc;
    c1_alpha1 = -c1_tau;
    c1_ix0 = c1_iv0;
    c1_b_ia0 = c1_ic0;
    c1_b_lda = c1_ldc;
    for (c1_i173 = 0; c1_i173 < 3; c1_i173++) {
      c1_b_work[c1_i173] = c1_work[c1_i173];
    }

    c1_d_eml_xger(chartInstance, c1_c_m, c1_c_n, c1_alpha1, c1_ix0, c1_b_work,
                  c1_C_data, c1_C_sizes, c1_b_ia0, c1_b_lda);
  }
}

static void c1_b_eml_xgemv(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_A_data[30], int32_T
  c1_A_sizes[2], int32_T c1_ia0, int32_T c1_lda, real_T c1_x_data[30], int32_T
  c1_x_sizes[2], int32_T c1_ix0, real_T c1_y[3])
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_b_ia0;
  int32_T c1_b_lda;
  int32_T c1_b_ix0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_alpha1;
  int32_T c1_c_ia0;
  int32_T c1_c_lda;
  int32_T c1_c_ix0;
  real_T c1_beta1;
  char_T c1_TRANSA;
  int32_T c1_var;
  ptrdiff_t c1_m_t;
  int32_T c1_b_var;
  ptrdiff_t c1_n_t;
  int32_T c1_c_var;
  ptrdiff_t c1_lda_t;
  ptrdiff_t c1_incx_t;
  ptrdiff_t c1_incy_t;
  double * c1_alpha1_t;
  double * c1_beta1_t;
  double * c1_yiy0_t;
  double * c1_Aia0_t;
  double * c1_xix0_t;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_ia0 = c1_ia0;
  c1_b_lda = c1_lda;
  c1_b_ix0 = c1_ix0;
  if (c1_b_n < 1) {
  } else {
    c1_c_m = c1_b_m;
    c1_c_n = c1_b_n;
    c1_alpha1 = 1.0;
    c1_c_ia0 = c1_b_ia0;
    c1_c_lda = c1_b_lda;
    c1_c_ix0 = c1_b_ix0;
    c1_beta1 = 0.0;
    c1_TRANSA = 'C';
    c1_var = c1_c_m;
    c1_m_t = (ptrdiff_t)(c1_var);
    c1_b_var = c1_c_n;
    c1_n_t = (ptrdiff_t)(c1_b_var);
    c1_c_var = c1_c_lda;
    c1_lda_t = (ptrdiff_t)(c1_c_var);
    c1_incx_t = (ptrdiff_t)(1);
    c1_incy_t = (ptrdiff_t)(1);
    c1_alpha1_t = (double *)(&c1_alpha1);
    c1_beta1_t = (double *)(&c1_beta1);
    c1_yiy0_t = (double *)(&c1_y[0]);
    c1_Aia0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ia0,
      1, c1_A_sizes[0] * 3, 1, 0) - 1]);
    c1_xix0_t = (double *)(&c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0,
      1, c1_x_sizes[0] * 3, 1, 0) - 1]);
    dgemv(&c1_TRANSA, &c1_m_t, &c1_n_t, c1_alpha1_t, c1_Aia0_t, &c1_lda_t,
          c1_xix0_t, &c1_incx_t, c1_beta1_t, c1_yiy0_t, &c1_incy_t);
  }
}

static void c1_d_eml_xger(SFc1_DrogueVisualNavigation3InstanceStruct
  *chartInstance, int32_T c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0,
  real_T c1_y[3], real_T c1_A_data[30], int32_T c1_A_sizes[2], int32_T c1_ia0,
  int32_T c1_lda)
{
  int32_T c1_b_m;
  int32_T c1_b_n;
  real_T c1_b_alpha1;
  int32_T c1_b_ix0;
  int32_T c1_b_ia0;
  int32_T c1_b_lda;
  int32_T c1_c_m;
  int32_T c1_c_n;
  real_T c1_c_alpha1;
  int32_T c1_c_ix0;
  int32_T c1_c_ia0;
  int32_T c1_c_lda;
  int32_T c1_var;
  ptrdiff_t c1_m_t;
  int32_T c1_b_var;
  ptrdiff_t c1_n_t;
  ptrdiff_t c1_incx_t;
  ptrdiff_t c1_incy_t;
  int32_T c1_c_var;
  ptrdiff_t c1_lda_t;
  double * c1_alpha1_t;
  int32_T c1_A[1];
  double * c1_Aia0_t;
  int32_T c1_b_A[1];
  double * c1_Aix0_t;
  double * c1_yiy0_t;
  c1_b_m = c1_m;
  c1_b_n = c1_n;
  c1_b_alpha1 = c1_alpha1;
  c1_b_ix0 = c1_ix0;
  c1_b_ia0 = c1_ia0;
  c1_b_lda = c1_lda;
  if (c1_b_n < 1) {
  } else {
    c1_c_m = c1_b_m;
    c1_c_n = c1_b_n;
    c1_c_alpha1 = c1_b_alpha1;
    c1_c_ix0 = c1_b_ix0;
    c1_c_ia0 = c1_b_ia0;
    c1_c_lda = c1_b_lda;
    c1_var = c1_c_m;
    c1_m_t = (ptrdiff_t)(c1_var);
    c1_b_var = c1_c_n;
    c1_n_t = (ptrdiff_t)(c1_b_var);
    c1_incx_t = (ptrdiff_t)(1);
    c1_incy_t = (ptrdiff_t)(1);
    c1_c_var = c1_c_lda;
    c1_lda_t = (ptrdiff_t)(c1_c_var);
    c1_alpha1_t = (double *)(&c1_c_alpha1);
    c1_A[0] = c1_A_sizes[0] * 3;
    c1_Aia0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ia0,
      1, c1_A_sizes[0] * 3, 1, 0) - 1]);
    c1_b_A[0] = c1_A_sizes[0] * 3;
    c1_Aix0_t = (double *)(&c1_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_ix0,
      1, c1_A_sizes[0] * 3, 1, 0) - 1]);
    c1_yiy0_t = (double *)(&c1_y[0]);
    dger(&c1_m_t, &c1_n_t, c1_alpha1_t, c1_Aix0_t, &c1_incx_t, c1_yiy0_t,
         &c1_incy_t, c1_Aia0_t, &c1_lda_t);
  }
}

static void init_dsm_address_info(SFc1_DrogueVisualNavigation3InstanceStruct
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

void sf_c1_DrogueVisualNavigation3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2629003808U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1915465107U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2266024996U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2118321712U);
}

mxArray *sf_c1_DrogueVisualNavigation3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("I51awk2QSdzNsk4f86P3VE");
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

mxArray *sf_c1_DrogueVisualNavigation3_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_DrogueVisualNavigation3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"yy\",},{M[8],M[0],T\"is_active_c1_DrogueVisualNavigation3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DrogueVisualNavigation3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
    chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DrogueVisualNavigation3MachineNumber_,
           1,
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,2,0,8,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,917);
        _SFD_CV_INIT_EML_IF(0,1,0,695,723,-1,762);
        _SFD_CV_INIT_EML_IF(0,1,1,804,840,-1,897);
        _SFD_CV_INIT_EML_FOR(0,1,0,105,115,189);
        _SFD_CV_INIT_EML_FOR(0,1,1,630,652,775);

        {
          static int condStart[] = { 698, 704, 710, 717 };

          static int condEnd[] = { 702, 708, 715, 722 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,698,722,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 807, 815, 823, 832 };

          static int condEnd[] = { 813, 821, 830, 839 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,807,839,4,4,&(condStart[0]),&(condEnd[0]),
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
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 860;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint32_T *c1_u2;
          uint32_T (*c1_u1)[412800];
          real_T (*c1_yy)[412800];
          real_T (*c1_u3)[412800];
          c1_u3 = (real_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 2);
          c1_u2 = (uint32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_yy = (real_T (*)[412800])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_u1 = (uint32_T (*)[412800])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_yy);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_u3);
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
  return "eo3KMybaCmTePtQLUEkftD";
}

static void sf_opaque_initialize_c1_DrogueVisualNavigation3(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DrogueVisualNavigation3
    ((SFc1_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
  initialize_c1_DrogueVisualNavigation3
    ((SFc1_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DrogueVisualNavigation3(void *chartInstanceVar)
{
  enable_c1_DrogueVisualNavigation3((SFc1_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_DrogueVisualNavigation3(void *chartInstanceVar)
{
  disable_c1_DrogueVisualNavigation3((SFc1_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_DrogueVisualNavigation3(void *chartInstanceVar)
{
  sf_c1_DrogueVisualNavigation3((SFc1_DrogueVisualNavigation3InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_DrogueVisualNavigation3
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DrogueVisualNavigation3
    ((SFc1_DrogueVisualNavigation3InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DrogueVisualNavigation3();/* state var info */
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

extern void sf_internal_set_sim_state_c1_DrogueVisualNavigation3(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DrogueVisualNavigation3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DrogueVisualNavigation3
    ((SFc1_DrogueVisualNavigation3InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_DrogueVisualNavigation3
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DrogueVisualNavigation3(S);
}

static void sf_opaque_set_sim_state_c1_DrogueVisualNavigation3(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_DrogueVisualNavigation3(S, st);
}

static void sf_opaque_terminate_c1_DrogueVisualNavigation3(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DrogueVisualNavigation3InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DrogueVisualNavigation3_optimization_info();
    }

    finalize_c1_DrogueVisualNavigation3
      ((SFc1_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DrogueVisualNavigation3
    ((SFc1_DrogueVisualNavigation3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DrogueVisualNavigation3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DrogueVisualNavigation3
      ((SFc1_DrogueVisualNavigation3InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DrogueVisualNavigation3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DrogueVisualNavigation3_optimization_info();
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
  ssSetChecksum0(S,(4108895848U));
  ssSetChecksum1(S,(788591298U));
  ssSetChecksum2(S,(1671131117U));
  ssSetChecksum3(S,(4118140522U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DrogueVisualNavigation3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DrogueVisualNavigation3(SimStruct *S)
{
  SFc1_DrogueVisualNavigation3InstanceStruct *chartInstance;
  chartInstance = (SFc1_DrogueVisualNavigation3InstanceStruct *)utMalloc(sizeof
    (SFc1_DrogueVisualNavigation3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DrogueVisualNavigation3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DrogueVisualNavigation3;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_DrogueVisualNavigation3;
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

void c1_DrogueVisualNavigation3_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DrogueVisualNavigation3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DrogueVisualNavigation3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DrogueVisualNavigation3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DrogueVisualNavigation3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
