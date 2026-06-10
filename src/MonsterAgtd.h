/**
 * @file MonsterAgtd.h
 * @brief Manages the statistics for the monster entity, in its agitated state.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include "MonsterBase.h"

/**
 * @brief Namespace that manages the functions for the monster entity, in its agitated state.
 * 
 */
namespace monsterA {
    /** 
     * @brief Class that represents the agitated state for the monster entity.
     * 
     * Manages the components of the agitated monster entity, as well as action functions used in battle.
     */
    class AgitatedM : public monsterB::baseM {
        public:
            /**
             * @brief Default Constructor for class AgitatedM.
             * 
             * This function sets the default information for the monster entity in its agitated state.
             * 
             */
            AgitatedM();

            /**
             * @brief Function that dictates when monster defends using shield.
             * 
             * This function sets <defending> as true when called, indicating that the monster will defend in that specific turn.
             * 
             */
            void shield();
            /**
             * @brief Function that dictates when monster uses ultimate against player.
             * 
             * This function double the amount of ATK damage the player takes.
             * 
             * @param player baseP type variable, representing the player entity and its components.
             */
            void ultimate(playerB::baseP& player);
            /**
             * @brief Function that dictates the monsters turn, overriding its parent's class use.
             * 
             * This function manages how the monster will behave during its turn, where there is a 50% chance it will either
             * use ultimate (double ATK damage) or shield (defends itself) once HP is below 15.
             * 
             * @param player baseP type variable, representing the player entity and its components.
             */
            void takeTurn(playerB::baseP& player) override;
            /**
             * @brief (Virtual) Function for managing the state the monster entity is in, overriding its use in the parent class.
             * 
             * This function returns what state the monster is in currently, as a string.
             * 
             * @return String of letters that represents the current state of the monster entity.
             */
            std::string getState() const override {return "Agitated";}
        
    };
}