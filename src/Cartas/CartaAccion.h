//
// Created by jfgarcianata on 13/02/26.
//

#ifndef PRACTICA01_EDD_CARTAACCION_H
#define PRACTICA01_EDD_CARTAACCION_H

#include "Carta.h"

class CartaAccion : public Carta
{
    private:
    string accion;

    public:
    CartaAccion(string color, string accion);

    string getAccion() const;
    void mostrar() const override;
};

#endif //PRACTICA01_EDD_CARTAACCION_H