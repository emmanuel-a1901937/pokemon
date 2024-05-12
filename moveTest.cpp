#include <iostream> 
#include "Move.h"

using namespace std; 

int main() {
  float bonus = 1.5; 
  float attackPower = 60; 
  float p1AttackStat = 70; 
  float p2DefenceStat = 50; 
  float totalDamage = (attackPower * (p1AttackStat/p2DefenceStat)) * bonus; 

  cout << totalDamage << endl; 
}