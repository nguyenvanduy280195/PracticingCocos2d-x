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

#if (CC_TARGET_PLATFORM ==CC_PLATFORM_WIN32)
static const string PATH_ROOT = "";
#else
static const string PATH_ROOT = FileUtils::getInstance()->getDefaultResourceRootPath();
#endif

static const string SPRITE_BACKGROUND_TOP = PATH_ROOT + "images/bg_top.png";
static const string SPRITE_BACKGROUND_BOT = PATH_ROOT + "images/bg_bot.png";
//static const string MAP = PATH_ROOT + "images/test.tmx";
static const Size DUCK_Y_SIZE(99, 95);
static const Vec2 DUCK_Y_POSI(636, 541);

static const Size DUCK_B_SIZE(99, 95);
static const Vec2 DUCK_B_POSI(636, 638);

static const Size TARGET_SIZE(128, 128);
static const Vec2 TARGET_POSI(404, 451);

static const string SPRITESHEET_OBJECTS = PATH_ROOT + "images/Spritesheets/spritesheet_objects.png";
static const string SPRITESHEET_HUD = PATH_ROOT + "images/Spritesheets/spritesheet_hud.png";

static const string JSON_OBJECTS = PATH_ROOT + "images/Spritesheets/spritesheet_objects.json";
static const string JSON_HUD = PATH_ROOT + "images/Spritesheets/spritesheet_hud.json";

//---
static const char* TEXTURE_ALIAS = "TextureAtlas";
static const char* SUB_TEXTURE = "SubTexture";
static const char* ATT_NAME = "-name";
static const char* ATT_X = "-x";
static const char* ATT_Y = "-y";
static const char* ATT_WIDTH = "-width";
static const char* ATT_HEIGHT = "-height";
//---


static const float SCROLLING_BACKGROUND_SPEED = 5;

#endif //MYGAME_HEADER_H
