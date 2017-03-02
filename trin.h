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
#include"intP2.h"

using namespace std;

class Triinte: public triangle
{
    public:
    //double a;double b;
    Matrice_creuse M;
    Matrice_creuse R;
    double bl;
    vector<double> coord;

    /*Triinte()
    :triangle()
    {
        switch(type)
          {
             case 1:
             bl=(sommets[1].x-sommets[0].x)*(sommets[2].y-sommets[0].y)-(sommets[2].x-sommets[0].x)*(sommets[1].y-sommets[0].y);
             break;

             case 2:
             bl=jacobian_triangle(sommets);
             break;

          };
    }*/

    Triinte(const point &P1, const point &P2,const point &P3)
    :triangle(P1,P2,P3),M(3,3),R(3,3)
    {
             bl=(sommets[1].x-sommets[0].x)*(sommets[2].y-sommets[0].y)-(sommets[2].x-sommets[0].x)*(sommets[1].y-sommets[0].y);

    }

    Triinte(const point &P1,const point &P2,const point &P3,const point &P4,const point &P5,const point &P6)
    :triangle(P1,P2,P3,P4,P5,P6),M(6,6),R(6,6)
    {
             for(int i=0;i<3;i++)
              {
                 coord.push_back(sommets[i].x);
                 coord.push_back(sommets[i].y);
              }
             bl=jacobian_triangle(coord);

    }
    Triinte(const triangle &T)
    :triangle(T),M(type*3,type*3),R(type*3,type*3)
    {
            if (type=1)
            {
                bl=(sommets[1].x-sommets[0].x)*(sommets[2].y-sommets[0].y)-(sommets[2].x-sommets[0].x)*(sommets[1].y-sommets[0].y);
            }
            else
            {
                for(int i=0;i<3;i++)
                 {
                   coord.push_back(sommets[i].x);
                   coord.push_back(sommets[i].y);
                 }
                bl=jacobian_triangle(coord);
            }

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
