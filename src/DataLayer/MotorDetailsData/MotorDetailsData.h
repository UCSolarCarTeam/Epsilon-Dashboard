#pragma once

#include "I_MotorDetailsData.h"

class MotorDetailsData : public I_MotorDetailsData
{
public:
    MotorDetailsData();
    virtual ~MotorDetailsData();

    MotorDetails motorZeroDetails() const;
    MotorDetails motorOneDetails() const;

    void setMotorZeroDetails(MotorDetails motorOneDetails);
    void setMotorOneDetails(MotorDetails motorZeroDetails);

private:
    MotorDetails motorZeroDetails_;
    MotorDetails motorOneDetails_;
};

