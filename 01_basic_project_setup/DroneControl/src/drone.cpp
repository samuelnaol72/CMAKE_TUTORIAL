#include "drone.h"
#include <iostream>

void Drone::takeoff() {
#ifdef ENABLE_LOGGING
    std::cout << "[LOG] Drone taking off...\n";
#else
    std::cout << "Drone taking off...\n";
#endif
}

