#pragma once

#include "../DataLayer/BatteryFaultsData/BatteryFaultsData.h"
#include "../DataLayer/BatteryFaultsData/BatteryLimitFlags.h"
#include "../FaultLabel/FaultDisplayData.h"
#include <QVector>

class BatteryFaultList
{
public:
    BatteryFaultList();

    ~BatteryFaultList();

    FaultDisplayData nextActiveFault();
    QVector<FaultDisplayData>& faultLabels();
    void updateErrors(const BatteryErrorFlags&);
    void updateLimits(const BatteryLimitFlags&);
    int numberOfActiveLabels() const;

private:
    QVector<FaultDisplayData> faultLabels_;
    int currentFault_;
};
