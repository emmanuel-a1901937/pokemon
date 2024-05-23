#include "DefendMove.h"

DefendMove::DefendMove(string _name, string _type, float _attackEffect, float _defenceEffect, float _speedEffect) {
  name = _name; 
  type = _type; 
  attackEffect = _attackEffect; 
  defenceEffect = _defenceEffect; 
  speedEffect = _speedEffect; 
}

string DefendMove::getName() {
  return name; 
}

float DefendMove::getAttackEffect() {
  return attackEffect; 
}

float DefendMove::getDefenceEffect() {
  return defenceEffect; 
}

float DefendMove::getSpeedEffect() {
  return speedEffect; 
}

void DefendMove::f() {} // does nothing; needed for Move to be a virtual class 