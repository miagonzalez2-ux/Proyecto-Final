/**
 * @file HardMode.h
 * @brief Manages the turn restrictions for the hard game mode.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include "MediumMode.h"

/**
 * @brief Namespace that manages the functions for turn restrictions for hard game mode.
 * 
 */
namespace hard {
    /** 
     * @brief Class that represents the hard game mode.
     * 
     * Manages the number of turns restricted by the hard game mode.
     */
    class Hard : public medium::Medium {
        public:
            /**
             * @brief Default Constructor for class Hard.
             * 
             * This function sets the default value (0) for the amount of turns in hard game mode.
             * 
             */
            Hard();
            /**
             * @brief Getter for the amount of turns in this game mode.
             * 
             * This function allows the user to get the value stored in the variable for 
             * amount of turns in this game mode, overriding the one used in parent class.
             * 
             * @return Integer that represents the number of turns for the hard game mode.
             */
            int getMAX() const override {return maxTurn3;}
            /**
             * @brief Setter for the amount of turns in the hard game mode.
             * 
             * This function allows the user to set the value for the number of turns allowed in the hard game mode.
             * 
             * @param maxTurn3 The integer that represents the amount of turns in the hard game mode.
             */
            void setMAX(int max) {maxTurn3 = max;}
            /**
             * @brief Establishes the amount of turns allowed in hard game mode based on the amount of turns in hard game mode.
             * 
             * This function substracts 5 turns from the amount of turns in hard game mode.
             * 
             * @param maxTurn2, maxTurn3 The integer amount of turns for medium game mode, and the integer amount of turns, by reference, for hard game mode.
             * @return Integer that represents the number of turns for the hard game mode.
             */
            int newMAX3(int maxTurn2, int& maxTurn3);
            /**
             * @brief Getter for the name of the game mode.
             * 
             * This function allows the user to get the name of the game mode, with the purpose of comparing 
             * and validating in what game mode the player is currently in, overriding the one in parent class.
             * 
             * @return String that represents the name of the game mode.
             */
            std::string getModeName() const override {return "Hard Mode";}
        private:
            /**
             * @brief Integer number of turns available in the hard game mode.
             */
            int maxTurn3;
    };
}