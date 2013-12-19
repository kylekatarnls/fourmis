using namespace std;

#include "Plateau.h"
#include <iostream>

// Constructeur vierge
Plateau::Plateau()
{
    // set_tab crée un tab vierge
    set_tab(9, 15); // dimensions par défaut
}

Plateau::Plateau(unsigned int h, unsigned int l)
{
    // set_tab crée un tab vierge
    set_tab(h, l); // dimensions fournies en paramètres
}

void Plateau::set_tab(unsigned int h, unsigned int l)
{
    hauteur = h;
    largeur = l;

    // Si hauteur est paire ou que largeur est paire
    if(!(hauteur & 1) || !(largeur & 1))
    {
        hauteur = 9;
        largeur = 15;
    }

    // Parcoure en largeur et hauteur et assignation de toutes les cases à un Etat par défaut
    tab = new Etat*[largeur];
    for(unsigned int x = 0; x < largeur; x++)
    {
        tab[x] = new Etat[hauteur];
        for(unsigned int y = 0; y < hauteur; y++)
        {
            Etat t;
            tab[x][y] = t;
        }
    }
}

Plateau::~Plateau()
{
    // Parcoure en largeur et hauteur et libération de la mémoire pour chaque case et chaque ligne
    for(unsigned int x = 0; x < largeur; x++)
    {
        for(unsigned int y = 0; y < hauteur; y++)
        {
            delete &tab[x][y];
        }
        delete tab[x];
    }
    delete tab;
}

// Constructeur par copie
Plateau::Plateau(Plateau& pl)
{
    largeur = pl.largeur;
    hauteur = pl.hauteur;

    // Parcoure en largeur et hauteur et copie des valeurs de pl
    tab = new Etat*[largeur];
    for(unsigned int x = 0; x < largeur; x++)
    {
        tab[x] = new Etat[hauteur];
        for(unsigned int y = 0; y < hauteur; y++)
        {
            tab[x][y] = pl.tab[x][y];
        }
    }
}

// Opérateur = appelle le constructeur par copie et retourne le résultat
Plateau& Plateau::operator=(Plateau& pl)
{
    Plateau plateau(pl);
    return plateau;
}

// Affichage du plateau
void Plateau::affiche()
{
    for(unsigned int y = 0; y < hauteur; y++)
    {
        for(unsigned int x = 0; x < largeur; x++)
        {
            cout << tab[x][y].symbole();
        }
        cout << endl;
    }
}

// Récupération de l'état d'une case
Etat& Plateau::get_case(unsigned int x, unsigned int y)
{
    return tab[x][y];
}
unsigned int Plateau::get_h()
{
    return hauteur;
}
unsigned int Plateau::get_l()
{
    return largeur;
}

bool Plateau::est_au_bord(unsigned int x, unsigned int y)
{
    return (x == 0 || y == 0 || x == largeur - 1 || y == hauteur - 1);
}

Plateau& Plateau::operator++(void)
{
    hauteur += 2;
    largeur += 2;
    Etat** tab2 = new Etat*[largeur];
    for(unsigned int x = 0; x < largeur; x++)
    {
        tab2[x] = new Etat[hauteur];
        for(unsigned int y = 0; y < hauteur; y++)
        {
            if(est_au_bord(x, y))
            {
                Etat t;
                tab2[x][y] = t;
            }
            else
            {
                tab2[x][y] = tab[x-1][y-1];
            }
        }
    }
    tab = tab2;
    return *this;
}
