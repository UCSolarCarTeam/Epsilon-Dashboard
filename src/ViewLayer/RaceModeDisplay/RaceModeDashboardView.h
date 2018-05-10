#pragma once

#include <QObject>
#include <QLabel>

#include "../../DataLayer/MpptData/Mppt.h"
#include "../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "Faults/BatteryFaults/BatteryFaultList.h"
#include "Faults/MotorFaults/MotorFaultList.h"


class BatteryPresenter;
class BatteryFaultsPresenter;
class DriverControlsPresenter;
class I_RaceModeDashboardUI;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;

class RaceModeDashboardView : public QObject
{
    Q_OBJECT
public:
    RaceModeDashboardView(BatteryPresenter& batteryPresenter,
                          BatteryFaultsPresenter& batteryFaultsPresenter,
                          DriverControlsPresenter& driverControlsPresenter,
                          KeyMotorPresenter& keyMotorPresenter,
                          LightsPresenter& lightsPresenter,
                          MpptPresenter& mpptPresenter,
                          MotorDetailsPresenter& motorDetailsPresenter,
                          MotorFaultsPresenter& motorFaultsPresenter,
                          I_RaceModeDashboardUI& ui,
                          MotorFaultList& motorZeroFaultsList,
                          MotorFaultList& motorOneFaultsList,
                          BatteryFaultList& batteryFaultsList);
    ~RaceModeDashboardView();

private:
    void connectBattery(BatteryPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    void updateMotorLabel(QLabel& motorLabel, FaultLabel faultLabel);

    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MpptPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    MotorFaultsPresenter& motorFaultsPresenter_;
    I_RaceModeDashboardUI& ui_;
    MotorFaultList& motorZeroFaultsList_;
    MotorFaultList& motorOneFaultsList_;
    BatteryFaultList& batteryFaultsList_;

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
