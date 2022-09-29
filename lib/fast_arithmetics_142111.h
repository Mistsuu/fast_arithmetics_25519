#ifndef FAST_142111
#define FAST_142111


// ============================ DEFINE STRUCT ============================
/*
    Define a 142-bit integer holder, using radix-2^48 representation.
*/
typedef struct Int142111
{
    __UINT64_TYPE__ limbs[3];
} Int142111;

// ============================ DEFINE FUNCS =============================
void mul142111(Int142111 *out, Int142111 *x, Int142111 *y);
void add142111(Int142111 *out, Int142111 *x, Int142111 *y);
void rand142111(Int142111 *out);

#endif