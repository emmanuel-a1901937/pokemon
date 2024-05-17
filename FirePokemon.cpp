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
    DefendMove* d1 = new DefendMove("SharpenBlade", "Fire", 30, 0, 0); // raises attack 
    DefendMove* d2 = new DefendMove("RaiseShield", "Fire", 0, 30 ,0); // raises defence 
    DefendMove* d3 = new DefendMove("QuickFeet", "Fire", 0, 0, 30); // raises speed 
    DefendMove* d4 = new DefendMove("DualWield", "Fire", 60, -40, 0); // doubles attack, halves defence 
    DefendMove* d5 = new DefendMove("DualShield", "Fire", -40, 60, 0); // doubles defence, halves attack 
    DefendMove* d6 = new DefendMove("LightningBoots", "Fire", 0, -40, 60); // doubles speed, halves defence
    DefendMove* d7 = new DefendMove("HeavyArmour", "Fire", 0, 60, -40); // doubles defence, halves speed
    DefendMove* d8 = new DefendMove("GreatWeapon", "Fire", 60, 0, -40); // doubles attack, halves speed
    possibleDefense.push_back(d1);
    possibleDefense.push_back(d2);
    possibleDefense.push_back(d3);
    possibleDefense.push_back(d4);
    possibleDefense.push_back(d5);
    possibleDefense.push_back(d6);
    possibleDefense.push_back(d7);
    possibleDefense.push_back(d8);

    // possible status 
    StatusMove* s1 = new StatusMove("BreakBlade", "Fire", -30, 0, 0, 90); // reduces attack 
    StatusMove* s2 = new StatusMove("ShieldBreaker", "Fire", 0, -30 ,0, 90); // reduces defence 
    StatusMove* s3 = new StatusMove("StickyFeet", "Fire", 0, 0, -30, 90); // reduces speed 
    StatusMove* s4 = new StatusMove("Infatuate", "Fire", -60, 40, 0, 90); // reduces attack, ups defence 
    StatusMove* s5 = new StatusMove("Taunt", "Fire", 40, -60, 0, 90); // reduces defence, ups attack 
    StatusMove* s6 = new StatusMove("IronBoots", "Fire", 0, 40, -60, 90); // reduces speed, ups defence
    StatusMove* s7 = new StatusMove("SlipperySlippers", "Fire", 0, -60, 40, 90); // reduces defence, ups speed
    StatusMove* s8 = new StatusMove("LilKnives", "Fire", -60, 0, 40, 90); // reduces attack, ups speed
    possibleStatus.push_back(s1);
    possibleStatus.push_back(s2);
    possibleStatus.push_back(s3);
    possibleStatus.push_back(s4);
    possibleStatus.push_back(s5);
    possibleStatus.push_back(s6);
    possibleStatus.push_back(s7);
    possibleStatus.push_back(s8);
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

