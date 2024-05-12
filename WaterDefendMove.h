#ifndef WATERDEFENDMOVE_H
#define WATERDEFENDMOVE_H

#include "DefendMove.h"
using namespace std; 

class WaterDefendMove : public DefendMove {
  private: 
    void useMove(Pokemon* p1, Pokemon* p2) {
      // p2 is not necessary since DefendMove is used on itself 
    }
};

#endif