#pragma once

#include "../DataLayer/BatteryFaultsData/BatteryFaultsData.h"
#include "../DataLayer/BatteryFaultsData/BatteryLimitFlags.h"
#include "../FaultLabel/FaultLabel.h"
#include <QVector>

class BatteryFaultList
{
public:
    BatteryFaultList();

    ~BatteryFaultList();

    FaultLabel getHighestActivePriorityLabel() const;
    QVector<FaultLabel>& errorLabels();
    QVector<FaultLabel>& limitLabels();
    void updateErrors(const BatteryErrorFlags& errorFlags);
    void updateLimits(const BatteryLimitFlags& limitFlags);

private:

    FaultLabel determineHighestActivePriorityLabel() const;

    QVector<FaultLabel> errorLabels_;
    QVector<FaultLabel> limitLabels_;
};
