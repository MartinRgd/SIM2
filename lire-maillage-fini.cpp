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
};

ostream& operator<<(ostream &,const point &);

class triangle
{public:
    int type_;
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
};


ostream& operator<<(ostream &,const triangle &);


class maillage
{public:
    list<triangle> trianglesP1;
    list<triangle> trianglesP2;
};

ostream & operator<<(ostream & out, const point & P)
{
    out<<P.num<<"("<<P.x<<","<<P.y<<")";
    return out;
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

int main()
{
    maillage maillage_lu;

   ifstream in("untitle2.msh");    // open the file
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
     double x[nodes_num-1],y[nodes_num-1],z[nodes_num-1];
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
}

list<triangle>::iterator it1;
int m=1;
for(it1 = maillage_lu.trianglesP1.begin();it1!=maillage_lu.trianglesP1.end();it1++,m++)
{

    it1->type_=2;
    cout<<"le triangle "<<m<<" contient "<< *it1<<endl;


}

}
