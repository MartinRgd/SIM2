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
  Triinte T(point(0,0.,0.),point(0,1.,0.),point(0,0.,1.));
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
      //Matrice_creuse AA(Nbp,Nbp);
      Noeud m1(T.sommets[0].num-1,T.sommets[0].num-1,vm[0].val());
      Noeud m2(T.sommets[0].num-1,T.sommets[1].num-1,vm[1].val());
      Noeud m3(T.sommets[0].num-1,T.sommets[2].num-1,vm[2].val());
      Noeud m4(T.sommets[1].num-1,T.sommets[0].num-1,vm[3].val());
      Noeud m5(T.sommets[1].num-1,T.sommets[1].num-1,vm[4].val());
      Noeud m6(T.sommets[1].num-1,T.sommets[2].num-1,vm[5].val());
      Noeud m7(T.sommets[2].num-1,T.sommets[0].num-1,vm[6].val());
      Noeud m8(T.sommets[2].num-1,T.sommets[1].num-1,vm[7].val());
      Noeud m9(T.sommets[2].num-1,T.sommets[2].num-1,vm[8].val());
      MM.Chaine.push_back(m1);
      MM.Chaine.push_back(m2);
      MM.Chaine.push_back(m3);
      MM.Chaine.push_back(m4);
      MM.Chaine.push_back(m5);
      MM.Chaine.push_back(m6);
      MM.Chaine.push_back(m7);
      MM.Chaine.push_back(m8);
      MM.Chaine.push_back(m9);
      //MM+=AA;//il faut definir l'operator +=
      //Matrice_creuse BB(Nbp,Nbp);
      Noeud r1(T.sommets[0].num-1,T.sommets[0].num-1,vr[0].val());
      Noeud r2(T.sommets[0].num-1,T.sommets[1].num-1,vr[1].val());
      Noeud r3(T.sommets[0].num-1,T.sommets[2].num-1,vr[2].val());
      Noeud r4(T.sommets[1].num-1,T.sommets[0].num-1,vr[3].val());
      Noeud r5(T.sommets[1].num-1,T.sommets[1].num-1,vr[4].val());
      Noeud r6(T.sommets[1].num-1,T.sommets[2].num-1,vr[5].val());
      Noeud r7(T.sommets[2].num-1,T.sommets[0].num-1,vr[6].val());
      Noeud r8(T.sommets[2].num-1,T.sommets[1].num-1,vr[7].val());
      Noeud r9(T.sommets[2].num-1,T.sommets[2].num-1,vr[8].val());
      RR.Chaine.push_back(r1);
      RR.Chaine.push_back(r2);
      RR.Chaine.push_back(r3);
      RR.Chaine.push_back(r4);
      RR.Chaine.push_back(r5);
      RR.Chaine.push_back(r6);
      RR.Chaine.push_back(r7);
      RR.Chaine.push_back(r8);
      RR.Chaine.push_back(r9);
      //RR+=BB;


  };
}


