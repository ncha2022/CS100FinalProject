#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {
    private:
        string class;
        string strength;
        string dexterity;
        string constitution;
        string intelligence;
        string wisdom;
        string charisma;
        string weapon;
        string armor;
        string money;
    public:
        Character();
        ~Character();

        void chooseClass();
        void chooseStats();
};

#endif // CHARACTER_HPP