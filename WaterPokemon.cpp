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
    DefendMove* d1 = new DefendMove("SharpenBlade", "Water", 30, 0, 0); // raises attack 
    DefendMove* d2 = new DefendMove("RaiseShield", "Water", 0, 30 ,0); // raises defence 
    DefendMove* d3 = new DefendMove("QuickFeet", "Water", 0, 0, 30); // raises speed 
    DefendMove* d4 = new DefendMove("DualWield", "Water", 60, -40, 0); // doubles attack, halves defence 
    DefendMove* d5 = new DefendMove("DualShield", "Water", -40, 60, 0); // doubles defence, halves attack 
    DefendMove* d6 = new DefendMove("LightningBoots", "Water", 0, -40, 60); // doubles speed, halves defence
    DefendMove* d7 = new DefendMove("HeavyArmour", "Water", 0, 60, -40); // doubles defence, halves speed
    DefendMove* d8 = new DefendMove("GreatWeapon", "Water", 60, 0, -40); // doubles attack, halves speed
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