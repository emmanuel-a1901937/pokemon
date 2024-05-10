#include "Game.h"

#include <iostream>

void run();

void initialise();

void newRound();

void playerTurn();

void computerTurn();

void saveGame();

static Game loadGame();

bool gameOver();

void Game::displayMainMenu(){
    std::cout << "Welcome to Pokemon: Knockoff!" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
}

void Game::displayGameMenu(){
    std::cout << "Your move!" << std::endl;
    std::cout << "1. Use " << player.getAcivePokemon().getMoves()[0].getName() << std::endl;
    std::cout << "2. Use " <<  <<std::endl;
    std::cout << "3. Use " <<  <<std::endl;
    std::cout << "4. Use " <<  <<std::endl;
    std::cout << "5. Save and Quit" << std::endl;
}