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
    string getName(); // Returns name attribute 
    string getType(); // Returns type attribute 

    // AttackMove child functions 
    virtual int getDamage(); // Calls function in AttackMove child class, and returns Damage attribute
    virtual int getAccuracy(); // Calls function in AttackMove or StatusMove child class, and returns Accuracy attribute

    // DefendMove and StatusMove child functions
    virtual int getAttackEffect(); // Calls function in DefendMove or StatusMove child class, and returns attackEffect attribute
    virtual int getDefenceEffect(); // Calls function in DefendMove or StatusMove child class, and returns defenceEffect attribute
    virtual int getSpeedEffect(); // Calls function in DefendMove or StatusMove child class, and returns speedEffect attribute
};

#endif