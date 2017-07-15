//
// Created by lazyguy on 15/07/2017.
//

#include "Target.h"

bool Target::init(){
    if(!Sprite::init()){
        return false;
    }

    int x = RandomHelper::random_int(10,20);
    int y = RandomHelper::random_int(10,20);


    return true;
}