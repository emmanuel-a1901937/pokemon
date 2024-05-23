#ifndef STATUSMOVE_H
#define STATUSMOVE_H

#include "Move.h"
using namespace std; 

class StatusMove : public Move {
  protected: 
    float attackEffect; 
    float defenceEffect; 
    float speedEffect; 
    int accuracy; 

  public: 
    StatusMove(string _name, string _type, float _attackEffect, float _defenceEffect, float _speedEffect, int _accuracy);
    string getName();
    float getAttackEffect();
    float getDefenceEffect();
    float getSpeedEffect();
    int getAccuracy();
    void f(); 
};

#endif