#include "WaterAttackMove.h"

WaterAttackMove::WaterAttackMove(string _name, string _type, int _damage, int _accuracy) {
  // Assign the appropriate input to variable
  this->name = _name; 
  this->type = _type; 
  this->damage = _damage; 
  this->accuracy = _accuracy; 
}

string WaterAttackMove::getName() {
  return name; 
}

int WaterAttackMove::getDamage() {
  return damage; 
}

int WaterAttackMove::getAccuracy() {
  return accuracy; 
}