#include "Computer.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"

#include <ctime>
#include <random>

Computer::Computer(){
    srand(time(0));

    for (int i = 0; i < 3; i++){
        int random = rand() % 3;

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
