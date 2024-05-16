#include <vector>
#include "FirePokemon.h"
#include <iostream>
#include <string>



FirePokemon::FirePokemon(string names) {
    name = names;
    type = "Fire";
    maxHealth = rand() % 200 + 100;  //These are just random values as placeholders, feel free to change
    currentHealth = maxHealth;
    attack = rand() % 90 + 70;
    defence = rand() % 90 + 70;
    speed = rand() % 90 + 70;
    fainted = false;

}

void FirePokemon::setMoves(FireAttackMove* F1, FireAttackMove* F2, DefendMove* D1, StatusMove* S1) {
    vector<FireAttackMove*> FA(2);
    FA.push_back(F1);
    FA.push_back(F2);
    possibleAttacks = FA;
    vector<DefendMove*> D(1);
    D.push_back(D1);
    possibleDefense = D;
    vector<StatusMove*> S(1);
    S.push_back(S1);
}

