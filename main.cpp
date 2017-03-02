#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"triangles.h"
#include"trin.h"
#include"assemblage.h"

using namespace std;



int main()
{
    //test de la part de matrice

        Noeud N1(1,1,2.);
        Noeud N2(2,2,3.);

        Matrice_creuse M(3,3);
        M.Chaine.push_back(N1);
        M.Chaine.push_back(N2);

        M.print();
        cout << "fin print" << endl;
        vector<double> V(3);
        vector<double> R(3);
        V.at(0) = 1.;
        V.at(1) = 1.;
        V.at(2) = 1.;
        cout << "ok" << endl;
        R = M*V;
        cout <<"Res : "<< R.at(0) << "," << R.at(1) << "," << R.at(2) << endl;

        Noeud NN1(0,1,2.);
        Noeud NN2(2,2,4.);

        Matrice_creuse M1(3,3);
        M1.Chaine.push_back(NN1);
        M1.Chaine.push_back(NN2);
        M+=M1;
        M.print();
        cout<<M.get_val(2,2)<<endl;

        cout<<"part de matrice_creuse ok"<<endl;

    //test de la part d'integrale

    point n1(1,0.,0.);
    point n2(2,1.,0.);
    point n3(3,0.,1.);
    cout<<n3.y<<endl;
    //triangle tr(n1,n2,n3);
    //point test;
    //test=tr.sommets[0];
   // cout<<test.y;
    //cout<<tr.sommets[0].y<<endl;
    Triinte ti(n1,n2,n3);
    cout<<ti.sommets[2].y<<endl;
    cout<<"yeah"<<endl;


    cout<<ti.bl<<endl;
    cout<<ti.sommets[0].y;
    ti.masse();
    ti.mprint();
    ti.rigid();
    ti.rprint();

    cout<<"part d'integrale ok"<<endl;

    //test de la part assemblage

    point n4(4,1.,1.);
    triangle t1(n1,n2,n3);
    triangle t2(n2,n3,n4);
    list<triangle> TT;
    TT.push_back(t1);
    TT.push_back(t2);
    Assemblage A(4);
    A.assembler(TT);
    A.MM.print();
    A.RR.print();

    cout<<"part d'assemblage ok"<<endl;


    cout << "It runs!" << endl;
    return 0;
}

//on a list<triangle> et Nbp
//Assemblage AA(Nbp);
//AA.assembler(TT);

