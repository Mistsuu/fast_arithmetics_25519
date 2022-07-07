#include <stdio.h>
#include "fast_arithmetics_25519.h"
#include "curve25519.h"

// ============================ MAIN ============================
int main(int argc, char **argv)
{
    Curve25519 curve;
    initCurve(&curve);

    PointMo25519 P = {
        {9, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };
    PointMo25519 R;

    uDBL(&P, &R);
    printf("0x%lx\n", R.u.limbs[0]);
    printf("0x%lx\n", R.u.limbs[1]);
    printf("0x%lx\n", R.u.limbs[2]);
    printf("0x%lx\n", R.u.limbs[3]);
    printf("0x%lx\n", R.u.limbs[4]);

    printf("0x%lx\n", R.w.limbs[0]);
    printf("0x%lx\n", R.w.limbs[1]);
    printf("0x%lx\n", R.w.limbs[2]);
    printf("0x%lx\n", R.w.limbs[3]);
    printf("0x%lx\n", R.w.limbs[4]);

    return 0;
}