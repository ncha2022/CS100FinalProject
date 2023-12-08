#ifndef GAMBLE_H
#define GAMBLE_H

#include "Character.h"


class Gamble{
private:
   int dice(int num); 

public:
   void gamble(Character &player);
};

#endif