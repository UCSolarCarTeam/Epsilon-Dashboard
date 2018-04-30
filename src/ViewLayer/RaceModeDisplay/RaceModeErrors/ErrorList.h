#pragma once

#include <QVector>
#include "../FaultLabel/FaultLabel.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"

class ErrorList
{
public:
    ErrorList();

    ~ErrorList();

    FaultLabel getHighestActivePriority() const;
    QVector<FaultLabel> getErrorLabelList() const;
    void updateFaults(const ErrorFlags& errorFlags);

private:

    QVector<FaultLabel> errorList_;
};
