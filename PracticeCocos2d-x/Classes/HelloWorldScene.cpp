#include "HelloWorldScene.h"

Scene* HelloWorld::createScene() {
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vect(0.0f, -100.0f));
	auto layer = HelloWorld::create();
	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init() {
	if (!Layer::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

    _crosshair = Sprite::create(SPRITE_CROSSHAIR_LARGE);
    _crosshair->setScale(0.4);
    _crosshair->setPosition(visibleSize/2);
    this->addChild(_crosshair,5);

	_bgTop = Sprite::create(SPRITE_BACKGROUND_TOP);
	_bgTop->setAnchorPoint(Vec2(0, 0));
	_bgTop->setPosition(0, 0);
	this->addChild(_bgTop, 0);

	_bgBot = Sprite::create(SPRITE_BACKGROUND_BOT);
	_bgBot->setAnchorPoint(Vec2(0, 0));
	_bgBot->setPosition(0, 0);
	this->addChild(_bgBot, 2);

	_target = Target::create();
	this->addChild(_target, 1);

    auto listenerMouse = EventListenerMouse::create();
    listenerMouse->onMouseMove = [&](EventMouse* e){
        auto x = e->getCursorX();
        auto y = e->getCursorY();
        _crosshair->setPosition(x,y);
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse,this);

	return true;
}
