#include "local_asm.h"
#include "fast_arithmetics_25519.h"

/*
    Define multiplication on finite field of size 2^255-19.
*/

// ============================ DEFINE REGISTERS AND SUB-FUNCTIONS ============================

// Registers used for multiplying limbs
#define R0 "%r8"
#define R1 "%r9"
#define R2 "%r10"
#define R3 "%r11"
#define R4 "%r12"

// Registers that store constants
#define R_0x7ffffffffffff "%r15" // Stores 0x7ffffffffffff

// Operands, mini-functions you might call it
#define MUL_LIMB00(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define MUL_LIMB0C(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(LREG, RLMUL)                       \
    MOV(RLMUL, RHMUL)                      \
    IMUL(RLMUL, RLMUL, "19")               \
    ADD(HREG, RLMUL)

#define MUL_LIMBCC(LREG, HREG, offX, offY) \
    MOVP(RLMUL, "1", offX)                 \
    MOVP(RHMUL, "2", offY)                 \
    IMUL(RLMUL, RLMUL, "19")               \
    MUL(RHMUL)                             \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define CARRY(LREG, HREG)        \
    MOV(RLMUL, LREG)             \
    AND(LREG, R_0x7ffffffffffff) \
    SAR(RLMUL, "51")             \
    ADD(HREG, RLMUL)

#define CARRY19(LREG, HREG)      \
    MOV(RLMUL, LREG)             \
    AND(LREG, R_0x7ffffffffffff) \
    SAR(RLMUL, "51")             \
    IMUL(RLMUL, RLMUL, "19")     \
    ADD(HREG, RLMUL)


// ============================ MULTIPLY IN GF(2^255-19) ============================

void mul25519(Int25519 *out, Int25519 *x, Int25519 *y)
{
    __asm__ __volatile__(
        // "nop;"

            // Clean registers first
            XOR(R0, R0)
            XOR(R1, R1)
            XOR(R2, R2)
            XOR(R3, R3)
            XOR(R4, R4)

            // Set the register "RMSK (user-defined)" to 0x7ffffffffffff
            // to save space
            IMOV(R_0x7ffffffffffff, "0x7ffffffffffff")

            // Good ol' multiply by assembly...
            MUL_LIMB00(R0, R1, "0", "0")   // x0*y0
            MUL_LIMB00(R1, R2, "0", "8")   // x0*y1
            MUL_LIMB00(R2, R3, "0", "16")  // x0*y2
            MUL_LIMB00(R3, R4, "0", "24")  // x0*y3
            MUL_LIMB0C(R4, R0, "0", "32")  // x0*y4

            MUL_LIMB00(R1, R2, "8", "0")   // x1*y0
            MUL_LIMB00(R2, R3, "8", "8")   // x1*y1
            MUL_LIMB00(R3, R4, "8", "16")  // x1*y2
            MUL_LIMB0C(R4, R0, "8", "24")  // x1*y3
            MUL_LIMBCC(R0, R1, "8", "32")  // x1*y4

            MUL_LIMB00(R2, R3, "16", "0")  // x2*y0
            MUL_LIMB00(R3, R4, "16", "8")  // x2*y1
            MUL_LIMB0C(R4, R0, "16", "16") // x2*y2
            MUL_LIMBCC(R0, R1, "16", "24") // x2*y3
            MUL_LIMBCC(R1, R2, "16", "32") // x2*y4

            MUL_LIMB00(R3, R4, "24", "0")  // x3*y0
            MUL_LIMB0C(R4, R0, "24", "8")  // x3*y1
            MUL_LIMBCC(R0, R1, "24", "16") // x3*y2
            MUL_LIMBCC(R1, R2, "24", "24") // x3*y3
            MUL_LIMBCC(R2, R3, "24", "32") // x3*y4

            MUL_LIMB0C(R4, R0, "32", "0")  // x4*y0
            MUL_LIMBCC(R0, R1, "32", "8")  // x4*y1
            MUL_LIMBCC(R1, R2, "32", "16") // x4*y2
            MUL_LIMBCC(R2, R3, "32", "24") // x4*y3
            MUL_LIMBCC(R3, R4, "32", "32") // x4*y4

            // Performs carry
            CARRY19(R4, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)
            CARRY(R2, R3)
            CARRY(R3, R4)
            CARRY19(R4, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)
            CARRY(R2, R3)
            CARRY(R3, R4)
            // CARRY19(R4, R0)
            // CARRY(R0, R1)
            // CARRY(R1, R2)
            // CARRY(R2, R3)
            // CARRY(R3, R4)

            // Move to result
            PMOV("0", "0",  R0)
            PMOV("0", "8",  R1)
            PMOV("0", "16", R2)
            PMOV("0", "24", R3)
            PMOV("0", "32", R4)

        // "nop;"
            :
            : "r"(out->limbs), "r"(x->limbs), "r"(y->limbs)
            : R0, R1, R2, R3, R4,
              RLMUL, RHMUL,
              R_0x7ffffffffffff
    );
}