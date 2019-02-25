#ifndef __SPRITEWITHLISTENER_SCENE_H__
#define __SPRITEWITHLISTENER_SCENE_H__

#include "cocos2d.h"
#include "ISpriteWithListener.h"

class SpriteWithListener : public cocos2d::Sprite
{
    
private:
    ISpriteWithListener* layer;
    bool moving = true;
    cocos2d::Rect rect;
public:
    bool ocupada = false;
    
    static SpriteWithListener* create(const std::string &filename, ISpriteWithListener *layer);
    
    void addEvents();

};

#endif // __SPRITEWITHLISTENER_SCENE_H__
