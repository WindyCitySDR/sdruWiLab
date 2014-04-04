/*
 * PHYReceive.h
 *
 * Code generation for function 'PHYReceive'
 *
 * C source code generated on: Thu Apr  3 19:36:38 2014
 *
 */

#ifndef __PHYRECEIVE_H__
#define __PHYRECEIVE_H__
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
#include "testPHYReceive_types.h"

/* Function Declarations */
extern void PHYReceive(testPHYReceiveStackData *SD, comm_AGC *ObjAGC, comm_SDRuReceiver *ObjSDRuReceiver, commcodegen_CRCDetector *ObjDetect, OFDMDemodulator_1 *ObjPreambleDemod, OFDMDemodulator *ObjDataDemod, struct_T *estimate, const creal_T rx_shortPreambleOFDM[64], const real_T rx_longPreamble[53], const real_T rx_pilots[48], const real_T c_rx_pilotLocationsWithoutGuard[4], const real_T rx_dataSubcarrierIndexies_data[48], const int32_T rx_dataSubcarrierIndexies_size[2], real_T messageBits_data[1689], int32_T messageBits_size[2], char_T recoveredMessage_data[80], int32_T recoveredMessage_size[2]);
#endif
/* End of code generation (PHYReceive.h) */
