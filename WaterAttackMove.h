#ifndef WATERATTACKMOVE_H
#define WATERATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class WaterAttackMove : public AttackMove {
  public: 
    WaterAttackMove(string _name, string _type, int _damage, int _accuracy);
    string getName();
    int getDamage();
    int getAccuracy();
};

#endif