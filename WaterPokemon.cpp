#include <Vector>
#include "WaterPokemon.h"
#include <iostream>

WaterPokemon::WaterPokemon(string names) {
    name = names;
    type = "Water";
    maxHealth = rand() % 100 + 100; //These are just random values as placeholders, feel free to change
    currentHealth = maxHealth;
    attack = rand() % 90 + 70;
    defence = rand() % 90 + 70;
    speed = rand() % 90 + 70;
    fainted = false;

}

void WaterPokemon::setMoves(WaterAttackMove* W1, WaterAttackMove* W2, DefendMove* D1, StatusMove* S1) {
    vector<WaterAttackMove*> WA(2);
    WA.push_back(W1);
    WA.push_back(W2);
    possibleAttacks = WA;
    vector<DefendMove*> D(1);
    D.push_back(D1);
    possibleDefense = D;
    vector<StatusMove*> S(1);
    S.push_back(S1);
}