//
// Created by pawel on 17.03.20.
//

#include <iostream>

#include "RectanglePrinter.h"

void RectanglePrinter::printRectangle(int rows, int cols) {
    std::string edgeChar = "x", middleChar = " ";
    drawEdge(cols, edgeChar);
    for(int i=1; i<rows-1; i++) {
        drawCenter(cols, edgeChar, middleChar);
    }
    drawEdge(cols, edgeChar);
}

void RectanglePrinter::drawEdge(int cols, std::string edgeChar) {
    drawCenter(cols, edgeChar, edgeChar);
}

void RectanglePrinter::drawCenter(int cols, std::string edgeChar, std::string middleChar) {
    std::cout << edgeChar;
    for(int i=1; i<cols-1; i++) {
        std::cout << middleChar;
    }
    std::cout << edgeChar;
    std::cout << std::endl;
}