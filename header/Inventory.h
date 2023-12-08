#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"

using namespace std;

class Inventory {
    private:
        vector<string> items;
    public:
        Character player;
        void addItem(const string&);
        void dropItem(const string&);
        void viewInventory() const;
        void equipWeapon(string);
        void unequipWeapon();
        void equipArmor(string);
        void unequipArmor();
        void useConsumable(string);
        string printBeginning();
        vector<string>::iterator begin() { return items.begin(); }
        vector<string>::iterator end() { return items.end(); }

};

#endif 
