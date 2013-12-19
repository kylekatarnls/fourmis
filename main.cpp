using namespace std;

#include <string>
#include <windows.h>
#include <iostream>
#include "Fourmiliere.h"
#define IMAGES_PAR_SECONDE 6

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

int main()
{
    Plateau pl;
    /*
        // Pour tester l'opérateur =
        Plateau pl2 = pl;
        pl2.affiche();
    */
    Fourmiliere f(pl);
    while(true)
    {
        // Si l'utilisateur appuie sur Echap
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            return EXIT_SUCCESS;
        }
        // Si la console est de type DOS/Windows
        if(system("CLS"))
        {
            // Effacement
            system("clear");
        }
        // Ajoute d'une fourmi
        f.ajout();
        // Affichage de la formulière (sur le plateau)
        f.affiche();


        cout << endl << endl;
        // Si l'utilisateur appuie sur Espace
        if(GetAsyncKeyState(VK_SPACE))
        {
            int min, max;
            cout << "Premiere fourmi : ";
            cin >> min;
            cout << "Derniere fourmi : ";
            cin >> max;
            // Afficher les statistiques pour les fourmis min à max
            f.stats(min-1, max-1);
        }
        else
        {
            // Afficher les statistiques pour toutes les fourmis
            f.stats();
        }


        cout << endl << endl;
        // Si l'utilisateur appuie sur Entrée
        if(GetAsyncKeyState(VK_RETURN))
        {
            // Pause avec affichage personnalisé
            cout << "Fleche droite : reprendre     Entree : pas a pas";
            system("pause > nul");
        }
        else
        {
            // Affichage des contrôles possibles
            cout << "Echap : quitter    Entree : pause   Espace : statistiques" << endl;
        }
        // Délais entre les images de l'animation
        Sleep(1000/IMAGES_PAR_SECONDE);
    }
    return EXIT_SUCCESS;
}
