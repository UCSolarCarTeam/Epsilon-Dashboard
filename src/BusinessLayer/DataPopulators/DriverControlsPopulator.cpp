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

#include "DriverControlsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines.h"

DriverControlsPopulator::DriverControlsPopulator(I_DriverControlsData& driverControlsData)
    : driverControlsData_(driverControlsData)
{
}

void DriverControlsPopulator::populateData(const QJsonObject& data)
{
    QJsonValue value = data.value(JsonFormat::DRIVERCONTROLS);
    driverControlsData_.setAlive(value.toObject().value(JsonFormat::DRIVERCONTROLS_ALIVE).toBool());
    driverControlsData_.setHeadlightsOff(value.toObject().value(JsonFormat::DRIVERCONTROLS_HEADLIGHTSOFF).toBool());
    driverControlsData_.setHeadlightsLow(value.toObject().value(JsonFormat::DRIVERCONTROLS_HEADLIGHTSLOW).toBool());
    driverControlsData_.setHeadlightsHigh(value.toObject().value(JsonFormat::DRIVERCONTROLS_HEADLIGHTSHIGH).toBool());
    driverControlsData_.setSignalRight(value.toObject().value(JsonFormat::DRIVERCONTROLS_SIGNALRIGHT).toBool());
    driverControlsData_.setSignalLeft(value.toObject().value(JsonFormat::DRIVERCONTROLS_SIGNALLEFT).toBool());
    driverControlsData_.setHazard(value.toObject().value(JsonFormat::DRIVERCONTROLS_HAZARD).toBool());
    driverControlsData_.setInterior(value.toObject().value(JsonFormat::DRIVERCONTROLS_INTERIOR).toBool());
    driverControlsData_.setVolumeUp(value.toObject().value(JsonFormat::DRIVERCONTROLS_VOLUMEUP).toBool());
    driverControlsData_.setVolumeDown(value.toObject().value(JsonFormat::DRIVERCONTROLS_VOLUMEDOWN).toBool());
    driverControlsData_.setNextSong(value.toObject().value(JsonFormat::DRIVERCONTROLS_NEXTSONG).toBool());
    driverControlsData_.setPrevSong(value.toObject().value(JsonFormat::DRIVERCONTROLS_PREVSONG).toBool());
    driverControlsData_.setAcceleration(value.toObject().value(JsonFormat::DRIVERCONTROLS_ACCELERATION).toDouble());
    driverControlsData_.setRegenBraking(value.toObject().value(JsonFormat::DRIVERCONTROLS_REGENBRAKING).toDouble());
    driverControlsData_.setBrakes(value.toObject().value(JsonFormat::DRIVERCONTROLS_BRAKES).toBool());
    driverControlsData_.setForward(value.toObject().value(JsonFormat::DRIVERCONTROLS_FORWARD).toBool());
    driverControlsData_.setReverse(value.toObject().value(JsonFormat::DRIVERCONTROLS_REVERSE).toBool());
    driverControlsData_.setPushToTalk(value.toObject().value(JsonFormat::DRIVERCONTROLS_PUSHTOTALK).toBool());
    driverControlsData_.setHorn(value.toObject().value(JsonFormat::DRIVERCONTROLS_HORN).toBool());
    driverControlsData_.setReset(value.toObject().value(JsonFormat::DRIVERCONTROLS_RESET).toBool());
    driverControlsData_.setAux(value.toObject().value(JsonFormat::DRIVERCONTROLS_AUX).toBool());
}
