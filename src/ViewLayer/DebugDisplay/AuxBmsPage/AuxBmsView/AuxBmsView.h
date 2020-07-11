#pragma once
#include <QObject>

class AuxBmsPresenter;
class I_AuxBmsUi;

class AuxBmsView : public QObject
{
    Q_OBJECT
public:
    AuxBmsView(AuxBmsPresenter& auxBmsPresenter,
               I_AuxBmsUi& ui);
    ~AuxBmsView() = default;

private slots:
    void prechargeStateReceived(const QString prechargeState);
    void auxVoltageReceived(const int auxVoltage);
    void auxBmsAliveReceived(const bool auxBmsAlive);
    void strobeBmsReceived(const bool strobe);
    void allowChargeReceived(const bool allowCharge);
    void chargeTripHighTemperatureCurrentReceived(const bool chargeTripHighTemperatureCurrent);
    void chargeTripHighVoltageReceived(const bool chargeTripHighVoltage);
    void chargeTripPackCurrentReceived(const bool chargeTripPackCurrent);
    void dischargeTripPackCurrentReceived(const bool dischargeTripPackCurrent);
    void dischargeTripHighTemperatureCurrentReceived(const bool dischargeTripHighTemperatureCurrent);
    void dischargeTripLowVoltageReceived(const bool dischargeTripLowVoltage);
    void protectionTripReceived(const bool protectionTrip);
    void highVoltageEnableStateReceived(const bool highVoltageEnableState);
    void allowDischargeReceived(const bool allowDischarge);
    void orionCanReceivedRecentlyReceived(const bool orionCanReceivedRecently);
    void chargeContactorErrorReceived(const bool chargeContactorError);
    void dischargeContactorErrorReceived(const bool dischargeContactorError);
    void commonContactorErrorReceived(const bool commonContactorError);
    void dischargeShouldTripReceived(const bool dischargeShouldTrip);
    void chargeShouldTripReceived(const bool chargeShouldTrip);
    void chargeOpenButShouldBeClosedReceived(const bool chargeOpenButShouldBeClosed);
    void dischargeOpenButShouldBeClosedReceived(const bool dischargeOpenButShouldBeClosed);
private:
    void connectAuxBms(AuxBmsPresenter& auxBmsPresenter);
    AuxBmsPresenter& presenter_;
    I_AuxBmsUi& ui_;
};

