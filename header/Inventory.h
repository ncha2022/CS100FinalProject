#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    std::string description;
    int quantity;
    Item(std::string name, std::string desc, int qty);
};

class Inventory {
private:
    std::vector<Item> items;
public:
    void addItem(const Item& item);
    void dropItem(const std::string& itemName);
    void viewInventory() const;
    bool hasItem(const std::string& itemName) const;
};

#endif // INVENTORY_H