#include "local_asm.h"
#include "fast_arithmetics_25519.h"

/*
    Define SUBTRACTION on finite field of size 2^255-19.
*/

// ============================ SUBTRACTION GF(2^255-19) ============================
void sub25519(Int25519 *out, Int25519 *x, Int25519 *y)
{
    out->limbs[0] = x->limbs[0] + P_LIMB_0 - y->limbs[0];
    out->limbs[1] = x->limbs[1] + P_LIMB_1 - y->limbs[1];
    out->limbs[2] = x->limbs[2] + P_LIMB_2 - y->limbs[2];
    out->limbs[3] = x->limbs[3] + P_LIMB_3 - y->limbs[3];
    out->limbs[4] = x->limbs[4] + P_LIMB_4 - y->limbs[4];
}