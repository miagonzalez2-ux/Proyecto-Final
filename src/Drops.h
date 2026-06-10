
/**
 * @file Drops.h
 * @brief Manages the drops that the monster entity holds.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include <random>

/**
 * @brief Namespace that manages the functions for the drops of the monster entity.
 * 
 */
namespace drops {
    /** 
     * @brief Class that represents the drops of the monster entity.
     * 
     * Manages the amount drops that the monster entity holds.
     */
    class Drops {
        public:
            /**
             * @brief Default Constructor for class Drops.
             * 
             * This function sets the default value (0) for the amount of cores that the monster entity has.
             * 
             */
            Drops();
            /**
             * @brief Default Constructor for class Drops.
             * 
             * This function randomly sets the value for the amount of cores that the monster entity has.
             * 
             */
            Drops(int core);
            /**
             * @brief Getter for the amount of cores that the monster entity has.
             * 
             * This function allows the user to get the value stored in the variable for amount of cores that the monster entity has.
             * 
             * @return Integer that represents the number of cores that the monster entity has.
             */
            int getCore() const {return core;}
            /**
             * @brief Setter for the amount of cores that the monster entity has.
             * 
             * This function allows the user to set the value for the number of cores that the monster entity has.
             * 
             * @param core The integer that represents the amount of cores that the monster entity has.
             */
            void setCore(int core) {this->core = core;}
        private:
            /**
             * @brief Integer number of cores that the monster entity has.
             */
            int core;
    };
}