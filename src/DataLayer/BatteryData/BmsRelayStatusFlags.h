#pragma once

class BmsRelayStatusFlags
{
public:
    BmsRelayStatusFlags();

    bool dischargeRelayEnabled() const;
    bool chargeRelayEnabled() const;
    bool chargerSafetyEnabled() const;
    bool malfunctionIndicatorActive() const;
    bool multiPurposeInputSignalStatus() const;
    bool alwaysOnSignalStatus() const;
    bool isReadySignalStatus() const;
    bool isChargingSignalStatus() const;

    void setDischargeRelayEnabled(bool dischargeRelayEnabled);
    void setChargeRelayEnabled(bool chargeRelayEnabled);
    void setChargerSafetyEnabled(bool chargerSafetyEnabled);
    void setMalfunctionIndicatorActive(bool malfunctionIndicatorActive);
    void setMultiPurposeInputSignalStatus(bool multiPurposeInputSignalStatus);
    void setAlwaysOnSignalStatus(bool alwaysOnSignalStatus);
    void setIsReadySignalStatus(bool isReadySignalStatus);
    void setIsChargingSignalStatus(bool isChargingSignalStatus);

private:
    bool dischargeRelayEnabled_;
    bool chargeRelayEnabled_;
    bool chargerSafetyEnabled_;
    bool malfunctionIndicatorActive_;
    bool multiPurposeInputSignalStatus_;
    bool alwaysOnSignalStatus_;
    bool isReadySignalStatus_;
    bool isChargingSignalStatus_;
};
