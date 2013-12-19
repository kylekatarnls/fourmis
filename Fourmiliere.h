using namespace std;

#ifndef FROUMILIERE_H_INCLUDED
#define FROUMILIERE_H_INCLUDED
#include "Plateau.h"
#include "Fourmi.h"
#include <vector>

class Fourmiliere
{
    private:
        Plateau* plateau;
        vector<Fourmi> popu;
        static unsigned int nb;
    public:
        Fourmiliere(Plateau& pl);
        void ajout();
        void affiche();
        void stats();
        void stats(unsigned int n, unsigned int m);
};

#endif // FROUMILIERE_H_INCLUDED
