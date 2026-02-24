//
// Created by jfgarcianata on 21/02/26.
//

#ifndef PRACTICA01_EDD_CONFIGURACIONJUEGO_H
#define PRACTICA01_EDD_CONFIGURACIONJUEGO_H

class ConfiguracionJuego
{
    private:
    bool acumulacionMas2;
    bool acumulacionMas4;
    bool retoMas4Habilitado;
    bool modoRoboSimple;
    bool ganarConNegra;

    public:
    ConfiguracionJuego();
    void configAcumulacion();
    void configRetoMas4();
    void configModoRobo();
    void configGanarConNegra();

    bool getAcumulacionMas2();
    bool getAcumulacionMas4();
    bool getRetoMas4();
    bool getModoRoboSimple();
    bool getGanarConNegra();
};

#endif //PRACTICA01_EDD_CONFIGURACIONJUEGO_H