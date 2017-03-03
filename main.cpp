#include<iostream>
#include<vector>

#include"noeud.h"
#include "matrice_creuse.h"
#include "grad_conj.h"
#include "triangles.h"
#include "trin.h"
#include "intP2.h"
#include "assemblage.h"

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
        M.get_Chaine().push_back(N1);
        M.get_Chaine().push_back(N2);
        M.get_Chaine().push_back(N3);

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
    /* Tests sur le gradient conjugu¨¦ pr¨¦conditionn¨¦ */
    {
        cout << "Test du gradient conjugu¨¦" << endl;
        // Si A est la matrice identit¨¦ on doit avoir x = b
        cout << "Test identit¨¦" << endl;
        Matrice_creuse A(2,2);
        Noeud N1(1,1,1.);
        Noeud N2(2,2,1.);
        A.get_Chaine().push_back(N1);
        A.get_Chaine().push_back(N2);

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
        A.get_Chaine().push_back(N1);
        A.get_Chaine().push_back(N2);

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
        A.get_Chaine().push_back(N1);
        A.get_Chaine().push_back(N2);
        A.get_Chaine().push_back(N3);
        A.get_Chaine().push_back(N4);
        A.print();

        vector<double> b(2,2.);
        vector<double> x=grad_conj(A,b);
        print(x);


        cout << "Fin Test du gradient conjugu¨¦" << endl;


    }

    //test de la part d'integrale

    point n1(1,0.,0.);
    point n2(2,1.,0.);
    point n3(3,0.,1.);
    Triinte ti(n1,n2,n3);
    triangle tr(n1,n2,n3);
    Triinte tii(tr);

    cout<<ti.bl<<endl;
    cout<<ti.sommets[2].y;
    ti.masse();
    ti.mprint();
    ti.rigid();
    ti.rprint();

    cout<<"partie d'integrale 1 ok"<<endl;

    //test de la part assemblage
    vector<point> sommet;
    sommet.push_back(n3);
    cout<<"point test "<<n3.num<<endl;
    cout<<"ex test "<<sommet[0].num<<endl;


    point n4(4,1.,1.);
    cout<<"num"<<n3.num<<endl;
    triangle t1(n1,n2,n3);
    cout<<"num tri"<<t1.sommets[2].num<<endl;
    triangle t2(n2,n3,n4);
    cout<<"num tri"<<t2.sommets[2].num<<endl;
    cout<<"x tri"<<t2.sommets[2].x<<endl;
    cout<<"y tri"<<t2.sommets[2].y<<endl;
    list<triangle> TT;
    TT.push_back(t1);
    TT.push_back(t2);
    Assemblage A(4);
    A.assembler(TT);
    A.MM.print();
    A.RR.print();

    cout<<"partie d'assemblage 1 ok"<<endl;

    point n5(4,0.5,0.);
    point n6(5,0.5,0.5);
    point n7(6,0.,0.5);
    Triinte ti2(n1,n2,n3,n5,n6,n7);
    cout<<ti2.bl<<endl;
    cout<<ti2.sommets[5].y<<endl;
    cout<<ti2.type<<endl;
    ti2.masse();
    ti2.mprint();
    ti2.rigid();
    ti2.rprint();

    cout<<ti2.coord[5]<<endl;
    //double testm=integrale_p2_masse(ti2.coord, 5, 6);
    //double testr=integrale_p2_rigidite(ti2.coord, 5, 6);
    //cout<<testm<<endl;

    cout<<"partie d'integrale 2 ok"<<endl;
    point r1(1,0.,0.);
    point r2(2,1.,0.);
    point r3(3,0.5,1.);
    point r4(4,0.5,0.);
    point r5(5,0.75,0.5);
    point r6(6,0.25,0.5);
    Triinte ti3(r1,r2,r3,r4,r5,r6);


    cout<<ti3.bl<<endl;
    cout<<ti3.milieux[2].x<<endl;
    cout<<ti3.type<<endl;
   // double test = integrale_p2_rigidite(ti3.coord,4,5);
   // cout << 'test =' << test << endl;
    ti3.masse();
    ti3.mprint();
    ti3.rigid();
    ti3.rprint();

    cout<<ti3.coord[4]<<endl;
    double testm2=integrale_p2_masse(ti3.coord, 4, 5);
    double testr2=integrale_p2_rigidite(ti3.coord, 4, 5);
    cout<<testr2<<endl;

    cout<<"partie d'integrale 2 ok2"<<endl;

    //test de la part assemblage 2


    triangle tri2(n1,n2,n3,n5,n6,n7);
    cout<<"num tri"<<tri2.sommets[2].num<<endl;
    cout<<"x tri"<<tri2.sommets[2].x<<endl;
    cout<<"y tri"<<tri2.sommets[2].y<<endl;
    list<triangle> TT2;
    TT2.push_back(tri2);
    Assemblage A2(6);
    cout<<"test1"<<endl;
    A2.assembler(TT2);
    cout<<"test2"<<endl;
    A2.MM.print();
    A2.RR.print();

    cout<<"partie d'assemblage 2 ok"<<endl;



        return 0;
}
