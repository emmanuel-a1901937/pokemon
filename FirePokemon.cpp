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

    // create list of possible moves 
    // possible attacks 
    FireAttackMove* a1 = new FireAttackMove("BlazingComet", "Fire", 20, 80);
    FireAttackMove* a2 = new FireAttackMove("InfernoBurst", "Fire", 25, 75);
    FireAttackMove* a3 = new FireAttackMove("LavaSurge", "Fire", 30, 70);
    FireAttackMove* a4 = new FireAttackMove("FlameVortex", "Fire", 35, 65);
    FireAttackMove* a5 = new FireAttackMove("EmberStorm", "Fire", 40, 60);
    FireAttackMove* a6 = new FireAttackMove("Pyroclasm", "Fire", 45, 55);
    FireAttackMove* a7 = new FireAttackMove("ScorchingRay", "Fire", 50, 50);
    FireAttackMove* a8 = new FireAttackMove("CinderStrike", "Fire", 55, 45);
    FireAttackMove* a9 = new FireAttackMove("WildfireWave", "Fire", 60, 40);
    FireAttackMove* a10 = new FireAttackMove("FlareBlitz", "Fire", 65, 35);
    possibleAttacks.push_back(a1);
    possibleAttacks.push_back(a2);
    possibleAttacks.push_back(a3);
    possibleAttacks.push_back(a4);
    possibleAttacks.push_back(a5);
    possibleAttacks.push_back(a6);
    possibleAttacks.push_back(a7);
    possibleAttacks.push_back(a8);
    possibleAttacks.push_back(a9);
    possibleAttacks.push_back(a10);

    // possible defence
    

    // possible status 

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

