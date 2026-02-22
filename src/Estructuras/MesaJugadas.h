//
// Created by jfgarcianata on 21/02/26.
//

#ifndef PRACTICA01_EDD_MASAJUGADAS_H
#define PRACTICA01_EDD_MASAJUGADAS_H
#include <inttypes.h>

#include "MazoPrincipal.h"
#include "NodoCarta.h"
#include "MesaJugadas.h"

class MesaJugadas
{
    private:
    NodoCarta* cabeza;
    int size;

    public:
    MesaJugadas();
    ~MesaJugadas();

    void agregarCarta(Carta* carta);
    Carta* verUltimaCarta();
    void reciclarAlMazo(MazoPrincipal& mazo);
    bool estaVacia();
    int getSize();
};

#endif //PRACTICA01_EDD_MASAJUGADAS_H