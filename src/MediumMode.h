/**
 * @file MediumMode.h
 * @brief Manages the turn restrictions for the medium game mode.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include "EasyMode.h"

/**
 * @brief Namespace that manages the functions for turn restrictions for medium game mode.
 * 
 */
namespace medium {
    /** 
     * @brief Class that represents the medium game mode.
     * 
     * Manages the number of turns restricted by the medium game mode.
     */
    class Medium : public easy::Easy {
        public:
            /**
             * @brief Default Constructor for class Medium.
             * 
             * This function sets the default value (0) for the amount of turns in medium game mode.
             * 
             */
            Medium();
            /**
             * @brief Getter for the amount of turns in this game mode.
             * 
             * This function allows the user to get the value stored in the variable for 
             * amount of turns in this game mode, overriding the one used for the parent class.
             * 
             * @return Integer that represents the number of turns for the medium game mode.
             */
            int getMAX() const override {return maxTurn2;}
            /**
             * @brief Setter for the amount of turns in the medium game mode.
             * 
             * This function allows the user to set the value for the number of turns allowed in the medium game mode.
             * 
             * @param maxTurn2 The integer that represents the amount of turns in the medium game mode.
             */
            void setMAX(int max) {maxTurn2 = max;}
            /**
             * @brief Establishes the amount of turns allowed in medium game mode based on the amount of turns in easy game mode.
             * 
             * This function substracts 5 turns from the amount of turns in easy game mode.
             * 
             * @param maxTurn1, maxTurn2 The integer amount of turns for easy game mode, and the integer amount of turns, by reference, for medium game mode.
             * @return Integer that represents the number of turns for the medium game mode.
             */
            int newMAX2(int maxTurn1, int& maxTurn2);
            /**
             * @brief Getter for the name of the game mode.
             * 
             * This function allows the user to get the name of the game mode, with the purpose of comparing 
             * and validating in what game mode the player is currently in, overriding the one in parent class.
             * 
             * @return String that represents the name of the game mode.
             */
            std::string getModeName() const override {return "Medium Mode";}
        protected:
            /**
             * @brief Integer number of turns available in the medium game mode.
             */
            int maxTurn2;
    };
}