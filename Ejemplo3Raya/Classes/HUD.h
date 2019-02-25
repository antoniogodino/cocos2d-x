#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "cocos2d.h"
#include "IHUD.h"

class HUD : public cocos2d::Layer
{

public:
    static int width;
    static IHUD *scene;
    
    static cocos2d::Layer* createHUD(int width, IHUD* scn);
    
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(HUD);
};

#endif // __HUD_LAYER_H__
