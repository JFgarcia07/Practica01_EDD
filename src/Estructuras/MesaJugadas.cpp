//
// Created by jfgarcianata on 21/02/26.
//

#include "MesaJugadas.h"

#include "MazoPrincipal.h"
MesaJugadas::MesaJugadas() : cabeza(nullptr), size(0) {}

MesaJugadas::~MesaJugadas()
{
    while (cabeza != nullptr)
    {
        NodoCarta* temp = cabeza;
        cabeza = cabeza->getSiguienteCarta();
        delete temp;
    }

    size = 0;
}

void MesaJugadas::agregarCarta(Carta* carta)
{
    carta->setEstaEnMano(false);
    NodoCarta* nuevo = new NodoCarta(carta);
    nuevo->setSiguienteCarta(cabeza);
    cabeza = nuevo;
    size++;
}

Carta* MesaJugadas::verUltimaCarta()
{
    if (estaVacia())
    {
        return nullptr;
    }

    return cabeza->getCarta();
}

void MesaJugadas::reciclarAlMazo(MazoPrincipal& mazo)
{
    if (estaVacia())
    {
        return;
    }

    NodoCarta* ultimaCarta = cabeza;
    cabeza = cabeza->getSiguienteCarta();
    size--;

    int total = size;
    Carta** cartas = new Carta*[total];
    int indice = 0;

    while(!estaVacia())
    {
        NodoCarta* temp = cabeza;
        cartas[indice++] = temp->getCarta();
        cabeza = cabeza->getSiguienteCarta();
        delete temp;
        size--;
    }

    //Barajeamos el mazo
    for (int i = total - 1; i >= 0; i--)
    {
        int j = rand() % (i+1);
        Carta* aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }

    //Reinsertamos las cartas al mazo principal
    for (int i = 0; i < total; i++)
    {
        cartas[i]->setEstaEnMano(false);
        mazo.insertarCarta(cartas[i]);
    }

    delete[] cartas;

    cabeza = ultimaCarta;
    cabeza->setSiguienteCarta(nullptr);
    size = 1;
}

bool MesaJugadas::estaVacia()
{
    return size == 0;
}

int MesaJugadas::getSize()
{
    return size;
}
