#ifndef DEFENDMOVE_H
#define DEFENDMOVE_H

#include "Move.h"
using namespace std; 

class DefendMove : public Move {
  protected: 
    float attackEffect; 
    float defenceEffect; 
    float speedEffect; 

  public: 
    DefendMove(string _name, string _type, float _attackEffect, float _defenceEffect, float _speedEffect);
    string getName();
    float getAttackEffect();
    float getDefenceEffect();
    float getSpeedEffect();
    void f(); 
};

#endif