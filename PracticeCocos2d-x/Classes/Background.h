//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_BACKGROUND_H
#define MYGAME_BACKGROUND_H

#include "Header.h"

class Background : public Layer{
public:
    CREATE_FUNC(Background);

    bool init() override;
    void update(float) override;

private:
    Sprite* _top;
    Sprite* _bot[2];

};


#endif //MYGAME_BACKGROUND_H
