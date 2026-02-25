# UNO - Laboratorio de Estructura de Datos
### Universidad San Carlos de Guatemala - CUNOC
### Ingeniería en Ciencias y Sistemas

---

## Descripción

Version avanzada del juego de cartas UNO implementada en C++ con Programación Orientada a Objetos. Soporta múltiples jugadores, reglas configurables y cartas especiales personalizadas. Se ejecuta en consola de texto.

---

## Requisitos

- Sistema operativo: Linux o Windows
- Compilador: g++ con soporte C++11 o superior
- CMake 3.10 o superior
- make


## Compilación con CMake

```bash
# 1. Entrar a la carpeta build
cd build

# 2. Generar archivos de compilación
cmake ..

# 3. Compilar el proyecto
make
```

---

## Compilación con Makefile

```bash
make
```

Para limpiar los archivos compilados:

```bash
make clean
```

---

## Ejecución

```bash
# Desde la carpeta build con CMake
./Practica01_EDD

# Desde la raiz con Makefile
./Practica01_EDD
```

---

## Reglas Configurables

Al iniciar el juego se puede activar o desactivar:

- **Acumulacion de +2 y +4**: Permite apilar cartas de robo entre jugadores.
- **Reto del +4**: El jugador afectado puede retar al lanzador del +4.
- **Modo de Robo**: Robar 1 carta y pasar, o robar hasta encontrar carta jugable.
- **Ganar con carta negra**: Permite o no terminar la partida con un comodin.

---

## Cartas del Juego

| Carta | Efecto |
|-------|--------|
| Numero | Jugar si coincide color o numero |
| Salto | El siguiente jugador pierde su turno |
| Reversa | Cambia el sentido del juego |
| +2 | El siguiente jugador roba 2 cartas |
| Comodin | Elige el color que continua |
| Comodin +4 | Elige color y el siguiente roba 4 |
| RobaTodo | Todos pierden sus comodines, elige color |

---

## Autores

Proyecto desarrollado para el Laboratorio de Estructura de Datos 
Centro Universitario de Occidente - CUNOC 
Universidad San Carlos de Guatemala - 2026
