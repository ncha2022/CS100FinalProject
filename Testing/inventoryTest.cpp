#include <gtest/gtest.h>
#include "../header/Inventory.h"
#include "../header/Character.h"

TEST(InventoryTest, addItemTest){
    Inventory inv;
    inv.addItem("Leather Armor");
    EXPECT_EQ("Leather Armor", inv.printBeginning());
}

TEST(InventoryTest, dropItemTest){
    Inventory inv;
    inv.addItem("Leather Armor");
    inv.addItem("Iron Armor");
    inv.dropItem("Leather Armor");
    EXPECT_EQ("Iron Armor", inv.printBeginning());
}

TEST(InventoryTest, equipWeaponTest){
    Inventory inv;
    inv.equipWeapon("Iron Sword");
    EXPECT_EQ("Iron Sword", inv.player.getWeapon());
}

TEST(InventoryTest, unequipWeaponTest){
    Inventory inv;
    inv.equipWeapon("Iron Sword");
    inv.unequipWeapon();
    EXPECT_EQ("", inv.player.getWeapon());
}

TEST(InventoryTest, equipArmorTest){
    Inventory inv;
    inv.equipArmor("Leather Armor");
    EXPECT_EQ("Leather Armor", inv.player.getArmor());
}

TEST(InventoryTest, unequipArmorTest){
    Inventory inv;
    inv.equipArmor("Leather Armor");
    inv.unequipArmor();
    EXPECT_EQ("", inv.player.getArmor());
}

TEST(InventoryTest, useConsumableTest){
    Inventory inv;
    inv.player.setCurrentHealth(10);
    inv.useConsumable("Small Health Potion");
    EXPECT_EQ(50, inv.player.getCurrentHealth());
}

TEST(InventoryTest, overhealTest){
    Inventory inv;
    inv.player.setCurrentHealth(80);
    inv.useConsumable("Small Health Potion");
    EXPECT_EQ(100, inv.player.getCurrentHealth());
}