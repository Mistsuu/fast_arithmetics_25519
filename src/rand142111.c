#include "local_asm.h"
#include "fast_arithmetics_142111.h"
#include <stdio.h>

/*
    Define RANDOM on finite field of size 2^142-111.
*/

// ============================ RANDOM GF(2^142-111) ============================
void rand142111(Int142111 *out)
{
    if (!out)
        return;

    // Read random values from file
    FILE* fptr = fopen("/dev/urandom", "r");
    fread(out, sizeof(Int142111), 1, fptr);
    fclose(fptr);

    // Chop down output
    out->limbs[0] &= 0xffffffffffff;
    out->limbs[1] &= 0xffffffffffff;
    out->limbs[2] &= 0xffffffffffff;
}