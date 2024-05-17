#include <iostream> 

using namespace std; 

#include "FireAttackMove.h"
#include "WaterAttackMove.h"
#include "GrassAttackMove.h"
#include "DefendMove.h"
#include "StatusMove.h"

int main() {
  FireAttackMove* a1 = new FireAttackMove("BlazingComet", "Fire", 20, 80);
  DefendMove* d1 = new DefendMove("SharpenBlade", "Fire", 30, 0, 0); 
  StatusMove* s1 = new StatusMove("BreakBlade", "Fire", -30, 0, 0, 90);

  
}