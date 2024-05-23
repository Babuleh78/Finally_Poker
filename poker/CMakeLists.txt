cmake_minimum_required(VERSION 3.15)
project(poker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    AI.cpp
    GameMenu.cpp
    GameProcess.cpp
    Graphics.cpp
)

set(HEADERS
    AI.h
    GameMenu.h
    GameProcess.h
    Graphics.h
)

add_executable(poker ${SOURCES} ${HEADERS})

set(SFML_DIR "C:/hui/zaeb/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6.1 REQUIRED COMPONENTS system window graphics network audio)

target_include_directories(poker PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(poker sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
