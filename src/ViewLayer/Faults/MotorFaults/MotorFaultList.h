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

    FaultLabel nextActiveFault();
    QVector<FaultLabel>& faultLabels();
    QVector<QString>& activeFaultLabels();
    void updateErrors(const ErrorFlags&);
    void updateLimits(const LimitFlags&);
    int numberOfActiveLabels() const;

private:
    QVector<FaultLabel> faultLabels_;
    QVector<QString> activeLabels_;
    int currentFault_;
};
