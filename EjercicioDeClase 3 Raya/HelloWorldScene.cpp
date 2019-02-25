#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    Sprite* tiles[3][3];
    
    for (int filas=0; filas<3; filas++)
        for(int cols=0; cols<3; cols++) {
            tiles[filas][cols] = Sprite::create("square.png");
            tiles[filas][cols]->setPosition(Vec2(100+80*filas,100+80*cols));
            tiles[filas][cols]->setTag(filas*3+cols);
            this->addChild(tiles[filas][cols]);
        }

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(false);
    listener1->onTouchBegan = [=](Touch* touch, Event* event) {
        if (event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())) {
            sel = (Sprite *)event->getCurrentTarget();
            return true;
        }
        return false;
    };
    
    listener1->onTouchMoved = [=](Touch* touch, Event* event){
        // your code
        return true;
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        if (event->getCurrentTarget()->getBoundingBox().containsPoint(touch->getLocation())) {
            sel->setTexture("cross.png");
            return true;
        }
        return false;
    };
    
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++) {
            getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1->clone(), tiles[i][j]);
        }


    return true;
}


