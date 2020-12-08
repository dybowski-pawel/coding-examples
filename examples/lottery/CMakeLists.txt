#    This file is part of Examples repository by Paweł Dybowski.
#
#    Copyright (C) 2020 Paweł Dybowski <dybowski015 at gmail dot com>
#    https://github.com/dybowski-pawel/coding-examples
#
#    Examples is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Examples is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Examples.  If not, see <https://www.gnu.org/licenses/>.

SET(source_Files
        src/main.cpp
        src/Lottery.cpp
        src/LottoTicket.cpp
        ../../src/Version.cpp
        src/LottoMachine.cpp)

include_directories(include)

add_executable(lottery
        ${source_Files}
        )
