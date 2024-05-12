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
      // determine if status move hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99

      if (randomNumber < accuracy) { // status move hits if randomNumber falls below the accuracy attribute 
        // apply new attributes to p1 
        int newAttack = p2->getAttack()  + this->attackEffect; // calculate new attributes 
        int newDefence = p2->getDefence() + this->defenceEffect; 
        int newSpeed = p2->getSpeed() + this->speedEffect; 

        // TODO: check if new attributes would be out of range 


        p2->setAttack(newAttack); // set new attributes
        p2->setDefence(newDefence);
        p2->setSpeed(newSpeed); 

        // print new stats 
        if (attackEffect != 0) { // only print messages if the stat has been affected by the StatusMove
          cout << p2->getName() << "'s Attack has been affected by " << attackEffect << ". New Attack stat is " << p2->getAttack() << endl; 
        }
        if (defenceEffect != 0) { // only print messages if the stat has been affected by the StatusMove
          cout << p2->getName() << "'s Defence has been affected by " << defenceEffect << ". New Defence stat is " << p2->getDefence() << endl; 
        }
        if (speedEffect != 0) { // only print messages if the stat has been affected by the StatusMove
          cout << p2->getName() << "'s Speed has been affected by " << speedEffect << ". New Speed stat is " << p2->getSpeed() << endl; 
        }
      }

      else { // if Status move did not hit 
        cout << p1->getName() << "'s Status Move was ineffective!" << endl; 
      }
    }
};

#endif