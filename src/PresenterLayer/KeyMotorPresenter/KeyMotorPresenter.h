#pragma once
#include "../DataLayer/KeyMotorData/I_KeyMotorData.h"
#include <QObject>
class I_KeyMotorData;

class KeyMotorPresenter : public QObject
{
    Q_OBJECT
public:
    explicit KeyMotorPresenter(const I_KeyMotorData& keyMotorData);

private:
    void relayKeyMotorData();

    const I_KeyMotorData& keyMotorData_;

signals:
    void motorZeroReceived(KeyMotor);
    void motorOneReceived(KeyMotor);
    void motorZeroSetPowerReceived(double);
    void motorOneSetPowerReceived(double);
    void motorZeroSetCurrentReceived(double);
    void motorOneSetCurrentReceived(double);
    void motorActualSpeedReceived(double);
    void motorZeroBusVoltageReceived(double);
    void motorOneBusVoltageReceived(double);
    void motorZeroBusCurrentReceived(double);
    void motorOneBusCurrentReceived(double);
};
