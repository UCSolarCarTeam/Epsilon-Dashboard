#include "ErrorFlags.h"

ErrorFlags::ErrorFlags()
    : motorOverSpeed_(false)
    , softwareOverCurrent_(false)
    , dcBusOverVoltage_(false)
    , badMotorPositionHallSequence_(false)
    , watchdogCausedLastReset_(false)
    , configReadError_(false)
    , railUnderVoltageLockOut_(false)
    , desaturationFault_(false)
{
}

bool ErrorFlags::motorOverSpeed() const
{
    return motorOverSpeed_;
}

bool ErrorFlags::softwareOverCurrent() const
{
    return softwareOverCurrent_;
}

bool ErrorFlags::dcBusOverVoltage() const
{
    return dcBusOverVoltage_;
}

bool ErrorFlags::badMotorPositionHallSequence() const
{
    return badMotorPositionHallSequence_;
}

bool ErrorFlags::watchdogCausedLastReset() const
{
    return watchdogCausedLastReset_;
}

bool ErrorFlags::configReadError() const
{
    return configReadError_;
}

bool ErrorFlags::railUnderVoltageLockOut() const
{
    return railUnderVoltageLockOut_;
}

bool ErrorFlags::desaturationFault() const
{
    return desaturationFault_;
}

void ErrorFlags::setMotorOverSpeed(bool value)
{
    motorOverSpeed_ = value;
}

void ErrorFlags::setSoftwareOverCurrent(bool value)
{
    softwareOverCurrent_ = value;
}

void ErrorFlags::setDcBusOverVoltage(bool value)
{
    dcBusOverVoltage_ = value;
}

void ErrorFlags::setBadMotorPositionHallSequence(bool value)
{
    badMotorPositionHallSequence_ = value;
}

void ErrorFlags::setWatchdogCausedLastReset(bool value)
{
    watchdogCausedLastReset_ = value;
}

void ErrorFlags::setConfigReadError(bool value)
{
    configReadError_ = value;
}

void ErrorFlags::setRailUnderVoltageLockOut(bool value)
{
    railUnderVoltageLockOut_ = value;
}

void ErrorFlags::setDesaturationFault(bool value)
{
    desaturationFault_ = value;
}

