#pragma once

#include "I_BatteryFaultsData.h"

class BatteryFaultsData : public I_BatteryFaultsData
{
public:
    BatteryFaultsData();
    virtual ~BatteryFaultsData();

    BatteryErrorFlags errorFlags() const;
    BatteryLimitFlags limitFlags() const;

    void setErrorFlags(const BatteryErrorFlags& errorFlags);
    void setLimitFlags(const BatteryLimitFlags& limitFlags);

private:
    BatteryErrorFlags batteryErrorFlags_;
    BatteryLimitFlags batteryLimitFlags_;
};
