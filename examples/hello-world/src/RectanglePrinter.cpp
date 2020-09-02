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

#include <iostream>

#include "RectanglePrinter.h"

void RectanglePrinter::PrintRectangle(int rows, int cols) {
    std::string edgeChar = "x", middleChar = " ";
    DrawEdge(cols, edgeChar);
    for(int i=1; i<rows-1; i++) {
        DrawCenter(cols, edgeChar, middleChar);
    }
    DrawEdge(cols, edgeChar);
}

void RectanglePrinter::DrawEdge(int cols, std::string edgeChar) {
    DrawCenter(cols, edgeChar, edgeChar);
}

void RectanglePrinter::DrawCenter(int cols, std::string edgeChar, std::string middleChar) {
    std::cout << edgeChar;
    for(int i=1; i<cols-1; i++) {
        std::cout << middleChar;
    }
    std::cout << edgeChar;
    std::cout << std::endl;
}