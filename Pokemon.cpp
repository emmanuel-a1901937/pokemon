#include <vector>
#include "Pokemon.h"
#include <iostream>
#include <string>
using namespace std;

vector<Move*>& Pokemon::getMoves() {
    return moves;
}

string Pokemon::getName() {
    return name;
}

 int Pokemon::getHealth(){
    return currentHealth;
 }

void Pokemon::takeDamage(int damage){
    currentHealth = currentHealth - damage;
    if (currentHealth <= 0) {
        currentHealth = 0;
        fainted = true;
    }
}

int Pokemon::getAttack() {
    return attack;
}
       
void Pokemon::setAttack(int newAttack) {
    attack = newAttack;
}

int Pokemon::getDefence() {
    return defence;
}

void Pokemon::setDefence(int newDefence) {
    defence = newDefence;
}

int Pokemon::getSpeed() {
    return speed;
}

void Pokemon::setSpeed(int newSpeed) {
    speed = newSpeed;
}

string Pokemon::getType() {
    return type;
}
 
bool Pokemon::isFainted() {
    return fainted;
}