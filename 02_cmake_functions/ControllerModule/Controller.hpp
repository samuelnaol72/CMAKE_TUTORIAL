#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Sensor.hpp"

class Controller {
public:
    Controller(std::shared_ptr<Sensor> sensor);
    void start();
    void stop();
    void process();

private:
    std::shared_ptr<Sensor> _sensor;
    bool _running = false;
};
