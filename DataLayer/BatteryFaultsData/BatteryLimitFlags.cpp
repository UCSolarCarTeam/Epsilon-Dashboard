#include "BatteryLimitFlags.h"

BatteryLimitFlags::BatteryLimitFlags()
    : dclReducedDueToLowSoc_(false)
    , dclReducedDueToHighCellResistance_(false)
    , dclReducedDueToTemperature_(false)
    , dclReducedDueToLowCellVoltage_(false)
    , dclReducedDueToLowPackVoltage_(false)
    , dclandCclReducedDueToVoltageFailsafe_(false)
    , dclandCclReducedDueToCommunicationFailsafe_(false)
    , cclReducedDueToHighSoc_(false)
    , cclReducedDueToHighCellResistance_(false)
    , cclReducedDueToTemperature_(false)
    , cclReducedDueToHighCellVoltage_(false)
    , cclReducedDueToHighPackVoltage_(false)
    , cclReducedDueToChargerLatch_(false)
    , cclReducedDueToAlternateCurrentLimit_(false)
{
}

bool BatteryLimitFlags::dclReducedDueToLowSoc() const
{
    return dclReducedDueToLowSoc_;
}

void BatteryLimitFlags::setDclReducedDueToLowSoc(bool dclReducedDueToLowSoc)
{
    dclReducedDueToLowSoc_ = dclReducedDueToLowSoc;
}

bool BatteryLimitFlags::dclReducedDueToHighCellResistance() const
{
    return dclReducedDueToHighCellResistance_;
}

void BatteryLimitFlags::setDclReducedDueToHighCellResistance(bool dclReducedDueToHighCellResistance)
{
    dclReducedDueToHighCellResistance_ = dclReducedDueToHighCellResistance;
}

bool BatteryLimitFlags::dclReducedDueToTemperature() const
{
    return dclReducedDueToTemperature_;
}

void BatteryLimitFlags::setDclReducedDueToTemperature(bool dclReducedDueToTemperature)
{
    dclReducedDueToTemperature_ = dclReducedDueToTemperature;
}

bool BatteryLimitFlags::dclReducedDueToLowCellVoltage() const
{
    return dclReducedDueToLowCellVoltage_;
}

void BatteryLimitFlags::setDclReducedDueToLowCellVoltage(bool dclReducedDueToLowCellVoltage)
{
    dclReducedDueToLowCellVoltage_ = dclReducedDueToLowCellVoltage;
}

bool BatteryLimitFlags::dclReducedDueToLowPackVoltage() const
{
    return dclReducedDueToLowPackVoltage_;
}

void BatteryLimitFlags::setDclReducedDueToLowPackVoltage(bool dclReducedDueToLowPackVoltage)
{
    dclReducedDueToLowPackVoltage_ = dclReducedDueToLowPackVoltage;
}

bool BatteryLimitFlags::dclandCclReducedDueToVoltageFailsafe() const
{
    return dclandCclReducedDueToVoltageFailsafe_;
}

void BatteryLimitFlags::setDclandCclReducedDueToVoltageFailsafe(bool dclandCclReducedDueToVoltageFailsafe)
{
    dclandCclReducedDueToVoltageFailsafe_ = dclandCclReducedDueToVoltageFailsafe;
}

bool BatteryLimitFlags::dclandCclReducedDueToCommunicationFailsafe() const
{
    return dclandCclReducedDueToCommunicationFailsafe_;
}

void BatteryLimitFlags::setDclandCclReducedDueToCommunicationFailsafe(bool dclandCclReducedDueToCommunicationFailsafe)
{
    dclandCclReducedDueToCommunicationFailsafe_ = dclandCclReducedDueToCommunicationFailsafe;
}

bool BatteryLimitFlags::cclReducedDueToHighSoc() const
{
    return cclReducedDueToHighSoc_;
}

void BatteryLimitFlags::setCclReducedDueToHighSoc(bool cclReducedDueToHighSoc)
{
    cclReducedDueToHighSoc_ = cclReducedDueToHighSoc;
}

bool BatteryLimitFlags::cclReducedDueToHighCellResistance() const
{
    return cclReducedDueToHighCellResistance_;
}

void BatteryLimitFlags::setCclReducedDueToHighCellResistance(bool cclReducedDueToHighCellResistance)
{
    cclReducedDueToHighCellResistance_ = cclReducedDueToHighCellResistance;
}

bool BatteryLimitFlags::cclReducedDueToTemperature() const
{
    return cclReducedDueToTemperature_;
}

void BatteryLimitFlags::setCclReducedDueToTemperature(bool cclReducedDueToTemperature)
{
    cclReducedDueToTemperature_ = cclReducedDueToTemperature;
}

bool BatteryLimitFlags::cclReducedDueToHighCellVoltage() const
{
    return cclReducedDueToHighCellVoltage_;
}

void BatteryLimitFlags::setCclReducedDueToHighCellVoltage(bool cclReducedDueToHighCellVoltage)
{
    cclReducedDueToHighCellVoltage_ = cclReducedDueToHighCellVoltage;
}

bool BatteryLimitFlags::cclReducedDueToHighPackVoltage() const
{
    return cclReducedDueToHighPackVoltage_;
}

void BatteryLimitFlags::setCclReducedDueToHighPackVoltage(bool cclReducedDueToHighPackVoltage)
{
    cclReducedDueToHighPackVoltage_ = cclReducedDueToHighPackVoltage;
}

bool BatteryLimitFlags::cclReducedDueToChargerLatch() const
{
    return cclReducedDueToChargerLatch_;
}

void BatteryLimitFlags::setCclReducedDueToChargerLatch(bool cclReducedDueToChargerLatch)
{
    cclReducedDueToChargerLatch_ = cclReducedDueToChargerLatch;
}

bool BatteryLimitFlags::cclReducedDueToAlternateCurrentLimit() const
{
    return cclReducedDueToAlternateCurrentLimit_;
}

void BatteryLimitFlags::setCclReducedDueToAlternateCurrentLimit(bool cclReducedDueToAlternateCurrentLimit)
{
    cclReducedDueToAlternateCurrentLimit_ = cclReducedDueToAlternateCurrentLimit;
}
