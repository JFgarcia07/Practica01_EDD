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
    
}

void MotorDelJuego::mostrarCartas()
{
    MazoPrincipal mazoPrincipal;
    mazoPrincipal.mostrarData();
}
