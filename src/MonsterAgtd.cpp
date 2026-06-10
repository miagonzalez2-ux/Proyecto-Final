#include "MonsterAgtd.h"
#include "PlayerBase.h"

namespace monsterA {
    AgitatedM::AgitatedM() : baseM() {//setting the default statistics for the agitated state
        hp = 25;
        atk = 6;
    }

    void AgitatedM::takeTurn(playerB::baseP& player) {
        if (hp < 15) {//when HP is low, there is a 50% (0 or 1) chance that the monster will use ultimate, or use shield
            std::random_device random;
            std::mt19937 gen(random());
            std::uniform_int_distribution<int> distrib(0,1);
            int action = distrib(gen);
            if (action == 0) {
                ultimate(player);
                return;
            }
            else {
                shield();
                return;
            }
        }
        std::cout << "<< " << getName() << " attacks! >>\n";
        player.takeDmg(atk);
        std::cout << "<< " << player.getUser() << " HP: " << player.getHp() << " >>\n";
    }

    void AgitatedM::ultimate(playerB::baseP& player) { //doubling amount of damage ULTIMATE does on player
        int uDmg = getAtk() * 2;
        std::cout << "<< " << getName() << " uses ULTIMATE! >>\n";
        player.takeDmg(uDmg);
        std::cout << "<< " << player.getUser() << " HP: " << player.getHp() << " >>\n";
    }

    void AgitatedM::shield() { //validating the use of shield as a defense
        std::cout << "<< " << getName() << " uses SHIELD! >>\n";
        defending = true;
    }
}