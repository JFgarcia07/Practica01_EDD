//
// Created by jfgarcianata on 7/02/26.
//

#ifndef PRACTICA01_EDD_CARTA_H
#define PRACTICA01_EDD_CARTA_H
#include <string>

using namespace std;

class Carta
{
    protected:
    string color;
    string tipo;
    bool estaEnMano;

    public:
    Carta(string color, string tipo, bool estaEnMano);
    virtual ~Carta();

    string getColor() const;
    string getTipo() const;
    bool getEstaEnMano() const;

    void setEstaEnMano(bool estaEnMano);

    virtual void mostrar() const = 0;
};
#endif //PRACTICA01_EDD_CARTA_H