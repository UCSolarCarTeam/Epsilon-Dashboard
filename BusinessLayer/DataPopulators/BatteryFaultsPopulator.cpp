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

#include "CommunicationLayer/JsonReceiver/I_JsonReceiver.h"
#include "BusinessLayer/DataPopulators/JsonDefines.h"

BatteryFaultsPopulator::BatteryFaultsPopulator(I_JsonReceiver& jsonReceiver,
        I_BatteryFaultsData& batteryFaultsData)
    : jsonReceiver_(jsonReceiver)
    , batteryFaultsData_(batteryFaultsData)
{
    connect(&jsonReceiver_, SIGNAL(dataReceived(const QJsonObject&)),
            this, SLOT(populateData(const QJsonObject&)));
}

void BatteryFaultsPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::BATTERYFAULTS);
    BatteryFaults batteryFaults;
    batteryFaults.setCellOverVoltage(value.toObject().value(JsonFormat::BATTERYFAULTS_CELLOVERVOLTAGE).toBool());
    batteryFaults.setCellUnderVoltage(value.toObject().value(JsonFormat::BATTERYFAULTS_CELLUNDERVOLTAGE).toBool());
    batteryFaults.setCellOverTemperature(value.toObject().value(JsonFormat::BATTERYFAULTS_CELLOVERTEMP).toBool());
    batteryFaults.setMeasurementUntrusted(value.toObject().value(JsonFormat::BATTERYFAULTS_MEASUREMENTUNTRUSTED).toBool());
    batteryFaults.setCmuCommTimeout(value.toObject().value(JsonFormat::BATTERYFAULTS_CmuCOMMTIMEOUT).toBool());
    batteryFaults.setBmuIsInSetupMode(value.toObject().value(JsonFormat::BATTERYFAULTS_BMUSETUPMODE).toBool());
    batteryFaults.setCmuCanBusPowerStatus(value.toObject().value(JsonFormat::BATTERYFAULTS_CmuCANBUSPOWERSTATUS).toBool());
    batteryFaults.setPackIsolationTestFailure(value.toObject().value(JsonFormat::BATTERYFAULTS_PACKISOLATIONFAILURE).toBool());
    batteryFaults.setSoftwareOverCurrentMeasured(value.toObject().value(JsonFormat::BATTERYFAULTS_SOFTWAREOVERCURRENT).toBool());
    batteryFaults.setCanSupplyIsLow(value.toObject().value(JsonFormat::BATTERYFAULTS_CAN12VSUPPLYLOW).toBool());
    batteryFaults.setContactorIsStuck(value.toObject().value(JsonFormat::BATTERYFAULTS_CONTACTORSTUCK).toBool());
    batteryFaults.setCmuDetectedExtraCellPresent(value.toObject().value(JsonFormat::BATTERYFAULTS_CmuDETECTEDEXTRACELL).toBool());
    batteryFaultsData_.setBatteryFaults(batteryFaults);
}
