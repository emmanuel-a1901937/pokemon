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
    virtual void f(); 
};

#endif