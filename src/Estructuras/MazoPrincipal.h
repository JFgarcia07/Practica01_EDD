//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_MAZOPRINCIPAL_H
#define PRACTICA01_EDD_MAZOPRINCIPAL_H
#include "NodoCarta.h"
#include "../DAO/Carta.h"

class MazoPrincipal
{
    private:
        NodoCarta* cabeza;
        int size;
    public:
        MazoPrincipal();
        MazoPrincipal(Carta* carta);
        ~MazoPrincipal();
        bool estaVacio();
        void insertarCarta(Carta* carta);
        int getSize();
        void eliminarCarta();
        void mostrarData();
        Carta* getCarta();
};
#endif //PRACTICA01_EDD_MAZOPRINCIPAL_H