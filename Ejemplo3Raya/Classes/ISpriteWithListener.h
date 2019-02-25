#ifndef __ISPRITELISTENER_LAYER_H__
#define __ISPRITELISTENER_LAYER_H__

#include "cocos2d.h"

class ISpriteWithListener
{
public:
    virtual void click(cocos2d::Sprite* sprite) = 0;
    virtual void drag(cocos2d::Touch* touch, cocos2d::Sprite* sprite) = 0;
    virtual void release(cocos2d::Touch* touch, cocos2d::Sprite* sprite) = 0;
};

#endif // __ISPRITELISTENER_LAYER_H__
