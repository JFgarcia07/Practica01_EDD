//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include "Carta.h"

using namespace std;

Carta::Carta(string color, string tipo, bool estaEnMano)
{
    this->color = color;
    this->tipo = tipo;
    this->estaEnMano = estaEnMano;
}

Carta::~Carta() {}

string Carta::getColor() const
{
    return color;
}

string Carta::getTipo() const
{
    return tipo;
}

bool Carta::getEstaEnMano() const
{
    return estaEnMano;
}

void Carta::setEstaEnMano(bool estaEnMano)
{
    this->estaEnMano = estaEnMano;
}

void Carta::setColor(string color)
{
    this->color = color;
}