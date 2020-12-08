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

#ifndef EXAMPLES_LOTTOTICKET_H
#define EXAMPLES_LOTTOTICKET_H

#include <vector>

class LottoTicket {
public:
    /*******************************************************************************
     * Return a vector of bets
     * Each bet is a vector of unsigned int
     ******************************************************************************/
    std::vector<std::vector<int>> GetBets() const;

    /*******************************************************************************
     * Sorts and then adds new bet to collection
     ******************************************************************************/
    void AddNewBet(std::vector<int> newBet);

    /*******************************************************************************
     * Prints bets to screen in form<br>
     * Id: x x x ... [newline]
     ******************************************************************************/
    void PrintBets() const;

private:
    std::vector<std::vector<int>> bets_;
};


#endif //EXAMPLES_LOTTOTICKET_H
