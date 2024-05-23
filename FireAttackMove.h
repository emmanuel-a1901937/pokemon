#ifndef FIREATTACKMOVE_H
#define FIREATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class FireAttackMove : public AttackMove {
  public: 
    FireAttackMove(string _name, string _type, int _damage, int _accuracy); 
    int getDamage(); // Returns the damage attribute 
    int getAccuracy(); // Returns the accuracy attribute 
};

#endif