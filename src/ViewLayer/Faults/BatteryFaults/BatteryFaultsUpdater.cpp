#include "BatteryFaultsUpdater.h"
#include "../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "BatteryFaultsResources.h"
#include "Faults/FaultLabel/FaultDisplayData.h"
#include "I_BatteryFaultList.h"

BatteryFaultsUpdater::BatteryFaultsUpdater(const BatteryFaultsPresenter& presenter,
        I_BatteryFaultList& faultList)
    : batteryFaultsPresenter_(presenter)
    , faultList_(faultList)
{
    connect(&batteryFaultsPresenter_, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter_, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));
}

void BatteryFaultsUpdater::errorFlagsReceived(BatteryErrorFlags errorFlags)
{
    QMap<BatteryFaults, FaultDisplayData>& faults = faultList_.faults();

    if (faults.contains(BatteryFaults::INTERNAL_COMMUNICATION_FAULT))
    {
        faults[BatteryFaults::INTERNAL_COMMUNICATION_FAULT].setActive(errorFlags.internalCommununicationFault());
    }

    if (faults.contains(BatteryFaults::INTERNAL_CONVERSION_FAULT))
    {
        faults[BatteryFaults::INTERNAL_CONVERSION_FAULT].setActive(errorFlags.internalConversionFault());
    }

    if (faults.contains(BatteryFaults::WEAK_CELL_FAULT))
    {
        faults[BatteryFaults::WEAK_CELL_FAULT].setActive(errorFlags.weakCellFault());
    }

    if (faults.contains(BatteryFaults::LOW_CELL_VOLTAGE_FAULT))
    {
        faults[BatteryFaults::LOW_CELL_VOLTAGE_FAULT].setActive(errorFlags.lowCellVoltageFault());
    }

    if (faults.contains(BatteryFaults::OPEN_WIRING_FAULT))
    {
        faults[BatteryFaults::OPEN_WIRING_FAULT].setActive(errorFlags.openWiringFault());
    }

    if (faults.contains(BatteryFaults::CURRENT_SENSOR_FAULT))
    {
        faults[BatteryFaults::CURRENT_SENSOR_FAULT].setActive(errorFlags.currentSensorFault());
    }

    if (faults.contains(BatteryFaults::PACK_VOLTAGE_SENSOR))
    {
        faults[BatteryFaults::PACK_VOLTAGE_SENSOR].setActive(errorFlags.packVoltageSensorFault());
    }

    if (faults.contains(BatteryFaults::VOLTAGE_REDUNDANCY_FAULT))
    {
        faults[BatteryFaults::VOLTAGE_REDUNDANCY_FAULT].setActive(errorFlags.voltageRedundancyFault());
    }

    if (faults.contains(BatteryFaults::THERMISTOR_FAULT))
    {
        faults[BatteryFaults::THERMISTOR_FAULT].setActive(errorFlags.thermistorFault());
    }

    if (faults.contains(BatteryFaults::CANBUS_COMMUNICATIONS_FAULT))
    {
        faults[BatteryFaults::CANBUS_COMMUNICATIONS_FAULT].setActive(errorFlags.canbusCommunicationsFault());
    }

    if (faults.contains(BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT))
    {
        faults[BatteryFaults::HIGH_VOLTAGE_ISOLATION_FAULT].setActive(errorFlags.highVoltageIsolationFault());
    }

    if (faults.contains(BatteryFaults::POWER_SUPPLY_FAULT))
    {
        faults[BatteryFaults::POWER_SUPPLY_FAULT].setActive(errorFlags.powerSupplyFault12V());
    }

    if (faults.contains(BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT))
    {
        faults[BatteryFaults::CHARGE_LIMIT_ENFORCEMENT_FAULT].setActive(errorFlags.chargeLimitEnforcementFault());
    }

    if (faults.contains(BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT))
    {
        faults[BatteryFaults::DISCHARGE_LIMIT_ENFORCEMENT_FAULT].setActive(errorFlags.dischargeLimitEnforcementFault());
    }

    if (faults.contains(BatteryFaults::CHARGER_SAFETY_RELAY_FAULT))
    {
        faults[BatteryFaults::CHARGER_SAFETY_RELAY_FAULT].setActive(errorFlags.chargerSafetyRelayFault());
    }

    if (faults.contains(BatteryFaults::INTERNAL_THERMISTOR_FAULT))
    {
        faults[BatteryFaults::INTERNAL_THERMISTOR_FAULT].setActive(errorFlags.internalThermistorFault());
    }

    if (faults.contains(BatteryFaults::INTERNAL_LOGIC_FAULT))
    {
        faults[BatteryFaults::INTERNAL_LOGIC_FAULT].setActive(errorFlags.internalLogicFault());
    }

    if (faults.contains(BatteryFaults::WEAK_PACK_FAULT))
    {
        faults[BatteryFaults::WEAK_PACK_FAULT].setActive(errorFlags.weakPackFault());
    }

    if (faults.contains(BatteryFaults::INTERNAL_MEMORY_FAULT))
    {
        faults[BatteryFaults::INTERNAL_MEMORY_FAULT].setActive(errorFlags.internalMemoryFault());
    }

    if (faults.contains(BatteryFaults::FAN_MONITOR_FAULT))
    {
        faults[BatteryFaults::FAN_MONITOR_FAULT].setActive(errorFlags.fanMonitorFault());
    }

    if (faults.contains(BatteryFaults::ALWAYS_ON_SUPPLY_FAULT))
    {
        faults[BatteryFaults::ALWAYS_ON_SUPPLY_FAULT].setActive(errorFlags.alwaysOnSupplyFault());
    }
}

void BatteryFaultsUpdater::limitFlagsReceived(BatteryLimitFlags limitFlags)
{
    QMap<BatteryFaults, FaultDisplayData>& faults = faultList_.faults();

    if (faults.contains(BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE))
    {
        faults[BatteryFaults::DCL_REDUCED_DUE_TO_TEMPERATURE].setActive(limitFlags.dclReducedDueToTemperature());
    }

    if (faults.contains(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE))
    {
        faults[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE].setActive(limitFlags.dclReducedDueToLowCellVoltage());
    }

    if (faults.contains(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE))
    {
        faults[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE].setActive(limitFlags.dclReducedDueToLowPackVoltage());
    }

    if (faults.contains(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE))
    {
        faults[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE].setActive(limitFlags.dclandCclReducedDueToVoltageFailsafe());
    }

    if (faults.contains(BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE))
    {
        faults[BatteryFaults::DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE].setActive(limitFlags.dclandCclReducedDueToCommunicationFailsafe());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_SOC].setActive(limitFlags.cclReducedDueToHighSoc());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_TEMPERATURE].setActive(limitFlags.cclReducedDueToTemperature());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE].setActive(limitFlags.cclReducedDueToHighCellVoltage());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE].setActive(limitFlags.cclReducedDueToHighPackVoltage());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_CHARGER_LATCH].setActive(limitFlags.cclReducedDueToChargerLatch());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT].setActive(limitFlags.cclReducedDueToAlternateCurrentLimit());
    }

    if (faults.contains(BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC))
    {
        faults[BatteryFaults::DCL_REDUCED_DUE_TO_LOW_SOC].setActive(limitFlags.dclReducedDueToLowSoc());
    }

    if (faults.contains(BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE))
    {
        faults[BatteryFaults::DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE].setActive(limitFlags.dclReducedDueToHighCellResistance());
    }

    if (faults.contains(BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE))
    {
        faults[BatteryFaults::CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE].setActive(limitFlags.cclReducedDueToHighCellResistance());
    }
}

