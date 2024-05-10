#ifndef POKEMON_H
#define POKEMON_H

#include "Move.h"

#include <string>
#include <vector>

class Pokemon{
    protected:
        std::string name;
        std::vector<Move*> moves;
        int currentHealth;
        int maxHealth;
        int attack;
        int defence;
        int speed;
        std::string type;
        bool fainted;
    public:
        std::vector<Move*>& getMoves();
        std::string getName();
        int getHealth();
        void takeDamage(int damage);
        int getAttack(); 
        void setAttack(int newAttack);
        int getDefence(); 
        void setDefence(int newDefence); 
        int getSpeed(); 
        void setSpeed(int newSpeed); 
        std::string getType(); 
        bool isFainted(); 
};




#endif