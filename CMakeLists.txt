cmake_minimum_required(VERSION 3.28)
project(Practica01_EDD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica01_EDD main.cpp
        src/DAO/Jugador.h
        src/DAO/Carta.h
        src/DAO/CartaFlip.h
        src/Estructuras/NodoCarta.h
        src/Estructuras/MazoPrincipal.h
        src/MotorDelJuego.h
        src/MotorDelJuego.cpp
        src/DAO/Carta.cpp
        src/DAO/CartaFlip.cpp
        src/DAO/Jugador.cpp
        src/Estructuras/NodoCarta.cpp
        src/Estructuras/MazoPrincipal.cpp
        src/DAO/CartaNumero.h
        src/DAO/CartaNumero.cpp
        src/DAO/CartaAccion.h
        src/DAO/CartaAccion.cpp
        src/DAO/CartaComodin.h
        src/DAO/CartaComodin.cpp)
