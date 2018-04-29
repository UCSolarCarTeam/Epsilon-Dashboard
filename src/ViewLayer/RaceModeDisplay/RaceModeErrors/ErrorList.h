#pragma once

#include <QVector>
#include "../FaultLabel/FaultLabel.h"
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"

class ErrorList
{
public:
    ErrorList();

    ~ErrorList();

    FaultLabel getHighestActivePriority();
    void updateFaults(ErrorFlags errorFlags);
    QVector<FaultLabel> getErrorLabelList();

private:

    QVector<FaultLabel> errorList_;
}
