#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

#include "EasyMode.h"
#include "MediumMode.h"
#include "HardMode.h"
#include "PlayerBase.h"
#include "Hero.h"
#include "Mage.h"
#include "MonsterBase.h"
#include "MonsterAgtd.h"

using namespace std;

//helper function for clearing screen during program
void clearScreen() {
    system("CLS");
}

//buffer for the player between certain options in the menu, to give time to choose
void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

//combat system function
bool combat(playerB::baseP* player, monsterB::baseM* monster, easy::Easy* mode) {//pointers to be able to use polymorphism of the classes
    int currentTurn = 1;
    int maxTurns = mode->getMAX();//setting max turns for easy mode

    while(player->isAlive() && monster->isAlive() && currentTurn <= maxTurns) {//combat engine while both entities alive
        cout << "\n----- TURN " << currentTurn << " -----\n";
        cout << "Monster: " << monster->getName() << " | HP: " << monster->getHp() << endl;
        cout << "Player: " << player->getUser() << " | HP: " << player->getHp() << endl;

        cout << "<< What will you do? >>\n" << player->getActions() << " >>\n";
        string choice;
        cin >> choice;

        //battle options for player, and results given if they are NOT valid in the moment
        if (choice == "ATK") {
            player->attack(*monster);
        }
        else if (choice == "DEF") {
            player->defend();
        }
        else if (choice == "CHARGE") {
            hero::Hero* h = dynamic_cast<hero::Hero*>(player);
            if (h) {//validating option if player is hero
                h->charge(*monster);
            }
            else {
                cout << "<< You are NOT a Hero yet! >>\n";
            }
        }
        else if (choice == "SMITE") {
            mage::Mage* m = dynamic_cast<mage::Mage*>(player);
            if (m) {//validating option if player is mage
                m->smite(*monster);
            }
            else {
                cout << "<< You are NOT a Mage yet! >>\n";
            }
        }
        else {//skipping turn for invalid action introduced
            cout << "<< Invalid Action! Your turn has been skipped!\n";
        }

        //checking if combat for current monster is donde
        if (!monster->isAlive())
            break;
        //moving over to monster's turn
        player->resetDef();
        monster->takeTurn(*player);

        currentTurn++;//adding turns for battle with current monster
    }

    if (!monster->isAlive()) { //once monster dies, cores get transformed into orbs, then added to player's inventory
        cout << "<< " << monster->getName() << " defeated! >>\n";
        int cores = monster->getDrops().getCore();
        for (int i = 0; i < cores; i++) {
            player->getInv().addOrb("Core Orb");
        }
        return true; //combat will continue to next monster
    }
    else if (!player->isAlive()) { //if player dies, all combat ends (game ends)
        cout << "<< You have been defeated! >>\n";
        return false;
    }
    else { //once player has ran out of turns, all combat ends (game ends)
        cout << "<< You have ran out of turns! You have retreated! >>\n";
        return false;
    }
}

//game system function
void game() {
    clearScreen();
    cout << "----- Monster Slaying -----\n";
    cout << "<< Welcome! Please enter your user: >>\n";
    string username;
    cin >> username;//getting player name

    cout << "<< Hello " << username << "! >>\n";
    cout << "<< Entering Easy Mode >>\n";

    playerB::baseP* player = new playerB::baseP(username);//creating player entity, and establishing easy mode
    easy::Easy* mode = new easy::Easy();

    int mDefeated = 0;
    bool gameRunning = true;//validating that game will continue

    while (gameRunning && player->isAlive()) {//game engine that runs while game is still running and player is alive
        monsterB::baseM* monster;//declaring monster entity, as pointer for polymorhpism use
        if (mode->getModeName() == "Hard Mode") {//creating monster entity in a specific state based off of current game mode
            monster = new monsterA::AgitatedM();
        }
        else {
            monster = new monsterB::baseM();
        }

        //printing player and monster statistics for player use
        cout << "\n" << player->tostring() << endl;
        cout << "----- Monster: " << monster->getName() << " -----\n";
        cout << "HP: " << monster->getHp() << endl;
        cout << "ATK: " << monster->getAtk() << endl;
        cout << "Core(s): " << monster->getDrops().getCore() << endl;

        bool won = combat(player, monster, mode);//setting combat with monster
        delete monster;//deleting monster after combat

        if (!won) { //when battle isn't won with monster (ran out of turns or player defeated), game stops running and leave game engine
            gameRunning = false;
            break;
        }

        mDefeated++; //adding to monsters defeated, for levelling it up purposes
        cout << "\n<< Defeated " << mDefeated << " Monster(s) >>\n";

        int orbs = player->getInv().getOrbAmnt();//getting player's orb amount to check if player can level up

        if (orbs >= 5 && player->getClassName() == "Player") { //player can level up to hero
            cout << "<< " << username << " has levelled up to HERO! >>\n";
            cout << "<< You may now use CHARGE, dealing double the amount of ATK! >>\n";

            int currentOrbs = player->getInv().getOrbAmnt();//transferring orbs from player(base) entity to new hero player entity
            hero::Hero* hero = new hero::Hero(username);
            for (int i = 0; i < currentOrbs; i++) {
                hero->getInv().addOrb("Core Orb");
            }
            delete player;
            player = hero;//making sure the player and hero are the same entity

            delete mode;
            mode = new medium::Medium();//moving up to next game mode
            cout << "<< Easy Mode: COMPLETED! >>\n";
            cout << "<< Now Entering: " << mode->getModeName() << " >>\n";
            cout << "<< You now have " << mode->getMAX() << " turns! >>\n";
        }

        else if (orbs >= 10 && player->getClassName() == "Hero") { //player can level up to mage
            cout << "<< " << username << " has levelled up to MAGE! >>\n";
            cout << "<< You may now use SMITE, dealing three times the amount of ATK! >>\n";

            int currentOrbs = player->getInv().getOrbAmnt();//transferring orbs from player entity to new mage entity
            mage::Mage* mage = new mage::Mage(username);
            for (int i = 0; i < currentOrbs; i++) {
                mage->getInv().addOrb("Core Orb");
            }
            delete player;
            player = mage;//making sure the player and mage are the same entity

            delete mode;
            mode = new hard::Hard();//moving up to next game mode
            cout << "<< Medium Mode: COMPLETED! >>\n";
            cout << "<< Now Entering: " << mode->getModeName() << " >>\n";
            cout << "<< You now have " << mode->getMAX() << " turns! >>\n";
            cout << "<< WARNING! Monsters can now use ULTIMATE and SHIELD at low HP! >>\n";
        }

        else if (orbs >= 15 && player->getClassName() == "Mage") {//player has finished game
            cout << "<< Hard Mode: COMPLETED! >>\n";
            cout << "<< You have finished Monster Slaying! CONGRATULATIONS! >>\n";
            gameRunning = false;
        }
    }
    delete player;
    delete mode;//deleting all dynamic variables during game run

    cout << "<< Want to play again? >> [Y/N]\n";//prompting to run game engine again
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        game();//recursion to be able to validate running the game engine again
    }
}

//printing player base
void playerEasy() {
    playerB::baseP* player = new playerB::baseP("USER");
    cout << "<< Name: " << player->getUser() << " >>\n";
    cout << "<< HP: " << player->getHp() << " >>\n";
    cout << "<< ATK: " << player->getAtk() << " >>\n";
    cout << "<< Inventory: " << player->getInv().getWpn() << ", " << player->getInv().getArmr() << " >>\n";
}

//printing hero base
void playerMedium() {
    hero::Hero* hero = new hero::Hero("USER");
    cout << "<< Name: " << hero->getUser() << " >>\n";
    cout << "<< HP: " << hero->getHp() << " >>\n";
    cout << "<< ATK: " << hero->getAtk() << " >>\n";
    cout << "<< STAMINA: " << hero->getStm() << " >>\n";
    cout << "<< Inventory: " << hero->getInv().getWpn() << ", " << hero->getInv().getArmr() << " >>\n";
}

//printing mage base
void playerHard() {
    mage::Mage* mage = new mage::Mage("USER");
    cout << "<< Name: " << mage->getUser() << " >>\n";
    cout << "<< HP: " << mage->getHp() << " >>\n";
    cout << "<< ATK: " << mage->getAtk() << " >>\n";
    cout << "<< STAMINA: " << mage->getStm() << " >>\n";
    cout << "<< MANA: " << mage->getMana() << " >>\n";
    cout << "<< Inventory: " << mage->getInv().getWpn() << ", " << mage->getInv().getArmr() << " >>\n";
}

int main() { //main function
    int option = 0;
    while(option != 5) {//menu for rpg simulator
        system("color 97");
        clearScreen();
        cout << "----- RPG SIMULATOR -----\n";
        cout << "1. Start New Game\n";
        cout << "2. View Player Base(Easy Mode)\n";
        cout << "3. View Hero Base(Medium Mode)\n";
        cout << "4. View Mage Base(Hard Mode)\n";
        cout << "5. Exit\n";
        cout << "Select an option (1,2,3,4,5): ";
        cin >> option;

        clearScreen();
        switch(option) {
            case 1: {//run game
                system("color D7");
                game();
                break;
            }
            case 2: {//showing the base player
                clearScreen();
                system("color C7");
                cout << "----- Player Base (Easy Mode) -----\n";
                playerEasy();
                waitForEnter();
                break;
            }
            case 3: {//showing the base hero
                clearScreen();
                system("color A7");
                cout << "----- Hero Base (Medium Mode) -----\n";
                playerMedium();
                waitForEnter();
                break;
            }
            case 4: {//showing the base mage
                clearScreen();
                system("color B7");
                cout << "----- Mage Base (Hard Mode) -----\n";
                playerHard();
                waitForEnter();
                break;
            }
            case 5: {//exit
                cout << "Goodbye!\n";
                break;
            }
            default : {//prompting user to introduce valid option
                cout << "Invalid Option! Please input a valid option.\n";
                waitForEnter();
            }
        }
    }
    return 0;
}