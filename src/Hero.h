/**
 * @file Hero.h
 * @brief Manages the statistics for the player entity, once levelled up as hero.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include "PlayerBase.h"

/**
 * @brief Namespace that manages the functions for the player entity, as a hero.
 * 
 */
namespace hero {
    /** 
     * @brief Class that represents the player entity, as a hero.
     * 
     * Manages the hero components of the player entity, as well as action functions for said player entity while in battle.
     */
    class Hero : public playerB::baseP {
        public:
            /**
             * @brief Default Constructor for class Hero.
             * 
             * This function sets the default information for the player entity, as a hero.
             * 
             */
            Hero();
            /**
             * @brief Constructor for class Hero.
             * 
             * This function sets the default information for the hero player, specifically its username.
             * 
             * @param userName String variable that represents the player's username
             */
            Hero(std::string userName);

            /**
             * @brief Getter for the STAMINA of the player entity, as a hero.
             * 
             * This function allows the user to get the value stored in the variable for the
             * STAMINA of the player entity, as a hero.
             * 
             * @return Integer that represents the STAMINA of the player entity, as a hero.
             */
            int getStm() const {return stamina;}

            /**
             * @brief Function for calculating the amount of stamina used up by the player entity.
             * 
             * This function allows the user to calculate the amount of stamina that will be used up by
             * the player entity during certain actions.
             * 
             * @param amount Integer variable representing the amount of stamina that will be used up by player.
             */
            void useStm(int amount);
            /**
             * @brief Function that dictates how player uses charge against monster.
             * 
             * This function double the amount of ATK damage the monster takes, validating if 
             * it can be used based off of stamina amount (has to be >3) and if charge hasn't been used already during battle.
             * 
             * @param monster baseM type variable, representing the monster entity and its components.
             */
            void charge(monsterB::baseM& monster);
            
            /**
             * @brief Function for getting the name of the player mode, overriding the use in parent class.
             * 
             * This function returns what level/mode the player is currently.
             * 
             * @return String of letters that represents the current state of the player entity.
             */
            std::string getClassName() const override {return "Hero";}
            /**
             * @brief Function for getting the options of action during battle, overriding its use in parent class.
             * 
             * This function returns what options the player can use during battle in its current level.
             * 
             * @return String of letters that represents the battle options.
             */
            std::string getActions() const override {return "[ATK/DEF/CHARGE]";}
        protected:
            /**
             * @brief Integer variable that represents the player's stamina.
             */
            int stamina;
            /**
             * @brief Bool variable that represents whether the player has used charge or not.
             */
            bool chargeUsed;
    };
}