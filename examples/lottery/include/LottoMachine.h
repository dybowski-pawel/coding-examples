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
// Created by pawel on 08.12.20.
//

#ifndef EXAMPLES_LOTTOMACHINE_H
#define EXAMPLES_LOTTOMACHINE_H

#include <set>
#include <random>

class LottoMachine {
public:

    /*******************************************************************************
     * Creates a lotto machine
     * @param minValue Minimum value that can be drawn
     * @param maxValue Maximum value that can be drawn
     ******************************************************************************/
    LottoMachine(const int &minValue, const int &maxValue);

    /*******************************************************************************
     * Resets the machine
     * After this operation all draws done so far are forgotten
     ******************************************************************************/
    void Reset();

    /*******************************************************************************
     * Does a new draw from the machine
     * This draw is different from all draws done since last reset
     * If all numbers have been drawn, 0 is returned
     ******************************************************************************/
    int Draw();

private:
    std::set<int> draws_;
    std::mt19937 mt_;
    std::uniform_int_distribution<int> distribution_;
    const unsigned int range;
};


#endif //EXAMPLES_LOTTOMACHINE_H
