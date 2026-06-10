#include "PlayerBase.h"
#include "MonsterBase.h"

namespace playerB {
    baseP::baseP() : hp(20), atk(5), defending(false) {} //defaulting information for the player's base

    baseP::baseP(std::string userName) : user(userName), hp(20), atk(5), defending(false) {} //defaulting the player's name and other information

    void baseP::attack(monsterB::baseM& monster) {//dealing damage to monster entity
        std::cout << "<< " << user << " attacks! >>\n";
        monster.takeDmg(atk);
    }

    void baseP::defend() {//setting the player's defensive turn
        defending = true;
        std::cout << "<< " << user << " defends! >>\n";
    }

    void baseP::resetDef() {//resetting the player's defense to ensure it applies to only one turn at a time
        defending = false;
    }

    void baseP::takeDmg(int dmg) {//managing the player's statistics during the monster's turn (not taking damage if defending, taking damage otherwise)
        if (defending) {
            std::cout << "<< " << user << " has avoided the attack! >>\n";
        }
        else {//validating HP in case it goes below 0
            hp -= dmg;
            if (hp < 0) 
                hp = 0;
        }
    }
    
}