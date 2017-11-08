#include "KeyMotorPresenter.h"


KeyMotorPresenter::KeyMotorPresenter(const I_KeyMotorData& keyMotorData)
    : keyMotorData_(keyMotorData)
{
    relayKeyMotorData();
}

void KeyMotorPresenter::relayKeyMotorData()
{
    connect(&keyMotorData_, SIGNAL(motorZeroReceived(KeyMotor)),
            this, SIGNAL(motorZeroReceived(KeyMotor)));
    connect(&keyMotorData_, SIGNAL(motorOneReceived(KeyMotor)),
            this, SIGNAL(motorOneReceived(KeyMotor)));
    connect(&keyMotorData_, SIGNAL(motorSetCurrentReceived(double)),
            this, SIGNAL(motorSetCurrentReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorActualSpeedReceived(double)),
            this, SIGNAL(motorActualSpeedReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorBusVoltageReceived(double)),
            this, SIGNAL(motorBusVoltageReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorBusCurrentReceived(double)),
            this, SIGNAL(motorBusCurrentReceived(double)));
}
