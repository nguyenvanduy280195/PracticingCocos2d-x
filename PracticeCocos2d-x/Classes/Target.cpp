//
// Created by lazyguy on 15/07/2017.
//

#include "Target.h"

Vec2 deltaMove() {
	int speed = RandomHelper::random_int(0, 200);
	int direct = (RandomHelper::random_int(0, 1) == 0) ? 1 : -1;
	bool isX = RandomHelper::random_int(0, 1);
	if (isX) {
		return Vec2(direct*speed, 0);
	}
	return Vec2(0, direct*speed);
}

bool Target::init() {
	if (!Layer::init()) {
		return false;
	}
	_sprite = Sprite::create(SPRITESHEET_OBJECTS, Rect(TARGET_POSI, TARGET_SIZE));

	int x = RandomHelper::random_int(200, 600);
	int y = RandomHelper::random_int(200, 400);

	_sprite->setPosition(x, y);
	_sprite->setScale(0.5);

	auto move = MoveBy::create(2, deltaMove());
	auto fade = FadeOut::create(3);
	auto spawn = Spawn::createWithTwoActions(move, fade);
	_sprite->runAction(spawn);

	this->addChild(_sprite);
	this->scheduleUpdate();
	return true;
}

void Target::update(float dt) {
	if (_isShooted == 1) {
		_isShooted++;
		_sprite->stopAllActions();

		auto in = FadeIn::create(0.1f);
		auto out = FadeOut::create(1);
		auto seq = Sequence::createWithTwoActions(in, out);
		_sprite->runAction(seq);
	}
}