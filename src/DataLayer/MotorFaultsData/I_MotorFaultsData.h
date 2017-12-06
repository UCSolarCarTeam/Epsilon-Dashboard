#pragma once

#include <QObject>

#include "ErrorFlags.h"
#include "LimitFlags.h"

class I_MotorFaultsData : public QObject
{
    Q_OBJECT
public:
    virtual ~I_MotorFaultsData() {}

    /* FaultData Gets */
    virtual ErrorFlags motorZeroErrorFlags() const = 0;
    virtual LimitFlags motorZeroLimitFlags() const = 0;
    virtual ErrorFlags motorOneErrorFlags() const = 0;
    virtual LimitFlags motorOneLimitFlags() const = 0;

    /* FaultData Sets */
    virtual void setMotorZeroErrorFlags(ErrorFlags errorFlags) = 0;
    virtual void setMotorZeroLimitFlags(LimitFlags limitFlags) = 0;
    virtual void setMotorOneErrorFlags(ErrorFlags errorFlags) = 0;
    virtual void setMotorOneLimitFlags(LimitFlags limitFlags) = 0;

signals:
    void motorZeroErrorFlagsReceived(ErrorFlags);
    void motorZeroLimitFlagsReceived(LimitFlags);
    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
};
