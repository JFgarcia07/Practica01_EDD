//
// Created by jfgarcianata on 14/02/26.
//

#ifndef PRACTICA01_EDD_NODOJUGADOR_H
#define PRACTICA01_EDD_NODOJUGADOR_H

#include "../DAO/Jugador.h"

class NodoJugador
{
        private:
        Jugador* jugador;
        NodoJugador* siguiente;
        NodoJugador* anterior;

        public:
        NodoJugador(Jugador* jugador);

        Jugador* getJugador();

        NodoJugador* getSiguiente();
        NodoJugador* getAnterior();

        void setSiguiente(NodoJugador* siguiente);
        void setAnterior(NodoJugador* anterior);
};

#endif //PRACTICA01_EDD_NODOJUGADOR_H