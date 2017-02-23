#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"trin.h"
#include"assemblage.h"

Assemblage::Assemblage(int n)
:MM(n,n),RR(n,n)
{
     Nbp=n;
}
/*void Assemblage::trii_init(const list<Triangle> & TL)
{
  list<Triangle>::const_iterator it;
  Triinte T();
  for(it=TL.begin();it!=TL.end();it++)
  {
      T.sommets.at(0)=it->sommets.at(0);
      T.sommets.at(1)=it->sommets.at(1)
      T.sommets.at(2)=it->sommets.at(2));
      T.masse();
      T.rigid();
      trii.push_back(T);
  };
}*/
void Assemblage::assembler(const list<triangle> & TL)
{
  list<triangle>::const_iterator it;
  Triinte T();
  //point p=T.sommets[0];
  for(it=TL.begin();it!=TL.end();it++)
  {
      T.sommets.at(0)=it->sommets.at(0);
      T.sommets.at(1)=it->sommets.at(1);
      T.sommets.at(2)=it->sommets.at(2);
      T.masse();
      T.rigid();
      //trii.push_back(T);
      vector<Noeud> vm=T.M.get_Chaine();
      vector<Noeud> vr=T.R.get_Chaine();
      Matrice_creuse AA(Nbp,Nbp);
      Noeud m1(T.sommets[0].num-1,T.sommets[0].num-1,vm[0].Val);
      Noeud m2(T.sommets[0].num-1,T.sommets[1].num-1,vm[1].Val);
      Noeud m3(T.sommets[0].num-1,T.sommets[2].num-1,vm[2].Val);
      Noeud m4(T.sommets[1].num-1,T.sommets[0].num-1,vm[3].Val);
      Noeud m5(T.sommets[1].num-1,T.sommets[1].num-1,vm[4].Val);
      Noeud m6(T.sommets[1].num-1,T.sommets[2].num-1,vm[5].Val);
      Noeud m7(T.sommets[2].num-1,T.sommets[0].num-1,vm[6].Val);
      Noeud m8(T.sommets[2].num-1,T.sommets[1].num-1,vm[7].Val);
      Noeud m9(T.sommets[2].num-1,T.sommets[2].num-1,vm[8].Val);
      AA.Chaine.push_back(m1);
      AA.Chaine.push_back(m2);
      AA.Chaine.push_back(m3);
      AA.Chaine.push_back(m4);
      AA.Chaine.push_back(m5);
      AA.Chaine.push_back(m6);
      AA.Chaine.push_back(m7);
      AA.Chaine.push_back(m8);
      AA.Chaine.push_back(m9);
      MM+=AA;//il faut definir l'operator +=
      Matrice_creuse BB(Nbp,Nbp);
      Noeud r1(T.sommets[0].num-1,T.sommets[0].num-1,vr[0].Val);
      Noeud r2(T.sommets[0].num-1,T.sommets[1].num-1,vr[1].Val);
      Noeud r3(T.sommets[0].num-1,T.sommets[2].num-1,vr[2].Val);
      Noeud r4(T.sommets[1].num-1,T.sommets[0].num-1,vr[3].Val);
      Noeud r5(T.sommets[1].num-1,T.sommets[1].num-1,vr[4].Val);
      Noeud r6(T.sommets[1].num-1,T.sommets[2].num-1,vr[5].Val);
      Noeud r7(T.sommets[2].num-1,T.sommets[0].num-1,vr[6].Val);
      Noeud r8(T.sommets[2].num-1,T.sommets[1].num-1,vr[7].Val);
      Noeud r9(T.sommets[2].num-1,T.sommets[2].num-1,vr[8].Val);
      BB.Chaine.push_back(r1);
      BB.Chaine.push_back(r2);
      BB.Chaine.push_back(r3);
      BB.Chaine.push_back(r4);
      BB.Chaine.push_back(r5);
      BB.Chaine.push_back(r6);
      BB.Chaine.push_back(r7);
      BB.Chaine.push_back(r8);
      BB.Chaine.push_back(r9);
      RR+=BB;


  };
}


