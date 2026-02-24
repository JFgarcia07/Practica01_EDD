//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador(string nombre)
{
    this->nombre = nombre;
    this->gritoUno = false;
}

string Jugador::getNombre()
{
    return nombre;
}

void Jugador::setNombre(string nombre)
{
    this->nombre = nombre;
}

ManoJugador& Jugador::getManoJugador()
{
    return manoJugador;
}

void Jugador::mostrarManoJugador()
{
    manoJugador.ordenarCartas();
    cout << "Cartas de " << nombre << " : " << endl;
    manoJugador.mostrarCartas();
}

