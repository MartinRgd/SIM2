#include<iostream>
#include<vector>
#include<cassert>
#include"matrice_creuse.h"

using namespace std;

/* FONCTIONS AUXILIAIRES */
double prod_scal(vector<double> x, vector<double> y)
// Effectue le produit scalaire de x et y
{
    assert (x.size()==y.size()); // On s'assure que le produit scalaire est posible
    double res =0;
    for(int i=0; i < x.size(); i++)
        res += x.at(i)*y.at(i);
    return res;
}

vector<double> diag(Matrice_creuse M)
// Fonction qui génère la Matrice_creuse diag(M)
{
    vector<double> C(M.Li(),0);
    vector<Noeud> :: iterator it;
    int i,j;

    for(it = M.Chaine.begin(); it != M.Chaine.end(); it++)
    {
        // On recupère le numero de ligne et de colonne
        i = it->li()-1;
        j = it->co()-1;
        // On teste si on est sur la diagonale
        if (i==j)
        {
            C[i]+=(it->val());
        }
    }

    return C;
}




/* ALGORITHME DU GRADIENT */
/// On veut résoudre le système linéaire Ax = b où A est notre matrice creuse

/// version AVEC préconditionnement

vector<double> grad_conj(const Matrice_creuse & A, const vector<double> & B)
// Effectue l'algorithme du gradient avec un critère d'arrêt de 10^(-6)
// IN :  - A une matrice creuse SYMETRIQUE
//       - B un vecteur de second membre
// OUT : - x un vecteur tel que Ax = B
{
    /// Paramètres
    double epsilon = 1E-6; // critère d'arrêt
    vector<double> u0 =vector<double>(B.size(),0.);// On part de x0 = 0 car pas d'infos spéciales

    /// Initialisation

    // Matrice de préconditionnement
    vector<double> C;
    C = diag(A); // On prend la diagonale de A
    cout << "C" << endl;
    print(C);
    cout << "A" << endl;
    A.print();

    // Nouveau second membre preconditionné
    vector<double> b = B/C;


    // Outils de l'algorithme
    vector<double> Cu0 = u0/C;
    vector<double> Cz = A*Cu0;
    vector<double> z = Cz/C;


    vector<double> r0 = b - z; // residu numero k (avec k initialisé à 0)
    vector<double> d0 = r0; // première direction de descente
    vector<double> r1 ; // residu numero k+1
    vector<double> Cd0 ; // vecteur auxiliaire


    // Paramètres scalaires
    double alpha; // paramètre optimal de descente
    double beta; // paramètre de conjugaison optimal
    int k= 0;

    double norm0=ps(r0,r0); // Normes des résidus
    double norm1;

    /// Boucle de gradient

    while(norm0> epsilon) // on garde k pour compter le nombre d'iterations
    {
        // Calcul de z =K*d où K est la direction de descente
        Cd0 = d0/C;
        //cout<< "Cd0" << endl;
        //print(Cd0);
        Cz = A*Cd0;
        //cout << "Cz" << endl;
        //print(Cz);
        z = Cz/C;


        alpha = norm0/ps(d0,z);
        u0 = u0 + alpha*d0;
        r1 = r0 - alpha*z;

        norm1 = ps(r1,r1);
        //if(ps(r1,r1)>epsilon) // On effectue le test d'arret
        //{
            beta = ps(r1,r1)/ps(r0,r0);
            d0 = r1 + beta*d0; // nouvelle direction de descente si le test d'arret n'est pas vérifié
        //}
        k++;
        r0 = r1;
        norm0 = ps(r0,r0);
        cout << k <<"  "<< norm0 << endl;

    }
    return u0/C;
}


