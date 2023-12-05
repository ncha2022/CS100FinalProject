#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Inventory.h"
#include "Store.hpp"
#include <vector>
#include <string>

class Game {
private:
    Character player;
    Inventory inventory;
    Store store;
    int currentRoom;
    const int totalRooms = 10;
    bool gameOver;

public:
    Game(); 
    void startGame();
    void openInventory();
    void enterStore();
    void fightEnemy(Character &enemy, bool isBossBattle); 
    void moveToNextRoom();
    Character initializeEnemyForRoom(int roomNumber); 
    void checkGameOver();
    void restartGame();
};

#endif 
