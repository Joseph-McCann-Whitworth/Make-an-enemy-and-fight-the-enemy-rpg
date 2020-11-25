#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"


using namespace std;

class Player;
class Enemy
{

private:
    int enemycounter = 1; // a counter used for the file of an enemy to open
    int enemyHealth;      // Stores the enemy health
    int enemyAttack;      // Stores the enemy attack
    string enemyphrase = ""; // Stores enemy catchphrase
    string enemyname = ""; // Stores enemy name
    string drop;            // Stores the name of the enemy drop
    int restoreVal = 0;     // The value of each drop's effect

public:
    Enemy();
    Enemy(int counter); // Sets the number that keeps track of how many enemies there are
    int getEnemyDamage();
    int enemyTakeDamage(Player & person);     // Input: player instance
                                                // Output: the enemy health after being attacked by the player
    void getenemy(int num); // Gets the data of the enemies
    int getEnemyHealth();   // Returns enemy health based on the files provided
    string getenemydrop();  // Returns enemy item drop
    void getEnemyStats(fstream &file); // This will read the enemy file and use the data
    int enemyDie();                    // Function for when the enemy dies
    void enemyDropItem(Player &p);     // Enemy sends item to player inventory
    void countenemy(int & totalnumenemy);   // Counts how many enemy files there are
};
#endif