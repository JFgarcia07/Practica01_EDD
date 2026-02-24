//
// Created by jfgarcianata on 24/02/26.
//

#ifndef PRACTICA01_EDD_CARTAROBATODO_H
#define PRACTICA01_EDD_CARTAROBATODO_H
#include "Carta.h"

class CartaRobaTodo: public Carta
{
    public:
    CartaRobaTodo();
    void mostrar() const override;
};

#endif //PRACTICA01_EDD_CARTAROBATODO_H