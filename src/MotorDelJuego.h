//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_MOTORDELJUEGO_H
#define PRACTICA01_EDD_MOTORDELJUEGO_H
#include "Estructuras/ListaJugadores.h"
#include "Estructuras/MazoPrincipal.h"

class MotorDelJuego
{
private:
    ListaJugadores listaJugadores;
    MazoPrincipal mazoPrincipal;
    NodoJugador* jugadorActual;
    Carta* cartaEnMesa;

public:
    MotorDelJuego();
    void iniciarJuego();
    void bienvenida();
    void crearJugadores();
    void repartirCartas(int cantidad);
    void mostrarTurno();

};
#endif //PRACTICA01_EDD_MOTORDELJUEGO_H