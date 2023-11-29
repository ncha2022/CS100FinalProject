#include "inventory.h"

using namespace std;

Item::Item(string name, string desc, int qty) : name(name), description(desc), quantity(qty) {}

void Inventory::addItem(const Item& item) {
    // check if item already exists in inventory
    for (auto& existingItem : items) {
        if (existingItem.name == item.name) {
            existingItem.quantity += item.quantity;
            return;
        }
    }
    // if doesnt exist then add item
    items.push_back(item);
}

void Inventory::dropItem(const string& itemName) {
    for (auto it = items.begin(); it != items.end(); ) {
        if (it->name == itemName) {
            if (it->quantity > 1) {
                --(it->quantity);
            } else {
                it = items.erase(it);
                continue;
            }
        }
        ++it;
    }
}

void Inventory::viewInventory() const {
    cout << "Inventory:" << endl;
    for (const auto& item : items) {
        cout << item.name << " - Quantity: " << item.quantity << endl;
    }
}

bool Inventory::hasItem(const std::string& itemName) const {
    for (const auto& item : items) {
        if (item.name == itemName && item.quantity > 0) {
            return true;
        }
    }
    return false;
}