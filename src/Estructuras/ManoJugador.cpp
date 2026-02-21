//
// Created by jfgarcianata on 14/02/26.
//

#include <iostream>
#include "ManoJugador.h"
#include "NodoMano.h"

using namespace std;

ManoJugador::ManoJugador()
{
    cabeza = nullptr;
    size = 0;
}

ManoJugador::~ManoJugador()
{
    while (cabeza != nullptr)
    {
        NodoMano* aux = cabeza;
        cabeza = cabeza->getSiguiente();

        delete aux->getCarta();
        delete aux;
    }
}

void ManoJugador::agregarCarta(Carta* carta)
{
    NodoMano* nuevo = new NodoMano(carta);

    nuevo->setSiguiente(cabeza);
    cabeza = nuevo;

    size++;
}

void ManoJugador::mostrarCartas() const
{
    NodoMano* actual = cabeza;
    int index = 1;

    while (actual != nullptr)
    {
        cout << index << ". ";
        actual->getCarta()->mostrar();
        actual = actual->getSiguiente();
        index++;
    }
}

Carta* ManoJugador::eliminarCarta(int posicion)
{
    if (posicion < 1 || posicion > size)
    {
        return nullptr;
    }

    NodoMano* actual = cabeza;
    NodoMano* anterior = nullptr;

    for (int i = 0; i < posicion; i++)
    {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (anterior == nullptr)
    {
        cabeza = actual->getSiguiente();
    } else
    {
        anterior->setSiguiente(actual->getSiguiente());
    }

    Carta* carta = actual->getCarta();
    delete actual;

    size--;
    return carta;
}


