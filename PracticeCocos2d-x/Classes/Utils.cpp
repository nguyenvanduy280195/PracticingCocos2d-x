//
// Created by lazyguy on 15/07/2017.
//

#include "Utils.h"

util::JSONParser::JSONParser(string filename) {
	auto fileUtils = FileUtils::getInstance();
	ssize_t size;
	auto buf = (char *)fileUtils->getFileData(PATH_ROOT + filename, "r", &size);
	buf[size] = '\0';
	_document.Parse(buf);

	_sizeArray = _document[TEXTURE_ALIAS][SUB_TEXTURE].Size();
}

Vec2 util::JSONParser::getPosition(string name) {
	for (int i = 0; i < _sizeArray; i++) {
		if (_document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_NAME].GetString() == name) {
			int x = _document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_X].GetInt();
			int y = _document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_Y].GetInt();
			return Vec2(x, y);
		}
	}
	return Vec2(-1, -1);
}

Size util::JSONParser::getSize(string name) {
	for (int i = 0; i < _sizeArray; i++) {
		if (_document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_NAME].GetString() == name) {
			int width = _document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_WIDTH].GetInt();
			int height = _document[TEXTURE_ALIAS][SUB_TEXTURE][i][ATT_HEIGHT].GetInt();
			return Size(width, height);
		}
	}
	return Size(-1, -1);
}