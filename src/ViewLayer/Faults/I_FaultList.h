#pragma once
#include "FaultLabel/FaultLabel.h"
#include "../MotorFaultsResources.h"
#include <QMap>

class I_FaultList
{
public:
    virtual ~I_FaultList() {};

    virtual FaultLabel nextActiveFault() = 0;
    virtual QMap<MotorFaults , FaultLabel>& faults() = 0;
    virtual int numberOfActiveFaults() = 0;

};
