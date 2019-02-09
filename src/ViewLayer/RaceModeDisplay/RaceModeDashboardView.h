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
class AuxBmsPresenter;
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
                          AuxBmsPresenter& auxBmsPresenter,
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
    void connectAuxBms(AuxBmsPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    void updateFaultLabel(QLabel&, FaultLabel);

    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    AuxBmsPresenter& auxBmsPresenter_;
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

    double busCurrent_;
    double busVoltage_;
    double mpptZeroPower_;
    double mpptOnePower_;
    double mpptTwoPower_;
    double mpptThreePower_;

private slots:
    // battery data slots
    void aliveReceived(bool);
    void prechargeStateReceived(QString);
    void packNetPowerReceived(double);
    void auxVoltageReceived(int);
    void packStateOfChargeReceived(double);
    void lowCellVoltageReceived(float);
    void averageCellVoltageReceived(float);
    void highTemperatureReceived(int);
    void averageTemperatureReceived(int);

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

    void setMotorPower();
};
