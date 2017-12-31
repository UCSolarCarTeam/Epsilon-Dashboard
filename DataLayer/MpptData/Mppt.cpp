#include "Mppt.h"

Mppt::Mppt()
{
}

Mppt::~Mppt()
{
}

bool Mppt::alive() const
{
    return alive_;
}
double Mppt::arrayVoltage() const
{
    return arrayVoltage_;
}
double Mppt::arrayCurrent() const
{
    return arrayCurrent_;
}
double Mppt::batteryVoltage() const
{
    return batteryVoltage_;
}
double Mppt::temperature() const
{
    return temperature_;
}

void Mppt::setAlive(bool alive)
{
    alive_ = alive;
}
void Mppt::setArrayVoltage(double arrayVoltage)
{
    arrayVoltage_ = arrayVoltage;
}
void Mppt::setArrayCurrent(double arrayCurrent)
{
    arrayCurrent_ = arrayCurrent;
}
void Mppt::setBatteryVoltage(double batteryVoltage)
{
    batteryVoltage_ = batteryVoltage;
}
void Mppt::setTemperature(double temperature)
{
    temperature_ = temperature;
}
