//
//  SpriteLocation.hpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#ifndef SpriteLocation_hpp
#define SpriteLocation_hpp

#include <stdio.h>
class SpriteLocation : public cocos2d::Sprite {
public:
    int fila;
    int columna;
public:
    SpriteLocation(int fil, int col);
    static SpriteLocation* create(int f, int c, const std::string &filename);
};
#endif /* SpriteLocation_hpp */
