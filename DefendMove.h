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
    DefendMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect) {
      name = _name; 
      type = _type; 
      attackEffect = _attackEffect; 
      defenceEffect = _defenceEffect; 
      speedEffect = _speedEffect; 
    }

    void useMove(Pokemon* p1, Pokemon* p2) {
      // Note: p2 is not used since DefendMove is used on itself 

      cout << p1->getName() << " has used Defend Move " << this->name << "!" << endl; // print message to let user know what move was used

      // apply Attack effect
      if (attackEffect != 0) { // if there is a change in Attack stat
        int newAttack = p1->getAttack()  + this->attackEffect; // calculate new Attack stat
        if (newAttack > 0) { // if newAttack is above 0
          p1->setAttack(newAttack); // update Attack stat 
          cout << p1->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p1->getAttack() << endl; // print message 
        }
        else { // if newAttack would be less than 1
          p1->setAttack(1); // set newAttack to 1
          cout << p1->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p1->getAttack() << endl; // print message 
        }
      }

      // apply Defence effect
      if (defenceEffect != 0) {
        int newDefence = p1->getDefence()  + this->defenceEffect; // calculate new Defence stat
        if (newDefence > 0) { // if newDefence falls within valid range 
          p1->setDefence(newDefence); // update Defence stat 
          cout << p1->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p1->getDefence() << endl; // print message 
        }
        else { // if newDefence would be less than 1
          p1->setDefence(1); // set newDefence to 1
          cout << p1->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p1->getDefence() << endl; // print message 
        }
      }

      // apply Speed effect
      if (speedEffect != 0) {
        int newSpeed = p1->getSpeed()  + this->speedEffect; // calculate new Speed stat
        if (newSpeed > 0) { // if newSpeed falls within valid range 
          p1->setSpeed(newSpeed); // update Speed stat 
          cout << p1->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p1->getSpeed() << endl; // print message 
        }
        else { // if newSpeed would be less than 1
          p1->setSpeed(1); // set newSpeed to 1
          cout << p1->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p1->getSpeed() << endl; // print message 
        }
      }
      
    }
};

#endif