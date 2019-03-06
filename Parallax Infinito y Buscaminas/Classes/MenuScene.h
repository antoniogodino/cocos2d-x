//
//  MenuScene.hpp
//  DemoJuego
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "InfiniteParallax.h"

class MenuScene : public cocos2d::Scene
{
private:
    InfiniteParallaxNode* par;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float delta);
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif /* MenuScene_hpp */
