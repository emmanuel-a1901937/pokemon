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
    StatusMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect, int _accuracy); // Initialize StatusMove object 
    string getName(); // Returns name attribute
    int getAttackEffect(); // Returns attackEffect attribute 
    int getDefenceEffect(); // Returns defenceEffect attribute 
    int getSpeedEffect(); // Returns speedEffect attribute 
    int getAccuracy(); // Returns accuracy attribute 
};

#endif