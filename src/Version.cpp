//    This file is part of Examples repository by Paweł Dybowski.
//
//    Copyright (C) 2020 Paweł Dybowski <dybowski015 at gmail dot com>
//    https://github.com/dybowski-pawel/coding-examples
//
//    Examples is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Examples is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Examples.  If not, see <https://www.gnu.org/licenses/>.

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
