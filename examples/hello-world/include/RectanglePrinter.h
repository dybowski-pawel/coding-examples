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

#ifndef EXAMPLES_RECTANGLEPRINTER_H
#define EXAMPLES_RECTANGLEPRINTER_H

#include <string>

class RectanglePrinter {
public:
    /*******************************************************************************
     * Print rectangle using "x" as edges
     * @param cols Number of columns the rectangle is supposed to have
     * @param rows Number of rows the rectangle is supposed to have
     ******************************************************************************/
    static void PrintRectangle(int rows, int cols);

private:
    /*******************************************************************************
     * Print rectangle's edge with given character.
     * @param cols Number of columns the edge is supposed to have
     * @param edgeChar what character to use while drawing edge
     ******************************************************************************/
    static void DrawEdge(int cols, std::string edgeChar);

    /*******************************************************************************
     * Print rectangle's center with given character
     * @param edgeChar what character to use as first and last in drawing
     * @param middleChar what character to use in between edges in drawing
     ******************************************************************************/
    static void DrawCenter(int cols, std::string edgeChar, std::string middleChar);
};

#endif //EXAMPLES_RECTANGLEPRINTER_H
