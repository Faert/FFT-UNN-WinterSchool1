#include "dft.h"

extern void dft8Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{   
    cfloat32_t tmpDst_8[8];
    /*
    #pragma omp parallel sections num_threads(2) 
    {
        #pragma omp section
        {
            cfloat32_t tmpDst_4[4];

            tmpDst_4[0].re = pSrc[0].re   + pSrc[4].re;
            tmpDst_4[0].im = pSrc[0].im   + pSrc[4].im;
            tmpDst_4[1].re = pSrc[0].re   - pSrc[4].re;
            tmpDst_4[1].im = pSrc[0].im   - pSrc[4].im;
            tmpDst_4[2].re = pSrc[2].re   + pSrc[6].re;
            tmpDst_4[2].im = pSrc[2].im   + pSrc[6].im;
            tmpDst_4[3].re = pSrc[2].re   - pSrc[6].re;
            tmpDst_4[3].im = pSrc[2].im   - pSrc[6].im;
            tmpDst_8[0].re   = tmpDst_4[0].re + tmpDst_4[2].re;
            tmpDst_8[0].im   = tmpDst_4[0].im + tmpDst_4[2].im;
            tmpDst_8[1].re   = tmpDst_4[1].re + tmpDst_4[3].im;
            tmpDst_8[1].im   = tmpDst_4[1].im - tmpDst_4[3].re;
            tmpDst_8[2].re   = tmpDst_4[0].re - tmpDst_4[2].re;
            tmpDst_8[2].im   = tmpDst_4[0].im - tmpDst_4[2].im;
            tmpDst_8[3].re   = tmpDst_4[1].re - tmpDst_4[3].im;
            tmpDst_8[3].im   = tmpDst_4[1].im + tmpDst_4[3].re;
        }
        #pragma omp section
        {
            cfloat32_t tmpDst_4[4];

            tmpDst_4[0].re = pSrc[1].re   + pSrc[5].re;
            tmpDst_4[0].im = pSrc[1].im   + pSrc[5].im;
            tmpDst_4[1].re = pSrc[1].re   - pSrc[5].re;
            tmpDst_4[1].im = pSrc[1].im   - pSrc[5].im;
            tmpDst_4[2].re = pSrc[3].re   + pSrc[7].re;
            tmpDst_4[2].im = pSrc[3].im   + pSrc[7].im;
            tmpDst_4[3].re = pSrc[3].re   - pSrc[7].re;
            tmpDst_4[3].im = pSrc[3].im   - pSrc[7].im;
            pDst[4].re   = tmpDst_4[0].re + tmpDst_4[2].re;
            pDst[4].im   = tmpDst_4[0].im + tmpDst_4[2].im;
            tmpDst_8[5].re   = tmpDst_4[1].re + tmpDst_4[3].im;
            tmpDst_8[5].im   = tmpDst_4[1].im - tmpDst_4[3].re;
            pDst[6].im   = tmpDst_4[2].re - tmpDst_4[0].re;//!
            pDst[6].re   = tmpDst_4[0].im - tmpDst_4[2].im;//!
            tmpDst_8[7].re   = tmpDst_4[1].re - tmpDst_4[3].im;
            tmpDst_8[7].im   = tmpDst_4[1].im + tmpDst_4[3].re;
        }
    }*/
    
    cfloat32_t tmpDst_4[4];

    tmpDst_4[0].re = pSrc[0].re   + pSrc[4].re;
    tmpDst_4[0].im = pSrc[0].im   + pSrc[4].im;
    tmpDst_4[1].re = pSrc[0].re   - pSrc[4].re;
    tmpDst_4[1].im = pSrc[0].im   - pSrc[4].im;
    tmpDst_4[2].re = pSrc[2].re   + pSrc[6].re;
    tmpDst_4[2].im = pSrc[2].im   + pSrc[6].im;
    tmpDst_4[3].re = pSrc[2].re   - pSrc[6].re;
    tmpDst_4[3].im = pSrc[2].im   - pSrc[6].im;
    tmpDst_8[0].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    tmpDst_8[0].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[1].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[1].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    tmpDst_8[2].re   = tmpDst_4[0].re - tmpDst_4[2].re;
    tmpDst_8[2].im   = tmpDst_4[0].im - tmpDst_4[2].im;
    tmpDst_8[3].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[3].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    tmpDst_4[0].re = pSrc[1].re   + pSrc[5].re;
    tmpDst_4[0].im = pSrc[1].im   + pSrc[5].im;
    tmpDst_4[1].re = pSrc[1].re   - pSrc[5].re;
    tmpDst_4[1].im = pSrc[1].im   - pSrc[5].im;
    tmpDst_4[2].re = pSrc[3].re   + pSrc[7].re;
    tmpDst_4[2].im = pSrc[3].im   + pSrc[7].im;
    tmpDst_4[3].re = pSrc[3].re   - pSrc[7].re;
    tmpDst_4[3].im = pSrc[3].im   - pSrc[7].im;
    pDst[4].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    pDst[4].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[5].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[5].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    pDst[6].im   = tmpDst_4[2].re - tmpDst_4[0].re;//!
    pDst[6].re   = tmpDst_4[0].im - tmpDst_4[2].im;//!
    tmpDst_8[7].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[7].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    pDst[5].re = (tmpDst_8[5].re + tmpDst_8[5].im) * SQRT2_1;
    pDst[5].im = (tmpDst_8[5].im - tmpDst_8[5].re) * SQRT2_1;

    pDst[7].re = (tmpDst_8[7].re - tmpDst_8[7].im) * SQRT2_1_;
    pDst[7].im = (tmpDst_8[7].im + tmpDst_8[7].re) * SQRT2_1_;

//vect&tasks
    
    pDst[0].re = tmpDst_8[0].re + pDst[4].re;
    pDst[0].im = tmpDst_8[0].im + pDst[4].im;
    pDst[1].re = tmpDst_8[1].re + pDst[5].re;
    pDst[1].im = tmpDst_8[1].im + pDst[5].im;
    pDst[2].re = tmpDst_8[2].re + pDst[6].re;
    pDst[2].im = tmpDst_8[2].im + pDst[6].im;
    pDst[3].re = tmpDst_8[3].re + pDst[7].re;
    pDst[3].im = tmpDst_8[3].im + pDst[7].im;

    pDst[4].re = tmpDst_8[0].re - pDst[4].re;
    pDst[4].im = tmpDst_8[0].im - pDst[4].im;
    pDst[5].re = tmpDst_8[1].re - pDst[5].re;
    pDst[5].im = tmpDst_8[1].im - pDst[5].im;
    pDst[6].re = tmpDst_8[2].re - pDst[6].re;
    pDst[6].im = tmpDst_8[2].im - pDst[6].im;
    pDst[7].re = tmpDst_8[3].re - pDst[7].re;
    pDst[7].im = tmpDst_8[3].im - pDst[7].im;

    /*
    int vl = vsetvlmax_e32m2();
    vl = vsetvl_e32m2(8);
    vfloat32m2_t tmpDst = vle32_v_f32m2((float*)&tmpDst_8, vl);
    vfloat32m2_t pDst_1 = vle32_v_f32m2((float*)pDst, vl);
    vfloat32m2_t pDst_2 = vle32_v_f32m2((float*)pDst+8, vl);
    pDst_1 = vfadd_vv_f32m2 (tmpDst, pDst_2, vl);
    pDst_2 = vfsub_vv_f32m2 (tmpDst, pDst_2, vl);

    vse32_v_f32m2 ((float*)pDst, pDst_1, vl);
    vse32_v_f32m2 ((float*)pDst+8, pDst_2, vl);*/

    return;
}
