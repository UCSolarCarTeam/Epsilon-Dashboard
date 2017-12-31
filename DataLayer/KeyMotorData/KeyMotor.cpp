#include "KeyMotor.h"

KeyMotor::KeyMotor()
{
    alive_ = false;
    setCurrent_ = 0;
    setVelocity_ = 0;
    busCurrent_ = 0;
    busVoltage_ = 0;
    vehicleVelocity_ = 0;
}

KeyMotor::~KeyMotor()
{
}

bool KeyMotor::alive() const
{
    return alive_;
}
double KeyMotor::setCurrent() const
{
    return setCurrent_;
}
double KeyMotor::setVelocity() const
{
    return setVelocity_;
}
double KeyMotor::busCurrent() const
{
    return busCurrent_;
}
double KeyMotor::busVoltage() const
{
    return busVoltage_;
}
double KeyMotor::vehicleVelocity() const
{
    return vehicleVelocity_;
}

void KeyMotor::setAlive(bool alive)
{
    alive_ = alive;
}
void KeyMotor::setSetCurrent(double setCurrent)
{
    setCurrent_ = setCurrent;
}
void KeyMotor::setSetVelocity(double setVelocity)
{
    setVelocity_ = setVelocity;
}
void KeyMotor::setBusCurrent(double busCurrent)
{
    busCurrent_ = busCurrent;
}
void KeyMotor::setBusVoltage(double busVoltage)
{
    busVoltage_ = busVoltage;
}
void KeyMotor::setVehicleVelocity(double vehicleVelocity)
{
    vehicleVelocity_ = vehicleVelocity;
}
