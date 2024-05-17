#ifndef GRASSPOKEMON_H
#define GRASSPOKEMON_H
#include <vector>
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
    void setMoves(); 
};

#endif