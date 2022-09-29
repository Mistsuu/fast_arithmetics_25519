#include "local_asm.h"
#include "fast_arithmetics_142111.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Define SET ELEMENT on finite field of size 2^142-111.
*/

// ============================ SET ELEMENT GF(2^142-111) ============================
void set142111(Int142111 *out, const char* in_base_16)
{
    if (!out || strlen(in_base_16) == 0)
        return;

    // Set limb_str
    char limb_str[37];
    limb_str[36] = '\0';
    if (in_base_16[0] == '0' && in_base_16[1] == 'x')
        memcpy(limb_str, &in_base_16[2], sizeof(limb_str) - 1);
    else
        memcpy(limb_str, in_base_16, sizeof(limb_str) - 1);

    // Get values
    int l = strlen(limb_str);
    int i = 0;
    for (; l > 12; l -= 12) {
        out->limbs[i++] = strtol(&limb_str[l-12], NULL, 16);
        limb_str[l-12] = '\0';
    }

    // Get remain
    if (l) {
        out->limbs[i++] = strtol(limb_str, NULL, 16);
    }

    // Set remain to 0
    for (; i < 3; ++i) {
        out->limbs[i] = 0;
    }
}