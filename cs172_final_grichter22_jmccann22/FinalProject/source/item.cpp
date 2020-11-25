#include "item.h"
#include "Player.h"
#include "enemy.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

item::item(string thing)
{

    name = thing;

}
void item::randomeffect()
{
   srand (time(NULL));
    random2 = rand() % 5 + 1;
   
    if (random2 == 1){
        healthboost = attribute;
    }
    if (random2 == 2){
        attackboost = attribute;
    }
    if(random2 == 3){
        healthboost = -attribute; // debuffs the player's health
    }
    if (random2 == 4){
        attackboost = -attribute; // debuffs the player's attack
    }
    if(random2 == 5){
        haboost = attribute;
    }

}
void item::randomvalue()    // Sets a random number for how much the decided statistic will be affected
{
    srand (time(NULL));
    random =  rand() % 5 + 1;
    
    if (random == 1){
        attribute = 10;
    }
    else if(random == 2){
        attribute = 15;
    }
    else if(random == 3){
       attribute = 20;
    }
    else if(random == 4){
        attribute = 25;
    }
    else if (random == 5)
    {
        attribute = 30;
    }
}
void item::assignitem(int & attack, int & health)   // Assigns the decided random values to the drop itself
{
    randomvalue();
    randomeffect();
    if(healthboost != 0)
    {
        health += healthboost;
        printitem();
    }
    else if(attackboost != 0)
    {
        attack += attackboost;
        printitem();
    }
    else if(haboost != 0)
    {
        attack += haboost;
        health += haboost;
        printitem();
    }
}
void item::printitem()  // Prints out the effect of the item so the player knows what it will do
{
    if(healthboost != 0)
    {
       cout << "The item:" << name << " is giving you:" << healthboost << " points to health." << endl;
    }
    else if(attackboost != 0)
    {
        
        cout << "The item:" << name << " is giving you:" << attackboost << " points to attack." << endl;
    }
    else if(haboost != 0)
    {
        cout << "The item:" << name << " is giving you:" << haboost << " points to attack and health." << endl;
    }
    
}