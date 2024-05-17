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
    StatusMove* s1 = new StatusMove("BreakBlade", "Water", -30, 0, 0, 90); // reduces attack 
    StatusMove* s2 = new StatusMove("ShieldBreaker", "Water", 0, -30 ,0, 90); // reduces defence 
    StatusMove* s3 = new StatusMove("StickyFeet", "Water", 0, 0, -30, 90); // reduces speed 
    StatusMove* s4 = new StatusMove("Infatuate", "Water", -60, 40, 0, 90); // reduces attack, ups defence 
    StatusMove* s5 = new StatusMove("Taunt", "Water", 40, -60, 0, 90); // reduces defence, ups attack 
    StatusMove* s6 = new StatusMove("IronBoots", "Water", 0, 40, -60, 90); // reduces speed, ups defence
    StatusMove* s7 = new StatusMove("SlipperySlippers", "Water", 0, -60, 40, 90); // reduces defence, ups speed
    StatusMove* s8 = new StatusMove("LilKnives", "Water", -60, 0, 40, 90); // reduces attack, ups speed
    possibleStatus.push_back(s1);
    possibleStatus.push_back(s2);
    possibleStatus.push_back(s3);
    possibleStatus.push_back(s4);
    possibleStatus.push_back(s5);
    possibleStatus.push_back(s6);
    possibleStatus.push_back(s7);
    possibleStatus.push_back(s8);

    setMoves(); 
}

void WaterPokemon::setMoves() {
    // random number generator from 0-9
    random_device rd; // Seed with a real random value, if available

    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 9); // Choose a random number between 0 and 9

    // pick random attack move
    int r1 = distrib(gen); // random number 1
    int r2 = distrib(gen); // random number 2
    while (r2 == r1) {
        r2 = distrib(gen); // ensure r2 != r1
    }
    Move* a1 = (possibleAttacks[r1]); // select first attack from possibleAttacks 
    Move* a2 = (possibleAttacks[r2]); // select second attack from possibleAttacks 
    this->moves.push_back(a1); 
    this->moves.push_back(a2);


    // random number generator 
    random_device rd; // Seed with a real random value, if available

    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, 7); // Choose a random number between 0 and 7


    // pick random defend move 
    int r3 = distrib(gen);
    Move* d1 = (possibleDefense[r3]); // select defend move from possibleDefence 
    this->moves.push_back(d1);

    // pick random status move 
    int r4 = distrib(gen); 
    Move* s1 = (possibleStatus[r4]); // select status move from possibleStatus 
    this->moves.push_back(s1);
}