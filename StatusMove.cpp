#include "StatusMove.h"

StatusMove::StatusMove(string _name, string _type, int _attackEffect, int _defenceEffect, int _speedEffect, int _accuracy) {
  // Writing input to appropriate variables
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

int StatusMove::getAttackEffect() {
  return attackEffect; 
}

int StatusMove::getDefenceEffect() {
  return defenceEffect; 
}

int StatusMove::getSpeedEffect() {
  return speedEffect; 
}

int StatusMove::getAccuracy() {
  return accuracy; 
}