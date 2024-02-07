#include "dft.h"

extern void dft16Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    cfloat32_t tmpDst_4[4];
    cfloat32_t tmpDst_8[8];
    cfloat32_t tmpDst_16[16];

    tmpDst_4[0].re = pSrc[0].re   + pSrc[8].re;
    tmpDst_4[0].im = pSrc[0].im   + pSrc[8].im;
    tmpDst_4[1].re = pSrc[0].re   - pSrc[8].re;
    tmpDst_4[1].im = pSrc[0].im   - pSrc[8].im;
    tmpDst_4[2].re = pSrc[4].re   + pSrc[12].re;
    tmpDst_4[2].im = pSrc[4].im   + pSrc[12].im;
    tmpDst_4[3].re = pSrc[4].re   - pSrc[12].re;
    tmpDst_4[3].im = pSrc[4].im   - pSrc[12].im;
    tmpDst_8[0].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    tmpDst_8[0].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[1].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[1].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    tmpDst_8[2].re   = tmpDst_4[0].re - tmpDst_4[2].re;
    tmpDst_8[2].im   = tmpDst_4[0].im - tmpDst_4[2].im;
    tmpDst_8[3].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[3].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    tmpDst_4[0].re = pSrc[2].re   + pSrc[10].re;
    tmpDst_4[0].im = pSrc[2].im   + pSrc[10].im;
    tmpDst_4[1].re = pSrc[2].re   - pSrc[10].re;
    tmpDst_4[1].im = pSrc[2].im   - pSrc[10].im;
    tmpDst_4[2].re = pSrc[6].re   + pSrc[14].re;
    tmpDst_4[2].im = pSrc[6].im   + pSrc[14].im;
    tmpDst_4[3].re = pSrc[6].re   - pSrc[14].re;
    tmpDst_4[3].im = pSrc[6].im   - pSrc[14].im;
    tmpDst_16[4].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    tmpDst_16[4].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[5].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[5].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    tmpDst_16[6].im   = tmpDst_4[2].re - tmpDst_4[0].re;//!!
    tmpDst_16[6].re   = tmpDst_4[0].im - tmpDst_4[2].im;//!!
    tmpDst_8[7].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[7].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    tmpDst_16[5].re = (tmpDst_8[5].re + tmpDst_8[5].im) * SQRT2_1;
    tmpDst_16[5].im = (tmpDst_8[5].im - tmpDst_8[5].re) * SQRT2_1;

    tmpDst_16[7].re = (tmpDst_8[7].re - tmpDst_8[7].im) * SQRT2_1_;
    tmpDst_16[7].im = (tmpDst_8[7].im + tmpDst_8[7].re) * SQRT2_1_;

    tmpDst_16[0].re = tmpDst_8[0].re + tmpDst_16[4].re;
    tmpDst_16[0].im = tmpDst_8[0].im + tmpDst_16[4].im;
    tmpDst_16[1].re = tmpDst_8[1].re + tmpDst_16[5].re;
    tmpDst_16[1].im = tmpDst_8[1].im + tmpDst_16[5].im;
    tmpDst_16[2].re = tmpDst_8[2].re + tmpDst_16[6].re;
    tmpDst_16[2].im = tmpDst_8[2].im + tmpDst_16[6].im;
    tmpDst_16[3].re = tmpDst_8[3].re + tmpDst_16[7].re;
    tmpDst_16[3].im = tmpDst_8[3].im + tmpDst_16[7].im;

    tmpDst_16[4].re = tmpDst_8[0].re - tmpDst_16[4].re;
    tmpDst_16[4].im = tmpDst_8[0].im - tmpDst_16[4].im;
    tmpDst_16[5].re = tmpDst_8[1].re - tmpDst_16[5].re;
    tmpDst_16[5].im = tmpDst_8[1].im - tmpDst_16[5].im;
    tmpDst_16[6].re = tmpDst_8[2].re - tmpDst_16[6].re;
    tmpDst_16[6].im = tmpDst_8[2].im - tmpDst_16[6].im;
    tmpDst_16[7].re = tmpDst_8[3].re - tmpDst_16[7].re;
    tmpDst_16[7].im = tmpDst_8[3].im - tmpDst_16[7].im;


    tmpDst_4[0].re = pSrc[1].re   + pSrc[9].re;
    tmpDst_4[0].im = pSrc[1].im   + pSrc[9].im;
    tmpDst_4[1].re = pSrc[1].re   - pSrc[9].re;
    tmpDst_4[1].im = pSrc[1].im   - pSrc[9].im;
    tmpDst_4[2].re = pSrc[5].re   + pSrc[13].re;
    tmpDst_4[2].im = pSrc[5].im   + pSrc[13].im;
    tmpDst_4[3].re = pSrc[5].re   - pSrc[13].re;
    tmpDst_4[3].im = pSrc[5].im   - pSrc[13].im;
    tmpDst_8[0].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    tmpDst_8[0].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[1].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[1].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    tmpDst_8[2].re   = tmpDst_4[0].re - tmpDst_4[2].re;
    tmpDst_8[2].im   = tmpDst_4[0].im - tmpDst_4[2].im;
    tmpDst_8[3].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[3].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    tmpDst_4[0].re = pSrc[3].re   + pSrc[11].re;
    tmpDst_4[0].im = pSrc[3].im   + pSrc[11].im;
    tmpDst_4[1].re = pSrc[3].re   - pSrc[11].re;
    tmpDst_4[1].im = pSrc[3].im   - pSrc[11].im;
    tmpDst_4[2].re = pSrc[7].re   + pSrc[15].re;
    tmpDst_4[2].im = pSrc[7].im   + pSrc[15].im;
    tmpDst_4[3].re = pSrc[7].re   - pSrc[15].re;
    tmpDst_4[3].im = pSrc[7].im   - pSrc[15].im;
    tmpDst_16[12].re   = tmpDst_4[0].re + tmpDst_4[2].re;
    tmpDst_16[12].im   = tmpDst_4[0].im + tmpDst_4[2].im;
    tmpDst_8[5].re   = tmpDst_4[1].re + tmpDst_4[3].im;
    tmpDst_8[5].im   = tmpDst_4[1].im - tmpDst_4[3].re;
    tmpDst_16[14].im   = tmpDst_4[2].re - tmpDst_4[0].re;//!!
    tmpDst_16[14].re   = tmpDst_4[0].im - tmpDst_4[2].im;//!!
    tmpDst_8[7].re   = tmpDst_4[1].re - tmpDst_4[3].im;
    tmpDst_8[7].im   = tmpDst_4[1].im + tmpDst_4[3].re;

    tmpDst_16[13].re = (tmpDst_8[5].re + tmpDst_8[5].im) * SQRT2_1;
    tmpDst_16[13].im = (tmpDst_8[5].im - tmpDst_8[5].re) * SQRT2_1;

    tmpDst_16[15].re = (tmpDst_8[7].re - tmpDst_8[7].im) * SQRT2_1_;
    tmpDst_16[15].im = (tmpDst_8[7].im + tmpDst_8[7].re) * SQRT2_1_;

    pDst[8].re = tmpDst_8[0].re + tmpDst_16[12].re;
    pDst[8].im = tmpDst_8[0].im + tmpDst_16[12].im;
    tmpDst_16[9].re = tmpDst_8[1].re + tmpDst_16[13].re;
    tmpDst_16[9].im = tmpDst_8[1].im + tmpDst_16[13].im;
    tmpDst_16[10].re = tmpDst_8[2].re + tmpDst_16[14].re;
    tmpDst_16[10].im = tmpDst_8[2].im + tmpDst_16[14].im;
    tmpDst_16[11].re = tmpDst_8[3].re + tmpDst_16[15].re;
    tmpDst_16[11].im = tmpDst_8[3].im + tmpDst_16[15].im;

    pDst[12].re = tmpDst_8[0].im - tmpDst_16[12].im;//!!
    pDst[12].im = tmpDst_16[12].re - tmpDst_8[0].re;//!!
    tmpDst_16[13].re = tmpDst_8[1].re - tmpDst_16[13].re;
    tmpDst_16[13].im = tmpDst_8[1].im - tmpDst_16[13].im;
    tmpDst_16[14].re = tmpDst_8[2].re - tmpDst_16[14].re;
    tmpDst_16[14].im = tmpDst_8[2].im - tmpDst_16[14].im;
    tmpDst_16[15].re = tmpDst_8[3].re - tmpDst_16[15].re;
    tmpDst_16[15].im = tmpDst_8[3].im - tmpDst_16[15].im;

    pDst[9].re = tmpDst_16[9].re * CP8 + tmpDst_16[9].im * C3P8;
    pDst[9].im = tmpDst_16[9].im * CP8 - tmpDst_16[9].re * C3P8;

    pDst[10].re = (tmpDst_16[10].re + tmpDst_16[10].im) * SQRT2_1;
    pDst[10].im = (tmpDst_16[10].im - tmpDst_16[10].re) * SQRT2_1;

    pDst[11].re = tmpDst_16[11].re * C3P8 + tmpDst_16[11].im * CP8;
    pDst[11].im = tmpDst_16[11].im * C3P8 - tmpDst_16[11].re * CP8;

    pDst[13].re = tmpDst_16[13].re * C3P8_ + tmpDst_16[13].im * CP8;
    pDst[13].im = tmpDst_16[13].im * C3P8_ - tmpDst_16[13].re * CP8;

    pDst[14].re = (tmpDst_16[14].re - tmpDst_16[14].im) * SQRT2_1_;
    pDst[14].im = (tmpDst_16[14].im + tmpDst_16[14].re) * SQRT2_1_;

    pDst[15].re = tmpDst_16[15].re * CP8_ + tmpDst_16[15].im * C3P8;
    pDst[15].im = tmpDst_16[15].im * CP8_ - tmpDst_16[15].re * C3P8;


    pDst[0].re = tmpDst_16[0].re + pDst[8].re;
    pDst[0].im = tmpDst_16[0].im + pDst[8].im;
    pDst[1].re = tmpDst_16[1].re + pDst[9].re;
    pDst[1].im = tmpDst_16[1].im + pDst[9].im;
    pDst[2].re = tmpDst_16[2].re + pDst[10].re;
    pDst[2].im = tmpDst_16[2].im + pDst[10].im;
    pDst[3].re = tmpDst_16[3].re + pDst[11].re;
    pDst[3].im = tmpDst_16[3].im + pDst[11].im;
    pDst[4].re = tmpDst_16[4].re + pDst[12].re;
    pDst[4].im = tmpDst_16[4].im + pDst[12].im;
    pDst[5].re = tmpDst_16[5].re + pDst[13].re;
    pDst[5].im = tmpDst_16[5].im + pDst[13].im;
    pDst[6].re = tmpDst_16[6].re + pDst[14].re;
    pDst[6].im = tmpDst_16[6].im + pDst[14].im;
    pDst[7].re = tmpDst_16[7].re + pDst[15].re;
    pDst[7].im = tmpDst_16[7].im + pDst[15].im;

    pDst[8].re = tmpDst_16[0].re - pDst[8].re;
    pDst[8].im = tmpDst_16[0].im - pDst[8].im;
    pDst[9].re = tmpDst_16[1].re - pDst[9].re;
    pDst[9].im = tmpDst_16[1].im - pDst[9].im;
    pDst[10].re = tmpDst_16[2].re - pDst[10].re;
    pDst[10].im = tmpDst_16[2].im - pDst[10].im;
    pDst[11].re = tmpDst_16[3].re - pDst[11].re;
    pDst[11].im = tmpDst_16[3].im - pDst[11].im;
    pDst[12].re = tmpDst_16[4].re - pDst[12].re;
    pDst[12].im = tmpDst_16[4].im - pDst[12].im;
    pDst[13].re = tmpDst_16[5].re - pDst[13].re;
    pDst[13].im = tmpDst_16[5].im - pDst[13].im;
    pDst[14].re = tmpDst_16[6].re - pDst[14].re;
    pDst[14].im = tmpDst_16[6].im - pDst[14].im;
    pDst[15].re = tmpDst_16[7].re - pDst[15].re;
    pDst[15].im = tmpDst_16[7].im - pDst[15].im;

    return;
}
