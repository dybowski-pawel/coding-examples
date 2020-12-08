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

#include "../include/LottoTicket.h"
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> LottoTicket::GetBets() const {
    return bets_;
}

void LottoTicket::AddNewBet(std::vector<int> newBet) {
    if(!newBet.empty()) {
        std::sort(newBet.begin(), newBet.end());
        bets_.push_back(newBet);
    }
}

void LottoTicket::PrintBets() const {
    int count = 0;
    for(const auto & itBets : bets_) {
        std::cout << (++count) << ":\t";
        for(const auto & it : itBets) {
            std::cout << it << "\t";
        }
        std::cout << std::endl;
    }
}