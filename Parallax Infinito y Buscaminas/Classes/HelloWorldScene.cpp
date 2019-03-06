#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>     /* srand, rand */
#include "InfiniteParallax.h"

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
 
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    fils = 12;
    cols = 12;
    tablero = Tablero(fils,cols);
    
    int vstep = visibleSize.height/fils;
    int xoffset = (visibleSize.width - visibleSize.height)/2;
    
    tableroUI = new SpriteLocation**[fils];
    for (int filas=0; filas<fils; filas++) {
        tableroUI[filas] = new SpriteLocation*[cols];
        for(int columnas=0; columnas<cols; columnas++) {
            tableroUI[filas][columnas] = SpriteLocation::create(filas, columnas, "square.png");
            tableroUI[filas][columnas]->setContentSize(Size(vstep,vstep));
            tableroUI[filas][columnas]->setAnchorPoint(Vec2(0,0));
            tableroUI[filas][columnas]->setPosition(Vec2(xoffset+vstep*filas,vstep*columnas));
            this->addChild(tableroUI[filas][columnas],1);
        }
    }

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener1->onTouchBegan = [=](Touch* touch, Event* event) {
        if (event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())) {
            return true;
        }
        return false;
    };
    
    listener1->onTouchMoved = [=](Touch* touch, Event* event){
        return true;
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        if (event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())) {
            SpriteLocation* celda = (SpriteLocation*)event->getCurrentTarget();
            if (!tablero.levantada(celda->fila, celda->columna)) {
                tablero.levanta(celda->fila, celda->columna);
                changeUI = true;
                if (tablero.esBomba(celda->fila, celda->columna)) {
                    auto exp = ParticleFire::create();
                    exp->setDuration(0.5f);
                    exp->setPosition(event->getCurrentTarget()->getPosition());
                    addChild(exp,100);
                }
            }
            return true;
        }
        return false;
    };
    
    for (int i=0; i<fils; i++)
        for(int j=0; j<cols; j++)
            getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1->clone(), tableroUI[i][j]);
    
    scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) {
    if (changeUI == true) {
        Size size = tableroUI[0][0]->getContentSize();
        for (int i=0 ; i< fils; i++)
            for( int j=0; j<cols; j++) {
                if (tablero.levantada(i,j)) {
                    if (tablero.esBomba(i,j))
                            tableroUI[i][j]->setTexture("bomb.png");
                    else if (tablero.getValor(i,j)==0)
                        tableroUI[i][j]->setTexture("");
                    else
                        tableroUI[i][j]->setTexture(("Number-"+std::to_string(tablero.getValor(i,j))+"-icon.png"));
                } else
                    tableroUI[i][j]->setTexture("square.png");
                tableroUI[i][j]->setContentSize(size);
            }
        changeUI = false;
    }
    
}

