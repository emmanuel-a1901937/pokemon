#include "Trainer.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
#include <iostream>
#include <limits>
#include <string>

void Trainer::addPokemon(){
    for (int i = 0; i < 3; i++){
        int choice;
        std::string name;
        std::cout << "What type of pokemon do you want? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
        std::cin >> choice;

        while (choice > 3 || choice <= 0){
            std::cout << "Try again, invalid input" << std::endl;
            std::cout << "What type of pokemon do you want? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
            std::cin >> choice;
        }

        std::cout << "What would you like to call your Pokemon?" << std::endl;
        std::cin >> name;

        switch (choice){
        case 1:
            party.push_back(new FirePokemon(name));
            break;
        case 2:
            party.push_back(new WaterPokemon(name));
            break;
        case 3:
            party.push_back(new GrassPokemon(name));
            break;
        }
    }
}

void Trainer::replacePokemon() {
    int size = party.size();
    int choice;
    std::cout << "Which Pokemon would you like to remove?" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Index " << i << std::endl;
        std::cout << party[i]->getName() << std::endl;
    }
    std::cin >> choice;

    while (choice < 0 || choice >= size) {
        std::cout << "Try again, invalid input" << std::endl;
        std::cout << "Which Pokemon would you like to remove?" << std::endl;
        std::cin >> choice;
    }

    std::string name = party[choice]->getName();
    delete party[choice];
    party.erase(party.begin() + choice);
    std::cout << "Removed " << name << std::endl;
    std::cout << "Time to add a new Pokemon" << std::endl;
    addPokemon();
}

//changed to a boolean function
bool Trainer::confirmPokemon() {
    int choice;
    std::cout << "Are you happy with your choice? (1 = yes, 2 = no): ";
    std::cin >> choice;
    
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice, please enter 1 for yes or 2 for no: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin >> choice;
    }

    if (choice == 1) {
        return true;
    } else {
        return false;
    }
}

std::vector<Pokemon*>& Trainer::getPokemon(){
    return party;
}

//removed paramater of Pokemon* p1
void Trainer::setActivePokemon(){
        for (int i = 0; i < party.size(); i++) {
        if (!party[i]->isFainted()) {
            activePokemon = party[i];
            return; 
        }
    }
    // If all Pokemon fainted, set nullptr or maybe will end the game before this is called again
    activePokemon = nullptr; 
}

Pokemon* Trainer::getActivePokemon(){
    return activePokemon;
}

//New function, will need to be added to the change log


bool Trainer::partyFainted(){
    for (int i = 0; i < 3; i++){
        if (!party[i]->isFainted()){
            return false;
        } 
    }
    return true;
}