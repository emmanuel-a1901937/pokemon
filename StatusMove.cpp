#include "StatusMove.h"

StatusMove::StatusMove(string _name, string _type, float _attackEffect, float _defenceEffect, float _speedEffect, int _accuracy) {
  name = _name; 
  type = _type; 
  attackEffect = _attackEffect; 
  defenceEffect = _defenceEffect; 
  speedEffect = _speedEffect; 
  accuracy = _accuracy; 
}

string StatusMove::getName() {
  return name; 
}

float StatusMove::getAttackEffect() {
  return attackEffect; 
}

float StatusMove::getDefenceEffect() {
  return defenceEffect; 
}

float StatusMove::getSpeedEffect() {
  return speedEffect; 
}

int StatusMove::getAccuracy() {
  return accuracy; 
}

void StatusMove::f() {} // does nothing; needed for Move to be a virtual class 