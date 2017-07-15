//
// Created by lazyguy on 15/07/2017.
//

#include "Utils.h"

Document Utils::xmlParse(string filename) {
    auto fileUtils = FileUtils::getInstance();
    string str = fileUtils->getDefaultResourceRootPath();

    Document document;
    ssize_t size;

    auto buf = (char *) fileUtils->getFileData(str + filename, "r", &size);

    document.Parse(buf);

    return document;
}