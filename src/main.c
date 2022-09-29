#include <stdio.h>
#include "fast_arithmetics_142111.h"

// ============================ MAIN ============================
int main(int argc, char **argv)
{
    Int142111 x;
    Int142111 y;
    Int142111 z;

    rnd142111(&x);
    rnd142111(&y);
    mul142111(&z, &x, &y);

    prn142111(&x);
    prn142111(&y);
    prn142111(&z);

    return 0;
}