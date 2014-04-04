/*
 * FIRRateConverter.c
 *
 * Code generation for function 'FIRRateConverter'
 *
 * C source code generated on: Thu Apr  3 19:51:42 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testMACReceiver.h"
#include "FIRRateConverter.h"
#include "testMACReceiver_data.h"

/* Function Definitions */
dspcodegen_FIRRateConverter *c_FIRRateConverter_FIRRateConve
  (dspcodegen_FIRRateConverter *obj)
{
  dspcodegen_FIRRateConverter *b_obj;
  dspcodegen_FIRRateConverter *c_obj;
  dsp_FIRRateConverter_7 *d_obj;
  int32_T i;
  static const real_T dv14[252] = { 0.0, -0.00080944841270701856,
    0.0017448652212834904, -0.003229237105918336, 0.005467801350010737,
    -0.0087713345939752219, 0.013701072061976847, -0.021508898209755666,
    0.0358577019470654, -0.074074931596807128, 0.98846260348411263,
    0.088200175685527793, -0.039570997819482069, 0.023273208680562884,
    -0.014750130057554595, 0.0094586677399020984, -0.0059335925299272676,
    0.0035433119085542192, -0.0019494049545480993, 0.00093419618481047279,
    -0.00033744961033280803, -1.4310536619858296E-18, 3.70668154995274E-18,
    -6.9846761033954277E-18, 1.1207102978491231E-17, -1.6173656797082727E-17,
    2.1551111961996462E-17, -2.6905432075821247E-17, 3.175277024096518E-17,
    -3.56219808482348E-17, 3.81188682834355E-17, 1.0, 3.81188682834355E-17,
    -3.56219808482348E-17, 3.175277024096518E-17, -2.6905432075821247E-17,
    2.1551111961996462E-17, -1.6173656797082727E-17, 1.1207102978491231E-17,
    -6.9846761033954277E-18, 3.70668154995274E-18, -1.4310536619858296E-18,
    -0.00033744961033280803, 0.00093419618481047279, -0.0019494049545480993,
    0.0035433119085542192, -0.0059335925299272676, 0.0094586677399020984,
    -0.014750130057554595, 0.023273208680562884, -0.039570997819482069,
    0.088200175685527793, 0.98846260348411263, -0.074074931596807128,
    0.0358577019470654, -0.021508898209755666, 0.013701072061976847,
    -0.0087713345939752219, 0.005467801350010737, -0.003229237105918336,
    0.0017448652212834904, -0.00080944841270701856, 0.0, -0.00072341743910430008,
    0.0019335163432223723, -0.00397498912882327, 0.007164230266835752,
    -0.011934919243443804, 0.018970597371494535, -0.02956852065612375,
    0.046799799620853719, -0.080488645920690632, 0.18804215009866251,
    0.95433736341321784, -0.13232183813601706, 0.066072070804115937,
    -0.039969462476574465, 0.025511020257529136, -0.016313189352039487,
    0.010134343593550898, -0.0059501873440592412, 0.0031843150094913544,
    -0.0014512199818476918, 0.0, -0.0011298783380794953, 0.0029246523773606707,
    -0.0059282781089010431, 0.010598343541304641, -0.017567982087074659,
    0.027849188538337278, -0.043395462405721459, 0.068928461346035891,
    -0.1200579254705211, 0.2963541708851769, 0.89906026063528,
    -0.17386706526764473, 0.08922655002527817, -0.054390867741211935,
    0.034773119396513764, -0.022205750162368854, 0.013745209350216864,
    -0.0080210195602343614, 0.0042496139109971572, -0.0019004581695687074, 0.0,
    -0.0015218049527437325, 0.0038251740642962374, -0.007650433134205231,
    0.013571041697501418, -0.022388294588697476, 0.035401449967862771,
    -0.055162027482693457, 0.087969790265235631, -0.15539008220258557,
    0.40940847283826587, 0.82494310934054782, -0.19866928825688832,
    0.10446069508539771, -0.064118621915997723, 0.041047129249206039,
    -0.026171474976264441, 0.016138458533448603, -0.0093578252569817746,
    0.0049060033713843928, -0.0021501811410915409, 0.0, -0.001859522418998347,
    0.0045494178332125875, -0.0089838159469023786, 0.015817603754262607,
    -0.025975289981051915, 0.0409779863881359, -0.063865387582636282,
    0.10230858413274846, -0.18355685537806973, 0.52308714027338821,
    0.73505615801074231, -0.20747871004960136, 0.11147786143222303,
    -0.068853245941257024, 0.044123890090586454, -0.028083901855743922,
    0.017248729892379792, -0.00993554741111805, 0.005151838481259061,
    -0.0022096861869127992, 0.0, -0.0021018299101738074, 0.0050153383341781958,
    -0.0097846054329695249, 0.017104267049697423, -0.02796547516576715,
    0.044023460301906153, -0.068644838078213019, 0.11051937729566859,
    -0.20175599200202762, 0.63307309464896355, 0.63307309464896355,
    -0.20175599200202762, 0.11051937729566859, -0.068644838078213019,
    0.044023460301906153, -0.02796547516576715, 0.017104267049697423,
    -0.0097846054329695249, 0.0050153383341781958, -0.0021018299101738074, 0.0,
    -0.0022096861869127992, 0.005151838481259061, -0.00993554741111805,
    0.017248729892379792, -0.028083901855743922, 0.044123890090586454,
    -0.068853245941257024, 0.11147786143222303, -0.20747871004960136,
    0.73505615801074231, 0.52308714027338821, -0.18355685537806973,
    0.10230858413274846, -0.063865387582636282, 0.0409779863881359,
    -0.025975289981051915, 0.015817603754262607, -0.0089838159469023786,
    0.0045494178332125875, -0.001859522418998347, 0.0, -0.0021501811410915409,
    0.0049060033713843928, -0.0093578252569817746, 0.016138458533448603,
    -0.026171474976264441, 0.041047129249206039, -0.064118621915997723,
    0.10446069508539771, -0.19866928825688832, 0.82494310934054782,
    0.40940847283826587, -0.15539008220258557, 0.087969790265235631,
    -0.055162027482693457, 0.035401449967862771, -0.022388294588697476,
    0.013571041697501418, -0.007650433134205231, 0.0038251740642962374,
    -0.0015218049527437325, 0.0, -0.0019004581695687074, 0.0042496139109971572,
    -0.0080210195602343614, 0.013745209350216864, -0.022205750162368854,
    0.034773119396513764, -0.054390867741211935, 0.08922655002527817,
    -0.17386706526764473, 0.89906026063528, 0.2963541708851769,
    -0.1200579254705211, 0.068928461346035891, -0.043395462405721459,
    0.027849188538337278, -0.017567982087074659, 0.010598343541304641,
    -0.0059282781089010431, 0.0029246523773606707, -0.0011298783380794953, 0.0,
    -0.0014512199818476918, 0.0031843150094913544, -0.0059501873440592412,
    0.010134343593550898, -0.016313189352039487, 0.025511020257529136,
    -0.039969462476574465, 0.066072070804115937, -0.13232183813601706,
    0.95433736341321784, 0.18804215009866251, -0.080488645920690632,
    0.046799799620853719, -0.02956852065612375, 0.018970597371494535,
    -0.011934919243443804, 0.007164230266835752, -0.00397498912882327,
    0.0019335163432223723, -0.00072341743910430008, 0.0 };

  b_obj = obj;
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  c_obj = b_obj;
  emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  c_obj->isInitialized = FALSE;
  c_obj->isReleased = FALSE;
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  c_obj->inputDirectFeedthrough1 = FALSE;
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  d_obj = &b_obj->cSFunObject;

  /* System object Constructor function: dsp.FIRRateConverter */
  d_obj->S0_isInitialized = FALSE;
  d_obj->S1_isReleased = FALSE;
  for (i = 0; i < 252; i++) {
    d_obj->P0_FILTER[i] = dv14[i];
  }

  for (i = 0; i < 12; i++) {
    d_obj->P1_PolyphaseSelector[i] = i;
  }

  d_obj->P2_StartIdx = 0;
  d_obj->P3_StopIdx = 12;
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&nj_emlrtRSI, emlrtRootTLSGlobal);
  return b_obj;
}

/* End of code generation (FIRRateConverter.c) */
