#ifndef ASSEMBLAGE_H_INCLUDED
#define ASSEMBLAGE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include"noeud.h"
#include"matrice_creuse.h"
#include"trin.h"


using namespace std;

class Assemblage: public matrice_creuse
{
    public:
    list<Triinte> trii;
    void trii_init(const list<Triangle> & TL);
    void assembler();

};

#endif // ASSEMBLAGE_H_INCLUDED
