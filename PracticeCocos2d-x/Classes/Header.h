//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_HEADER_H
#define MYGAME_HEADER_H

#include "cocos2d.h"
#include <json/document.h>
#include <json/rapidjson.h>


using namespace std;
using namespace rapidjson;
USING_NS_CC;

static const string PATH_ROOT = FileUtils::getInstance()->getDefaultResourceRootPath();
static const string SPRITE_BACKGROUND_BOT = PATH_ROOT + "maps/bg_water_2.png";

static const float SCROLLING_BACKGROUND_SPEED = 5;

#endif //MYGAME_HEADER_H
