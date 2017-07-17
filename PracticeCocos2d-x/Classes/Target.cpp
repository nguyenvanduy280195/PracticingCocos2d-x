//
// Created by lazyguy on 15/07/2017.
//

#include "Target.h"

bool Target::init() {
    if (!Layer::init()) {
        return false;
    }

    _t0 = 0;

    this->scheduleUpdate();
    return true;
}

void Target::update(float dt) {
    auto cur = getCurrentTime();
    if (cur - _t0 > 1) {
        _t0 = cur;

        Sprite *sprite = Sprite::create(SPRITESHEET_OBJECTS, Rect(TARGET_POSI, TARGET_SIZE));

        int x = RandomHelper::random_int(200, 600);
        int y = RandomHelper::random_int(300, 500);

        sprite->setPosition(x, y);
        sprite->setScale(0.75);

        auto move = MoveBy::create(3, Vec2(0, -y));
        auto fade = FadeOut::create(3);
        auto spawn = Spawn::createWithTwoActions(move, fade);
        sprite->runAction(spawn);

        this->addChild(sprite, 1);
        _sprites.pushBack(sprite);
    }

    for (int i = 0; i < _sprites.size(); i++) {
        if (_sprites.at(i)->getNumberOfRunningActions() == 0) {
            _sprites.erase(i);
        }
    }

}

long long Target::getCurrentTime() {
    time_t t = time(0);
    tm *now = localtime(&t);

    return now->tm_hour * 3600 + now->tm_min * 60 + now->tm_sec;
}
