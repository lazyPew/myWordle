cmake_minimum_required(VERSION 3.1)

project(myWordle LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
set(SOURCES
    main.cpp
    game.cpp
    wordsmodel.cpp
    )

set(HEADERS
    game.h
    wordsmodel.h
    )

set(DISTFILES
    qrc/qml.qrc
    .gitignore
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${DISTFILES})

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    )
