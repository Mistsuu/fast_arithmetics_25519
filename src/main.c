#include <stdio.h>
#include "fast_arithmetics_142111.h"

// ============================ MAIN ============================
int main(int argc, char **argv)
{
    Int142111 x;
    Int142111 y;
    Int142111 z;
    Int142111 r;
    Int142111 w;

    rnd142111(&x);
    rnd142111(&y);
    rnd142111(&r);
    rnd142111(&w);

    prn142111(&x);
    prn142111(&y);
    prn142111(&r);
    prn142111(&w);
    
    add142111(&z, &x, &y);
    add142111(&z, &z, &r);
    add142111(&z, &z, &w);
    add142111(&z, &z, &w);
    add142111(&z, &z, &w);
    add142111(&z, &z, &w);
    add142111(&z, &z, &w);
    mul142111(&z, &z, &z);

    prn142111(&z);

    return 0;
}