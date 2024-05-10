#ifndef MOVE_H
#define MOVE_H

#include <string>
using namespace std; 

class Move {
  protected: 
    string name; 
    string type; 

  public: 
    virtual void useMove(Pokemon* p1, Pokemon* p2) {

    }
};

#endif