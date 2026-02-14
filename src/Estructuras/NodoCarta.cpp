//
// Created by jfgarcianata on 8/02/26.
//

#include "NodoCarta.h"
#include "../DAO/Carta.h"

NodoCarta::NodoCarta(Carta* carta)
{
    this->carta = carta;
    this->siguiente = nullptr;
}

Carta* NodoCarta::getCarta()
{
    return carta;
}

NodoCarta* NodoCarta::getSiguienteCarta()
{
    return siguiente;
}

void NodoCarta::setSiguienteCarta(NodoCarta* siguiente)
{
    this->siguiente = siguiente;
}