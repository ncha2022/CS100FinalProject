CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
add_subdirectory(googletest)
project(cs100-game)

# ADD_EXECUTABLE(games
#     src/game.cpp
#     src/Character.cpp
#     src/gamble.cpp 
#     src/Inventory.cpp
#     src/store.cpp
# )

ADD_EXECUTABLE(game
    src/game.cpp
    src/Character.cpp
    src/gamble.cpp 
    src/Inventory.cpp
    src/store.cpp
    Testing/testStore.cpp
)

TARGET_LINK_LIBRARIES(game gmock gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(game PRIVATE gtest_disable_pthreads=ON)
