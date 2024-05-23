#include "TrainerTest.h"

#include <vector>
#include <iostream>
#include <string>

void TrainerTest::testAddPokemon(){
    // Manually input Pokemon 1 name "A", 2 "B" and 3 "C"
    trainer.addPokemon();
    std::vector<Pokemon*>& party = trainer.getPokemon();

    
    for (int i = 0; i < 3; i++){
        if (party[i]->getName() != "A" && party[i]->getName() != "B" && party[i]->getName() != "C")
            std::cout << "Program didn't work as expected (1)" << std::endl;
    }
    std::cout << "Program worked as expected (1)" << std::endl;
}

void TrainerTest::testReplacePokemon(){
    // Remove "C" & add "D"
    trainer.replacePokemon();
    std::vector<Pokemon*>& party = trainer.getPokemon();

    if (party[2]->getName() != "D"){
        std::cout << "Program didn't work as expected (2)" << std::endl;
    }
    std::cout << "Program worked as expected (2)" << std::endl;
}

void TrainerTest::testSetActivePokemon(){
    trainer.setActivePokemon();
    if (trainer.getActivePokemon()->getName() != "A"){
        std::cout << "Program didn't work as expected (3)" << std::endl;
    }
    std::cout << "Program worked as expected (3)" << std::endl;
}

void TrainerTest::testPartyFainted(){
    if (!trainer.partyFainted()){
        std::cout << "Program worked as expected (4)" << std::endl;
    }
    else{
        std::cout << "Program didn't work as expected (4)" << std::endl;
    }
}
