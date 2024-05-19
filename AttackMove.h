#ifndef ATTACKMOVE_H
#define ATTACKMOVE_H

#include "Move.h"
using namespace std; 

class AttackMove : public Move {
  protected: 
    int damage; 
    int accuracy; 

  public:
    void f(); 
};

#endif