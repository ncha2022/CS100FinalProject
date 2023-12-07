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
        int baseDamage;
        int totalDamage;
    public:
        //Constructor and Deconstructor
        Character();    //For new game
        Character(string currClass, string weapon, string armor, int money, int lvl, int exp, int maxHealth, int currentHealth, int newBaseDamaage, int newTotalDamage);    //For old game
        ~Character();

        //Setter functions
        void setClass(string, Character);
        void setWeapon(string);
        void setArmor(string);
        void setMoney(int);
        void setLvl(int);
        void setExp(int);
        void setMaxHealth(int);
        void setCurrentHealth(int); 
        void setBaseDamage(int);
        void setTotalDamage(int);

        //Getter functions
        string getClass();
        string getWeapon();
        string getArmor();
        int getMoney();
        int getLvl();
        int getExp();
        int getMaxHealth();
        int getCurrentHealth();
        int getBaseDamage();
        int getTotalDamage();

};

#endif // CHARACTER_HPP