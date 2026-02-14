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
        string simbolo;
        string color;
        bool esNegra;
        bool estaEnUso;

    public:
        Carta();
        Carta(string simbolo, string color, bool esNegra);
        virtual void mostrarCarta();

        //Getters y setters
        string getSimbolo();
        string getColor();
        bool getEsNegra();
        bool getEstaEnUso();
        void setEstaEnUso(bool estaEnUso);


};
#endif //PRACTICA01_EDD_CARTA_H