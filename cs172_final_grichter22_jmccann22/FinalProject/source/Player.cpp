// Implementation of player class

#include "Player.h"
#include "enemy.h"
#include "item.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player()
{
    name = "";
    playerHealth = 100; // Starts the player with full health
    inventoryMax = 7;   // Subject to change
                        // Sets space for player to carry items
}

Player::Player(string nameTemp)
{
    name = nameTemp;
    playerHealth = 100; // Starts the player with full health
    inventoryMax = 7;   // Subject to change
                        // Sets space for player to carry items
}

Player::Player(const Player &other)
{
    playerHealth = other.playerHealth;
    inventory = other.inventory;
    inventory = new int[itemNumber];
    for (int i = 0; i < itemNumber; i++)
    {
        inventory[i] = other.inventory[i];
    }
}
void Player::returnHealth()
{ // Displays health
    cout << "Current health: " << playerHealth << endl;
}

void Player::returnInventory()
{
   
    cout << "Inventory space remaining: " << inventoryMax - currentinventorysize << endl; // Shows how much space is in inventory
    cout << "Items in inventory: ";                                             // Displays items in inventory
    for (int i = 0; i < currentinventorysize; i++)
    {
        cout << itemname.at(i) <<  ", ";
    }
    cout << endl;
}

void Player::takeItemvalue(int item)
{
if (currentinventorysize <= 7)
{
    int *newinventory = new int[itemNumber + 1];    // Puts the value in the player inventory
    delete[] inventory;
    inventory = newinventory;
    inventory[itemNumber] = item;
    itemNumber++;
    currentinventorysize++;
}
    else 
    {
        cout << "Inventory is full" << endl;
    }
}
void Player::takeItemname(string iteml) // Puts item name in inventory
{
    itemname.push_back(iteml);
}

string Player::getName()    // Takes in player entered name
{
    cout << "What is your name?" << endl;
    cin >> name;
    return name;
}
void Player::useitem()
{
    string use; // What the player wants to use
    cout << "What item would you like to use?" << endl;
cin >> use;
item used(use);
used.assignitem(playerDamage,playerHealth);

currentinventorysize--; // Removes the item from the inventory
    
}
int Player::getPlayerDamage()
{

    return playerDamage;
}


int Player::playerTakeDamage(Enemy & hi)    // Subtracts enemy damage from player health
{
    playerHealth -= hi.getEnemyDamage();
    cout << "Your health remaining: " << playerHealth << endl;
    return playerHealth;
}

int Player::getPlayerHealth()
{

    return playerHealth;
}