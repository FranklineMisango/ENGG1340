//Declaring the Functions to use
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "quitProgram.h"

using namespace std;

// Constants
const int MAX_ALIENS = 30; // Maximum number of aliens
const int MAX_HEALTH = 100; // Our health can only be 100 bars
const int MAX_SHIELD = 50; //Shield status can only be 50
const int MIN_HEALTH = 50; //The Minimum health generation should be 40
const int MIN_SHIELD = 25; // The Minimum Random generation for shields < 25
const int MIN_ALIENS = 10; //The Minimum Aliens we can generate for the random function is 10
const int SHIP_HEALTH = 100; // Initial health of the ship
const int ALIEN_DAMAGE = 10; // Damage caused by each alien on shields
const int HEALTH_PLAY_DAMAGE = 5; //Small damage cause despite our shields
const int HEALTH_DAMAGE = 20; // The Damage Aliens can cause to our ship if we are out of shields
const int SHIELD_CHARGE = 25; // Shield recharge amount
const int ALIEN_CHARGE = 10; // Alien recharge half as max. no of aliens
const int HEALTH_CHARGE = 25; // Shield recharge amount
const string SAVE_FILE = "save_game.txt"; // Save file name 

// Function prototypes
void readRules();
void newGame();
void loadSavedGame();
void saveGame(int health, int aliens, int shield);
void generateAliens(int& aliens);
int fightAliens(int& health, int& shield, int& aliens);
int playGame(int& health, int& shield, int& aliens);
void alienAttack(int& health, int& shield);
void shipAttack(int& health, int& aliens);

//The main function 
int main() {
    cout << "==========================" << endl;
    cout << "Welcome to Ships vs Aliens!" << endl;
    int choice;
    do {
        cout << endl;
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Read The Rules" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                newGame();
                break;
            case 2:
                loadSavedGame();
                break;
            case 3:
                readRules();
                // Wait for user to acknowledge the rules before continuing
                cout << "Press any key to return to the menu...";
                cin.ignore(); // Ignore the previous newline character in the input stream
                cin.get(); // Wait for user to press a key
                break;
            case 4:
                cout << "Goodbye!" << endl;
                quitProgram();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

//Function to Access the rules
void readRules(){
    cout << "------------------------------------Rules Scroll-----------------------------------------------------" << endl;
    cout << "| 1.In Main Menu , Enter a number from 1 to 3 to start a new game, load a saved game or quit the game|" <<endl;
    cout << "| 2.After the game has started, the number of aliens, your health and shield value will be displayed.|" <<endl;
    cout << "| 3.After First round where aliens attack you first, You enter the dialogue controlled by Aliens.....|" <<endl;
    cout << "| 4.In this dialogue, You can either continue attacking, pause to follow their advice or surrender...|" <<endl;
    cout << "| 5.If you choose to attack, The aliens killed will be displayed and also damage your ship incurs....|" <<endl;
    cout << "| 6.If you choose to surrender, You will be captured and Game Over displayed.........................|" <<endl;
    cout << "| 7.If You Pause, You can either Recharge & Resume Game, save the game or quit the Game..............|" <<endl;
    cout << "| 8.If You Recharge & Resume, Your health bars and shields will increase, & the aliens will multiply.|" <<endl;
    cout << "| 9.While in the Dialogue Menu, You can keep playing & acting accordingly until you win..............|" <<endl;
    cout << "| 10.If you load a game, You will be redirected to the pause menu where you can do as you please.....|" <<endl;
    cout << "------------------------------------Rules Scroll-----------------------------------------------------" << endl;
    
}

// Loads a saved game
void loadSavedGame() {
    cout <<"Loading a Saved Game...."<<endl;
    cout <<"Redirecting to the Menu for continuation" <<endl;
    int health, aliens, shield;
    ifstream infile(SAVE_FILE);
    if (!infile) {
        cout << "Error loading saved game. No saved game found." << endl;
        return;
    }
    infile >> health >> aliens >> shield;
    infile.close();
    cout << "The saved game had " << health << " Health bar(s) , " << shield << " shield(s)" << "and " << aliens << " Remaining alien(s)" << endl;
    playGame(health, shield, aliens);
}

// Saves the current game status
void saveGame(int health, int aliens, int shield) {
    ofstream outfile(SAVE_FILE);
    if (!outfile) {
        cout << "Error saving The game. Cannot create save file." << endl;
        return;
    }
    outfile << health << " " << aliens << " " << shield << endl;
    outfile.close();
}

// Generates random number of aliens
void generateAliens(int& aliens) {
    srand(time(NULL));
    aliens = rand() % MAX_ALIENS + 1;
    cout << "You have encountered " << aliens << " alien(s)!" << endl;
}

// The Alien Dialogue
int fightAliens(int& health, int& shield, int& aliens) {
    while (aliens > 0 && health > 0) {
        cout << endl;
        cout << "*We Aliens Now control the Dialogue*" << endl;
        cout << "===       Alien Encounter        ===" << endl;
        cout << "Your ship has " << health << " health bars and " << shield << " shield(s)." << endl;
        cout << "We are now " << aliens << " alien(s) remaining." << endl;
        if (shield <= 0) {
             cout <<"**|----------------------------WARNING---------------------------------|**" << endl;
             cout <<"**|WARNING You have 0 shields, You can click Pause to Access Recharge..|**" << endl;
             cout <<"**|However, If you Recharge, Be warned.................................|**" << endl;
             cout <<"**|We will also Multiply and give you a challenge!.....................|**" << endl;
             cout <<"**|----------------------------WARNING---------------------------------|**" << endl;
        }
        cout << "1. Attack us with your ship" << endl;
        cout << "2. Pause to Recharge or save" << endl;
        cout << "3. Surrender to us" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                shipAttack(health, aliens);
                if (aliens > 0) {
                    alienAttack(health, shield);
                    break;
                }
                if (aliens <= 0) {
                break; // return 1 to indicate victory
                }
            case 2:
                playGame(health, shield, aliens);
                break;
            case 3:
                cout << "You have surrendered to the aliens. Game over." << endl;
                quitProgram(); // quit the function when user selects option 2
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue; // continue with the loop to ask the user for input again
}

    }
    if (health <= 0) {
        cout << "Your ship has been Captured as by the aliens. Your remaining health bars are " << health << ". The Game is over." << endl;
        quitProgram();
    }
    return 0;
}

// Attacking Alien ship
//The logic here is aliens decrease with our ship damage
void shipAttack(int& health, int& aliens) {
    int damage = HEALTH_DAMAGE;
    if (aliens < 3) {
        damage *= 2;
    }
    aliens -= damage / ALIEN_DAMAGE; //Aliens should reduce by 2 
    cout << "After your attack on us, we have reduced to " << aliens << " alien(s)" <<endl;
}

// Attacks the ship 
void alienAttack(int& health, int& shield) {
    int damage = ALIEN_DAMAGE;
    if (shield > 0) {
        if (shield >= damage) {
            shield -= damage;
            health -= HEALTH_PLAY_DAMAGE;
        } else {
            damage -= shield;
            shield = 0; // Shields here are Negative
            health -= damage;
        }
    }
    else {
        health -= HEALTH_DAMAGE; //Here is if you have no shields at all
    } 
    if (health <= 0) {
        cout << "Your ship's Health has been destroyed by the alien(s). Game over." << endl;
        quitProgram();
    }
    
    cout << "The alien(s) attack your ship and wipe " << ALIEN_DAMAGE << " shield(s)." << endl;
    cout << "After the alien(s) attack, your health bars have reduced to " << health << endl;
    cout << "Your ship now has " << health << " healthy bars and " << shield << " shield(s) remaining." << endl;
}


// Loads the game status from a file
void loadGame(int& health, int& aliens, int& shield) {
    ifstream infile("savegame.txt");
    infile >> health;
    infile >> aliens;
    infile >> shield;
    infile.close();
    cout << "Importing the saved game attributes from the savegame.txt..Redirecting to Playing the Game" <<endl;
    fightAliens(health, shield,aliens);
}

// Generates initial game status
void generateGameStatus(int& health, int& aliens, int& shield) {
    srand(time(NULL));
    health = rand() % (MAX_HEALTH - MIN_HEALTH + 1) + MIN_HEALTH;
    shield = rand() % (MAX_SHIELD - MIN_SHIELD + 1) + MIN_SHIELD;
    aliens = rand() % MAX_ALIENS + 1;
    cout << "Your ship starts with " << health << " health bars and " << shield << " shield(s)." << endl;
    cout << "You have encountered " << aliens << " aliens!" << endl;
}

int playGame(int& health, int& shield, int& aliens) {
    int choice;
    do {
        cout <<"=== Game Menu ===" << endl;
        cout <<"===  Rules    ===" <<endl;
        cout <<" --------------------------------------------------------------------------------------- " <<endl;
        cout <<" |If you are here because you paused, You can ONLY click : 2 , 3 and 4                 |" << endl;
        cout <<" |If you are here because you generated a saved game , You can do as you wish !        |"<<endl;
        cout <<" |If you are here because you Won the Game , Congrats ! Click 4 and start New Game     |"<<endl;
        cout <<" --------------------------------------------------------------------------------------- "<<endl;
        cout << "1. Continue the Saved Game !" << endl;
        cout << "2. Recharge and Resume Game" << endl;
        cout << "3. Save Game" <<endl;
        cout << "4. Read Rules" <<endl;
        cout << "5. Quit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                if (aliens <= 0) {
                    cout << "There Were no aliens to fight in the saved game. Quit and start New Game" << endl;
                    quitProgram();
                } else {
                    fightAliens(health, shield, aliens);
                    break;
                }
                break;
            case 2:
                shield = shield + SHIELD_CHARGE;
                aliens = aliens + ALIEN_CHARGE;
                health = health + HEALTH_CHARGE;
                cout << "Shields Boosted to " << shield << "." << endl;
                cout << "Health bars increased to " << health << "." << endl;
                cout << "Aliens Increased to " << aliens << endl;
                fightAliens(health, shield, aliens);
                break;
            case 3:
                saveGame(health, aliens, shield);
                cout << "Game saved successfully." << endl;
                break;
            case 4:
                readRules();
                // Wait for user to acknowledge the rules before continuing
                cout << "Press any key to return to the Alien Dialogue menu...";
                cin.ignore(); // Ignore the previous newline character in the input stream
                cin.get(); // Wait for user to press a key
                break;
            case 5:
                quitProgram();
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}

// Starts a new game
void newGame() {
    cout << "Starting a new game..." << endl;
    int health, aliens, shield;
    generateGameStatus(health, aliens, shield);
    while (aliens > 0 && health > 0) {
        alienAttack(health, shield);
        if (aliens > 0) {
            fightAliens(health, shield, aliens);
        }
    }
    if (health > 0) {
        cout << "Congratulations! You have defeated all the aliens and saved the universe!" << endl;
    }
    cout << "Your game is being saved" << endl;
    saveGame(health, aliens, shield);
}