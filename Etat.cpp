using namespace std;

#include "Etat.h"

Etat::Etat()
{
    occupe = false;
    direction = 1;
}
Etat::Etat(bool o, unsigned int d)
{
    occupe = o;
    set_d(d);
}

// getter occupe
bool Etat::get_o()
{
    return occupe;
}

// getter direction
unsigned int Etat::get_d()
{
    return direction;
}

// setter occupe
void Etat::set_o(bool o)
{
    occupe = o;
}

// setter direction
void Etat::set_d(unsigned int d)
{
    if(direction < 1 && direction > 4)
    {
        direction = 1;
    }
}

// Incrémente la direction (rotation de 90° en sens horaire) et retourne la valeur modifiée
unsigned int Etat::modif_d()
{
    return direction = direction % 4 + 1;
}

// Retourne un symbole en fonction de la direction et de l'occupation de la case
char Etat::symbole()
{
    char symboles[8] = {'o', 'n', 'e', 's', 'O', 'N', 'E', 'S'};
    return symboles[(direction-1) | (occupe ? 4 : 0)];
}
