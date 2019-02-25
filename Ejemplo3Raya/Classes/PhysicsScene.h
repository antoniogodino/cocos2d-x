#ifndef __PHYSICS_SCENE_H__
#define __PHYSICS_SCENE_H__

#include "cocos2d.h"

class PhysicsScene : public cocos2d::Layer
{
    
private:
    cocos2d::PhysicsWorld * sceneWorld;
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    void createWithPhysics(cocos2d::PhysicsWorld *sceneWorld);
    ///// bool onContactBegin(cocos2d::PhysicsContact& contact);

    
    // implement the "static create()" method manually
    CREATE_FUNC(PhysicsScene);
};

#endif // __PHYSICS_SCENE_H__
