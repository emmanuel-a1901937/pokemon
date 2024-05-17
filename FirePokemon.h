#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H
#include <vector>
#include "Pokemon.h"
#include "FireAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"
#include <string>
using namespace std; 

class FirePokemon : public Pokemon {
  protected: 
  vector<FireAttackMove*> possibleAttacks;
  vector<DefendMove*> possibleDefense;
  vector<StatusMove*> possibleStatus;

  public:
    FirePokemon(string names);
    void setMoves(FireAttackMove* F1, FireAttackMove* F2, DefendMove* D1, StatusMove* S1) {
      
    }
};

#endif