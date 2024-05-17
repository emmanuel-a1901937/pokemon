#ifndef STATUSMOVE_H
#define STATUSMOVE_H

#include "Move.h"
using namespace std; 

class StatusMove : public Move {
  protected: 
    int attackEffect; 
    int defenceEffect; 
    int speedEffect; 
    int accuracy; 

  public: 
    StatusMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect, int _accuracy) {
      name = _name; 
      type = _type; 
      attackEffect = _attackEffect; 
      defenceEffect = _defenceEffect; 
      speedEffect = _speedEffect; 
      accuracy = _accuracy; 
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

    int getAccuracy() {
      return accuracy; 
    }
};

#endif