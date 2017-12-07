#pragma once

#include <QObject>
#include <QLabel>

#include "../../../DataLayer/MpptData/Mppt.h"
#include "../../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "../../../PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "../../../PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "../../../PresenterLayer/LightsPresenter/LightsPresenter.h"
#include "../../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../../../PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "../../../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "../DisplayDashboardUI/I_DisplayDashboardUI.h"

class BatteryPresenter;
class BatteryFaultsPresenter;
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
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MpptPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    MotorFaultsPresenter& motorFaultsPresenter_;

    I_DisplayDashboardUI& ui_;

private slots:
    // battery data slots
    void aliveReceived(bool);
    void prechargeStateReceived(QString);
    void packNetPowerReceived(double);

    // battery faults slots
    void errorFlagsReceived(BatteryErrorFlags);
    void limitFlagsReceived(BatteryLimitFlags);

    void resetReceived(bool);

    // key motor slots
    void motorSetCurrentReceived(double);
    void motorActualSpeedReceived(double);
    void motorBusVoltageReceived(double);
    void motorBusCurrentReceived(double);

    // lights slots
    void lowBeamsReceived(bool);
    void highBeamsReceived(bool);
    void leftSignalReceived(bool);
    void rightSignalReceived(bool);
    void lightAliveReceived(bool);

    // mppt slots
    void mpptReceived(int, Mppt);
    void mpptPowerReceived(double);

    // motor faults slots
    void motorZeroErrorFlagsReceived(ErrorFlags);
    void motorZeroLimitFlagsReceived(LimitFlags);
    void motorOneErrorFlagsReceived(ErrorFlags);
    void motorOneLimitFlagsReceived(LimitFlags);
};
