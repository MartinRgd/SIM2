#ifndef INTP2_H
#define INTP2_H

#include "matrice_creuse.h"
#include"triangles.h"


using namespace std;

/* FONCTIONS ELEMENTAIRES */
 double omega2(int n, double x, double y); // fonction élémentaire n en (x,y)
 vector<double> grad2(int n, double x, double y);  // gradient de omega n en (x,y)


//Differentielle de la transformation
vector< vector<double> > dFl2(const vector<double> & coord); // fonction que calcule la matrice differentielle de la transformation
double jacobian_triangle(const vector<double>& coord); // fonction que calcule le jacobien la matrice differentielle de la transformation
vector< vector<double> > invdFl2(const vector<double> & coord); // fonction que calcule l'inverse de la matrice differentielle de la transformation
Matrice_creuse Cl(const vector<double> & coord); // fonction qui calcule la matrice creuse Cl pour la matrice de rigidité en les points x,y

/// MATRICES ELEMENTAIRES
double integrale_p2_masse(const vector<double> & coord, int i, int j); // calcul de l'integrale P2 pour la matrice de masse par une formule de quadrature à 7 points
double integrale_p2_rigidite(const vector<double> & coord, int i, int j);// calcul de l'integrale P2 pour la matrice de rigidite par une formule de quadrature à 7 points




// VOIR CE QU ON FAIT ENSUITE POUR CALCULER LE MATRICE DE MASSE ET CELLE DE RIGIDITE
// + TEST DES FONCTIONS

#endif // INTP2_H
