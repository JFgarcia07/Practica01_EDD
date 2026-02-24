//
// Created by jfgarcianata on 21/02/26.
//

#ifndef PRACTICA01_EDD_LOGICAJUEGO_H
#define PRACTICA01_EDD_LOGICAJUEGO_H
#include "ConfiguracionJuego.h"
#include "../Cartas/Carta.h"
#include "../Estructuras/ListaJugadores.h"
#include "../Estructuras/MesaJugadas.h"

class LogicaJuego
{
private:
    ListaJugadores& jugadores;
    MazoPrincipal& mazoPrincipal;
    MesaJugadas& mesaJugadas;
    ConfiguracionJuego& configuracion;
    int acumulado;
    bool hayAcumulado;

public:
    LogicaJuego(ListaJugadores& jugadores, MazoPrincipal& mazoPrincipal, MesaJugadas& mesaJugadas,
        ConfiguracionJuego& configuracion);
    bool cartaEsJugable(Carta* cartaJugada, Carta* cartaEnMesa);
    void aplicarEfecto(Carta* carta);
    bool manejarRobo(Jugador* jugador, Carta* cartaEnMesa);
};
#endif //PRACTICA01_EDD_LOGICAJUEGO_H