// Griffith Richter and Joseph McCann
// Final project
//

#include "Player.h"
#include "enemy.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string command; // User entered command
    string anothername;
    string choice;  // Choice when asked about item use
    int enemynumber = 1;    // Counts how many enemies are in the game

    Player user("");    // Player instance
    anothername = user.getName();// Sets user name
    cout << "Hello, " << anothername << "!" << endl;
    Enemy cool(enemynumber);    // Enemy instance
    cool.countenemy(enemynumber);
 
   
    
for (int i =1; i < enemynumber; i++)
{
    int x = i;
    //// Combat ////
   do{
       if (user.getPlayerHealth() > 0){ // Game will occur while the player has health
           cool.getenemy(i);
        cout << "Enemy health: " << cool.getEnemyHealth() << endl;
       }
       x++;
   }while (i == x);
   
    if (user.getPlayerHealth() <= 0)    // When the player dies, output a game over message
    {
        cout << "Game over! " << endl;
        break;
    }
   
    while (cool.getEnemyHealth() > 0 && user.getPlayerHealth() > 0) // Turns are allowed when either character has health
    {
       
        cout << "What will you do?" << endl;
        cout << "Available commands are 'A' for attack, 'I' for Inventory, and 'R' for running away. " << endl;
        cin >> command;
        if (command == "I")
        {
            user.returnInventory(); // Displays inventory
            continue;
        }
        else if (command == "R"){
            cool.getenemy(rand() % enemynumber + 1);    // Allows player to run away if they do not want to finish the fight
            continue;
        }
        else if (command == "A")
        {
            cout << "You hit the enemy for:" << user.getPlayerDamage() << endl; // Enemy takes damage
            cool.enemyTakeDamage(user);
        }
        else {
            cout << "Invalid command." << endl; // In case player enters invalid command
            continue;
        }
        cout << "Enemy attacks and hits you for:" << cool.getEnemyDamage() << endl; // Player takes damage
        user.playerTakeDamage(cool);
    }
    if (cool.getEnemyHealth() <= 0) // Display an enemy defeated message
    {
        cout << "Enemy defeated! " << endl;
        cool.enemyDie();
        cool.enemyDropItem(user);
        user.returnInventory();
    cout << "Would you like to use an item(say yes or no)" << endl; // User will have a chance to recover at the end of the round
                                                                    // If the player runs out of health as he defeats the enemy, he can use an item
                                                                    // This gives him a chance to return to the game if he is lucky
    cin >> choice;

    if (choice == "yes")
    {

        user.useitem();
    }

    
    
    }
}
    //// End combat ////

}