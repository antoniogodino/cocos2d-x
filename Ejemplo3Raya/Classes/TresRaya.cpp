#include "TresRaya.h"
#include "SimpleAudioEngine.h"
#include "SpriteWithListener.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* TresRaya::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TresRaya::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TresRaya::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    for(int f=0; f<3; f++)
        for(int c=0; c<3; c++)
        {
            tablero_ui[f][c] = SpriteWithListener::create("icon_square.png", this);
            Size sprite_size = tablero_ui[f][c]->getBoundingBox().size;
            Vec2 posicion = Vec2(visibleSize.width/2 + (f-1)*(sprite_size.width),
                                 visibleSize.height/2 + (c-1)*(sprite_size.height));
            tablero_ui[f][c]->setPosition(posicion);
            this->addChild(tablero_ui[f][c]);
        }
    
    return true;
}

void TresRaya::click(Sprite* sprite)
{
    if (!block_ui) {
    //log("CLICK");
    SpriteWithListener* sprite_wl = (SpriteWithListener*) sprite;
    
        if (!sprite_wl->ocupada && num_fichas < 6) {
            auto callbackFade = CallFunc::create([=](){
                auto fade_in = FadeIn::create(0.5);
                if (turno)
                    sprite_wl->setTexture("icon_cross.png");
                else
                    sprite_wl->setTexture("icon_plus.png");
            
                turno = !turno;
                sprite_wl->ocupada = true;
                sprite_wl->runAction(fade_in);
            });

            auto fade_out = FadeOut::create(0.5);
            sprite_wl->runAction(Sequence::create(fade_out,callbackFade, nullptr));
            num_fichas++;
        }
    moving = false;
    }
}

void TresRaya::drag(Touch *touch, Sprite* sprite)
{
    if (!block_ui) {
    //log("DRAG");
    if (((SpriteWithListener*)sprite)->ocupada) {
        if (!moving) {
            moving = true;
            origin = sprite->getPosition();
        }
        sprite->setPosition(touch->getLocation());
        sprite->setOpacity(200);
    }
    }
}

void TresRaya::release(cocos2d::Touch* touch, Sprite* sprite) {
    if (!block_ui) {
    //log("RELEASE");
    if (((SpriteWithListener*)sprite)->ocupada) {
        sprite->setOpacity(255);
        moving = false;
        bool colocado = false;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++) {
                if (sprite!=tablero_ui[i][j] && !((SpriteWithListener*)tablero_ui[i][j])->ocupada) {
                    if (!colocado && tablero_ui[i][j]->getBoundingBox().containsPoint(sprite->getPosition())) {
                        Vec2 posicion = tablero_ui[i][j]->getPosition();
                        //block_ui = true;
                        block();
                        auto move_new = MoveTo::create(0.25, posicion);
                        auto seq_new = Sequence::create(move_new, CallFunc::create( [this](){this->unblock();} ), nullptr);
                        sprite->runAction(seq_new);
                        
                        block();
                        auto move_new_otro = MoveTo::create(0.2, origin);
                        auto seq_new_otro = Sequence::create(move_new_otro, CallFunc::create( [this](){this->unblock();} ), nullptr);
                        tablero_ui[i][j]->runAction(seq_new_otro);
                        colocado = true;
                    }
                }
            }
    
        //// move back to origin
        if (!colocado) {
            //block_ui = true;
            block();
            auto move_back = MoveTo::create(0.25, origin);
            auto seq_move_back = Sequence::create(move_back, CallFunc::create( [this](){this->unblock();} ), nullptr);
            sprite->runAction(seq_move_back);
        }
    } else if (sprite->getBoundingBox().containsPoint(touch->getLocation()))
        /// control que no se va fuera
        click(sprite);
    }
}


void TresRaya::block()
{
    block_semaphore++;
    block_ui = (block_semaphore > 0);
}

void TresRaya::unblock()
{
    block_semaphore--;
    block_ui = (block_semaphore > 0);
}



