#pragma once

#include <QString>

class Mppt
{
public:
    Mppt();

    virtual ~Mppt();

    bool alive() const;
    double arrayVoltage() const;
    double arrayCurrent() const;
    double batteryVoltage() const;
    double temperature() const;

    void setAlive(bool alive);
    void setArrayVoltage(double arrayVoltage);
    void setArrayCurrent(double arrayCurrent);
    void setBatteryVoltage(double batteryVoltage);
    void setTemperature(double temperature);

private:
    bool alive_;
    double arrayVoltage_;
    double arrayCurrent_;
    double batteryVoltage_;
    double temperature_;
};
