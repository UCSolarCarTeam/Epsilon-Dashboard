#include "BatteryFaultsPresenter.h"

BatteryFaultsPresenter::BatteryFaultsPresenter(const I_BatteryFaultsData& batteryFaultsData)
    : batteryFaultsData_(batteryFaultsData)
{
    relayBatteryFaultsData();
}

void BatteryFaultsPresenter::relayBatteryFaultsData()
{
    connect(&batteryFaultsData_, SIGNAL(batteryErrorFlagsReceived(BatteryErrorFlags)),
            this, SIGNAL(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsData_, SIGNAL(batteryLimitFlagsReceived(BatteryLimitFlags)),
            this, SIGNAL(errorFlagsReceived(BatteryErrorFlags)));
}
