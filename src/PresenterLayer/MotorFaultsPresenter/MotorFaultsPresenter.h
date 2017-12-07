#pragma once

#include <QObject>
#include "../DataLayer/MotorFaultsData/I_MotorFaultsData.h"

class I_MotorFaultsData;

class MotorFaultsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MotorFaultsPresenter(const I_MotorFaultsData& motorFaultsData);

private:
    void relayMotorFaultsData();

    const I_MotorFaultsData& motorFaultsData_;

signals:
    void motorZeroErrorFlagsReceived(ErrorFlags);
    void motorZeroLimitFlagsReceived(LimitFlags);
    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
};
