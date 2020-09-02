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

#include <RectanglePrinter.h>
#include <Version.h>

int main(int argc, const char *argv[]) {

    std::cout << "Version: " << Version::GetVersion() << std::endl << std::endl;

    std::cout << "Hello world!" << std::endl << "The lucky number for today (and always) is: " << 13 << std::endl;
    std::cout << "Here's a square for you" << std::endl;
    RectanglePrinter::PrintRectangle(15,25);
    std::cout << "Did you notice it is not a square?" << std::endl;
    return 0;
}