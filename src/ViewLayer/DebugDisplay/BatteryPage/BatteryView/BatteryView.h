#pragma once
#include <QObject>
#include <QLabel>

#include "../../../../DataLayer/BatteryData/BatteryData.h"
#include "../../../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../BatteryPage/BatteryUi/I_BatteryUi.h"

class BatteryPresenter;

class BatteryView : public QObject
{
    Q_OBJECT
public:
    BatteryView(BatteryPresenter& batteryPresenter,
                I_BatteryUi& ui);
    ~BatteryView();

private:
    void connectBattery(BatteryPresenter&);

    BatteryPresenter& batteryPresenter_;

    I_BatteryUi& ui_;

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
    void lowCellVoltageReceived(const int);
    void lowCellVoltageIdReceived(const int);
    void highCellVoltageReceived(const int);
    void highCellVoltageIdReceived(const int);
    void averageCellVoltageReceived(const int);
    void prechargeStateReceived(const QString);
    void auxVoltageReceived(const int);
    void auxBmsAliveReceived(const bool);
    void packNetPowerReceived(const double);
