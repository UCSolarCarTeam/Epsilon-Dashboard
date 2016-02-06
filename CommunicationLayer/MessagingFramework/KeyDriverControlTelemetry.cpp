/**
 *  Schulich Delta Host Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Schulich Delta Host Telemetry
 *
 *  The Schulich Delta Host Telemetry is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Schulich Delta Host Telemetry is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Schulich Delta Host Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#include "KeyDriverControlTelemetry.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int setSpeedIndex = 1;
   const int setCurrentIndex = 5;
   const int busCurrentIndex = 9;
   const int busVoltageIndex = 13;
   const int speedIndex = 17;
}

KeyDriverControlTelemetry::KeyDriverControlTelemetry(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float KeyDriverControlTelemetry::setSpeed() const
{
   return getFloat(messageData_, setSpeedIndex);
}

float KeyDriverControlTelemetry::setCurrent() const
{
   return getFloat(messageData_, setCurrentIndex);
}

float KeyDriverControlTelemetry::busCurrent() const
{
   return getFloat(messageData_, busCurrentIndex);
}

float KeyDriverControlTelemetry::busVoltage() const
{
   return getFloat(messageData_, busVoltageIndex);
}

float KeyDriverControlTelemetry::speed() const
{
   return getFloat(messageData_, speedIndex);
}

QString KeyDriverControlTelemetry::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::KeyDriverControlTelemetry) + ", ";
   messageString += QString::number(setSpeed()) + ", ";
   messageString += QString::number(setCurrent()) + ", ";
   messageString += QString::number(busCurrent()) + ", ";
   messageString += QString::number(busVoltage()) + ", ";
   messageString += QString::number(speed()) + ", ";
   return messageString;
}
