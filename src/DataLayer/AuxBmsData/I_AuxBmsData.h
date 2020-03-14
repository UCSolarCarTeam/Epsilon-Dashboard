#pragma once

#include <QObject>
#include <QString>

class I_AuxBmsData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_AuxBmsData() {}

    /* Data "Gets" */
    virtual QString prechargeState() const = 0;
    virtual int auxVoltage() const = 0;
    virtual bool auxBmsAlive() const = 0;
    virtual bool strobeBmsLight() const = 0;
    virtual bool allowCharge() const = 0;
    virtual bool chargeTripHighTemperatureCurrent() const = 0;
    virtual bool chargeTripHighVoltage() const = 0;
    virtual bool chargeTripPackCurrent() const = 0;
    virtual bool dischargeTripPackCurrent() const = 0;
    virtual bool dischargeTripHighTemperatureCurrent() const = 0;
    virtual bool dischargeTripLowVoltage() const = 0;
    virtual bool protectionTrip() const = 0;
    virtual bool highVoltageEnableState() const = 0;
    virtual bool allowDischarge() const = 0;
    virtual bool orionCanReceivedRecently() const = 0;
    virtual bool chargeContactorError() const = 0;
    virtual bool dischargeContactorError() const = 0;
    virtual bool commonContactorError() const = 0;
    virtual bool dischargeShouldTrip() const = 0;
    virtual bool chargeShouldTrip() const = 0;
    virtual bool chargeOpenButShouldBeClosed() const = 0;
    virtual bool dischargeOpenButShouldBeClosed() const = 0;
    /* Data "Sets" */
    virtual void setPrechargeState(const QString&) = 0;
    virtual void setAuxVoltage(const int) = 0;
    virtual void setAuxBmsAlive(const bool) = 0;
    virtual void setStrobeBmsLight(const bool) = 0;
    virtual void setAllowCharge(const bool) = 0;
    virtual void setChargeTripHighTemperatureCurrent(const bool) = 0;
    virtual void setChargeTripHighVoltage(const bool) = 0;
    virtual void setChargeTripPackCurrent(const bool) = 0;
    virtual void setDischargeTripPackCurrent(const bool) = 0;
    virtual void setDischargeTripHighTemperatureCurrent(const bool) = 0;
    virtual void setDischargeTripLowVoltage(const bool) = 0;
    virtual void setProtectionTrip(const bool) = 0;
    virtual void setHighVoltageEnableState(const bool) = 0;
    virtual void setAllowDischarge(const bool) = 0;
    virtual void setOrionCanReceivedRecently(const bool) = 0;
    virtual void setChargeContactorError(const bool) = 0;
    virtual void setDischargeContactorError(const bool) = 0;
    virtual void setCommonContactorError(const bool) = 0;
    virtual void setDischargeShouldTrip(const bool) = 0;
    virtual void setChargeShouldTrip(const bool) = 0;
    virtual void setChargeOpenButShouldBeClosed(const bool) = 0;
    virtual void setDischargeOpenButShouldBeClosed(const bool) = 0;

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
};
