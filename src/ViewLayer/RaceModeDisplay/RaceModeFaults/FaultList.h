#pragma once

#include <QVector>
#include "../FaultLabel/FaultLabel.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../DataLayer/MotorFaultsData/LimitFlags.h"

class FaultList
{
public:
    FaultList();

    ~FaultList();

    FaultLabel getHighestActivePriorityLabel() const;
    QVector<FaultLabel> getErrorLabelList() const;
    QVector<FaultLabel> getLimitLabelList() const;
    void updateErrors(const ErrorFlags& errorFlags);
    void updateLimits(const LimitFlags& limitFlags);

private:

    QVector<FaultLabel> errorList_;
    QVector<FaultLabel> limitList_;
};
