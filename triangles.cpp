#include "triangles.h"

using namespace std;

/* OPERATEURS SUR LES POINTS */


point & point::operator=(const point &U)
//egalite
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
// surcharge de l'opérateur d'affichage
{
    out<<"("<<U.x<<","<<U.y<<")";
    return out;
}


/* FONCTIONS RELATIVES AU CALCUL DE IT */

vector<double> proj1(triangle const& T, vector<double> const& Uh)
// fonction qui projette la solution Uh du modele P1 sur les trois sommets du triangle T
//IN  : - T le triangle désiré,
//      - Uh, le vecteur solution du systeme P1
//OUT : - UhT un vecteur de R^3 qui contient les valeurs aux trois sommets
{
    vector<double> UhT(3,0);
    int ind; // stockera l'indice du sommet du triangle

    for(int i(0); i<3; i++)
    {
        ind = T.sommets.at(i).num; // numerotation globale du point dans le maillage (numéroté à partir de 1)
        UhT.at(i) = Uh.at(ind-1);  // on prend ind-1 car la numerotation ind commence à 1
    }

    return UhT;
}

vector<double> proj12(triangle const& T, vector<double> const& Uh)
//fonction qui projette la solution du modele P1 sur les trois sommets de T puis interpole les valeurs en les milieux de cotes par la moyenne des valeurs en les sommets
//IN  : - T le triangle désiré,
//      - Uh, le vecteur solution du systeme P1
//OUT : - UhT un vecteur de R^6 qui contient les valeurs aux trois sommets ainsi que les valeurs en les milieux (estimées par moyenne des valeurs aux sommets)
{
    vector<double> UhT(3,0);
    int ind; // stockera l'indice du sommet du triangle

    /* BOUCLE POUR LES SOMMETS */
    for(int i(0); i<3; i++)
    {
        ind = T.sommets.at(i).num; // numerotation globale du point dans le maillage (numéroté à partir de 1)
        UhT.at(i) = Uh.at(ind-1);  // on prend ind-1 car la numerotation ind commence à 1
    }

    UhT.at(3) = (UhT.at(0)+UhT.at(1))/2;
    UhT.at(4) = (UhT.at(1)+UhT.at(2))/2;
    UhT.at(5) = (UhT.at(0)+UhT.at(2))/2;



}

vector<double> proj2(triangle const& T, vector<double> const& Uh)
// fonction qui projette la solution Uh du modele P2 sur les trois sommets du triangle T et les trois milieux
//IN  : - T le triangle désiré,
//      - Uh, le vecteur solution du systeme P2
//OUT : - UhT un vecteur de R^6 qui contient les valeurs aux trois sommets
{

    vector<double> UhT(6,0);
    int ind; // stockera l'indice du sommet du triangle

    for(int i(0); i<6; i++)
    {
        ind = T.sommets.at(i).num; // numerotation globale du point dans le maillage (numéroté à partir de 1)
        UhT.at(i) = Uh.at(ind-1);  // on prend ind-1 car la numerotation ind commence à 1
    }

    return UhT;

}

double IT(triangle const& T, vector<double> const& Uh1, vector<double> const& Uh2, int h)
//fonction qui calcule l'indicateur IT pour un triangle T donné
//IN  : - T le triangle désiré,
//      - Uh1, le vecteur solution du systeme P1
//      - Uh2, le vecteur solution du systeme P2
//      - h, le parametre du maillage
//OUT : - IT, l'indicateur IT du triangle T donné
{
   cout << "MODIFIER LA FONCTION IT AVEC LA MATRICE DE K" << endl;
   return 0.5;

}
