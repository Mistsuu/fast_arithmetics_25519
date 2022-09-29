#include "local_asm.h"
#include "fast_arithmetics_142111.h"

/*
    Define multiplication on finite field of size 2^255-19.
*/

// ============================ DEFINE REGISTERS AND SUB-FUNCTIONS ============================

// Registers used for multiplying limbs
#define R0 "%r8"
#define R1 "%r9"
#define R2 "%r10"

// Registers that store constants
#define R_0xffffffffffff "%r12" // Stores 0xffffffffffff

// Operands, mini-functions you might call it
#define MUL_LIMB00(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "16")               \
    AND(RLMUL, R_0xffffffffffff)           \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define MUL_LIMB0C(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "16")               \
    AND(RLMUL, R_0xffffffffffff)           \
    ADD(LREG, RLMUL)                       \
    MOV(RLMUL, RHMUL)                      \
    IMUL(RLMUL, RLMUL, "444")              \
    ADD(HREG, RLMUL)

#define MUL_LIMBCC(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    IMUL(RLMUL, RLMUL, "444")              \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "16")               \
    AND(RLMUL, R_0xffffffffffff)           \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define CARRY(LREG, HREG)        \
    MOV(RLMUL, LREG)             \
    AND(LREG, R_0xffffffffffff)  \
    SAR(RLMUL, "48")             \
    ADD(HREG, RLMUL)

#define CARRY444(LREG, HREG)     \
    MOV(RLMUL, LREG)             \
    AND(LREG, R_0xffffffffffff)  \
    SAR(RLMUL, "48")             \
    IMUL(RLMUL, RLMUL, "444")    \
    ADD(HREG, RLMUL)


// ============================ MULTIPLY IN GF(2^255-19) ============================

void mul25519(Int142111 *out, Int142111 *x, Int142111 *y)
{
    __asm__ __volatile__(
        // "nop;"

            // Clean registers first
            XOR(R0, R0)
            XOR(R1, R1)
            XOR(R2, R2)

            // Set the register "RMSK (user-defined)" to 0xffffffffffff
            // to save space
            IMOV(R_0xffffffffffff, "0xffffffffffff")

            // Good ol' multiply by assembly...
            MUL_LIMB00(R0, R1, "0", "0")   // x0*y0
            MUL_LIMB00(R1, R2, "0", "8")   // x0*y1
            MUL_LIMB0C(R2, R0, "0", "16")  // x0*y2

            MUL_LIMB00(R1, R2, "8", "0")   // x1*y0
            MUL_LIMB0C(R2, R0, "8", "8")   // x1*y1
            MUL_LIMBCC(R0, R1, "8", "16")  // x1*y2

            MUL_LIMB0C(R2, R0, "16", "0")  // x2*y0
            MUL_LIMBCC(R0, R1, "16", "8")  // x2*y1
            MUL_LIMBCC(R1, R2, "16", "16") // x2*y2

            // Performs carry
            CARRY444(R2, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)
            CARRY444(R2, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)
            CARRY444(R2, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)

            // Move to result
            PMOV("0", "0",  R0)
            PMOV("0", "8",  R1)
            PMOV("0", "16", R2)

        // "nop;"
            :
            : "r"(out->limbs), "r"(x->limbs), "r"(y->limbs)
            : R0, R1, R2,
              RLMUL, RHMUL,
              R_0xffffffffffff
    );
}