#ifndef TRIN_H_INCLUDED
#define TRIN_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"

using namespace std;

class Point
{
    public:
    double x;double y;
    Point(double a=0,double b=0)
    :x(a),y(b)
    {}
    Point(const Point &U)
    {
        x=U.x;y=U.y;
    }

};

Point operator + (const Point&U,const Point&V);
Point operator * (double a,const Point &U);
ostream & operator <<(ostream & out,const Point &U);

class Triangle
{
    public:
    vector<Point> sommet;
    Triangle()
    {
        sommet.push_back(Point(0,0));
        sommet.push_back(Point(0,1));
        sommet.push_back(Point(1,0));
    }
    Triangle(const Point &U,const Point &V,const Point &W)
    {
        sommet.push_back(U);
        sommet.push_back(V);
        sommet.push_back(W);
    }
    Point operator()(int i) const
    {return sommet[i-1];}

};

ostream & operator <<(ostream & out,const Triangle &U);


class Triinte: public Triangle
{
    public:
    double a;double b;
    double bl=(sommet[1].x-sommet[0].x)*(sommet[2].y-sommet[0].y)-(sommet[2].x-sommet[0].x)*(sommet[1].y-sommet[0].y);



    Triinte(const Point &U, const Point &V,const Point &W,double p=1.,double q=1.)
    :Triangle(U,V,W)
    {
        a=p;b=q;
    }
    /*Triinte(const Triangle &T)
    {
        sommet=T.sommet;
    }*/
    Triinte(const Triinte &M);
    Matrice_creuse masse () const;
    Matrice_creuse rigid () const;
};


#endif // TRIN_H_INCLUDED
