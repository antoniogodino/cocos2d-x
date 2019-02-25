#ifndef __EJEMPLO1_SCENE_H__
#define __EJEMPLO1_SCENE_H__

#include "cocos2d.h"

class Ejemplo1 : public cocos2d::Layer
{
private:
    
    cocos2d::Sprite* tablero_ui[3][3];
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Ejemplo1);
};

#endif // __EJEMPLO1_SCENE_H__
