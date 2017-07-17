#include "PlayScene.h"


Scene* PlayScene::createScene() {
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	scene->addChild(PlayScene::create());
	return scene;
}

bool PlayScene::init() {
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	// cross hair
	_crosshair = Sprite::create(CROSSHAIR_LARGE);
	_crosshair->setPosition(visibleSize/2);
	this->addChild(_crosshair);

	//--- event mouse listener ---
	auto mouseListener = EventListenerMouse::create();
	// mouse down
	mouseListener->onMouseDown = [&](EventMouse* e) {
		_crosshair->setTexture(CROSSHAIR_SMALL);
	};
	// mouse up
	mouseListener->onMouseUp = [&](EventMouse* e) {
		_crosshair->setTexture(CROSSHAIR_LARGE);
	};

	// mouse move
	mouseListener->onMouseMove = [&](EventMouse* e) {
		auto x = e->getCursorX();
		auto y = e->getCursorY();
		Vec2 cursor(x, y);

		_crosshair->setPosition(cursor);

		
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	
	//--- event contact listener ---
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [](PhysicsContact& contact) {
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}
