#ifndef WATERATTACKMOVE_H
#define WATERATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class WaterAttackMove : public AttackMove {
  public: 
    void useMove(Pokemon* p1, Pokemon* p2) {
      // determine if attack hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99

      if (randomNumber < this->accuracy) { // attack hits if randomNumber falls below the accuracy attribute 
        float bonus = 1; 

        if (p2->getType() == "Fire") {
          bonus = 1.5; // super effective bonus applied if WaterAttackMove used against FirePokemon
        }

        // calculate damage dealt 
        float attackPower = this->damage; 
        float p1AttackStat = p1->getAttack(); 
        float p2DefenceStat = p2->getDefence(); 
        float totalDamage = (attackPower * (p1AttackStat/p2DefenceStat)) * bonus; 


        p2->takeDamage(totalDamage); // reduce p2 health 
        cout << p1->getName() << " successfully dealt " << totalDamage <<  " damage to " << p2->getName() << endl; // print successful attack message 
      } 
      
      else { // no damage is dealt otherwise 
        cout << p1->getName() << " did not deal any damage to " << p2->getName() << endl; // print failed attack message
      }    
    }
};

#endif