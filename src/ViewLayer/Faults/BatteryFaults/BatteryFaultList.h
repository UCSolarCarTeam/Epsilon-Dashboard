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
    QVector<QString>& activeFaultLabels();
    void updateErrors(const BatteryErrorFlags&);
    void updateLimits(const BatteryLimitFlags&);
    int numberOfActiveLabels() const;

private:
    QVector<FaultLabel> faultLabels_;
    QVector<QString> activeLabels_;
    int currentFault_;
};
