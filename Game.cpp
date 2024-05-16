#include "Game.h"
#include "Pokemon.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void Game::run(){
    initialise();
    while(!player.partyFainted() && !computer.partyFainted()){
        newRound();
        if (gameOver()){ // might not be in the right spot (should check after every attack)
            break;
        }
    }
}

void Game::initialise(){
    player.addPokemon();
    while (!player.confirmPokemon()){
        player.replacePokemon();
    }
}

void Game::newRound(){
    srand(time (0)); // Should only need to do this once for entire game, but necessary for testing
    if(player.getActivePokemon()->getSpeed() > computer.getActivePokemon()->getSpeed()){
            playerTurn();
            computerTurn();
        }
        else if (player.getActivePokemon()->getSpeed() < computer.getActivePokemon()->getSpeed()){
            computerTurn();
            playerTurn();
        }
        else {
            int random = rand();
            if (random == 1){
                playerTurn();
                computerTurn();
            }
            else {
                computerTurn();
                playerTurn();
            }
        }
}

void Game::playerTurn(){
    int choice;
    displayGameMenu();
    std::cin >> choice;
    // Need to do error handling
    switch (choice){
        case 1:
            player.getActivePokemon()->getMoves()[0]->useMove(player.getActivePokemon(), computer.getActivePokemon());
        case 2:
            player.getActivePokemon()->getMoves()[1]->useMove(player.getActivePokemon(), computer.getActivePokemon());
        case 3:
            player.getActivePokemon()->getMoves()[2]->useMove(player.getActivePokemon(), computer.getActivePokemon());
        case 4:
            player.getActivePokemon()->getMoves()[3]->useMove(player.getActivePokemon(), computer.getActivePokemon());
        case 5:
            saveGame();
    }
    computer.setActivePokemon();
}

void Game::computerTurn(){
    srand(time(0));
    int choice = rand() % 4;
    switch (choice){
        case 0:
            computer.getActivePokemon()->getMoves()[0]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 1:
            computer.getActivePokemon()->getMoves()[1]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 2:
            computer.getActivePokemon()->getMoves()[2]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 3:
            computer.getActivePokemon()->getMoves()[3]->useMove(computer.getActivePokemon(), player.getActivePokemon());
    }
    player.setActivePokemon();
}   

void Game::saveGame(){}

Game Game::loadGame(){}

bool Game::gameOver(){
    if(!player.partyFainted() && computer.partyFainted()){
            std::cout << "You win!!" << std::endl;
            return true;
        }
        else if (player.partyFainted() && !computer.partyFainted()){
            std::cout << "You lost, you suck!" << std::endl;
            return true;
        }
    return false;
}

void Game::displayMainMenu(){
    std::cout << "Welcome to Pokemon: Knockoff!" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
}

void Game::displayGameMenu(){
    std::cout << "Your move!" << std::endl;
    std::cout << player.getActivePokemon()->getName() << "'s health is: " << player.getActivePokemon()->getHealth() << std::endl;
    // Need to write functions for getting the name, damage & accuracy of the move
    std::cout << "1. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "2. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "3. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "4. Use " << player.getActivePokemon()->getMoves()[0] <<std::endl;
    std::cout << "5. Save and Quit" << std::endl;
}