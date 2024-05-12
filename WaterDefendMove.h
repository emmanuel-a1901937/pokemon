#ifndef WATERDEFENDMOVE_H
#define WATERDEFENDMOVE_H

#include "DefendMove.h"
using namespace std; 

class WaterDefendMove : public DefendMove {
  private: 
    void useMove(Pokemon* p1, Pokemon* p2) {
      // Note: p2 is not used since DefendMove is used on itself 

      // apply new attributes to p1 
      int newAttack = p1->getAttack()  + this->attackEffect; // calculate new attributes 
      int newDefence = p1->getDefence() + this->defenceEffect; 
      int newSpeed = p1->getSpeed() + this->speedEffect; 

      p1->setAttack(newAttack); // set new attributes
      p1->setDefence(newDefence);
      p1->setSpeed(newSpeed); 
    }
};

#endif