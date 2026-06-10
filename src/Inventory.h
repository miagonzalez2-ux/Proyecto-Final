/**
 * @file Inventory.h
 * @brief Manages the inventory for the player entity.
 * @author Mia Gonzalez Ramirez
 * @date 2026-06-10
 */

#pragma once

#include <iostream>
#include <string>

/**
 * @brief Namespace that manages the functions for the player's inventory.
 * 
 */
namespace inventory {
    /** 
     * @brief Class that represents the inventory for the player entity.
     * 
     * Manages the inventory that the player entity holds.
     */
    class Inventory {
        public:
            /**
             * @brief Default Constructor for class Inventory.
             * 
             * This function sets the default value for the amount of orbs that the player entity has, and the default names for weapon and armor.
             * 
             */
            Inventory();
            /**
             * @brief Destructor for class Inventory.
             * 
             * This function allows deletion of dynamic variables in the class, specifically the register for orbs(a pointer).
             * 
             */
            ~Inventory();

            /**
             * @brief Getter for the name of weapon that the player entity holds.
             * 
             * This function allows the user to get the name stored in the variable for the name of the weapon the player entity holds.
             * 
             * @return String that represents the name of the weapon the player entity holds.
             */
            std::string getWpn() const {return weapon;}
            /**
             * @brief Getter for the name of armor that the player entity holds.
             * 
             * This function allows the user to get the name stored in the variable for the name of the armor the player entity holds.
             * 
             * @return String that represents the name of the armor the player entity holds.
             */
            std::string getArmr() const {return armor;}
            /**
             * @brief Getter for the amount of orbs that the player entity holds.
             * 
             * This function allows the user to get the value stored in the variable for amount of orbs that the player entity holds.
             * 
             * @return Integer that represents the number of orbs that the player entity holds.
             */
            int getOrbAmnt() const {return orbsAmount;}
            /**
             * @brief Setter for the player's weapon.
             * 
             * This function allows the user to set which weapon (by name) the player holds.
             * 
             * @param weapon String variable that represents the weapon's name.
             */
            void setWpn(std::string weapon) {this->weapon = weapon;}
            /**
             * @brief Setter for the player's armor.
             * 
             * This function allows the user to set which armor (by name) the player holds.
             * 
             * @param armor String variable that represents the armor's name.
             */
            void setArmr(std::string armor) {this->armor = armor;}
            /**
             * @brief Setter for the amount of orbs a player holds.
             * 
             * This function allows the user to set the amount of orbs being held.
             * 
             * @param orbsAmount Integer variable representing the number of orbs held at the moment.
             */
            void setOrb(int orbsAmount) {this->orbsAmount = orbsAmount;}
            /**
             * @brief Function to add orbs to inventory, by name.
             * 
             * This function allows the user to add orbs by verifying the current capacity of orbs (increasing it if necessary),
             *  registering the name of the item, and increasing the amount of current orbs held.
             * 
             * @param orbName String variable that represents the name of the item tracked, orbs.
             */
            void addOrb(std::string orbName);
            /**
             * @brief Function to print components of the player's inventory.
             * 
             * This function allows the user to get returned what is currently in the inventory, as strings.
             * 
             * @return Components of inventory in the form of strings.
             */
            std::string tostring() const {
                return "Inventory-> {Weapon: " + weapon + ", " 
                + "Armor: " + armor + ", " + "Orbs: " + std::to_string(getOrbAmnt()) + "}";}
        private:
            /**
             * @brief String variable to represent the weapon's name.
             */
            std::string weapon;
            /**
             * @brief String variable to represent the armor's name.
             */
            std::string armor;
            /**
             * @brief String pointer to represent register(current log) of orbs in inventory(by item name).
             */
            std::string* orbsTrack;
            /**
             * @brief Integer variable to represent the amount of orbs held currently.
             */
            int orbsAmount;
            /**
             * @brief Integer variable to represent the amount of orbs that can be currently held, in case of addition.
             */
            int orbsLmt;
    };
}