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

    _background = Background::create();
    this->addChild(_background);



	return true;
}
