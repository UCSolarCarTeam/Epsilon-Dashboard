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

    FaultLabel nextActiveFault();
    QVector<FaultLabel>& faultLabels();
    void updateErrors(const BatteryErrorFlags&);
    void updateLimits(const BatteryLimitFlags&);
    int numberOfActiveLabels() const;

private:
    QVector<FaultLabel> faultLabels_;
    int currentFault_;
};
