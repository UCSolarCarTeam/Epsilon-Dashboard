#pragma once

#include <QObject>
#include <QLabel>
#include <QLayout>
#include <QDebug>
#include <QScrollBar>

#include "../../../../DataLayer/MotorFaultsData/ErrorFlags.h"
#include "../../../../DataLayer/MotorFaultsData/LimitFlags.h"
#include "../../../../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "../../../../PresenterLayer/MotorFaultsPresenter/MotorFaultsPresenter.h"
#include "../FaultUi/I_FaultUi.h"
#include "Faults/MotorFaults/MotorFaultList.h"

class MotorFaultsPresenter;
class BatteryFaultsPresenter;
class I_FaultUi;

class FaultView : public QObject
{
    Q_OBJECT
public:
    FaultView(MotorFaultsPresenter& motorFaultsPresenter,
              BatteryFaultsPresenter& batteryFaultsPresenter,
              I_FaultUi& ui,
              MotorFaultList motorZeroFaultList,
              MotorFaultList motorOneFaultList);
    ~FaultView();

private:
    void connectMotorFaults(MotorFaultsPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void initializeLabel(QLabel& label, QLayout*& layout, QString& styleSheet);
    void initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB);
    void updateLabel(const bool& receivedValue, QLabel& label, QWidget& contentsWidget, int& labelCount);

    MotorFaultsPresenter& motorFaultsPresenter_;
    BatteryFaultsPresenter& batteryFaultsPresenter_;

    I_FaultUi& ui_;

    // Motor 0
    MotorFaultList motorZeroFaultList_;
    int label0Count_;

    // Motor 1
    MotorFaultList motorOneFaultList_;
    int label1Count_;

    // Battery
    QLabel alwaysOnSupplyFault_;
    QLabel canbusCommunicationsFault_;
    QLabel chargeLimitEnforcementFault_;
    QLabel chargerSafetyRelayFault_;
    QLabel currentSensorFault_;
    QLabel dischargeLimitEnforcementFault_;
    QLabel fanMonitorFault_;
    QLabel highVoltageIsolationFault_;
    QLabel internalCommununicationFault_;
    QLabel internalConversionFault_;
    QLabel internalLogicFault_;
    QLabel internalMemoryFault_;
    QLabel internalThermistorFault_;
    QLabel lowCellVoltageFault_;
    QLabel openWiringFault_;
    QLabel packVoltageSensorFault_;
    QLabel powerSupplyFault12V_;
    QLabel thermistorFault_;
    QLabel voltageRedundancyFault_;
    QLabel weakCellFault_;
    QLabel weakPackFault_;

    QLabel cclReducedDueToAlternateCurrentLimit_;
    QLabel cclReducedDueToChargerLatch_;
    QLabel cclReducedDueToHighCellResistance_;
    QLabel cclReducedDueToHighCellVoltage_;
    QLabel cclReducedDueToHighPackVoltage_;
    QLabel cclReducedDueToHighSoc_;
    QLabel cclReducedDueToTemperature_;
    QLabel dclandCclReducedDueToCommunicationFailsafe_;
    QLabel dclandCclReducedDueToVoltageFailsafe_;
    QLabel dclReducedDueToHighCellResistance_;
    QLabel dclReducedDueToLowCellVoltage_;
    QLabel dclReducedDueToLowPackVoltage_;
    QLabel dclReducedDueToLowSoc_;
    QLabel dclReducedDueToTemperature_;
    int labelBCount_;

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

