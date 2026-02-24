//
// Created by jfgarcianata on 13/02/26.
//

#include "CartaComodin.h"
#include <iostream>

CartaComodin::CartaComodin(string efecto) : Carta("Negro", "Comodin", false)
{
    this->efecto = efecto;
}

string CartaComodin::getEfecto() const
{
    return efecto;
}

void CartaComodin::mostrar() const
{
    cout << "[Negro " << efecto << "]" << endl;
}

void CartaComodin::setColor(string color)
{
    this->color = color;
}
