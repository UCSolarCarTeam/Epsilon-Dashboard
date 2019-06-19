#include "KeyMotorData.h"
#include <QDebug>

KeyMotorData::KeyMotorData()
{
}

KeyMotorData::~KeyMotorData()
{
}

KeyMotor KeyMotorData::motorZero() const
{
    return motorZero_;
}
KeyMotor KeyMotorData::motorOne() const
{
    return motorOne_;
}
void KeyMotorData::setMotorZero(KeyMotor motorZero)
{
    motorZero_ = motorZero;
    emit motorZeroReceived(motorZero_);
    emit motorZeroSetPowerReceived(motorZero_.busVoltage() * motorZero_.busCurrent());
    emit motorZeroSetCurrentReceived(motorZero_.setCurrent());
    emit motorActualSpeedReceived((motorZero_.vehicleVelocity() + motorOne_.vehicleVelocity()) / 2);
    emit motorZeroBusVoltageReceived(motorZero_.busVoltage());
    emit motorZeroBusCurrentReceived(motorZero_.busCurrent());
}
void KeyMotorData::setMotorOne(KeyMotor motorOne)
{
    motorOne_ = motorOne;
    emit motorOneReceived(motorOne_);
    emit motorOneSetPowerReceived(motorOne_.busVoltage() * motorOne_.busCurrent());
    emit motorOneSetCurrentReceived(motorOne_.setCurrent());
    emit motorActualSpeedReceived((motorZero_.vehicleVelocity() + motorOne_.vehicleVelocity()) / 2);
    emit motorOneBusVoltageReceived(motorOne_.busVoltage());
    emit motorOneBusCurrentReceived(motorOne_.busCurrent());
}
