#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "enemy.h"

using namespace std;

class Player;
class Enemy;
class item{
private:
string name;    // Name of the dropped item
int random; // First random tracker to decide what the buff value will be
int random2; // Second random tracker to decide what buff / debuff effect will be activated
int healthboost = 0; // Stores the value of how much health will be affected
int attackboost = 0; // Stores value of how much attack will be affected
int haboost = 0; // gives an attack and a health boost
int attribute; // Stores the value of buff/debuff

public:

item(string thing); // Constructor
void randomeffect(); // gives the item an random effect
void randomvalue(); // gives the item an random value
void assignitem(int & attack, int & health); // Gives the item from file the attributes decided by above functions excluding the constructor
void printitem(); // Prints the item info

};








#endif