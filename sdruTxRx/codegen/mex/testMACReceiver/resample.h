/*
 * resample.h
 *
 * Code generation for function 'resample'
 *
 * C source code generated on: Thu Apr  3 19:51:42 2014
 *
 */

#ifndef __RESAMPLE_H__
#define __RESAMPLE_H__
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
extern void resample(testMACReceiverStackData *SD, const creal_T x[48], creal_T yout[576]);
#endif
/* End of code generation (resample.h) */
