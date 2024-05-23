#include "GameTest.h"

int main(){
    // Initialise an object of Game
    GameTest test;

    // Call the functions defined in the GameTest class
    test.testInitialise();
    test.testGameOver();
    test.testPlayerTurn();
    test.testComputerTurn(); 
}