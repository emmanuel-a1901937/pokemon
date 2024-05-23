#ifndef GAME_H
#define GAME_H

#include "Trainer.h"
#include "Computer.h"

class Game{
    protected:
        Trainer player;
        Computer computer;
    public:
        void run(); // Function to run the game loop
        void initialise(); // Function to allow the player to choose their pokemon
        void playerTurn(); // Takes user input to determine what Move to play during the player's turn 
        void computerTurn(); // Randomly selects what Move to play during computer's turn 
        bool gameOver(); // Checks if either Trainer has all Pokemon fainted (if yes, game ends)
        void displayMainMenu(); // Displays player's choices to either 1. Start a new game, 2. Load from saved game, or 3. Quit game 
        void displayGameMenu(); // Displays both Trainers' Pokemon statuses and Player's available moves 
        Trainer getTrainer(); // Returns the Player's Trainer object 
        Computer getComputer(); // Returns the Computer's Trainer object 
};

#endif