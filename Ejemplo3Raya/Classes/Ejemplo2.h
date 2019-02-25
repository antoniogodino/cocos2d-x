#ifndef __EJEMPLO2_SCENE_H__
#define __EJEMPLO2_SCENE_H__

#include "cocos2d.h"

class Ejemplo2 : public cocos2d::Layer
{
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Ejemplo2);
};

#endif // __EJEMPLO2_SCENE_H__
