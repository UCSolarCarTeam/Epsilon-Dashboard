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

class I_FaultUi;

class FaultView : public QObject
{
    Q_OBJECT
public:
    FaultView(I_FaultUi& ui,
              I_MotorFaultList& motorZeroFaultList,
              I_MotorFaultList& motorOneFaultList,
              I_BatteryFaultList& batteryFaultList);
    ~FaultView();

private:
    void initializeLabel(FaultDisplayData& label, QLayout*& layout, QString& styleSheet);
    void initializeLabels(QLayout*& layoutM0, QLayout*& layoutM1, QLayout*& layoutB);
    void updateLabel(FaultDisplayData& label);
    void updateLabelListHeight(QWidget& contentsWidget, int& labelCount);
    void updateBatteryFaults();
    void updateMotor0Faults();
    void updateMotor1Faults();

    I_FaultUi& ui_;

    QMap<QString, QLabel*> faultLabelList_;

    // Motor 0
    I_MotorFaultList& motorZeroFaultList_;
    int label0Count_;

    // Motor 1
    I_MotorFaultList& motorOneFaultList_;
    int label1Count_;

    // Battery
    I_BatteryFaultList& batteryFaultList_;
    int labelBCount_;
};

