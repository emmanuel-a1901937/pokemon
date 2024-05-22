#ifndef TRAINER_H
#define TRAINER_H

#include "Pokemon.h"
#include <vector>

class Trainer{
    protected:
        std::vector<Pokemon*> party;
        Pokemon* activePokemon;
        int pokemonRemaining;
    public:
        // Adds 3 pokemon to the party
        void addPokemon();
        // Removes 1 pokemon & replaces it
        void replacePokemon();
        // To confirm that the player is happy with their pokemon
        bool confirmPokemon();
        // Return a reference to the party vector, so it can be accessed
        std::vector<Pokemon*>& getPokemon();
        // Set active pokemon as lowest index pokemon that hasn't fainted
        void setActivePokemon();
        // return a pointer to the active pokemon so it can be accessed
        Pokemon* getActivePokemon();
        // check if every pokemon in the party has fainted
        bool partyFainted();
};



#endif