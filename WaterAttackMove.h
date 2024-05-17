#ifndef WATERATTACKMOVE_H
#define WATERATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class WaterAttackMove : public AttackMove {
  public: 
    WaterAttackMove(string _name, string _type, int _damage, int _accuracy) {
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