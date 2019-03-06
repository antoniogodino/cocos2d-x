//
//  Tablero.hpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 4/3/19.
//

#ifndef Tablero_hpp
#define Tablero_hpp

#include "Casilla.h"


class Tablero {
private:
    Casilla **casillas;
    int filas;
    int columnas;
    
public:
    Tablero();
    Tablero(int fils, int cols);
    void levanta(int fil, int col);
    int getValor(int fil, int col);
    bool esBomba(int fil, int col);
    bool levantada(int fil, int col);
};

#endif /* Tablero_hpp */
