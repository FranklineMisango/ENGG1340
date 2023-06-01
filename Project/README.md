# Comp2113G162

## Identification of the team members: 

We are group 162 and our members include 
1. Fong Hu Zi Zheng
2. Oyolo Frankline Misango
3. Tang Wai Shing
4. Yip Tsz Lun

## Description of your game and introduce the game rules:
Our group game is called alien.
This is a simple text-based game which gives you a spaceship to fight aliens. 
When the game started, you will encounter a random number of alien and you will receieve a spaceship which has a shield and health bar.
Your goal is to defeat the alien before they attack you and reduce your health to zero.
The aliens will attack you first and after that player and aliens will take turns to attack each other. 
In the aliens turn, they will first damage your shield and then your health when your shield is gone.
In the player turn, you can choose to attack the aliens with your ship, pause to recharge shield, save the game or surrender and quit the game.
If you choose to recharge or save game, you can choose to recharge shield and health, and resume the game or save the game.


### A list of features that you have implemented and explain how each coding
element 1 to 5 listed under the coding requirements aforementioned support
your features: 

We make use of all the requirements 1 to 5 including:
1. Generation of random game sets or events
2. Data structures for storing game status
3. Dynamic memory management
4. File input/output (e.g., for loading/saving game status)
5. Program codes in multiple files

and our coding supports them by
1. generateAliens(int& aliens) is included to generate a random value for the variables health, aliens and shield in the game. However, there a constant maximum value is set for each variable which ensures there is a limitation for the randomness. 
2. fstream is used to create a file thta saves the data in the game. Also, string is used in the game to send message to the player.
3. pointers (e.g. int* aliens) are used to dynamically allocate an interger array and assign its memory location to the pointer aliens
4. The functions, loadSavedGame() and saveGame(int health, int aliens, int shield) are one feature in our game which allows the player to save current game status and load previous game setup by using the File input/output in C++. When the player wants to load a saved game, the program will bring up the file (save_game.txt) in the main function so they can continue on the previous game.
5. An external program in quitProgram.h is used that gives the player to quit the game in each round which shows that program are coded in more than one files.

### A list of non-standard C/C++ libraries: 
The standard list do library we included are 
1. iostream
2. fstring
3. iostream
4. string
5. cstdlib
6. ctime
7. fstream

### Compilation and execution instructions. This serves like a "Quick start" of your
game: 
The compilation and execution procedure is list as the following
 
1. clone the github repository to your terminal by typing "git clone https://github.com/ZFMemo7/Comp2113G162.git" in the CLI
2. type in your github username and associated token / SSH code for access
3. Type "make" to compile all of the .cpp files into one single file called... ""
4. Enter a number from 1 to 3 to start a new game, load a saved game or quit the game.
5. After the game has started, the number of aliens, your health and shield value will be displayed.
6. After every round (alien has attacked you), you can enter a number from 1 to 3 to attack the alien with your ship, pause to recharge the ship, or surrender to it
6.1. If you choose to attack the alien: the program will display the damaged done to the aliens
6.2. If you choose to pause to recharge the ship: a menu and list of rule about the game will be displayed. Also the you will be given four options to fight the aliens, recharge resume game, save the current game or quit the game. 
6.2.1. fight the aliens: this option will bring you back to step 6.
6.2.2. recharge resume game: this option will give you updated shield and health values, leading you back to step 6.
6.2.3. save the game: this option will allow you to save current game status (e.g. health, sheild and numbers of alien).
6.2.4. quit the game: this option will get you to step 6.3.
6.3 If you choose to surrender to us: the program will output a gameover text and the text "Quitting the program..". This will save your game that can be accessed in the future
 7. Result will be revealed and the program brings you back to step 6.2 to continue a saved game, recharge resume game, save a game or quit the game.
