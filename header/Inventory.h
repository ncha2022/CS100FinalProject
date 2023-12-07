#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"

class Item {
    public:
        std::string name;
        Item(std::string name);
};

class Inventory {
    private:
        std::vector<Item> items;
        Character player;
    public:
        void addItem(const Item& item);
        void dropItem(const std::string& itemName);
        void viewInventory() const;
        void equipWeapon(string);
        void unequipWeapon();
        void equipArmor(string);
        void unequipArmor();
        void useConsumable(string);
};

#endif 
