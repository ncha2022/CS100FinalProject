#include <gtest/gtest.h>
#include "../header/Character.h"

TEST(CharacterTest, constructorTest) {
    Character player;
    EXPECT_EQ(50, player.getMoney());
    EXPECT_EQ("", player.getClass());
    EXPECT_EQ("", player.getWeapon());
    EXPECT_EQ("", player.getArmor());
    EXPECT_EQ(1, player.getLvl());
    EXPECT_EQ(0, player.getExp());
    EXPECT_EQ(100, player.getMaxHealth());
    EXPECT_EQ(100, player.getCurrentHealth());
    EXPECT_EQ(20, player.getBaseDamage());
    EXPECT_EQ(20, player.getTotalDamage());
}


TEST(CharacterTest, classTest){
    Character player;
    player.setClass("Fighter", player);
    EXPECT_EQ("Fighter", player.getClass());
}

TEST(CharacterTest, moneyTest){
    Character player;
    player.setMoney(100);
    EXPECT_EQ(100, player.getMoney());
}

TEST(CharacterTest, weaponTest){
    Character player;
    player.setWeapon("Wooden Sword");
    EXPECT_EQ("Wooden Sword", player.getWeapon());
}

TEST(CharacterTest, armorTest){
    Character player;
    player.setArmor("Leather Armor");
    EXPECT_EQ("Leather Armor", player.getArmor());
}

TEST(CharacterTest, lvlTest){
    Character player;
    player.setLvl(3);
    EXPECT_EQ(3, player.getLvl());
}

TEST(CharacterTest, expTest){
    Character player;
    player.setExp(3);
    EXPECT_EQ(3, player.getExp());
}

TEST(CharacterTest, maxHealthTest){
    Character player;
    player.setMaxHealth(3);
    EXPECT_EQ(3, player.getMaxHealth());
}

TEST(CharacterTest, currentHealthTest){
    Character player;
    player.setCurrentHealth(3);
    EXPECT_EQ(3, player.getCurrentHealth());
    EXPECT_EQ(100, player.getMaxHealth());
}

TEST(CharacterTest, baseDamageTest){
    Character player;
    player.setBaseDamage(3);
    EXPECT_EQ(3, player.getBaseDamage());
}

TEST(CharacterTest, totalDamageTest){
    Character player;
    player.setTotalDamage(3);
    EXPECT_EQ(3, player.getTotalDamage());
}

