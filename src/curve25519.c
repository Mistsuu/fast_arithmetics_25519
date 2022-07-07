#include "fast_arithmetics_25519.h"
#include "curve25519.h"
#include <string.h>
#include <stdio.h>

/*  ------------- convertToEd25519() -------------
*   Convert point on Mongomery curve to corresponding point on Edward curve.
*/
void convertToEd25519(PointMo25519* in, PointEd25519* out)
{
    Int25519 u1;
    Int25519 u2;
    memcpy(u1.limbs, in->u.limbs, sizeof(Int25519));
    memcpy(u2.limbs, in->u.limbs, sizeof(Int25519));

    // Obtain u-1
    u1.limbs[0] += P25519_LIMB_0 - 1;
    u1.limbs[1] += P25519_LIMB_1;
    u1.limbs[2] += P25519_LIMB_2;
    u1.limbs[3] += P25519_LIMB_3;
    u1.limbs[4] += P25519_LIMB_4;
    // Obtain u+1
    u2.limbs[0]++;

    // Calculate (u-1)/(u+1)
    inv25519(&u2, &u2);
    mul25519(&out->y, &u1, &u2);
    
    // Force sign-bit to 0
    out->s = 0;
}

/*  ------------- initCurve() -------------
*   Initialize variables for Curve25519.
*/
void initCurve(Curve25519* curve)
{
    // Curve25519.Bmo
    curve->Bmo.u.limbs[0] = 9;
    curve->Bmo.u.limbs[1] = 0;
    curve->Bmo.u.limbs[2] = 0;
    curve->Bmo.u.limbs[3] = 0;
    curve->Bmo.u.limbs[4] = 0;
    curve->Bmo.w.limbs[0] = 1;
    curve->Bmo.w.limbs[1] = 0;
    curve->Bmo.w.limbs[2] = 0;
    curve->Bmo.w.limbs[3] = 0;
    curve->Bmo.w.limbs[4] = 0;

    // Curve25519.p
    curve->p.limbs[0] = P25519_LIMB_0;
    curve->p.limbs[1] = P25519_LIMB_1;
    curve->p.limbs[2] = P25519_LIMB_2;
    curve->p.limbs[3] = P25519_LIMB_3;
    curve->p.limbs[4] = P25519_LIMB_4;

    // Curve25519.q
    curve->q.limbs[0] = 0x2631a5cf5d3ed;
    curve->q.limbs[1] = 0x3d45ef39acb02;
    curve->q.limbs[2] = 0x537be7;
    curve->q.limbs[3] = 0x0;
    curve->q.limbs[4] = 0x1000000000000;

    // Curve25519.c
    curve->c.limbs[0] = 4;
    curve->c.limbs[1] = 0;
    curve->c.limbs[2] = 0;
    curve->c.limbs[3] = 0;
    curve->c.limbs[4] = 0;

    // Curve25519.d
    curve->d.limbs[0] = 0x34dca135978a3;
    curve->d.limbs[1] = 0x1a8283b156ebd;
    curve->d.limbs[2] = 0x5e7a26001c029;
    curve->d.limbs[3] = 0x739c663a03cbb;
    curve->d.limbs[4] = 0x52036cee2b6ff;

    // Curve25519.A
    curve->A.limbs[0] = 486662;
    curve->A.limbs[1] = 0;
    curve->A.limbs[2] = 0;
    curve->A.limbs[3] = 0;
    curve->A.limbs[4] = 0;
    
    // Curve25519.n
    curve->n.limbs[0] = 2;
    curve->n.limbs[1] = 0;
    curve->n.limbs[2] = 0;
    curve->n.limbs[3] = 0;
    curve->n.limbs[4] = 0;

    // Curve25519.bp
    curve->bp = 255;
    // Curve25519.bq
    curve->bp = 253;
    // Curve25519.n
    curve->b = 256;

    // Curve25519.Bmo
    convertToEd25519(&curve->Bmo, &curve->Bed);
}

/*  ------------- uADD() -------------
*   Computes P+Q -> R on Mongomery curve knowing P-Q
*/
void uADD(PointMo25519* P, PointMo25519* Q, PointMo25519* P_Q, PointMo25519* R)
{
    Int25519 V0,V1,V2,V3,V4,xR,zR;
    add25519(&V0, &P->u, &P->w);
    sub25519(&V1, &Q->u, &Q->w);
    mul25519(&V1, &V1, &V0);
    sub25519(&V0, &P->u, &P->w);
    add25519(&V2, &Q->u, &Q->w);
    mul25519(&V2, &V2, &V0);
    add25519(&V3, &V1, &V2);
    sqr25519(&V3, &V3);
    sub25519(&V4, &V1, &V2);
    sqr25519(&V4, &V4);
    mul25519(&R->u, &P_Q->w, &V3);
    mul25519(&R->w, &P_Q->u, &V4);
}



/*  ------------- uDBL() -------------
*   Computes 2P -> R on Mongomery curve
*/
void uDBL(PointMo25519* P, PointMo25519* R)
{
    Int25519 V1,V2,V3,xR,zR,A2={121666,0,0,0,0};
    add25519(&V1, &P->u, &P->w);
    sqr25519(&V1, &V1);
    sub25519(&V2, &P->u, &P->w);
    sqr25519(&V2, &V2);
    mul25519(&R->u, &V1, &V2);
    sub25519(&V1, &V1, &V2);
    mul25519(&V3, &A2, &V1);
    add25519(&V3, &V3, &V2);
    mul25519(&R->w, &V1, &V3);
}