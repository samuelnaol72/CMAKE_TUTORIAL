#include "Sensor.hpp"
#include <iostream>

Sensor::Sensor(const std::string& name) : _name(name) {}

void Sensor::initialize() {
    std::cout << "Initializing sensor: " << _name << std::endl;
    _is_initialized = true;
}

void Sensor::calibrate() {
    if (!_is_initialized) {
        std::cerr << "Sensor not initialized, cannot calibrate!" << std::endl;
        return;
    }
    std::cout << "Calibrating sensor: " << _name << std::endl;
}
