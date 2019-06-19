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
