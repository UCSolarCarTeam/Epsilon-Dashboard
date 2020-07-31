#pragma once
#include "../FaultLabel/FaultLabel.h"
#include "../../MotorFaultsResources.h"
#include <QMap>

class I_MotorFaultList
{
public:
    virtual ~I_MotorFaultList() {};

    virtual FaultLabel nextActiveFault() = 0;
    virtual QMap<MotorFaults , FaultLabel>& faults() = 0;
    virtual int numberOfActiveFaults() = 0;

};
