#include "EasyMode.h"

namespace easy {
    Easy::Easy() { // randomly generating the default value for number of turns
        std::random_device random;
        std::mt19937 gen(random());
        std::uniform_int_distribution<int> distrib(1,25);
        int random_num = distrib(gen);
        maxTurn1 = random_num;
    }

    Easy::Easy(int maxTurn1) { // randomly generating the number of turns that will be available in easy game mode
        std::random_device random;
        std::mt19937 gen(random());
        std::uniform_int_distribution<int> distrib(1,25);
        int random_num = distrib(gen);
        maxTurn1 = random_num;
    }
}