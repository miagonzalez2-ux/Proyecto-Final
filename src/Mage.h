/**
 * @file Mage.h
 * @brief Manages the statistics for the player entity, once levelled up as mage.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include "Hero.h"

/**
 * @brief Namespace that manages the functions for the player entity, as a mage.
 * 
 */
namespace mage {
    /** 
     * @brief Class that represents the player entity, as a mage.
     * 
     * Manages the mage components of the player entity, as well as action functions for said player entity while in battle.
     */
    class Mage : public hero::Hero {
        public:
            /**
             * @brief Default Constructor for class Mage.
             * 
             * This function sets the default information for the player entity, as a mage.
             * 
             */
            Mage();
            /**
             * @brief Constructor for class Mage.
             * 
             * This function sets the default information for the mage player, specifically its username.
             * 
             * @param userName String variable that represents the player's username
             */
            Mage(std::string userName);

            /**
             * @brief Getter for the MANA of the player entity, as a mage.
             * 
             * This function allows the user to get the value stored in the variable for the
             * MANA of the player entity, as a mage.
             * 
             * @return Integer that represents the MANA of the player entity, as a mage.
             */
            int getMana() const {return mana;}
            /**
             * @brief Function for calculating the amount of mana used up by the player entity.
             * 
             * This function allows the user to calculate the amount of mana that will be used up by
             * the player entity during certain actions.
             * 
             * @param amount Integer variable representing the amount of mana that will be used up by player.
             */
            void useMana(int amount);
            /**
             * @brief Function that dictates how player uses smite against monster.
             * 
             * This function triples the amount of ATK damage the monster takes, validating if 
             * it can be used based off of stamina amount (has to be >5), mana amount (has to be >10),
             * and if smite hasn't been used already during battle.
             * 
             * @param monster baseM type variable, representing the monster entity and its components.
             */
            void smite(monsterB::baseM& monster);

            /**
             * @brief Function for getting the name of the player mode, overriding the use in parent class.
             * 
             * This function returns what level/mode the player is currently.
             * 
             * @return String of letters that represents the current state of the player entity.
             */
            std::string getClassName() const override {return "Mage";}
            /**
             * @brief Function for getting the options of action during battle, overriding its use in parent class.
             * 
             * This function returns what options the player can use during battle in its current level.
             * 
             * @return String of letters that represents the battle options.
             */
            std::string getActions() const override {return "[ATK/DEF/CHARGE/SMITE]";}
        private:
            /**
             * @brief Integer variable that represents the player's mana.
             */
            int mana;
            /**
             * @brief Bool variable that represents whether the player has used smite or not.
             */
            bool smiteUsed;
    };
}