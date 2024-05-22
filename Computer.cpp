#include "Computer.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"

#include <ctime>
#include <random>

Computer::Computer(){
    // Seed the randomness (mostly just for testing)
    srand(time(0));

    // Loop 3 times
    for (int i = 0; i < 3; i++){
        // generate a random number from 0 to 2
        int random = rand() % 3;

        // switch case to add the correct type of Pokemon into the party
        switch (random){
        case 0:
            party.push_back(new FirePokemon("Fire"));
            break;
        case 1:
            party.push_back(new WaterPokemon("Water"));
            break;
        case 2:
            party.push_back(new GrassPokemon("Grass"));
            break;
        }
    }
}
