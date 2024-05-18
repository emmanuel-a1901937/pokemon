#include "FireAttackMove.h"

FireAttackMove::FireAttackMove(string _name, string _type, int _damage, int _accuracy) {
  this->name = _name; 
  this->type = _type; 
  this->damage = _damage; 
  this->accuracy = _accuracy; 
}

string FireAttackMove::getName() {
  return name; 
}

int FireAttackMove::getDamage() {
  return damage; 
}

int FireAttackMove::getAccuracy() {
  return accuracy; 
}