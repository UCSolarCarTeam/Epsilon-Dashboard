#pragma once

#include <QVector>
#include <QMapIterator>
#include "../FaultLabel/FaultDisplayData.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../DataLayer/MotorFaultsData/LimitFlags.h"
#include "I_MotorFaultList.h"

class MotorFaultList : public I_MotorFaultList
{
public:
    MotorFaultList();

    ~MotorFaultList();

    FaultDisplayData nextActiveFault();
    QMap<MotorFaults, FaultDisplayData>& faults();
    int numberOfActiveFaults();
    QVector<QString>& activeFaultLabels();

private:
    QMap<MotorFaults, FaultDisplayData> faultList_;
    QMap<MotorFaults, FaultDisplayData>::iterator  currentFault_;
    QVector<QString> activeLabels_;
};
