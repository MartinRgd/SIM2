#ifndef MATRICE_CREUSE_H
#define MATRICE_CREUSE_H

#include<iostream>
#include <vector>
#include <cassert>
#include"noeud.h"

using namespace std;

class Matrice_creuse
// Classe matrice creuse sous forme d'une liste chainee de Noeuds
{
    // ATTRIBUTS
    private :
        int nbLi, nbCo;  // Nombre de Lignes et de Colonnes max de la matrice

    public:

        vector<Noeud> Chaine;

        /* CONSTRUCTEUR ET PRINT*/
        Matrice_creuse(const int & l= 0, const int & c=0);
        void print();

        /* FONCTIONS D'ACCES CONST*/
        int Li() const;
        int Co() const;
        const vector<Noeud> & get_Chaine() const {return Chaine;};

    /* FONCTIONS FRIENDS */
    friend vector<double> operator*(const Matrice_creuse M, const vector<double> &V); // fonction qui surcharge le produit matrice vecteur
    friend vector<double> diag(Matrice_creuse M); // Fonction qui génère la Matrice_creuse diag(M)

};

/// Operateurs sur les vecteurs ///
void print(vector<double> x);                                 // Affiche le vector x
vector<double> operator+(vector<double> a, vector<double> b); // Addition des vector<double>
vector<double> operator-(vector<double> a);                   // Operateur unaire de l'opposé
vector<double> operator-(vector<double> a, vector<double> b); // Soustraction pour les vecteurs a-b NON SYMETRIQUE
vector<double> operator*(double a, vector<double> X);         // multiplication par un scalaire
vector<double> operator/(vector<double> x, vector<double> y); // X/Y effectue la division terme à terme de X par Y
double ps(vector<double> x, vector<double> y);                // Produit scalaire


#endif // MATRICE_CREUSE_H
