//
// Created by jfgarcianata on 14/02/26.
//

#include "NodoJugador.h"

NodoJugador::NodoJugador(Jugador* jugador)
{
    this->jugador = jugador;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Jugador* NodoJugador::getJugador()
{
    return jugador;
}

NodoJugador* NodoJugador::getSiguiente()
{
    return siguiente;
}

NodoJugador* NodoJugador::getAnterior()
{
    return anterior;
}

void NodoJugador::setSiguiente(NodoJugador* siguiente)
{
    this->siguiente = siguiente;
}

void NodoJugador::setAnterior(NodoJugador* anterior)
{
    this->anterior = anterior;
}
