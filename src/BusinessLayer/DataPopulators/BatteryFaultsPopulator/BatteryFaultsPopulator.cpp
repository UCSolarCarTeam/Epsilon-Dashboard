/**
 *  Schulich Delta Android Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of Schulich Delta Android Telemetry
 *
 *  Schulich Delta Android Telemetry is free software:
 *  you can redistribute it and/or modify it under the terms
 *  of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  Schulich Delta Android Telemetry is distributed
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General
 *  Public License along with Schulich Delta Android Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include <QJsonObject>
#include <QJsonArray>

#include "BatteryFaultsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines/JsonDefines.h"

BatteryFaultsPopulator::BatteryFaultsPopulator(I_BatteryFaultsData& batteryFaultsData)
    : batteryFaultsData_(batteryFaultsData)
{
}

void BatteryFaultsPopulator::populateData(const QJsonObject& data)
{
    BatteryErrorFlags errorFlags;
    BatteryLimitFlags limitFlags;
    QJsonValue value = data.value(JsonFormat::BATTERYFAULTS);

    QJsonObject errorFlagsSubValue = value.toObject().value(JsonFormat::BATTERYFAULTS_ERRORFLAGS).toObject();
    errorFlags.setInternalCommununicationFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_INTERNALCOMMUNICATIONFAULT).toBool());
    errorFlags.setInternalConversionFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_INTERNALCONVERSIONFAULT).toBool());
    errorFlags.setWeakCellFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_WEAKCELLFAULT).toBool());
    errorFlags.setLowCellVoltageFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_LOWCELLVOLTAGEFAULT).toBool());
    errorFlags.setOpenWiringFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_OPENWIRINGFAULT).toBool());
    errorFlags.setCurrentSensorFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_CURRENTSENSORFAULT).toBool());
    errorFlags.setPackVoltageSensorFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_PACKVOLTAGESENSORFAULT).toBool());
    errorFlags.setWeakPackFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_WEAKPACKFAULT).toBool());
    errorFlags.setVoltageRedundancyFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_VOLTAGEREDUNDANCYFAULT).toBool());
    errorFlags.setFanMonitorFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_FANMONITORFAULT).toBool());
    errorFlags.setThermistorFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_THERMISTORFAULT).toBool());
    errorFlags.setCanbusCommunicationsFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_CANBUSCOMMUNICATIONSFAULT).toBool());
    errorFlags.setAlwaysOnSupplyFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_ALWAYSONSUPPLYFAULT).toBool());
    errorFlags.setHighVoltageIsolationFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_HIGHVOLTAGEISOLATIONFAULT).toBool());
    errorFlags.setPowerSupplyFault12V(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_POWERSUPPLYFAULT12V).toBool());
    errorFlags.setChargeLimitEnforcementFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_CHARELIMITENFORCEMENTFAULT).toBool());
    errorFlags.setDischargeLimitEnforcementFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_DISCHARGELIMITENFORCEMENTFAULT).toBool());
    errorFlags.setChargerSafetyRelayFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_CHARGERSAFETYRELAYFAULT).toBool());
    errorFlags.setInternalMemoryFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_INTERNALMEMORYFAULT).toBool());
    errorFlags.setInternalThermistorFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_INTERNALTHERMISTORFAULT).toBool());
    errorFlags.setInternalLogicFault(errorFlagsSubValue.value(JsonFormat::BATTERYFAULTS_ERRORFLAGS_INTERNALLOGICFAULT).toBool());
    batteryFaultsData_.setErrorFlags(errorFlags);

    QJsonObject limitFlagsSubValue = value.toObject().value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS).toObject();
    limitFlags.setDclReducedDueToLowSoc(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLREDUCEDDUETOLOWSOC).toBool());
    limitFlags.setDclReducedDueToHighCellResistance(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLREDUCEDDUETOHIGHCELLRESISTANCE).toBool());
    limitFlags.setDclReducedDueToTemperature(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLREDUCEDDUETOTEMPERATURE).toBool());
    limitFlags.setDclReducedDueToLowCellVoltage(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLREDUCEDDUETOLOWCELLVOLTAGE).toBool());
    limitFlags.setDclReducedDueToLowPackVoltage(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLREDUCEDDUETOLOWPACKVOLTAGE).toBool());
    limitFlags.setDclandCclReducedDueToVoltageFailsafe(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLANDCCLREDUCEDDUETOVOLTAGEFAILSAFE).toBool());
    limitFlags.setDclandCclReducedDueToCommunicationFailsafe(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_DCLANDCCLREDUCEDDUETOCOMMUNICATIONFAILSAFE).toBool());
    limitFlags.setCclReducedDueToHighSoc(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOHIGHSOC).toBool());
    limitFlags.setCclReducedDueToHighCellResistance(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOHIGHCELLRESISTANCE).toBool());
    limitFlags.setCclReducedDueToTemperature(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOTEMPERATURE).toBool());
    limitFlags.setCclReducedDueToHighCellVoltage(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOHIGHCELLVOLTAGE).toBool());
    limitFlags.setCclReducedDueToHighPackVoltage(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOHIGHPACKVOLTAGE).toBool());
    limitFlags.setCclReducedDueToChargerLatch(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOCHARGERLATCH).toBool());
    limitFlags.setCclReducedDueToAlternateCurrentLimit(limitFlagsSubValue.value(JsonFormat::BATTERYFAULTS_LIMITSFLAGS_CCLREDUCEDDUETOALTERNATECURRENTLIMIT).toBool());
    batteryFaultsData_.setLimitFlags(limitFlags);
}
