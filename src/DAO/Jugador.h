//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_JUGADOR_H
#define PRACTICA01_EDD_JUGADOR_H
#include <string>
#include "../Estructuras/ManoJugador.h"

using namespace std;

class Jugador
{
    private:
        string nombre;
        bool gritoUno;
        ManoJugador manoJugador;

    public:
        Jugador();
        Jugador(string nombre);
        void mostrarManoJugador();

        //Getters y setters
        string getNombre();
        void setNombre(string nombre);

        ManoJugador& getManoJugador();
};
#endif //PRACTICA01_EDD_JUGADOR_H