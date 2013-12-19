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
    direction = d;
    if(direction < 1 && direction > 4)
    {
        direction = 1;
    }
}
bool Etat::get_o()
{
    return occupe;
}
unsigned int Etat::get_d()
{
    return direction;
}
void Etat::set_o(bool o)
{
    occupe = o;
}
void Etat::set_d(unsigned int d)
{
    direction = d;
}
unsigned int Etat::modif_d()
{
    return direction = direction % 4 + 1;
}
char Etat::symbole()
{
    char symboles[8] = {'o', 'n', 'e', 's', 'O', 'N', 'E', 'S'};
    return symboles[(direction-1) | (occupe ? 4 : 0)];
}
