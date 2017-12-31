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
    connect(&keyMotorData_, SIGNAL(motorSetCurrentReceived(double setCurrent)),
            this, SIGNAL(motorSetCurrentReceived(double setCurrent)));
    connect(&keyMotorData_, SIGNAL(motorActualSpeedReceived(double actualSpeed)),
            this, SIGNAL(motorActualSpeedReceived(double actualSpeed)));
    connect(&keyMotorData_, SIGNAL(motorBusVoltageReceived(double busVoltage)),
            this, SIGNAL(motorBusVoltageReceived(double busVoltage)));
    connect(&keyMotorData_, SIGNAL(motorBusCurrentReceived(double busCurrent)),
            this, SIGNAL(motorBusCurrentReceived(double busCurrent)));
}
