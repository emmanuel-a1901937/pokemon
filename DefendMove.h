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
    DefendMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect); // Instantiate DefendMove object
    string getName(); // returns the name of the DefendMove
    int getAttackEffect(); // returns the attackEffect attribute 
    int getDefenceEffect(); // returns the defenceEffect attribute 
    int getSpeedEffect(); // returns the speedEffect attribute 
};

#endif