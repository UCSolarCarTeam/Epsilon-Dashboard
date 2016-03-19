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

#include "DriverControlDetails.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int motorVelocityIndex = 1;
   const int motorVoltageIndex = 5;
   const int motorCurrentRealIndex = 9;
   const int backEmfIndex = 13;
   const int dpsBoardTemperatureIndex = 17;
   const int dcBusAmpHoursIndex = 21;
   const int odometerIndex = 25;
}

DriverControlDetails::DriverControlDetails(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float DriverControlDetails::motorVelocity() const
{
   return getFloat(messageData_, motorVelocityIndex);
}

float DriverControlDetails::motorVoltage() const
{
   return getFloat(messageData_, motorVoltageIndex);
}

float DriverControlDetails::motorCurrentReal() const
{
   return getFloat(messageData_, motorCurrentRealIndex);
}

float DriverControlDetails::backEmf() const
{
   return getFloat(messageData_, backEmfIndex);
}

float DriverControlDetails::dpsBoardTemperature() const
{
   return getFloat(messageData_, dpsBoardTemperatureIndex);
}

float DriverControlDetails::dcBusAmpHours() const
{
   return getFloat(messageData_, dcBusAmpHoursIndex);
}

float DriverControlDetails::odometer() const
{
   return getFloat(messageData_, odometerIndex);
}

QString DriverControlDetails::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::DriverControlDetails) + ", ";
   messageString += QString::number(motorVelocity()) + ", ";
   messageString += QString::number(motorVoltage()) + ", ";
   messageString += QString::number(motorCurrentReal()) + ", ";
   messageString += QString::number(backEmf()) + ", ";
   messageString += QString::number(dpsBoardTemperature()) + ", ";
   messageString += QString::number(dcBusAmpHours()) + ", ";
   messageString += QString::number(odometer()) + ", ";
   return messageString;
}
