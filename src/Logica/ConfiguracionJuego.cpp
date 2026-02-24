//
// Created by jfgarcianata on 21/02/26.
//
#include <iostream>
#include "ConfiguracionJuego.h"

using namespace std;


ConfiguracionJuego::ConfiguracionJuego()
{
    acumulacionMas2 = false;
    acumulacionMas4 = false;
    retoMas4Habilitado = false;
    modoRoboSimple = true;
    ganarConNegra = false;
}

void ConfiguracionJuego::configAcumulacion()
{
    int opcionMas2, opcionMas4;
    cout << "-------------------------------------------------" << endl;
    cout << "Permite responder a un +2 con otro +2" << endl;
    cout << "1. Habilitar   |   Cualquier otro. Deshabilitar" << endl;

    while (true)
    {
        string entrada;
        cout << "Ingrese una opcion: ";
        cin >> entrada;
        try { opcionMas2 = stoi(entrada); break; }
        catch (...) { cout << "Entrada invalida.\n"; }
    }
    acumulacionMas2 = (opcionMas2 == 1);

    cout << "-------------------------------------------------" << endl;
    cout << "Permite responder a un +4 con otro +4." << endl;
    cout << "1. Habilitar   |   Cualquier otro. Deshabilitar" << endl;

    while (true)
    {
        string entrada;
        cout << "Ingrese una opcion: ";
        cin >> entrada;
        try
        {
            opcionMas4 = stoi(entrada); break;
        }
        catch (...)
        {
            cout << "Entrada invalida." << endl;
        }
    }
    acumulacionMas4 = (opcionMas4 == 1);
}

void ConfiguracionJuego::configRetoMas4()
{
    int opcion;
    cout << "-------------------------------------------------" << endl;
    cout << "--------------------Reto del +4------------------" << endl;
    cout << "Si un jugador lanza un +4, el afectado puede Retar" << endl;
    cout << "Si el lanzador tenia otra carta: el lanzador roba 4." << endl;
    cout << "Si no tenia otra opcion: el que reto roba 6." << endl;
    cout << "1. Habilitar   |   Cualquier otro. Deshabilitar" << endl;

    while (true)
    {
        string entrada;
        cout << "Ingrese una opcion: ";
        cin >> entrada;
        try { opcion = stoi(entrada); break; }
        catch (...) { cout << "Entrada invalida." << endl; }
    }
    retoMas4Habilitado = (opcion == 1);
}

void ConfiguracionJuego::configModoRobo()
{
    int opcion;
    cout << "-------------------------------------------------" << endl;
    cout << "--------------Modo de robar cartas---------------" << endl;
    cout << "1. Robar solo 1 carta y pasar." << endl;
    cout << "Cualquier otro. Robar hasta poder jugar." << endl;

    while (true)
    {
        string entrada;
        cout << "Ingrese una opcion: ";
        cin >> entrada;
        try
        {
            opcion = stoi(entrada); break;
        }
        catch (...)
        {
            cout << "Entrada invalida." << endl;
        }
    }
    modoRoboSimple = (opcion == 1);
}

void ConfiguracionJuego::configGanarConNegra()
{
    int opcion;
    cout << "-------------------------------------------------" << endl;
    cout << "-----------------Ganar con Negra-----------------" << endl;
    cout << "El jugador puede ganar si su ultima carta es negra." << endl;
    cout << "1. Habilitar   |   Cualquier otro. Deshabilitar" << endl;

    while (true)
    {
        string entrada;
        cout << "Ingrese una opcion: ";
        cin >> entrada;
        try
        {
            opcion = stoi(entrada); break;
        }
        catch (...)
        {
            cout << "Entrada invalida" << endl;
        }
    }
    ganarConNegra = (opcion == 1);
}

bool ConfiguracionJuego::getAcumulacionMas2() { return acumulacionMas2; }
bool ConfiguracionJuego::getAcumulacionMas4() { return acumulacionMas4; }
bool ConfiguracionJuego::getRetoMas4()        { return retoMas4Habilitado; }
bool ConfiguracionJuego::getModoRoboSimple()  { return modoRoboSimple; }
bool ConfiguracionJuego::getGanarConNegra()   { return ganarConNegra; }