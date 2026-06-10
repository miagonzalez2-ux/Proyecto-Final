#include "Drops.h"

namespace drops {
    Drops::Drops() : core(1) {} //defaulting the number of cores in monster drops, making sure there is atleast 1

    Drops::Drops(int core) { //randomly generating the amount of cores a monster will drop
        std::random_device random;
        std::mt19937 gen(random());
        std::uniform_int_distribution<int> distrib(1,4);
        int random_num = distrib(gen);
        this->core = random_num;
    }
}