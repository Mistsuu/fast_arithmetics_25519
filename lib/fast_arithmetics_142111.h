#ifndef FAST_25519
#define FAST_25519


// ============================ DEFINE STRUCT ============================
/*
    Define a 255-bit integer holder, using radix-2^51 representation.
*/
typedef struct Int142111
{
    __UINT64_TYPE__ limbs[5];
} Int142111;

/*
    Define the number 2^255-19 in radix-2^51 form.
*/
#define P25519_LIMB_0 0x7ffffffffffed
#define P25519_LIMB_1 0x7ffffffffffff
#define P25519_LIMB_2 0x7ffffffffffff
#define P25519_LIMB_3 0x7ffffffffffff
#define P25519_LIMB_4 0x7ffffffffffff

// ============================ DEFINE FUNCS =============================
void mul25519(Int142111 *out, Int142111 *x, Int142111 *y);
void add25519(Int142111 *out, Int142111 *x, Int142111 *y);

#endif