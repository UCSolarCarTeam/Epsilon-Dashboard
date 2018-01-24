    #include "MotorFaultsData.h"

MotorFaultsData::MotorFaultsData()
{
}

MotorFaultsData::~MotorFaultsData()
{
}

/* FaultData Gets */
ErrorFlags MotorFaultsData::motorZeroErrorFlags() const
{
    return motorZeroErrorFlags_;
}
LimitFlags MotorFaultsData::motorZeroLimitFlags() const
{
    return motorZeroLimitFlags_;
}
ErrorFlags MotorFaultsData::motorOneErrorFlags() const
{
    return motorOneErrorFlags_;
}
LimitFlags MotorFaultsData::motorOneLimitFlags() const
{
    return motorOneLimitFlags_;
}

/* FaultData Sets */
void MotorFaultsData::setMotorZeroErrorFlags(ErrorFlags errorFlags)
{
    motorZeroErrorFlags_ = errorFlags;
    emit motorZeroErrorFlagsReceived(motorZeroErrorFlags_);
}
void MotorFaultsData::setMotorZeroLimitFlags(LimitFlags limitFlags)
{
    motorZeroLimitFlags_ = limitFlags;
    emit motorZeroLimitFlagsReceived(motorZeroLimitFlags_);
}
void MotorFaultsData::setMotorOneErrorFlags(ErrorFlags errorFlags)
{
    motorOneErrorFlags_ = errorFlags;
    emit motorOneErrorFlagsReceived(motorOneErrorFlags_);
}
void MotorFaultsData::setMotorOneLimitFlags(LimitFlags limitFlags)
{
    motorOneLimitFlags_ = limitFlags;
    emit motorOneLimitFlagsReceived(motorOneLimitFlags_);
}
