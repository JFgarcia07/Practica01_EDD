//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador(string nombre, bool gritoUno)
{
    this->nombre = nombre;
    this->gritoUno = gritoUno;
}

void Jugador::jugarCarta()
{

}

void Jugador::robarCarta()
{

}

void Jugador::gritarUno()
{

}

string Jugador::getNombre()
{
    return nombre;
}

void Jugador::setNombre(string nombre)
{
    this->nombre = nombre;
}


