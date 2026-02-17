//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_NODOCARTA_H
#define PRACTICA01_EDD_NODOCARTA_H
#include "../Cartas/Carta.h"

class NodoCarta
{
    private:
        Carta* carta;
        NodoCarta* siguiente;
    public:
        NodoCarta(Carta* carta);
        void setSiguienteCarta(NodoCarta* siguiente);
        NodoCarta* getSiguienteCarta();
        Carta* getCarta();
};
#endif //PRACTICA01_EDD_NODOCARTA_H