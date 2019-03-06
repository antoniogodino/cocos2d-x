#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Model/Tablero.h"
#include "Model/SpriteLocation.h"
#include "InfiniteParallax.h"

class HelloWorld : public cocos2d::Scene
{
private:
    SpriteLocation*** tableroUI;
    Tablero tablero;
    int fils;
    int cols;
    bool changeUI;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float delta);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
