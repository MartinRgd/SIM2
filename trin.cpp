#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"trin.h"

using namespace std;

Point operator + (const Point&U,const Point&V)
{
    Point W(U);
    W.x+=V.x;
    W.y+=V.y;
    return W;
}

Point operator * (double a,const Point &U)
{
    Point W(U);
    W.x*=a;
    W.y*=a;
    return W;
}

ostream & operator <<(ostream & out,const Point &U)
{
    out<<"("<<U.x<<","<<U.y<<")";
    return out;
}

ostream & operator <<(ostream & out,const Triangle &U)
{
    out<<U(1)<<" "<<U(2)<<" "<<U(3);
    return out;
}

Triinte::Triinte(const Triinte &M)
{

    sommet=M.sommet;
}
Matrice_creuse Triinte::masse () const
{
    Matrice_creuse M(3,3);
    Noeud n1(0,0,a*bl/12);
    Noeud n2(0,1,a*bl/24);
    Noeud n3(0,2,a*bl/24);
    Noeud n4(1,0,a*bl/24);
    Noeud n5(1,1,a*bl/12);
    Noeud n6(1,2,a*bl/24);
    Noeud n7(2,0,a*bl/24);
    Noeud n8(2,1,a*bl/24);
    Noeud n9(2,2,a*bl/12);
    M.Chaine.push_back(n1);M.Chaine.push_back(n2);M.Chaine.push_back(n3);
    M.Chaine.push_back(n4);M.Chaine.push_back(n5);M.Chaine.push_back(n6);
    M.Chaine.push_back(n7);M.Chaine.push_back(n8);M.Chaine.push_back(n9);
    M.print();
    return M;
}

Matrice_creuse Triinte::rigid () const
{
    Matrice_creuse R(3,3);

    vector<double> deltaom1(2);
    deltaom1.at(0)=-1.;deltaom1.at(1)=-1.;
    vector<double> deltaom2(2);
    deltaom2.at(0)=1.;deltaom2.at(1)=0.;
    vector<double> deltaom3(2);
    deltaom3.at(0)=0.;deltaom3.at(1)=1.;
    cout<<"1 ok"<<endl;
    //Noeud r1(0,0,1.);
    //R.Chaine.push_back(r1);
    Matrice_creuse BLTI(2,2);
    Noeud b1(0,0,(sommet[2].y-sommet[0].y)/bl);Noeud b2(0,1,(sommet[0].x-sommet[2].x)/bl);
    Noeud b3(1,0,(sommet[0].y-sommet[1].y)/bl);Noeud b4(1,1,(sommet[1].x-sommet[0].x)/bl);
    BLTI.Chaine.push_back(b1);BLTI.Chaine.push_back(b2);
    BLTI.Chaine.push_back(b3);BLTI.Chaine.push_back(b4);
    //ps(deltaom1,deltaom2);
    //vector<double> test(2);
    //test=BLTI*deltaom1;
    //double p=ps(BLTI*deltaom1,BLTI*deltaom1);
    Noeud r1(0,0,(0.5)*b*ps(BLTI*deltaom1,BLTI*deltaom1));
    Noeud r2(0,1,(0.5)*b*ps(BLTI*deltaom1,BLTI*deltaom2));
    Noeud r3(0,2,(0.5)*b*ps(BLTI*deltaom1,BLTI*deltaom3));
    Noeud r4(1,0,(0.5)*b*ps(BLTI*deltaom2,BLTI*deltaom1));
    Noeud r5(1,1,(0.5)*b*ps(BLTI*deltaom2,BLTI*deltaom2));
    Noeud r6(1,2,(0.5)*b*ps(BLTI*deltaom2,BLTI*deltaom3));
    Noeud r7(2,0,(0.5)*b*ps(BLTI*deltaom3,BLTI*deltaom1));
    Noeud r8(2,1,(0.5)*b*ps(BLTI*deltaom3,BLTI*deltaom2));
    Noeud r9(2,2,(0.5)*b*ps(BLTI*deltaom3,BLTI*deltaom3));
    R.Chaine.push_back(r1);R.Chaine.push_back(r2);R.Chaine.push_back(r3);
    R.Chaine.push_back(r4);R.Chaine.push_back(r5);R.Chaine.push_back(r6);
    R.Chaine.push_back(r7);R.Chaine.push_back(r8);R.Chaine.push_back(r9);
    R.print();
    return R;
}

