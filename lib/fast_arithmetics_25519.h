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

// ============================ DEFINE FUNCS =============================
void mul25519(Int25519 *out, Int25519 *x, Int25519 *y);
void sqr25519(Int25519 *out, Int25519 *x);
void inv25519(Int25519 *out, Int25519 *x);
void sqrt25519(Int25519 *out, Int25519 *x);
void pow25519(Int25519 *out, Int25519 *x, Int25519 *y);

#endif