//
//  MenuScene.cpp
//  DemoJuego
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "InfiniteParallax.h"
#include "HelloWorldScene.h"

USING_NS_CC;


Scene* MenuScene::createScene()
{
    
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto fondo = Sprite::create("background.jpg");
    fondo->setAnchorPoint(Vec2(0.5,0.5));
    fondo->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(fondo,-100);
    
    // ME
    MenuItemFont::setFontSize(50);
    auto menuItemFirst = MenuItemFont::create("Play", [&](Ref* pSender) {
        auto scene = HelloWorld::createScene();
        Director::getInstance()->replaceScene(scene);
    });
    
    auto menuCenter = Menu::create(menuItemFirst, NULL);
    menuCenter->setPosition(Vec2(visibleSize.width/2.0, visibleSize.height/2.0));
    this->addChild(menuCenter, 3);
    
  
    //// PARALLAX
    par = InfiniteParallaxNode::create();
    auto nubes_sol = Sprite::create("Status-weather-clouds-icon.png");
    nubes_sol->setAnchorPoint(Vec2(0,0));
    par->addChild(nubes_sol, -1,Vec2(0.2f,0.0f),Vec2(100,120));
    
    auto nubes = Sprite::create("Status-weather-many-clouds-icon.png");
    nubes->setAnchorPoint(Vec2(0,0));
    par->addChild(nubes, -2,Vec2(0.4f,0.0f),Vec2(100,80));
    
    auto nubes2 = Sprite::create("Status-weather-many-clouds-icon-1.png");
    nubes2->setAnchorPoint(Vec2(0,0));
    par->addChild(nubes2, -2,Vec2(0.5f,0.0f),Vec2(120,100));
    
    auto nubes3 = Sprite::create("Status-weather-many-clouds-icon-1.png");
    nubes3->setAnchorPoint(Vec2(0,0));
    par->addChild(nubes3, -2,Vec2(0.6f,0.0f),Vec2(240,140));
    
    auto nubes4 = Sprite::create("Status-weather-many-clouds-icon.png");
    nubes4->setAnchorPoint(Vec2(0,0));
    par->addChild(nubes4, -2,Vec2(0.5f,0.0f),Vec2(400,160));
    
    auto montanas = Sprite::create("Mountain-icon.png");
    montanas->setAnchorPoint(Vec2(0,0));
    par->addChild(montanas, -3,Vec2(0.8f,0.0f),Vec2::ZERO);
    
    auto montanas1 = Sprite::create("Mountain-icon.png");
    montanas1->setAnchorPoint(Vec2(0,0));
    par->addChild(montanas1, -3,Vec2(0.8f,0.0f),Vec2(500,0));
    
    auto montanas2 = Sprite::create("Mountain-icon-1.png");
    montanas2->setAnchorPoint(Vec2(0,0));
    par->addChild(montanas2, -3,Vec2(0.75f,0.0f),Vec2(200,10));
    
    auto montanas3 = Sprite::create("Mountain-icon-1.png");
    montanas3->setAnchorPoint(Vec2(0,0));
    par->addChild(montanas3, -3,Vec2(0.7f,0.0f),Vec2(250,10));
    
    this->setPosition(Vec2::ZERO);
    this->addChild(par);
    
    /*auto moveBy = MoveBy::create(10, Vec2(2000,0));
     par->runAction(moveBy);*/
    scheduleUpdate();
    return true;
}

void MenuScene::update(float delta) {
    par->setPosition(Vec2(par->getPosition().x-1, par->getPosition().y));
    par->updatePosition();
}

