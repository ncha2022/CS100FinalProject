#include <iostream>

void gamble() { //need adjustments for accounting for opponent's stats
    //assuming stats are in integer form or converted and are in a range of 1-100
    double strength = (player.getStrength()) / (enemy.getStrength());
    double dex = (player.getDexterity()) / (enemy.getDexterity());
    // constitution will not be compared to opponent's
    double constitution = player.getConstitution() / 100;
    double intelligence = (player.getIntelligence()) / (enemy.getIntelligence());
    double wisdom = (player.getWisdom()) / (enemy.getWisdom());
    double charisma = (player.getCharisma()) / (enemy.getCharisma());
    //adjust stat percentages according to ratio's later

    double chance;
    int damage = action.getDamage();
    char input;

    cout << "Would you like to stake some money?\n";
    while (input != 'y' || input != 'n') {
        cout << "y or n?\n";
        cin >> input;
        if (input != 'y' || input != 'n') {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no\n";
        }
    }

    if (input == 'y') {
        //figure out money gambling mechanic and how it will affect action
    }
    else {
        //change chance formula according to action stats (whether it depends on strength, wisdom, intelligence, etc)
        chance = (strength + dex + consitution + intelligence + wisdom + charisma) / 6;
        cout << "You have a " << chance << "% chance of effectiveness\n";
        damage = damage * chance;
        //either print out opponent health or display accordingly based on damage adjustment
    }
}