#pragma once

#include <QVector>
#include "../FaultLabel/FaultLabel.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../DataLayer/MotorFaultsData/LimitFlags.h"

class MotorFaultList
{
public:
    MotorFaultList();

    ~MotorFaultList();

    FaultLabel getHighestActivePriorityLabel() const;
    QVector<FaultLabel>& errorLabels();
    QVector<FaultLabel>& limitLabels();
    void updateErrors(const ErrorFlags&);
    void updateLimits(const LimitFlags&);

private:

    FaultLabel determineHighestActivePriorityLabel() const;

    QVector<FaultLabel> errorLabels_;
    QVector<FaultLabel> limitLabels_;
};
