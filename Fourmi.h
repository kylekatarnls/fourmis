using namespace std;

#ifndef FOURMI_H_INCLUDED
#define FOURMI_H_INCLUDED

#include "Plateau.h"

class Fourmi
{
    private:
        int x, y;
        unsigned int d;
    public:
        Fourmi(Plateau& pl);
        unsigned int get_d();
        friend bool operator<(const Fourmi& a, const Fourmi& b);
};

#endif // FOURMI_H_INCLUDED
