Griffith Richter and Joseph McCann
CS 172 Final Documentation

Purpose: Create a turn-based fighting game that allows users to create their own enemies. This allows users to change the game to suit their skill level without changing the core mechanics.
Requirements: We will need a “Player” and “Enemy” class. The player will be able to attack, take damage, take items, and check inventory contents. The enemy will attack, take damage, and drop items. We also need functions in “Enemy” that allow it to take statistics from a file. These statistics will be health, attack damage, name, item drop, and catchphrase. “Player” and “Enemy” will have to interact inside each other’s .cpp files. 
Assumptions: They would use the item they get immediately and a person wouldn’t fight the same enemy twice to have two of the same item.
UML Diagrams:
Class: 
Enemy
-int enemycounter 
    -int enemyHealth
    -int enemyAttack
    -string enemyphrase 
    -string enemyname 
    -string drop
    -int restoreVal

Enemy()
   Enemy(int counter)
   + int getEnemyDamage()
  +  int enemyTakeDamage(Player & person)
  +  void getenemy(int num)
   + int getEnemyHealth()
    +string getenemydrop()
   + void getEnemyStats(fstream &file)   +int enemyDie()
  +  void enemyDropItem(Player &p)     
   + void countenemy(int & totalnumenemy)

Data Members:
int enemycounter - a counter used for the file of an enemy to open
    int enemyHealth - Sets the enemy health
    int enemyAttack - Sets the enemy attack
    string enemyphrase  - To store the enemy’s catchphrase
    string enemyname – To store the enemy’s name
    string drop – to store the drop from the specific enemy
    int restoreVal – for the function in player to increase inventory size


Methods:
Enemy()- empty constructor
    Enemy(int counter)-constructor to take in the number of the enemy
    int getEnemyDamage() - returns the enemy damage
    int enemyTakeDamage(Player & person)- Returns enemy health after being attacked by player
    void getenemy(int num)-gets the enemy
    int getEnemyHealth()- gets the enemys health
    string getenemydrop()- gets the enemys drop
    void getEnemyStats(fstream &file)- This will read the enemy file and use the data
    int enemyDie()- Function for when the enemy dies
    void enemyDropItem(Player &p)-     // Enemy sends item to player inventory
    void countenemy(int & totalnumenemy)- counts the total number of enemys in the game










Class:
Player
- float capacity
- float temperature
- float currentLevel
- string liquidType
- int coolingTime
Player()
    Player(string nameTemp)
    Player(const Player &other)
    +void returnHealth()
    +int getPlayerDamage()
    +int playerTakeDamage(Enemy &hi) 
    +int getPlayerHealth()
    +void returnInventory()
    +void takeItemvalue( int item)
    +void dropItem()
    +string getName()
    +void takeItemname(string iteml)
    +void useitem()

Data Members:
string name-Player may enter their name
    int playerHealth- Player health
    int playerDamage - Damage the player will do
    int inventoryMax-Maximum inventory space
    int attack- Attack damage done by player, weapons may have own class
    int itemNumber- Allows increase in currentInventory
vector <string> itemname;  a vector of strings for the names of the items
    int currentinventorysize- keeps track of the inventory size
   
    int *oldinventory- a pointer for the inventory that will be deleted to copy over all previous items
    int *inventory- a pointer for the inventory that points to the current player's inventory



Methods:
Player()-  empty constructor. Set player health and inventory size
    Player(string nameTemp)- sets the name for the player 
    Player(const Player &other)- to copy over all of the player's information
    void returnHealth()- Print out player health
    int getPlayerDamage()- to get the player’s damage
    int playerTakeDamage(Enemy &hi)-Removes enemy damage value from player health
    int getPlayerHealth()- Returns remaining health of the player
    void returnInventory()- Prints out inventory items
    void takeItemvalue( int item)- Allows player to take an item
    void dropItem()- Allows player to drop items in their inventory
    string getName()- Sets player name
    void takeItemname(string iteml)- adds the item name to the vector string
    void useitem()- uses the item that the player wants to use





Class:
Item
-string name
-int random
-int random2
-int healthboost
-int attackboost
-int haboost
-int attribute

item(string thing)
+void randomeffect()
+void randomvalue()
+void assignitem(int & attack, int & health)
+void printitem()

Data Members
string name- name of the item
int random- random number for deciding value of the effect
int random- decides what the random effect is
int healthboost- stores how much health will be affected
int attackboost – stores how much attack will be affected
int haboost – health and attack can be boosted
int attribute- holds the value for buff/debuff


Methods:
item(string thing)- constructor. Takes in the item name
void randomeffect()- gives the item an random effect
void randomvalue()- gives the item an random value for the effect
void assignitem(int & attack, int & health)- assigns the item an attack and/or health buff and/or debuff
void printitem()- prints out what the item will do to the player’s stats



Manual: There will be a folder titled “Enemyfolder”. This contains the files with the enemy details. If you want to add or change enemies, add a file and title it “Enemy#” with the appropriate number instead of the #. The number you type after “Enemy” is the order in which you will encounter the enemies, so the first ones should be weaker. The program is fairly straightforward after that, and it will print out an instruction manual. I will still explain it here. The player may type “A” to attack the enemy. The player starts with an attack value of 10. The enemy will then attack, completing a turn cycle. The player can also type “I” to see what items they currently have. This does not take a turn. The user can type “R” to run from a fight if they believe they cannot defeat the enemy. If the player reduces the enemy health to 0, the next enemy will appear. If there is no following enemy file, the game will end. The game also ends if the player runs out of health. 

Works Cited:
http://www.cplusplus.com/reference/string/string/substr/  for substring
http://www.cplusplus.com/reference/string/stoi/  for string to int

