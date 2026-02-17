//
// Created by jfgarcianata on 13/02/26.
//

#ifndef PRACTICA01_EDD_CARTACOMODIN_H
#define PRACTICA01_EDD_CARTACOMODIN_H
#include "Carta.h"

class CartaComodin : public Carta
{
    private:
    string efecto;

    public:
    CartaComodin(string efecto);

    string getEfecto() const;
    void mostrar() const override;
};

#endif //PRACTICA01_EDD_CARTACOMODIN_H