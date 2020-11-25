// Class of player character
// Holds functions for actions the player can perform
//

#ifndef PLAYER_H
#define PLAYER_H

#include "enemy.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Enemy;
class Player
{

private:
    string name;           // Player may enter their name
    int playerHealth;      // Player health
    int playerDamage = 10; // Damage the player will do
    int inventoryMax;      // Maximum inventory space
    int attack; // Attack damage done by player, weapons may have own class
    int itemNumber = 0; // Allows increase in currentInventory
    int currentinventorysize = 0;
    // Make function for drop/use, this will decrease when completed
    int *oldinventory = NULL;
    int *inventory = NULL;
    vector <string> itemname; // a vector of strings for the names of the items

public:
    Player(); // Set player health and inventory size
    Player(string nameTemp);
    Player(const Player &other); // to copy over all of the player's information
    void returnHealth();         // Print out player health
    int getPlayerDamage(); // to get the player's damage
    int playerTakeDamage(Enemy &hi); // Removes enemy damage value from player health
    int getPlayerHealth();           // Returns remaining health of the player
    void returnInventory();          // Prints out inventory items
    void takeItemvalue( int item);         // Allows player to take an item
    void dropItem();                 // Allows player to drop items in their inventory
    string getName();                // Sets player name
    void takeItemname(string iteml);
    void useitem();
};

#endif