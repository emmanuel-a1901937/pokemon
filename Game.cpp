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

    // Display the main menu and its choices (see function for more details)
    displayMainMenu();

    // Take an input of the players choice
    int choice;
    std::cin >> choice;

    switch (choice){
    // Player wants to play the game (just let code run procedurally)
    case 1:
        break;
    // Player wants to load a saved game
    case 2:
        loadGame();
        break;
    // Player wants to exit the program
    case 3:
        return;
        break;
    }

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
    int choice = rand() % 4;

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
    // If all player pokemon have fainted, but computer has some left, you lose
    else if (player.partyFainted() && !computer.partyFainted()){
        std::cout << "You lost, you suck!" << std::endl;
        return true;
    }
    // Otherwise continue game as usual
    return false;
}

// Display all the choices to the player
void Game::displayMainMenu() {
    std::cout << "===================================" << std::endl;
    std::cout << "       Welcome to Pokemon: Knockoff!       " << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "           Main Menu               " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Please enter your choice: ";
}

void Game::displayGameMenu() {
    // Display a header or a title for the game menu
    std::cout << "========================" << std::endl;
    std::cout << "         Your Move!        " << std::endl;
    std::cout << "========================" << std::endl;

    // Display player's Pokemon's name and health
    Pokemon* activePokemon = player.getActivePokemon();
    std::cout << "Your active Pokemon: " << activePokemon->getName() << std::endl;
    std::cout << "Health: " << activePokemon->getHealth() << std::endl;
    std::cout << "Type: " << activePokemon->getType() << std::endl;

    // Display computer's Pokemon's name and health
    Pokemon* computerPokemon = computer.getActivePokemon();
    std::cout << "Opponents Pokemon: " << computerPokemon->getName() << std::endl;
    std::cout << "Health: " << computerPokemon->getHealth() << std::endl;

    // Display the available moves
    std::cout << "\nAvailable Moves:" << std::endl;
    std::vector<Move*>& moves = activePokemon->getMoves();

    // First two are attacking moves
    for (int i = 0; i < 2; i++) {
        std::cout << i + 1 << ". " << moves[i]->getName() << std::endl;
        std::cout << "   Damage: " << moves[i]->getDamage() << " | Accuracy: " << moves[i]->getAccuracy() << std::endl;
    }

    // Third is a defense move
    std::cout << "3. " << moves[2]->getName() << " - Defense move" << std::endl;
    std::cout << "Attack Effect: " << moves[2]->getAttackEffect() << std::endl; 
    std::cout << "Defence Effect: " << moves[2]->getDefenceEffect() << std::endl; 
    std::cout << "Speed Effect: " << moves[2]->getSpeedEffect() << std::endl; 

    // Fourth is a status move
    std::cout << "4. " << moves[3]->getName() << " - Status move" << std::endl;
    std::cout << "Attack Effect: " << moves[3]->getAttackEffect() << std::endl; 
    std::cout << "Defence Effect: " << moves[3]->getDefenceEffect() << std::endl; 
    std::cout << "Speed Effect: " << moves[3]->getSpeedEffect() << std::endl; 

    // Option to save and quit
    std::cout << "5. Save and Quit" << std::endl;

    // Additional styling or prompts
    std::cout << "========================" << std::endl;
    std::cout << "Choose an option (1-5): ";
}