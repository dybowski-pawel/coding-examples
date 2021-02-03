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

#include "Lottery.h"
#include "LottoMachine.h"

LottoTicket Lottery::GetTicket(const unsigned int &bets, const unsigned int &drawsPerBet, const int &min_value, const int &max_value) {
    LottoTicket lottoTicket;
    LottoMachine lottoMachine(min_value, max_value);
    for(int bet=0; bet<bets; bet++) {
        lottoMachine.Reset();
        std::vector<int> currentDraws(drawsPerBet);
        for (int draw=0; draw < drawsPerBet; draw++) {
            currentDraws[draw] = lottoMachine.Draw();
        }
        lottoTicket.AddNewBet(currentDraws);
    }
    return lottoTicket;
}