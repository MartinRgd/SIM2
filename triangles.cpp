#include "triangles.h"

using namespace std;

/* OPERATEURS SUR LES POINTS */

point operator + (const point&U,const point&V)
// addition
{
    point W(U);
    W.x+=V.x;
    W.y+=V.y;
    return W;
}

point operator * (double a,const point &U)
// multiplication par un scalaire
{
    point W(U);
    W.x*=a;
    W.y*=a;
    return W;
}

ostream & operator <<(ostream & out,const point &U)
// surcharge de l'opérateur d'affichage
{
    out<<"("<<U.x<<","<<U.y<<")";
    return out;
}
