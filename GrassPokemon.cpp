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
    
    // create list of possible moves 
    // possible attacks 
    GrassAttackMove* a1 = new GrassAttackMove("LeafSurge", "Grass", 20, 80);
    GrassAttackMove* a2 = new GrassAttackMove("VineLash", "Grass", 25, 75);
    GrassAttackMove* a3 = new GrassAttackMove("ChlorophyllBurst", "Grass", 30, 70);
    GrassAttackMove* a4 = new GrassAttackMove("BriarBash", "Grass", 35, 65);
    GrassAttackMove* a5 = new GrassAttackMove("PetalCyclone", "Grass", 40, 60);
    GrassAttackMove* a6 = new GrassAttackMove("SapStrike", "Grass", 45, 55);
    GrassAttackMove* a7 = new GrassAttackMove("RootSnare", "Grass", 50, 50);
    GrassAttackMove* a8 = new GrassAttackMove("FernFury", "Grass", 55, 45);
    GrassAttackMove* a9 = new GrassAttackMove("ThicketThrust", "Grass", 60, 40);
    GrassAttackMove* a10 = new GrassAttackMove("MeadowMirage", "Grass", 65, 35);
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
    DefendMove* d1 = new DefendMove("SharpenBlade", "Grass", 30, 0, 0); // raises attack 
    DefendMove* d2 = new DefendMove("RaiseShield", "Grass", 0, 30 ,0); // raises defence 
    DefendMove* d3 = new DefendMove("QuickFeet", "Grass", 0, 0, 30); // raises speed 
    DefendMove* d4 = new DefendMove("DualWield", "Grass", 60, -40, 0); // doubles attack, halves defence 
    DefendMove* d5 = new DefendMove("DualShield", "Grass", -40, 60, 0); // doubles defence, halves attack 
    DefendMove* d6 = new DefendMove("LightningBoots", "Grass", 0, -40, 60); // doubles speed, halves defence
    DefendMove* d7 = new DefendMove("HeavyArmour", "Grass", 0, 60, -40); // doubles defence, halves speed
    DefendMove* d8 = new DefendMove("GreatWeapon", "Grass", 60, 0, -40); // doubles attack, halves speed
    possibleDefense.push_back(d1);
    possibleDefense.push_back(d2);
    possibleDefense.push_back(d3);
    possibleDefense.push_back(d4);
    possibleDefense.push_back(d5);
    possibleDefense.push_back(d6);
    possibleDefense.push_back(d7);
    possibleDefense.push_back(d8);

    // possible status 

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