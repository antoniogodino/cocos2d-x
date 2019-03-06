//
//  Casilla.cpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 4/3/19.
//

#include "Casilla.h"


Casilla::Casilla() {
    levantada = false;
    valor = 0;
    bomba = false;
}

void Casilla::levanta() {
    levantada = true;
}

void Casilla::ponBomba() {
    bomba = true;
}

int Casilla::getValor() {
    return valor;
}

bool Casilla::esBomba() {
    return bomba;
}

bool Casilla::estaLevantada() {
    return levantada;
}

void Casilla::sumaUno() {
    valor ++;
}
