//
// Created by jfgarcianata on 7/02/26.
//
#include "MotorDelJuego.h"
#include <iostream>
#include "../src/DAO/Carta.h"
#include "Estructuras/MazoPrincipal.h"
#include "Estructuras/NodoCarta.h"

using namespace std;

void MotorDelJuego::bienvenida()
{
    cout << "=========================================\n";
    cout << "              BIENVENIDO UNO             \n";
    cout << "=========================================\n";
    cout << "Gracias por usar nuestro programa.\n";
    cout << "Esperamos que tengas una excelente experiencia\n";
    cout << "-----------------------------------------\n";
    cout << "          ¡Disfruta tu estadía! 😊        \n";
    cout << "=========================================\n";
}


void MotorDelJuego::crearCartas()
{
    MazoPrincipal mazoPrincipal;

    mazoPrincipal.insertarCarta(new Carta("0", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("1", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("3", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("4", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("5", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("6", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("7", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("8", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("9", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("REV", "ROJO", false));
    mazoPrincipal.insertarCarta(new Carta("+2", "ROJO", false));

    mazoPrincipal.insertarCarta(new Carta("0", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("1", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("3", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("4", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("5", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("6", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("7", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("8", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("9", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("REV", "AZUL", false));
    mazoPrincipal.insertarCarta(new Carta("+2", "AZUL", false));
}

void MotorDelJuego::mostrarCartas()
{
    MazoPrincipal mazoPrincipal;
    mazoPrincipal.mostrarData();
}
