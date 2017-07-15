//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_BACKGROUND_H
#define MYGAME_BACKGROUND_H

#include "Header.h"

class Background : public Layer{
public:
    CREATE_FUNC(Background);

    Scene* createScene();
    bool init() override;
    void update(float) override;

private:
    Sprite* _top;
    Sprite* _bot;
    Sprite* _bot1;

};


#endif //MYGAME_BACKGROUND_H
