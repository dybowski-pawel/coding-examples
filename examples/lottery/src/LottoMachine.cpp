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

#include "LottoMachine.h"

LottoMachine::LottoMachine(const int &minValue, const int &maxValue)
    : range((unsigned int) maxValue - minValue + 1) {
        std::random_device device;
        std::mt19937 generator(device());
        mt_ = generator;
        distribution_ = std::uniform_int_distribution<int>(minValue, maxValue);
}

void LottoMachine::Reset() {
    draws_.clear();
}

int LottoMachine::Draw() {
    if(range == draws_.size()) {
        return 0;
    }
    int draw = 0;
    while (true) {
        draw = distribution_(mt_);
        if (draws_.count(draw) == 0) {
            draws_.insert(draw);
            break;
        }
    }
    return draw;
}