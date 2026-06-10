#include "MonsterBase.h"
#include "PlayerBase.h"

namespace monsterB {
    baseM::baseM() : hp(15), atk(3), defending(false) { //randomly generating the name for the monster entity, when called
        std::string names[] = {"Goblin", "Slime", "Wolf", "Thief", "Centaur"};
        std::random_device random;
        std::mt19937 gen(random());
        std::uniform_int_distribution<int> distrib(0,4);
        name = names[distrib(gen)];

        drop = drops::Drops(1);
    } 

    void baseM::takeDmg(int dmg) {
        if (defending) { //enters loop if defending is true, and will only remain true for one turn exactly, tagging it as false (at the end of the loop)
            std::cout << "<< " << name << " has used SHIELD! 0 damage taken! >>\n";
            defending = false;
        }
        else { //when not defending, monster takes the <dmg> amount of damage, validating when it may get below 0
            hp -= dmg;
            if (hp < 0)
                hp = 0;
            std::cout << "<< " << name << " HP: " << hp << " >>\n";
        }
    }

    void baseM::takeTurn(playerB::baseP& player) { //calling the function takedmg during the monster's turn, when it attacks
        std::cout << "<< " << name << " attacks! >>\n";
        player.takeDmg(atk);
        std::cout << "<< " << player.getUser() << " HP: " << player.getHp() << " >>\n";
    }
}