//
//  Casilla.hpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 4/3/19.
//

#ifndef Casilla_hpp
#define Casilla_hpp

class Casilla {
private:
    bool levantada;
    bool bomba;
    int valor;
    
public:
    Casilla();
    void levanta();
    void ponBomba();
    int getValor();
    bool esBomba();
    bool estaLevantada();
    void sumaUno();
};


#endif /* Casilla_hpp */
