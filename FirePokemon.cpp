#include <vector>
#include "FirePokemon.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>



FirePokemon::FirePokemon(string names) { // Constructs a Fire Pokemon using randomly generated stats and an inputted name
    srand(time(0));
    name = names;
    type = "Fire";
    maxHealth = rand() % 41 + 100;  //These are just random values as placeholders, feel free to change
    currentHealth = maxHealth;
    attack = rand() % 21 + 70;
    defence = rand() % 21 + 70;
    speed = rand() % 21 + 70;
    fainted = false;

    // create list of possible moves 
    // possible attacks 
    FireAttackMove* a1 = new FireAttackMove("BlazingComet", "Attack", 20, 100);
    FireAttackMove* a2 = new FireAttackMove("InfernoBurst", "Attack", 25, 97);
    FireAttackMove* a3 = new FireAttackMove("LavaSurge", "Attack", 30, 94);
    FireAttackMove* a4 = new FireAttackMove("FlameVortex", "Attack", 35, 91);
    FireAttackMove* a5 = new FireAttackMove("EmberStorm", "Attack", 40, 88);
    FireAttackMove* a6 = new FireAttackMove("Pyroclasm", "Attack", 45, 85);
    FireAttackMove* a7 = new FireAttackMove("ScorchingRay", "Attack", 50, 82);
    FireAttackMove* a8 = new FireAttackMove("CinderStrike", "Attack", 55, 79);
    FireAttackMove* a9 = new FireAttackMove("WildfireWave", "Attack", 60, 76);
    FireAttackMove* a10 = new FireAttackMove("FlareBlitz", "Attack", 65, 73);
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
     DefendMove* d1 = new DefendMove("SharpenBlade", "Defend", 10, 0, 0); // raises attack 
    DefendMove* d2 = new DefendMove("RaiseShield", "Defend", 0, 10 ,0); // raises defence 
    DefendMove* d3 = new DefendMove("QuickFeet", "Defend", 0, 0, 10); // raises speed 
    DefendMove* d4 = new DefendMove("DualWield", "Defend", 20, -10, 0); // highly raises attack, lowers defence 
    DefendMove* d5 = new DefendMove("DualShield", "Defend", -10, 20, 0); // highly raises defence, lowers attack 
    DefendMove* d6 = new DefendMove("LightningBoots", "Defend", 0, -10, 20); // highly raises speed, lowers defence
    DefendMove* d7 = new DefendMove("HeavyArmour", "Defend", 0, 20, -10); // highly raises defence, lowers speed
    DefendMove* d8 = new DefendMove("GreatWeapon", "Defend", 20, 0, -10); // highly raises attack, lowers speed
    possibleDefense.push_back(d1);
    possibleDefense.push_back(d2);
    possibleDefense.push_back(d3);
    possibleDefense.push_back(d4);
    possibleDefense.push_back(d5);
    possibleDefense.push_back(d6);
    possibleDefense.push_back(d7);
    possibleDefense.push_back(d8);

    // possible status 
    StatusMove* s1 = new StatusMove("BreakBlade", "Status", -10, 0, 0, 90); // reduces attack 
    StatusMove* s2 = new StatusMove("ShieldBreaker", "Status", 0, -10 ,0, 90); // reduces defence 
    StatusMove* s3 = new StatusMove("StickyFeet", "Status", 0, 0, -10, 90); // reduces speed 
    StatusMove* s4 = new StatusMove("Infatuate", "Status", -20, 10, 0, 90); // reduces attack, ups defence 
    StatusMove* s5 = new StatusMove("Taunt", "Status", 10, -20, 0, 90); // reduces defence, ups attack 
    StatusMove* s6 = new StatusMove("IronBoots", "Status", 0, 10, -20, 90); // reduces speed, ups defence
    StatusMove* s7 = new StatusMove("SlipperySlippers", "Status", 0, -20, 10, 90); // reduces defence, ups speed
    StatusMove* s8 = new StatusMove("LilKnives", "Status", -20, 0, 10, 90); // reduces attack, ups speed
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

void FirePokemon::setMoves() {
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

void FirePokemon::useMove(Move* move, Pokemon* targetPokemon) { // public function, called by Game object 
  string moveType = move->getType(); 
  if (moveType == "Attack") {
    useAttack(move, targetPokemon);
  } else if (moveType == "Defend") {
    useDefend(move); 
  } else if (moveType == "Status") {
    useStatus(move, targetPokemon);
  } else {
    cout << "Invalid Move option!" << endl; 
  }
}

void FirePokemon::useAttack(Move* move, Pokemon* targetPokemon) { // protected function, called by FirePokemon object 
    cout << this->name << " used Fire Attack " << move->getName() << " on " << targetPokemon->getName() << endl; 

      // determine if attack hits based on accuracy attribute 
      srand(static_cast<unsigned int>(time(0))); // seed rng with the current time
      int randomNumber = rand() % 100; // generate a random number between 0 and 99
      
      if (randomNumber < move->getAccuracy()) { // attack hits if randomNumber falls below the accuracy attribute 
        float bonus = 1; 

        if (targetPokemon->getType() == "Grass") {
          bonus = 1.5; // super effective bonus applied if FireAttackMove used against GrassPokemon
        } else if(targetPokemon->getType() == "Water") {
          bonus = 0.5;
      }

        // calculate damage dealt 
        float attackPower = move->getDamage(); 
        float actingPokemonAttackStat = this->attack; 
        float targetPokemonDefenceStat = targetPokemon->getDefence(); 
        int totalDamage = (attackPower * (actingPokemonAttackStat/targetPokemonDefenceStat)) * bonus; 

        cout << this->name << " successfully dealt " << totalDamage << " damage to " << targetPokemon->getName() << endl; // print successful attack message
        targetPokemon->takeDamage(totalDamage);                                                                           // reduce p2 health
      } 
      
      else { // if attack does not hit (based on randomNumber)
        cout << this->name << "'s Attack missed!" << endl; // print failed attack message
      }    
}

void FirePokemon::useDefend(Move* move) {
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

void FirePokemon::useStatus(Move* move, Pokemon* targetPokemon) {
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

FirePokemon::~FirePokemon() {
  // delete each status attack & defence attack
  for (int i = 0; i < 8; i++){
    delete possibleStatus[i];
    delete possibleDefense[i];
  }

  // remove the elements from the vector
  possibleDefense.clear();
  possibleStatus.clear(); 

  // delete each attack
  for (int i = 0; i < 10; i++){
    delete possibleAttacks[i];
  }

  // remove the elements from the vector
  possibleAttacks.clear();
}