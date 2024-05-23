#include "DefendMove.h"

DefendMove::DefendMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect) {
  // Assign appropriate input to variable
  name = _name; 
  type = _type; 
  attackEffect = _attackEffect; 
  defenceEffect = _defenceEffect; 
  speedEffect = _speedEffect; 
}

string DefendMove::getName() {
  // return name for access outside class
  return name; 
}

int DefendMove::getAttackEffect() {
  // return attackEffect for access outside class
  return attackEffect; 
}

int DefendMove::getDefenceEffect() {
  // return defenceEffect for access outside class
  return defenceEffect; 
}

int DefendMove::getSpeedEffect() {
  // return speedEffect for access outside class
  return speedEffect; 
}