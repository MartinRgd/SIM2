#include<iostream>
#include<vector>
#include<cassert>
#include"matrice_creuse.h"

using namespace std

/* FONCTIONS AUXILIAIRES */
double prod_scal(vector<double> x, vector<double> y)
{
    assert (x.size()==y.size()); // On s'assure que le produit scalaire est posible
    double res =0;
    for(int i=0; i < x.size(); i++)
        res += x.at(i)*y.at(i);
    return res;
}

/// On veut résoudre le système linéaire Ax = b où A est notre matrice creuse

/// version sans préconditionnement

vector<double> grad_conj(Matrice_creuse A, vector<double> b)
{
    /// Initialisation
    vector<double> xo =0;// On part de x0 = 0 car pas d'infos spéciales
    vector<double> r0 = b-A*xo;
    vector<double> p0 = r0;
    int k = 0;

   // while
    return x0
}

