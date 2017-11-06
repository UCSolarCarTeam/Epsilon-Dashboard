#pragma once

#include <QObject>
#include <QLabel>
#include <QLayout>
#include <QDebug>

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

    QLabel badMotorPositionHallSequence0Fault_;
    QLabel configReadError0Fault_;
    QLabel dcBusOverVoltage0Fault_;
    QLabel desaturationFault0Fault_;
    QLabel motorOverSpeed0Fault_;
    QLabel railUnderVoltageLockOut0Fault_;
    QLabel watchdogCausedLastReset0Fault_;
    QLabel softwareOverCurrent0Fault_;

    QLabel busCurrentLimit0Fault_;
    QLabel busVoltageUpperLimit0Fault_;
    QLabel busVoltageLowerLimit0Fault_;
    QLabel ipmOrMotorTelemetryLimit0Fault_;
    QLabel motorCurrentLimit0Fault_;
    QLabel outputVoltagePwmLimit0Fault_;
    QLabel velocityLimit0Fault_;

    int label0Count_;

    QLabel badMotorPositionHallSequence1Fault_;
    QLabel configReadError1Fault_;
    QLabel dcBusOverVoltage1Fault_;
    QLabel desaturationFault1Fault_;
    QLabel motorOverSpeed1Fault_;
    QLabel railUnderVoltageLockOut1Fault_;
    QLabel watchdogCausedLastReset1Fault_;
    QLabel softwareOverCurrent1Fault_;

    QLabel busCurrentLimit1Fault_;
    QLabel busVoltageUpperLimit1Fault_;
    QLabel busVoltageLowerLimit1Fault_;
    QLabel ipmOrMotorTelemetryLimit1Fault_;
    QLabel motorCurrentLimit1Fault_;
    QLabel outputVoltagePwmLimit1Fault_;
    QLabel velocityLimit1Fault_;
    int label1Count_;

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

