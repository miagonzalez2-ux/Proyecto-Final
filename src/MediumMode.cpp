#include "MediumMode.h"

namespace medium {
    Medium::Medium() : easy::Easy() { //defaulting the number of turns for medium game mode, validating it does not go below 5
        maxTurn2 = maxTurn1 - 5;
        if (maxTurn2 < 5)
            maxTurn2 = 5;
    }

    int Medium::newMAX2(int maxTurn1, int& maxTurn2) { //setting the number of turns in medium game mode based off turns available in easy game mode
        maxTurn2 = maxTurn1 - 5;
        return maxTurn2;
    }
}