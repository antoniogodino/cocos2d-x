#include "SpriteWithListener.h"
#include "SimpleAudioEngine.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

SpriteWithListener* SpriteWithListener::create(const std::string &filename, ISpriteWithListener *layer)
{
    // 'scene' is an autorelease object
    SpriteWithListener *pSprite = new SpriteWithListener();
    if (pSprite && pSprite->initWithFile(filename))
    {
        pSprite->autorelease();
        pSprite->addEvents();
        pSprite->layer = layer;
        return pSprite;
    }
    
    CC_SAFE_DELETE(pSprite);
    return nullptr;
}

void SpriteWithListener::addEvents()
{
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [this](Touch* touch, Event* event)
    {

        Vec2 p = touch->getLocation();
        rect = this->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            moving = false;
            return true; // to indicate that we have consumed it.
        }
        
        return false; // we did not consume this event, pass thru.
    };
    
    listener->onTouchMoved = [this] (Touch* touch, Event* event) {
        moving = true;
        layer->drag(touch, this);
        return true;
    };
    
    listener->onTouchEnded = [this](Touch* touch, Event* event)
    {
        //SpriteWithListener::touchEvent(touch);
        Vec2 p = touch->getLocation();
        //Rect rect = this->getBoundingBox();
        if(!moving && rect.containsPoint(p))
            this->layer->click(this);
        else this->layer->release(touch, this);
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}



