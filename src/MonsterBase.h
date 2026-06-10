/**
 * @file MonsterBase.h
 * @brief Manages the base statistics for the monster entity.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Drops.h"

/**
 * @brief Namespace (and class) that manages the functions for the player entity, with the purpose of forward declaration in this file.
 * 
 */
namespace playerB {class baseP;}

/**
 * @brief Namespace that manages the functions for the monster entity.
 * 
 */
namespace monsterB {
    /** 
     * @brief Class that represents the base for the monster entity.
     * 
     * Manages the base components of the monster entity, as well as action functions for the monster entity while in battle.
     */
    class baseM {
        public:
            /**
             * @brief Default Constructor for class baseM.
             * 
             * This function sets the default information for the monster entity.
             * 
             */
            baseM();
            /**
             * @brief Virtual destructor for class baseM.
             * 
             * This function allows (polymorphic) deletion for derived objects.
             * 
             */
            virtual ~baseM() = default;
        
            /**
             * @brief Getter for the HP of the monster entity.
             * 
             * This function allows the user to get the value stored in the variable for the
             * HP of the monster entity.
             * 
             * @return Integer that represents the HP of the monster entity.
             */
            int getHp() const {return hp;}
            /**
             * @brief Getter for the ATK of the monster entity.
             * 
             * This function allows the user to get the value stored in the variable for the
             * ATK of the monster entity, how much damage the monster can do.
             * 
             * @return Integer that represents the ATK of the monster entity.
             */
            int getAtk() const {return atk;}
            /**
             * @brief Getter for the name of the monster entity.
             * 
             * This function allows the user to get the string of letters stored in the variable for the
             * name of the monster entity.
             * 
             * @return String that represents the name of the monster entity.
             */
            std::string getName() const {return name;}
            /**
             * @brief Getter for the drops of the monster entity.
             * 
             * This function allows the user to get the drops of the monster entity.
             * 
             * @return Integer that represents the HP of the monster entity.
             */
            drops::Drops getDrops() const {return drop;}
            /**
             * @brief Validating function for the aliveness of the monster entity.
             * 
             * This function allows the user to validate whether the monster entity is alive (HP > 0) or not (HP = 0).
             * 
             * @return Bool variable that returns true when HP > 0 and returns false when HP = 0.
             */
            bool isAlive() const {return hp > 0;}
            /**
             * @brief Validating function for when the monster entity is defending.
             * 
             * This function allows the user to validate whether the monster entity is defending in their turn or not.
             * 
             * @return Bool variable that returns true for when monster is defending and returns false when it isn't.
             */
            bool isDefending() const {return defending;}

            /**
             * @brief Function for calculating the amount of damage that the monster entity will receive.
             * 
             * This function allows the user to calculate the amount of damage the monster will receive 
             * based off if it is defending itself or not, while it is the player's turn.
             * 
             * @param dmg Integer variable representing the amount of damage the monster will take.
             */
            void takeDmg(int dmg);
            /**
             * @brief (Virtual) Function for managing turns between the player and the monster entity, allowing it to be used by derived classes.
             * 
             * This function manages the monster's turn in attacking, specifically how the player will take damage.
             * 
             * @param player baseP type variable, representing the player entity and its components.
             */
            virtual void takeTurn(playerB::baseP& player);
            /**
             * @brief (Virtual) Function for managing the state the monster entity is in, allowing it to be used by child classes.
             * 
             * This function returns what state the monster is in currently, as a string.
             * 
             * @return String of letters that represents the current state of the monster entity.
             */
            virtual std::string getState() const {return "Normal";}
            /**
             * @brief Function for printing in a string of characters the monster's statistics.
             * 
             * This function returns the information regarding the monster entity, such as its name, HP, ATK, and amount of Cores, as strings.
             * 
             * @return String of letters that represents the current state of the monster entity.
             */
            std::string tostring() const {
                return "Monster-> {Name: " + name + ", "
                + "HP: " + std::to_string(getHp()) + ", "
                + "ATK: " + std::to_string(getAtk()) + ", "
                + "Core(s): " + std::to_string(drop.getCore()) + "}";
            }            
        protected:
            /**
             * @brief Integer number of HP that the monster entity has.
             */
            int hp;
            /**
             * @brief Integer number of ATK damage that the monster entity deals.
             */
            int atk;
            /**
             * @brief String variable for the name of the monster.
             */
            std::string name;
            /**
             * @brief Class combination to represent the drops, variable type Drops, that the monster holds.
             */
            drops::Drops drop;
            /**
             * @brief Bool variable to represent if the monster is defending or not.
             */
            bool defending;
    };
}