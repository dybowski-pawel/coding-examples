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
// Created by pawel on 02.09.20.
//

#include <iostream>
#include <Counter.h>
#include "Version.h"

int main(int argc, const char *argv[]) {

    std::cout << "Version: " << Version::GetVersion() << std::endl << std::endl;
    Counter counter(0, true, 500);
    counter.WaitUntilReady();
    counter.AddToBuffer(4);
    counter.AddToBuffer(13);
    counter.AddToBuffer(16);
    counter.AddToBuffer(71);
    counter.AddToBuffer(41);
    counter.AddToBuffer(1);
    counter.AddToBuffer(7);
    while (!counter.IsBufferEmpty()) {
        counter.DisplayAccumulatedValue();
        Thread::Sleep(200);
    }
    counter.StopAndWait();

    return 0;
}