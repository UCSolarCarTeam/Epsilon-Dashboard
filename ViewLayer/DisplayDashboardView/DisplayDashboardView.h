#pragma once

#include <QObject>
#include <QLabel>

#include "DataLayer/BatteryFaultsData/BatteryFaults.h"
#include "DataLayer/MPPTData/MPPT.h"
#include "DataLayer/MotorFaultsData/ErrorFlags.h"
#include "DataLayer/MotorFaultsData/LimitFlags.h"
#include "PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "PresenterLayer/CMUPresenter/CMUPresenter.h"
#include "PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "PresenterLayer/LightsPresenter/LightsPresenter.h"
#include "PresenterLayer/MPPTPresenter/MPPTPresenter.h"
#include "PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "ViewLayer/DisplayDashboardUI/DisplayDashboardUI.h"

class BatteryPresenter;
class BatteryFaultsPresenter;
class CMUPresenter;
class DriverControlsPresenter;
class I_DisplayDashboardUI;
class KeyMotorPresenter;
class LightsPresenter;
class MPPTPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;

class DisplayDashboardView : public QObject
{
    Q_OBJECT
public:
    DisplayDashboardView(BatteryPresenter& batteryPresenter,
                         BatteryFaultsPresenter& batteryFaultsPresenter,
                         CMUPresenter& cmuPresenter,
                         DriverControlsPresenter& driverControlsPresenter,
                         KeyMotorPresenter& keyMotorPresenter,
                         LightsPresenter& lightsPresenter,
                         MPPTPresenter& mpptPresenter,
                         MotorDetailsPresenter& motorDetailsPresenter,
                         MotorFaultsPresenter& motorFaultsPresenter,
                         DisplayDashboardUI& ui);
    ~DisplayDashboardView();

private:
    void connectBattery(BatteryPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void connectCMU(CMUPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMPPT(MPPTPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    CMUPresenter& cmuPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MPPTPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    MotorFaultsPresenter& motorFaultsPresenter_;

    DisplayDashboardUI& ui_;

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

    void mpptZeroReceived(MPPT);
    void mpptOneReceived(MPPT);
    void mpptTwoReceived(MPPT);
    void mpptPowerReceived(double);

    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
    void motorTwoErrorFlagsReceived(ErrorFlags);
    void motorTwoLimitFlagsReceived(LimitFlags);
};
