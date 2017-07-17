#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;
static const string CROSSHAIR_SMALL = "images/crosshair_small.png";
static const string CROSSHAIR_LARGE = "images/crosshair_large.png";



class PlayScene : public Layer {
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	CREATE_FUNC(PlayScene);
private:
	Sprite* _crosshair;
};



#endif // __INTRO_SCENE_H__