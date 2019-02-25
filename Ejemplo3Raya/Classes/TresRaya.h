#ifndef __TRESRAYA_SCENE_H__
#define __TRESRAYA_SCENE_H__

#include "cocos2d.h"
#include "ISpriteWithListener.h"

class TresRaya : public cocos2d::Layer, public ISpriteWithListener
{
private:
    cocos2d::Sprite* tablero_ui[3][3];
    bool turno = true;
    int num_fichas = 0;
    bool moving = false;
    cocos2d::Vec2 origin = cocos2d::Vec2(0,0);
    
    bool block_ui = false;
    int block_semaphore = 0;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void click(cocos2d::Sprite* sprite);
    virtual void drag(cocos2d::Touch* touch, cocos2d::Sprite* sprite);
    virtual void release(cocos2d::Touch* touch, cocos2d::Sprite* sprite);

    void block();
    void unblock();
    // implement the "static create()" method manually
    CREATE_FUNC(TresRaya);
};

#endif // __TRESRAYA_SCENE_H__
