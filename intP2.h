#ifndef INTP2_H
#define INTP2_H

#include"triangles.h"

using namespace std;

/* FONCTIONS ELEMENTAIRES */
 double omega2(int n, double x, double y); // fonction élémentaire n en (x,y)
 vector<double> grad2(int n, double x, double y);  // gradient de omega n en (x,y)

// VOIR CE QU ON FAIT ENSUITE POUR CALCULER LE MATRICE DE MASSE ET CELLE DE RIGIDITE


#endif // INTP2_H
