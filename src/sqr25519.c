#include "local_asm.h"
#include "fast_arithmetics_25519.h"

/*
    Define squaring on finite field of size 2^255-19.
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
#define selfMUL_LIMB00(LREG, HREG, Xi)     \
    MOV(RLMUL, Xi)                         \
    MUL(RLMUL)                             \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define selfMUL_LIMB0C(LREG, HREG, Xi)     \
    MOV(RLMUL, Xi)                         \
    MUL(RLMUL)                             \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(LREG, RLMUL)                       \
    MOV(RLMUL, RHMUL)                      \
    IMUL(RLMUL, RLMUL, "19")               \
    ADD(HREG, RLMUL)

#define selfMUL_LIMBCC(LREG, HREG, Xi)     \
    MOV(RLMUL, Xi)                         \
    IMUL(RLMUL, RLMUL, "19")               \
    MUL(Xi)                                \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define dbleMUL_LIMB00(LREG, HREG, Xi, Xj) \
    MOV(RLMUL, Xi)                         \
    SAL(RLMUL, "1")                        \
    MUL(Xj)                                \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(HREG, RHMUL)                       \
    ADD(LREG, RLMUL)

#define dbleMUL_LIMB0C(LREG, HREG, Xi, Xj) \
    MOV(RLMUL, Xi)                         \
    SAL(RLMUL, "1")                        \
    MUL(Xj)                                \
    SHLD(RHMUL, RLMUL, "13")               \
    AND(RLMUL, R_0x7ffffffffffff)          \
    ADD(LREG, RLMUL)                       \
    MOV(RLMUL, RHMUL)                      \
    IMUL(RLMUL, RLMUL, "19")               \
    ADD(HREG, RLMUL)

#define dbleMUL_LIMBCC(LREG, HREG, Xi, Xj) \
    MOV(RLMUL, Xi)                         \
    IMUL(RLMUL, RLMUL, "38")               \
    MUL(Xj)                                \
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


// ============================ SQUARING IN GF(2^255-19) ============================
void sqr25519(Int25519 *out, Int25519 *x)
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
            selfMUL_LIMB00(R0, R1, "0")             // x0*x0
            dbleMUL_LIMB00(R1, R2, "0", "1")        // x0*x1*2
            dbleMUL_LIMB00(R2, R3, "0", "2")        // x0*x2*2
            dbleMUL_LIMB00(R3, R4, "0", "3")        // x0*x3*2
            dbleMUL_LIMB0C(R4, R0, "0", "4")        // x0*x4*2
            selfMUL_LIMB00(R2, R3, "1")             // x1*x1
            dbleMUL_LIMB00(R3, R4, "1", "2")        // x1*x2*2
            dbleMUL_LIMB0C(R4, R0, "1", "3")        // x1*x3*2
            dbleMUL_LIMBCC(R0, R1, "1", "4")        // x1*x4*2
            selfMUL_LIMB0C(R4, R0, "2")             // x2*x2
            dbleMUL_LIMBCC(R0, R1, "2", "3")        // x2*x3*2
            dbleMUL_LIMBCC(R1, R2, "2", "4")        // x2*x4*2
            selfMUL_LIMBCC(R1, R2, "3")             // x3*x3
            dbleMUL_LIMBCC(R2, R3, "3", "4")        // x3*x4*2
            selfMUL_LIMBCC(R3, R4, "4")             // x4*x4


            // Performs carry
            CARRY19(R4, R0)
            CARRY(R0, R1)
            CARRY(R1, R2)
            CARRY(R2, R3)
            CARRY(R3, R4)

            // Move to result
            PMOV("5", "0",  R0)
            PMOV("5", "8",  R1)
            PMOV("5", "16", R2)
            PMOV("5", "24", R3)
            PMOV("5", "32", R4)

        // "nop;"
            :
            : "r"(x->limbs[0]), "r"(x->limbs[1]), "r"(x->limbs[2]), "r"(x->limbs[3]), "r"(x->limbs[4]), "r"(out->limbs)
            : R0, R1, R2, R3, R4,
              RLMUL, RHMUL,
              R_0x7ffffffffffff
    );
}