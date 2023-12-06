#include "../header/game.h"
#include <iostream>
#include <limits>


using namespace std;

Game::Game() : player(), inventory(), store(), currentRoom(0), gameOver(false) {
    player.setMoney(50); // starting money
}

void Game::startGame() {
    cout << "Hello! Welcome to the dungeon games." << endl;
    int classChoice;
    string chosenClass;
    bool validClass = false;

    while (!validClass) {
        cout << "Choose your character class:" << endl;
        cout << "1. Tank" << endl;
        cout << "2. Fighter" << endl;
        cout << "3. Glass Cannon" << endl;
        cout << "4. Gambler" << endl;

        if (cin >> classChoice) {
            switch (classChoice) {
                case 1:
                    chosenClass = "Tank";
                    validClass = true;
                    break;
                case 2:
                    chosenClass = "Fighter";
                    validClass = true;
                    break;
                case 3:
                    chosenClass = "Glass Cannon";
                    validClass = true;
                    break;
                case 4:
                    chosenClass = "Gambler";
                    validClass = true;
                    break;
                default:
                    cout << "Invalid choice. Please choose a valid class." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    player.setClass(chosenClass, player);
    cout << "You have chosen the " << chosenClass << " class!" << endl;
    // ... rest of the function
}


void Game::openInventory() {
    bool inventoryOpen = true;
    while (inventoryOpen) {
        cout << "\nInventory Menu:" << endl;
        cout << "1. View Inventory" << endl;
        cout << "2. Equip Weapon" << endl;
        cout << "3. Unequip Weapon" << endl;
        cout << "4. Equip Armor" << endl;
        cout << "5. Unequip Armor" << endl;
        cout << "6. Use Consumable" << endl;
        cout << "7. Return to Main Menu" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.viewInventory();
                break;
            case 2: {
                cout << "Enter the name of the weapon to equip: ";
                string weapon;
                cin.ignore(); 
                getline(cin, weapon);
                if (player.getWeapon() == weapon) {
                    cout << "Weapon '" << weapon << "' is already equipped." << endl;
                } else {
                    inventory.equipWeapon(weapon);
                }
                break;
            }
            case 3:
                inventory.unequipWeapon();
                break;
            case 4: {
                cout << "Enter the name of the armor to equip: ";
                string armor;
                cin.ignore(); 
                getline(cin, armor);
                if (player.getArmor() == armor) {
                    cout << "Armor '" << armor << "' is already equipped." << endl;
                } else {
                    inventory.equipArmor(armor);
                }
                break;
            }
            case 5:
                inventory.unequipArmor();
                break;
            case 6: {
                cout << "Enter the name of the consumable to use: ";
                string consumable;
                cin.ignore(); 
                getline(cin, consumable);
                inventory.useConsumable(consumable);
                break;
            }
            case 7:
                inventoryOpen = false;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}


void Game::enterStore() {
    bool storeOpen = true;
    while (storeOpen) {
        cout << "\nStore Menu:" << endl;
        cout << "1. View Items" << endl;
        cout << "2. Buy Item" << endl;
        cout << "3. Return to Main Menu" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                store.displayStoreContents();
                break;
            case 2: {
                cout << "Enter the name of the item to buy: ";
                string item;
                cin >> item;
                store.purchaseItem(item);
                break;
            }
            case 3:
                storeOpen = false;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}

void Game::fightEnemy(Character &enemy, bool isBossBattle) {
    cout << (isBossBattle ? "Boss battle begins!" : "Combat starts!") << endl;

    bool playerTurn = true;
    while (player.getCurrentHealth() > 0 && enemy.getCurrentHealth() > 0) {
        if (playerTurn) {
            cout << "\nYour turn:" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use Item" << endl;

            int choice;
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // go to next iteration of while loop
            }

            switch (choice) {
                case 1: {
                    int damage = player.getTotalDamage();
                    cout << "You attack the enemy!" << endl;
                    int enemyHealth = enemy.getCurrentHealth() - damage;
                    enemy.setCurrentHealth(enemyHealth > 0 ? enemyHealth : 0);
                    cout << "The enemy has taken " << damage << " damage! Enemy's current HP: " << enemy.getCurrentHealth() << endl;
                    break;
                }
                case 2:
                    openInventory(); 
                    break;
                default:
                    cout << "Invalid choice, try again." << endl;
                    continue; // skips enemy turn
            }
        } else {
            // enemy's turn
            cout << "\nThe enemy attacks!" << endl;
            int damage = enemy.getTotalDamage();
            int playerHealth = player.getCurrentHealth() - damage;
            player.setCurrentHealth(playerHealth > 0 ? playerHealth : 0);
            cout << "Ouch! You have taken " << damage << " damage! Your current HP: " << player.getCurrentHealth() << endl;
        }

        // if you lost
        if (player.getCurrentHealth() <= 0) {
            cout << "You have been defeated!" << endl;
            gameOver = true;
            return;
        }

        // if enemy is defeated
        if (enemy.getCurrentHealth() <= 0) {
            cout << "You defeated the enemy!" << endl;
            if (isBossBattle) {
                cout << "Congratulations, you have defeated the boss and won the game!" << endl;
                gameOver = true;
            }
            return;
        }

        playerTurn = !playerTurn;
    }
}



void Game::moveToNextRoom() {
    if (currentRoom < totalRooms) {
        currentRoom++;
        cout << "Entering room " << currentRoom << "..." << endl;

        // enemy for currect room
        Character enemy = initializeEnemyForRoom(currentRoom);

        if (currentRoom == totalRooms) {
            cout << "final boss!" << endl;
            fightEnemy(enemy, true); // true for boss battle
        } else {
            cout << "An enemy is lurking in the shadows!" << endl;
            //false for reg enemy
            fightEnemy(enemy, false);
        }
    } else {
        cout << "Your journey has reached its conclusion. There are no more rooms to explore." << endl;
    }
}


Character Game::initializeEnemyForRoom(int roomNumber) {
    int enemyLevel = roomNumber; // enemy lvl = room #
    int enemyHealth = 50 + (roomNumber * 10); // health scaling
    int enemyAttack = 10 + (roomNumber * 5); // attack scaling

    // initialize enemy
    Character enemy("EnemyType", "Weapon", "Armor", 0, enemyLevel, 0, enemyHealth, enemyHealth, enemyAttack, enemyAttack);
    return enemy;
}

Character& Game::getPlayer() {
    return player;
}


void Game::checkGameOver() {
    if (gameOver) {
        cout << "Game Over. Restarting..." << endl;
        restartGame();
    }
}

void Game::restartGame() {
    // Reset game state
    Game();
}

int Game::getCurrentRoom() const{
    return currentRoom;
}

int main() {
    Game game;
    game.startGame();

   // add more storyline if needed

    bool gameRunning = true;

    while (gameRunning) {
        cout << "\nYou are currently in Room " << game.getCurrentRoom() << " of 10 ." << endl;
        
        cout << "Choose an action:" << endl;
        cout << "1. Open Inventory" << endl;
        cout << "2. Visit Store" << endl;
        cout << "3. Move to Next Room" << endl;
        cout << "4. Gamble" << endl; 
        cout << "5. Quit Game" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                game.openInventory();
                break;
            case 2:
                game.enterStore();
                break;
            case 3:
                game.moveToNextRoom();
                break;
            case 4:
                // gamble(game.getPlayer()); 
                break;
            case 5:
                cout << "THE END" << endl;
                gameRunning = false;
                break;
            default:
                cout << "invalid choice" << endl;
        }

        game.checkGameOver();
    }

    return 0;
}
