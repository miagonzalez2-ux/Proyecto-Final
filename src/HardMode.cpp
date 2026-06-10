#include "HardMode.h"

namespace hard {
    Hard::Hard() : medium::Medium() {
        maxTurn3 = maxTurn2 - 5;
        if(maxTurn3 < 3)
            maxTurn3 = 3;
    }

    int Hard::newMAX3(int maxTurn2, int& maxTurn3) {
        maxTurn3 = maxTurn2 - 5;
        return maxTurn3;
    }
}