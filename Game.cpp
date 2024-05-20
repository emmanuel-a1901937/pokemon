#include "Game.h"
#include "Pokemon.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function to run the game loop
void Game::run(){

    //Need to include the main menu and its choices here

    // Allow the player to choose their pokemon (see function for more details)
    initialise();

    // Main game loop, runs until one party has no more un-fainted pokemon
    while (!player.partyFainted() && !computer.partyFainted()) {

        // If the player's pokemon's speed is greater or same as the computer's, player goes first
        if (player.getActivePokemon()->getSpeed() >= computer.getActivePokemon()->getSpeed()) {
            playerTurn();
            if (gameOver()) break; // Check after every turn to see if every pokemon has fainted

            computerTurn();
            if (gameOver()) break;
            } 
            
            // If computer's pokemon is faster, computer goes first
            else {
            computerTurn();
            if (gameOver()) break;

            playerTurn();
            if (gameOver()) break;
        }
    }
}

// Function to allow the player to choose their pokemon
void Game::initialise(){
    // Player chooses 3 pokemon
    player.addPokemon();

    //While loop runs while player is unhappy with their pokemon
    while (!player.confirmPokemon()){
        // Allows player to choose pokemon to remove & add another
        player.replacePokemon();
    }

    // Set the Pokemon at lowest index (which hasn't fainted) as active Pokemon
    player.setActivePokemon();
    computer.setActivePokemon();
}

void Game::playerTurn(){
    // get player's and computer's active pokemon 
    Pokemon* playerPokemon = player.getActivePokemon(); 
    Pokemon* computerPokemon = computer.getActivePokemon(); 

    // Displays the move choices for the player
    displayGameMenu();

    // Ask the player to make a choice
    int choice;
    std::cin >> choice;

    // Need to do error handling

    // Switch case to activate correct move
    switch (choice){
        case 1: 
        {
            // use the move at index 0 (attack1)
            Move* a1 = playerPokemon->getMoves()[0];
            playerPokemon->useMove(a1, computerPokemon);
            break;
        }
        case 2:
        {
            //use the move at index 1 (attack2)
            Move* a2 = playerPokemon->getMoves()[1];
            playerPokemon->useMove(a2, computerPokemon);
            break;
        }
        case 3:
        {
            //use the move at index 2 (defend)
            Move* d1 = playerPokemon->getMoves()[2];
            playerPokemon->useMove(d1, computerPokemon);
            break;
        }
        case 4:
        {
            //use the move at index 3 (status)
            Move* s1 = playerPokemon->getMoves()[3];
            playerPokemon->useMove(s1, computerPokemon);
            break;
        }
        case 5:
            //save the game (how tf do i make this quit, do I need to?)
            saveGame();
            break;
    }

    //Computer pokemon has been attacked, if fainted, set next pokemon in party as active Pokemon
    computer.setActivePokemon();
}

void Game::computerTurn(){
    // get player's and computer's active pokemon 
    Pokemon* playerPokemon = player.getActivePokemon(); 
    Pokemon* computerPokemon = computer.getActivePokemon(); 

    // Seed the randomness based on the current time
    srand(time(0));

    // Randomly choose an integer from 0 to 3 (inclusive)
    int choice = rand() % 3;

    // Based on the choice, the attack is randomly chosen
    switch (choice){
        case 0: 
        {
            // use the move at index 0 (attack1)
            Move* a1 = computerPokemon->getMoves()[0];
            computerPokemon->useMove(a1, playerPokemon);
            break;
        }
        case 1:
        {
            //use the move at index 1 (attack2)
            Move* a2 =  computerPokemon->getMoves()[1];
            computerPokemon->useMove(a2, playerPokemon);
            break;
        }
        case 2:
        {
            //use the move at index 2 (defend)
            Move* d1 = computerPokemon->getMoves()[2];
            computerPokemon->useMove(d1, playerPokemon);
            break;
        }
        case 3:
        {
            //use the move at index 3 (status)
            Move* s1 = computerPokemon->getMoves()[3];
            computerPokemon->useMove(s1, playerPokemon);
            break;
        }
    }

    //Player pokemon has been attacked, if fainted, set next pokemon in party as active Pokemon
    player.setActivePokemon();
}   

void Game::saveGame(){}

Game Game::loadGame(){}

bool Game::gameOver(){
    // If all computer pokemon fainted, but player has some left, you win
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
    // show opposing pokemon name & health & maybe type
    std::cout << player.getActivePokemon()->getName() << "'s health is: " << player.getActivePokemon()->getHealth() << std::endl;
    // Need to write functions for getting the name, damage & accuracy of the move
    std::cout << "1. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "2. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "3. Use " << player.getActivePokemon()->getMoves()[0] << std::endl;
    std::cout << "4. Use " << player.getActivePokemon()->getMoves()[0] <<std::endl;
    std::cout << "5. Save and Quit" << std::endl;
}