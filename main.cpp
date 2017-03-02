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
#include"intP2.h"

using namespace std;



int main()
{
    //test de la part de matrice

        Noeud N1(0,1,2.);
        Noeud N2(2,1,3.);

        Matrice_creuse M(3,3);
        M.Chaine.push_back(N1);
        M.Chaine.push_back(N2);

        M.print();
        cout << "fin print" << endl;
        vector<double> V(3);
        vector<double> R(3);
        V.at(0) = 1.;
        V.at(1) = 2.;
        V.at(2) = 1.;
        cout << "ok" << endl;
        R = M*V;
        cout <<"Res : "<< R.at(0) << "," << R.at(1) << "," << R.at(2) << endl;

        Noeud NN1(0,1,2.);
        Noeud NN2(2,2,4.);

        Matrice_creuse M1(3,3);
        M1.Chaine.push_back(NN1);
        M1.Chaine.push_back(NN2);
        M1.print();
        //cout<<M1.get_val(2,2)<<endl;

        cout<<"partie de matrice_creuse ok"<<endl;

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

    cout<<"partie d'integrale 1 ok"<<endl;

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

    cout<<"partie d'assemblage 1 ok"<<endl;

    point n5(5,0.5,0.);
    point n6(6,0.5,0.5);
    point n7(7,0.,0.5);
    Triinte ti2(n1,n2,n3,n5,n6,n7);
    cout<<ti2.sommets[2].y<<endl;
    //cout<<"yeah"<<endl;


    cout<<ti2.bl<<endl;
    cout<<ti2.sommets[5].y<<endl;
    cout<<ti2.type<<endl;
    ti2.masse();
    ti2.mprint();
    ti2.rigid();
    ti2.rprint();

    cout<<ti2.coord[5]<<endl;
    double testm=integrale_p2_masse(ti2.coord, 5, 6);
    //double testr=integrale_p2_rigidite(ti2.coord, 5, 6);
    cout<<testm<<endl;

    cout<<"partie d'integrale 2"<<endl;
    point r1(1,0.,0.);
    point r2(2,1.,0.);
    point r3(3,0.5,1.);
    point r4(4,0.5,0.);
    point r5(5,0.75,0.5);
    point r6(6,0.25,0.5);
    Triinte ti3(r1,r2,r3,r4,r5,r6);
    //cout<<"yeah"<<endl;


    cout<<ti3.bl<<endl;
    cout<<ti3.milieux[2].x<<endl;
    cout<<ti3.type<<endl;
    double test = integrale_p2_rigidite(ti3.coord,4,5);
    cout << 'test =' << test << endl;
    ti3.masse();
    ti3.mprint();
    ti3.rigid();
    ti3.rprint();

    cout<<ti3.coord[4]<<endl;
    double testm2=integrale_p2_masse(ti3.coord, 4, 5);
    double testr2=integrale_p2_rigidite(ti3.coord, 4, 5);
    cout<<testm2<<endl;

    cout<<"partie d'integrale 2 ok"<<endl;



    cout << "It runs!" << endl;
    return 0;
}

//on a list<triangle> et Nbp
//Assemblage AA(Nbp);
//AA.assembler(TT);

