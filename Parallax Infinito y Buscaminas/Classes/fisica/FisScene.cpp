//
//  MenuScene.cpp
//  DemoJuego
//
//  Created by Luis Fernando de Mingo López on 5/3/19.
//

#include "FisScene.h"

USING_NS_CC;


Scene* FisScene::createScene()
{
    
    return FisScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool FisScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }
    getPhysicsWorld()->setGravity(Vec2(0,-98));
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto pelota = Sprite::create("telegram.png");
    pelota->setPosition(visibleSize/2.0);
    auto pb_pelota = PhysicsBody::createCircle(pelota->getBoundingBox().size.width/2.0, PhysicsMaterial(1.0f,1.0f,1.0f));
    pb_pelota->setDynamic(false);
    pelota->addComponent(pb_pelota);
    addChild(pelota);
    
    
    //// para el borde de la pantalla
    
    auto pb_border = PhysicsBody::createEdgeBox(visibleSize);
    auto border = Node::create();
    border->setAnchorPoint(Vec2(0,0));
    border->setPosition(visibleSize/2);
    pb_border->setDynamic(false);
    border->addComponent(pb_border);
    addChild(border);
    
    
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener1->onTouchBegan = [=](Touch* touch, Event* event) {
        return true;
    };
    
    listener1->onTouchMoved = [=](Touch* touch, Event* event){
        return true;
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        auto pelota = Sprite::create("telegram.png");
        pelota->setPosition(touch->getLocation());
        
        auto pb_pelota = PhysicsBody::createCircle(pelota->getBoundingBox().size.width/2.0, PhysicsMaterial(1.0f,1.0f,1.0f));
        pelota->addComponent(pb_pelota);
        
        pb_pelota->applyImpulse(Vec2(500000,500000));
        //pb_pelota->applyForce(Vec2(50000000,50000000));
        addChild(pelota);
        return true;
    };
    
    
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
    
    return true;
}

