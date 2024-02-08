#include "dft.h"

extern void dft2Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    /*
    pDst[0].re = pSrc[0].re + pSrc[1].re;
    pDst[0].im = pSrc[0].im + pSrc[1].im;
    pDst[1].re = pSrc[0].re - pSrc[1].re;
    pDst[1].im = pSrc[0].im - pSrc[1].im;*/
    int vl = vsetvlmax_e32m1();
    vl = vsetvl_e32m1(2);
    vfloat32m1_t tmpDst1 = vle32_v_f32m1((float*)pSrc, vl);
    vfloat32m1_t tmpDst2 = vle32_v_f32m1((float*)pSrc+2, vl);
    vfloat32m1_t pDst_1 = vle32_v_f32m1((float*)pDst, vl);
    //vfloat32m1_t pDst_2 = vle32_v_f32m1((float*)pDst+2, vl);
    pDst_1 = vfadd_vv_f32m1 (tmpDst1, tmpDst2, vl);
    tmpDst2 = vfsub_vv_f32m1 (tmpDst1, tmpDst2, vl);

    vse32_v_f32m1 ((float*)pDst, pDst_1, vl);
    vse32_v_f32m1 ((float*)pDst+2, tmpDst2, vl);
}
