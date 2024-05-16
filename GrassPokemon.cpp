#include <vector>
#include "GrassPokemon.h"
#include <iostream>


GrassPokemon::GrassPokemon(string names) {
    name = names;
    type = "Grass";
    maxHealth = rand() % 100 + 100; //These are just random values as placeholders, feel free to change
    currentHealth = maxHealth;
    attack = rand() % 90 + 70;
    defence = rand() % 90 + 70;
    speed = rand() % 90 + 70;
    fainted = false;

}

void GrassPokemon::setMoves(GrassAttackMove* G1, GrassAttackMove* G2, DefendMove* D1, StatusMove* S1) {
    vector<GrassAttackMove*> GA(2);
    GA.push_back(G1);
    GA.push_back(G2);
    possibleAttacks = GA;
    vector<DefendMove*> D(1);
    D.push_back(D1);
    possibleDefense = D;
    vector<StatusMove*> S(1);
    S.push_back(S1);
}