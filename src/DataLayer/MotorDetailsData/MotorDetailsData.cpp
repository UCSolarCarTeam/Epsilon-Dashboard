#include "MotorDetailsData.h"
#include <QDebug>

MotorDetailsData::MotorDetailsData()
{
}

MotorDetailsData::~MotorDetailsData()
{
}

MotorDetails MotorDetailsData::motorZeroDetails() const
{
    return motorZeroDetails_;
}
MotorDetails MotorDetailsData::motorOneDetails() const
{
    return motorOneDetails_;
}

void MotorDetailsData::setMotorZeroDetails(MotorDetails motorZeroDetails)
{
    motorZeroDetails_ = motorZeroDetails;
    emit motorZeroDetailsReceived(motorZeroDetails_);
}
void MotorDetailsData::setMotorOneDetails(MotorDetails motorOneDetails)
{
    motorOneDetails_ = motorOneDetails;
    emit motorOneDetailsReceived(motorOneDetails_);
}