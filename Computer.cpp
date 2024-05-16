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
            //idk what were doing about names for the computer, maybe allow Computer to hold a list of names 
            //and randomly choose one from that (based on type obviously)
        case 0:
            party.push_back(new FirePokemon);
            break;
        case 1:
            party.push_back(new WaterPokemon);
            break;
        case 2:
            party.push_back(new GrassPokemon);
            break;
        }
    }
}
