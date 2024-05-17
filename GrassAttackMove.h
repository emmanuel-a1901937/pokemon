#ifndef GRASSATTACKMOVE_H
#define GRASSATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class GrassAttackMove : public AttackMove {
  public: 
    GrassAttackMove(string _name, string _type, int _damage, int _accuracy) {
      this->name = _name; 
      this->type = _type; 
      this->damage = _damage; 
      this->accuracy = _accuracy; 
    }

    string getName() {
      return name; 
    }

    int getDamage() {
      return damage; 
    }

    int getAccuracy() {
      return accuracy; 
    }
};

#endif