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

#include "CommunicationLayer/JsonReceiver/I_JsonReceiver.h"
#include "BusinessLayer/DataPopulators/JsonDefines.h"
#include "DataLayer/BatteryData/I_BatteryData.h"

BatteryPopulator::BatteryPopulator(I_JsonReceiver& jsonReceiver,
                                   I_BatteryData& batteryData)
    : jsonReceiver_(jsonReceiver)
    , batteryData_(batteryData)
{
    connect(&jsonReceiver_, SIGNAL(dataReceived(const QJsonObject&)),
            this, SLOT(populateData(const QJsonObject&)));
}

void BatteryPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::BATTERY);
    batteryData_.setAlive(value.toObject().value(JsonFormat::BATTERY_ALIVE).toBool());
    batteryData_.setPackSocAmpHours(value.toObject().value(JsonFormat::BATTERY_PACKSOCAMPHOURS).toDouble());
    batteryData_.setPackSocPercentage(value.toObject().value(JsonFormat::BATTERY_PACKSOCPERCENTAGE).toDouble());
    batteryData_.setPackBalanceSocAmpHours(value.toObject().value(JsonFormat::BATTERY_PACKBALANCESOCAMPHOURS).toDouble());
    batteryData_.setPackBalanceSocPercentage(value.toObject().value(JsonFormat::BATTERY_PACKBALANCESOCPERCENTAGE).toDouble());
    batteryData_.setChargingCellVoltageError(value.toObject().value(JsonFormat::BATTERY_CHARGINGCELLVOLTAGEERROR).toDouble());
    batteryData_.setCellTempMargin(value.toObject().value(JsonFormat::BATTERY_CELLTEMPMARGIN).toDouble());
    batteryData_.setDischargingCellVoltageError(value.toObject().value(JsonFormat::BATTERY_DISCHARGINGCELLVOLTAGEERROR).toDouble());
    batteryData_.setTotalPackCapacity(value.toObject().value(JsonFormat::BATTERY_TOTALPACKCAPACITY).toDouble());
    batteryData_.setPrechargeContactor0DriverStatus(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR0DRIVERSTATUS).toBool());
    batteryData_.setPrechargeContactor1DriverStatus(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR1DRIVERSTATUS).toBool());
    batteryData_.setPrechargeContactor2DriverStatus(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR2DRIVERSTATUS).toBool());
    batteryData_.setPrechargeContactor0DriverError(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR0DRIVERERROR).toBool());
    batteryData_.setPrechargeContactor1DriverError(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR1DRIVERERROR).toBool());
    batteryData_.setPrechargeContactor2DriverError(value.toObject().value(JsonFormat::BATTERY_PRECHARGECONTACTOR2DRIVERERROR).toBool());
    batteryData_.setContactorSupplyOk(value.toObject().value(JsonFormat::BATTERY_CONTACTORSUPPLYOK).toBool());
    batteryData_.setPrechargeState(value.toObject().value(JsonFormat::BATTERY_PRECHARGESTATE).toString());
    batteryData_.setPrechargeTimerElapsed(value.toObject().value(JsonFormat::BATTERY_PRECHARGETIMERELAPSED).toBool());
    batteryData_.setPrechargeTimerCount(value.toObject().value(JsonFormat::BATTERY_PRECHARGETIMERCOUNT).toDouble());
    batteryData_.setVoltage(value.toObject().value(JsonFormat::BATTERY_VOLTAGE).toDouble());
    batteryData_.setCurrent(value.toObject().value(JsonFormat::BATTERY_CURRENT).toDouble());
    batteryData_.setFan0Speed(value.toObject().value(JsonFormat::BATTERY_FAN0SPEED).toDouble());
    batteryData_.setFan1Speed(value.toObject().value(JsonFormat::BATTERY_FAN1SPEED).toDouble());
    batteryData_.setFanContactorsCurrent(value.toObject().value(JsonFormat::BATTERY_FANCONTACTORSCURRENT).toDouble());
    batteryData_.setCmuCurrent(value.toObject().value(JsonFormat::BATTERY_CMUCURRENT).toDouble());
    QJsonValue subValue = value.toObject().value(JsonFormat::BATTERY_LOWESTCELLVOLTAGE);
    batteryData_.setLowestCellVoltage_Voltage(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLVOLTAGE_VOLTAGE).toDouble());
    batteryData_.setLowestCellVoltage_CmuNumber(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLVOLTAGE_CMUNUMBER).toInt());
    batteryData_.setLowestCellVoltage_CellNumber(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLVOLTAGE_CELLNUMBER).toInt());
    subValue = value.toObject().value(JsonFormat::BATTERY_LOWESTCELLTEMP);
    batteryData_.setLowestCellTemp_Temperature(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLTEMP_TEMPERATURE).toDouble());
    batteryData_.setLowestCellTemp_CmuNumber(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLTEMP_CMUNUMBER).toInt());
    batteryData_.setLowestCellTemp_CellNumber(subValue.toObject().value(JsonFormat::BATTERY_LOWESTCELLTEMP_CELLNUMBER).toInt());
    subValue = value.toObject().value(JsonFormat::BATTERY_HIGHESTCELLVOLTAGE);
    batteryData_.setHighestCellVoltage_Voltage(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLVOLTAGE_VOLTAGE).toDouble());
    batteryData_.setHighestCellVoltage_CmuNumber(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLVOLTAGE_CMUNUMBER).toInt());
    batteryData_.setHighestCellVoltage_CellNumber(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLVOLTAGE_CELLNUMBER).toInt());
    subValue = value.toObject().value(JsonFormat::BATTERY_HIGHESTCELLTEMP);
    batteryData_.setHighestCellTemp_Temperature(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLTEMP_TEMPERATURE).toDouble());
    batteryData_.setHighestCellTemp_CmuNumber(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLTEMP_CMUNUMBER).toInt());
    batteryData_.setHighestCellTemp_CellNumber(subValue.toObject().value(JsonFormat::BATTERY_HIGHESTCELLTEMP_CELLNUMBER).toInt());
}
