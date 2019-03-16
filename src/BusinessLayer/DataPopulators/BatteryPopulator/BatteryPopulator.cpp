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

#include "BatteryPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines/JsonDefines.h"
#include "../DataLayer/BatteryData/I_BatteryData.h"

BatteryPopulator::BatteryPopulator(I_BatteryData& batteryData)
    : batteryData_(batteryData)
{
}

void BatteryPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::BATTERY);
    batteryData_.setAlive(value.toObject().value(JsonFormat::BATTERY_ALIVE).toBool());

    QJsonValue bmsRelayStatusSubValue = value.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS);
    BmsRelayStatusFlags bmsRelayStatusFlagValues;
    bmsRelayStatusFlagValues.setDischargeRelayEnabled(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_DISCHARGERELAYENABLED).toBool());
    bmsRelayStatusFlagValues.setChargeRelayEnabled(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_CHARGERELAYENABLED).toBool());
    bmsRelayStatusFlagValues.setChargerSafetyEnabled(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_CHARGERSAFETYENABLED).toBool());
    bmsRelayStatusFlagValues.setMalfunctionIndicatorActive(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_MALFUNCTIONINDICATORACTIVE).toBool());
    bmsRelayStatusFlagValues.setMultiPurposeInputSignalStatus(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_MULTIPURPOSEINPUTSIGNALSTATUS).toBool());
    bmsRelayStatusFlagValues.setAlwaysOnSignalStatus(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_ALWAYSONSIGNALSTATUS).toBool());
    bmsRelayStatusFlagValues.setIsReadySignalStatus(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_ISREADYSIGNALSTATUS).toBool());
    bmsRelayStatusFlagValues.setIsChargingSignalStatus(bmsRelayStatusSubValue.toObject().value(JsonFormat::BATTERY_BMSRELAYSTATUSFLAGS_ISCHARGINGSIGNALSTATUS).toBool());
    batteryData_.setBmsRelayStatus(bmsRelayStatusFlagValues);

    batteryData_.setPopulatedCells(value.toObject().value(JsonFormat::BATTERY_POPULATEDCELLS).toInt());
    batteryData_.setInputVoltage12V(value.toObject().value(JsonFormat::BATTERY_12VINPUTVOLTAGE).toDouble());
    batteryData_.setFanVoltage(value.toObject().value(JsonFormat::BATTERY_FANVOLTAGE).toDouble());
    batteryData_.setPackCurrent(value.toObject().value(JsonFormat::BATTERY_PACKCURRENT).toDouble());
    batteryData_.setPackVoltage(value.toObject().value(JsonFormat::BATTERY_PACKVOLTAGE).toDouble());
    batteryData_.setPackStateOfCharge(value.toObject().value(JsonFormat::BATTERY_PACKSTATEOFCHARGE).toDouble());
    batteryData_.setPackAmphours(value.toObject().value(JsonFormat::BATTERY_PACKAMPHOURS).toDouble());
    batteryData_.setPackDepthOfDischarge(value.toObject().value(JsonFormat::BATTERY_PACKDEPTHOFDISCHARGE).toDouble());
    batteryData_.setHighTemperature(value.toObject().value(JsonFormat::BATTERY_HIGHTEMPERATURE).toInt());
    batteryData_.setHighThermistorId(value.toObject().value(JsonFormat::BATTERY_HIGHTHERMISTORID).toInt());
    batteryData_.setLowTemperature(value.toObject().value(JsonFormat::BATTERY_LOWTEMPERATURE).toInt());
    batteryData_.setLowThermistorId(value.toObject().value(JsonFormat::BATTERY_LOWTHERMISTORID).toInt());
    batteryData_.setAverageTemperature(value.toObject().value(JsonFormat::BATTERY_AVERAGETEMPERATURE).toInt());
    batteryData_.setInternalTemperature(value.toObject().value(JsonFormat::BATTERY_INTERNALTEMPERATURE).toInt());
    batteryData_.setFanSpeed(value.toObject().value(JsonFormat::BATTERY_FANSPEED).toInt());
    batteryData_.setRequestedFanSpeed(value.toObject().value(JsonFormat::BATTERY_REQUESTEDFANSPEED).toInt());
    batteryData_.setLowCellVoltage(value.toObject().value(JsonFormat::BATTERY_LOWCELLVOLTAGE).toInt());
    batteryData_.setLowCellVoltageId(value.toObject().value(JsonFormat::BATTERY_LOWCELLVOLTAGEID).toInt());
    batteryData_.setHighCellVoltage(value.toObject().value(JsonFormat::BATTERY_HIGHCELLVOLTAGE).toInt());
    batteryData_.setHighCellVoltageId(value.toObject().value(JsonFormat::BATTERY_HIGHCELLVOLTAGEID).toInt());
    batteryData_.setAverageCellVoltage(value.toObject().value(JsonFormat::BATTERY_AVERAGECELLVOLTAGE).toInt());
}
