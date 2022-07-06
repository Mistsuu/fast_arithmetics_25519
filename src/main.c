#include <stdio.h>
#include "fast_arithmetics_25519.h"

// ============================ MAIN ============================
int main(int argc, char **argv)
{
    Int25519 num1;
    Int25519 num2;
    Int25519 result;

    num1.limbs[0] = 0x68bdcffcc16d3;
    num1.limbs[1] = 0x15cb7bb8c25ba;
    num1.limbs[2] = 0x778636fe3ad4c;
    num1.limbs[3] = 0x53a800d1736e5;
    num1.limbs[4] = 0x1bbf4b8dc5d84;

    num2.limbs[0] = 0x2a54d03719354;
    num2.limbs[1] = 0x76924a12ffff6;
    num2.limbs[2] = 0x1229659a16b13;
    num2.limbs[3] = 0x761ea16c8a484;
    num2.limbs[4] = 0x55c987ed5d82d;

    add25519(&result, &num1, &num2);

    return 0;
}