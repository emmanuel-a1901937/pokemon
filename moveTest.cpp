#include <iostream> 

using namespace std; 

#include "FireAttackMove.h"
#include "WaterAttackMove.h"
#include "GrassAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"
#include "Pokemon.h"

int main() {
  FireAttackMove* a1 = new FireAttackMove("BlazingComet", "Fire", 20, 80);
  DefendMove* d1 = new DefendMove("SharpenBlade", "Fire", 30, 0, 0); 
  StatusMove* s1 = new StatusMove("BreakBlade", "Fire", -30, 0, 0, 90);

  cout << "Attack: " << a1->getName() << a1->getAccuracy() << a1->getDamage() << endl; 
  cout << "Defend: " << d1->getName() << d1->getAttackEffect() << d1->getDefenceEffect() << d1->getSpeedEffect() << endl; 
  cout << "Status: " << s1->getName() << s1->getAccuracy() << s1->getAttackEffect() << s1->getDefenceEffect() << s1->getSpeedEffect() << endl; 

}