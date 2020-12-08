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

#ifndef EXAMPLES_LOTTERY_H
#define EXAMPLES_LOTTERY_H


#include "LottoTicket.h"

class Lottery {
public:
    /*******************************************************************************
     * Returns a Lottery ticket from draws that it performs on a lotto machine
     * @param bets Number of bets to make
     * @param drawsPerBet Number of draws to make per bet. <br> Default: 6
     * @param minValue Minimum value that can be drawn. <br> Default: 1
     * @param maxValue Maximum value that can be drawn. <br> Default: 49
     ******************************************************************************/
    static LottoTicket GetTicket(const unsigned int &bets, const unsigned int &drawsPerBet = 6, const int &minValue = 1, const int &maxValue = 49);
};


#endif //EXAMPLES_LOTTERY_H
