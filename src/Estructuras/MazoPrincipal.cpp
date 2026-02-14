//
// Created by jfgarcianata on 8/02/26.
//
#include <iostream>
#include "MazoPrincipal.h"
#include "../DAO/Carta.h"

using namespace std;

MazoPrincipal::MazoPrincipal(): cabeza(nullptr), size(0){}

MazoPrincipal::~MazoPrincipal()
{
    while (!estaVacio())
    {
        eliminarCarta();
    }
}

void MazoPrincipal::insertarCarta(Carta* carta)
{
    NodoCarta* nuevo = new NodoCarta(carta);
    nuevo->setSiguienteCarta(cabeza);
    cabeza = nuevo;
    size++;
}

Carta* MazoPrincipal::eliminarCarta()
{
    if (estaVacio())
    {
        return nullptr;
    }

    NodoCarta* temporal = cabeza;
    Carta* carta = temporal->getCarta();

    cabeza = temporal->getSiguienteCarta();
    delete temporal;

    size--;
    return carta;
}

Carta* MazoPrincipal::mostrarData()
{
    if (estaVacio())
    {
        return nullptr;
    }

    return cabeza->getCarta();
}

bool MazoPrincipal::estaVacio()
{
    return cabeza == nullptr;
}

int MazoPrincipal::getSize()
{
    return size;
}
