//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_MAZOPRINCIPAL_H
#define PRACTICA01_EDD_MAZOPRINCIPAL_H
#include "NodoCarta.h"
#include "../Cartas/Carta.h"

class MazoPrincipal
{
    private:
        NodoCarta* cabeza;
        int size;
    public:
        MazoPrincipal();
        ~MazoPrincipal();

        void insertarCarta(Carta* carta);
        Carta* eliminarCarta();
        Carta* mostrarData();

        int getSize();
        bool estaVacio();

        void llenarMazo(int jugadores);
};
#endif //PRACTICA01_EDD_MAZOPRINCIPAL_H