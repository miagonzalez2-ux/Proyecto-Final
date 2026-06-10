#include "Inventory.h"

namespace inventory {
    Inventory::Inventory() {
        weapon = "SWORD";
        armor = "TUNIC";
        orbsLmt = 10;
        orbsAmount = 0;
        orbsTrack = new std::string [orbsLmt]; //creating dynamic array for orb register (tracking how many in inventory, by name)
    }

    Inventory::~Inventory() {
        delete[] orbsTrack; // deleting dynamic array for orb register
    }

    void Inventory::addOrb(std::string orbName) {
        if (orbsAmount >= orbsLmt) { //verifying if current number of orbs exceeds capacity, and increasing it for orb addition
            orbsLmt *= 2;
            std::string* newTrack = new std::string [orbsLmt]; // new and bigger dynamic array to store current orbs and make space for new ones
            for (int i = 0; i < orbsAmount; i++) {
                newTrack[i] = orbsTrack[i];
            }
            delete[] orbsTrack;
            orbsTrack = newTrack;
        }
        orbsTrack[orbsAmount] = orbName; //storing new orb with its respective item name, in the register;
        orbsAmount++;
    } 

}