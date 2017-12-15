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

#include "MpptPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

MpptPopulator::MpptPopulator(I_MpptData& mpptData)
    : mpptData_(mpptData)
{
}

void MpptPopulator::populateData(const QJsonObject& data)
{
    Mppt mpptZero;
    Mppt mpptOne;
    Mppt mpptTwo;
    QList<bool> aliveList;
    QList<double> arrayVoltageList;
    QList<double> arrayCurrentList;
    QList<double> batteryVoltageList;
    QList<double> temperatureList;
    QJsonValue value = data.value(JsonFormat::MPPT);
    QJsonArray array = value.toArray();

    foreach (const QJsonValue& v, array)
    {
        aliveList.append(v.toObject().value(JsonFormat::MPPT_ALIVE).toBool());
        arrayVoltageList.append(v.toObject().value(JsonFormat::MPPT_ARRAYVOLTAGE).toDouble());
        arrayCurrentList.append(v.toObject().value(JsonFormat::MPPT_ARRAYCURRENT).toDouble());
        batteryVoltageList.append(v.toObject().value(JsonFormat::MPPT_BATTERYVOLTAGE).toDouble());
        temperatureList.append(v.toObject().value(JsonFormat::MPPT_TEMPERATURE).toDouble());
    }

    mpptZero.setAlive(aliveList.value(0));
    mpptZero.setArrayVoltage(arrayVoltageList.value(0));
    mpptZero.setArrayCurrent(arrayCurrentList.value(0));
    mpptZero.setBatteryVoltage(batteryVoltageList.value(0));
    mpptZero.setTemperature(temperatureList.value(0));
    mpptOne.setAlive(aliveList.value(1));
    mpptOne.setArrayVoltage(arrayVoltageList.value(1));
    mpptOne.setArrayCurrent(arrayCurrentList.value(1));
    mpptOne.setBatteryVoltage(batteryVoltageList.value(1));
    mpptOne.setTemperature(temperatureList.value(1));
    mpptTwo.setAlive(aliveList.value(2));
    mpptTwo.setArrayVoltage(arrayVoltageList.value(2));
    mpptTwo.setArrayCurrent(arrayCurrentList.value(2));
    mpptTwo.setBatteryVoltage(batteryVoltageList.value(2));
    mpptTwo.setTemperature(temperatureList.value(2));
    mpptData_.setMppt(0, mpptZero);
    mpptData_.setMppt(1, mpptOne);
    mpptData_.setMppt(2, mpptTwo);
}
