//
// Created by jfgarcianata on 13/02/26.
//

#include "CartaNumero.h"
#include <iostream>

using namespace std;

CartaNumero::CartaNumero(string color, int numero)
    : Carta(color, "Numero") {
    this->numero = numero;
}

int CartaNumero::getNumero() const
{
    return numero;
}

void CartaNumero::mostrar() const
{
    cout << "[" << color << " " << numero <<  "]" << endl;
}