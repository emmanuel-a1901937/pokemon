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
  public: 
    WaterPokemon(string names);
    void setMoves(); 
};

#endif