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


    return 0;
}