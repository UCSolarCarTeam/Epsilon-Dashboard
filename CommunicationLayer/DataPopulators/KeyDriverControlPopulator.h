/**
 *  Gen 5 Dashboard
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Gen 5 Dashboard
 *
 *  The Gen 5 Dashboard is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Gen 5 Dashboard is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Gen 5 Dashboard.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#pragma once

#include <QObject>
#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
#include "CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h"
#include "DataLayer/VehicleData/I_VehicleData.h"
#include "DataLayer/PowerData/I_PowerData.h"

class KeyDriverControlPopulator : public QObject
{
   Q_OBJECT
public:
   KeyDriverControlPopulator(I_PacketDecoder& packetDecoder,
                       I_VehicleData& vehicleData,
                       I_PowerData& powerData);

public slots:
   void populateData(const KeyDriverControlTelemetry);

private:
   I_PacketDecoder& packetDecoder_;
   I_VehicleData& vehicleData_;
   I_PowerData& powerData_;
};
