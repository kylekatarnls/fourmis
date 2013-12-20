using namespace std;

#include <iostream>
#include "Fourmiliere.h"

unsigned int Fourmiliere::nb = 0;

Fourmiliere::Fourmiliere(Plateau& pl)
{
    plateau = &pl;
}

void Fourmiliere::ajout()
{
    nb++;
    // Création d'une fourmi sur le plateau
    Fourmi f(*plateau);
    // Ajout de la formi à la population de la fourmilière
    popu.push_back(f);
}

void Fourmiliere::affiche()
{
    cout << "Fourmi numero " << nb << endl << endl;
    (*plateau).affiche();
    cout << endl << "Distance parcourue par cette fourmi : " << popu[nb-1].get_d();
}
void Fourmiliere::stats()
{
    // À défaut de paramètres les statistiques vont de la première fourmi à la dernière fourmi
    stats(0, nb-1);
}
void Fourmiliere::stats(unsigned int n, unsigned int m)
{
    // S'il n'y a aucune fourmi
    if(nb == 0)
    {
        cout << "Aucune fourmi" << endl;
        return;
    }
    // Si n est supérieur à m, on les inverse
    if(n > m)
    {
        unsigned int t = m;
        m = n;
        n = t;
        delete &t;
    }
    // Si m ou n dépassent nb, on les limite
    if(m >= nb)
    {
        m = nb-1;
        if(n >= nb)
        {
            n = nb-1;
        }
    }
    // Initialisation des données de statistique avec les valeurs de la première fourmi de la sélection [ n -> m ]
    unsigned int min_n = n;
    unsigned int max_n = n;
    unsigned int sum = popu[n].get_d();
    // Pour chacune des autres fourmis de la sélection
    for(unsigned int i = n; i <= m; i++)
    {
        // Si elle bat le reccord du minimum
        if(popu[i] < popu[min_n])
        {
            min_n = i;
        }
        // Si elle bat le reccord du maximum
        else if(popu[max_n] < popu[i])
        {
            max_n = i;
        }
        // Ajout de la distance au total
        sum += popu[i].get_d();;
    }
    // Calcul de moyenne en fonction du total et du nombre de fourmis
    double avg = (double) sum / (double) (m - n + 1);
    cout << "Minimum : " << popu[min_n].get_d() << " par la fourmi " << (min_n + 1) << endl;
    cout << "Maximum : " << popu[max_n].get_d() << " par la fourmi " << (max_n + 1) << endl;
    cout << "Moyenne : " << avg << endl;
}

