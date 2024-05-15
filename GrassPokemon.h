#ifndef GRASSPOKEMON_H
#define GRASSPOKEMON_H
#include <Vector>
#include "Pokemon.h"
#include "GrassAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"
using namespace std; 

class GrassPokemon : public Pokemon {
protected:
    vector<GrassAttackMove*> possibleAttacks;
    vector<DefendMove*> possibleDefense;
    vector<StatusMove*> possibleStatus;
public: 
    GrassPokemon(string names);
    void setMoves(GrassAttackMove* G1, GrassAttackMove* G2, DefendMove* D1, StatusMove* S1) {
      
    }
};

#endif