#include "Controller.hpp"

Controller::Controller(std::shared_ptr<Sensor> sensor) : _sensor(sensor) {}

void Controller::start() {
    std::cout << "Controller starting." << std::endl;
    _sensor->initialize();
    _sensor->calibrate();
    _running = true;
}

void Controller::stop() {
    std::cout << "Controller stopping." << std::endl;
    _running = false;
}

void Controller::process() {
    if (!_running) {
        std::cerr << "Controller not running!" << std::endl;
        return;
    }

    auto data = _sensor->readData();
    std::cout << "Processing sensor data with " << data.size() << " values." << std::endl;
}
