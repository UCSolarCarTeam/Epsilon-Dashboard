#include "LimitFlags.h"

LimitFlags::LimitFlags()
    : outputVoltagePwmLimit_(false)
    , motorCurrentLimit_(false)
    , velocityLimit_(false)
    , busCurrentLimit_(false)
    , busVoltageUpperLimit_(false)
    , busVoltageLowerLimit_(false)
    , ipmOrMotorTelemetryLimit_(false)
{
}

bool LimitFlags::outputVoltagePwmLimit() const
{
    return outputVoltagePwmLimit_;
}

bool LimitFlags::motorCurrentLimit() const
{
    return motorCurrentLimit_;
}

bool LimitFlags::velocityLimit() const
{
    return velocityLimit_;
}

bool LimitFlags::busCurrentLimit() const
{
    return busCurrentLimit_;
}

bool LimitFlags::busVoltageUpperLimit() const
{
    return busVoltageUpperLimit_;
}

bool LimitFlags::busVoltageLowerLimit() const
{
    return busVoltageLowerLimit_;
}

bool LimitFlags::ipmOrMotorTelemetryLimit() const
{
    return ipmOrMotorTelemetryLimit_;
}

void LimitFlags::setOutputVoltagePwmLimit(bool value)
{
    outputVoltagePwmLimit_ = value;
}

void LimitFlags::setMotorCurrentLimit(bool value)
{
    motorCurrentLimit_ = value;
}

void LimitFlags::setVelocityLimit(bool value)
{
    velocityLimit_ = value;
}

void LimitFlags::setBusCurrentLimit(bool value)
{
    busCurrentLimit_ = value;
}

void LimitFlags::setBusVoltageUpperLimit(bool value)
{
    busVoltageUpperLimit_ = value;
}

void LimitFlags::setBusVoltageLowerLimit(bool value)
{
    busVoltageLowerLimit_ = value;
}

void LimitFlags::setIpmOrMotorTelemetryLimit(bool value)
{
    ipmOrMotorTelemetryLimit_ = value;
}

