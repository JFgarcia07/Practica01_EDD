//
// Created by jfgarcianata on 7/02/26.
//
#include "MotorDelJuego.h"
#include <iostream>
#include "Cartas/Carta.h"
#include "Estructuras/ListaJugadores.h"
#include "Estructuras/MazoPrincipal.h"

using namespace std;

MotorDelJuego::MotorDelJuego()
{
    jugadorActual = nullptr;
    cartaEnMesa = nullptr;
}

void MotorDelJuego::iniciarJuego()
{
    bienvenida();
    crearJugadores();

    repartirCartas(7);

    cartaEnMesa = mazoPrincipal.eliminarCarta();

    if (cartaEnMesa == nullptr)
    {
        cout << "Error: No se pudo obtener carta inicial.\n";
        return;
    }
    cout << "\nCarta inicial en mesa:\n";
    cartaEnMesa->mostrar();

    mostrarTurno();
}

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

    jugadorActual = listaJugadores.getCabeza();

    cout << "Jugadores creados correctamente ";

    for (int i = 0; i < numeroDeJugadores; i++) {
        cout << listaJugadores.getJugadorActual()->getNombre() << endl;
        listaJugadores.avanzarTurno();
    }

    mazoPrincipal.llenarMazo(numeroDeJugadores);
}

void MotorDelJuego::repartirCartas(int cantidad)
{

    if (listaJugadores.estaVacia())
    {
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        NodoJugador* temp = listaJugadores.getCabeza();
        do {
            Carta* carta = mazoPrincipal.eliminarCarta();
            if (carta != nullptr)
                temp->getJugador()->getManoJugador().agregarCarta(carta);
            temp = temp->getSiguiente();
        } while (temp != listaJugadores.getCabeza());
    }
}

void MotorDelJuego::mostrarTurno()
{
    cout << "\n----------------------------------\n";
    cout << "Turno de: " << listaJugadores.getJugadorActual()->getNombre() << endl;

    listaJugadores.getJugadorActual()->mostrarManoJugador();
}
