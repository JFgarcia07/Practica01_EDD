//
// Created by jfgarcianata on 21/02/26.
//

#ifndef PRACTICA01_EDD_LOGICAJUEGO_H
#define PRACTICA01_EDD_LOGICAJUEGO_H
#include "../Cartas/Carta.h"

class LogicaJuego
{
    public:
    bool cartaEsJugable(Carta* cartaAjugar, Carta* cartaEnMesa);
    void aplicarEfecto(Carta* carta, ListaJugadores& jugadores, MazoPrincipal& mazo);
};
#endif //PRACTICA01_EDD_LOGICAJUEGO_H