#include <iostream>
using namespace std;

void dice() {
    srand(time(0)); //set seed for random numbers
    int roll = (rand() % 20) + 1; //roll of 1 - 20
}