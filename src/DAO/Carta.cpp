//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include  "Carta.h"

using namespace std;

Carta::Carta(string color, string tipo)
{
    this->color = color;
    this->tipo = tipo;
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

