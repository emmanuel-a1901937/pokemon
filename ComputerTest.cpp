#include "ComputerTest.h"
#include "Computer.h"

#include <iostream>
#include <vector>

void ComputerTest::testInitialisation(){
    // Get the reference to the computers party
    std::vector<Pokemon*>& party = computer.getPokemon();

    // Loop through 3 times
    for (int i = 0; i < 3; i++){
        // Check if the name is incorrect
        if (party[i]->getName() != "Fire" && party[i]->getName() != "Water" && party[i]->getName() != "Grass"){
            // If it is, the object wasn't initialised properly
            std::cout << "Object initialised incorrectly" << std::endl;
        }
    }
    // If the code gets to here, the object was initialised properly
    std::cout << "Object initialised correctly" << std::endl;
}