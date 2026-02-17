//
// Created by jfgarcianata on 13/02/26.
//

#include "CartaAccion.h"
#include <iostream>

CartaAccion::CartaAccion(string color, string accion)
    : Carta(color, "Accion", false) {
    this->accion = accion;
}

string CartaAccion::getAccion() const
{
    return accion;
}

void CartaAccion::mostrar() const
{
    cout << "[" << color << " " << accion <<  "]" << endl;
}
