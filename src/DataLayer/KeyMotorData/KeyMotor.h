#pragma once

#include <QString>

class KeyMotor
{
public:
    KeyMotor();

    virtual ~KeyMotor();

    bool alive() const;
    double setCurrent() const;
    double setVelocity() const;
    double busCurrent() const;
    double busVoltage() const;
    double vehicleVelocity() const;

    void setAlive(bool alive);
    void setSetCurrent(double setCurrent);
    void setSetVelocity(double setVelocity);
    void setBusCurrent(double busCurrent);
    void setBusVoltage(double busVoltage);
    void setVehicleVelocity(double vehicleVelocity);

private:
    bool alive_;
    double setCurrent_;
    double setVelocity_;
    double busCurrent_;
    double busVoltage_;
    double vehicleVelocity_;
};
