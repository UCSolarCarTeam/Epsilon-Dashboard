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

#include "KeyMotorPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

KeyMotorPopulator::KeyMotorPopulator(I_KeyMotorData& keyMotorData)
    : keyMotorData_(keyMotorData)
{
}

void KeyMotorPopulator::populateData(const QJsonObject& data)
{
    KeyMotor motorZero;
    KeyMotor motorOne;
    QList<bool> aliveList;
    QList<double> setCurrentList;
    QList<double> setVelocityList;
    QList<double> busCurrentList;
    QList<double> busVoltageList;
    QList<double> vehicleVelocityList;
    QJsonValue value = data.value(JsonFormat::KEYMOTOR);
    QJsonArray array = value.toArray();

    foreach (const QJsonValue& v, array)
    {
        aliveList.append(v.toObject().value(JsonFormat::KEYMOTOR_ALIVE).toBool());
        setCurrentList.append(v.toObject().value(JsonFormat::KEYMOTOR_SETCURRENT).toDouble());
        setVelocityList.append(v.toObject().value(JsonFormat::KEYMOTOR_SETVELOCITY).toDouble());
        busCurrentList.append(v.toObject().value(JsonFormat::KEYMOTOR_BUSCURRENT).toDouble());
        busVoltageList.append(v.toObject().value(JsonFormat::KEYMOTOR_BUSVOLTAGE).toDouble());
        vehicleVelocityList.append(v.toObject().value(JsonFormat::KEYMOTOR_VEHICLEVELOCITY).toDouble());
    }

    motorZero.setAlive(aliveList.value(0));
    motorZero.setSetCurrent(setCurrentList.value(0));
    motorZero.setSetVelocity(setVelocityList.value(0));
    motorZero.setBusCurrent(busCurrentList.value(0));
    motorZero.setBusVoltage(busVoltageList.value(0));
    motorZero.setVehicleVelocity(vehicleVelocityList.value(0));
    motorOne.setAlive(aliveList.value(1));
    motorOne.setSetCurrent(setCurrentList.value(1));
    motorOne.setSetVelocity(setVelocityList.value(1));
    motorOne.setBusCurrent(busCurrentList.value(1));
    motorOne.setBusVoltage(busVoltageList.value(1));
    motorOne.setVehicleVelocity(vehicleVelocityList.value(1));
    keyMotorData_.setMotorZero(motorZero);
    keyMotorData_.setMotorOne(motorOne);
}
