#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Computer.h"

class Game{
    protected:
        Player player;
        Computer computer;
        int phase;
    public:
        void run();
        void initialise();
        void newRound();
        void playerTurn();
        void computerTurn();
        void saveGame();
        static Game loadGame();
        bool gameOver();
        void displayMainMenu();
        void displayGameMenu();
};

#endif