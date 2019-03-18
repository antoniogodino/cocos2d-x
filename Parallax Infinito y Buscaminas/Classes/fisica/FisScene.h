//
//  MenuScene.hpp
//  DemoJuego
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#ifndef FMenuScene_hpp
#define FMenuScene_hpp

#include <stdio.h>

#include "cocos2d.h"

class FisScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(FisScene);
};

#endif /* MenuScene_hpp */
