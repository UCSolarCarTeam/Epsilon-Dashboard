#pragma once

#include <QObject>
#include <QLabel>
#include <QScopedPointer>

#include "../../../DataLayer/MpptData/Mppt.h"
#include "../../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../../PresenterLayer/AuxBmsPresenter/AuxBmsPresenter.h"
#include "../../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "../../../PresenterLayer/DriverControlsPresenter/DriverControlsPresenter.h"
#include "../../../PresenterLayer/KeyMotorPresenter/KeyMotorPresenter.h"
#include "../../../PresenterLayer/LightsPresenter/LightsPresenter.h"
#include "../../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../../../PresenterLayer/MotorDetailsPresenter/MotorDetailsPresenter.h"
#include "../../../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "../DisplayDashboardUI/I_DisplayDashboardUI.h"
#include "Faults/BatteryFaults/BatteryFaultList.h"
#include "Faults/MotorFaults/MotorFaultList.h"


class AuxBmsPresenter;
class BatteryPresenter;
class BatteryFaultsPresenter;
class DriverControlsPresenter;
class I_DisplayDashboardUI;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;
class QTimer;

class DisplayDashboardView : public QObject
{
    Q_OBJECT
public:
    DisplayDashboardView(AuxBmsPresenter& auxBmsPresenter,
                         BatteryPresenter& batteryPresenter,
                         BatteryFaultsPresenter& batteryFaultsPresenter,
                         DriverControlsPresenter& driverControlsPresenter,
                         KeyMotorPresenter& keyMotorPresenter,
                         LightsPresenter& lightsPresenter,
                         MpptPresenter& mpptPresenter,
                         MotorDetailsPresenter& motorDetailsPresenter,
                         MotorFaultsPresenter& motorFaultsPresenter,
                         I_DisplayDashboardUI& ui,
                         MotorFaultList& motorZeroFaultsList,
                         MotorFaultList& motorOneFaultsList,
                         BatteryFaultList& batteryFaultsList);
    ~DisplayDashboardView();

private:
    void connectAuxBms(AuxBmsPresenter&);
    void connectBattery(BatteryPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void connectMotorFaults(MotorFaultsPresenter&);

    void updateFaultLabel(QLabel&, FaultLabel);
    void updateDriveStateLabel();

    AuxBmsPresenter& auxBmsPresenter_;
    BatteryPresenter& batteryPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MpptPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    MotorFaultsPresenter& motorFaultsPresenter_;
    I_DisplayDashboardUI& ui_;
    MotorFaultList& motorZeroFaultsList_;
    MotorFaultList& motorOneFaultsList_;
    BatteryFaultList& batteryFaultsList_;

    //used in mpptReceived
    double mpptZeroPower_;
    double mpptOnePower_;
    double mpptTwoPower_;
    double mpptThreePower_;
    QScopedPointer<QTimer> faultsTimer_;

    bool aux_;
    bool forward_;
    bool reverse_;

private slots:
    // auxBms data slots
    void prechargeStateReceived(QString);

    // battery data slots
    void aliveReceived(bool);
    void packNetPowerReceived(double);
    void packStateOfChargeReceived(double);
    void highTemperatureReceived(int);
    void lowCellVoltageReceived(float);
    void averageTemperatureReceived(int);
    void averageCellVoltageReceived(float);

    // battery faults slots
    void errorFlagsReceived(BatteryErrorFlags);
    void limitFlagsReceived(BatteryLimitFlags);

    // driver controls slots
    void resetReceived(bool);
    void auxReceived(bool);
    void forwardReceived(bool);
    void reverseReceived(bool);

    // key motor slots
    void motorSetPowerReceived(double);
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

    void updateBatteryFaults();
    void updateMotor0Faults();
    void updateMotor1Faults();
};
