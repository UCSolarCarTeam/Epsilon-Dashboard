#pragma once

#include <QObject>
#include "../DataLayer/BatteryFaultsData/BatteryErrorFlags.h"
#include "../DataLayer/BatteryFaultsData/BatteryLimitFlags.h"

class I_BatteryFaultList;
class BatteryFaultsPresenter;

class BatteryFaultsUpdater : public QObject
{
    Q_OBJECT
public:
    BatteryFaultsUpdater(const BatteryFaultsPresenter& presenter,
                         I_BatteryFaultList& faultList);

private slots:
    void errorFlagsReceived(BatteryErrorFlags);
    void limitFlagsReceived(BatteryLimitFlags);

private:
    const BatteryFaultsPresenter& batteryFaultsPresenter_;
    I_BatteryFaultList& faultList_;

};
