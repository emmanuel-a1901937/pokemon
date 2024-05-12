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