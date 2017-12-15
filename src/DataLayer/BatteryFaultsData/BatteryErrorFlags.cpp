#include "BatteryErrorFlags.h"

BatteryErrorFlags::BatteryErrorFlags()
    : internalCommununicationFault_(false)
    , internalConversionFault_(false)
    , weakCellFault_(false)
    , lowCellVoltageFault_(false)
    , openWiringFault_(false)
    , currentSensorFault_(false)
    , packVoltageSensorFault_(false)
    , weakPackFault_(false)
    , voltageRedundancyFault_(false)
    , fanMonitorFault_(false)
    , thermistorFault_(false)
    , canbusCommunicationsFault_(false)
    , alwaysOnSupplyFault_(false)
    , highVoltageIsolationFault_(false)
    , powerSupplyFault12V_(false)
    , chargeLimitEnforcementFault_(false)
    , dischargeLimitEnforcementFault_(false)
    , chargerSafetyRelayFault_(false)
    , internalMemoryFault_(false)
    , internalThermistorFault_(false)
    , internalLogicFault_(false)
{
}

bool BatteryErrorFlags::internalCommununicationFault() const
{
    return internalCommununicationFault_;
}

void BatteryErrorFlags::setInternalCommununicationFault(bool internalCommununicationFault)
{
    internalCommununicationFault_ = internalCommununicationFault;
}

bool BatteryErrorFlags::internalConversionFault() const
{
    return internalConversionFault_;
}

void BatteryErrorFlags::setInternalConversionFault(bool internalConversionFault)
{
    internalConversionFault_ = internalConversionFault;
}

bool BatteryErrorFlags::weakCellFault() const
{
    return weakCellFault_;
}

void BatteryErrorFlags::setWeakCellFault(bool weakCellFault)
{
    weakCellFault_ = weakCellFault;
}

bool BatteryErrorFlags::lowCellVoltageFault() const
{
    return lowCellVoltageFault_;
}

void BatteryErrorFlags::setLowCellVoltageFault(bool lowCellVoltageFault)
{
    lowCellVoltageFault_ = lowCellVoltageFault;
}

bool BatteryErrorFlags::openWiringFault() const
{
    return openWiringFault_;
}

void BatteryErrorFlags::setOpenWiringFault(bool openWiringFault)
{
    openWiringFault_ = openWiringFault;
}

bool BatteryErrorFlags::currentSensorFault() const
{
    return currentSensorFault_;
}

void BatteryErrorFlags::setCurrentSensorFault(bool currentSensorFault)
{
    currentSensorFault_ = currentSensorFault;
}

bool BatteryErrorFlags::packVoltageSensorFault() const
{
    return packVoltageSensorFault_;
}

void BatteryErrorFlags::setPackVoltageSensorFault(bool packVoltageSensorFault)
{
    packVoltageSensorFault_ = packVoltageSensorFault;
}

bool BatteryErrorFlags::weakPackFault() const
{
    return weakPackFault_;
}

void BatteryErrorFlags::setWeakPackFault(bool weakPackFault)
{
    weakPackFault_ = weakPackFault;
}

bool BatteryErrorFlags::voltageRedundancyFault() const
{
    return voltageRedundancyFault_;
}

void BatteryErrorFlags::setVoltageRedundancyFault(bool voltageRedundancyFault)
{
    voltageRedundancyFault_ = voltageRedundancyFault;
}

bool BatteryErrorFlags::fanMonitorFault() const
{
    return fanMonitorFault_;
}

void BatteryErrorFlags::setFanMonitorFault(bool fanMonitorFault)
{
    fanMonitorFault_ = fanMonitorFault;
}

bool BatteryErrorFlags::thermistorFault() const
{
    return thermistorFault_;
}

void BatteryErrorFlags::setThermistorFault(bool thermistorFault)
{
    thermistorFault_ = thermistorFault;
}

bool BatteryErrorFlags::canbusCommunicationsFault() const
{
    return canbusCommunicationsFault_;
}

void BatteryErrorFlags::setCanbusCommunicationsFault(bool canbusCommunicationsFault)
{
    canbusCommunicationsFault_ = canbusCommunicationsFault;
}

bool BatteryErrorFlags::alwaysOnSupplyFault() const
{
    return alwaysOnSupplyFault_;
}

void BatteryErrorFlags::setAlwaysOnSupplyFault(bool alwaysOnSupplyFault)
{
    alwaysOnSupplyFault_ = alwaysOnSupplyFault;
}

bool BatteryErrorFlags::highVoltageIsolationFault() const
{
    return highVoltageIsolationFault_;
}

void BatteryErrorFlags::setHighVoltageIsolationFault(bool highVoltageIsolationFault)
{
    highVoltageIsolationFault_ = highVoltageIsolationFault;
}

bool BatteryErrorFlags::powerSupplyFault12V() const
{
    return powerSupplyFault12V_;
}

void BatteryErrorFlags::setPowerSupplyFault12V(bool powerSupplyFault12V)
{
    powerSupplyFault12V_ = powerSupplyFault12V;
}

bool BatteryErrorFlags::chargeLimitEnforcementFault() const
{
    return chargeLimitEnforcementFault_;
}

void BatteryErrorFlags::setChargeLimitEnforcementFault(bool chargeLimitEnforcementFault)
{
    chargeLimitEnforcementFault_ = chargeLimitEnforcementFault;
}

bool BatteryErrorFlags::dischargeLimitEnforcementFault() const
{
    return dischargeLimitEnforcementFault_;
}

void BatteryErrorFlags::setDischargeLimitEnforcementFault(bool dischargeLimitEnforcementFault)
{
    dischargeLimitEnforcementFault_ = dischargeLimitEnforcementFault;
}

bool BatteryErrorFlags::chargerSafetyRelayFault() const
{
    return chargerSafetyRelayFault_;
}

void BatteryErrorFlags::setChargerSafetyRelayFault(bool chargerSafetyRelayFault)
{
    chargerSafetyRelayFault_ = chargerSafetyRelayFault;
}

bool BatteryErrorFlags::internalMemoryFault() const
{
    return internalMemoryFault_;
}

void BatteryErrorFlags::setInternalMemoryFault(bool internalMemoryFault)
{
    internalMemoryFault_ = internalMemoryFault;
}

bool BatteryErrorFlags::internalThermistorFault() const
{
    return internalThermistorFault_;
}

void BatteryErrorFlags::setInternalThermistorFault(bool internalThermistorFault)
{
    internalThermistorFault_ = internalThermistorFault;
}

bool BatteryErrorFlags::internalLogicFault() const
{
    return internalLogicFault_;
}

void BatteryErrorFlags::setInternalLogicFault(bool internalLogicFault)
{
    internalLogicFault_ = internalLogicFault;
}
