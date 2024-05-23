#ifndef GRASSATTACKMOVE_H
#define GRASSATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class GrassAttackMove : public AttackMove {
  public: 
    GrassAttackMove(string _name, string _type, int _damage, int _accuracy); // constructor to initialise object
    string getName(); // Returns name of the GrassAttackMove
    int getDamage(); // Returns damage attribute 
    int getAccuracy(); // Returns accuracy attribute 
};

#endif