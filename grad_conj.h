#ifndef GRAD_CONJ_H
#define GRAD_CONJ_H

#include<iostream>
#include<vector>
#include<cassert>
#include"matrice_creuse.h"

using namespace std;

/* FONCTIONS AUXILIAIRES */
double prod_scal(vector<double> x, vector<double> y); // Effectue le produit scalaire de x et y
vector<double> diag(Matrice_creuse M); // Fonction qui génère la Matrice_creuse diag(M)

/* ALGORITHME DU GRADIENT */
/// On veut résoudre le système linéaire Ax = b où A est notre matrice creuse
/// version avec préconditionnement

vector<double> grad_conj(const Matrice_creuse & A, const vector<double> & B);
// On choisit d'appliquer le gradient conjugué à invC*A*invC*y = inC*b
// Donc on doit multiplier le résultat par C avant de le renvoyer


#endif // GARD_CONJ_H

