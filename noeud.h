#ifndef NOEUD_H
#define NOEUD_H

class Noeud
// Classe Noeud qui prend la forme d'un triblet avec le numero de ligne, de colonne et le contenu du noeud
{
    private:
        /// ATTRIBUTS
        int Li,Co;
        double Val;

    public:
        // CONSTRUCTEUR qui initialise tout a 0
        Noeud(const int & l=0, const int & c =0, const double & v=0.) : Li(l),Co(c),Val(v) {}

        /// Fonctions d'acces

        // Version non const
        int & li();          // fonction permettant la lecture et l'écriture dans les lignes
        int & co();          // idem dans les colonnes
        double & val();      // idem pour la valeur

        //Version const
        int li() const;
        int co() const;
        double val() const;

        void print();         // fonction qui affiche le triplet
        void print() const;         // version const

};


#endif // NOEUD_H
