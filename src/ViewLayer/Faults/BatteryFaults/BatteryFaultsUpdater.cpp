#include "BatteryFaultsUpdater.h"
#include "../PresenterLayer/BatteryFaultsPresenter/BatteryFaultsPresenter.h"
#include "../PresenterLayer/AuxBmsPresenter/AuxBmsPresenter.h"
#include "BatteryFaultsResources.h"
#include "Faults/FaultLabel/FaultDisplayData.h"
#include "I_BatteryFaultList.h"

BatteryFaultsUpdater::BatteryFaultsUpdater(const BatteryFaultsPresenter& batteryFaultsPresenter,
        const AuxBmsPresenter& auxBmsPresenter,
        I_BatteryFaultList& faultList)
    : batteryFaultsPresenter_(batteryFaultsPresenter)
    , auxBmsPresenter_(auxBmsPresenter)
    , faultList_(faultList)
{
    connect(&batteryFaultsPresenter_, SIGNAL(errorFlagsReceived(BatteryErrorFlags)),
            this, SLOT(errorFlagsReceived(BatteryErrorFlags)));
    connect(&batteryFaultsPresenter_, SIGNAL(limitFlagsReceived(BatteryLimitFlags)),
            this, SLOT(limitFlagsReceived(BatteryLimitFlags)));

    connectAuxBmsTrips(auxBmsPresenter);
}


void BatteryFaultsUpdater::connectAuxBmsTrips(const AuxBmsPresenter& auxBmsPresenter)
{
    connect(&auxBmsPresenter, SIGNAL(chargeContactorErrorReceived(const bool)),
            this, SLOT(chargeContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeContactorErrorReceived(const bool)),
            this, SLOT(dischargeContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(commonContactorErrorReceived(const bool)),
            this, SLOT(commonContactorErrorReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeShouldTripReceived(const bool)),
            this, SLOT(dischargeShouldTripReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeShouldTripReceived(const bool)),
            this, SLOT(chargeShouldTripReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeOpenButShouldBeClosedReceived(const bool)),
            this, SLOT(chargeOpenButShouldBeClosedReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeOpenButShouldBeClosedReceived(const bool)),
            this, SLOT(dischargeOpenButShouldBeClosedReceived(const bool)));

    connect(&auxBmsPresenter, SIGNAL(chargeTripHighTemperatureCurrentReceived(const bool)),
            this, SLOT(chargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeTripHighVoltageReceived(const bool)),
            this, SLOT(chargeTripHighVoltageReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(chargeTripPackCurrentReceived(const bool)),
            this, SLOT(chargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripPackCurrentReceived(const bool)),
            this, SLOT(dischargeTripPackCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripHighTemperatureCurrentReceived(const bool)),
            this, SLOT(dischargeTripHighTemperatureCurrentReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(dischargeTripLowVoltageReceived(const bool)),
            this, SLOT(dischargeTripLowVoltageReceived(const bool)));
    connect(&auxBmsPresenter, SIGNAL(protectionTripReceived(const bool)),
            this, SLOT(protectionTripReceived(const bool)));
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

//Slots for Aux BMS trips
void BatteryFaultsUpdater::chargeContactorErrorReceived(const bool chargeContactorError)
{
    faultList_.faults()[BatteryFaults::CHARGE_CONTACTOR_ERRROR].setActive(chargeContactorError);
}

void BatteryFaultsUpdater::dischargeContactorErrorReceived(const bool dischargeContactorError)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_CONTACTOR_ERROR].setActive(dischargeContactorError);
}

void BatteryFaultsUpdater::commonContactorErrorReceived(const bool commonContactorError)
{
    faultList_.faults()[BatteryFaults::COMMON_CONTACTOR_ERROR].setActive(commonContactorError);
}

void BatteryFaultsUpdater::dischargeShouldTripReceived(const bool dischargeShouldTrip)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_SHOULD_TRIP].setActive(dischargeShouldTrip);
}

void BatteryFaultsUpdater::chargeShouldTripReceived(const bool chargeShouldTrip)
{
    faultList_.faults()[BatteryFaults::CHARGE_SHOULD_TRIP].setActive(chargeShouldTrip);
}

void BatteryFaultsUpdater::chargeOpenButShouldBeClosedReceived(const bool chargeOpenButShouldBeClosed)
{
    faultList_.faults()[BatteryFaults::CHARGE_OPEN_BUT_SHOULD_BE_CLOSED].setActive(chargeOpenButShouldBeClosed);
}

void BatteryFaultsUpdater::dischargeOpenButShouldBeClosedReceived(const bool dischargeOpenButShouldBeClosed)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_OPEN_BUT_SHOULD_BE_CLOSED].setActive(dischargeOpenButShouldBeClosed);
}

void BatteryFaultsUpdater::chargeTripHighTemperatureCurrentReceived(const bool highTemperatureCurrent)
{
   faultList_.faults()[BatteryFaults::CHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT].setActive(highTemperatureCurrent);
}

void BatteryFaultsUpdater::chargeTripHighVoltageReceived(const bool highVoltage)
{
   faultList_.faults()[BatteryFaults::CHARGE_TRIP_DUE_TO_HIGH_CELL_VOLTAGE].setActive(highVoltage);
}

void BatteryFaultsUpdater::chargeTripPackCurrentReceived(const bool chargeTripPackCurrent)
{
    faultList_.faults()[BatteryFaults::CHARGE_TRIP_DUE_TO_PACK_CURRENT].setActive(chargeTripPackCurrent);
}

void BatteryFaultsUpdater::dischargeTripPackCurrentReceived(const bool dischargeTripPackCurrent)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_TRIP_DUE_TO_PACK_CURRENT].setActive(dischargeTripPackCurrent);
}

void BatteryFaultsUpdater::dischargeTripHighTemperatureCurrentReceived(const bool dischargeTripHighTemperatureCurrent)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_TRIP_DUE_TO_HIGH_TEMPERATURE_AND_CURRENT].setActive(dischargeTripHighTemperatureCurrent);
}

void BatteryFaultsUpdater::dischargeTripLowVoltageReceived(const bool lowVoltage)
{
    faultList_.faults()[BatteryFaults::DISCHARGE_TRIP_DUE_TO_LOW_CELL_VOLTAGE].setActive(lowVoltage);
}

void BatteryFaultsUpdater::protectionTripReceived(const bool protectionTrip)
{
    faultList_.faults()[BatteryFaults::PROTECTION_TRIP].setActive(protectionTrip);
}

