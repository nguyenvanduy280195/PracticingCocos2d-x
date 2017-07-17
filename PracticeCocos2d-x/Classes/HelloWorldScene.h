#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Background.h"
#include "Target.h"

using namespace std;

USING_NS_CC;

class HelloWorld : public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HelloWorld);
private:
    Sprite* _bgTop;
	Sprite* _bgBot;
	Target* _target;
    Vector<Sprite*> _targets;
};

#endif // __HELLOWORLD_SCENE_H__
