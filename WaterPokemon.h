#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H
#include <vector>
#include "Pokemon.h"
#include "WaterAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"
using namespace std; 

class WaterPokemon : public Pokemon {
  protected:
    vector<WaterAttackMove*> possibleAttacks;
    vector<DefendMove*> possibleDefense;
    vector<StatusMove*> possibleStatus;
    void useAttack(Move* move, Pokemon* targetPokemon);
    void useDefend(Move* move); 
    void useStatus(Move* move, Pokemon* targetPokemon);

  public: 
    WaterPokemon(string names);
    void setMoves(); 
    void useMove(Move* move, Pokemon* targetPokemon);
};

#endif