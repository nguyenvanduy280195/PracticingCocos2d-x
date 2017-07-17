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
	_crosshair->setScale(0.5);
	_crosshair->setPosition(visibleSize/2);
	this->addChild(_crosshair);

	//--- event keyboard listener ---
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = [&](KeyCode keyCode, Event* e) {
		_keyDown++;
		_KeyCodes.push(keyCode);
	};
	keyboardListener->onKeyReleased = [&](KeyCode keyCode, Event* e) {
		_keyDown--;
		_KeyCodes.pop();
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	
	//--- event contact listener ---
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = [](PhysicsContact& contact) {
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	this->scheduleUpdate();
	return true;
}

void PlayScene::update(float dt) {
	const int step = 1;
	
	if (_keyDown > 0) {
		auto keyCode = _KeyCodes.top();
		switch (keyCode) {
		case KeyCode::KEY_UP_ARROW:
			_crosshair->setPositionY(_crosshair->getPositionY() + step);
			break;
		case KeyCode::KEY_DOWN_ARROW:
			_crosshair->setPositionY(_crosshair->getPositionY() - step);
			break;
		case KeyCode::KEY_RIGHT_ARROW:
			_crosshair->setPositionX(_crosshair->getPositionX() + step);
			break;
		case KeyCode::KEY_LEFT_ARROW:
			_crosshair->setPositionX(_crosshair->getPositionX() - step);
			break;
		}
	}

	
}