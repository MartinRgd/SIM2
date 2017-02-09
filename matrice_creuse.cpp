#include<iostream>
#include "matrice_creuse.h"

/// IMPLEMENTATION EXTERNE DES FONCTIONS ///

// CONSTRUCTEUR //

Matrice_creuse :: Matrice_creuse(const int &l, const int & c)
// Constructeur avec dimensions
// IN : -l, un entier representant le nombre de lignes
//      -c, nbre de colonnes
{
    //cout << "const Matrice_creuse dim" << endl;
    nbLi = l;
    nbCo = c;
}

void Matrice_creuse :: print()
// Affiche la liste chainee
{
    vector<Noeud> :: iterator it;

    for(it=Chaine.begin(); it !=Chaine.end(); it++)
    {
        it->print();
    }
}


/* Version const de print()*/
void Matrice_creuse :: print() const
// Affiche la liste chainee
{
    vector<Noeud> :: const_iterator it;
    const vector<Noeud> & Chaine = (*this).get_Chaine();

    for(it=Chaine.begin(); it !=Chaine.end(); it++)
    {
        it->print();
    }
}


/* FONCTIONS D'ACCES CONST */

int Matrice_creuse :: Li() const
// fonction qui permet de lire et ecrire dans le nbre de lignes max
{
    return nbLi;
}

int Matrice_creuse :: Co() const
// fonction qui permet de lire et ecrire dans le nbre de colonnes max
{
    return nbCo;
}

vector<double> operator*(const Matrice_creuse M, const vector<double>& V)
// fonction qui surcharge le produit matrice vecteur
// IN  : -M Une matrice creuse sous forme de liste chainee,ATTENTION on suppose qu'elle est triee ! (en fait pas sur, je pense que ça marche tout le temps)
//       -V Un vecteur de la classe vector<double> de la STL
// OUT : - Un vector<double> de la STL correspondant au produit de M par V

{
    // On s'assure que le produit est possible
    assert(M.Co() == V.size());

    // Si tout va bien on lance le produit
    vector<double> res(M.Li()) ;
    const vector<Noeud> & Chaine = M.get_Chaine();
    vector<Noeud> :: const_iterator it;
    int i,j;

    for(it = Chaine.begin(); it != Chaine.end(); it++)
    {
        // on recupere la ligne et la colonne associees au noeud
        i = it->li()-1;
        j = it->co()-1;
        res.at(i) += (it->val())*V.at(j);
    }

    return res;
}

/// OPERATEURS SUR LES VECTEURS

void print(vector<double> x)
// Affiche le vector x
{
    cout<< "[" ;
    for(int i =0; i<x.size(); i++)
        cout << x.at(i) << " ";
    cout <<"]"<< endl;
}

vector<double> operator+(vector<double> a, vector<double> b)
// Addition
{
    assert(a.size() == b.size());
    unsigned int n = a.size();
    vector<double> res = a;

    for(int i=0;i<n;i++)
        res.at(i) += b.at(i);

    return res;
}

vector<double> operator-(vector<double> a)
// Operateur unaire de l'opposé
{
    vector<double> res(a.size());
    for (int i=0; i < a.size();i++)
        res.at(i)=-a.at(i);

    return res;
}

vector<double> operator-(vector<double> a, vector<double> b)
// Soustraction
{
    return a + (-b);
}

vector<double> operator*(double a, vector<double> X)
// Multiplication par un scalaire terme à terme
{
    vector<double> res(X.size());
    for(int i=0; i<X.size(); i++)
        res.at(i)=a*X.at(i);

    return res;
}


vector<double> operator/(vector<double> x, vector<double> y)
// X/Y effectue la division terme à terme de X par Y
{
    assert(x.size() == y.size());
    unsigned int n = x.size();
    vector<double> res = x;

    for(int i=0;i<n;i++)
        res.at(i) /= y.at(i);

    return res;
}

double ps(vector<double> x, vector<double> y)
// Produit scalaire
{
    assert(x.size()==y.size());
    double res =0.;

    for(int i=0; i<x.size(); i++)
        res+= x.at(i)*y.at(i);

    return res;
}


