#pragma once

#include <QObject>
#include <QLabel>

#include "DataLayer/BatteryFaultsData/BatteryFaults.h"
#include "DataLayer/MpptData/Mppt.h"
#include "DataLayer/MotorFaultsData/ErrorFlags.h"
#include "DataLayer/MotorFaultsData/LimitFlags.h"
#include "PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "PresenterLayer/CmuPresenter/CmuPresenter.h"
#include "PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "PresenterLayer/LightsPresenter/LightsPresenter.h"
#include "PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "ViewLayer/DisplayDashboardUI/I_DisplayDashboardUI.h"

class BatteryPresenter;
class BatteryFaultsPresenter;
class CmuPresenter;
class DriverControlsPresenter;
class I_DisplayDashboardUI;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;

class DisplayDashboardView : public QObject
{
    Q_OBJECT
public:
    DisplayDashboardView(BatteryPresenter& batteryPresenter,
                         BatteryFaultsPresenter& batteryFaultsPresenter,
                         CmuPresenter& cmuPresenter,
                         DriverControlsPresenter& driverControlsPresenter,
                         KeyMotorPresenter& keyMotorPresenter,
                         LightsPresenter& lightsPresenter,
                         MpptPresenter& mpptPresenter,
                         MotorDetailsPresenter& motorDetailsPresenter,
                         MotorFaultsPresenter& motorFaultsPresenter,
                         I_DisplayDashboardUI& ui);
    ~DisplayDashboardView();

private:
    void connectBattery(BatteryPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void connectCmu(CmuPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    CmuPresenter& cmuPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MpptPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    MotorFaultsPresenter& motorFaultsPresenter_;

    I_DisplayDashboardUI& ui_;

private slots:
    void aliveReceived(bool);
    void packSocPercentageReceived(double);
    void prechargeStateReceived(QString);
    void prechargeTimerElapsedReceived(bool);
    void prechargeTimerCountReceived(double);
    void netPowerReceived(double);

    void batteryFaultsReceived(BatteryFaults);

    void cmuMaxCellTempReceived(double);
    void cmuLowestCellVoltageReceived(double);
    void cmuAverageCellTempReceived(double);
    void cmuAverageVoltageReceived(double);

    void resetReceived(bool);

    void motorSetCurrentReceived(double);
    void motorActualSpeedReceived(double);
    void motorBusVoltageReceived(double);
    void motorBusCurrentReceived(double);

    void lowBeamsReceived(bool);
    void highBeamsReceived(bool);
    void leftSignalReceived(bool);
    void rightSignalReceived(bool);

    void mpptZeroReceived(Mppt);
    void mpptOneReceived(Mppt);
    void mpptTwoReceived(Mppt);
    void mpptPowerReceived(double);

    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
    void motorTwoErrorFlagsReceived(ErrorFlags);
    void motorTwoLimitFlagsReceived(LimitFlags);
};
