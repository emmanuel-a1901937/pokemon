#ifndef POKEMON_H
#define POKEMON_H

#include "Move.h"
#include <random>
#include <string>
#include <vector>

class Pokemon{
    protected:
        std::string name;
        std::vector<Move*> moves; // in the order of Attack, Attack, Defence, Status
        int currentHealth;
        int maxHealth;
        int attack;
        int defence;
        int speed;
        std::string type;
        bool fainted;
    public:
        std::vector<Move*>& getMoves(); // Returns a vector of the Pokemon's Moves
        std::string getName(); // Returns the Pokemon's name 
        int getHealth(); // Returns the Pokemon's Health attribute 
        void takeDamage(int damage); // Function to handle Pokemon's Health getting reduced due to damage taken 
        int getAttack(); // Returns the Attack attribute 
        void setAttack(int newAttack); // Sets the Attack attribute 
        int getDefence(); // Returns the Defence attribute 
        void setDefence(int newDefence); // Sets the Defence attribute 
        int getSpeed(); // Returns the Speed attribute 
        void setSpeed(int newSpeed); // Sets the Speed attribute 
        std::string getType(); // Returns the Type attribute 
        bool isFainted(); // Checks and returns if the Pokemon is fainted 
        virtual void useMove(Move* move, Pokemon* targetPokemon) = 0; // Uses one of the Pokemon's Moves. Virtual function takes into account each Pokemon child class will behave differently depending on its Pokemon type
        virtual ~Pokemon(); // Virtual destructor to deallocate memory set for Vectors of pointer variables 
};




#endif