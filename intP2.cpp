#include "intP2.h"
#include <cassert>
#include <cmath>

using namespace std;

/* IMPLEMENTATION DES FONCTIONS ELEMENTAIRES */

double omega2(int n, double x, double y)
// fonction élémentaire n en (x,y)
// IN : - n, un entier entre 1 et 6 qui designe quel omega on utilise
//      -x,y, coordonnées d'évaluation de la fonction
// OUT: - un double qui est l'évaluation en (x,y) de omega n
{
   switch(n)
   {
       case 1:
        return (1-x-y)*(1-2*x-2*y);
        break;

       case 2:
        return x*(2*x-1);
        break;

       case 3:
        return y*(2*y-1);
        break;

       case 4:
        return 4*x*(1-x-y);
        break;

       case 5:
        return 4*x*y;
        break;

       case 6:
        return 4*y*(1-x-y);
        break;
   }

}

vector<double> grad2(int n, double x, double y)
// gradient de omega n en (x,y)
// IN : - n, un entier entre 1 et 6 qui designe quel omega on utilise
//      -x,y, coordonnées d'évaluation de la fonction
//OUT:  - vector de double qui ets le gradient de omega n en (x,y)
{
    vector<double> grad(2);
   switch(n)
   {
       case 1:
        grad[0] = 4*(x+y)-3;
        grad[1] = 4*(x+y)-3;
        break;

       case 2:
        grad[0] = 4*x-1;
        grad[1] = 0;
        break;

       case 3:
        grad[0] = 0;
        grad[1] = 4*y-1;
        break;

       case 4:
        grad[0] = 4-4*y-8*x;
        grad[1] = -4*x;
        break;

       case 5:
        grad[0] = 4*y;
        grad[1] = 4*x;
        break;

       case 6:
        grad[0] = -4*y;
        grad[1] = 4-4*x-8*y;
        break;
   }

    return grad;
}



//DIFFERENTIELLE DE LA TRANSFORMATION

vector< vector<double> > dFl2(const vector<double> & coord)
// fonction que calcule la matrice differentielle de la transformation
// IN : - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - un vecteur des lignes (vector<double>) de la matrice differentielle de la transformation
{
    vector<double> l1,l2;
    //Ligne 1
    l1.push_back(-coord.at(0)+coord.at(2));
    l1.push_back(-coord.at(0)+coord.at(4));
    //Ligne 2
    l2.push_back(-coord.at(1)+coord.at(3));
    l2.push_back(-coord.at(1)+coord.at(5));

    //Assemblage
    vector< vector<double> > M;
    M.push_back(l1);
    M.push_back(l2);

    return M;
}


double jacobian_triangle(const vector<double> & coord)
// fonction que calcule le jacobien la matrice differentielle de la transformation
// IN : - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - un double qui est le jacobien de la matrice differentielle de la transformation
{
    return -coord.at(0)*coord.at(5)-coord.at(2)*coord.at(1)+coord.at(2)*coord.at(5)+coord.at(1)*coord.at(4)-coord.at(3)*coord.at(0)+coord.at(1)*coord.at(4);
}

vector< vector<double> > invdFl2(const vector<double> & coord)
// fonction que calcule l'inverse de la matrice differentielle de la transformation
// IN : - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - un vecteur des lignes (vector<double>) de la matrice differentielle de la transformation
{
    // calcul du déterminant et on vérifie qu'il n'est pas nul
    double J = jacobian_triangle(coord);
    assert(J!=0);

    vector<double> l1,l2;
    //Ligne 1
    l1.push_back((-coord.at(1)+coord.at(5))/J);
    l1.push_back((coord.at(0)-coord.at(4))/J);
    //Ligne 2
    l2.push_back((coord.at(1)-coord.at(3))/J);
    l2.push_back((-coord.at(0)+coord.at(2))/J);

    //Assemblage
    vector< vector<double> > M;
    M.push_back(l1);
    M.push_back(l2);

    return M;
}


Matrice_creuse Cl(const vector<double> & coord)
// fonction qui calcule la matrice creuse Cl pour la matrice de rigidité en les points x,y
// IN : - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - une matrice creuse constante
{
    vector < vector <double> > MI ;
    MI = invdFl2(coord); // inverse de dFl

    Noeud N1(1,1, (MI.at(0)).at(0)*(MI.at(0)).at(0) + (MI.at(0)).at(1)*(MI.at(0)).at(1) );
    Noeud N2(1,2, (MI.at(0)).at(0)*(MI.at(1)).at(0) + (MI.at(0)).at(1)*(MI.at(1)).at(1) );
    Noeud N3(2,1, (MI.at(0)).at(0)*(MI.at(1)).at(0) + (MI.at(1)).at(1)*(MI.at(1)).at(1) );
    Noeud N4(2,2, (MI.at(1)).at(0)*(MI.at(1)).at(0) + (MI.at(1)).at(1)*(MI.at(1)).at(1) );

    Matrice_creuse C(2,2);
    C.get_Chaine().push_back(N1);
    C.get_Chaine().push_back(N2);
    C.get_Chaine().push_back(N3);
    C.get_Chaine().push_back(N4);

    return C;

}

/// MATRICES ELEMENTAIRES

/// MATRICE DE MASSE

double integrale_p2_masse(const vector<double> & coord, int i, int j)
// calcul de l'integrale P2 pour la matrice de masse par une formule de quadrature à 7 points
// IN : - i,j, des entiers entre 1 et 6 tels que l'on calcule intégrale de omega(i)*omega(j)
//      - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - l'intégrale P2 voulue
{
    // Coordonnes des points pour la quadrature
    double s0,s1,s2,s3,s4;
    s0 = 1/3;
    s1 = (6-sqrt(15))/21;
    s2 = (6+sqrt(15))/21;
    s3 = (9+2*sqrt(15))/21;
    s4 = (9-2*sqrt(15))*21;

    // Definition des vecteurs de abscisses et des ordonnées de points de la formule
    vector <double> absc; // ABSCISSES
    vector <double> ord;  // ORDONNEES

    absc.push_back(s0);ord.push_back(s0);
    absc.push_back(s1);ord.push_back(s1);
    absc.push_back(s1);ord.push_back(s3);
    absc.push_back(s3);ord.push_back(s1);
    absc.push_back(s2);ord.push_back(s2);
    absc.push_back(s2);ord.push_back(s4);
    absc.push_back(s4);ord.push_back(s2);

    // POIDS
    int n0, n1, n2;
    n0 = 9/80; n1 = (155-sqrt(15))/2400; n2=(155+sqrt(15))/2400;

    //Vecteur des poids
    vector <double> w; // POIDS
    w.push_back(n0);
    w.push_back(n1);
    w.push_back(n1);
    w.push_back(n1);
    w.push_back(n2);
    w.push_back(n2);
    w.push_back(n2);

    // FORMULE DE QUADRATURE
    double inte =0;

    for(int k=0; k<7; k++)
    {
        inte += omega2(i,absc.at(k),ord.at(k))*omega2(j,absc.at(k),ord.at(k))*w.at(k);
    }

    return inte;

}


/// MATRICE DE RIGIDITE


double integrale_p2_rigidite(const vector<double> & coord, int i, int j)
// calcul de l'integrale P2 pour la matrice de rigidité par une formule de quadrature à 7 points
// IN : - i,j, des entiers entre 1 et 6 tels que l'on calcule intégrale de grad_omega(i)*grad_omega(j)
//      - coord, un vecteur de doubles des coordonnées des sommets du triangles
//               [x1,y1,x2,y2,x3,y3]
//OUT : - l'intégrale P2 voulue
{
    // Coordonnes des points pour la quadrature
    double s0,s1,s2,s3,s4;
    s0 = 1/3;
    s1 = (6-sqrt(15))/21;
    s2 = (6+sqrt(15))/21;
    s3 = (9+2*sqrt(15))/21;
    s4 = (9-2*sqrt(15))*21;

    // Definition des vecteurs de abscisses et des ordonnées de points de la formule
    vector <double> absc; // ABSCISSES
    vector <double> ord;  // ORDONNEES

    absc.push_back(s0);ord.push_back(s0);
    absc.push_back(s1);ord.push_back(s1);
    absc.push_back(s1);ord.push_back(s3);
    absc.push_back(s3);ord.push_back(s1);
    absc.push_back(s2);ord.push_back(s2);
    absc.push_back(s2);ord.push_back(s4);
    absc.push_back(s4);ord.push_back(s2);

    // POIDS
    int n0, n1, n2;
    n0 = 9/80; n1 = (155-sqrt(15))/2400; n2=(155+sqrt(15))/2400;

    //Vecteur des poids
    vector <double> w; // POIDS
    w.push_back(n0);
    w.push_back(n1);
    w.push_back(n1);
    w.push_back(n1);
    w.push_back(n2);
    w.push_back(n2);
    w.push_back(n2);

    // FORMULE DE QUADRATURE
    Matrice_creuse C = Cl(coord);
    double J = jacobian_triangle(coord);
    vector<double> grad_i;
    vector<double> grad_j;


    double inte =0;

    for(int k=0; k<7; k++)
    {
        grad_i = grad2(i,absc.at(k),ord.at(k));
        grad_j = grad2(j,absc.at(k),ord.at(k));
        inte += ps(C*grad_i,grad_j)*abs(J)*w.at(k);
    }

    return inte;

}
