#include "GrassAttackMove.h"

GrassAttackMove::GrassAttackMove(string _name, string _type, int _damage, int _accuracy) {
  this->name = _name; 
  this->type = _type; 
  this->damage = _damage; 
  this->accuracy = _accuracy; 
}

string GrassAttackMove::getName() {
  return name; 
}

int GrassAttackMove::getDamage() {
  return damage; 
}

int GrassAttackMove::getAccuracy() {
  return accuracy; 
}