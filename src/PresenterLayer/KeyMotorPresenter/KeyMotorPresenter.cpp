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

    connect(&keyMotorData_, SIGNAL(motorZeroSetPowerReceived(double)),
            this, SIGNAL(motorZeroSetPowerReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorOneSetPowerReceived(double)),
            this, SIGNAL(motorOneSetPowerReceived(double)));

    connect(&keyMotorData_, SIGNAL(motorZeroSetCurrentReceived(double)),
            this, SIGNAL(motorZeroSetCurrentReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorOneSetCurrentReceived(double)),
            this, SIGNAL(motorOneSetCurrentReceived(double)));

    connect(&keyMotorData_, SIGNAL(motorActualSpeedReceived(double)),
            this, SIGNAL(motorActualSpeedReceived(double)));

    connect(&keyMotorData_, SIGNAL(motorZeroBusVoltageReceived(double)),
            this, SIGNAL(motorZeroBusVoltageReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorOneBusVoltageReceived(double)),
            this, SIGNAL(motorOneBusVoltageReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorZeroBusCurrentReceived(double)),
            this, SIGNAL(motorZeroBusCurrentReceived(double)));
    connect(&keyMotorData_, SIGNAL(motorOneBusCurrentReceived(double)),
            this, SIGNAL(motorOneBusCurrentReceived(double)));

}
