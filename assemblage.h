#ifndef ASSEMBLAGE_H_INCLUDED
#define ASSEMBLAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"triangles.h"
#include"trin.h"
#include"intP2.h"


using namespace std;

class Assemblage
{
    public:
    int Nbp;
    //list<Triinte> trii;
    Matrice_creuse MM;
    Matrice_creuse RR;
    Assemblage(int n);
    //void trii_init(const list<Triangle> & TL);//initialise
    void assembler(const list<triangle> & TL);//assembler quand non initialise
    void assemblertrin(const list<Triinte> & TI);//assembler les triintes
    //void assembler();//assembler quand deja initialise

};

#endif // ASSEMBLAGE_H_INCLUDED
