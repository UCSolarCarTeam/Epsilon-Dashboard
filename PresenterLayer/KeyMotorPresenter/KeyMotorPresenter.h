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
    void motorZeroReceived(KeyMotor motorZero);
    void motorOneReceived(KeyMotor motorOne);
    void motorSetCurrentReceived(double setCurrent);
    void motorActualSpeedReceived(double actualSpeed);
    void motorBusVoltageReceived(double busVoltage);
    void motorBusCurrentReceived(double busVoltage);
};
