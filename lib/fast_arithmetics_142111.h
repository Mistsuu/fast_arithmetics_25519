#ifndef FAST_25519
#define FAST_25519


// ============================ DEFINE STRUCT ============================
/*
    Define a 255-bit integer holder, using radix-2^51 representation.
*/
typedef struct Int25519
{
    __UINT64_TYPE__ limbs[5];
} Int25519;

/*
    Define the number 2^255-19 in radix-2^51 form.
*/
#define P25519_LIMB_0 0x7ffffffffffed
#define P25519_LIMB_1 0x7ffffffffffff
#define P25519_LIMB_2 0x7ffffffffffff
#define P25519_LIMB_3 0x7ffffffffffff
#define P25519_LIMB_4 0x7ffffffffffff

// ============================ DEFINE FUNCS =============================
void mul25519(Int25519 *out, Int25519 *x, Int25519 *y);
void add25519(Int25519 *out, Int25519 *x, Int25519 *y);

#endif