#include <iostream>
#include <limits>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int dice(int num) {
    srand(time(0)); //set seed
    int roll = (rand() % num) + 1; //roll of 1 - num
    return roll;
}

void gamble(Character player) { 
    char input = 'x';

    while (input != 'y' && input != 'n') {
        cout << "Would you like to stake some money?\n";
        cout << "y or n?\n";
        cin >> input;
        if (input != 'y' && input != 'n') {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (input == 'y') { // gamble option
        if(player.getMoney() < 1) {
            cout << "You do not have the sufficient funds to gamble.\n";
            cout << "Current balance: " << player.getMoney() << '\n';
            cout << "Exiting...\n";
            return;
        }

        cout << "How much money would you like to bet?\n";
        cout << "Current balance: " << player.getMoney() << '\n';

        int bet = -1;
        cin >> bet;
        while (bet > player.getMoney() || bet < 1) {
            if (bet > player.getMoney()) {
                cout << "Invalid input. You do not have the sufficient funds to bet that amount.\n";
            }
            else if (bet < 1) {
                cout << "Invalid input. You cannot bet no/negative money.\n";
            }
            cout << "Please enter a valid amount you would like to bet from your funds.\n";
            cout << "Current balance: " << player.getMoney() << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> bet;
        }

        cout << "You have decided to bet " << bet << " from your funds.\n";
        cout << "Your balance will be adjusted accordingly.\n";
        player.setMoney(player.getMoney() - bet);
        cout << "Current balance: " << player.getMoney() << '\n';
        cout << "Bet amount : " << bet << '\n';
        cout << '\n';
        
        cout << "Would you like to 2x, 5x or 10x your money?\n";
        cout << "Enter 1 for 2x, 2 for 5x, or 3 for 10x\n";

        int num = 0;
        while (num < 1 || num > 3) {
            cin >> num;
            if (num < 1 || num > 3) {
                cout << "Invalid input. Please enter 1, 2 or 3 to decide.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (num == 1) {
            cout << "You have chosen to 2x your money.\n";
            cout << "Heads or Tails?\n";
            cout << "Enter H for Heads or T for Tails\n";

            char choice = 'x';
            while (choice != 'H' && choice != 'T') {
                cin >> choice;
                if (choice != 'H' && choice != 'T') {
                    cout << "Invalid input. Please enter H or T.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if (choice == 'H') {
                cout << "You have chosen Heads.\n";
            }
            else if (choice == 'T') {
                cout << "You have chosen Tails.\n";
            }
            cout << "Flipping a coin.\n";
            sleep(3);
            int result = dice(2);

            if (result == 1) {
                cout << "Heads!\n";
            }
            else if (result == 2) {
                cout << "Tails!\n";
            }

            if (result == 1 && choice == 'H' || result == 2 && choice == 'T') {
                cout << "Congratulations! The coin has landed in your favor.\n";
                cout << "You will now receive 2x your money bet.\n";
                player.setMoney(player.getMoney() + (2 * bet));
                cout << "Current balance: " << player.getMoney() << '\n';
            }
            else {
                cout << "The gods of luck do not smile upon you this time.\n";
                cout << "You have lost the money you have bet and you are now filled with severe disappointment.\n";
            }
        }
        else if (num == 2) {
            cout << "You have chosen to 5x your money.\n";
            cout << "A singular 5-sided dice will be rolled.\n";
            cout << "Choose a number from 1 to 5.\n";

            int guess = 0;
            while (guess < 1 || guess > 5) {
                cin >> guess;
                if (guess < 1 || guess > 5) {
                    cout << "Invalid input. Please choose a number from 1 to 5.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "You have chosen the number " << guess << ".\n";
            cout << "Rolling the dice.\n";
            sleep(5);
            int result = dice(5);

            if (result == guess) {
                cout << "Congratulations! Lady Luck has smiled upon you.\n";
                cout << "The dice has landed on " << result << ".\n";
                cout << "You will now receive 5x your money bet.\n";
                player.setMoney(player.getMoney() + (5 * bet));
                cout << "Current balance: " << player.getMoney() << '\n';
            }
            else {
                cout << "Unfortunately, the dice has landed on " << result << ".\n";
                cout << "You have lost the money you have bet and you are now filled with severe disappointment.\n";
                cout << "You wonder about what could have been if you won and are now developing slight alcoholic tendencies.\n";
            }
        }
        else if (num == 3) {
            cout << "You have chosen to 10x your money.\n";
            cout << "A singular 10-sided dice will be rolled.\n";
            cout << "Choose a number from 1 to 10.\n";

            int guess = 0;
            while (guess < 1 || guess > 10) {
                cin >> guess;
                if (guess < 1 || guess > 10) {
                    cout << "Invalid input. Please choose a number from 1 to 10.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "You have chosen the number " << guess << ".\n";
            cout << "Rolling the dice.\n";
            sleep(5);
            int result = dice(10);

            if (result == guess) {
                cout << "Congratulations! Lady Luck has smiled upon you.\n";
                cout << "The dice has landed on " << result << ".\n";
                cout << "You will now receive 10x your money bet.\n";
                player.setMoney(player.getMoney() + (10 * bet));
                cout << "Current balance: " << player.getMoney() << '\n';
            }
            else {
                cout << "Unfortunately, the dice has landed on " << result << ".\n";
                cout << "You have lost the money you have bet and you are now filled with severe disappointment.\n";
                cout << "You wonder about what could have been if you won and are now developing slight alcoholic tendencies.\n";
                cout << "You stop by the bar on the way home and decide to have a few drinks.\n";
                cout << "Some time passes and you have gotten too drunk.\n";
                cout << "You end up getting into a fight at the bar and you are now spending the night in jail, wondering how you lost both your money and your dignity.\n";
            }
        }
    }
    else { // no gamble option
        cout << "Congratulations! You have decided not to stake any money.\n";
        cout << "You are within the more uncommon portion of the population who decide not to gamble their money away.\n";
    }
}