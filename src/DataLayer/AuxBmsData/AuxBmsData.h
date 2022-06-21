#pragma once

#include "I_AuxBmsData.h"

class AuxBmsData : public I_AuxBmsData
{
public:
    AuxBmsData();
    virtual ~AuxBmsData();

    /* Data getter */
    QString prechargeState() const override;
    int auxVoltage() const override;
    bool auxBmsAlive() const override;
    bool strobeBmsLight() const override;
    bool allowCharge() const override;
    bool chargeTripHighTemperatureCurrent() const override;
    bool chargeTripHighVoltage() const override;
    bool chargeTripPackCurrent() const override;
    bool dischargeTripPackCurrent() const override;
    bool dischargeTripHighTemperatureCurrent() const override;
    bool dischargeTripLowVoltage() const override;
    bool protectionTrip() const override;
    bool highVoltageEnableState() const override;
    bool allowDischarge() const override;
    bool orionCanReceivedRecently() const override;
    bool chargeContactorError() const override;
    bool dischargeContactorError() const override;
    bool commonContactorError() const override;
    bool dischargeShouldTrip() const override;
    bool chargeShouldTrip() const override;
    bool chargeOpenButShouldBeClosed() const override;
    bool dischargeOpenButShouldBeClosed() const override;
    bool tripContactorDisconnectedUnexpectedly() const override;
    bool tripOrionMessageTimeout() const override;
    bool dischargeNotClosedHighCurrent() const override;
    bool chargeNotClosedHighCurrent() const override;



    /* Data setter */
    void setPrechargeState(const QString& prechargeState) override;
    void setAuxVoltage(const int auxVoltage) override;
    void setAuxBmsAlive(const bool auxBmsAlive) override;
    void setStrobeBmsLight(const bool strobeBmsLight) override;
    void setAllowCharge(const bool allowCharge) override;
    void setChargeTripHighTemperatureCurrent(const bool highTemperatureCurrent) override;
    void setChargeTripHighVoltage(const bool highVoltage) override;
    void setChargeTripPackCurrent(const bool packCurrrent) override;
    void setDischargeTripPackCurrent(const bool packCurrrent) override;
    void setDischargeTripHighTemperatureCurrent(const bool highTemperatureCurrent) override;
    void setDischargeTripLowVoltage(const bool lowVoltage) override;
    void setProtectionTrip(const bool protectionTrip) override;
    void setHighVoltageEnableState(const bool highVoltageEnableState) override;
    void setAllowDischarge(const bool allowDischarge) override;
    void setOrionCanReceivedRecently(const bool orionCanReceivedRecently) override;
    void setChargeContactorError(const bool chargeContactorError) override;
    void setDischargeContactorError(const bool dischargeContactorError) override;
    void setCommonContactorError(const bool commonContactorError) override;
    void setDischargeShouldTrip(const bool dischargeShouldTrip) override;
    void setChargeShouldTrip(const bool chargeShouldTrip) override;
    void setChargeOpenButShouldBeClosed(const bool chargeOpenButShouldBeClosed) override;
    void setDischargeOpenButShouldBeClosed(const bool dischargeOpenButShouldBeClosed) override;
    void setTripContactorDisconnectedUnexpectedly(const bool tripContactorDisconnectedUnexpectedly) override;
    void setTripOrionMessageTimeout(const bool tripOrionMessageTimeout) override;
    void setDischargeNotClosedHighCurrent(const bool dischargeNotClosedHighCurrent) override;
    void setChargeNotClosedHighCurrent(const bool chargeNotClosedHighCurrent) override;

private:
    QString prechargeState_;
    int auxVoltage_;
    bool auxBmsAlive_;
    bool strobeBmsLight_;
    bool allowCharge_;
    bool chargeTripHighTemperatureCurrent_;
    bool chargeTripHighVoltage_;
    bool chargeTripPackCurrent_;
    bool dischargeTripPackCurrent_;
    bool dischargeTripHighTemperatureCurrent_;
    bool dischargeTripLowVoltage_;
    bool protectionTrip_;
    bool highVoltageEnableState_;
    bool allowDischarge_;
    bool orionCanReceivedRecently_;
    bool chargeContactorError_;
    bool dischargeContactorError_;
    bool commonContactorError_;
    bool dischargeShouldTrip_;
    bool chargeShouldTrip_;
    bool chargeOpenButShouldBeClosed_;
    bool dischargeOpenButShouldBeClosed_;
    bool tripContactorDisconnectedUnexpectedly_;
    bool tripOrionMessageTimeout_;
    bool dischargeNotClosedHighCurrent_;
    bool chargeNotClosedHighCurrent_;

};
