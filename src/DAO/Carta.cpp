//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include  "Carta.h"

using namespace std;

Carta::Carta(string simbolo, string color, bool esNegra)
{
    this->simbolo = simbolo;
    this->color = color;
    this->esNegra = esNegra;
}

void Carta::mostrarCarta()
{
    cout << "[" << color << simbolo << "]" << endl;
}

string Carta::getColor()
{
    return color;
}

string Carta::getSimbolo()
{
    return simbolo;
}

bool Carta::getEsNegra()
{
    return esNegra;
}

bool Carta::getEstaEnUso()
{
    return estaEnUso;
}

void Carta::setEstaEnUso(bool estaEnUso)
{
    this->estaEnUso = estaEnUso;
}

