#pragma once
#include "Faults/FaultPopulator.h"

class I_BatteryFaultList;

class BatteryFaultPopulator : public FaultPopulator
{
public:
    BatteryFaultPopulator(I_BatteryFaultList& faultList);

    void populateFaults() override;
    void populateRaceFaults() override;

private:
    I_BatteryFaultList& faultList_;
};


