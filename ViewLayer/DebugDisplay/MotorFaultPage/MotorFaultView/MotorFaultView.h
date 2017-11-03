#pragma once

#include <QObject>
#include <QLabel>
#include <QLayout>

#include "../../../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../../../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "../../../../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "../MotorFaultUi/I_MotorFaultUi.h"

class MotorFaultsPresenter;
class BatteryFaultsPresenter;
class I_MotorFaultUi;

class MotorFaultView : public QObject
{
    Q_OBJECT
public:
    MotorFaultView(MotorFaultsPresenter& motorFaultsPresenter,
                   BatteryFaultsPresenter& batteryFaultsPresenter,
                   I_MotorFaultUi& ui);
    ~MotorFaultView();

private:
    void connectMotorFaults(MotorFaultsPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);

    MotorFaultsPresenter& motorFaultsPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;

    I_MotorFaultUi& ui_;

    QLabel badMotorPositionHallSequenceFault_;
    QLabel configReadErrorFault_;
    QLabel dcBusOverVoltageFault_;
    QLabel desaturationFaultFault_;
    QLabel motorOverSpeedFault_;
    QLabel railUnderVoltageLockOutFault_;
    QLabel watchdogCausedLastResetFault_;

private slots:
    // battery faults slots
    void errorFlagsReceived(BatteryErrorFlags);
    void limitFlagsReceived(BatteryLimitFlags);

    // motor faults slots
    void motorZeroErrorFlagsReceived(ErrorFlags);
    void motorZeroLimitFlagsReceived(LimitFlags);
    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
};

