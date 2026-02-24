//
// Created by jfgarcianata on 24/02/26.
//

#include "CartaRobaTodo.h"
#include <iostream>
using namespace std;

CartaRobaTodo::CartaRobaTodo() : Carta("Negro", "RobaTodo", false) {}

void CartaRobaTodo::mostrar() const
{
    cout << "[Negro 💀]" << endl;
}