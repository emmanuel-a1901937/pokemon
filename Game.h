#ifndef GAME_H
#define GAME_H

#include "Trainer.h"
#include "Computer.h"

class Game{
    protected:
        Trainer player;
        Computer computer;
    public:
        void run();
        void initialise();
        void playerTurn();
        void computerTurn();
        bool gameOver();
        void displayMainMenu();
        void displayGameMenu();
        Trainer getTrainer();
        Computer getComputer();
};

#endif