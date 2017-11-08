#pragma once

#include "BatteryErrorFlags.h"
#include "BatteryLimitFlags.h"

#include <QObject>
#include <QString>

class I_BatteryFaultsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_BatteryFaultsData() {}

    /* FaultData Gets */
    virtual BatteryErrorFlags errorFlags() const = 0;
    virtual BatteryLimitFlags limitFlags() const = 0;

    /* FaultData Sets */
    virtual void setErrorFlags(const BatteryErrorFlags& errorFlags) = 0;
    virtual void setLimitFlags(const BatteryLimitFlags& limitFlags) = 0;

signals:
    void batteryErrorFlagsReceived(BatteryErrorFlags errorFlags);
    void batteryLimitFlagsReceived(BatteryLimitFlags limitFlags);
};
