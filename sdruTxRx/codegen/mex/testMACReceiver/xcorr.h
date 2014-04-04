/*
 * xcorr.h
 *
 * Code generation for function 'xcorr'
 *
 * C source code generated on: Thu Apr  3 19:51:42 2014
 *
 */

#ifndef __XCORR_H__
#define __XCORR_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "testMACReceiver_types.h"

/* Function Declarations */
extern void b_xcorr(const real_T arg1_data[1231], real_T C_data[2461], int32_T C_size[1]);
extern void xcorr(const creal_T arg1_data[1231], const creal_T arg2_data[16], creal_T C_data[2461], int32_T C_size[1]);
#endif
/* End of code generation (xcorr.h) */
