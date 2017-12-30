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
    emit motorSetCurrentReceived((motorZero_.setCurrent() + motorOne_.setCurrent()) / 2);
    emit motorActualSpeedReceived((motorZero_.vehicleVelocity() + motorOne_.vehicleVelocity()) / 2);
    emit motorBusVoltageReceived((motorZero_.busVoltage() + motorOne_.busVoltage()) / 2);
    emit motorBusCurrentReceived((motorZero_.busCurrent() + motorOne_.busCurrent()) / 2);
}
void KeyMotorData::setMotorOne(KeyMotor motorOne)
{
    motorOne_ = motorOne;
    emit motorOneReceived(motorOne_);
    emit motorSetCurrentReceived((motorZero_.setCurrent() + motorOne_.setCurrent()) / 2);
    emit motorActualSpeedReceived((motorZero_.vehicleVelocity() + motorOne_.vehicleVelocity()) / 2);
    emit motorBusVoltageReceived((motorZero_.busVoltage() + motorOne_.busVoltage()) / 2);
    emit motorBusCurrentReceived((motorZero_.busCurrent() + motorOne_.busCurrent()) / 2);
}