#include "Ejemplo2.h"

USING_NS_CC;

Scene* Ejemplo2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Ejemplo2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Ejemplo2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto sprite_uno = Sprite::create("icon_right.png");
    sprite_uno->setPosition(Vec2(100,100));
    
    
    auto sprite_dos = Sprite::create("icon_left.png");
    sprite_dos->setPosition(Vec2(100,100));
    
    
    this->addChild(sprite_uno);
    this->addChild(sprite_dos);
    
    
    auto lis_uno = EventListenerTouchOneByOne::create();
    lis_uno->setSwallowTouches(true);
    lis_uno->onTouchBegan = [] (Touch* touch, Event* event) {
        log("uno");
        return true;
    };
    
    auto lis_dos = EventListenerTouchOneByOne::create();
    lis_dos->setSwallowTouches(true);
    lis_dos->onTouchBegan = [] (Touch* touch, Event* event) {
        log("dos");
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis_uno,sprite_uno);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis_dos,sprite_dos);
    
    return true;
}












