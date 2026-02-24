//
// Created by jfgarcianata on 7/02/26.
//
#include "MotorDelJuego.h"
#include <iostream>

#include "Cartas/Carta.h"
#include "Estructuras/ListaJugadores.h"
#include "Estructuras/MazoPrincipal.h"

using namespace std;

MotorDelJuego::MotorDelJuego(): logica(listaJugadores, mazoPrincipal, mesaJugadas, configuracion)
{
    jugadorActual = nullptr;
    cartaEnMesa = nullptr;
    ganador = nullptr;
}

void MotorDelJuego::iniciarJuego()
{
    bienvenida();
    crearJugadores();

    configuracion.configAcumulacion();
    configuracion.configRetoMas4();
    configuracion.configModoRobo();
    configuracion.configGanarConNegra();

    repartirCartas(7);

    cartaEnMesa = mazoPrincipal.eliminarCarta();

    while (cartaEnMesa != nullptr && cartaEnMesa->getTipo() != "Numero")
    {
        mazoPrincipal.insertarCarta(cartaEnMesa);
        cartaEnMesa = mazoPrincipal.eliminarCarta();
    }

    if (cartaEnMesa == nullptr)
    {
        cout << "Error: No se pudo obtener carta inicial.\n";
        return;
    }

    cout << "\nCarta inicial en mesa:\n";
    cartaEnMesa->mostrar();

    while (!hayGanador())
    {
        mostrarTurno();
        procesarTurno();
        listaJugadores.avanzarTurno();
    }

    mostrarGanador();
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

    NodoJugador* temp = listaJugadores.getCabeza();
    do {
        cout << temp->getJugador()->getNombre() << endl;
        temp = temp->getSiguiente();
    } while (temp != listaJugadores.getCabeza());

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
    //system("clear");
    cout << "\n----------------------------------\n";
    cout << "Turno de: " << listaJugadores.getJugadorActual()->getNombre() << endl;

    listaJugadores.getJugadorActual()->mostrarManoJugador();
}

void MotorDelJuego::procesarTurno()
{
    Jugador* jugador = listaJugadores.getJugadorActual();
    int opcion;
    int totalCartas = jugador->getManoJugador().getSize();

    cout << "\n----------------------------------\n";
    cout << "Cartas en Mesa: " << endl;
    cartaEnMesa->mostrar();

    cout << "Elige una carta (1-" << totalCartas << ") para jugar" << endl;
    cout << "si no puede jugar una carta, ingrese cualquier otro numero para robar" << endl;
    cin >> opcion;

    if (opcion >= 1 && opcion <= totalCartas)
    {
        Carta* cartaJugada = jugador->getManoJugador().eliminarCarta(opcion);

        if (cartaJugada == nullptr)
        {
            cout << "Error al obtener carta";
            return;
        }

        if (logica.cartaEsJugable(cartaJugada, cartaEnMesa))
        {
            mesaJugadas.agregarCarta(cartaEnMesa);
            cartaEnMesa = cartaJugada;

            cout << "Carta jugada: ";
            cartaEnMesa->mostrar();

            logica.aplicarEfecto(cartaEnMesa);

            if (jugador->getManoJugador().getSize() == 1)
            {
                string grito;
                cout << "Tienes 1 carta solamente, ESCRIBE UNO: ";
                cin.ignore();
                getline(cin, grito);

                if (grito == "UNO" || grito == "uno")
                    cout << jugador->getNombre() << " ha gritado UNO\n";
                else
                {
                    cout << "No gritaste UNO, robas 2 cartas.\n";
                    jugador->getManoJugador().agregarCarta(robarCarta());
                    jugador->getManoJugador().agregarCarta(robarCarta());
                }
            }
        }
        else
        {
            cout << "Carta no valida para jugar.\n";
            jugador->getManoJugador().agregarCarta(cartaJugada);
            logica.manejarRobo(jugador, cartaEnMesa);
        }
    }
    else
    {
        Carta* carta = robarCarta();
        if (carta != nullptr)
        {
            jugador->getManoJugador().agregarCarta(carta);
            cout << "Robaste una carta.\n";
        }
    }
}

Carta* MotorDelJuego::robarCarta()
{
    if (mazoPrincipal.estaVacio())
    {
        if (mesaJugadas.getSize() <= 1)
        {
            cout << "No hay cartas disponibles ";
            return nullptr;
        }

        cout << "Mazo vacio, reciclando cartas jugadas..." << endl;
        mesaJugadas.reciclarAlMazo(mazoPrincipal);
    }
    return mazoPrincipal.eliminarCarta();
}

bool MotorDelJuego::hayGanador()
{
    NodoJugador* temp = listaJugadores.getCabeza();
    do
    {
        if (temp->getJugador()->getManoJugador().getSize() == 0)
        {
            ganador = temp->getJugador();
            return true;
        }
        temp = temp->getSiguiente();
    } while (temp != listaJugadores.getCabeza());

    return false;
}

void MotorDelJuego::mostrarGanador()
{
    cout << "\n==========================================\n";
    cout << "     GANADOR :) , FELICIDADES: " << ganador->getNombre() << endl;
    cout << "\n==========================================\n";
}
