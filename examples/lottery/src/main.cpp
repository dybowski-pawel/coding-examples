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

#include <iostream>
#include <string>
#include <chrono>
#include <Lottery.h>
#include "Version.h"

int main(int argc, const char *argv[]) {

    unsigned int bets = 0;
    unsigned int draws = 0;
    int minValue = 0;
    int maxValue = 0;

    if(argc > 1) {
        std::string arg(argv[1]);
        if(arg == "-V" || arg == "-v" || arg == "--version") {
            std::cout << "Version: " << Version::GetVersion() << std::endl;
            return 0;
        } else if(arg == "-h") {
            std::cout << "Usage: ./lottery numberOfBest numberOfDraws minValue maxValue" << std::endl;
            std::cout << "Version: ./lottery -V" << std::endl;
        } else {
            bets = (unsigned int) std::stoul(arg);
            if(argc > 2) {
                arg = std::string(argv[2]);
                draws = (unsigned int) std::stoul(arg);
                if(argc > 3) {
                    arg = std::string(argv[3]);
                    minValue = (unsigned int) std::stoul(arg);
                    if(argc > 4) {
                        arg = std::string(argv[4]);
                        maxValue = (unsigned int) std::stoul(arg);
                    }
                }
            }
        }
    }

    if(bets == 0) {
        std::cout << "How many bets do you want to place?" << std::endl;
        std::cout << "Input: ";
        std::string input;
        std::cin >> input;
        bets = (unsigned int) std::stoul(input);
    }

    if(draws == 0) {
        std::cout << "How many draws do you want to have per bet?" << std::endl;
        std::cout << "Input: ";
        std::string input;
        std::cin >> input;
        draws = (unsigned int) std::stoul(input);
    }

    if(minValue == 0) {
        std::cout << "What is the smallest possible number to draw?" << std::endl;
        std::cout << "Input: ";
        std::string input;
        std::cin >> input;
        minValue = std::stoi(input);
    }

    if(maxValue == 0) {
        std::cout << "What is the highest possible number to draw?" << std::endl;
        std::cout << "Input: ";
        std::string input;
        std::cin >> input;
        maxValue = std::stoi(input);
    }

    if(minValue > maxValue) {
        std::cout << "Minimum value is greater than maximum value. Exiting." << std::endl;
        return 1;
    }

    if(maxValue - minValue + 1 < draws) {
        std::cout << "Number of draws exceeds allowed range. Exiting." << std::endl;
        return 2;
    }

    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
    std::time_t  time = std::chrono::system_clock::to_time_t(timePoint);
    const char * timeChar = std::ctime(&time);

    const LottoTicket lottoTicket = Lottery::GetTicket(bets, draws, minValue, maxValue);

    std::cout << std::string( 100, '\n' );

    std::cout << "XXXXXXXXXXXXXXX   LOTTO   XXXXXXXXXXXXXXX" << std::endl;

    lottoTicket.PrintBets();

    std::cout << "Draw date: " << timeChar;

    return 0;
}
