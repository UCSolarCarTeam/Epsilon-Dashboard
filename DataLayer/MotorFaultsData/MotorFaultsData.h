#pragma once

#include "I_MotorFaultsData.h"

class ErrorFlags;
class LimitFlags;

class MotorFaultsData : public I_MotorFaultsData
{
public:
    MotorFaultsData();
    virtual ~MotorFaultsData();

    /* FaultData Gets */
    ErrorFlags motorZeroErrorFlags() const;
    LimitFlags motorZeroLimitFlags() const;
    ErrorFlags motorOneErrorFlags() const;
    LimitFlags motorOneLimitFlags() const;

    /* FaultData Sets */
    void setMotorZeroErrorFlags(ErrorFlags errorFlags);
    void setMotorZeroLimitFlags(LimitFlags limitFlags);
    void setMotorOneErrorFlags(ErrorFlags errorFlags);
    void setMotorOneLimitFlags(LimitFlags limitFlags);

private:
    ErrorFlags motorZeroErrorFlags_;
    LimitFlags motorZeroLimitFlags_;
    ErrorFlags motorOneErrorFlags_;
    LimitFlags motorOneLimitFlags_;
};
