#include "MotorDetailsPresenter.h"

MotorDetailsPresenter::MotorDetailsPresenter(const I_MotorDetailsData& motorDetailsData)
    : motorDetailsData_(motorDetailsData)
{
    relayMotorDetailsData();
}

void MotorDetailsPresenter::relayMotorDetailsData()
{
    connect(&motorDetailsData_, SIGNAL(motorZeroDetailsReceived(MotorDetails)),
            this, SIGNAL(motorZeroDetailsReceived(MotorDetails)));
    connect(&motorDetailsData_, SIGNAL(motorOneDetailsReceived(MotorDetails)),
            this, SIGNAL(motorOneDetailsReceived(MotorDetails)));
}

