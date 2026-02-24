//
// Created by jfgarcianata on 8/02/26.
//
#include <iostream>
#include "MazoPrincipal.h"
#include "../Cartas/Carta.h"
#include "../Cartas/CartaAccion.h"
#include "../Cartas/CartaNumero.h"
#include "../Cartas/CartaComodin.h"
#include "../Cartas/CartaRobaTodo.h"

using namespace std;

MazoPrincipal::MazoPrincipal(): cabeza(nullptr), size(0){}

MazoPrincipal::~MazoPrincipal()
{
    while (!estaVacio())
    {
        Carta* carta = eliminarCarta();
        delete carta;
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

void MazoPrincipal::llenarMazo(int jugadores)
{
    int cantidadMazos = ((jugadores - 1)/6) + 1;
    int totalCartas = 108 * cantidadMazos;

    Carta** cartas = new Carta*[totalCartas];
    int indice = 0;

    string colores[] = {"Rojo", "Verde", "Azul", "Amarillo"};

    for (int m = 0; m < cantidadMazos; m++)
    {
        for (int i = 0; i < 4; i++)
        {
            string color = colores[i];
            cartas[indice++] = new CartaNumero(color, 0);
            for (int num = 1; num <= 9; num++)
            {
                cartas[indice++] = new CartaNumero(color, num);
                cartas[indice++] = new CartaNumero(color, num);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            string color = colores[i];
            for (int j = 0; j < 2; j++)
            {
                cartas[indice++] = new CartaAccion(color, "🚫");
                cartas[indice++] = new CartaAccion(color, "🔄");
                cartas[indice++] = new CartaAccion(color, "+2");
            }
        }

        for (int i = 0; i < 2; i++)
            cartas[indice++] = new CartaComodin("🎨");

        for (int i = 0; i < 4; i++)
            cartas[indice++] = new CartaComodin("+4🎨");

        for (int i = 0; i < 6; i++)
            cartas[indice++] = new CartaRobaTodo();
    }

    srand(time(nullptr));
    for (int i = totalCartas - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Carta* aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }

    for (int i = 0; i < totalCartas; i++)
        insertarCarta(cartas[i]);

    delete[] cartas;
}