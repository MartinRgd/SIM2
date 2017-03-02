#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include <cstdlib>
#include <cmath>
#include<vector>
#include<list>

#include "triangles.h"

using namespace std;

/* OPERATEURS SUR LES POINTS */
point & point::operator=(const point &U)
{
   x=U.x;y=U.y;num=U.num;
   return *this;
}
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
// surcharge de l'op¨¦rateur d'affichage
{
    out<<"("<<U.x<<","<<U.y<<")";
    return out;
}
