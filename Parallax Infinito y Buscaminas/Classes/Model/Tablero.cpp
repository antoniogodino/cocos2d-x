//
//  Tablero.cpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 4/3/19.
//

#include "Tablero.h"
#include <stdlib.h>     /* srand, rand */

Tablero::Tablero() {
        
}

Tablero::Tablero(int fils, int cols) {
    // Tablero con un borde
    filas = fils + 2;
    columnas = cols + 2;
    
    casillas = new Casilla*[filas];
    for (int i = 0; i<filas; i++) {
        casillas[i] = new Casilla[columnas];
        for (int j= 0; j<columnas; j++)
            casillas[i][j] = Casilla();
    }
    // poner bordes con 1
    for(int i=0; i<filas; i++) {
        casillas[i][0].sumaUno();
        casillas[i][columnas-1].sumaUno();
    }
    for(int j=0; j<columnas; j++) {
        casillas[0][j].sumaUno();
        casillas[filas-1][j].sumaUno();
    }
    
    /// Generar bombas aleatoriamente
    srand (time(NULL));
    for (int i = 1; i<filas-1; i++) {
        for (int j= 1; j<columnas-1; j++)
            if ((rand() % 100 + 1)<10) {
                casillas[i][j].ponBomba();
                // sumar 1s alrededor de donde está la bomba
                for(int f=i-1; f<=i+1; f++)
                    for(int c=j-1; c<=j+1; c++)
                        casillas[f][c].sumaUno();
            }
    }
}

void Tablero::levanta(int fil, int col) {
    casillas[fil+1][col+1].levanta();
    if (!esBomba(fil,col) && getValor(fil,col)==0)
        for(int i=fil-1; i<=fil+1; i++) {
            for(int j=col-1; j<=col+1; j++) {
                if (!levantada(i,j)) {
                    levanta(i,j);
                }
            }
        }
}

bool Tablero::esBomba(int fil, int col) {
    return casillas[fil+1][col+1].esBomba();
}

bool Tablero::levantada(int fil, int col) {
    return casillas[fil+1][col+1].estaLevantada();
}
int Tablero::getValor(int fil, int col) {
    return casillas[fil+1][col+1].getValor();
}
