#include "local_asm.h"
#include "fast_arithmetics_142111.h"
#include <stdio.h>

/*
    Define RANDOM on finite field of size 2^142-111.
*/

// ============================ RANDOM GF(2^142-111) ============================
void rnd142111(Int142111 *out)
{
    if (!out)
        return;

    // Read random values from file
    FILE* fptr;
    int   bytesRead;
    fptr      = fopen("/dev/urandom", "r");
    bytesRead = fread(&out->limbs[0], sizeof(__UINT64_TYPE__), 1, fptr);
    bytesRead = fread(&out->limbs[1], sizeof(__UINT64_TYPE__), 1, fptr);
    bytesRead = fread(&out->limbs[2], sizeof(__UINT64_TYPE__), 1, fptr);
    fclose(fptr);

    // Chop down output
    out->limbs[0] &= 0xffffffffffff;
    out->limbs[1] &= 0xffffffffffff;
    out->limbs[2] &= 0x3fffffffffff;
}