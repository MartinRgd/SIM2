#include<iostream>
#include"noeud.h"

using namespace std;

/// IMPLEMENTATION EXTERNE DES FONCTIONS ///

void Noeud :: print()
// fonction qui affiche le triplet
{
    cout << "[" << Li << "," << Co << ",Val="<< Val << "]" << endl;
}

void Noeud :: print() const
// version const fonction qui affiche le triplet
{
    cout << "[" << Li << "," << Co << ",Val="<< Val << "]" << endl;
}



/* Fonctions d'acces */

//Version non const

int & Noeud :: li()
{
    return Li;
}

int & Noeud :: co()
{
    return Co;
}


double & Noeud :: val()
{
     return Val;
}


// Version const
int Noeud :: li() const
{
    return Li;
}

int Noeud :: co() const
{
    return Co;
}

double Noeud :: val() const
{
     return Val;
}
