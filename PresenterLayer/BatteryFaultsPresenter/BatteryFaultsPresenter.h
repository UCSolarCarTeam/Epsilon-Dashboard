#pragma once

#include <QObject>
#include "../DataLayer/BatteryFaultsData/I_BatteryFaultsData.h"

class I_BatteryFaultsData;

class BatteryFaultsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit BatteryFaultsPresenter(const I_BatteryFaultsData& batteryFaultsData);

private:
    void relayBatteryFaultsData();

    const I_BatteryFaultsData& batteryFaultsData_;

signals:
    void batteryFaultsReceived(BatteryFaults batteryFaults);
};
