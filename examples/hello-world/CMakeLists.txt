SET(source_Files
        src/main.cpp
        src/RectanglePrinter.cpp
        ../../src/Version.cpp
        )

include_directories(include)

add_executable(hello-world
        ${source_Files}
        )
