#include <iostream> 

using namespace std; 

int main() {
  // dummy test just to play around with the formula calculating totalDamage 
  float bonus = 1.5; 
  float attackPower = 60; 
  float p1AttackStat = 70; 
  float p2DefenceStat = 60; 
  float totalDamage = (attackPower * (p1AttackStat/p2DefenceStat)) * bonus; 

  cout << totalDamage << endl; 
}