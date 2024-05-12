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

      // print new attributes  
      if (attackEffect != 0) { // only print messages if the stat has been affected by the StatusMove
        cout << p1->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p1->getAttack() << endl; 
      }
      if (defenceEffect != 0) { // only print messages if the stat has been affected by the StatusMove
        cout << p1->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p1->getDefence() << endl; 
      }
      if (speedEffect != 0) { // only print messages if the stat has been affected by the StatusMove
        cout << p1->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p1->getSpeed() << endl; 
      }
    }
};

#endif