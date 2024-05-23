#include "Move.h"

string Move::getName() {
  return name; 
}

string Move::getType() {
  return type; 
}

// AttackMove child functions 
int Move::getDamage() {
  return -1; // will be implemented properly by child classes, if applicable (this function here just catches all calls to 'getDamage')
}

int Move::getAccuracy() {
  return -1; 
}

// DefendMove and StatusMove child functions
float Move::getAttackEffect() {
  return -1; 
}

float Move::getDefenceEffect() {
  return -1; 
}

float Move::getSpeedEffect() {
  return -1; 
}