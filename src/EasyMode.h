/**
 * @file EasyMode.h
 * @brief Manages the turn restrictions for the easy game mode.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include <random>

/**
 * @brief Namespace that manages the functions for turn restrictions for easy game mode.
 * 
 */

namespace easy {
    /** 
     * @brief Class that represents the easy game mode.
     * 
     * Manages the number of turns restricted by the easy game mode.
     */ 
    class Easy {
        public:
            /**
             * @brief Default Constructor for class Easy.
             * 
             * This function sets the default (random) value for the amount of turns in easy game mode.
             * 
             */
            Easy();
            /**
             * @brief Constructor for class Easy.
             * 
             * This function randomly sets the initial value for the amount of turns in easy game mode.
             * 
             * @param maxTurn1 The integer that represents the amount of turns in the easy game mode.
             */
            Easy(int maxTurn1);
            /**
             * @brief Virtual destructor for class Easy.
             * 
             * This function allows (polymorphic) deletion for derived objects.
             * 
             */
            virtual ~Easy() = default;
            /**
             * @brief (Virtual) Getter for the amount of turns in this game mode.
             * 
             * This virtual function allows the user to get the value stored in the variable for 
             * amount of turns in the game mode, and may be used in derived classes.
             * 
             * @return Integer that represents the number of turns for the easy game mode.
             */
            virtual int getMAX() const {return maxTurn1;}
            /**
             * @brief Setter for the amount of turns in the easy game mode.
             * 
             * This function allows the user to set the value for the number of turns allowed in the easy game mode.
             * 
             * @param maxTurn1 The integer that represents the amount of turns in the easy game mode.
             */
            void setMAX(int max) {maxTurn1 = max;}
            /**
             * @brief (Virtual) Getter for the name of the game mode.
             * 
             * This function allows the user to get the name of the game mode, with the purpose of 
             * comparing and validating in what game mode the player is currently in.
             * 
             * @return String that represents the name of the game mode.
             */
            virtual std::string getModeName() const {return "Easy Mode";}
        protected:
            /**
             * @brief Integer number of turns available in the easy game mode.
             */
            int maxTurn1;
    };
}
