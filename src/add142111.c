#include "local_asm.h"
#include "fast_arithmetics_142111.h"

/*
    Define ADDITION on finite field of size 2^255-19.
*/

// ============================ ADDITION GF(2^255-19) ============================
void add25519(Int142111 *out, Int142111 *x, Int142111 *y)
{
    out->limbs[0] = x->limbs[0] + y->limbs[0];
    out->limbs[1] = x->limbs[1] + y->limbs[1];
    out->limbs[2] = x->limbs[2] + y->limbs[2];
}