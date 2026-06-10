#include "HardMode.h"

namespace hard {
    Hard::Hard() : medium::Medium() { //defaulting value for turns in hard mode, and validating it does not go below 3
        maxTurn3 = maxTurn2 - 5;
        if(maxTurn3 < 3)
            maxTurn3 = 3;
    }

    int Hard::newMAX3(int maxTurn2, int& maxTurn3) { //setting amount of turns in hard mode based off of turns in medium mode
        maxTurn3 = maxTurn2 - 5;
        return maxTurn3;
    }
}