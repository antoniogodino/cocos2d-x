#include "PhysicsScene.h"

USING_NS_CC;


Scene* PhysicsScene::createScene()
{
    log ("create");
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    log("inicio layer create");
    
    auto layer = PhysicsScene::create();
    log("fin layer create");
    //layer->setPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    layer->createWithPhysics(scene->getPhysicsWorld());
    scene->addChild(layer);

    log ("fin create");
    // return the scene
    return scene;
}



// on "init" you need to initialize your instance
bool PhysicsScene::init()
{
    log("init");
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    return true;

}

void PhysicsScene::createWithPhysics(PhysicsWorld* pw) {

    sceneWorld = pw;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    // sprite
    auto mi_bola = Sprite::create("icon_cross.png");
    mi_bola->setPosition(Vec2(200,200));
    
    // body
    auto mi_body = PhysicsBody::createCircle(
                        // radio
                        mi_bola->getContentSize().width/2.0f,
                        // material
                        PhysicsMaterial(0.0,1.0,0.0)
    );
    
    mi_body->setDynamic(true);
    mi_body->setCategoryBitmask(0x00001);
    mi_body->setCollisionBitmask(0x00002);
    
    mi_body->setContactTestBitmask(0x00002);

    
    mi_bola->addComponent(mi_body);
    
    
    this->addChild(mi_bola);
    
    
    ////// bode pantalla
    
    auto borde = Node::create();
    borde->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));

    
    // body
    auto mi_body_borde = PhysicsBody::createEdgeBox(
                    visibleSize
            );
    mi_body_borde->setDynamic(false);
    
    borde->addComponent(mi_body_borde);
    
    this->addChild(borde);
    
    
    
    
    auto otra_bola = Sprite::create("icon_cross.png");
    //otra_bola->setPosition(Vec2(280,300));
    otra_bola->setPosition(Vec2(200,300));
    
    auto otro_body = PhysicsBody::createCircle(
                                               otra_bola->getContentSize().width/2.0f,
                                               PhysicsMaterial(0.0,1.0,0.0));
    //otro_body->setDynamic(false);
    otro_body->setDynamic(true);
    
    otro_body->setCategoryBitmask(0x00002); // 0010
    otro_body->setCollisionBitmask(0x00001); // 0001
    
    otro_body->setContactTestBitmask(0x00001); // 0001
    
    otra_bola->addComponent(otro_body);
    this->addChild(otra_bola);
    
    
    // joint
    
    // auto join = PhysicsJointDistance::construct(mi_body,otro_body,  Vec2(0,0), Vec2(0,0));
    // sceneWorld->addJoint(join);
    
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(PhysicsScene::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
}


bool PhysicsScene::onContactBegin(PhysicsContact& contact)
{
    //auto bodyA = contact.getShapeA()->getBody()->getNode();
    //auto bodyB = contact.getShapeB()->getBody()->getNode();
    
    log("contacto");
    return true;
}












