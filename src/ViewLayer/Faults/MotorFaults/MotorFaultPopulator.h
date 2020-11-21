#pragma once
#include "Faults/FaultPopulator.h"

class I_MotorFaultList;

class MotorFaultPopulator : public FaultPopulator
{
public:
    MotorFaultPopulator(I_MotorFaultList& faultListZero,
                            I_MotorFaultList& faultListOne);

    void populateFaults() override;
    void populateRaceFaults() override;

private:
    I_MotorFaultList& faultListZero_;
    I_MotorFaultList& faultListOne_;
};


