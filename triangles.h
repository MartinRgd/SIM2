#ifndef TRIANGLES_H_INCLUDED
#define TRIANGLES_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include <cstdlib>
#include <cmath>
#include<vector>
#include<list>

using namespace std;

/// CLASSE POINT ///
class point
// classe qui d¨¦finit u point avec son abscisse et son ordonn¨¦e
{
    public:
    int num;  // num¨¦rotation du point dans le triangle
    double x; // abscisse
    double y; // ordonn¨¦e
    point(int num0=0,double x0=0.,double y0=0.){num=num0;x=x0;y=y0;}; // constructeur
    point (const point &U){num=U.num;x=U.x; y=U.y;}; // constructeur par copie
    point & operator=(const point &);
};

/* OPERATEURS SUR LES POINTS */

ostream& operator<<(ostream &,const point &); // surcharge de cout
point operator + (const point&U,const point&V); // addition
point operator * (double a,const point &U); // multiplication

/// CLASSE TRIANGLE ///
class triangle
{public:
    int type;
    vector<point> sommets; // vecteur contenant les sommets
    vector<point> milieux; // vecteur contenant les milieux
    /*triangle()
    {
        point P1(0,0.,0.);
        point P2(0,1.,0.);
        point P3(0,0.,1.);
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
    };*/
    triangle(const point &P1,const point &P2,const point &P3) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        type=1;
    };

    triangle(const point &P1,const point &P2,const point &P3,const point &P4,const point &P5,const point &P6) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        milieux.push_back(P4);
        milieux.push_back(P5);
        milieux.push_back(P6);
        type=2;
    };

    triangle(const triangle &T)
    {
        sommets.push_back(T.sommets[0]);
        sommets.push_back(T.sommets[1]);
        sommets.push_back(T.sommets[2]);
        type=1;
        if((T.milieux.size())!=0)
        {
            milieux.push_back(T.milieux[0]);
            milieux.push_back(T.milieux[1]);
            milieux.push_back(T.milieux[2]);
            type=2;
        }

    };
    point & operator()(int i){return sommets[i-1];}; // une fonction d'acces au ieme sommet
};


#endif // TRIANGLES_H_INCLUDED
