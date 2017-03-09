#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<list>
using namespace std;


class point
{public:
    double x;
    double y;
    int num;
    point(int num0=0,double x0=0,double y0=0){num=num0;x=x0;y=y0;};

   bool operator ==(const point &) ;

};

point operator +(const point &,const point &);
point operator /(const point &, int  );

ostream& operator<<(ostream &,const point &);


class triangle
{public:
    int type_;
    double IT = 0;
    int cas_;
    vector<point> sommets;
    vector<point> milieux;
    triangle(const point &P1,const point &P2,const point &P3) //constructeur prenant 3 points
    {
        sommets.push_back(P1);
        sommets.push_back(P2);
        sommets.push_back(P3);
    };

    triangle(const point &P1,const point &P2,const point &P3,const point &P4,const point &P5,const point &P6) //constructeur prenant 6 points
    {
        milieux.push_back(P1);
        milieux.push_back(P2);
        milieux.push_back(P3);
        milieux.push_back(P4);
        milieux.push_back(P5);
        milieux.push_back(P6);
    };
   // une fonction d'acces au ieme sommet
    point  operator()(int i) const
    {if (type_==9) return milieux[i-1];
     else if (type_==2) return sommets[i-1];};

     bool operator !=(const triangle &);

};



ostream& operator<<(ostream &,const triangle &);


class maillage
{public:
    list<triangle> trianglesP1;
    list<triangle> trianglesP2;
    list<triangle> Traff;
    list<triangle> Traff_rest;
    list<triangle> Tvois;
    list<triangle> nouveau_triangles;
    list<triangle> trianglesP2P2;
};

point operator +(const point & P,const point &Q)
{
    point R(0,0);
    R.x=P.x+Q.x;
    R.y=P.y+Q.y;
    return R;
}

point operator /(const point & P, int m)
{
    point R(0,0);
    R.x=P.x/m;
    R.y=P.y/m;
    return R;
}




ostream & operator<<(ostream & out, const point & P)
{
    out<<P.num<<"("<<P.x<<","<<P.y<<")";
    return out;
}

bool point::operator ==(const point & P2)
{
     if (x==P2.x && y==P2.y ) return true;
     else return false;

}

ostream & operator<<(ostream & out, const triangle & T)
{   if(T.type_==9)
     {
    out<<T(1)<<","<<T(2)<<","<<T(3)<<","<<T(4)<<","<<T(5)<<","<<T(6)<<endl;
    }
     if(T.type_==2)
     {
    out<<T(1)<<","<<T(2)<<","<<T(3)<<endl;
    }

    return out;
}

bool triangle::operator !=( const triangle & T2)                                                      // deux triangles partagent une arrete
{
    if  (type_==9)
    {
             if ((milieux[0]==T2(1)||milieux[0]==T2(2) ||milieux[0]==T2(3)) &&(milieux[1]==T2(1)||milieux[1]==T2(2) ||milieux[1]==T2(3)))
             { cas_=1;
                  return true;}
    else if   ((milieux[0]==T2(1)||milieux[0]==T2(2) ||milieux[0]==T2(3)) &&(milieux[2]==T2(1)||milieux[2]==T2(2) ||milieux[2]==T2(3)))
             {cas_=2;
                  return true;}
    else if   ((milieux[1]==T2(1)||milieux[1]==T2(2) ||milieux[1]==T2(3)) &&(milieux[2]==T2(1)||milieux[2]==T2(2) ||milieux[2]==T2(3)))
             {cas_=3;
                  return true;}
    else return false;
    }


     if  (type_==2)
    {
             if ((sommets[0]==T2(1)||sommets[0]==T2(2) ||sommets[0]==T2(3)) &&(sommets[1]==T2(1)||sommets[1]==T2(2) ||sommets[1]==T2(3)))
                  { cas_=1;
                  return true;}
    else if   ((sommets[0]==T2(1)||sommets[0]==T2(2) ||sommets[0]==T2(3)) &&(sommets[2]==T2(1)||sommets[2]==T2(2) ||sommets[2]==T2(3)))
        { cas_=2;
                  return true;}
    else if   ((sommets[1]==T2(1)||sommets[1]==T2(2) ||sommets[1]==T2(3)) &&(sommets[2]==T2(1)||sommets[2]==T2(2) ||sommets[2]==T2(3)))
       { cas_=3;
                  return true;}
    else return false;
    }

}




int main()
{
    maillage maillage_lu;

   ifstream in("mesh.msh");    // open the file
    //ifstream in;
    //in.open("untitled2.msh");
    //int i=0;
    if (!in.is_open())
        cout << "File not open" << endl;  // assurer que le file est ouvri correct

    string str;

  //Read the header $MeshFormat
    getline(in,str);
    if (str != "$MeshFormat")
        cout << "Reading problem 1" << endl;

 // Read the version numbers
    getline(in,str);
    stringstream stream(str);

    string vNumber1; int vNumber2;int vNumber3;
    stream >> vNumber1;
    if(vNumber1 != "2.2")
        cout  << "Reading problem 2" << endl;
    stream >> vNumber2;
    if(vNumber2 != 0)
        cout << "Reading problem 3" << endl;
    stream >> vNumber3;
    if(vNumber3 != 8)
        cout << "Reading problem 4" << endl;
// Read the header $EndMeshFormat
    getline(in,str);
    if (str != "$EndMeshFormat")
        cout << "Reading problem 5" << endl;
// Read the header $Nodes
    getline(in,str);
    if (str != "$Nodes")
        cout << "Reading problem 6" << endl;
//Read te number of nodes
      getline(in,str);
     int nodes_num=atoi(str.c_str());
//Loop over the nodes
     int No;
     double x[1000],y[1000],z[1000];
    // double x[nodes_num-1],y[nodes_num-1],z[nodes_num-1];

     for(int k=0;k<=nodes_num-1;k++)
    {
        getline(in,str);
        stringstream stream(str);
        stream>>No>>x[k]>>y[k]>>z[k];        //x(k),y(k),z(k) sont les coordon¨¦es de point(k+1)
        stream.clear();
    }
//Read the header $EndNodes
     getline(in,str);
     if (str != "$EndNodes")
        cout << "Reading problem 7" << endl;
//Read the  header $Elements
     getline(in,str);
     if (str != "$Elements")
        cout << "Reading problem 8 " << endl;
//Read te number of elements
     getline(in,str);
     int elements_num=atoi(str.c_str());

//Loop over the nodes

     int type,rien; int p[5];
     int no_P1_en_P2=0;

    for(int k=0;k<=elements_num-1;k++)
    {
        getline(in,str);
        stringstream stream(str);
        stream>>No;
        stream>>type;
        if(type==15)
        {
            cout<<"element"<<No<<" est un point"<<endl;
        }
         else if(type==8)
        {
            cout<<"element"<<No<<" est une arret en P2"<<endl;
        }
        else if(type==9)
        {
            cout<<"element"<<No<<" est un triangle en P2"<<endl;

            stream>>rien>>rien>>rien>>p[0]>>p[1]>>p[2]>>p[3]>>p[4]>>p[5];

            point P1(p[0],x[p[0]-1],y[p[0]-1]);
            point P2(p[1],x[p[1]-1],y[p[1]-1]);
            point P3(p[2],x[p[2]-1],y[p[2]-1]);
            point P4(p[3],x[p[3]-1],y[p[3]-1]);
            point P5(p[4],x[p[4]-1],y[p[4]-1]);
            point P6(p[5],x[p[5]-1],y[p[5]-1]);
            maillage_lu.trianglesP2.push_back(triangle(P1,P2,P3,P4,P5,P6));
            maillage_lu.trianglesP2P2.push_back(triangle(P1,P2,P3,P4,P5,P6));
        }
        else if(type==1)
        {
            cout<<"element"<<No<<" est un arret en P1"<<endl;
        }
        else if(type==2)
        {
            cout<<"element"<<No<<" est un triangle en P1"<<endl;

            stream>>rien>>rien>>rien>>p[0]>>p[1]>>p[2];

            point P1(p[0],x[p[0]-1],y[p[0]-1]);
            point P2(p[1],x[p[1]-1],y[p[1]-1]);
            point P3(p[2],x[p[2]-1],y[p[2]-1]);
            // p2p2
            point P4=(P1+P2)/2;
            point P5=(P2+P3)/2;
            point P6=(P1+P3)/2;

            no_P1_en_P2=no_P1_en_P2+3;
            maillage_lu.trianglesP2P2.push_back(triangle(P1,P2,P3,P4,P5,P6));

            /////////
            maillage_lu.trianglesP1.push_back(triangle(P1,P2,P3));
        }
        stream.clear();
    }

//Read te number of elements $EndElements
     getline(in,str);
     if (str == "$EndElements")
        cout << "Stop" << endl;


list<triangle>::iterator it2;
int i=1;
for(it2 = maillage_lu.trianglesP2.begin();it2!=maillage_lu.trianglesP2.end();it2++,i++)
{
    it2->type_=9;
    cout<<"le triangle "<<i<<" contient "<< *it2<<endl;
    if (it2->IT>1)
    {maillage_lu.Traff.push_back(*it2);}
    else
    {maillage_lu.Traff_rest.push_back(*it2);}

}


list<triangle>::iterator it1;
int m=1;
for(it1 = maillage_lu.trianglesP1.begin();it1!=maillage_lu.trianglesP1.end();it1++,m++)
{

    it1->type_=2;
    cout<<"le triangle "<<m<<" contient "<< *it1<<endl;


    if (m==4) //test
    {it1->IT=2; }        //test

    if (m==7) //test
    {it1->IT=2; }        //test


    if (it1->IT>1)
     {maillage_lu.Traff.push_back(*it1);}
    else
     {maillage_lu.Traff_rest.push_back(*it1);}

}



int sss=1;
                                                                                               //boucle, trouber l'ensemble Traff et Tvois
while (sss!=0)
{
list<triangle>::iterator it3;
list<triangle>::iterator it4;
sss=0;
for(it3 = maillage_lu.Traff.begin();it3!=maillage_lu.Traff.end();it3++)
{
      for(it4 =maillage_lu.Traff_rest.begin()  ;it4!=maillage_lu.Traff_rest.end();)
    {
         if (*it3!=*it4)
         {

         maillage_lu.Tvois.push_back(*it4);

        it4=maillage_lu.Traff_rest.erase(it4);
        sss=sss+1;
         }
          else
         {
            it4++;
         }
    }
}

list<triangle>::iterator it5;

for(it5 = maillage_lu.Tvois.begin();it5!=maillage_lu.Tvois.end();)
{
    int ii=0;
       for(it3 = maillage_lu.Traff.begin();it3!=maillage_lu.Traff.end();it3++)
       {  if (*it5!=*it3)
       ii=ii+1;
       }
       if(ii>=2)
       {
            maillage_lu.Traff.push_back(*it5);
            it5=maillage_lu.Tvois.erase(it5);
       }
       else
       {
            it5++;
       }
}

}

//test


int number_of_nouveau_triangles=0;

list<triangle>::iterator it12;
int mmm=1;
for(it12 = maillage_lu.Traff_rest.begin();it12!=maillage_lu.Traff_rest.end();it12++,mmm++)
{

    cout<<"le triangle traff rest "<<mmm<<" contient "<< *it12<<endl;
    maillage_lu.nouveau_triangles.push_back( *it12);
    number_of_nouveau_triangles=number_of_nouveau_triangles+1;

}


double nouveau_points_x[4*nodes_num];
double nouveau_points_y[4*nodes_num];
int a_a,b_b,c_c;


list<triangle>::iterator it15;
int nn=1;
int nodes_num_new;
for(it15 = maillage_lu.Traff.begin();it15!=maillage_lu.Traff.end();it15++,nn++)
{
      a_a=0;
      b_b=0;
      c_c=0;

    cout<<"le triangle traff "<<nn<<" contient "<< *it15<<endl;
    triangle T =*it15;
    point P1,P2,P3,P4,P5,P6;
    P1 = T(1);
    P2 = T(2);
    P3 = T(3);
    P4=(P1+P2)/2;
    P5=(P2+P3)/2;
    P6=(P1+P3)/2;

    if(nn==1)
      {   nouveau_points_x[0]=P4.x;
          nouveau_points_y[0]=P4.y;
          nouveau_points_x[1]=P5.x;
          nouveau_points_y[1]=P5.y;
          nouveau_points_x[2]=P6.x;
          nouveau_points_y[2]=P6.y;

          nodes_num_new=nodes_num+1;
          P4.num=nodes_num_new;
          nodes_num_new=nodes_num_new+1;
          P5.num=nodes_num_new;
          nodes_num_new=nodes_num_new+1;
          P6.num=nodes_num_new;
          }
     else
{

      for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {

          if (P4.x==nouveau_points_x[w]&&P4.y==nouveau_points_y[w])
          {a_a=1;
          P4.num=nodes_num+w+1;
          }
     }

       if(a_a==0)
     {
          nouveau_points_x[nodes_num_new-nodes_num]=P4.x;
          nouveau_points_y[nodes_num_new-nodes_num]=P4.y;
          nodes_num_new=nodes_num_new+1;
          P4.num=nodes_num_new;
     }

      for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {
     if (P5.x==nouveau_points_x[w]&&P5.y==nouveau_points_y[w])
         {b_b=1;
          P5.num=nodes_num+w+1;
         }
     }
      if(b_b==0)
     {
          nouveau_points_x[nodes_num_new-nodes_num]=P5.x;
          nouveau_points_y[nodes_num_new-nodes_num]=P5.y;
          nodes_num_new=nodes_num_new+1;
          P5.num=nodes_num_new;
    }

       for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {
     if  (P6.x==nouveau_points_x[w]&&P5.y==nouveau_points_y[w])
         {c_c=1;
          P6.num=nodes_num+w+1;
         }
     }
     if(c_c==0)
     {  nouveau_points_x[nodes_num_new-nodes_num]=P6.x;
        nouveau_points_y[nodes_num_new-nodes_num]=P6.y;
        nodes_num_new=nodes_num_new+1;
        P6.num=nodes_num_new;
     }

}

    maillage_lu.nouveau_triangles.push_back(triangle(P1,P4,P6));
    maillage_lu.nouveau_triangles.push_back(triangle(P2,P4,P5));
    maillage_lu.nouveau_triangles.push_back(triangle(P3,P5,P6));
    maillage_lu.nouveau_triangles.push_back(triangle(P4,P5,P6));
     number_of_nouveau_triangles=number_of_nouveau_triangles+4;

}



list<triangle>::iterator it11;
int mm=1;
for(it11 = maillage_lu.Tvois.begin();it11!=maillage_lu.Tvois.end();it11++,mm++)
{
    a_a=0;
    cout<<"le triangle tvois "<<mm<<" contient "<< *it11<<endl;

    triangle T=*it11;
     point P1,P2,P3,P4;
     P1 = T(1);
     P2 = T(2);
     P3 = T(3);
     if (it11->cas_==1)
     {
         P4=(P1+P2)/2;

          for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {

          if (P4.x==nouveau_points_x[w]&&P4.y==nouveau_points_y[w])
          {a_a=1;
          P4.num=nodes_num+w+1;
          }
     }

    maillage_lu.nouveau_triangles.push_back(triangle(P1,P4,P3));
    maillage_lu.nouveau_triangles.push_back(triangle(P2,P4,P3));
     number_of_nouveau_triangles=number_of_nouveau_triangles+2;
     }
       if (it11->cas_==2)
     {
         P4=(P1+P3)/2;
          for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {

          if (P4.x==nouveau_points_x[w]&&P4.y==nouveau_points_y[w])
          {a_a=1;
          P4.num=nodes_num+w+1;
          }
     }
    maillage_lu.nouveau_triangles.push_back(triangle(P1,P4,P2));
    maillage_lu.nouveau_triangles.push_back(triangle(P2,P4,P3));
    number_of_nouveau_triangles=number_of_nouveau_triangles+2;
     }
       if (it11->cas_==3)
     {
         P4=(P2+P3)/2;
          for(int w=0;w<=nodes_num_new-nodes_num-1;w++)
    {

          if (P4.x==nouveau_points_x[w]&&P4.y==nouveau_points_y[w])
          {a_a=1;
          P4.num=nodes_num+w+1;
          }
     }
     maillage_lu.nouveau_triangles.push_back(triangle(P1,P4,P2));
     maillage_lu.nouveau_triangles.push_back(triangle(P1,P4,P3));
     number_of_nouveau_triangles=number_of_nouveau_triangles+2;
     }

}


list<triangle>::iterator it88;                                           // l'arrete
i=1;
int arrete1[1000];int arrete2[1000];int arrete_num=0;
int cas1; int cas2; int cas3;
for(it88 = maillage_lu.nouveau_triangles.begin();it88!=maillage_lu.nouveau_triangles.end();it88++,i++)
{
     cas1=0; cas2=0; cas3=0;
if(i==1)
{
    arrete1[i-1]=(*it88).sommets[0].num;
    arrete2[i-1]=(*it88).sommets[1].num;
    arrete1[i]=(*it88).sommets[1].num;
    arrete2[i]=(*it88).sommets[2].num;
    arrete1[i+1]=(*it88).sommets[2].num;
    arrete2[i+1]=(*it88).sommets[0].num;
    arrete_num=arrete_num+3;
}

else
{
     for(int t=0;t<arrete_num;t++)
     {
          if (((*it88).sommets[0].num==arrete1[t]&&(*it88).sommets[1].num==arrete2[t])||((*it88).sommets[0].num==arrete2[t]&&(*it88).sommets[1].num==arrete1[t]))
          {cas1=1;}
          if (((*it88).sommets[0].num==arrete1[t]&&(*it88).sommets[2].num==arrete2[t])||((*it88).sommets[0].num==arrete2[t]&&(*it88).sommets[2].num==arrete1[t]))
          {cas2=1;}
          if (((*it88).sommets[1].num==arrete1[t]&&(*it88).sommets[2].num==arrete2[t])||((*it88).sommets[1].num==arrete2[t]&&(*it88).sommets[2].num==arrete1[t]))
          {cas3=1;}
     }
     if((cas1==1)&&(cas2==0)&&(cas3==0))
     {

       arrete1[arrete_num]=(*it88).sommets[0].num;
       arrete2[arrete_num]=(*it88).sommets[2].num;
       arrete1[arrete_num+1]=(*it88).sommets[1].num;
       arrete2[arrete_num+1]=(*it88).sommets[2].num;
       arrete_num=arrete_num+2;
     }
    else if((cas1==0)&&(cas2==1)&&(cas3==0))
     {
                arrete1[arrete_num]=(*it88).sommets[0].num;
                arrete2[arrete_num]=(*it88).sommets[1].num;
                arrete1[arrete_num+1]=(*it88).sommets[1].num;
                arrete2[arrete_num+1]=(*it88).sommets[2].num;
                arrete_num=arrete_num+2;
     }
    else  if((cas1==0)&&(cas2==0)&&(cas3==1))
     {
                arrete1[arrete_num]=(*it88).sommets[0].num;
                arrete2[arrete_num]=(*it88).sommets[1].num;
                arrete1[arrete_num+1]=(*it88).sommets[0].num;
                arrete2[arrete_num+1]=(*it88).sommets[2].num;
                   arrete_num=arrete_num+2;
     }
     else if((cas1==1)&&(cas2==1)&&(cas3==0))
     {

       arrete1[arrete_num]=(*it88).sommets[1].num;
       arrete2[arrete_num]=(*it88).sommets[2].num;
       arrete_num=arrete_num+1;
     }
     else if((cas1==1)&&(cas2==0)&&(cas3==1))
     {

       arrete1[arrete_num]=(*it88).sommets[0].num;
       arrete2[arrete_num]=(*it88).sommets[2].num;
          arrete_num=arrete_num+1;
     }
     else if((cas1==0)&&(cas2==1)&&(cas3==1))
     {

       arrete1[arrete_num]=(*it88).sommets[0].num;
       arrete2[arrete_num]=(*it88).sommets[1].num;
        arrete_num=arrete_num+1;
     }
          else if((cas1==0)&&(cas2==0)&&(cas3==0))
     {

                arrete1[arrete_num]=(*it88).sommets[0].num;
                arrete2[arrete_num]=(*it88).sommets[1].num;
                arrete1[arrete_num+1]=(*it88).sommets[0].num;
                arrete2[arrete_num+1]=(*it88).sommets[2].num;
               arrete1[arrete_num+2]=(*it88).sommets[1].num;
                arrete2[arrete_num+2]=(*it88).sommets[2].num;
                arrete_num=arrete_num+3;
     }
}

}


ofstream outfile;
outfile.open("le nouveau maillage.msh");
outfile<<"$MeshFormat"<<endl;
outfile<<"2.2 0 8"<<endl;
outfile<<"$EndMeshFormat"<<endl;
outfile<<"$Nodes"<<endl;
outfile<<nodes_num_new<<endl;

for(int i=0; i<nodes_num; i++)
{
     outfile<<i+1<<" "<<x[i]<<" "<<y[i]<<" 0"<<endl;
}

for(int i=0; i<nodes_num_new-nodes_num; i++)
{
     outfile<<i+1+nodes_num<<" "<<nouveau_points_x[i]<<" "<<nouveau_points_y[i]<<" 0"<<endl;
}

outfile<<"$EndNodes"<<endl;
outfile<<"$Elements"<<endl;
outfile<< number_of_nouveau_triangles+nodes_num_new+arrete_num<<endl;

// number of elements

for(int i=0; i<nodes_num; i++)
{
     outfile<<i+1<<" 15 2 1 "<<i+1<<" "<<i+1<<endl;
}

for(int i=0; i<nodes_num_new-nodes_num; i++)
{
     outfile<<i+1+nodes_num<<" 15 2 1 "<<i+1+nodes_num<<" "<<i+1+nodes_num<<endl;
}


for(int i=0;i< arrete_num;i++)
{
   outfile<<i+1+nodes_num_new<<" 1 2 1 1 "<<arrete1[i]<<" "<<arrete2[i]<<endl;
}



list<triangle>::iterator it8;
i=1;
for(it8 = maillage_lu.nouveau_triangles.begin();it8!=maillage_lu.nouveau_triangles.end();it8++,i++)
{

     outfile<<i+nodes_num_new+arrete_num<<" 2 2 1 1 "<<(*it8).sommets[0].num<<" "<<(*it8).sommets[1].num<<" "<<(*it8).sommets[2].num<<endl;


}

  outfile<<"$EndElements"<<endl;
}





