#ifndef FAST_25519
#define FAST_25519


// ============================ DEFINE STRUCT ============================
/*
    Define a 142-bit integer holder, using radix-2^47 representation.
*/
typedef struct Int142111
{
    __UINT64_TYPE__ limbs[3];
} Int142111;

// ============================ DEFINE FUNCS =============================
void mul25519(Int142111 *out, Int142111 *x, Int142111 *y);
void add25519(Int142111 *out, Int142111 *x, Int142111 *y);

#endif