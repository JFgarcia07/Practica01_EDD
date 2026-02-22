//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_MOTORDELJUEGO_H
#define PRACTICA01_EDD_MOTORDELJUEGO_H
#include "Estructuras/ListaJugadores.h"
#include "Estructuras/MazoPrincipal.h"
#include "Estructuras/MesaJugadas.h"

class MotorDelJuego
{
private:
    ListaJugadores listaJugadores;
    MazoPrincipal mazoPrincipal;
    NodoJugador* jugadorActual;
    Carta* cartaEnMesa;
    Jugador* ganador;
    MesaJugadas mesaJugadas;

public:
    MotorDelJuego();
    void iniciarJuego();
    void bienvenida();
    void crearJugadores();
    void repartirCartas(int cantidad);
    void mostrarTurno();
    void procesarTurno();
    Carta* robarCarta();
    void mostrarGanador();
    bool hayGanador();
};
#endif //PRACTICA01_EDD_MOTORDELJUEGO_H