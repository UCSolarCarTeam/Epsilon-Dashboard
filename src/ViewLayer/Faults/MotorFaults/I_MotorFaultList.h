#pragma once
#include "Faults/FaultLabel/FaultDisplayData.h"
#include "MotorFaultsResources.h"
#include <QMap>

class I_MotorFaultList
{
public:
    virtual ~I_MotorFaultList() {};

    virtual FaultDisplayData nextActiveFault() = 0;
    virtual QMap<MotorFaults , FaultDisplayData>& faults() = 0;
    virtual int numberOfActiveFaults() = 0;

};
