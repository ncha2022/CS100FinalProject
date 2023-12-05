#include "game.h"
#include <iostream>

using namespace std;

Game::Game() : player(), inventory(), store(), currentRoom(0), gameOver(false) {
    player.setMoney(50); // starting money
}

void Game::startGame() {
    cout << "Welcome to our game" << endl;

    cout << "Choose your character class:" << endl;
    cout << "1. Tank" << endl;
    cout << "2. Fighter" << endl;
    cout << "3. Glass Cannon" << endl;
    cout << "4. Gambler" << endl;

    int classChoice;
    cin >> classChoice;
    string chosenClass;

    switch (classChoice) {
        case 1:
            chosenClass = "Tank";
            break;
        case 2:
            chosenClass = "Fighter";
            break;
        case 3:
            chosenClass = "Glass Cannon";
            break;
        case 4:
            chosenClass = "Gambler";
            break;
        default:
            cout << "Invalid choice. Defaulting to Fighter." << endl;
            chosenClass = "Fighter";
    }

    player.setClass(chosenClass, player);
    cout << "You have chosen the " << chosenClass << " class!" << endl;

    // initial room
    currentRoom = 1;
    cout << "You start your journey in room " << currentRoom << "." << endl;

    // storyline info
    cout << "your adventure begins...." << endl;
    cout << "add more story here " << endl;

    // instructions
    cout << "here are some instructions on how to play the game: " << endl;

    // game loop
    cout << "your journey starts now!!" << endl;
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
                if (inventory.getEquippedWeapon() == weapon) {
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
                if (inventory.getEquippedArmor() == armor) {
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
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "You attack the enemy!" << endl;
                    int enemyHealth = enemy.getCurrentHealth() - player.getTotalDamage();
                    enemy.setCurrentHealth(enemyHealth > 0 ? enemyHealth : 0);
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
            int playerHealth = player.getCurrentHealth() - enemy.getTotalDamage();
            player.setCurrentHealth(playerHealth > 0 ? playerHealth : 0);
        }

        // if you lost
        if (player.getCurrentHealth() <= 0) {
            cout << "You have been defeated!" << endl;
            gameOver = true;
            return;
        }

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

int main() {
    Game game;
    game.startGame();

    cout << "storyline " << endl;
    cout << "storyline " << endl;

    bool gameRunning = true;

    while (gameRunning && !game.gameOver) {
        cout << "\nYou are currently in Room " << game.getCurrentRoom() << " of " << game.getTotalRooms() << "." << endl;
        
        cout << "Choose an action:" << endl;
        cout << "1. Open Inventory" << endl;
        cout << "2. Visit Store" << endl;
        cout << "3. Move to Next Room" << endl;
        cout << "4. Check Stats" << endl;
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
                game.checkStats();
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
