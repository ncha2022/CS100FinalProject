#include "../header/Character.h"
#include <iostream>
#include <string.h>

using namespace std;

Character::Character() {
    // Constructor for new game
    currClass = "";
    weapon = "";
    armor = "";
    money = 50;
    lvl = 1;
    exp = 0;
    maxHealth = 100;
    currentHealth = maxHealth;
    baseDamage = 20;
    totalDamage = baseDamage;
}

// Constructor for old game
Character::Character(string newClass, string newWeapon, string newArmor, int mny, int newLvl, int newExp, int maxHP, int currHP, int newBaseDamage, int newTotalDamage) {
    currClass = newClass;
    weapon = newWeapon;
    armor = newArmor;
    money = mny;
    lvl = newLvl;
    exp = newExp;
    maxHealth = maxHP;
    currentHealth = currHP;
    baseDamage = newBaseDamage;
    totalDamage = newTotalDamage;
}

// Destructor
Character::~Character() {

}

//Setter functions implementation
void Character::setClass(string newClass, Character currPlayer) {
    while(currClass == ""){
        if(newClass == "Tank"){
            currClass = newClass;
            armor = "Chainmail Armor";
            maxHealth = 150;
            currentHealth = 150;
            baseDamage = 10;
            weapon = "Wooden Sword";
            totalDamage = 20;
        }else if(newClass == "Fighter"){
            currClass = newClass;
            armor = "Leather Armor";
            maxHealth = 110;
            currentHealth = 110;
            baseDamage = 30;
            weapon = "Stone Sword";
            totalDamage = 60;
        }else if(newClass == "Glass Cannon"){
            currClass = newClass;
            armor = "";
            maxHealth = 500;
            currentHealth = 500;
            baseDamage = 80;
            weapon = "Stone Sword";
            totalDamage = 110;
        }else if(newClass == "Gambler"){
            currClass = newClass;
            armor = "";
            maxHealth = 40;
            currentHealth = 40;
            baseDamage = 10;
            weapon = "";
            totalDamage = 10;
            money = 200;
        }else{
            cout << "Unvalid Class" << endl;
        }
    }
}

void Character::setWeapon(string newWeapon) {
    weapon = newWeapon;
}

void Character::setArmor(string newArmor) {
    armor = newArmor;
}

void Character::setMoney(int mny) {
    money = mny;
}

void Character::setLvl(int newLvl) {
    lvl = newLvl;
}

void Character::setExp(int newExp) {
    exp = newExp;
}

void Character::setMaxHealth(int maxHP) {
    maxHealth = maxHP;
}

void Character::setCurrentHealth(int currHP) {
    currentHealth = currHP;
}

void Character::setBaseDamage(int newBaseDamage){
    baseDamage = newBaseDamage;
}

void Character::setTotalDamage(int newTotalDamage){
    totalDamage = newTotalDamage;
}


// Getter functions implementation
string Character::getClass() {
    return currClass;
}

string Character::getWeapon() {
    return weapon;
}

string Character::getArmor() {
    return armor;
}

int Character::getMoney() {
    return money;
}

int Character::getLvl() {
    return lvl;
}

int Character::getExp() {
    return exp;
}

int Character::getMaxHealth() {
    return maxHealth;
}

int Character::getCurrentHealth() {
    return currentHealth;
}

int Character::getBaseDamage(){
    return baseDamage;
}

int Character::getTotalDamage(){
    return totalDamage;
}
