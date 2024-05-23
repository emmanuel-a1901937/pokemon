#include "GrassAttackMove.h"

GrassAttackMove::GrassAttackMove(string _name, string _type, int _damage, int _accuracy) {
  // Assign the appropriate inputs to variables
  this->name = _name; 
  this->type = _type; 
  this->damage = _damage; 
  this->accuracy = _accuracy; 
}

string GrassAttackMove::getName() {
  // return name for access outside of class
  return name; 
}

int GrassAttackMove::getDamage() {
  // return damage for access outside class
  return damage; 
}

int GrassAttackMove::getAccuracy() {
  // return accuracy for access outside class
  return accuracy; 
}