#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.h"
#include "TresRaya.h"
#include "DynamicLight.h"
#include "PhysicsScene.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->preloadBackgroundMusic("mp3/Halo.mp3");
    
    audio->playBackgroundMusic("mp3/Halo.mp3");
    

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    
    
    // pre-loading background music and effects. You could pre-load
    // effects, perhaps on app startup so they are already loaded
    // when you want to use them.
    audio->preloadEffect("sounds/sound_beep.mp3");
    
    
    
    auto label = Label::createWithTTF("Ejemplos varios", "fonts/Walt_Disney.ttf", 24);
    label->enableOutline(Color4B::BLACK,1);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.jpg");
    
    // efecto luz blanca
    auto spriteluz = Sprite::create("light.png");
    DynamicLight* dynLight = DynamicLight::create();
    dynLight->retain();
    dynLight->setShadowCasters(spriteluz);
    dynLight->setColor(Color4B(130,170,130,220));
    dynLight->setPosition({ 240,150 });
    dynLight->setLightSize(100);
    this->addChild(dynLight, 9);
    auto moveBy = MoveBy::create(60, Vec2(240,-150));
    dynLight->runAction(moveBy);
    
    
    
    /// efecto
    auto scaleBy = ScaleBy::create(20.0f, 1.2f);
    sprite->runAction(scaleBy);
    
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    
    Vector<MenuItem*> menuItems;
    auto label_hud = Label::createWithTTF("Controles HUD", "fonts/Walt_Disney.ttf", 14);
    label_hud->enableOutline(Color4B::BLACK,1);
    auto mi1 = MenuItemLabel::create(label_hud,
                          [=](Ref* obj) {
                              audio->playEffect("sounds/sound_beep.mp3");
                              Director::getInstance()->replaceScene(TransitionFade::create(1, MenuScene::createScene() , Color3B(0,0,0)));

                            });
    menuItems.pushBack(mi1);
    
    auto label_customsprite = Label::createWithTTF("Custom Sprite Listener", "fonts/Walt_Disney.ttf", 14);
    label_customsprite->enableOutline(Color4B::BLACK,1);
    auto mi2 = MenuItemLabel::create(label_customsprite,
                                    [=](Ref* obj) {
                                        audio->playEffect("sounds/sound_beep.mp3");
                                        Director::getInstance()->replaceScene(TransitionFade::create(1, TresRaya::createScene() , Color3B(0,0,0)));

                                    });
    menuItems.pushBack(mi2);
    
    
    auto label_physics = Label::createWithTTF("Physics", "fonts/Walt_Disney.ttf", 14);
    label_physics->enableOutline(Color4B::BLACK,1);
    auto mi3 = MenuItemLabel::create(label_physics,
                                     [=](Ref* obj) {
                                         audio->playEffect("sounds/sound_beep.mp3");
                                         Director::getInstance()->replaceScene(TransitionFade::create(1, PhysicsScene::createScene() , Color3B(0,0,0)));
                                         
                                     });
    menuItems.pushBack(mi3);
    
    auto menus = Menu::createWithArray(menuItems);
    menus->alignItemsVertically();
    menus->setPosition(visibleSize/2);
    this->addChild(menus, 1);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
