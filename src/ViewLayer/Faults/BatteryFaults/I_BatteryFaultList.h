#pragma once
#include "Faults/FaultLabel/FaultDisplayData.h"
#include "BatteryFaultsResources.h"
#include <QMap>

class I_BatteryFaultList
{
public:
    virtual ~I_BatteryFaultList() {};

    virtual FaultDisplayData nextActiveFault() = 0;
    virtual QMap<BatteryFaults, FaultDisplayData>& faults() = 0;
    virtual int numberOfActiveFaults() = 0;
    virtual QVector<QString>& activeFaultLabels() = 0;

};
