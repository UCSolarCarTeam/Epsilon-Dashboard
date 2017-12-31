#pragma once

#include <QString>

class LimitFlags
{
public:
    LimitFlags();

    bool outputVoltagePwmLimit() const;
    bool motorCurrentLimit() const;
    bool velocityLimit() const;
    bool busCurrentLimit() const;
    bool busVoltageUpperLimit() const;
    bool busVoltageLowerLimit() const;
    bool ipmOrMotorTelemetryLimit() const;

    void setOutputVoltagePwmLimit(bool value);
    void setMotorCurrentLimit(bool value);
    void setVelocityLimit(bool value);
    void setBusCurrentLimit(bool value);
    void setBusVoltageUpperLimit(bool value);
    void setBusVoltageLowerLimit(bool value);
    void setIpmOrMotorTelemetryLimit(bool value);

private:
    bool outputVoltagePwmLimit_;
    bool motorCurrentLimit_;
    bool velocityLimit_;
    bool busCurrentLimit_;
    bool busVoltageUpperLimit_;
    bool busVoltageLowerLimit_;
    bool ipmOrMotorTelemetryLimit_;
};
