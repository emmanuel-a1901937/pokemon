#ifndef GRASSATTACKMOVE_H
#define GRASSATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class GrassAttackMove : public AttackMove {
  public: 
    GrassAttackMove(string _name, string _type, int _damage, int _accuracy);
    string getName();
    int getDamage();
    int getAccuracy();
};

#endif