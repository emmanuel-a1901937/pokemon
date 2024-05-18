#include "DefendMove.h"

DefendMove::DefendMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect) {
  name = _name; 
  type = _type; 
  attackEffect = _attackEffect; 
  defenceEffect = _defenceEffect; 
  speedEffect = _speedEffect; 
}

string DefendMove::getName() {
  return name; 
}

int DefendMove::getAttackEffect() {
  return attackEffect; 
}

int DefendMove::getDefenceEffect() {
  return defenceEffect; 
}

int DefendMove::getSpeedEffect() {
  return speedEffect; 
}