#include "fast_arithmetics_25519.h"

/*
    Define square root on finite field of size 2^255-19.
    Code stolen idea from https://cr.yp.to/ecdh.html
*/

// ============================ SQUAREROOT IN GF(2^255-19) ============================
void sqrt25519(Int25519 *out, Int25519 *x)
{
    Int25519 x2;
    Int25519 x9;
    Int25519 x2_5_0;
    Int25519 x2_10_0;
    Int25519 x2_20_0;
    Int25519 x2_50_0;
    Int25519 x2_100_0;
    Int25519 t0;
    Int25519 out2;

    /* 2              */ sqr25519(&x2,x);
    /* 4              */ sqr25519(&t0,&x2);
    /* 8              */ sqr25519(&t0,&t0);
    /* 9              */ mul25519(&x9,&t0,x);
    /* 11             */ mul25519(&t0,&x9,&x2);
    /* 22             */ sqr25519(&t0,&t0);
    /* 2^5 - 2^0 = 31 */ mul25519(&x2_5_0,&t0,&x9);

    /* 2^6 - 2^1      */ sqr25519(&t0,&x2_5_0);
    /* 2^7 - 2^2      */ sqr25519(&t0,&t0);
    /* 2^8 - 2^3      */ sqr25519(&t0,&t0);
    /* 2^9 - 2^4      */ sqr25519(&t0,&t0);
    /* 2^10 - 2^5     */ sqr25519(&t0,&t0);
    /* 2^10 - 2^0     */ mul25519(&x2_10_0,&t0,&x2_5_0);

    /* 2^11 - 2^1     */ sqr25519(&t0,&x2_10_0);
    /* 2^12 - 2^2     */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
    /* 2^20 - 2^10    */ sqr25519(&t0,&t0);
    /* 2^20 - 2^0     */ mul25519(&x2_20_0,&t0,&x2_10_0);

    /* 2^21 - 2^1     */ sqr25519(&t0,&x2_20_0);
    /* 2^22 - 2^2     */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);                         
                         sqr25519(&t0,&t0);
    /* 2^40 - 2^20    */ sqr25519(&t0,&t0);
    /* 2^40 - 2^0     */ mul25519(&t0,&t0,&x2_20_0);

    /* 2^41 - 2^1     */ sqr25519(&t0,&t0);
    /* 2^42 - 2^2     */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0);
    /* 2^50 - 2^10    */ sqr25519(&t0,&t0);
    /* 2^50 - 2^0     */ mul25519(&x2_50_0,&t0,&x2_10_0);

    /* 2^51 - 2^1     */ sqr25519(&t0,&x2_50_0);
    /* 2^52 - 2^2     */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
    /* 2^100 - 2^50   */ sqr25519(&t0,&t0);
    /* 2^100 - 2^0    */ mul25519(&x2_100_0,&t0,&x2_50_0);

    /* 2^101 - 2^1    */ sqr25519(&t0,&x2_100_0);
    /* 2^102 - 2^2    */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
    /* 2^200 - 2^100  */ sqr25519(&t0,&t0);
    /* 2^200 - 2^0    */ mul25519(&t0,&t0,&x2_100_0);

    /* 2^201 - 2^1    */ sqr25519(&t0,&t0);
    /* 2^202 - 2^2    */ sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
                         sqr25519(&t0,&t0);
                         sqr25519(&t0,&t0); 
    /* 2^250 - 2^50   */ sqr25519(&t0,&t0);
    /* 2^250 - 2^0    */ mul25519(&t0,&t0,&x2_50_0);

    /* 2^251 - 2^1    */ sqr25519(&t0,&t0);
    /* 2^252 - 2^2    */ sqr25519(&t0,&t0);
    /* 2^252 - 2^1    */ mul25519(out,&t0,&x2);
}