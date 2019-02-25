#include "HUD.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
int HUD::width = 0;
IHUD* HUD::scene = NULL;

Layer* HUD::createHUD(int w, IHUD *scn)
{
    width = w;
    scene = scn;
    
    // 'layer' is an autorelease object
    auto layer = HUD::create();
    
    // return the scene
    return layer;
}

// on "init" you need to initialize your instance
bool HUD::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    
    
    auto spr_jump = Sprite::create("icon_jump.png");
    spr_jump->setAnchorPoint(Vec2(0,0));
    spr_jump->setPosition(Vec2(0,0));
    this->addChild(spr_jump);

    auto spr_right = Sprite::create("icon_right.png");
    spr_right->setAnchorPoint(Vec2(1,0));
    spr_right->setPosition(Vec2(this->width,0));
    this->addChild(spr_right);

    
    auto spr_left = Sprite::create("icon_left.png");
    spr_left->setAnchorPoint(Vec2(1,0));
    spr_left->setPosition(Vec2(this->width - spr_right->getContentSize().width,0));
    this->addChild(spr_left);

    
    this->setOpacity(100);
    this->setCascadeOpacityEnabled(true);
    this->setContentSize(Size(this->width,spr_left->getContentSize().height));
    
    
    auto listener1 = EventListenerTouchOneByOne::create();
    // avoid others to use it
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [=](Touch* touch, Event* event){
        if (spr_jump->getBoundingBox().containsPoint(touch->getLocation())) {
            scene->fire();
            return true;
        } else if (spr_right->getBoundingBox().containsPoint(touch->getLocation())) {
            scene->right();
            return true;
        } else if (spr_left->getBoundingBox().containsPoint(touch->getLocation())) {
            scene->left();
            return true;
        }
        return false; // if you are consuming it
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        // your code
        if (!spr_jump->getBoundingBox().containsPoint(touch->getLocation())) {
            scene->depress();
        }
        
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);

    
    return true;
}

