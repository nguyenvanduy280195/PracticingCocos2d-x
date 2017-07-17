//
// Created by lazyguy on 15/07/2017.
//

#ifndef MYGAME_UTILS_H
#define MYGAME_UTILS_H

#include "Header.h"
namespace util {

	//API JSON
	class JSONParser {
	public:
		JSONParser(string);
		Vec2 getPosition(string);
		Size getSize(string);
		
	private:
		rapidjson::Document _document;
		int _sizeArray;
	};
}

#endif //MYGAME_UTILS_H
