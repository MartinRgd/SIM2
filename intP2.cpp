#include "intP2.h"

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
        return 4*(x-1)*(x-0.5)*(y-1)*(y-0.5);
        break;

       case 2:
        return 2*x*(x-0.5);
        break;

       case 3:
        return 2*y*(y-0.5);
        break;

       case 4:
        return 8*(x-1)*x*(y-0.5);
        break;

       case 5:
        return -8*x*(x-1)*y;
        break;

       case 6:
        return -8*(x-0.5)*(x-1)*y*(y-1);
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
        grad[0] = 4*(y-1)*(y-0.5)*(2*x-1.5);
        grad[1] = 4*(x-1)*(x-0.5)*(2*y-1.5);
        break;

       case 2:
        grad[0] = 2*(2*x-0.5);
        grad[1] = 0;
        break;

       case 3:
        grad[0] = 0;
        grad[1] = 2*(2*y-0.5);
        break;

       case 4:
        grad[0] = 8*(y-0.5)*(2*x-1);
        grad[1] = 8*(x-1)*x;
        break;

       case 5:
        grad[0] = -8*(2*x-1)*y;
        grad[1] = -8*x*(x-1);
        break;

       case 6:
        grad[0] = -8*y*(y-1)*(2*x-1.5);
        grad[1] = -8*(x-0.5)*(x-1)*(2*y-1);
        break;
   }

    return grad;
}
