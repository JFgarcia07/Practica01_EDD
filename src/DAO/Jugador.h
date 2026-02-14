//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_JUGADOR_H
#define PRACTICA01_EDD_JUGADOR_H
#include <string>

using namespace std;

class Jugador
{
    private:
        string nombre;
        bool gritoUno;

    public:
        Jugador();
        Jugador(string nombre, bool gritoUno);

        //Acciones del jugador
        void robarCarta();
        void jugarCarta();
        void gritarUno();

        //Getters y setters
        string getNombre();
        void setNombre(string nombre);
};
#endif //PRACTICA01_EDD_JUGADOR_H