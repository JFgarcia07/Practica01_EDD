//
// Created by jfgarcianata on 8/02/26.
//

#include <iostream>
#include "CartaFlip.h"

using namespace std;

CartaFlip::CartaFlip(string simboloOscuro, string colorOscuro)
{
    this->colorOscuro = colorOscuro;
    this->simboloOscuro = simboloOscuro;
}

void CartaFlip::mostrarCartaEspecial(bool modoOscuro)
{
    if (!modoOscuro) {
        cout << "[Lado Claro: " << color << simbolo << " ]" << endl;
    } else {
        cout << "[Lado Oscuro: " << colorOscuro << simboloOscuro << " ]" << endl;
    }
}
