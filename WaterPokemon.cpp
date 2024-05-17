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

void WaterPokemon::useAttack(WaterAttackMove* move, Pokemon* targetPokemon) {
    cout << this->name << " used Water Attack " << move->getName() << " on " << targetPokemon->getName() << endl; 

      // determine if attack hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99

      if (randomNumber < move->getAccuracy()) { // attack hits if randomNumber falls below the accuracy attribute 
        float bonus = 1; 

        if (targetPokemon->getType() == "Fire") {
          bonus = 1.5; // super effective bonus applied if FireAttackMove used against FirePokemon
        }

        // calculate damage dealt 
        float attackPower = move->getDamage(); 
        float actingPokemonAttackStat = this->attack; 
        float targetPokemonDefenceStat = targetPokemon->getDefence(); 
        float totalDamage = (attackPower * (actingPokemonAttackStat/targetPokemonDefenceStat)) * bonus; 

        targetPokemon->takeDamage(totalDamage); // reduce p2 health 
        cout << this->name << " successfully dealt " << totalDamage <<  " damage to " << targetPokemon->getName() << endl; // print successful attack message 
      } 
      
      else { // if attack does not hit (based on randomNumber)
        cout << this->name << "'s Attack missed!" << endl; // print failed attack message
      }    
}

void WaterPokemon::useDefend(DefendMove* move) {
    cout << this->name << " used Defend Move " << move->getName() << "!" << endl; // print message to let user know what move was used

      // apply Attack effect
      if (move->getAttackEffect() != 0) { // if there is a change in Attack stat
        int newAttack = this->attack  + move->getAttackEffect(); // calculate new Attack stat
        if (newAttack > 0) { // if newAttack is above 0
          setAttack(newAttack); // update Attack stat 
          cout << this->name << "'s Attack has been affected by " << move->getAttackEffect() << ". New Attack stat is " << attack << endl; // print message 
        }
        else { // if newAttack would be less than 1
          setAttack(1); // set newAttack to 1
          cout << this->name << "'s Attack has been affected by " << move->getAttackEffect() << ". New Attack stat is " << attack << endl; // print message 
        }
      }

      // apply Defence effect
      if (move->getDefenceEffect() != 0) { // if there is a change in Defence stat
        int newDefence = this->defence  + move->getDefenceEffect(); // calculate new Defence stat
        if (newDefence > 0) { // if newDefence is above 0
          setDefence(newDefence); // update Defence stat 
          cout << this->name << "'s Defence has been affected by " << move->getDefenceEffect() << ". New Defence stat is " << defence << endl; // print message 
        }
        else { // if newDefence would be less than 1
          setDefence(1); // set newDefence to 1
          cout << this->name << "'s Defence has been affected by " << move->getDefenceEffect() << ". New Defence stat is " << defence << endl; // print message 
        }
      }

      // apply Speed effect
      if (move->getSpeedEffect() != 0) { // if there is a change in Speed stat
        int newSpeed = this->speed  + move->getSpeedEffect(); // calculate new Speed stat
        if (newSpeed > 0) { // if newSpeed is above 0
          setSpeed(newSpeed); // update Speed stat 
          cout << this->name << "'s Speed has been affected by " << move->getSpeedEffect() << ". New Speed stat is " << speed << endl; // print message 
        }
        else { // if newSpeed would be less than 1
          setSpeed(1); // set newSpeed to 1
          cout << this->name << "'s Speed has been affected by " << move->getSpeedEffect() << ". New Speed stat is " << speed << endl; // print message 
        }
      }
}

void WaterPokemon::useStatus(StatusMove* move, Pokemon* targetPokemon) {
    cout << name << " used Status Move " << move->getName() << " against " << targetPokemon->getName() << "!" << endl; // print message to let user know what move was used

    // determine if status move hits based on accuracy attribute 
    srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
    int randomNumber = rand() % 100; // generate a random number between 0 and 99

    if (randomNumber < move->getAccuracy()) { // status move hits if randomNumber falls below the accuracy attribute 

    // apply Attack effect
    if (move->getAttackEffect() != 0) { // if there is a change in Attack stat
        int newAttack = targetPokemon->getAttack()  + move->getAttackEffect(); // calculate new Attack stat
        if (newAttack > 0) { // ensure newAttack is above 0
        targetPokemon->setAttack(newAttack); // update Attack stat 
        cout << targetPokemon->getName() << "'s Attack has been affected by " << move->getAttackEffect() << ". New Attack stat is " << targetPokemon->getAttack() << endl; // print message 
        }
        else { // if newAttack would be less than 1
        targetPokemon->setAttack(1); // set newAttack to 1
        cout << targetPokemon->getName() << "'s Attack has been affected by " << move->getAttackEffect() << ". New Attack stat is " << targetPokemon->getAttack() << endl; // print message 
        }
    }

    // apply Defence effect
    if (move->getDefenceEffect() != 0) {
        int newDefence = targetPokemon->getDefence()  + move->getDefenceEffect(); // calculate new Defence stat
        if (newDefence > 0) { // if newDefence is above 0
        targetPokemon->setDefence(newDefence); // update Defence stat 
        cout << targetPokemon->getName() << "'s Defence has been affected by " << move->getDefenceEffect() << ". New Defence stat is " << targetPokemon->getDefence() << endl; // print message 
        }
        else { // if newDefence would be less than 1
        targetPokemon->setDefence(1); // set newDefence to 1
        cout << targetPokemon->getName() << "'s Defence has been affected by " << move->getDefenceEffect() << ". New Defence stat is " << targetPokemon->getDefence() << endl; // print message 
        }
    }

    // apply Speed effect
    if (move->getSpeedEffect() != 0) {
        int newSpeed = targetPokemon->getSpeed()  + move->getSpeedEffect(); // calculate new Speed stat
        if (newSpeed > 0) { // if newSpeed is above 0
        targetPokemon->setSpeed(newSpeed); // update Speed stat 
        cout << targetPokemon->getName() << "'s Speed has been affected by " << move->getSpeedEffect() << ". New Speed stat is " << targetPokemon->getSpeed() << endl; // print message 
        }
        else { // if newSpeed would be less than 1
        targetPokemon->setSpeed(1); // set newSpeed to 1
        cout << targetPokemon->getName() << "'s Speed has been affected by " << move->getSpeedEffect() << ". New Speed stat is " << targetPokemon->getSpeed() << endl; // print message 
        }
    }
    }

    else { // if Status move did not hit 
    cout << name << "'s Status Move was ineffective!" << endl; 
    }
}