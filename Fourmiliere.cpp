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
    unsigned int d = popu[n].get_d();
    unsigned int min = d;
    unsigned int min_n = n;
    unsigned int max = d;
    unsigned int max_n = n;
    unsigned int sum = d;
    for(unsigned int i = n; i <= m; i++)
    {
        d = popu[i].get_d();
        if(d < min)
        {
            min = d;
            min_n = i;
        }
        else if(d > max)
        {
            max = d;
            max_n = i;
        }
        sum += d;
    }
    double avg = (double) sum / (double) (m - n + 1);
    cout << "Minimum : " << min << " par la fourmi " << (min_n + 1) << endl;
    cout << "Maximum : " << max << " par la fourmi " << (max_n + 1) << endl;
    cout << "Moyenne : " << avg << endl;
}

