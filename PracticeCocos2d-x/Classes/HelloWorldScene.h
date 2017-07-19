#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Target.h"

using namespace std;

USING_NS_CC;

class HelloWorld : public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;
	void update(float) override;
	CREATE_FUNC(HelloWorld);
private:
	void scoreSetTexture(int, int);
	void changeScore();

    Sprite* _bgTop;
	Sprite* _bgBot;
	//Sprite* _crosshair;
	Sprite* _lblScore;
	Sprite* _score[3];
	Vector<Target*> _targets;
	//win _scoreNumber == 999
	int _scoreNumber = 0;
	long long _t0 = 0;
};

#endif // __HELLOWORLD_SCENE_H__
