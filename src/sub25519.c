#include "fast_arithmetics_25519.h"

/*
    Define SUBTRACTION on finite field of size 2^255-19.
*/

// ============================ SUBTRACTION GF(2^255-19) ============================
void sub25519(Int25519 *out, Int25519 *x, Int25519 *y)
{
    out->limbs[0] = (x->limbs[0] + (P25519_LIMB_0<<2)) - y->limbs[0];
    out->limbs[1] = (x->limbs[1] + (P25519_LIMB_1<<2)) - y->limbs[1];
    out->limbs[2] = (x->limbs[2] + (P25519_LIMB_2<<2)) - y->limbs[2];
    out->limbs[3] = (x->limbs[3] + (P25519_LIMB_3<<2)) - y->limbs[3];
    out->limbs[4] = (x->limbs[4] + (P25519_LIMB_4<<2)) - y->limbs[4];
}