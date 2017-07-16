//
// Created by lazyguy on 15/07/2017.
//

#include "Background.h"

/**
 *
 * @return
 */
bool Background::init() {

    if (!Layer::init()) {
        return false;
    }

    //set prites for top
    _top = Sprite::create(SPRITE_BACKGROUND_TOP);
    _top->setScale(0.5);
    _top->setAnchorPoint(Vec2(0,0));
    _top->setPosition(0,98);
    this->addChild(_top,0);

    //set sprites for bot
//    _bot = Sprite::create(SPRITE_BACKGROUND_BOT);
//    _bot->setAnchorPoint(Vec2(0, 0));
//    _bot->setScale(0.5);
//    _bot->setPosition(0, 100);
//    _bot->runAction(RepeatForever::create(MoveBy::create(1,Vec2(50,0))));
//    this->addChild(_bot);
//
//    _bot1 = Sprite::create(SPRITE_BACKGROUND_BOT);
//    _bot1->setAnchorPoint(Vec2(0, 0));
//    _bot1->setScale(0.5);
//    _bot1->setPosition(-_bot1->getContentSize().width, 100);
//    _bot1->runAction(RepeatForever::create(MoveBy::create(1,Vec2(50,0))));
//    this->addChild(_bot1);
    for(int i = 0; i<2;i++){
        _bot[i] = Sprite::create(SPRITE_BACKGROUND_BOT);
        _bot[i]->setAnchorPoint(Vec2(0, 0));
        //_bot[i]->setScale(0.5);

        auto x = (i == 0)?0:-i*_bot[i-1]->getContentSize().width + 5;
        auto y = 100;
        _bot[i]->setPosition(x, y);

//        _bot[i]->runAction(RepeatForever::create(MoveBy::create(1,Vec2(100,0))));
        this->addChild(_bot[i]);
    }

    scheduleUpdate();
    return true;
}
/**
 *
 * @param dt
 */
void Background::update(float dt) {
    //-1 for padding
//    if (_bot->getPositionX() > _bot->getContentSize().width)
//        _bot->setPositionX(-(_bot1->getPositionX() -  - 1));
//    if (_bot1->getPositionX() > _bot1->getContentSize().width)
//        _bot1->setPositionX(-(_bot->getPositionX() -  - 1));

//    for(int i = 0;i<2;i++){
//        if(_bot[i]->getPositionX() > _bot[i]->getContentSize().width){
//            auto previ = (i==0)?1:(i-1);
//            auto x = -(_bot[previ]->getPositionX() + _bot[previ]->getContentSize().width);
//            _bot[i]->setPositionX(x);
//        }
//    }
}