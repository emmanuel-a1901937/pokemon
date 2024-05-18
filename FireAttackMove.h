#ifndef FIREATTACKMOVE_H
#define FIREATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class FireAttackMove : public AttackMove {
  public: 
    FireAttackMove(string _name, string _type, int _damage, int _accuracy); 
    string getName();
    int getDamage();
    int getAccuracy();
};

#endif