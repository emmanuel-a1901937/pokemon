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
        void addPokemon();
        void replacePokemon();
        bool confirmPokemon();
        std::vector<Pokemon*>& getPokemon();
        void setActivePokemon();
        Pokemon* getActivePokemon();
        bool partyFainted();
};



#endif