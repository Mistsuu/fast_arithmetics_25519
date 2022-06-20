#ifndef LOCAL_ASM
#define LOCAL_ASM

// ========================== Common registers ==========================
#define RLMUL "%rax"
#define RHMUL "%rdx"

// ========================== Common commands ===========================
#define NOP "nop;"
#define MOV(dstreg, srcreg)                                 "mov %" srcreg ", %" dstreg ";"
#define IMOV(dstreg, value)                                 "mov $" value ", %" dstreg ";"
#define MOVP(dstreg, srcreg, offset)                        "mov " offset "(%" srcreg "), %" dstreg ";"
#define PMOV(dstreg, offset, srcreg)                        "mov %" srcreg ", " offset "(%" dstreg ");"
#define MUL(srcreg)                                         "mul %" srcreg ";"
#define INC(srcreg)                                         "inc %" srcreg ";"
#define DEC(srcreg)                                         "dec %" srcreg ";"
#define XOR(dstreg, srcreg)                                 "xor %" srcreg ", %" dstreg ";"
#define ADD(dstreg, srcreg)                                 "add %" srcreg ", %" dstreg ";"
#define IADD(dstreg, value)                                 "add $" value ", %" dstreg ";"
#define ISUB(dstreg, value)                                 "sub $" value ", %" dstreg ";"
#define SAR(dstreg, shiftAmount)                            "sar $" shiftAmount ", %" dstreg ";"
#define SAL(dstreg, shiftAmount)                            "sal $" shiftAmount ", %" dstreg ";"
#define SHLD(dstreg, srcreg, shiftAmount)                   "shld $" shiftAmount ", %" srcreg ", %" dstreg ";"
#define AND(dstreg, srcreg)                                 "and %" srcreg ", %" dstreg ";"
#define IMUL(dstreg, srcreg, value)                         "imul $" value ", %" srcreg ", %" dstreg ";"
#define RET "ret;"



#endif