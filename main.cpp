#include<iostream>
#include<vector>

#include"noeud.h"
#include "matrice_creuse.h"
#include "grad_conj.h"

using namespace std;

int main()
{
    /*Tests sur les fonctions de bases des classes Noeud et Matrice_creuse */
    {
        cout << "Test des fonctions de base" << endl;
        Noeud N1(1,1,2.);
        Noeud N2(2,2,3.);
        Noeud N3(1,2,2.);


        Matrice_creuse M(3,3);
        M.Chaine.push_back(N1);
        M.Chaine.push_back(N2);
        M.Chaine.push_back(N3);

        M.print();
        cout << "Fin print" << endl;

        vector<double> V(3);
        vector<double> R(3);
        V.at(0) = 1.;
        V.at(1) = 1.;
        V.at(2) = 1.;
        R = M*V;
        print(R);


        cout << " Test de la fonction diag" << endl;
        vector<double> Vec(3);
        Vec = diag(M);
        print(Vec);

        cout << "Fin Test des fonctions de base" << endl;
    }
    /* Tests sur le gradient conjugué préconditionné */
    {
        cout << "Test du gradient conjugué" << endl;
        // Si A est la matrice identité on doit avoir x = b
        cout << "Test identité" << endl;
        Matrice_creuse A(2,2);
        Noeud N1(1,1,1.);
        Noeud N2(2,2,1.);
        A.Chaine.push_back(N1);
        A.Chaine.push_back(N2);

        vector<double> b(2,2.);
        vector<double> x=grad_conj(A,b);
        print(x);

    }
    {

        // Si A est la matrice diagonale(1,2) on doit avoir x = [2 1]
        cout << "Test Diagonale" << endl;
        Matrice_creuse A(2,2);
        Noeud N1(1,1,1.);
        Noeud N2(2,2,2.);
        A.Chaine.push_back(N1);
        A.Chaine.push_back(N2);

        vector<double> b(2,2.);
        vector<double> x=grad_conj(A,b);
        print(x);



    }
    {

        // Si A est la matrice diagonale(1,2) on doit avoir x = [2 1]
        // NE FONCTIONNNE PAS
        cout << "Test Diagonale strictement dominante" << endl;
        Matrice_creuse A(2,2);
        Noeud N1(1,1,1.);
        Noeud N2(2,2,2.);
        Noeud N3(1,2,0.5);
        Noeud N4(2,1,0.5);
        A.Chaine.push_back(N1);
        A.Chaine.push_back(N2);
        A.Chaine.push_back(N3);
        A.Chaine.push_back(N4);

        vector<double> b(2,2.);
        vector<double> x=grad_conj(A,b);
        print(x);


        cout << "Fin Test du gradient conjugué" << endl;


    }
        return 0;
}
