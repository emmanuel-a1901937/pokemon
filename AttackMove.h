#ifndef ATTACKMOVE_H
#define ATTACKMOVE_H

#include "Move.h"
using namespace std; 

class AttackMove : public Move {
  protected: 
    int damage; 
    int accuracy; 
  
  public: 
    int getDamage(); // Returns the AttackMove's damage attribute 
    int getAccuracy(); // Returns the AttackMove's accuracy attribute 
};

#endif