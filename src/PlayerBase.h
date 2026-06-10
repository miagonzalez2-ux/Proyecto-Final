/**
 * @file PlayerBase.h
 * @brief Manages the base statistics for the player entity.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include <string>
#include "Inventory.h"

/**
 * @brief Namespace (and class) that manages the functions for the monster entity, with the purpose of forward declaration in this file.
 * 
 */
namespace monsterB {class baseM;}

/**
 * @brief Namespace that manages the functions for the player entity.
 * 
 */
namespace playerB {
    /** 
     * @brief Class that represents the base for the player entity.
     * 
     * Manages the base components of the player entity, as well as action functions for the player entity while in battle.
     */
    class baseP {
        public:
            /**
             * @brief Default Constructor for class baseP.
             * 
             * This function sets the default information for the player entity.
             * 
             */
            baseP();
            /**
             * @brief Constructor for class baseP.
             * 
             * This function sets the default information for the player, specifically its username.
             * 
             * @param userName String variable that represents the player's username
             */
            baseP(std::string userName);
            /**
             * @brief Virtual destructor for class baseP.
             * 
             * This function allows (polymorphic) deletion for derived objects.
             * 
             */
            virtual ~baseP() = default;

            /**
             * @brief Getter for the HP of the player entity.
             * 
             * This function allows the user to get the value stored in the variable for the
             * HP of the player entity.
             * 
             * @return Integer that represents the HP of the player entity.
             */
            int getHp() const {return hp;}
            /**
             * @brief Getter for the ATK of the player entity.
             * 
             * This function allows the user to get the value stored in the variable for the
             * ATK of the player entity, how much damage the player can do.
             * 
             * @return Integer that represents the ATK of the player entity.
             */
            int getAtk() const {return atk;}
            /**
             * @brief Getter for the name of the player entity.
             * 
             * This function allows the user to get the string of letters stored in the variable for the
             * name of the player entity.
             * 
             * @return String that represents the name of the player entity.
             */
            std::string getUser() const {return user;}
            /**
             * @brief Getter for the inventory of the player entity.
             * 
             * This function allows the user to get the components of the player's inventory.
             * 
             * @return Inventory variable that represents the inventory held by the player.
             */
            inventory::Inventory& getInv() {return inv;}
            /**
             * @brief Validating function for the aliveness of the player entity.
             * 
             * This function allows the user to validate whether the player entity is alive (HP > 0) or not (HP = 0).
             * 
             * @return Bool variable that returns true when HP > 0 and returns false when HP = 0.
             */
            bool isAlive() const {return hp > 0;}
            /**
             * @brief Validating function for when the player entity is defending.
             * 
             * This function allows the user to validate whether the player entity is defending in their turn or not.
             * 
             * @return Bool variable that returns true for when player is defending and returns false when it isn't.
             */
            bool isDefending() const {return defending;}

            /**
             * @brief Setter for the player's HP.
             * 
             * This function allows the user to set the HP for the player.
             * 
             * @param hP Integer variable for the amount of HP the player has.
             */
            void setHp(int hP) {hp = hP;}
            /**
             * @brief Setter for the player's ATK.
             * 
             * This function allows the user to set the ATK for the player, how much damage they do.
             * 
             * @param aTK Integer variable for the amount of ATK damage the player deals.
             */
            void setAtk(int aTK) {atk = aTK;}
            /**
             * @brief Function for calculating the amount of damage that the player entity will receive.
             * 
             * This function allows the user to calculate the amount of damage the player will receive 
             * based off if it is defending itself or not, while it is the monster's turn.
             * 
             * @param dmg Integer variable representing the amount of damage the player will take.
             */
            void takeDmg(int dmg);

            /**
             * @brief (Virtual) Function for managing the attack the player deals to monster, allowing it to be used by derived classes.
             * 
             * This function manages the player's turn in attacking, specifically how the monster will take damage.
             * 
             * @param monster baseM type variable, representing the monster entity and its components.
             */
            virtual void attack(monsterB::baseM& monster);
            /**
             * @brief Function for managing what happens when a player defends itself in its turn.
             * 
             * This function manages the monster's turn in attacking, specifically how the player will take damage.
             * 
             */
            void defend();
            /**
             * @brief Function for resetting the defense mechanism for the player.
             * 
             * This function resets the defending state of the player to false, ensuring that defending itself only lasts for one turn.
             * 
             */
            void resetDef();
            /**
             * @brief (Virtual) Function for getting the name of the player mode, allowing it to be used by child classes.
             * 
             * This function returns what level/mode the player is currently.
             * 
             * @return String of letters that represents the current state of the player entity.
             */
            virtual std::string getClassName() const {return "Player";}
            /**
             * @brief (Virtual) Function for getting the options of action during battle, allowing it to be used by child classes.
             * 
             * This function returns what options the player can use during battle in its current level.
             * 
             * @return String of letters that represents the battle options.
             */
            virtual std::string getActions() const {return "[ATK/DEF]";}
            /**
             * @brief Function for printing in a string of characters the player's statistics.
             * 
             * This function returns the information regarding the player entity, such as its name, HP, ATK, and inventory, as strings.
             * 
             * @return String of letters that represents the player's components.
             */
            std::string tostring() const {
                return "Player-> {User: " + user + ", " 
                    + "HP: " + std::to_string(getHp()) + ", " 
                    + "ATK: " + std::to_string(getAtk()) + ", " 
                    + inv.tostring() + "}";}
        protected:
            /**
             * @brief String variable that represents the player's username.
             */
            std::string user;
            /**
             * @brief Integer variable that represents the player's HP.
             */
            int hp;
            /**
             * @brief Integer variable that represents the player's ATK damage, how much it can deal to monsters.
             */
            int atk;
            /**
             * @brief Inventory variable, as a composition of classes, that represents the player's inventory.
             */
            inventory::Inventory inv;
            /**
             * @brief Bool variable that represents whether the player is currently defending or not.
             */
            bool defending;
    };
}