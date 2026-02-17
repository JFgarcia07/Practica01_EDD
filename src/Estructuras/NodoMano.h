//
// Created by jfgarcianata on 14/02/26.
//

#ifndef PRACTICA01_EDD_NODOMANO_H
#define PRACTICA01_EDD_NODOMANO_H

#include "../Cartas/Carta.h"

class NodoMano
{
private:
    Carta* carta;
    NodoMano* siguiente;

public:
    NodoMano(Carta* carta);

    Carta* getCarta() const;
    NodoMano* getSiguiente() const;

    void setSiguiente(NodoMano* siguiente);

};
#endif //PRACTICA01_EDD_NODOMANO_H