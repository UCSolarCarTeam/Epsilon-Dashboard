#pragma once

#include "I_KeyMotorData.h"

class KeyMotorData : public I_KeyMotorData
{
public:
    KeyMotorData();
    virtual ~KeyMotorData();


    KeyMotor motorZero() const;
    KeyMotor motorOne() const;
    void setMotorZero(KeyMotor motorZero);
    void setMotorOne(KeyMotor motorOne);

private:
    KeyMotor motorZero_;
    KeyMotor motorOne_;
};

