using namespace std;

#include <iostream>
#include <windows.h>
#include "Animations.h"

// Texte défilant lors de l'arrêt du logiciel
void Animations::quitter()
{
    for(unsigned int i = 0; i < 33; i++)
    {
        if(i == 20)
        {
            cout << "         Fin de la demonstration" <<
            endl << "         ~~~~~~~~~~~~~~~~~~~~~~~";
        }
        else
        {
            cout << endl;
        }
        Sleep(30);
    }
    Sleep(2000);
}
