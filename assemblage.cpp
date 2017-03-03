#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
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
  //Triinte T1(point(1,0.,0.),point(2,1.,0.),point(3,0.,1.));
  //Triinte T2(point(1,0.,0.),point(2,1.,0.),point(3,0.,1.),point(4,0.5,0.),point(5,0.5,0.5),point(6,0.,0.5));
  //point p=T.sommets[0];
  for(it=TL.begin();it!=TL.end();it++)
  {
      if(it->type==1)
      {
          Triinte T1(it->sommets[0],it->sommets[1],it->sommets[2]);
          /*for(int i=0;i<3;i++)
          {
              T1.sommets.at(i)=it->sommets.at(i);
          }*/
          T1.masse();
          T1.rigid();
      //trii.push_back(T);
          vector<Noeud> vm=T1.M.get_Chaine();
          vector<Noeud> vr=T1.R.get_Chaine();
      //Matrice_creuse AA(Nbp,Nbp);
          int j=0;
          for(int m=0;m<3;m++)
          {
              for(int n=0;n<3;n++)
              {
                  MM.Chaine.push_back(Noeud(T1.sommets[m].num,T1.sommets[n].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(T1.sommets[m].num,T1.sommets[n].num,vr[j].val()));
                  j++;
              }
          }
      }
      else
      {
          Triinte T2(it->sommets[0],it->sommets[1],it->sommets[2],it->milieux[0],it->milieux[1],it->milieux[2]);
          /*for(int i=0;i<3;i++)
          {
              T2.sommets.at(i)=it->sommets.at(i);
              T2.milieux.at(i)=it->milieux.at(i);
          }*/
          T2.masse();
          T2.rigid();
      //trii.push_back(T);
          vector<Noeud> vm=T2.M.get_Chaine();
          vector<Noeud> vr=T2.R.get_Chaine();
      //Matrice_creuse AA(Nbp,Nbp);
          int j=0;
          for(int m1=0;m1<3;m1++)
          {
              for(int n1=0;n1<3;n1++)
              {
                  MM.Chaine.push_back(Noeud(T2.sommets[m1].num,T2.sommets[n1].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(T2.sommets[m1].num,T2.sommets[n1].num,vr[j].val()));
                  j++;
              }
              for(int n2=0;n2<3;n2++)
              {
                  MM.Chaine.push_back(Noeud(T2.sommets[m1].num,T2.milieux[n2].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(T2.sommets[m1].num,T2.milieux[n2].num,vr[j].val()));
                  j++;
              }
          }
          for(int m2=0;m2<3;m2++)
          {
              for(int n3=0;n3<3;n3++)
              {
                  MM.Chaine.push_back(Noeud(T2.milieux[m2].num,T2.sommets[n3].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(T2.milieux[m2].num,T2.sommets[n3].num,vr[j].val()));
                  j++;
              }
              for(int n4=0;n4<3;n4++)
              {
                  MM.Chaine.push_back(Noeud(T2.milieux[m2].num,T2.milieux[n4].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(T2.milieux[m2].num,T2.milieux[n4].num,vr[j].val()));
                  j++;
              }
          }

      }
  }
}

void Assemblage::assemblertrin(const list<Triinte> & TI)
{
  list<Triinte>::const_iterator it;
  for(it=TI.begin();it!=TI.end();it++)
  {
      if(it->type==1)
      {
      //trii.push_back(T);
          vector<Noeud> vm=it->M.get_Chaine();
          vector<Noeud> vr=it->R.get_Chaine();
      //Matrice_creuse AA(Nbp,Nbp);
          int j=0;
          for(int m=0;m<3;m++)
          {
              for(int n=0;n<3;n++)
              {
                  MM.Chaine.push_back(Noeud(it->sommets[m].num,it->sommets[n].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(it->sommets[m].num,it->sommets[n].num,vr[j].val()));
                  j++;
              }
          }
      }
      else
      {

      //trii.push_back(T);
          vector<Noeud> vm=it->M.get_Chaine();
          vector<Noeud> vr=it->R.get_Chaine();
      //Matrice_creuse AA(Nbp,Nbp);
          int j=0;
          for(int m1=0;m1<3;m1++)
          {
              for(int n1=0;n1<3;n1++)
              {
                  MM.Chaine.push_back(Noeud(it->sommets[m1].num,it->sommets[n1].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(it->sommets[m1].num,it->sommets[n1].num,vr[j].val()));
                  j++;
              }
              for(int n2=0;n2<3;n2++)
              {
                  MM.Chaine.push_back(Noeud(it->sommets[m1].num,it->milieux[n2].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(it->sommets[m1].num,it->milieux[n2].num,vr[j].val()));
                  j++;
              }
          }
          for(int m2=0;m2<3;m2++)
          {
              for(int n3=0;n3<3;n3++)
              {
                  MM.Chaine.push_back(Noeud(it->milieux[m2].num,it->sommets[n3].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(it->milieux[m2].num,it->sommets[n3].num,vr[j].val()));
                  j++;
              }
              for(int n4=0;n4<3;n4++)
              {
                  MM.Chaine.push_back(Noeud(it->milieux[m2].num,it->milieux[n4].num,vm[j].val()));
                  RR.Chaine.push_back(Noeud(it->milieux[m2].num,it->milieux[n4].num,vr[j].val()));
                  j++;
              }
          }

      }
  }
}
      /*Noeud m1(T.sommets[0].num,T.sommets[0].num,vm[0].val());
      cout<<"test"<<T.sommets[2].num<<endl;
      Noeud m2(T.sommets[0].num,T.sommets[1].num,vm[1].val());
      Noeud m3(T.sommets[0].num,T.sommets[2].num,vm[2].val());
      Noeud m4(T.sommets[1].num,T.sommets[0].num,vm[3].val());
      Noeud m5(T.sommets[1].num,T.sommets[1].num,vm[4].val());
      Noeud m6(T.sommets[1].num,T.sommets[2].num,vm[5].val());
      Noeud m7(T.sommets[2].num,T.sommets[0].num,vm[6].val());
      Noeud m8(T.sommets[2].num,T.sommets[1].num,vm[7].val());
      Noeud m9(T.sommets[2].num,T.sommets[2].num,vm[8].val());
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
      Noeud r1(T.sommets[0].num,T.sommets[0].num,vr[0].val());
      Noeud r2(T.sommets[0].num,T.sommets[1].num,vr[1].val());
      Noeud r3(T.sommets[0].num,T.sommets[2].num,vr[2].val());
      Noeud r4(T.sommets[1].num,T.sommets[0].num,vr[3].val());
      Noeud r5(T.sommets[1].num,T.sommets[1].num,vr[4].val());
      Noeud r6(T.sommets[1].num,T.sommets[2].num,vr[5].val());
      Noeud r7(T.sommets[2].num,T.sommets[0].num,vr[6].val());
      Noeud r8(T.sommets[2].num,T.sommets[1].num,vr[7].val());
      Noeud r9(T.sommets[2].num,T.sommets[2].num,vr[8].val());
      RR.Chaine.push_back(r1);
      RR.Chaine.push_back(r2);
      RR.Chaine.push_back(r3);
      RR.Chaine.push_back(r4);
      RR.Chaine.push_back(r5);
      RR.Chaine.push_back(r6);
      RR.Chaine.push_back(r7);
      RR.Chaine.push_back(r8);
      RR.Chaine.push_back(r9);

      }
      T.sommets.at(0)=it->sommets.at(0);
      T.sommets.at(1)=it->sommets.at(1);
      T.sommets.at(2)=it->sommets.at(2);
      T.masse();
      T.rigid();
      //trii.push_back(T);
      vector<Noeud> vm=T.M.get_Chaine();
      vector<Noeud> vr=T.R.get_Chaine();
      //Matrice_creuse AA(Nbp,Nbp);
      Noeud m1(T.sommets[0].num,T.sommets[0].num,vm[0].val());
      cout<<"test"<<T.sommets[2].num<<endl;
      Noeud m2(T.sommets[0].num,T.sommets[1].num,vm[1].val());
      Noeud m3(T.sommets[0].num,T.sommets[2].num,vm[2].val());
      Noeud m4(T.sommets[1].num,T.sommets[0].num,vm[3].val());
      Noeud m5(T.sommets[1].num,T.sommets[1].num,vm[4].val());
      Noeud m6(T.sommets[1].num,T.sommets[2].num,vm[5].val());
      Noeud m7(T.sommets[2].num,T.sommets[0].num,vm[6].val());
      Noeud m8(T.sommets[2].num,T.sommets[1].num,vm[7].val());
      Noeud m9(T.sommets[2].num,T.sommets[2].num,vm[8].val());
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
      Noeud r1(T.sommets[0].num,T.sommets[0].num,vr[0].val());
      Noeud r2(T.sommets[0].num,T.sommets[1].num,vr[1].val());
      Noeud r3(T.sommets[0].num,T.sommets[2].num,vr[2].val());
      Noeud r4(T.sommets[1].num,T.sommets[0].num,vr[3].val());
      Noeud r5(T.sommets[1].num,T.sommets[1].num,vr[4].val());
      Noeud r6(T.sommets[1].num,T.sommets[2].num,vr[5].val());
      Noeud r7(T.sommets[2].num,T.sommets[0].num,vr[6].val());
      Noeud r8(T.sommets[2].num,T.sommets[1].num,vr[7].val());
      Noeud r9(T.sommets[2].num,T.sommets[2].num,vr[8].val());
      RR.Chaine.push_back(r1);
      RR.Chaine.push_back(r2);
      RR.Chaine.push_back(r3);
      RR.Chaine.push_back(r4);
      RR.Chaine.push_back(r5);
      RR.Chaine.push_back(r6);
      RR.Chaine.push_back(r7);
      RR.Chaine.push_back(r8);
      RR.Chaine.push_back(r9);
      //RR+=BB;*/




