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
Character::Character(string newClass, string newWeapon, string newArmor, int mny, int newLvl, int newExp, int maxHP, int currHP, int newBaseDamaage, int newTotalDamage) {
    currClass = cClass;
    weapon = wpn;
    armor = armr;
    money = mny;
    lvl = lv;
    exp = xp;
    maxHealth = maxHP;
    currentHealth = currHP;
    baseDamage = newBaseDamaage;
    totalDamage = newTotalDamage;
}

// Destructor
Character::~Character() {

}

//Setter functions implementation
void Character::setClass(string newClass) {
    currClass = newClass;
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
    baseDamagedamage = newBaseDamage;
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
