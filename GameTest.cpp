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
    if (!game.gameOver()){
        std::cout << "Program worked as expected (3)" << std::endl;
    }
    else{
        std::cout << "Program didn't work as expected (3)" << std::endl;
    }

}

void GameTest::testComputerTurn() {
    game.computerTurn(); 
}