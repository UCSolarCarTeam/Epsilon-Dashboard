#pragma once

#include <QObject>
#include <QLabel>
#include <QScopedPointer>

#include "../../DataLayer/MpptData/Mppt.h"
#include "../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../DataLayer/KeyMotorData/KeyMotor.h"

class BatteryPresenter;
class AuxBmsPresenter;
class DriverControlsPresenter;
class I_RaceModeDashboardUI;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class QTimer;
class QPropertyAnimation;
class QGraphicsColorizeEffect;
class I_BatteryFaultList;
class I_MotorFaultList;
class FaultDisplayData;

class RaceModeDashboardView : public QObject
{
    Q_OBJECT
public:
    RaceModeDashboardView(BatteryPresenter& batteryPresenter,
                          AuxBmsPresenter& auxBmsPresenter,
                          DriverControlsPresenter& driverControlsPresenter,
                          KeyMotorPresenter& keyMotorPresenter,
                          LightsPresenter& lightsPresenter,
                          MpptPresenter& mpptPresenter,
                          MotorDetailsPresenter& motorDetailsPresenter,
                          I_RaceModeDashboardUI& ui,
                          I_MotorFaultList& motorZeroFaultsList,
                          I_MotorFaultList& motorOneFaultsList,
                          I_BatteryFaultList& batteryFaultsList);
    ~RaceModeDashboardView();

private:
    void connectBattery(BatteryPresenter&);
    void connectAuxBms(AuxBmsPresenter&);
    void connectDriverControls(DriverControlsPresenter&);
    void connectKeyMotor(KeyMotorPresenter&);
    void connectLights(LightsPresenter&);
    void connectMppt(MpptPresenter&);
    void connectMotorDetails(MotorDetailsPresenter&);
    void updateFaultLabel(QLabel&, FaultDisplayData);
    void initalizeFaultAnimation();
    void reverseFaultAnimation();
    bool faultAnimationCheck(QVector<QString>& currentFaults, QVector<QString>& prevFaults);
    void updateDriveStateLabel();

    BatteryPresenter& batteryPresenter_;
    AuxBmsPresenter& auxBmsPresenter_;
    DriverControlsPresenter& driverControlsPresenter_;
    KeyMotorPresenter& keyMotorPresenter_;
    LightsPresenter& lightsPresenter_;
    MpptPresenter& mpptPresenter_;
    MotorDetailsPresenter& motorDetailsPresenter_;
    I_RaceModeDashboardUI& ui_;
    I_MotorFaultList& motorZeroFaultsList_;
    I_MotorFaultList& motorOneFaultsList_;
    I_BatteryFaultList& batteryFaultsList_;

    QScopedPointer<QPropertyAnimation> faultAnimation_;
    QScopedPointer<QGraphicsColorizeEffect> fadeEffect_;
    QVector<QString> prevMotorOneFaults_;
    QVector<QString> prevMotorZeroFaults_;
    QVector<QString> prevBatteryFaults_;

    double busCurrent_;
    double busVoltage_;
    double mpptZeroPower_;
    double mpptOnePower_;
    double mpptTwoPower_;
    double mpptThreePower_;
    QScopedPointer<QTimer> faultsTimer_;

    bool aux_;
    bool forward_;
    bool reverse_;
    double totalSpeed_;
    int updateCount_;\
    bool lap_;

private slots:
    // battery data slots
    void aliveReceived(bool);
    void prechargeStateReceived(QString);
    void packNetPowerReceived(double);
    void auxVoltageReceived(int);
    void packStateOfChargeReceived(double);
    void lowCellVoltageReceived(float);
    void highCellVoltageReceived(float);
    void highTemperatureReceived(int);
    void averageTemperatureReceived(int);

    // driver controls slots
    void resetReceived(bool);
    void auxReceived(bool);
    void forwardReceived(bool);
    void reverseReceived(bool);
    void lapReceived(bool);

    // key motor slots
    void motorActualSpeedReceived(double);
    void motorZeroReceived(KeyMotor motorZero);
    void motorOneReceived(KeyMotor motorZero);
    void motorZeroBusPowerReceived(double motorPower);
    void motorOneBusPowerReceived(double motorPower);

    // lights slots
    void lowBeamsReceived(bool);
    void leftSignalReceived(bool);
    void rightSignalReceived(bool);
    void lightAliveReceived(bool);

    // mppt slots
    void mpptReceived(int, Mppt);
    void mpptPowerReceived(double);

    // faults slots
    void updateBatteryFaults();
    void updateMotor0Faults();
    void updateMotor1Faults();
    void runFaultAnimation();
};
