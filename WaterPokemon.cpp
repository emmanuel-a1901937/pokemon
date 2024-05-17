#include <vector>
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

    // create list of possible moves 
    // possible attacks 
    WaterAttackMove* a1 = new WaterAttackMove("TidalWave", "Water", 20, 80);
    WaterAttackMove* a2 = new WaterAttackMove("AquaVortex", "Water", 25, 75);
    WaterAttackMove* a3 = new WaterAttackMove("BubbleBurst", "Water", 30, 70);
    WaterAttackMove* a4 = new WaterAttackMove("HydroHammer", "Water", 35, 65);
    WaterAttackMove* a5 = new WaterAttackMove("CascadeCrush", "Water", 40, 60);
    WaterAttackMove* a6 = new WaterAttackMove("WhirlpoolStrike", "Water", 45, 55);
    WaterAttackMove* a7 = new WaterAttackMove("RainDanceBlitz", "Water", 50, 50);
    WaterAttackMove* a8 = new WaterAttackMove("AquaLance", "Water", 55, 45);
    WaterAttackMove* a9 = new WaterAttackMove("GeyserBlast", "Water", 60, 40);
    WaterAttackMove* a10 = new WaterAttackMove("OceanicRoar", "Water", 65, 35);
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