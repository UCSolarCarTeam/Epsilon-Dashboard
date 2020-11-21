#pragma once

#include <QVector>
#include <QMapIterator>
#include "../FaultLabel/FaultLabel.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../DataLayer/MotorFaultsData/LimitFlags.h"
#include "I_MotorFaultList.h"

class MotorFaultList : public I_MotorFaultList
{
public:
    MotorFaultList();

    ~MotorFaultList();

    FaultLabel nextActiveFault();
    QMap<MotorFaults, FaultLabel>& faults();
    int numberOfActiveFaults();

private:
    QMap<MotorFaults, FaultLabel> faultList_;
    int currentFault_;
};
