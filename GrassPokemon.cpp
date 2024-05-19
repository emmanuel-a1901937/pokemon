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
    StatusMove* s1 = new StatusMove("BreakBlade", "Grass", -30, 0, 0, 90); // reduces attack 
    StatusMove* s2 = new StatusMove("ShieldBreaker", "Grass", 0, -30 ,0, 90); // reduces defence 
    StatusMove* s3 = new StatusMove("StickyFeet", "Grass", 0, 0, -30, 90); // reduces speed 
    StatusMove* s4 = new StatusMove("Infatuate", "Grass", -60, 40, 0, 90); // reduces attack, ups defence 
    StatusMove* s5 = new StatusMove("Taunt", "Grass", 40, -60, 0, 90); // reduces defence, ups attack 
    StatusMove* s6 = new StatusMove("IronBoots", "Grass", 0, 40, -60, 90); // reduces speed, ups defence
    StatusMove* s7 = new StatusMove("SlipperySlippers", "Grass", 0, -60, 40, 90); // reduces defence, ups speed
    StatusMove* s8 = new StatusMove("LilKnives", "Grass", -60, 0, 40, 90); // reduces attack, ups speed
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

void GrassPokemon::setMoves() {
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

    // pick random defend move 
    int r3 = distrib(gen);
    while (r3 > 7) { // ensure r3 is between 0 and 7 
      r3 = distrib(gen);
    }
    Move* d1 = (possibleDefense[r3]); // select defend move from possibleDefence 
    this->moves.push_back(d1);

    // pick random status move 
    // ensure r4 is between 0 and 7 
    int r4 = distrib(gen);
    while (r4 > 7) { // ensure r4 is between 0 and 7 
      r4 = distrib(gen);
    }
    Move* s1 = (possibleStatus[r4]); // select status move from possibleStatus 
    this->moves.push_back(s1);
}

void GrassPokemon::useAttack(Move* move, Pokemon* targetPokemon) {
    GrassAttackMove* a1 = dynamic_cast<GrassAttackMove*>(move); 
    cout << this->name << " used Grass Attack " << a1->getName() << " on " << targetPokemon->getName() << endl; 

      // determine if attack hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99

      if (randomNumber < a1->getAccuracy()) { // attack hits if randomNumber falls below the accuracy attribute 
        float bonus = 1; 

        if (targetPokemon->getType() == "Water") {
          bonus = 1.5; // super effective bonus applied if FireAttackMove used against WaterPokemon
        }

        // calculate damage dealt 
        float attackPower = a1->getDamage(); 
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

void GrassPokemon::useDefend(Move* move) {
    DefendMove* d1 = dynamic_cast<DefendMove*>(move); 
    cout << this->name << " used Defend Move " << d1->getName() << "!" << endl; // print message to let user know what move was used

      // apply Attack effect
      if (d1->getAttackEffect() != 0) { // if there is a change in Attack stat
        int newAttack = this->attack  + d1->getAttackEffect(); // calculate new Attack stat
        if (newAttack > 0) { // if newAttack is above 0
          setAttack(newAttack); // update Attack stat 
          cout << this->name << "'s Attack has been affected by " << d1->getAttackEffect() << ". New Attack stat is " << attack << endl; // print message 
        }
        else { // if newAttack would be less than 1
          setAttack(1); // set newAttack to 1
          cout << this->name << "'s Attack has been affected by " << d1->getAttackEffect() << ". New Attack stat is " << attack << endl; // print message 
        }
      }

      // apply Defence effect
      if (d1->getDefenceEffect() != 0) { // if there is a change in Defence stat
        int newDefence = this->defence  + d1->getDefenceEffect(); // calculate new Defence stat
        if (newDefence > 0) { // if newDefence is above 0
          setDefence(newDefence); // update Defence stat 
          cout << this->name << "'s Defence has been affected by " << d1->getDefenceEffect() << ". New Defence stat is " << defence << endl; // print message 
        }
        else { // if newDefence would be less than 1
          setDefence(1); // set newDefence to 1
          cout << this->name << "'s Defence has been affected by " << d1->getDefenceEffect() << ". New Defence stat is " << defence << endl; // print message 
        }
      }

      // apply Speed effect
      if (d1->getSpeedEffect() != 0) { // if there is a change in Speed stat
        int newSpeed = this->speed  + d1->getSpeedEffect(); // calculate new Speed stat
        if (newSpeed > 0) { // if newSpeed is above 0
          setSpeed(newSpeed); // update Speed stat 
          cout << this->name << "'s Speed has been affected by " << d1->getSpeedEffect() << ". New Speed stat is " << speed << endl; // print message 
        }
        else { // if newSpeed would be less than 1
          setSpeed(1); // set newSpeed to 1
          cout << this->name << "'s Speed has been affected by " << d1->getSpeedEffect() << ". New Speed stat is " << speed << endl; // print message 
        }
      }
}

void GrassPokemon::useStatus(Move* move, Pokemon* targetPokemon) {
    StatusMove* s1 = dynamic_cast<StatusMove*>(move); 
    cout << name << " used Status Move " << s1->getName() << " against " << targetPokemon->getName() << "!" << endl; // print message to let user know what move was used

    // determine if status move hits based on accuracy attribute 
    srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
    int randomNumber = rand() % 100; // generate a random number between 0 and 99

    if (randomNumber < s1->getAccuracy()) { // status move hits if randomNumber falls below the accuracy attribute 

    // apply Attack effect
    if (s1->getAttackEffect() != 0) { // if there is a change in Attack stat
        int newAttack = targetPokemon->getAttack()  + s1->getAttackEffect(); // calculate new Attack stat
        if (newAttack > 0) { // ensure newAttack is above 0
        targetPokemon->setAttack(newAttack); // update Attack stat 
        cout << targetPokemon->getName() << "'s Attack has been affected by " << s1->getAttackEffect() << ". New Attack stat is " << targetPokemon->getAttack() << endl; // print message 
        }
        else { // if newAttack would be less than 1
        targetPokemon->setAttack(1); // set newAttack to 1
        cout << targetPokemon->getName() << "'s Attack has been affected by " << s1->getAttackEffect() << ". New Attack stat is " << targetPokemon->getAttack() << endl; // print message 
        }
    }

    // apply Defence effect
    if (s1->getDefenceEffect() != 0) {
        int newDefence = targetPokemon->getDefence()  + s1->getDefenceEffect(); // calculate new Defence stat
        if (newDefence > 0) { // if newDefence is above 0
        targetPokemon->setDefence(newDefence); // update Defence stat 
        cout << targetPokemon->getName() << "'s Defence has been affected by " << s1->getDefenceEffect() << ". New Defence stat is " << targetPokemon->getDefence() << endl; // print message 
        }
        else { // if newDefence would be less than 1
        targetPokemon->setDefence(1); // set newDefence to 1
        cout << targetPokemon->getName() << "'s Defence has been affected by " << s1->getDefenceEffect() << ". New Defence stat is " << targetPokemon->getDefence() << endl; // print message 
        }
    }

    // apply Speed effect
    if (s1->getSpeedEffect() != 0) {
        int newSpeed = targetPokemon->getSpeed()  + s1->getSpeedEffect(); // calculate new Speed stat
        if (newSpeed > 0) { // if newSpeed is above 0
        targetPokemon->setSpeed(newSpeed); // update Speed stat 
        cout << targetPokemon->getName() << "'s Speed has been affected by " << s1->getSpeedEffect() << ". New Speed stat is " << targetPokemon->getSpeed() << endl; // print message 
        }
        else { // if newSpeed would be less than 1
        targetPokemon->setSpeed(1); // set newSpeed to 1
        cout << targetPokemon->getName() << "'s Speed has been affected by " << s1->getSpeedEffect() << ". New Speed stat is " << targetPokemon->getSpeed() << endl; // print message 
        }
    }
    }

    else { // if Status move did not hit 
    cout << name << "'s Status Move was ineffective!" << endl; 
    }
}