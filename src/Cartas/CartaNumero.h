//
// Created by jfgarcianata on 13/02/26.
//

#ifndef PRACTICA01_EDD_CARTANUMERO_H
#define PRACTICA01_EDD_CARTANUMERO_H

#include "Carta.h"

class CartaNumero : public Carta
{
    private:
    int numero;

    public:
    CartaNumero(string color, int numero);

    int getNumero() const;
    void mostrar() const override;
};

#endif //PRACTICA01_EDD_CARTANUMERO_H

