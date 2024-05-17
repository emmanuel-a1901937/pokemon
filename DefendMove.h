#ifndef DEFENDMOVE_H
#define DEFENDMOVE_H

#include "Move.h"
using namespace std; 

class DefendMove : public Move {
  protected: 
    int attackEffect; 
    int defenceEffect; 
    int speedEffect; 

  public: 
    DefendMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect) {
      name = _name; 
      type = _type; 
      attackEffect = _attackEffect; 
      defenceEffect = _defenceEffect; 
      speedEffect = _speedEffect; 
    }

    string getName() {
      return name; 
    }

    int getAttackEffect() {
      return attackEffect; 
    }

    int getDefenceEffect() {
      return defenceEffect; 
    }

    int getSpeedEffect() {
      return speedEffect; 
    }
};

#endif