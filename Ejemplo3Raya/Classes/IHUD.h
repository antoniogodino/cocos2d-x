#ifndef __IHUD_LAYER_H__
#define __IHUD_LAYER_H__

#include "cocos2d.h"

class IHUD
{
public:
    virtual void fire() = 0;
    virtual void left() = 0;
    virtual void right() = 0;
    virtual void depress() = 0;
};

#endif // __IHUD_LAYER_H__
