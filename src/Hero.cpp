#include "Hero.h"
#include "MonsterBase.h"

namespace hero {
    Hero::Hero() : baseP() {//defaulting information for hero player entity
        hp = 30;
        atk = 8;
        stamina = 10;
        chargeUsed = false;
    }

    Hero::Hero(std::string userName) : baseP(userName) { //defaulting the username for the player, as a hero
        hp = 30;
        atk = 8;
        stamina = 10;
        chargeUsed = false;
    }

    void Hero::useStm(int amount) {//calculating the remaining stamina after use, validating if it goes below 0
        stamina -= amount;
        if (stamina < 0)
            stamina = 0;
    }

    void Hero::charge(monsterB::baseM& monster) { //managing the charge mechanic as a hero, validating if already used and if stamina is too low, then calculating damage to monster
        if (chargeUsed) {
            std::cout << "<< CHARGE has already been used in this battle! >>\n";
            return;
        }
        if (stamina < 3) {
            std::cout << "<< You don't have enough STAMINA! >>\n";
            return;
        }
        std::cout << "<< " << user << " uses CHARGE! >>\n";
        int cDmg = atk * 2;
        monster.takeDmg(cDmg);
        stamina -= 3;
        chargeUsed = true;
    }
}

