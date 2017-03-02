#ifndef TRIANGLES_H
#define TRIANGLES_H

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<list>

using namespace std;

/// CLASSE POINT ///
class point
// classe qui définit u point avec son abscisse et son ordonnée
{
    public:
    double x; // abscisse
    double y; // ordonnée
    int num;  // numérotation du point dans le triangle
    point(int num0=0,double x0=0,double y0=0){num=num0;x=x0;y=y0;}; // constructeur
    point (const point &U){x=U.x; U.y;}; // constructeur par copie
};

/* OPERATEURS SUR LES POINTS */

ostream& operator<<(ostream &,const point &); // surcharge de cout
point operator + (const point&U,const point&V); // addition
point operator * (double a,const point &U); // multiplication

/// CLASSE TRIANGLE ///
class triangle
{public:
    vector<point> sommets; // vecteur contenant les sommets
    vector<point> milieux; // vecteur contenant les milieux
    triangle(const point &P1,const point &P2,const point &P3) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
    };

    triangle(const point &P1,const point &P2,const point &P3,const point &P4,const point &P5,const point &P6) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        milieux.push_back(P4);
        milieux.push_back(P5);
        milieux.push_back(P6);
    };
    point & operator()(int i){return sommets[i-1];}; // une fonction d'acces au ieme sommet
};

#endif // TRIANGLES_H
