#pragma once

#include <QString>

class ErrorFlags
{
public:
    ErrorFlags();

    bool motorOverSpeed() const;
    bool softwareOverCurrent() const;
    bool dcBusOverVoltage() const;
    bool badMotorPositionHallSequence() const;
    bool watchdogCausedLastReset() const;
    bool configReadError() const;
    bool railUnderVoltageLockOut() const;
    bool desaturationFault() const;

    void setMotorOverSpeed(bool value);
    void setSoftwareOverCurrent(bool value);
    void setDcBusOverVoltage(bool value);
    void setBadMotorPositionHallSequence(bool value);
    void setWatchdogCausedLastReset(bool value);
    void setConfigReadError(bool value);
    void setRailUnderVoltageLockOut(bool value);
    void setDesaturationFault(bool value);

private:
    bool motorOverSpeed_;
    bool softwareOverCurrent_;
    bool dcBusOverVoltage_;
    bool badMotorPositionHallSequence_;
    bool watchdogCausedLastReset_;
    bool configReadError_;
    bool railUnderVoltageLockOut_;
    bool desaturationFault_;
};
