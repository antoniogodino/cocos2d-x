//
//  SpriteLocation.cpp
//  DemoJuego-mobile
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#include "SpriteLocation.h"


SpriteLocation::SpriteLocation(int fil, int col) : cocos2d::Sprite() {
    fila = fil;
    columna = col;
}

SpriteLocation* SpriteLocation::create(int f, int c, const std::string &filename)
{
    // 'scene' is an autorelease object
    SpriteLocation *pSprite = new SpriteLocation(f, c);
    if (pSprite && pSprite->initWithFile(filename))
    {
        pSprite->autorelease();
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return nullptr;
}
