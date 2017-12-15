#include "BatteryFaultsData.h"
#include <QDebug>

BatteryFaultsData::BatteryFaultsData()
{
}

BatteryFaultsData::~BatteryFaultsData()
{
}

BatteryErrorFlags BatteryFaultsData::errorFlags() const
{
    return batteryErrorFlags_;
}

BatteryLimitFlags BatteryFaultsData::limitFlags() const
{
    return batteryLimitFlags_;
}

void BatteryFaultsData::setErrorFlags(const BatteryErrorFlags& batteryErrorFlags)
{
    batteryErrorFlags_ = batteryErrorFlags;
    emit batteryErrorFlagsReceived(batteryErrorFlags_);
}

void BatteryFaultsData::setLimitFlags(const BatteryLimitFlags& batteryLimitFlags)
{
    batteryLimitFlags_ = batteryLimitFlags;
    emit batteryLimitFlagsReceived(batteryLimitFlags_);
}
