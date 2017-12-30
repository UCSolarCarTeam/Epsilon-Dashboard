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



#include "JsonReceiver.h"
#include "CommDeviceControl/I_CommDevice.h"

JsonReceiver::JsonReceiver(I_CommDevice& inputDevice,
                           BatteryPopulator& batteryPopulator,
                           BatteryFaultsPopulator& batteryFaultsPopulator,
                           DriverControlsPopulator& driverControlsPopulator,
                           KeyMotorPopulator& keyMotorPopulator,
                           LightsPopulator& lightsPopulator,
                           MpptPopulator& mpptPopulator,
                           MotorDetailsPopulator& motorDetailsPopulator,
                           MotorFaultsPopulator& motorFaultsPopulator,
                           I_CommunicationsMonitoringService& communicationsMonitoringService)
    : inputDevice_(inputDevice)
    , batteryPopulator_(batteryPopulator)
    , batteryFaultsPopulator_(batteryFaultsPopulator)
    , driverControlsPopulator_(driverControlsPopulator)
    , keyMotorPopulator_(keyMotorPopulator)
    , lightsPopulator_(lightsPopulator)
    , mpptPopulator_(mpptPopulator)
    , motorDetailsPopulator_(motorDetailsPopulator)
    , motorFaultsPopulator_(motorFaultsPopulator)
    , communicationsMonitoringService_(communicationsMonitoringService)
{
    //Q_UNUSED(inputDevice);
    connect(&inputDevice_, SIGNAL(dataReceived(QByteArray)), this, SLOT(handleIncomingData(QByteArray)));

    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &batteryPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &batteryFaultsPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &driverControlsPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &keyMotorPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &lightsPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &mpptPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &motorDetailsPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(dataReceived(const QJsonObject&)),
            &motorFaultsPopulator_, SLOT(populateData(const QJsonObject&)));
    connect(this, SIGNAL(invalidDataReceived()),
            &communicationsMonitoringService_, SLOT(invalidPacketReceived()));
}

void JsonReceiver::handleIncomingData(const QByteArray& data)
{
    QJsonParseError err;
    QJsonObject parsedData = QJsonDocument::fromJson(data, &err).object();

    if (err.error != QJsonParseError::NoError)
    {
        qDebug() << err.errorString();
        emit invalidDataReceived();
    }
    else
    {
        emit dataReceived(parsedData);
    }
}
