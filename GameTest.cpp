#include "GameTest.h"

#include <string>
#include <iostream>

void GameTest::testInitialise(){
    game.initialise();
    if(game.getTrainer().getActivePokemon()->getName() != "A"){ // When testing, first Pokemon's name was set to "A"
        std::cout << "Program didn't work as expected (1)" << std::endl;
    }
    else {
        std::cout << "Program worked as expected (1)" << std::endl;
    }
}

void GameTest::testPlayerTurn(){
    // Just have to make sure it does what its supposed to (testing specifics not possible)
    game.playerTurn();
}

void GameTest::testGameOver(){
    // When testing, will have no fainted Pokemon, so if returns false, program worked as expected
    if (!game.gameOver()){
        std::cout << "Program worked as expected (3)" << std::endl;
    }
    // If returns true, didn't work properly
    else{
        std::cout << "Program didn't work as expected (3)" << std::endl;
    }

}

void GameTest::testComputerTurn() {
    game.computerTurn(); //Run the computerTurn function for testing
}