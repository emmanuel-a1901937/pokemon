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
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Invalid choice, please enter 1 for new game, or 2 to quit: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    switch (choice){
    // Player wants to play the game (just let code run procedurally)
    case 1:
        break;
    // Player wants to exit the program
    case 2:
        return;
        break;
    }

    // Allow the player to choose their pokemon (see function for more details)
    initialise();

    int round = 1;

    // Main game loop, runs until one party has no more un-fainted pokemon
    while (!player.partyFainted() && !computer.partyFainted()) {

        std::cout << "\n" << "Round " << round << "\n" << std::endl;

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
        round++;
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
    while (!(std::cin >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
        std::cout << "Invalid choice, please enter 1 for Fire, 2 for Water, or 3 for Grass: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

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
    }

    //Computer pokemon has been attacked, if fainted, set next pokemon in party as active Pokemon
    computer.setActivePokemon();
}

void Game::computerTurn(){
    // get player's and computer's active pokemon 
    Pokemon* playerPokemon = player.getActivePokemon(); 
    Pokemon* computerPokemon = computer.getActivePokemon(); 

    std::cout << "========================" << std::endl;
    std::cout << "      Computer Move!    " << std::endl;
    std::cout << "========================" << std::endl;

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

    std::cout << "========================" << std::endl;

    //Player pokemon has been attacked, if fainted, set next pokemon in party as active Pokemon
    player.setActivePokemon();
}   

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
    std::cout << "2. Quit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Please enter your choice: ";
}

void Game::displayGameMenu() {
    // Display a header or a title for the game menu
    std::cout << "========================" << std::endl;
    std::cout << "        Your Move!      " << std::endl;
    std::cout << "========================" << std::endl;

    // Display player's Pokemon's name and health
    Pokemon* activePokemon = player.getActivePokemon();
    std::cout << "Your active Pokemon: " << activePokemon->getName() << std::endl;
    std::cout << "Health: " << activePokemon->getHealth() << std::endl;
    std::cout << "Type: " << activePokemon->getType() << std::endl;
    std::cout << "\n";

    // Display computer's Pokemon's name and health
    Pokemon* computerPokemon = computer.getActivePokemon();
    std::cout << "Opponents Pokemon: " << computerPokemon->getName() << std::endl;
    std::cout << "Health: " << computerPokemon->getHealth() << std::endl;

    // Display the available moves
    std::cout << "\nAvailable Moves:" << std::endl;
    std::vector<Move*>& moves = activePokemon->getMoves();

    // First two are attacking moves
    for (int i = 0; i < 2; i++) {
        std::cout << "\n";
        std::cout << i + 1 << ". " << moves[i]->getName() << std::endl;
        std::cout << "   Attack Rating: " << moves[i]->getDamage() << " | Accuracy: " << moves[i]->getAccuracy() << std::endl;
    }

    // Third is a defense move
    std::cout << "\n";
    std::cout << "3. " << moves[2]->getName() << " - Defense move" << std::endl;
    std::cout << "   Attack Effect: " << moves[2]->getAttackEffect() << " "; 
    std::cout << "Defence Effect: " << moves[2]->getDefenceEffect() << " "; 
    std::cout << "Speed Effect: " << moves[2]->getSpeedEffect() << std::endl; 

    // Fourth is a status move
    std::cout << "\n";
    std::cout << "4. " << moves[3]->getName() << " - Status move" << std::endl;
    std::cout << "   Attack Effect: " << moves[3]->getAttackEffect() << " ";
    std::cout << "Defence Effect: " << moves[3]->getDefenceEffect() << " ";
    std::cout << "Speed Effect: " << moves[3]->getSpeedEffect() << std::endl; 
    std::cout << "\n";

    // Additional styling or prompts
    std::cout << "========================" << std::endl;
    std::cout << "Choose an option (1-4): ";
}

// Return computer for access outside class (only for testing)
Computer Game::getComputer(){ return computer;}

// Return trainer for access outside class (only for testing)
Trainer Game::getTrainer(){ return player;}