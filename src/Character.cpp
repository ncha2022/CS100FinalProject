#include "character.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Character::Character{
    name = new char[strlen(name_)];
    strcpy(name, name_);
    father = father_;
    mother = mother_;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}

Character::~Character(){
    delete character;
}

// void Person::addChild(Person *newChild){
//     if(numChildren == capacity) expand(&children, &capacity);
//     children[numChildren++] = newChild;
// }

