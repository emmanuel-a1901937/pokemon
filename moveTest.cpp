#include <iostream> 

using namespace std; 

#include "FireAttackMove.h"
#include "WaterAttackMove.h"
#include "GrassAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
#include "vector"

void testCreateMoves() { // test creating Move objects 
  FireAttackMove* a1 = new FireAttackMove("BlazingComet", "Attack", 20, 80);
  DefendMove* d1 = new DefendMove("SharpenBlade", "Defend", 30, 0, 0); 
  StatusMove* s1 = new StatusMove("BreakBlade", "Status", -30, 0, 0, 90);

  cout << "Attack: " << a1->getName() << " Damage: " << a1->getDamage() << " Accuracy: " << a1->getAccuracy() << endl; 
  cout << "Defend: " << d1->getName() << " Attack Effect: " << d1->getAttackEffect() << " Defence Effect: " << d1->getDefenceEffect() << " Speed Effect: " << d1->getSpeedEffect() << endl; 
  cout << "Status: " << s1->getName() << " Attack Effect: " << s1->getAttackEffect() << " Defence Effect: " << s1->getDefenceEffect() << " Speed Effect: " << s1->getSpeedEffect() << " Accuracy: " << s1->getAccuracy() << endl; 
}

void testCreatePokemon() { // test creating Pokemon objects 

  // NOTE: RANDOM NUMBER GENERATORS ARE NOT SEEDED IN FIREPOKEMON, WATERPOKEMON, GRASSPOKEMON CONSTRUCTORS SO THEY KEEP GENERATING THE SAME STATS !! 

  // create a FirePokemon
  Pokemon* firey = new FirePokemon("Firey");
  cout << "Name: " << firey->getName() << endl; 
  cout << "Type: " << firey->getType() << endl; 
  cout << "Health: " << firey->getHealth() << endl; 
  cout << "Attack stat: " << firey->getAttack() << endl; 
  cout << "Defence stat: " << firey->getDefence() << endl; 
  cout << "Speed stat: " << firey->getSpeed() << endl; 
  // print names of each move
  vector<Move*>& movesFirey = firey->getMoves(); 
  for (int i = 0; i < 4; i++) {
    cout << "Move #" << i << " name: " << movesFirey[i]->getName() << endl; 
  }
  cout << "*** ***" << endl; // spacer line in terminal 


  // create a WaterPokemon 
  Pokemon* puddle = new WaterPokemon("Puddle");
  cout << "Name: " << puddle->getName() << endl; 
  cout << "Type: " << puddle->getType() << endl; 
  cout << "Health: " << puddle->getHealth() << endl; 
  cout << "Attack stat: " << puddle->getAttack() << endl; 
  cout << "Defence stat: " << puddle->getDefence() << endl; 
  cout << "Speed stat: " << puddle->getSpeed() << endl; 
  // print names of each move
  vector<Move*>& movesPuddle = puddle->getMoves(); 
  for (int i = 0; i < 4; i++) {
    cout << "Move #" << i << " name: " << movesPuddle[i]->getName() << endl; 
  }
  cout << "*** ***" << endl; // spacer line in terminal 


  // create a GrassPokemon 
  Pokemon* dirt = new GrassPokemon("Dirt");
  cout << "Name: " << dirt->getName() << endl; 
  cout << "Type: " << dirt->getType() << endl; 
  cout << "Health: " << dirt->getHealth() << endl; 
  cout << "Attack stat: " << dirt->getAttack() << endl; 
  cout << "Defence stat: " << dirt->getDefence() << endl; 
  cout << "Speed stat: " << dirt->getSpeed() << endl; 
  // print names of each move
  vector<Move*>& movesDirt = dirt->getMoves(); 
  for (int i = 0; i < 4; i++) {
    cout << "Move #" << i << " name: " << movesDirt[i]->getName() << endl; 
  }
}

void testPokemonUseMove() { // test using 'useMove' function in Pokemon objects 

}

int main() {
  testCreatePokemon(); 

  return 0; 
}