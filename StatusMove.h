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
    StatusMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect, int _accuracy);
    string getName();
    int getAttackEffect();
    int getDefenceEffect();
    int getSpeedEffect();
    int getAccuracy();
};

#endif