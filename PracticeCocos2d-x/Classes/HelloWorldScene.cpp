#include "HelloWorldScene.h"

long long getCurrentTime() {
    time_t t = time(0);
    tm *now = localtime(&t);

    return now->tm_hour * 3600 + now->tm_min * 60 + now->tm_sec;
}


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
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	const auto origin = Director::getInstance()->getVisibleOrigin();

	//crosshair
	//_crosshair = Sprite::create(SPRITE_CROSSHAIR_LARGE);
	//_crosshair->setScale(0.4);
	//_crosshair->setPosition(visibleSize / 2);
	//this->addChild(_crosshair, 5);
	//background top
	_bgTop = Sprite::create(SPRITE_BACKGROUND_TOP);
	_bgTop->setAnchorPoint(Vec2(0, 0));
	_bgTop->setPosition(0, 0);
	this->addChild(_bgTop, 0);
	//background bottom
	_bgBot = Sprite::create(SPRITE_BACKGROUND_BOT);
	_bgBot->setAnchorPoint(Vec2(0, 0));
	_bgBot->setPosition(0, 0);
	this->addChild(_bgBot, 2);
	//label score
	_lblScore = Sprite::create(SPRITESHEET_HUD, Rect(SCORE_POSI, SCORE_SIZE));
	_lblScore->setAnchorPoint(Vec2(0, 1));
	_lblScore->setPosition(10, visibleSize.height * 9 / 10.0);
	this->addChild(_lblScore, 3);
	//score
	for (int i = 0; i < 3; i++) {
		_score[i] = Sprite::create(SPRITESHEET_HUD, Rect(SPRITE_NUMBER_POS[0], SPRITE_NUMBER_SIZE[0]));
		_score[i]->setAnchorPoint(Vec2(0, 1));

		auto x = _lblScore->getContentSize().width + (i + 1)*SPRITE_NUMBER_SIZE[1].width;
		auto y = _lblScore->getPositionY();
		_score[i]->setPosition(x, y);

		_score[i]->setVisible(false);
		this->addChild(_score[i], 3);
	}

	_score[0]->setVisible(true);

	////event listener mouse
	//auto listenerMouse = EventListenerMouse::create();
	////mouse move
	//listenerMouse->onMouseMove = [&](EventMouse* e) {
	//	auto x = e->getCursorX();
	//	auto y = e->getCursorY();
	//	_crosshair->setPosition(x, y);
	//};
	////mouse down
	//listenerMouse->onMouseDown = [&](EventMouse* e) {
	//	auto x = e->getCursorX();
	//	auto y = e->getCursorY();
	//	Vec2 cursor(x, y);
	//	for (auto target : _targets) {
	//		auto distance = cursor.distance(target->_sprite->getPosition());
	//		auto radiusTarget = 0.45*target->_sprite->getContentSize().width;
	//		if (distance < radiusTarget && !target->_isShooted) {
	//			_scoreNumber++;
	//			target->_isShooted++;
	//		}
	//	}
	//};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);

	//event listener touch
	auto listenerTouch = EventListenerTouchOneByOne::create();
	listenerTouch->onTouchBegan = [&](Touch* t, Event* e) {
		Vec2 touch = t->getLocation();
		for (auto target : _targets) {
			auto distance = touch.distance(target->_sprite->getPosition());
			auto radiusTarget = 0.45*target->_sprite->getContentSize().width;
			if (distance < radiusTarget && !target->_isShooted) {
				_scoreNumber++;
				target->_isShooted++;
			}
		}
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerTouch, this);
	this->scheduleUpdate();
	return true;
}

void HelloWorld::update(float dt) {
	//target is created every r seconds
	auto r = RandomHelper::random_real(0.0f, 5.0f);
	auto now = getCurrentTime();
	if (float(now - _t0) > r) {
		_t0 = now;
		auto target = Target::create();
		this->addChild(target, 1);
		_targets.pushBack(target);
	}
	//target is removed when target runs complete action
	for (int i = 0; i < _targets.size(); i++) {
		if (_targets.at(i)->_sprite->getNumberOfRunningActions() == 0) {
            if(!_targets.at(i)->_isShooted){//game over
                Director::getInstance()->stopAnimation();
                this->stopAllActions();
                auto gameOver = Sprite::create(SPRITESHEET_HUD, Rect(0,0,348,71));
                gameOver->setPosition(640/2,480/2);
                this->addChild(gameOver,10);
            }

			this->removeChild(_targets.at(i));
			_targets.erase(i);
		}
	}
	//change score
	this->changeScore();
}

void HelloWorld::scoreSetTexture(int iScore, int iSprite) {
	//set new spritesheet
	_score[iScore]->setTexture(SPRITESHEET_HUD);
	//set rect of new spritesheet
	Rect rect(SPRITE_NUMBER_POS[iSprite], SPRITE_NUMBER_SIZE[iSprite]);
	_score[iScore]->setTextureRect(rect);
}

void HelloWorld::changeScore() {
	int t = _scoreNumber / 100;
	int c = (_scoreNumber % 100) / 10;
	int d = _scoreNumber % 10;

	if (_scoreNumber < 10) { //[0..9]
		scoreSetTexture(0, d);
	} else {//[10..999]
		if (_scoreNumber < 100) {//[11..99]
			_score[1]->setVisible(true);
			scoreSetTexture(0, c);
			scoreSetTexture(1, d);
		} else {//[111..999]
			_score[2]->setVisible(true);
			scoreSetTexture(0, t);
			scoreSetTexture(1, c);
			scoreSetTexture(2, d);
		}
	}
}