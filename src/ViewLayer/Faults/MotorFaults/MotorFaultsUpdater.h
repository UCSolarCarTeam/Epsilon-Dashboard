#pragma once
#include <QObject>
#include "../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../DataLayer/MotorFaultsData/LimitFlags.h"

class I_FaultList;
class MotorFaultsPresenter;

class MotorFaultsUpdater : public QObject
{
    Q_OBJECT
public:
    MotorFaultsUpdater(const MotorFaultsPresenter& presenter, I_FaultList& faultList);

private slots:
    void motorZeroErrorFlagsReceived(ErrorFlags);
    void motorZeroLimitFlagsReceived(LimitFlags);
    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);

private:
    const MotorFaultsPresenter& motorFaultsPresenter_;
    I_FaultList& faultList_;
};
