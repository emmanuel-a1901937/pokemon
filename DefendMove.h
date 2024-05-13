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

      cout << p1->getName() << " has used Defend Move " << this->name << "!" << endl; // print message to let user know what move was used

      int lowerLimit = 30; // stats must fall between 30 and 90 
      int upperLimit = 90; 

      // apply Attack effect
      if (attackEffect != 0) { // if there is a change in Attack stat
        int newAttack = p1->getAttack()  + this->attackEffect; // calculate new Attack stat
        if (newAttack > lowerLimit && newAttack < upperLimit) { // if newAttack falls within valid range 
          p1->setAttack(newAttack); // update Attack stat 
          cout << p1->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p1->getAttack() << endl; // print message 
        }
        else { // newAttack does not fall within valid range 
          cout << p1->getName() << "'s Attack stat cannot be changed at this point in time!" << endl; 
        }
      }

      // apply Defence effect
      if (defenceEffect != 0) {
        int newDefence = p1->getDefence()  + this->defenceEffect; // calculate new Defence stat
        if (newDefence > lowerLimit && newDefence < upperLimit) { // if newDefence falls within valid range 
          p1->setDefence(newDefence); // update Defence stat 
          cout << p1->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p1->getDefence() << endl; // print message 
        }
        else { // newDefence does not fall within valid range 
          cout << p1->getName() << "'s Defence stat cannot be changed at this point in time!" << endl; 
        }
      }

      // apply Speed effect
      if (speedEffect != 0) {
        int newSpeed = p1->getSpeed()  + this->speedEffect; // calculate new Speed stat
        if (newSpeed > lowerLimit && newSpeed < upperLimit) { // if newSpeed falls within valid range 
          p1->setSpeed(newSpeed); // update Speed stat 
          cout << p1->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p1->getSpeed() << endl; // print message 
        }
        else {
          cout << p1->getName() << "'s Speed stat cannot be changed at this point in time!" << endl; 
        }
      }
      
    }
};

#endif