#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream> 
using namespace std; 

#include "Pokemon.h"

class Move {
  protected: 
    string name; 
    string type; 

  public: 
    virtual void useMove(Pokemon* p1, Pokemon* p2) = 0; 
};

#endif