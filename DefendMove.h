#ifndef DEFENDMOVE_H
#define DEFENDMOVE_H

#include "Move.h"
using namespace std; 

class DefendMove : public Move {
  protected: 
    int attackEffect; 
    int defenceEffect; 
    int speedEffect; 
};

#endif