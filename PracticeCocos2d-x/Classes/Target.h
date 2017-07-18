//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_TARGET_H
#define MYGAME_TARGET_H

#include "Header.h"

class Target : public Layer{
public:
	CREATE_FUNC(Target);
	bool init() override;
	void update(float) override;
	Sprite* _sprite;
	int _isShooted = 0;
};


#endif //MYGAME_TARGET_H
