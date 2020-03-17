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
    static void printRectangle(int rows, int cols);

private:
    static void drawEdge(int cols, std::string edgeChar);
    static void drawCenter(int cols, std::string edgeChar, std::string middleChar);
};

#endif //EXAMPLES_RECTANGLEPRINTER_H
