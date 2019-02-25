#include "Ejemplo1.h"

USING_NS_CC;

Scene* Ejemplo1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Ejemplo1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Ejemplo1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    for(int f=0; f<3; f++)
        for(int c=0; c<3; c++)
        {
            tablero_ui[f][c] = Sprite::create("icon_square.png");
            Size sprite_size = tablero_ui[f][c]->getBoundingBox().size;
            Vec2 posicion = Vec2(visibleSize.width/2 + (f-1)*(sprite_size.width),
                                 visibleSize.height/2 + (c-1)*(sprite_size.height));
            tablero_ui[f][c]->setPosition(posicion);
            this->addChild(tablero_ui[f][c]);
            
            
            
            
        }
    
    
    auto mi_lis = EventListenerTouchOneByOne::create();
    
    mi_lis->setSwallowTouches(false);
    mi_lis->onTouchBegan = [this] (Touch *touch, Event* event) {
        
        auto part = ParticleFire::create();
        part->setDuration(1);
        part->setPosition(touch->getLocation());
        this->addChild(part);
        
        
        bool enc = false;
        int i, j;
        for ( i=0; i<3 && !enc; i++)
            for( j=0;j<3 && !enc; j++) {
                Rect rect = tablero_ui[i][j]->getBoundingBox();
                Point punto = touch->getLocation();
                
                if (rect.containsPoint(punto)) {
                    enc = true;
                }
            }
        log("%d %d",i,j);
        if (enc) {
            tablero_ui[i-1][j-1]->setTexture("icon_cross.png");
            return true;
        }
        
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mi_lis, this);
    
    return true;
}












