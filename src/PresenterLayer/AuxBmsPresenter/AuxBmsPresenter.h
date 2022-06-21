# pragma once

#include <QObject>

class I_AuxBmsData;

class AuxBmsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AuxBmsPresenter(const I_AuxBmsData& auxBmsData);

private:
    void relayAuxBmsData();

    const I_AuxBmsData& auxBmsData_;

signals:
    void prechargeStateReceived(const QString&);
    void auxVoltageReceived(const int);
    void auxBmsAliveReceived(const bool);
    void strobeBmsLightReceived(const bool);
    void allowChargeReceived(const bool);
    void chargeTripHighTemperatureCurrentReceived(const bool);
    void chargeTripHighVoltageReceived(const bool);
    void chargeTripPackCurrentReceived(const bool);
    void dischargeTripPackCurrentReceived(const bool);
    void dischargeTripHighTemperatureCurrentReceived(const bool);
    void dischargeTripLowVoltageReceived(const bool);
    void protectionTripReceived(const bool);
    void highVoltageEnableStateReceived(const bool);
    void allowDischargeReceived(const bool);
    void orionCanReceivedRecentlyReceived(const bool);
    void chargeContactorErrorReceived(const bool);
    void dischargeContactorErrorReceived(const bool);
    void commonContactorErrorReceived(const bool);
    void dischargeShouldTripReceived(const bool);
    void chargeShouldTripReceived(const bool);
    void chargeOpenButShouldBeClosedReceived(const bool);
    void dischargeOpenButShouldBeClosedReceived(const bool);
    void tripContactorDisconnectedUnexpectedlyReceived(const bool);
    void tripOrionMessageTimeoutReceived(const bool);
    void dischargeNotClosedHighCurrentReceived(const bool);
    void chargeNotClosedHighCurrentReceived(const bool);
};
