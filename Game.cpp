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
    // Displays the move choices for the player
    displayGameMenu();

    // Ask the player to make a choice
    int choice;
    std::cin >> choice;

    // Need to do error handling

    // Switch case to activate correct move
    switch (choice){
        Pokemon* playerPokemon = player.getActivePokemon(); 
        Pokemon* computerPokemon = computer.getActivePokemon(); 
        case 1:
            // use the move at index 0 (attack1)
            Move* a1 = playerPokemon->getMoves()[0];
            playerPokemon->useAttack(a1, computerPokemon);
            break;
        case 2:
            //use the move at index 1 (attack2)
            player.getActivePokemon()->getMoves()[1]->useMove(player.getActivePokemon(), computer.getActivePokemon());
            break;
        case 3:
            //use the move at index 2 (defend)
            player.getActivePokemon()->getMoves()[2]->useMove(player.getActivePokemon(), computer.getActivePokemon());
            break;
        case 4:
            //use the move at index 3 (status)
            player.getActivePokemon()->getMoves()[3]->useMove(player.getActivePokemon(), computer.getActivePokemon());
            break;
        case 5:
            //save the game (how tf do i make this quit, do I need to?)
            saveGame();
            break;
    }

    //Computer pokemon has been attacked, if fainted, set next pokemon in party as active Pokemon
    computer.setActivePokemon();
}

void Game::computerTurn(){
    // Seed the randomness based on the current time
    srand(time(0));

    // Randomly choose an integer from 1 to 4 (inclusive)
    int choice = rand() % 4;

    // Based on the choice, the attack is randomly chosen
    switch (choice){
        case 0:
            //use attack at index 0
            computer.getActivePokemon()->getMoves()[0]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 1:
            //use attack at index 1
            computer.getActivePokemon()->getMoves()[1]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 2:
            //use attack at index 2
            computer.getActivePokemon()->getMoves()[2]->useMove(computer.getActivePokemon(), player.getActivePokemon());
        case 3:
            //use attack at index 3
            computer.getActivePokemon()->getMoves()[3]->useMove(computer.getActivePokemon(), player.getActivePokemon());
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