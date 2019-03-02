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

#include "MotorDetailsPopulator.h"

#include "../BusinessLayer/DataPopulators/JsonDefines/JsonDefines.h"

MotorDetailsPopulator::MotorDetailsPopulator(I_MotorDetailsData& motorDetailsData)
    : motorDetailsData_(motorDetailsData)
{
}

void MotorDetailsPopulator::populateData(const QJsonObject& data)
{
    MotorDetails motorDetailsZero;
    MotorDetails motorDetailsOne;
    QJsonValue value = data.value(JsonFormat::MOTORDETAILS);
    QJsonArray array = value.toArray();
    QJsonValue motorZeroJson = array.at(0);
    QJsonValue motorOneJson = array.at(1);
    motorDetailsZero.setPhaseCCurrent(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_PHASECCURRENT).toDouble());
    motorDetailsZero.setPhaseBCurrent(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_PHASEBCURRENT).toDouble());
    motorDetailsZero.setMotorVoltageReal(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORVOLTAGEREAL).toDouble());
    motorDetailsZero.setMotorVoltageImaginary(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORVOLTAGEIMAGINARY).toDouble());
    motorDetailsZero.setMotorCurrentReal(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORCURRENTREAL).toDouble());
    motorDetailsZero.setMotorCurrentImaginary(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORCURRENTIMAGINARY).toDouble());
    motorDetailsZero.setBackEmf(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_BACKEMF).toDouble());
    motorDetailsZero.setVoltageRail15VSupply(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL15VSUPPLY).toDouble());
    motorDetailsZero.setVoltageRail3VSupply(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL3VSUPPLY).toDouble());
    motorDetailsZero.setVoltageRail1VSupply(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL1VSUPPLY).toDouble());
    motorDetailsZero.setHeatSinkTemp(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_HEATSINKTEMP).toDouble());
    motorDetailsZero.setMotorTemp(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORTEMP).toDouble());
    motorDetailsZero.setDspBoardTemp(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_DSPBOARDTEMP).toDouble());
    motorDetailsZero.setDcBusAmpHours(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_DCBUSAMPHOURS).toDouble());
    motorDetailsZero.setOdometer(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_ODOMETER).toDouble());
    motorDetailsZero.setSlipSpeed(motorZeroJson.toObject().value(JsonFormat::MOTORDETAILS_SLIPSPEED).toDouble());
    motorDetailsOne.setPhaseCCurrent(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_PHASECCURRENT).toDouble());
    motorDetailsOne.setPhaseBCurrent(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_PHASEBCURRENT).toDouble());
    motorDetailsOne.setMotorVoltageReal(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORVOLTAGEREAL).toDouble());
    motorDetailsOne.setMotorVoltageImaginary(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORVOLTAGEIMAGINARY).toDouble());
    motorDetailsOne.setMotorCurrentReal(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORCURRENTREAL).toDouble());
    motorDetailsOne.setMotorCurrentImaginary(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORCURRENTIMAGINARY).toDouble());
    motorDetailsOne.setBackEmf(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_BACKEMF).toDouble());
    motorDetailsOne.setVoltageRail15VSupply(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL15VSUPPLY).toDouble());
    motorDetailsOne.setVoltageRail3VSupply(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL3VSUPPLY).toDouble());
    motorDetailsOne.setVoltageRail1VSupply(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_VOLTAGERAIL1VSUPPLY).toDouble());
    motorDetailsOne.setHeatSinkTemp(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_HEATSINKTEMP).toDouble());
    motorDetailsOne.setMotorTemp(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_MOTORTEMP).toDouble());
    motorDetailsOne.setDspBoardTemp(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_DSPBOARDTEMP).toDouble());
    motorDetailsOne.setDcBusAmpHours(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_DCBUSAMPHOURS).toDouble());
    motorDetailsOne.setOdometer(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_ODOMETER).toDouble());
    motorDetailsOne.setSlipSpeed(motorOneJson.toObject().value(JsonFormat::MOTORDETAILS_SLIPSPEED).toDouble());
    motorDetailsData_.setMotorZeroDetails(motorDetailsZero);
    motorDetailsData_.setMotorOneDetails(motorDetailsOne);
}
