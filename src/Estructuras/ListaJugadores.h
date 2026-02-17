//
// Created by jfgarcianata on 14/02/26.
//

#ifndef PRACTICA01_EDD_LISTAJUGADORES_H
#define PRACTICA01_EDD_LISTAJUGADORES_H

#include "NodoJugador.h"

class ListaJugadores
{
    private:
    NodoJugador* cabeza;
    int size;
    bool sentidoHorario;

    public:
    ListaJugadores();
    ~ListaJugadores();

    void agregarJugador(string nombre);
    void avanzarTurno();
    void cambiarSentido();

    Jugador* getJugadorActual();

    bool estaVacia();
    int getSize() const;

    void mostrarJugadores() const;

};
#endif //PRACTICA01_EDD_LISTAJUGADORES_H