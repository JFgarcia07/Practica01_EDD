//
// Created by jfgarcianata on 14/02/26.
//
#include "NodoMano.h"
#include "../Cartas/Carta.h"

NodoMano::NodoMano(Carta* carta)
{
    this->carta = carta;
    this->siguiente = nullptr;
}

Carta* NodoMano::getCarta() const
{
    return carta;
}

NodoMano* NodoMano::getSiguiente() const
{
    return siguiente;
}

void NodoMano::setSiguiente(NodoMano* siguiente)
{
    this->siguiente = siguiente;
}


