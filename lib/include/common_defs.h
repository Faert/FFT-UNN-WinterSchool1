#ifndef COMMON_H
#define COMMON_H

#ifdef USE_OPENMP
#include <omp.h>
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "riscv_vector.h"

#define OWN_2PI 0x1.921fb54442d18p+2
#define SQRT2_1 (float)0.70710678
#define SQRT2_1_ (float)-0.70710678

#define CP8 (float)0.92387953251
#define C3P8 (float)0.38268343236
#define CP8_ (float)-0.92387953251
#define C3P8_ (float)-0.38268343236

// Complex float data type
typedef struct {
    float re;
    float im;
} cfloat32_t;

#endif // COMMON_H
