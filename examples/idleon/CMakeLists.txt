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

SET("OpenCV_BASE_DIR" "${PROJECT_SOURCE_DIR}/../../OpenCV-4.6.0")
SET("OpenCV_DIR" "${OpenCV_BASE_DIR}/mingw-build")
SET("OpenCV_SRC_DIR" "${OpenCV_BASE_DIR}/sources")
SET("OpenCV_INCLUDE_DIR" "${OpenCV_SRC_DIR}/include")

find_package(OpenCV REQUIRED)

SET(source_Files
        src/main.cpp
        src/Screenshot.cpp
        ../../src/Version.cpp
        )

SET(include_Files
        include
        ${OpenCV_INCLUDE_DIRS}
        )

SET(link_Libraries
        ${OpenCV_LIBS}
        )

include_directories(${include_Files})

add_executable(idleon ${source_Files})

target_link_libraries(idleon ${link_Libraries})

message(STATUS "OpenCV_DIR: ${OpenCV_DIR}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")