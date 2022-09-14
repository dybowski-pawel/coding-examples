#    This file is part of Examples repository by Pawe³ Dybowski.
#
#    Copyright (C) 2021 Pawe³ Dybowski <dybowski015 at gmail dot com>
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
        src/Screenshot.cpp
        ../../src/Version.cpp
        )

include_directories(include)

SET("OpenCV_DIR" "${PROJECT_SOURCE_DIR}/external/OpenCV-4.5.4/build")

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

message(STATUS "OpenCV_DIR: ${OpenCV_DIR}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")

add_executable(idleon
        ${source_Files}
        )        

target_link_libraries(idleon ${OpenCV_LIBS} )