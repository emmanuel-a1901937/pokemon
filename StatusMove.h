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

        int lowerLimit = 30; // stats must fall between 30 and 90 
        int upperLimit = 90; 

        // apply Attack effect
        if (attackEffect != 0) { // if there is a change in Attack stat
          int newAttack = p2->getAttack()  + this->attackEffect; // calculate new Attack stat
          if (newAttack > lowerLimit && newAttack < upperLimit) { // if newAttack falls within valid range 
            p2->setAttack(newAttack); // update Attack stat 
            cout << p2->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p2->getAttack() << endl; // print message 
          }
          else { // newAttack does not fall within valid range 
            cout << p2->getName() << "'s Attack stat cannot be changed at this point in time!" << endl; 
          }
        }

        // apply Defence effect
        if (defenceEffect != 0) {
          int newDefence = p2->getDefence()  + this->defenceEffect; // calculate new Defence stat
          if (newDefence > lowerLimit && newDefence < upperLimit) { // if newDefence falls within valid range 
            p2->setDefence(newDefence); // update Defence stat 
            cout << p2->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p2->getDefence() << endl; // print message 
          }
          else { // newDefence does not fall within valid range 
            cout << p2->getName() << "'s Defence stat cannot be changed at this point in time!" << endl; 
          }
        }

        // apply Speed effect
        if (speedEffect != 0) {
          int newSpeed = p2->getSpeed()  + this->speedEffect; // calculate new Speed stat
          if (newSpeed > lowerLimit && newSpeed < upperLimit) { // if newSpeed falls within valid range 
            p2->setSpeed(newSpeed); // update Speed stat 
            cout << p2->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p2->getSpeed() << endl; // print message 
          }
          else { // newSpeed does not fall within valid range 
            cout << p2->getName() << "'s Speed stat cannot be changed at this point in time!" << endl; 
          }
        }
      }

      else { // if Status move did not hit 
        cout << p1->getName() << "'s Status Move was ineffective!" << endl; 
      }
    }
};

#endif