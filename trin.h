#ifndef TRIN_H_INCLUDED
#define TRIN_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"triangles.h"
#include"trin.h"

using namespace std;

class Triinte: public triangle
{
    public:
    //double a;double b;
    Matrice_creuse M;
    Matrice_creuse R;
    double bl;

    Triinte()
    :triangle()
    {
        bl=(sommets[1].x-sommets[0].x)*(sommets[2].y-sommets[0].y)-(sommets[2].x-sommets[0].x)*(sommets[1].y-sommets[0].y);

    }

    Triinte(const point &U, const point &V,const point &W)
    :triangle(U,V,W),M(3,3),R(3,3)
    {
        bl=(sommets[1].x-sommets[0].x)*(sommets[2].y-sommets[0].y)-(sommets[2].x-sommets[0].x)*(sommets[1].y-sommets[0].y);

    }

    /*Triinte(const triangle &TL)
    {
        sommets[1].x=TL.sommets[1];
    }
    */
    //Triinte(const Triinte &M);
    void masse (double a=1.);
    void mprint();
    void rigid (double b=1.);
    void rprint ();
};


#endif // TRIN_H_INCLUDED
