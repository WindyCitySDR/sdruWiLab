/*
 * testPHYTransmit_initialize.c
 *
 * Code generation for function 'testPHYTransmit_initialize'
 *
 * C source code generated on: Sat Mar 29 15:48:37 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testPHYTransmit.h"
#include "testPHYTransmit_initialize.h"
#include "testPHYTransmit_data.h"

/* Function Declarations */
static void testPHYTransmit_once(void);

/* Function Definitions */
static void testPHYTransmit_once(void)
{
  isSetupsdruCalled = FALSE;
}

void testPHYTransmit_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal, "Communication_Toolbox", 2);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal, "communication_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    testPHYTransmit_once();
  }
}

/* End of code generation (testPHYTransmit_initialize.c) */
