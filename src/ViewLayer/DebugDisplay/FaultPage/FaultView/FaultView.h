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
#include "Faults/BatteryFaults/BatteryFaultList.h"
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
              MotorFaultList motorOneFaultList,
              BatteryFaultList batteryFaultList);
    ~FaultView();

private:
    void connectMotorFaults(MotorFaultsPresenter&);
    void connectBatteryFaults(BatteryFaultsPresenter&);
    void initializeLabel(FaultLabel& label, QLayout*& layout, QString& styleSheet);
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
    BatteryFaultList batteryFaultList_;
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

