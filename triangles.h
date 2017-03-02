#ifndef TRIANGLES_H
#define TRIANGLES_H

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <cmath>
#include<sstream>
#include<vector>
#include<list>

using namespace std;

/// CLASSE POINT ///
class point
// classe qui définit un point par son abscisse et son ordonnée
{
    public:
    double x; // abscisse
    double y; // ordonnée
    int num;  // numérotation globale du point dans le maillage (!!!A PARTIR DE 1 !!!)
    point(int num0=0,double x0=0,double y0=0){num=num0;x=x0;y=y0;}; // constructeur
    point (const point &U){x=U.x; y=U.y;}; // constructeur par copie
    point & operator=(const point &); // operateur egal

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
    triangle() // constructeur par défaut
    {
        point P1(0,0.,0.);
        point P2(0,1.,0.);
        point P3(0,0.,1.);
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        type = 1;
    };

    triangle(const point &P1,const point &P2,const point &P3) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        type=1;
    };

    triangle(const point &P1,const point &P2,const point &P3,const point &P4,const point &P5,const point &P6) //constructeur prenant 6 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
        milieux.push_back(P4);
        milieux.push_back(P5);
        milieux.push_back(P6);
        type = 2;
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

    }


    point & operator()(int i){return sommets[i-1];}; // une fonction d'acces au ieme sommet
};


/* FONTIONS RELATIVES AU CALCUL DE IT */
vector<double> proj1(triangle const& T, vector<double> const& Uh)  ;  // fonction qui projette la solution Uh du modele P1 sur les trois sommets du triangle T
vector<double> proj12(triangle const& T, vector<double> const& Uh) ;  //fonction qui projette la solution du modele P1 sur les trois sommets de T puis interpole les valeurs en les milieux de cotes par la moyenne des valeurs en les sommets
vector<double> proj2(triangle const& T, vector<double> const& Uh)  ;  // fonction qui projette la solution Uh du modele P2 sur les trois sommets du triangle T et les trois milieux
double IT(triangle const& T, vector<double> const& Uh1, vector<double> const& Uh2, int h) ; //fonction qui calcule l'indicateur IT pour un triangle T donné


#endif // TRIANGLES_H
