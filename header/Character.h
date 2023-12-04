#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string.h>

using namespace std;

class Character {
    private:
        string currClass;
        string weapon;
        string armor;
        int money;
        int lvl;
        int exp;
        int maxHealth;
        int currentHealth;
    public:
        //Constructor and Deconstructor
        Character();    //For new game
        Character(string currClass, string weapon, string armor, int money, int lvl, int exp, int maxHealth, int currentHealth);    //For old game
        ~Character();

        //Setter functions
        void setClass();
        void setWeapon();
        void setArmor();
        void setMoney();
        void setLvl();
        void setExp();
        void setMaxHealth();
        void setCurrentHealth(); 

        //Getter functions
        string getClass();
        string getWeapon();
        string getArmor();
        int getMoney();
        int getLvl();
        int getExp();
        int getMaxHealth();
        int getCurrentHealth();

};

#endif // CHARACTER_HPP