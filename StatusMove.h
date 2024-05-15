#ifndef STATUSMOVE_H
#define STATUSMOVE_H

#include "Move.h"
using namespace std; 

class StatusMove : public Move {
  protected: 
    int attackEffect; 
    int defenceEffect; 
    int speedEffect; 
    int accuracy; 

  public: 
    void useMove(Pokemon* p1, Pokemon* p2) {
      cout << p1->getName() << " has used Status Move " << this->name << "!" << endl; // print message to let user know what move was used

      // determine if status move hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99

      if (randomNumber < accuracy) { // status move hits if randomNumber falls below the accuracy attribute 

        // apply Attack effect
        if (attackEffect != 0) { // if there is a change in Attack stat
          int newAttack = p2->getAttack()  + this->attackEffect; // calculate new Attack stat
          if (newAttack > 0) { // ensure newAttack is above 0
            p2->setAttack(newAttack); // update Attack stat 
            cout << p2->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p2->getAttack() << endl; // print message 
          }
          else { // if newAttack would be less than 1
            p2->setAttack(1); // set newAttack to 1
            cout << p2->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p2->getAttack() << endl; // print message 
          }
        }

        // apply Defence effect
        if (defenceEffect != 0) {
          int newDefence = p2->getDefence()  + this->defenceEffect; // calculate new Defence stat
          if (newDefence > 0) { // if newDefence is above 0
            p2->setDefence(newDefence); // update Defence stat 
            cout << p2->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p2->getDefence() << endl; // print message 
          }
          else { // if newDefence would be less than 1
            p2->setDefence(1); // set newDefence to 1
            cout << p2->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p2->getDefence() << endl; // print message 
          }
        }

        // apply Speed effect
        if (speedEffect != 0) {
          int newSpeed = p2->getSpeed()  + this->speedEffect; // calculate new Speed stat
          if (newSpeed > 0) { // if newSpeed is above 0
            p2->setSpeed(newSpeed); // update Speed stat 
            cout << p2->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p2->getSpeed() << endl; // print message 
          }
          else { // if newSpeed would be less than 1
            p2->setSpeed(1); // set newSpeed to 1
            cout << p2->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p2->getSpeed() << endl; // print message 
          }
        }
      }

      else { // if Status move did not hit 
        cout << p1->getName() << "'s Status Move was ineffective!" << endl; 
      }
    }
};

#endif