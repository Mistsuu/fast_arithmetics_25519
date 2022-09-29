#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fast_arithmetics_142111.h"

#define NCOLS 10000
#define NROWS 10000

Int142111* mat1;
Int142111* mat2;
#define M1(irow, icol)         mat1[(irow) * NCOLS + (icol)]
#define M2(irow, icol)         mat2[(irow) * NCOLS + (icol)]
#define M1L(irow, icol, ilimb) mat1[(irow) * NCOLS + (icol)].limbs[ilimb]
#define M2L(irow, icol, ilimb) mat2[(irow) * NCOLS + (icol)].limbs[ilimb]

Int142111* createMatrix()
{
    Int142111* tmpMat = (Int142111*)malloc(NROWS * NCOLS * sizeof(Int142111));
    memset(tmpMat, 0, NROWS * NCOLS * sizeof(Int142111));
    return tmpMat;
}

void init()
{
    mat1 = createMatrix(NROWS, NCOLS);
    mat2 = createMatrix(NROWS, NCOLS);
    for (int i = 0; i < 9999; ++i)
        set142111(&M1(i, i+1), "0x1");
    
    set142111(&M1(9999, 0), "");
}

void cleanup()
{
    free(mat2);
    free(mat1);
}

// ======================== ARITHMETICS =========================

void sqrMatrix()
{

}

// ============================ MAIN ============================
int main(int argc, char **argv)
{
    init();
    // --------------- logic here --------------------

    Int142111 x;
    set142111(&x, "0x123abcd3242494232952305893");
    prn142111(&x);

    // -----------------------------------------------
    cleanup();
    return 0;
}