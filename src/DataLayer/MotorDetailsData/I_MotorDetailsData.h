#pragma once

#include <QObject>
#include "MotorDetails.h"

class I_MotorDetailsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_MotorDetailsData() {}

    virtual MotorDetails motorZeroDetails() const = 0;
    virtual MotorDetails motorOneDetails() const = 0;

    virtual void setMotorZeroDetails(MotorDetails motorDetails) = 0;
    virtual void setMotorOneDetails(MotorDetails motorDetails) = 0;

signals:
    void motorZeroDetailsReceived(MotorDetails);
    void motorOneDetailsReceived(MotorDetails);
};
