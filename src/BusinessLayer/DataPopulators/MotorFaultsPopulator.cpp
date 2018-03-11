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

#include "MotorFaultsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

MotorFaultsPopulator::MotorFaultsPopulator(I_MotorFaultsData& motorFaultsData)
    : motorFaultsData_(motorFaultsData)
{
}

void MotorFaultsPopulator::populateData(const QJsonObject& data)
{
    ErrorFlags motorZeroErrorFlags;
    LimitFlags motorZeroLimitFlags;
    ErrorFlags motorOneErrorFlags;
    LimitFlags motorOneLimitFlags;
    QJsonValue value = data.value(JsonFormat::MOTORFAULTS);
    QJsonArray array = value.toArray();
    QJsonValue motorZeroJson = array.at(0);
    QJsonValue motorOneJson = array.at(1);
    QJsonValue motorZeroErrorFlagsJson = motorZeroJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS);
    motorZeroErrorFlags.setMotorOverSpeed(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_MOTOROVERSPEED).toBool());
    motorZeroErrorFlags.setSoftwareOverCurrent(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_SOFTWAREOVERCURRENT).toBool());
    motorZeroErrorFlags.setDcBusOverVoltage(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_DCBUSOVERVOLTAGE).toBool());
    motorZeroErrorFlags.setBadMotorPositionHallSequence(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_BADMOTORPOSITIONHALLSEQUENCE).toBool());
    motorZeroErrorFlags.setWatchdogCausedLastReset(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_WATCHDOGCAUSEDLASTRESET).toBool());
    motorZeroErrorFlags.setConfigReadError(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_CONFIGREADERROR).toBool());
    motorZeroErrorFlags.setRailUnderVoltageLockOut(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_RAIL15VUNDERVOLTAGELOCKOUT).toBool());
    motorZeroErrorFlags.setDesaturationFault(motorZeroErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_DESATURATIONFAULT).toBool());
    QJsonValue motorZeroLimitFlagsJson = motorZeroJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS);
    motorZeroLimitFlags.setOutputVoltagePwmLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_OUTPUTVOLTAGEPWM).toBool());
    motorZeroLimitFlags.setMotorCurrentLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_MOTORCURRENT).toBool());
    motorZeroLimitFlags.setVelocityLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_VELOCITY).toBool());
    motorZeroLimitFlags.setBusCurrentLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSCURRENT).toBool());
    motorZeroLimitFlags.setBusVoltageUpperLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSVOLTAGEUPPER).toBool());
    motorZeroLimitFlags.setBusVoltageLowerLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSVOLTAGELOWER).toBool());
    motorZeroLimitFlags.setIpmOrMotorTemperatureLimit(motorZeroLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_IPMORMOTORTEMPERATURE).toBool());
    QJsonValue motorOneErrorFlagsJson = motorOneJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS);
    motorOneErrorFlags.setMotorOverSpeed(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_MOTOROVERSPEED).toBool());
    motorOneErrorFlags.setSoftwareOverCurrent(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_SOFTWAREOVERCURRENT).toBool());
    motorOneErrorFlags.setDcBusOverVoltage(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_DCBUSOVERVOLTAGE).toBool());
    motorOneErrorFlags.setBadMotorPositionHallSequence(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_BADMOTORPOSITIONHALLSEQUENCE).toBool());
    motorOneErrorFlags.setWatchdogCausedLastReset(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_WATCHDOGCAUSEDLASTRESET).toBool());
    motorOneErrorFlags.setConfigReadError(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_CONFIGREADERROR).toBool());
    motorOneErrorFlags.setRailUnderVoltageLockOut(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_RAIL15VUNDERVOLTAGELOCKOUT).toBool());
    motorOneErrorFlags.setDesaturationFault(motorOneErrorFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_ERRORFLAGS_DESATURATIONFAULT).toBool());
    QJsonValue motorOneLimitFlagsJson = motorOneJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS);
    motorOneLimitFlags.setOutputVoltagePwmLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_OUTPUTVOLTAGEPWM).toBool());
    motorOneLimitFlags.setMotorCurrentLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_MOTORCURRENT).toBool());
    motorOneLimitFlags.setVelocityLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_VELOCITY).toBool());
    motorOneLimitFlags.setBusCurrentLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSCURRENT).toBool());
    motorOneLimitFlags.setBusVoltageUpperLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSVOLTAGEUPPER).toBool());
    motorOneLimitFlags.setBusVoltageLowerLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_BUSVOLTAGELOWER).toBool());
    motorOneLimitFlags.setIpmOrMotorTemperatureLimit(motorOneLimitFlagsJson.toObject().value(JsonFormat::MOTORFAULTS_LIMITFLAGS_IPMORMOTORTEMPERATURE).toBool());
    motorFaultsData_.setMotorZeroErrorFlags(motorZeroErrorFlags);
    motorFaultsData_.setMotorZeroLimitFlags(motorZeroLimitFlags);
    motorFaultsData_.setMotorOneErrorFlags(motorOneErrorFlags);
    motorFaultsData_.setMotorOneLimitFlags(motorOneLimitFlags);
}
