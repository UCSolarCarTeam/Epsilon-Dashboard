#pragma once

#include <QObject>
#include "KeyMotor.h"

class I_KeyMotorData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_KeyMotorData() {}

    virtual KeyMotor motorZero() const = 0;
    virtual KeyMotor motorOne() const = 0;

    virtual void setMotorZero(KeyMotor motorZero) = 0;
    virtual void setMotorOne(KeyMotor motorOne) = 0;

signals:
    void motorZeroReceived(KeyMotor motorZero);
    void motorOneReceived(KeyMotor motorOne);
    void motorSetCurrentReceived(double setCurrent);
    void motorActualSpeedReceived(double actualSpeed);
    void motorBusVoltageReceived(double busVoltage);
    void motorBusCurrentReceived(double busCurrent);
};
