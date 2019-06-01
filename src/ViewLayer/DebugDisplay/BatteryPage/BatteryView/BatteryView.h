#pragma once
#include <QObject>
#include <QLabel>
#include <QList>
#include <QWidget>

#include "../../../../DataLayer/BatteryData/BatteryData.h"
#include "../../../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../BatteryPage/BatteryUi/I_BatteryUi.h"
#include "../ProgressBar.h"
#include "../BatteryUi/BatteryUi.h"
#include "../../../../PresenterLayer/AuxBmsPresenter/AuxBmsPresenter.h"

class BatteryPresenter;

class I_BatteryUi;

class ProgressBar;

class BatteryView : public QObject
{
    Q_OBJECT
public:
    BatteryView(BatteryPresenter& batteryPresenter,
                I_BatteryUi& ui, ProgressBar& bar,
                AuxBmsPresenter& auxBMSPresenter);
    ~BatteryView();
    void updateProgress(double stateOfCharge);

private:
    void connectBattery(BatteryPresenter&);
    void connectAuxBMS(AuxBmsPresenter&);

    BatteryPresenter& batteryPresenter_;
    I_BatteryUi& ui_;
    ProgressBar& bar_;
    AuxBmsPresenter& auxBMSPresenter_;

    QList<QWidget*> fanSpeedList_;
    QList<QWidget*> requestedFanSpeedList_;


private slots:
    void aliveReceived(const bool);
    void bmsRelayStatusReceived(BmsRelayStatusFlags);
    void populatedCellsReceived(const int);
    void inputVoltage12VReceived(const double);
    void fanVoltageReceived(const double);
    void packCurrentReceived(const double);
    void packVoltageReceived(const double);
    void packStateOfChargeReceived(const double);
    void packAmphoursReceived(const double);
    void packDepthOfDischargeReceived(const double);
    void highTemperatureReceived(const int);
    void highThermistorIdReceived(const int);
    void lowTemperatureReceived(const int);
    void lowThermistorIdReceived(const int);
    void averageTemperatureReceived(const int);
    void internalTemperatureReceived(const int);
    void fanSpeedReceived(const int);
    void requestedFanSpeedReceived(const int);
    void lowCellVoltageReceived(const float);
    void lowCellVoltageIdReceived(const int);
    void highCellVoltageReceived(const float);
    void highCellVoltageIdReceived(const int);
    void averageCellVoltageReceived(const float);
    void prechargeStateReceived(const QString);
    void auxVoltageReceived(const int);
    void auxBmsAliveReceived(const bool);
    void packBatteryPowerReceived(const double);
    void strobeBMSReceived(bool);
    void allowChargeReceived(bool);
    void contactorErrorReceived(bool);
    void highVoltageEnableReceived(bool);

};
