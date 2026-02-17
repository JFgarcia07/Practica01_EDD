//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_CARTAFLIP_H
#define PRACTICA01_EDD_CARTAFLIP_H
#include "Carta.h"

class CartaFlip : public Carta
{
    private:
    string simboloOscuro;
    string colorOscuro;

    public:
    CartaFlip();
    CartaFlip(string simboloOscuro, string colorOscuro);
    void mostrarCartaEspecial(bool modoOscuro);
};
#endif //PRACTICA01_EDD_CARTAFLIP_H