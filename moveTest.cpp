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
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;
   Pokemon* lake = new WaterPokemon("Emmanuel");
   Pokemon* ground = new GrassPokemon("Alex");
   vector<Move*>& movesEmmanuel = lake->getMoves(); 
   vector<Move*>& movesAlex = ground->getMoves(); 
   cout << "Emmanuel Health " << lake->getHealth() << " Alex Health " << ground->getHealth() << endl;
   lake->useMove(movesEmmanuel[1], ground);
   ground->useMove(movesAlex[1], lake);
   cout << "Emmanuel Health " << lake->getHealth() << " Alex Health " << ground->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* pond = new WaterPokemon("Emmanuel2");
   Pokemon* ash = new FirePokemon("Alex2");
   vector<Move*>& movesEmmanuel2 = pond->getMoves(); 
   vector<Move*>& movesAlex2 = ash->getMoves(); 
   cout << "Emmanuel2 Health " << pond->getHealth() << " Alex2 Health " << ash->getHealth() << endl;
   pond->useMove(movesEmmanuel2[1], ash);
   ash->useMove(movesAlex2[1], pond);
   cout << "Emmanuel2 Health " << pond->getHealth() << " Alex2 Health " << ash->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* river = new WaterPokemon("Emmanuel3");
   Pokemon* ocean = new WaterPokemon("Alex3");
   vector<Move*>& movesEmmanuel3 = river->getMoves(); 
   vector<Move*>& movesAlex3 = ocean->getMoves(); 
   cout << "Emmanuel3 Health " << river->getHealth() << " Alex3 Health " << ocean->getHealth() << endl;
   river->useMove(movesEmmanuel3[1], ocean);
   ocean->useMove(movesAlex3[1], river);
   cout << "Emmanuel3 Health " << river->getHealth() << " Alex3 Health " << ocean->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* ember = new FirePokemon("Emmanuel4");
   Pokemon* flame = new FirePokemon("Alex4");
   vector<Move*>& movesEmmanuel4 = ember->getMoves(); 
   vector<Move*>& movesAlex4 = flame->getMoves(); 
   cout << "Emmanuel4 Health " << ember->getHealth() << " Alex4 Health " << flame->getHealth() << endl;
   ember->useMove(movesEmmanuel4[1], flame);
   flame->useMove(movesAlex4[1], ember);
   cout << "Emmanuel4 Health " << ember->getHealth() << " Alex4 Health " << flame->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* bonfire = new FirePokemon("Emmanuel5");
   Pokemon* sprout = new GrassPokemon("Alex5");
   vector<Move*>& movesEmmanuel5 = bonfire->getMoves(); 
   vector<Move*>& movesAlex5 = sprout->getMoves(); 
   cout << "Emmanuel5 Health " << bonfire->getHealth() << " Alex5 Health " << sprout->getHealth() << endl;
   bonfire->useMove(movesEmmanuel5[1], sprout);
   sprout->useMove(movesAlex5[1], bonfire);
   cout << "Emmanuel5 Health " << bonfire->getHealth() << " Alex5 Health " << sprout->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* twig = new GrassPokemon("Emmanuel6");
   Pokemon* tree = new GrassPokemon("Alex6");
   vector<Move*>& movesEmmanuel6 = twig->getMoves(); 
   vector<Move*>& movesAlex6 = tree->getMoves(); 
   cout << "Emmanuel6 Health " << twig->getHealth() << " Alex6 Health " <<tree->getHealth() << endl;
   twig->useMove(movesEmmanuel6[1], tree);
   tree->useMove(movesAlex6[1], twig);
   cout << "Emmanuel6 Health " << twig->getHealth() << " Alex6 Health " <<tree->getHealth() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* Barry = new GrassPokemon("TheCoolerEmmanuel");
   vector<Move*>& movesTheCoolerEmmanuel = Barry->getMoves();
   cout << "The Cooler Emmanuel stats " << Barry->getAttack() << " " <<Barry->getDefence() << " " << Barry->getSpeed() << endl;
   Barry->useMove(movesTheCoolerEmmanuel[2], Barry);
   cout << "The Cooler Emmanuel new stats " << Barry->getAttack() << " " <<Barry->getDefence() << " " << Barry->getSpeed() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;

   Pokemon* Kevin = new GrassPokemon("TheCoolerAlex");
   vector<Move*>& movesTheCoolerAlex = Kevin->getMoves();
   cout << "The Cooler Alex stats " << Kevin->getAttack() << " " <<Kevin->getDefence() << " " << Kevin->getSpeed() << endl;
   Kevin->useMove(movesTheCoolerAlex[3], Kevin);
   cout << "The Cooler Alex new stats " << Kevin->getAttack() << " " <<Kevin->getDefence() << " " << Kevin->getSpeed() << endl;
   cout << endl;
   cout << "**** ****" << endl;
   cout << endl;



}


int main() {
  ///testCreatePokemon(); 
  testPokemonUseMove();
//clang++ moveTest.cpp Pokemon.cpp StatusMove.cpp DefendMove.cpp Move.cpp FireAttackMove.cpp FirePokemon.cpp WaterAttackMove.cpp WaterPokemon.cpp GrassAttackMove.cpp GrassPokemon.cpp AttackMove.cpp -o t
  return 0; 
}