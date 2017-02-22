#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "IHUD.h"

class MenuScene : public cocos2d::Layer, public IHUD
{
private:
    cocos2d::Sprite *spr_ball;
    int dx = 0;
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void update(float);
    
    
    virtual void fire();
    virtual void left();
    virtual void right();
    virtual void depress();
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif // __MENU_SCENE_H__
