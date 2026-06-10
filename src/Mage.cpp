#include "Mage.h"
#include "MonsterBase.h"

namespace mage {
    Mage::Mage() : Hero() {//defaulting information for mage player
        hp = 40;
        atk = 12;
        stamina = 15;
        mana = 20;
        smiteUsed = false;
    }

    Mage::Mage(std::string userName) : Hero(userName) {//defaulting username for mage player
        hp = 40;
        atk = 12;
        stamina = 15;
        mana = 20;
        smiteUsed = false;
    }

    void Mage::useMana(int amount) { //calculating how much mana will be used up, and validating if it goes below 0
        mana -= amount;
        if (mana < 0)
            mana = 0;
    }

    void Mage::smite(monsterB::baseM& monster) {//managing the smite mechanism
        if (smiteUsed) {//validating if smite has already been used in battle
            std::cout << "<< SMITE has already been used in this battle! >>\n";
            return;
        }
        if (stamina < 5 || mana < 10) {//validating that smite can be used by player
            std::cout << "<< You don't have enough STAMINA or MANA! >>\n";
        }
        std::cout << "<< " << user << " uses SMITE! >>\n";
        int sDmg = atk * 3;//calculating how much smite damage the monster will take, and adjusting player amounts of stamina and mana
        monster.takeDmg(sDmg);
        stamina -= 5;
        mana -= 10;
        smiteUsed = true;
    }
}