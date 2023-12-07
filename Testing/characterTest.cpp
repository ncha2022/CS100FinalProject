#include <gtest/gtest.h>
#include "../header/Character.h"

TEST(CharacterTest, constructorTest) {
    Character player;
    EXPECT_EQ(50, player.getMoney());
}
