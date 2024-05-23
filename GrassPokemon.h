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
    vector<GrassAttackMove*> possibleAttacks; // Contains all Possible Grass Attack Moves
    vector<DefendMove*> possibleDefense; // Contains all Possible Defence Moves
    vector<StatusMove*> possibleStatus;  // Contains all Possible Status Moves
    void useAttack(Move* move, Pokemon* targetPokemon); // Uses an Attacking move on a pokemon.
    void useDefend(Move* move); // Uses a Defence Move on itself.
    void useStatus(Move* move, Pokemon* targetPokemon); // Uses a status move on opposing pokemon

public: 
    GrassPokemon(string names);
    void setMoves(); // Sets the pokemons moves from a the vector of available moves
    void useMove(Move* move, Pokemon* targetPokemon); // Uses a move from a pokemons list of assigned moves on a specific pokemon.
    ~GrassPokemon(); 
};

#endif