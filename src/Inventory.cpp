#include "inventory.h"
#include "Character.h"

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

void Inventory::equipWeapon(string newWeapon){
    if(player.getWeapon == ""){
        player.setWeapon(newWeapon);
    }
}

void Inventory::unequipWeapon(){
    
}

void Inventory::equipArmor(){
    
}

void Inventory::unequipAeapon(){
    
}
