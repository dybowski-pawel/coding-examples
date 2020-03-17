//
// Created by pawel on 17.03.20.
//

#include <Version.h>

void Version::initialize() {
    VERSION_MAJOR = "0";
    VERSION_MINOR = "1";
    VERSION_PATCH = "0";
    VERSION_BUILD = "";
    initialized = true;
}

std::string Version::getVersion() {
    if(!initialized) {
        initialize();
    }
    std::string out = std::string(VERSION_MAJOR+"."+VERSION_MINOR+"."+VERSION_PATCH);
    if(!VERSION_BUILD.empty()) {
        out += "+"+VERSION_BUILD;
    }
    return std::string(out);
}

int Version::calculateValue() {
    if(!initialized) {
        initialize();
    }
    int value = 0;
    value += std::stoi(VERSION_BUILD)*100*100;
    value += std::stoi(VERSION_MAJOR)*100;
    value += std::stoi(VERSION_MINOR);
    return value;
}
