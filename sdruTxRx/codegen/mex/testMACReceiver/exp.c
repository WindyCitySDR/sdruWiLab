/*
 * exp.c
 *
 * Code generation for function 'exp'
 *
 * C source code generated on: Thu Apr  3 19:51:42 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testMACReceiver.h"
#include "exp.h"

/* Function Definitions */
void b_exp(creal_T x_data[1280], int32_T x_size[1])
{
  int32_T i39;
  int32_T k;
  real_T r;
  real_T x_data_im;
  real_T b_x_data_im;
  i39 = x_size[0];
  for (k = 0; k < i39; k++) {
    r = muDoubleScalarExp(x_data[k].re / 2.0);
    x_data_im = x_data[k].im;
    b_x_data_im = x_data[k].im;
    x_data[k].re = r * (r * muDoubleScalarCos(x_data_im));
    x_data[k].im = r * (r * muDoubleScalarSin(b_x_data_im));
  }
}

/* End of code generation (exp.c) */
