using namespace std;

#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "Etat.h"

class Plateau
{
    private:
        Etat** tab;
        unsigned int hauteur, largeur;
    public:
        virtual ~Plateau();
        Plateau();
        Plateau(Plateau& pl);
        Plateau(unsigned int h, unsigned int l);
        Plateau& operator++(void);
        Plateau& operator=(Plateau& pl);
        void set_tab(unsigned int h, unsigned int l);
        void affiche();
        Etat& get_case(unsigned int x, unsigned int y);
        unsigned int get_h();
        unsigned int get_l();
        bool est_au_bord(unsigned int x, unsigned int y);
};

#endif // PLATEAU_H_INCLUDED
