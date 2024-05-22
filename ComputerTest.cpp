#include "ComputerTest.h"
#include "Computer.h"

#include <iostream>
#include <vector>

void ComputerTest::testInitialisation(){
    std::vector<Pokemon*>& party = computer.getPokemon();
    for (int i = 0; i < 3; i++){
        if (party[i]->getName() != "Fire" && party[i]->getName() != "Water" && party[i]->getName() != "Grass"){
            std::cout << "Object initialised incorrectly" << std::endl;
        }
    }
    std::cout << "Object initialised correctly" << std::endl;
}