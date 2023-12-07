cmake_minimum_required(VERSION 3.2)

add_subdirectory(googletest)

ADD_EXECUTABLE(game
    src/game.cpp
    src/Character.cpp
    src/gamble.cpp 
    src/Inventory.cpp
    src/store.cpp
)

ADD_EXECUTABLE(test
    Testing/characterTest.cpp
    src/Character.cpp
    )

TARGET_LINK_LIBRARIES(test gmock gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
