#include "inventory.h"

using namespace std;

Item::Item(string name) : name(name) {}

void Inventory::addItem(const Item& item) {
    items.push_back(item);
}

void Inventory::dropItem(const string& itemName) {
    for (auto it = items.begin(); it != items.end(); ) {
        if (it->name == itemName) {
            it = items.erase(it);
        } else {
            ++it;
        }
    }
}

void Inventory::viewInventory() const {
    cout << "Inventory:" << endl;
    for (const auto& item : items) {
        cout << item.name << endl;
    }
}
