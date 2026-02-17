//
// Created by jfgarcianata on 7/02/26.
//
#include "MotorDelJuego.h"
#include <iostream>
#include "Cartas/Carta.h"
#include "Estructuras/ListaJugadores.h"
#include "Estructuras/MazoPrincipal.h"

using namespace std;

void MotorDelJuego::bienvenida()
{
    cout << "==============================================\n";
    cout << "                 BIENVENIDO UNO               \n";
    cout << "==============================================\n";
    cout << "Gracias por usar nuestro programa.\n";
    cout << "Esperamos que tengas una excelente experiencia\n";
    cout << "----------------------------------------------\n";
    cout << "             ¡Disfruta tu estadía! 😊         \n";
    cout << "==============================================\n";
    cout << endl;
}

void MotorDelJuego::crearJugadores()
{
    ListaJugadores listaJugadores;
    int numeroDeJugadores;
    string nombreJugador;


    cout << "Ingrese la cantidad de jugadiores que participaran: ";

    while (!(cin >> numeroDeJugadores) || numeroDeJugadores < 2)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ERROR: Debe de ingresar un valor numerico mayor o igual a 2" << endl;
        cout << "Ingrese la cantidad de jugadiores que participaran: ";
    }

    for (int i = 0; i < numeroDeJugadores; i++)
    {
        cout << "Ingrese el nombre del Jugador " << i + 1 << ":" << endl;
        cin  >> nombreJugador;

        listaJugadores.agregarJugador(nombreJugador);

        nombreJugador.clear();
    }

    cout << "Jugadores creados correctamente ";

    for (int i = 0; i < numeroDeJugadores; i++) {
        cout << listaJugadores.getJugadorActual()->getNombre() << endl;
        listaJugadores.avanzarTurno();
    }
}

