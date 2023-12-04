#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>

class Item {
    public:
        std::string name;
        Item(std::string name);
};

class Inventory {
    private:
        std::vector<Item> items;
    public:
        void addItem(const Item& item);
        void dropItem(const std::string& itemName);
        void viewInventory() const;
};

#endif 
