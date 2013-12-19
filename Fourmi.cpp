using namespace std;

#include "Fourmi.h"

Fourmi::Fourmi(Plateau& pl)
{
    // Position du centre du plateau
    x = (pl.get_l() - 1) / 2;
    y = (pl.get_h() - 1) / 2;
    // Nombre de déplacement = 0
    d = 0;

    Etat* e = &pl.get_case(x, y);
    // Le passage par référence permet de modifier l'état de la case, ce qui n'aurait pas été possible avec :
    // Etat e = pl.get_case(x, y);s

    // Tant que la case sur laquelle est la fourmi est occupée
    while((*e).get_o())
    {
        d++; // +1 déplacement
        // Modification de la position (coordonnée x ou y) en fonction de la direction préalablement modifiée d'une rotation à 90° en sens horaire
        switch((*e).modif_d())
        {
            case 1: // Ouest
                x--;
                break;
            case 2: // Nord
                y--;
                break;
            case 3: // Est
                x++;
                break;
            case 4: // Sud
                y++;
                break;
        }
        // On récupère la nouvelle case
        e = &pl.get_case(x, y);
    }
    // On marque la case atteinte comme "occupée"
    (*e).set_o(true);

    // Si la fourmi a atteint un bord du plateau
    if(pl.est_au_bord(x, y))
    {
        // On agrandit le plateau
        ++pl;
    }
}

unsigned int Fourmi::get_d()
{
    return d;
}

bool operator<(const Fourmi& a, const Fourmi& b)
{
    return a.d < b.d;
}
