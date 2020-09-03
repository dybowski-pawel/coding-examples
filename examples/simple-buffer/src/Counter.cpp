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

#include "Counter.h"
#include <iostream>
void Counter::AddToBuffer(int value) {
    if(!IsReady() || IsStopRequested()) {
        return;;
    }
    number_buffer_.Add(value);
}

bool Counter::IsBufferEmpty() {
    return number_buffer_.Empty();
}


void Counter::DisplayAccumulatedValue() {
    std::unique_lock<std::mutex> lock(mutex_);
    std::cout << "So far I have: " << accumulated_value_ << std::endl;
}

void Counter::Loop() {
    const auto & value = number_buffer_.Get();
    std::unique_lock<std::mutex> lock(mutex_);
    accumulated_value_ += (*value.get());
}

void Counter::DeInit() {
    number_buffer_.Clear();
}