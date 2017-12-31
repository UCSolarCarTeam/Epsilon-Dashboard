#pragma once

class BatteryErrorFlags
{
public:
    BatteryErrorFlags();

    /* getter */
    bool internalCommununicationFault() const;
    bool internalConversionFault() const;
    bool weakCellFault() const;
    bool lowCellVoltageFault() const;
    bool openWiringFault() const;
    bool currentSensorFault() const;
    bool packVoltageSensorFault() const;
    bool weakPackFault() const;
    bool voltageRedundancyFault() const;
    bool fanMonitorFault() const;
    bool thermistorFault() const;
    bool canbusCommunicationsFault() const;
    bool alwaysOnSupplyFault() const;
    bool highVoltageIsolationFault() const;
    bool powerSupplyFault12V() const;
    bool chargeLimitEnforcementFault() const;
    bool dischargeLimitEnforcementFault() const;
    bool chargerSafetyRelayFault() const;
    bool internalMemoryFault() const;
    bool internalThermistorFault() const;
    bool internalLogicFault() const;

    /* setter */
    void setInternalCommununicationFault(bool internalCommununicationFault);
    void setInternalConversionFault(bool internalConversionFault);
    void setWeakCellFault(bool weakCellFault);
    void setLowCellVoltageFault(bool lowCellVoltageFault);
    void setOpenWiringFault(bool openWiringFault);
    void setCurrentSensorFault(bool currentSensorFault);
    void setPackVoltageSensorFault(bool packVoltageSensorFault);
    void setWeakPackFault(bool weakPackFault);
    void setVoltageRedundancyFault(bool voltageRedundancyFault);
    void setFanMonitorFault(bool fanMonitorFault);
    void setThermistorFault(bool thermistorFault);
    void setCanbusCommunicationsFault(bool canbusCommunicationsFault);
    void setAlwaysOnSupplyFault(bool alwaysOnSupplyFault);
    void setHighVoltageIsolationFault(bool highVoltageIsolationFault);
    void setPowerSupplyFault12V(bool powerSupplyFault12V);
    void setChargeLimitEnforcementFault(bool chargeLimitEnforcementFault);
    void setDischargeLimitEnforcementFault(bool dischargeLimitEnforcementFault);
    void setChargerSafetyRelayFault(bool chargerSafetyRelayFault);
    void setInternalMemoryFault(bool internalMemoryFault);
    void setInternalThermistorFault(bool internalThermistorFault);
    void setInternalLogicFault(bool internalLogicFault);

private:
    bool internalCommununicationFault_;
    bool internalConversionFault_;
    bool weakCellFault_;
    bool lowCellVoltageFault_;
    bool openWiringFault_;
    bool currentSensorFault_;
    bool packVoltageSensorFault_;
    bool weakPackFault_;
    bool voltageRedundancyFault_;
    bool fanMonitorFault_;
    bool thermistorFault_;
    bool canbusCommunicationsFault_;
    bool alwaysOnSupplyFault_;
    bool highVoltageIsolationFault_;
    bool powerSupplyFault12V_;
    bool chargeLimitEnforcementFault_;
    bool dischargeLimitEnforcementFault_;
    bool chargerSafetyRelayFault_;
    bool internalMemoryFault_;
    bool internalThermistorFault_;
    bool internalLogicFault_;
};
