#include "MotorFaultsPresenter.h"


MotorFaultsPresenter::MotorFaultsPresenter(const I_MotorFaultsData& motorFaultsData)
    : motorFaultsData_ (motorFaultsData)
{
    relayMotorFaultsData();
}

void MotorFaultsPresenter::relayMotorFaultsData()
{
    connect(&motorFaultsData_, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)),
            this, SIGNAL(motorZeroErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsData_, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)),
            this, SIGNAL(motorZeroLimitFlagsReceived(LimitFlags)));
    connect(&motorFaultsData_, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)),
            this, SIGNAL(motorOneErrorFlagsReceived(ErrorFlags)));
    connect(&motorFaultsData_, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
            this, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)));
}
