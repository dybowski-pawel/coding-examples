//
// Created by pawel on 17.03.20.
//

#include <iostream>

#include <RectanglePrinter.h>
#include <Version.h>

int main(int argc, const char *argv[]) {

    std::cout << "Version: " << Version::getVersion() << std::endl << std::endl;

    std::cout << "Hello world!" << std::endl << "The lucky number for today (and always) is: " << 13 << std::endl;
    std::cout << "Here's a square for you" << std::endl;
    RectanglePrinter::printRectangle(15,25);
    std::cout << "Did you notice it is not a square?" << std::endl;
    return 0;
}