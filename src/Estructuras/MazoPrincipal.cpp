//
// Created by jfgarcianata on 8/02/26.
//
#include <iostream>
#include "MazoPrincipal.h"
#include "../DAO/Carta.h"

using namespace std;

MazoPrincipal::MazoPrincipal(): cabeza(nullptr), size(0){}

MazoPrincipal::MazoPrincipal(Carta* carta)
{
    cabeza = new NodoCarta(carta);
    size = 1;
}

bool MazoPrincipal::estaVacio()
{
    return size == 0;
}

int MazoPrincipal::getSize()
{
    return size;
}

void MazoPrincipal::insertarCarta(Carta* carta)
{
    if (cabeza == nullptr)
    {
        cabeza = new NodoCarta(carta);
    } else
    {
        NodoCarta* actual = cabeza;
        while (actual->getSiguienteCarta() != nullptr)
        {
            actual = actual->getSiguienteCarta();
        }
        actual->setSiguienteCarta(new NodoCarta(carta));
    }
    size++;
}

void MazoPrincipal::eliminarCarta()
{
    if (cabeza == nullptr) return;

    NodoCarta* siguiente = cabeza->getSiguienteCarta();
    delete cabeza;
    cabeza = siguiente;
    size--;
}

void MazoPrincipal::mostrarData()
{
    NodoCarta* actual = cabeza;

    while (actual != nullptr)
    {
        Carta* carta = actual->getCarta();
        carta->mostrarCarta();

        actual = actual->getSiguienteCarta();
    }
}

MazoPrincipal::~MazoPrincipal()
{
    while (!estaVacio())
    {
        eliminarCarta();
    }
}

Carta* MazoPrincipal::getCarta()
{

}
