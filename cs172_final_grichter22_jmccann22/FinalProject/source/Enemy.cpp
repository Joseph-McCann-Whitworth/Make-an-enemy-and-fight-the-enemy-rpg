// Referenced http://www.cplusplus.com/reference/string/string/substr/ for substring
// Referenced http://www.cplusplus.com/reference/string/stoi/ for string to int

#include "Player.h"
#include "enemy.h"
#include "item.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
Enemy::Enemy()
{
}

Enemy::Enemy(int counter)
{

    enemycounter = counter;
}

void Enemy::getenemy(int num) // Finds the file of the enemy based on the decided number
                                // Will start with Enemy1, "run" command will choose a random enemy
{
    fstream hostile;    // Creates fstream instance
    string enemyname = "";  // Keep the enemy name empty until assigned
    string coolphrase = ""; // Keep the catchphrase empty until assigned
    hostile.open(".\\Enemyfolder\\Enemy" + to_string(num) + ".txt", ios::in); // Opens the enemy file according to what count is equal to
    if (hostile.fail())
    {
        cout << "Couldn't open enemy file" << endl;
    }
    else
    {
        cout << "Enemy has appeared!" << endl; // Confirms that the files have opened
    }
     // Increments the enemy number so the player can encounter the next one
                    // This will change the called file
    getEnemyStats(hostile);
}
void Enemy::countenemy(int & totalnumenemy) // Counts how many enemy files are in the folder
                                            // Will iterate through each file number until it does not find the next number in the sequence
{
     fstream count;
    do{
        count.open(".\\Enemyfolder\\Enemy" + to_string(totalnumenemy) + ".txt", ios::in);   
        if (count.fail())
        {
            break;
        }
         totalnumenemy++;   // Increases the total enemy file count
         count.close();     // Closes the current file
    }while(!count.fail());
   totalnumenemy--;         
}
void Enemy::getEnemyStats(fstream &file) // Gets the name, health, attack, and catchphrase of enemy
{

    string line;
    while (!file.eof())
    {
        getline(file, line);


        if (line.find("Name:") == 0)    // Gets the name of the enemy
        {

            cout << "Name: ";

            enemyname = line.substr(5);
            cout << enemyname << endl;
        }
        else if (line.find("Catchphrase:") == 0)    // Gets enemy catchphrase
        {
          
            enemyphrase = line.substr(12);
            cout << enemyphrase << endl;
        }

        else if (line.find("Attack:") == 0) // Gets enemy attack value
        {
            cout << "Enemy attack: ";
            enemyAttack = stoi(line.substr(7));
            cout << enemyAttack << endl;
        }

        else if (line.find("Drop:") == 0)   // Gets the name of the enemy drop, no values
        {
        
            drop = line.substr(5);
         
        }
        else if (line.find("Health:") == 0) // Gets the enemy health
        {
            enemyHealth = stoi(line.substr(7));

        }
    }
}

int Enemy::enemyTakeDamage(Player & person) // This will enable the enemy to take damage
                                            // It will take in the player's damage and subtract that from the enemy health
                                            // Returns health after it has been reduced
{
   
    enemyHealth -= person.getPlayerDamage();
    cout << "Enemy health remaining: " << enemyHealth << endl;
    return enemyHealth;
}
int Enemy::getEnemyHealth() // Returns enemy health 
{
    return enemyHealth;
}

int Enemy::getEnemyDamage() // Returns enemy damage
{
    return enemyAttack;
}

int Enemy::enemyDie() // When enemy dies, the counter will increase
                        // This will allow us to change the enemy after one  has been killed
{
    enemycounter++;
    return enemycounter;
}


void Enemy::enemyDropItem(Player &p)    // Sends the enemy item to player inventory when enemy is killed
{
   
    p.takeItemvalue(restoreVal);
    p.takeItemname(drop); 
}


string Enemy::getenemydrop()    // Gets the name of the enemy item
{
    return drop;
}