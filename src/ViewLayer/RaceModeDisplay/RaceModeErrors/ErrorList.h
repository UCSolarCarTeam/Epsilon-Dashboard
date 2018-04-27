#pragma once

#include "../FaultLabel/FaultLabel.h"

class ErrorList
{
public:
    ErrorList();

    FaultLabel getHighestActivePriority();
    void updateFaultsList();
    FaultLabel* getLabelList();

private:
    FaultLabel faultList_ [];
}
