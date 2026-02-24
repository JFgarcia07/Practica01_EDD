//
// Created by jfgarcianata on 22/02/26.
//

#include "LogicaJuego.h"
#include <iostream>
#include "../Cartas/CartaAccion.h"
#include "../Cartas/CartaComodin.h"
#include "../Cartas/CartaNumero.h"
using namespace std;

LogicaJuego::LogicaJuego(ListaJugadores& jugadores, MazoPrincipal& mazoPrincipal,
               MesaJugadas& mesaJugadas, ConfiguracionJuego& configuracion)
    : jugadores(jugadores), mazoPrincipal(mazoPrincipal),
      mesaJugadas(mesaJugadas), configuracion(configuracion)
{
    acumulado = 0;
    hayAcumulado = false;
}

bool LogicaJuego::cartaEsJugable(Carta* cartaJugada, Carta* cartaEnMesa)
{
    if (cartaJugada->getTipo() == "Comodin") return true;
    if (cartaJugada->getTipo() == "RobaTodo") return true;
    if (cartaJugada->getColor() == cartaEnMesa->getColor()) return true;

    if (cartaJugada->getTipo() == "Accion" && cartaEnMesa->getTipo() == "Accion")
    {
        CartaAccion* ca1 = dynamic_cast<CartaAccion*>(cartaJugada);
        CartaAccion* ca2 = dynamic_cast<CartaAccion*>(cartaEnMesa);
        if (ca1 && ca2 && ca1->getAccion() == ca2->getAccion())
            return true;
    }

    if (cartaJugada->getTipo() == "Numero" && cartaEnMesa->getTipo() == "Numero")
    {
        CartaNumero* cn1 = dynamic_cast<CartaNumero*>(cartaJugada);
        CartaNumero* cn2 = dynamic_cast<CartaNumero*>(cartaEnMesa);
        if (cn1 && cn2 && cn1->getNumero() == cn2->getNumero())
            return true;
    }

    return false;
}

void LogicaJuego::aplicarEfecto(Carta* carta)
{
    if (carta->getTipo() == "Accion")
    {
        CartaAccion* accion = dynamic_cast<CartaAccion*>(carta);
        if (!accion) return;

        if (accion->getAccion() == "🚫")
        {
            cout << "Carta Bloqueo! El siguiente jugador pierde su turno.\n";
            jugadores.saltarTurno();
        }
        else if (accion->getAccion() == "🔄")
        {
            cout << "Carta Reversa! Se cambia el sentido.\n";
            jugadores.cambiarSentido();
        }
        else if (accion->getAccion() == "+2")
        {
            if (configuracion.getAcumulacionMas2() && hayAcumulado)
            {
                acumulado += 2;
                cout << "Acumulacion! El siguiente jugador robara " << acumulado << " cartas.\n";
            }
            else
            {
                acumulado = 2;
                jugadores.avanzarTurno();
                Jugador* afectado = jugadores.getJugadorActual();
                cout << afectado->getNombre() << " roba " << acumulado << " cartas.\n";
                for (int i = 0; i < acumulado; i++)
                    afectado->getManoJugador().agregarCarta(mazoPrincipal.eliminarCarta());
                acumulado = 0;
                hayAcumulado = false;
            }
        }
    } else if (carta->getTipo() == "RobaTodo")
    {
        cout << "¡RobaTodo! Todos los jugadores pierden sus comodines" << endl;

        NodoJugador* temp = jugadores.getCabeza();
        do
        {
            Jugador* jugador = temp->getJugador();
            ManoJugador& mano = jugador->getManoJugador();
            int total = mano.getSize();

            Carta** cartasTemp = new Carta*[total];
            for (int i = 0; i < total; i++)
                cartasTemp[i] = mano.eliminarCarta(1);

            for (int i = 0; i < total; i++)
            {
                if (cartasTemp[i]->getTipo() == "Comodin")
                {
                    mazoPrincipal.insertarCarta(cartasTemp[i]);
                    cout << jugador->getNombre() << " pierde un comodin." << endl;
                }
                else
                {
                    mano.agregarCarta(cartasTemp[i]);
                }
            }
            delete[] cartasTemp;
            temp = temp->getSiguiente();
        } while (temp != jugadores.getCabeza());
    }
    else if (carta->getTipo() == "Comodin")
    {
        CartaComodin* comodin = dynamic_cast<CartaComodin*>(carta);
        if (!comodin) return;

        if (comodin->getEfecto() == "+4🎨")
        {
            if (configuracion.getAcumulacionMas4() && hayAcumulado)
            {
                acumulado += 4;
                cout << "Acumulacion! El siguiente jugador robara " << acumulado << " cartas.\n";
            }
            else
            {
                string colorElegido = elegirColor();
                comodin->setColor(colorElegido);

                acumulado = 4;
                jugadores.avanzarTurno();
                Jugador* afectado = jugadores.getJugadorActual();

                if (configuracion.getRetoMas4())
                {
                    int reto;
                    cout << afectado->getNombre() << " quiere retar el +4? (1. Si / otro. No): ";
                    cin >> reto;

                    if (reto == 1)
                    {
                        jugadores.avanzarTurno();
                        Jugador* lanzador = jugadores.getJugadorActual();
                        cout << lanzador->getNombre() << " fue retado y roba 4 cartas.\n";
                        for (int i = 0; i < 4; i++)
                            lanzador->getManoJugador().agregarCarta(mazoPrincipal.eliminarCarta());
                        jugadores.avanzarTurno();
                    }
                    else
                    {
                        cout << afectado->getNombre() << " roba " << acumulado << " cartas.\n";
                        for (int i = 0; i < acumulado; i++)
                            afectado->getManoJugador().agregarCarta(mazoPrincipal.eliminarCarta());
                    }
                }
                else
                {
                    cout << afectado->getNombre() << " roba " << acumulado << " cartas.\n";
                    for (int i = 0; i < acumulado; i++)
                        afectado->getManoJugador().agregarCarta(mazoPrincipal.eliminarCarta());
                }

                acumulado = 0;
                hayAcumulado = false;
            }
        }
        else
        {
            string colorElegido = elegirColor();
            comodin->setColor(colorElegido);
        }
    }
}

string LogicaJuego::elegirColor()
{
    string color;
    int opcion;
    cout << "Elige un color:";
    cout << "1.Rojo 2.Verde 3.Azul 4.Amarillo " << endl;

    while (true)
    {
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1) { color = "Rojo";      break; }
        if (opcion == 2) { color = "Verde";     break; }
        if (opcion == 3) { color = "Azul";      break; }
        if (opcion == 4) { color = "Amarillo";  break; }
        cout << "Opcion invalida." << endl;
    }
    return color;
}

bool LogicaJuego::manejarRobo(Jugador* jugador, Carta* cartaEnMesa)
{
    if (configuracion.getModoRoboSimple())
    {
        if (mazoPrincipal.estaVacio())
        {
            if (mesaJugadas.getSize() <= 1)
            {
                cout << "No hay cartas disponibles.\n";
                return false;
            }
            mesaJugadas.reciclarAlMazo(mazoPrincipal);
        }

        Carta* carta = mazoPrincipal.eliminarCarta();
        if (carta != nullptr)
        {
            jugador->getManoJugador().agregarCarta(carta);
            cout << "Robaste 1 carta y pasas turno.\n";
        }
        return false;
    }
    else
    {
        cout << "Robando hasta encontrar carta jugable...\n";
        int intentos = 0;
        while (true)
        {
            if (mazoPrincipal.estaVacio())
            {
                if (mesaJugadas.getSize() <= 1)
                {
                    cout << "No hay cartas disponibles." << endl;;
                    return false;
                }
                mesaJugadas.reciclarAlMazo(mazoPrincipal);
            }

            Carta* carta = mazoPrincipal.eliminarCarta();
            if (carta == nullptr)
            {
                cout << "No hay mas cartas." << endl;;
                return false;
            }

            jugador->getManoJugador().agregarCarta(carta);
            cout << "Robaste: ";
            carta->mostrar();

            if (carta->getColor() == "Negro" && !configuracion.getGanarConNegra())
            {
                intentos++;
                if (intentos >= mazoPrincipal.getSize() + mesaJugadas.getSize())
                {
                    cout << "No hay cartas jugables disponibles." << endl;;
                    return false;
                }
                continue;
            }

            if (cartaEsJugable(carta, cartaEnMesa))
            {
                cout << "Carta jugable encontrada!" << endl;
                return true;
            }

            intentos++;
            if (intentos >= 20)
            {
                cout << "No se encontro carta jugable, pasas turno." << endl;
                return false;
            }
        }
    }
}