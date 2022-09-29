#include "local_asm.h"
#include "fast_arithmetics_142111.h"
#include <stdio.h>

/*
    Define DISPLAY of element on finite field of size 2^142-111.
*/

// ============================ DISPLAY GF(2^142-111) ============================
void prn142111(Int142111 *in)
{
    if (in)
        printf("0x%lx%012lx%012lx\n", 
                    in->limbs[2],
                    in->limbs[1],
                    in->limbs[0]
              );
}