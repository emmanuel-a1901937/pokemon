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
   virtual string getName(); 
   virtual string getType(); 

    // AttackMove child functions 
    virtual int getDamage();
    virtual int getAccuracy(); // note: also a StatusMove child function 

    // DefendMove and StatusMove child functions
    virtual int getAttackEffect();
    virtual int getDefenceEffect();
    virtual int getSpeedEffect();
};

#endif