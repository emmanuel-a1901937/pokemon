#include "Trainer.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
#include <iostream>
#include <limits>
#include <string>

void Trainer::addPokemon(){
    // Loop to add 3 Pokemon into player's party
    for (int i = 0; i < 3; i++){
        // Initialise variables for later in the function
        int choice;
        std::string name;

        // Ask the player what type of Pokemon they want to add to their party
        std::cout << "What type of pokemon do you want? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
        std::cin >> choice;

        // Ensure the player doesn't choose greater than 3 or 0 or less
        while (choice > 3 || choice <= 0){
            std::cout << "Try again, invalid input" << std::endl;
            std::cout << "What type of pokemon do you want? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
            std::cin >> choice;
        }

        // Ask the what they want to call their Pokemon
        std::cout << "What would you like to call your Pokemon?" << std::endl;
        std::cin >> name;


        // Switch case to add the correct type of Pokemon to their party, with their chosen name
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
    // Initialise variables for later in the function
    int size = party.size();
    int choice;

    // Loop to display the pokemon in their party
    for (int i = 0; i < size; i++) {
        std::cout << "Index " << i << std::endl;
        std::cout << party[i]->getName() << std::endl;
    }

    // Ask the player which pokemon they would like to remove from their party
    std::cout << "Which Pokemon would you like to remove?" << std::endl;

    // Take the input of the players choice
    std::cin >> choice;

    // While loop to ensure input of 0 to 2
    while (choice < 0 || choice >= size) {
        std::cout << "Try again, invalid input" << std::endl;
        std::cout << "Which Pokemon would you like to remove?" << std::endl;
        std::cin >> choice;
    }

    // Save name for confirmation later after deletion
    std::string name = party[choice]->getName();

    // Delete the pokemon in the specified index
    delete party[choice];
    party.erase(party.begin() + choice);

    //Confirm the pokemon has been removed from their party
    std::cout << "Removed " << name << std::endl;
    std::cout << "Time to add a new Pokemon" << std::endl;

    // add a new Pokemon (need to fix this as will try to add 3 again)
    std::cout << "What type of pokemon do you want as a replacement? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
    std::cin >> choice;

    // Ensure the player doesn't choose greater than 3 or 0 or less
    while (choice > 3 || choice <= 0){
        std::cout << "Try again, invalid input" << std::endl;
        std::cout << "What type of pokemon do you want? (1 = Fire, 2 = Water, 3 = Grass)" << std::endl;
        std::cin >> choice;
    }

        // Ask the what they want to call their Pokemon
        std::cout << "What would you like to call your Pokemon?" << std::endl;
        std::cin >> name;


        // Switch case to add the correct type of Pokemon to their party, with their chosen name
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

        // confirm to the player that the Pokemon has been added to the party
        std::cout << "Added " << name << " to your party." << std::endl;
} 

//changed to a boolean function
bool Trainer::confirmPokemon() {
    int choice;

    // Ask the player if they are happy with their choice
    std::cout << "Are you happy with your choice? (1 = yes, 2 = no): ";
    std::cin >> choice;
    
    // While loop to ensure that only 1 or 2 can be input
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice, please enter 1 for yes or 2 for no: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin >> choice;
    }

    // Return true if 1, or false if 2
    if (choice == 1) {
        return true;
    } else {
        return false;
    }
}

std::vector<Pokemon*>& Trainer::getPokemon(){
    // return the party variable
    return party;
}

//removed paramater of Pokemon* p1
void Trainer::setActivePokemon(){
    
    // Loop through the party to find the first unfainted pokemon
    for (int i = 0; i < party.size(); i++) {
        if (!party[i]->isFainted()) {
            
            // set the pokemon as the activePokemon
            activePokemon = party[i];
            return; 
        }
    }
    // If all Pokemon fainted, set nullptr (game will be over before this needs to be ran)
    activePokemon = nullptr; 
}

Pokemon* Trainer::getActivePokemon(){
    // returns the Active pokemon
    return activePokemon;
}

//New function, will need to be added to the change log


bool Trainer::partyFainted(){
    
    // Loop through the party to see if there are any unfainted pokemon
    for (int i = 0; i < 3; i++){
        if (!party[i]->isFainted()){
            // if a pokemon hasn't fainted return false
            return false;
        } 
    }
    // If all have fainted return true
    return true;
}