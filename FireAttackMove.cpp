#include "FireAttackMove.h"

FireAttackMove::FireAttackMove(string _name, string _type, int _damage, int _accuracy) {
  // Assign the variable to the appropriate input
  this->name = _name; 
  this->type = _type; 
  this->damage = _damage; 
  this->accuracy = _accuracy; 
}

int FireAttackMove::getDamage() {
  //return damage so it can be accessed
  return damage; 
}

int FireAttackMove::getAccuracy() {
  //return accuracy so it can be accessed
  return accuracy; 
}