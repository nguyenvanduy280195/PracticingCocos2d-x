//
// Created by lazyguy on 15/07/2017.
//

#include "Background.h"

Scene *Background::createScene() {
    auto scene = Scene::create();
    scene->addChild(Background::create());
    return scene;
}

bool Background::init() {

    if (!Layer::init()) {
        return false;
    }

    //set prites for top



    //set sprites for bot
    _bot = Sprite::create(SPRITE_BACKGROUND_BOT);
    _bot->setAnchorPoint(Vec2(0, 0));
    _bot->setScaleY(0.5);
    _bot->setPosition(0, 0);
    _bot->runAction(RepeatForever::create(MoveBy::create(1,Vec2(50,0))));
    this->addChild(_bot);

    _bot1 = Sprite::create(SPRITE_BACKGROUND_BOT);
    _bot1->setAnchorPoint(Vec2(0, 0));
    _bot1->setScaleY(0.5);
    _bot1->setPosition(-_bot1->getContentSize().width, 0);
    _bot1->runAction(RepeatForever::create(MoveBy::create(1,Vec2(50,0))));
    this->addChild(_bot1);

    scheduleUpdate();
    return true;
}

void Background::update(float dt) {
    //-1 for padding
    if (_bot->getPositionX() > _bot->getContentSize().width)
        _bot->setPositionX(-(_bot1->getPositionX() + _bot1->getContentSize().width - 1));
    if (_bot1->getPositionX() > _bot1->getContentSize().width)
        _bot1->setPositionX(-(_bot->getPositionX() + _bot->getContentSize().width - 1));
}