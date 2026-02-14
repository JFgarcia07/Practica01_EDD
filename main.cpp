#include <iostream>

#include "src/MotorDelJuego.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{

    MotorDelJuego motor;
    motor.bienvenida();
    motor.crearCartas();
    motor.mostrarCartas();
    return 0;
}