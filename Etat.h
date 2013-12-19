using namespace std;

#ifndef ETAT_H_INCLUDED
#define ETAT_H_INCLUDED

class Etat
{
    private:
        bool occupe;
        unsigned int direction;
        /*
        1 : ouest
        2 : nord
        3 : est
        4 : sud
        */
    public:
        Etat();
        Etat(bool o, unsigned int d);
        bool get_o();
        unsigned int get_d();
        void set_o(bool o);
        void set_d(unsigned int d);
        unsigned int modif_d();
        char symbole();
};

#endif // ETAT_H_INCLUDED
