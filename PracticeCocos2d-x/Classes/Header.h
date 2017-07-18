//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_HEADER_H
#define MYGAME_HEADER_H

#include "cocos2d.h"
#include <json/document.h>
#include <json/rapidjson.h>
using namespace std;

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
static const string PATH_ROOT = "";
#else
static const string PATH_ROOT = FileUtils::getInstance()->getDefaultResourceRootPath();
#endif

//name of images file
static const string SPRITE_BACKGROUND_TOP = PATH_ROOT + "images/bg_top.png";
static const string SPRITE_BACKGROUND_BOT = PATH_ROOT + "images/bg_bot.png";

static const string SPRITE_CROSSHAIR_SMALL = "images/PNG/crosshair_small.png";
static const string SPRITE_CROSSHAIR_LARGE = "images/PNG/crosshair_large.png";

static const string SPRITESHEET_OBJECTS = PATH_ROOT + "images/Spritesheets/spritesheet_objects.png";
static const string SPRITESHEET_HUD = PATH_ROOT + "images/Spritesheets/spritesheet_hud.png";

//location in spritesheet objects
static const Size DUCK_Y_SIZE(99, 95);
static const Vec2 DUCK_Y_POSI(636, 541);

static const Size DUCK_B_SIZE(99, 95);
static const Vec2 DUCK_B_POSI(636, 638);

static const Size TARGET_SIZE(128, 128);
static const Vec2 TARGET_POSI(404, 451);

//location in spritesheet hub
static const Size SCORE_SIZE(116, 39);
static const Vec2 SCORE_POSI(0, 278);

static const Size SPRITE_NUMBER_SIZE[] = {
	Size(32, 37),
	Size(23, 36),
	Size(29, 37),
	Size(28, 36),
	Size(30, 36),
	Size(29, 36),
	Size(28, 36),
	Size(30, 36),
	Size(31, 37),
	Size(30, 36)
};

static const Vec2 SPRITE_NUMBER_POS[] = {
	Vec2(303, 382),
	Vec2(382, 0),
	Vec2(359, 271),
	Vec2(365, 111),
	Vec2(359, 233),
	Vec2(359, 310),
	Vec2(370, 378),
	Vec2(340, 73),
	Vec2(337, 378),
	Vec2(350, 0)
};
#endif //MYGAME_HEADER_H
