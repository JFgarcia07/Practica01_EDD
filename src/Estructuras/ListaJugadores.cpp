//
// Created by jfgarcianata on 14/02/26.
//

#include "ListaJugadores.h"

ListaJugadores::ListaJugadores()
{
     cabeza = nullptr;
     size = 0;
     sentidoHorario = true;
}

void ListaJugadores::agregarJugador(string nombre)
{
     Jugador* nuevoJugador = new Jugador(nombre);
     NodoJugador* nuevoNodo = new NodoJugador(nuevoJugador);

     if (estaVacia())
     {
          cabeza = nuevoNodo;
          cabeza->setSiguiente(cabeza);
          cabeza->setAnterior(cabeza);
          jugadorActual = cabeza;
     } else
     {
          NodoJugador* cola = cabeza->getAnterior();

          cola->setSiguiente(nuevoNodo);
          nuevoNodo->setAnterior(cola);

          nuevoNodo->setSiguiente(cabeza);
          cabeza->setAnterior(nuevoNodo);
     }
     size++;
}

void ListaJugadores::avanzarTurno()
{
     if(sentidoHorario)
     {
          jugadorActual = jugadorActual->getSiguiente();
     } else
     {
          jugadorActual = jugadorActual->getAnterior();
     }
}

void ListaJugadores::saltarTurno()
{
     avanzarTurno();
     avanzarTurno();
}

void ListaJugadores::cambiarSentido()
{
     sentidoHorario = !sentidoHorario;
}

Jugador* ListaJugadores::getJugadorActual()
{
     if (estaVacia())
     {
          return nullptr;
     }

     return jugadorActual->getJugador();
}

ListaJugadores::~ListaJugadores()
{
     if (estaVacia())
     {
          return;
     }

     NodoJugador* temporal = cabeza;
     NodoJugador* inicio = cabeza;

     do
     {
          NodoJugador* siguiente = temporal->getSiguiente();

          delete temporal->getJugador();
          delete temporal;

          temporal = siguiente;

     } while (temporal != inicio);

     cabeza = nullptr;
}

bool ListaJugadores::estaVacia()
{
     return cabeza == nullptr;
}

NodoJugador* ListaJugadores::getCabeza()
{
     return cabeza;
}