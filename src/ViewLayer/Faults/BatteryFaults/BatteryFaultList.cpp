#include "BatteryFaultList.h"

namespace
{
    int NUMBER_OF_BATTERY_ERRORS = 21;
    int NUMBER_OF_BATTERY_LIMITS = 14;
    //Battery errors
    QString INTERNAL_COMMUNICATION_FAULT = "Intern. Comms. Fault";
    QString INTERNAL_CONVERSION_FAULT = "Intern. Conv. Fault";
    QString WEAK_CELL_FAULT = "Weak Cell Fault";
    QString LOW_CELL_VOLTAGE_FAULT = "Low Cell Voltage Fault";
    QString OPEN_WIRING_FAULT = "Open Wiring Fault";
    QString CURRENT_SENSOR_FAULT = "Current Sensor Fault";
    QString PACK_VOLTAGE_SENSOR = "Pack Voltage Sensor";
    QString VOLTAGE_REDUNDANCY_FAULT = "Voltage Redundancy Fault";
    QString THERMISTOR_FAULT = "Thermistor Fault";
    QString CANBUS_COMMUNICATIONS_FAULT = "CANBUS Communications Fault";
    QString HIGH_VOLTAGE_ISOLATION_FAULT = "High Voltage Isolation Fault";
    QString POWER_SUPPLY_FAULT = "Power Supply Fault";
    QString CHARGE_LIMIT_ENFORCEMENT_FAULT = "Charge Limit Enforcement Fault";
    QString DISCHARGE_LIMIT_ENFORCEMENT_FAULT = "Discharge Limit Enforcement Fault";
    QString CHARGER_SAFETY_RELAY_FAULT = "Charger Safety Relay Fault";
    QString INTERNAL_THERMISTOR_FAULT = "Intern. Thermistor Fault";
    QString INTERNAL_LOGIC_FAULT = "Intern. Logic Fault";
    QString WEAK_PACK_FAULT = "Weak Pack Fault";
    QString INTERNAL_MEMORY_FAULT = "Intern. Memory Fault";
    QString FAN_MONITOR_FAULT = "Fan Monitor Fault";
    QString ALWAYS_ON_SUPPLY_FAULT = "Always-On Supply Fault";
    //Battery limits
    QString DCL_REDUCED_DUE_TO_TEMPERATURE = "DCL Temperature";
    QString DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE = "DCL Low Cell Voltage";
    QString DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE = "DCL Low Pack Voltage";
    QString DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE = "DCL CCL Voltage Failsafe";
    QString DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE = "DCL CCL Communication Failsafe";
    QString CCL_REDUCED_DUE_TO_HIGH_SOC = "CCL High SOC";
    QString CCL_REDUCED_DUE_TO_TEMPERATURE = "CCL Temperature";
    QString CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE = "CCL High Cell Voltage";
    QString CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE = "CCL High Pack Voltage";
    QString CCL_REDUCED_DUE_TO_CHARGER_LATCH = "CCL Charger Latch";
    QString CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT = "CCL Alternate Current";
    QString DCL_REDUCED_DUE_TO_LOW_SOC = "DCL Low SOC";
    QString DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "DCL High Cell Resistance";
    QString CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE = "CCL High Cell Resistance";
}

BatteryFaultList::BatteryFaultList()
    : faultLabels_(
{
    FaultLabel(INTERNAL_COMMUNICATION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_CONVERSION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(WEAK_CELL_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(LOW_CELL_VOLTAGE_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(OPEN_WIRING_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CURRENT_SENSOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(PACK_VOLTAGE_SENSOR, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(VOLTAGE_REDUNDANCY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(THERMISTOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CANBUS_COMMUNICATIONS_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(HIGH_VOLTAGE_ISOLATION_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(POWER_SUPPLY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CHARGE_LIMIT_ENFORCEMENT_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DISCHARGE_LIMIT_ENFORCEMENT_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CHARGER_SAFETY_RELAY_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_THERMISTOR_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(INTERNAL_LOGIC_FAULT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(WEAK_PACK_FAULT, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(INTERNAL_MEMORY_FAULT, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(FAN_MONITOR_FAULT, FaultPriorities::LOW_PRIORITY, false)
    , FaultLabel(ALWAYS_ON_SUPPLY_FAULT, FaultPriorities::LOW_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_TEMPERATURE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_LOW_CELL_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_LOW_PACK_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_VOLTAGE_FAILSAFE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DCL_AND_CCL_REDUCED_DUE_TO_COMMUNICATION_FAILSAFE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_SOC, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_TEMPERATURE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_PACK_VOLTAGE, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_CHARGER_LATCH, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_ALTERNATE_CURRENT_LIMIT, FaultPriorities::HIGH_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_LOW_SOC, FaultPriorities::MEDIUM_PRIORITY, false)
    , FaultLabel(DCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultPriorities::LOW_PRIORITY, false)
    , FaultLabel(CCL_REDUCED_DUE_TO_HIGH_CELL_RESISTANCE, FaultPriorities::LOW_PRIORITY, false)
})
, currentFault_(0)
{
}

BatteryFaultList::~BatteryFaultList()
{
}

FaultLabel BatteryFaultList::nextActiveFault()
{
    for (int i = 0; i < (NUMBER_OF_BATTERY_ERRORS + NUMBER_OF_BATTERY_LIMITS); i++)
    {
        int faultIndex = currentFault_;
        currentFault_++;
        currentFault_ %= (NUMBER_OF_BATTERY_ERRORS + NUMBER_OF_BATTERY_LIMITS);

        if (faultLabels_[faultIndex].isActive())
        {
            return faultLabels_[faultIndex];
        }
    }

    return FaultLabel();
}

QVector<FaultLabel>& BatteryFaultList::faultLabels()
{
    return faultLabels_;
}

QVector<QString>& BatteryFaultList::activeFaultLabels()
{
    activeLabels_.clear();

    for (int i = 0; i < (NUMBER_OF_BATTERY_ERRORS + NUMBER_OF_BATTERY_LIMITS); i++)
    {
        if (faultLabels_[i].isActive())
        {
            activeLabels_.append(faultLabels_[i].name());
        }
    }

    return activeLabels_;
}

void BatteryFaultList::updateErrors(const BatteryErrorFlags& errorFlags)
{
    faultLabels_[0].setActive(errorFlags.internalCommununicationFault());
    faultLabels_[1].setActive(errorFlags.internalConversionFault());
    faultLabels_[2].setActive(errorFlags.weakCellFault());
    faultLabels_[3].setActive(errorFlags.lowCellVoltageFault());
    faultLabels_[4].setActive(errorFlags.openWiringFault());
    faultLabels_[5].setActive(errorFlags.currentSensorFault());
    faultLabels_[6].setActive(errorFlags.packVoltageSensorFault());
    faultLabels_[7].setActive(errorFlags.voltageRedundancyFault());
    faultLabels_[8].setActive(errorFlags.thermistorFault());
    faultLabels_[9].setActive(errorFlags.canbusCommunicationsFault());
    faultLabels_[10].setActive(errorFlags.highVoltageIsolationFault());
    faultLabels_[11].setActive(errorFlags.powerSupplyFault12V());
    faultLabels_[12].setActive(errorFlags.chargeLimitEnforcementFault());
    faultLabels_[13].setActive(errorFlags.dischargeLimitEnforcementFault());
    faultLabels_[14].setActive(errorFlags.chargerSafetyRelayFault());
    faultLabels_[15].setActive(errorFlags.internalThermistorFault());
    faultLabels_[16].setActive(errorFlags.internalLogicFault());
    faultLabels_[17].setActive(errorFlags.weakPackFault());
    faultLabels_[18].setActive(errorFlags.internalMemoryFault());
    faultLabels_[19].setActive(errorFlags.fanMonitorFault());
    faultLabels_[20].setActive(errorFlags.alwaysOnSupplyFault());
}

void BatteryFaultList::updateLimits(const BatteryLimitFlags& limitFlags)
{
    faultLabels_[0 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclReducedDueToTemperature());
    faultLabels_[1 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclReducedDueToLowCellVoltage());
    faultLabels_[2 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclReducedDueToLowPackVoltage());
    faultLabels_[3 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclandCclReducedDueToVoltageFailsafe());
    faultLabels_[4 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclandCclReducedDueToCommunicationFailsafe());
    faultLabels_[5 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToHighSoc());
    faultLabels_[6 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToTemperature());
    faultLabels_[7 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToHighCellVoltage());
    faultLabels_[8 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToHighPackVoltage());
    faultLabels_[9 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToChargerLatch());
    faultLabels_[10 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToAlternateCurrentLimit());
    faultLabels_[11 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclReducedDueToLowSoc());
    faultLabels_[12 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.dclReducedDueToHighCellResistance());
    faultLabels_[13 + NUMBER_OF_BATTERY_ERRORS].setActive(limitFlags.cclReducedDueToHighCellResistance());
}

int BatteryFaultList::numberOfActiveLabels() const
{
    int numberOfLabels = 0;

    for (int i = 0; i < faultLabels_.size(); i++)
    {
        if (faultLabels_[i].isActive())
        {
            numberOfLabels++;
        }
    }

    return numberOfLabels;
}
