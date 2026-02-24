//
// Created by jfgarcianata on 14/02/26.
//

#include <iostream>
#include "ManoJugador.h"
#include "NodoMano.h"
#include "../Cartas/CartaNumero.h"

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

void ManoJugador::ordenarCartas()
{
    if(size <= 1){return;}

    Carta** arreglo = new Carta*[size];
    NodoMano* actual = cabeza;
    for (int i = 0; i < size; i++)
    {
        arreglo[i] = actual->getCarta();
        actual = actual->getSiguiente();
    }

    int salto = size/2;

    while (salto > 0)
    {
        for (int i = salto; i < size; i++)
        {
            Carta* aux = arreglo[i];
            int j = i;

            while (j >= salto && compararCarta(arreglo[j - salto], aux) > 0)
            {
                arreglo[j] = arreglo[j - salto];
                j = j - salto;
            }
            arreglo[j] = aux;
        }
        salto = salto/2;
    }

    NodoMano* nodo = cabeza;
    for (int i = 0; i < size; i++)
    {
        nodo->setCarta(arreglo[i]);
        nodo = nodo->getSiguiente();
    }

    delete[] arreglo;
}

int ManoJugador::compararCarta(Carta* carta1, Carta* carta2)
{
    if (carta1->getColor() != carta2->getColor())
    {
        return carta1->getColor().compare(carta2->getColor());
    }

    if (carta1->getTipo() == "Comodin") {return 1;}
    if (carta2->getTipo() == "Comodin") {return -1;}

    if (carta1->getTipo() == "Numero" && carta2->getTipo() == "Accion") {return 1;}
    if (carta1->getTipo() == "Accion" && carta2->getTipo() == "Numero") {return -1;}

    if (carta1->getTipo() == "Numero" && carta2->getTipo() == "Numero")
    {
        CartaNumero* cn1 = dynamic_cast<CartaNumero*>(carta1);
        CartaNumero* cn2 = dynamic_cast<CartaNumero*>(carta2);

        if (cn1 && cn2)
        {
            return cn1->getNumero() - cn2->getNumero();
        }
    }

    return 0;
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

    for (int i = 0; i < posicion - 1; i++)
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

int ManoJugador::getSize() const
{
    return size;
}


bool ManoJugador::estaVacio() const
{
    return size == 0;
}
