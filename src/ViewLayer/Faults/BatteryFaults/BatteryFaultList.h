#pragma once

#include <QMap>
#include <QMapIterator>
#include "../DataLayer/BatteryFaultsData/BatteryFaultsData.h"
#include "../DataLayer/BatteryFaultsData/BatteryLimitFlags.h"
#include "../FaultLabel/FaultDisplayData.h"
#include "I_BatteryFaultList.h"

class BatteryFaultList : public I_BatteryFaultList
{
public:
    BatteryFaultList();

    ~BatteryFaultList();

    FaultDisplayData nextActiveFault();
    QMap<BatteryFaults, FaultDisplayData>& faults();
    int numberOfActiveFaults() const;
    QVector<QString>& activeFaultLabels();

private:
    QMap<BatteryFaults, FaultDisplayData> faultList_;
    QMap<BatteryFaults, FaultDisplayData>::iterator  currentFault_;
    QVector<QString> activeLabels_;
};
