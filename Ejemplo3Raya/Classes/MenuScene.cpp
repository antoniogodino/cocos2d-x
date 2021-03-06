#include "MenuScene.h"
#include "HUD.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    ////
    // screen dimensions
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto hud = HUD::createHUD(visibleSize.width, this);
    
    spr_ball = Sprite::create("icon_ball.png");
    spr_ball->setAnchorPoint(Vec2(0,0));
    spr_ball->setPosition(Vec2(100,100));
    this->addChild(spr_ball);
    
    
    hud->setPosition(Vec2(0,0));
    hud->setAnchorPoint(Vec2(0,0));
    this->addChild(hud);
    
    
    this->scheduleUpdate();
    return true;
}


void MenuScene::update(float p)
{
    if (dx != 0) {
        Vec2 pos = spr_ball->getPosition();
        pos.x += dx;
        spr_ball->setPosition(pos);
    }
}


void MenuScene::fire()
{
    log("jump");
}

void MenuScene::left()
{
    dx = -4;
}

void MenuScene::right()
{
    dx = 4;
}

void MenuScene::depress()
{
    dx = 0;
}
