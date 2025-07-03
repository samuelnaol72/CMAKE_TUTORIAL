#pragma once
#include <string>
#include <vector>

class Sensor {
public:
    Sensor(const std::string& name);
    virtual ~Sensor() = default;

    virtual void initialize();
    virtual std::vector<float> readData() = 0;  // pure virtual, must be overridden
    virtual void calibrate();

protected:
    std::string _name;
    bool _is_initialized = false;
};
