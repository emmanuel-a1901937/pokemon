#ifndef FIREATTACKMOVE_H
#define FIREATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class FireAttackMove : public AttackMove {
  public: 
    FireAttackMove(string _name, string _type, int _damage, int _accuracy) {
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