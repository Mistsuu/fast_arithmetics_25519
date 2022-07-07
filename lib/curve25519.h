#ifndef CURVE_25519
#define CURVE_25519

#include "local_asm.h"
#include "fast_arithmetics_25519.h"

// ============================ DEFINE STRUCT ============================

/*
    Define a point of Edwards curve Ed25519.
                (x:y)
    Here, we will store y and sign bit s as
    an alternative to the upper.
*/
typedef struct PointEd25519
{
    Int25519 y;
    int s;
} PointEd25519;

/*
    Define a point of Mongomery curve Curve25519.
                     (u:v:w)
    Here, we will store u and w only.
*/
typedef struct PointMo25519
{
    Int25519 u;
    Int25519 w;
} PointMo25519;

/*
    Define Curve25519 & Ed25519.
*/
typedef struct Curve25519
{
    PointEd25519 Bed;   // Base point in Edwards Curve
    PointMo25519 Bmo;   // Base point in Mongomery Curve
    Int25519 p;         // Field prime         
    Int25519 q;         // Order of base point B
    Int25519 c;         // Cofactor
    Int25519 d;         // Twisted Edwards Curve constant
    Int25519 A;         // Mongomery Curve constant
    Int25519 n;         // Nonsquare integer modulo p
    int bp;             // ceil(log2(p))
    int bq;             // ceil(log2(q))
    int b;              // 8 * (ceil((bp + 1) / 8))

} Curve25519;

// ============================ DEFINE FUNCS =============================
void convertToEd25519(PointMo25519* in, PointEd25519* out);
void initCurve(Curve25519* curve);
void uADD(PointMo25519* P, PointMo25519* Q, PointMo25519* P_Q, PointMo25519* R);
void uDBL(PointMo25519* P, PointMo25519* R);

#endif