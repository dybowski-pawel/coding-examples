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

#ifndef EXAMPLES_COUNTER_H
#define EXAMPLES_COUNTER_H

#include <Thread.h>
#include <Buffer.h>

class Counter : public Thread {
    using Thread::Thread;
public:
    /*******************************************************************************
     * Add new value to buffer. When thread receives it, it will be added to sum
     ******************************************************************************/
    void AddToBuffer(int value);

    /*******************************************************************************
     * Check whether the buffer is empty
     * @return If buffer is empty
     ******************************************************************************/
    bool IsBufferEmpty();

    /*******************************************************************************
     * Print the sum in console
     ******************************************************************************/
    void DisplayAccumulatedValue();

protected:

    /*******************************************************************************
     * Wait for new value to be added to buffer, get it and add to sum
     ******************************************************************************/
    void Loop() override;

    /*******************************************************************************
     * Clear buffer of anything that was left
     ******************************************************************************/
    void DeInit() override;

    std::mutex mutex_;
    Buffer<int> number_buffer_;
    int accumulated_value_{0};
};


#endif //EXAMPLES_COUNTER_H
