cmake_minimum_required(VERSION 3.28)
project(Practica01_EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica01_EDD main.cpp
        src/DAO/Jugador.h
        src/Cartas/Carta.h
        src/Cartas/CartaFlip.h
        src/Estructuras/NodoCarta.h
        src/Estructuras/MazoPrincipal.h
        src/MotorDelJuego.h
        src/MotorDelJuego.cpp
        src/Cartas/Carta.cpp
        src/Cartas/CartaFlip.cpp
        src/DAO/Jugador.cpp
        src/Estructuras/NodoCarta.cpp
        src/Estructuras/MazoPrincipal.cpp
        src/Cartas/CartaNumero.h
        src/Cartas/CartaNumero.cpp
        src/Cartas/CartaAccion.h
        src/Cartas/CartaAccion.cpp
        src/Cartas/CartaComodin.h
        src/Cartas/CartaComodin.cpp
        src/Estructuras/NodoJugador.h
        src/Estructuras/NodoJugador.cpp
        src/Estructuras/ListaJugadores.h
        src/Estructuras/ListaJugadores.cpp
        src/Estructuras/NodoMano.h
        src/Estructuras/NodoMano.cpp
        src/Estructuras/ManoJugador.h
        src/Estructuras/ManoJugador.cpp)
