#ifndef WATERATTACKMOVE_H
#define WATERATTACKMOVE_H

#include "AttackMove.h"
using namespace std; 

class WaterAttackMove : public AttackMove {
  private: 
    void useMove(Pokemon* p1, Pokemon* p2) {
      float bonus = 1; 

      // determine if attack hits (based on accuracy)
      

      if (p2->getType() == "Fire") {
        bonus = 1.5; // super effective bonus applied if WaterAttackMove used against FirePokemon
      }

      // calculate damage dealt 
      float attackPower = this->damage; 
      float p1AttackStat = p1->getAttack(); 
      float p2DefenceStat = p2->getDefence(); 
      float totalDamage = (attackPower * (p1AttackStat/p2DefenceStat)) * bonus; 


      // reduce p2 health 
      p2->takeDamage(totalDamage); 
    }
};

#endif