#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream> 
using namespace std; 

class Move {
  protected: 
    string name; 
    string type; 

  public: 
    string getName(); 
    string getType(); 

    // AttackMove child functions 
    int getDamage();
    int getAccuracy(); // note: also a StatusMove child function 

    // DefendMove and StatusMove child functions
    int getAttackEffect();
    int getDefenceEffect();
    int getSpeedEffect();
};

#endif