//
// Created by jfgarcianata on 14/02/26.
//

#ifndef PRACTICA01_EDD_MANOJUGADOR_H
#define PRACTICA01_EDD_MANOJUGADOR_H

#include "NodoCarta.h"
#include  "NodoMano.h"

class ManoJugador
{
    private:
    NodoMano* cabeza;
    int size;

    public:
    ManoJugador();
    ~ManoJugador();

    void agregarCarta(Carta* carta);
    Carta* eliminarCarta(int posicion);

    void ordenarCartas();
    void mostrarCartas() const;
    int compararCarta(Carta* carta1, Carta* carta2);

    bool estaVacio() const;
    int getSize() const;
};

#endif //PRACTICA01_EDD_MANOJUGADOR_H