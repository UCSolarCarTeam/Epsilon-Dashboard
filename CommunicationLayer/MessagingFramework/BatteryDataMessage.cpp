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

#include "BatteryDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int BATTERY_VOLTAGE_INDEX = 1;
   const int BATTERY_CURRENT_INDEX = 5;
   const int STATE_OF_CHARGE_INDEX = 9;
   const int BALANCE_SOC_INDEX = 13;
   const int SECONDARY_ERROR_INDEX = 17;
}

BatteryDataMessage::BatteryDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

float BatteryDataMessage::batteryVoltage() const
{
   return getFloat(messageData_, BATTERY_VOLTAGE_INDEX);
}

float BatteryDataMessage::batteryCurrent() const
{
   return getFloat(messageData_, BATTERY_CURRENT_INDEX);
}

float BatteryDataMessage::stateOfCharge() const
{
   return getFloat(messageData_, STATE_OF_CHARGE_INDEX);
}

float BatteryDataMessage::balanceStateOfCharge() const
{
   return getFloat(messageData_, BALANCE_SOC_INDEX);
}

bool BatteryDataMessage::secondaryBatteryUnderVoltage() const
{
   return static_cast<bool>(messageData_.at(SECONDARY_ERROR_INDEX));
}

QString BatteryDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::BatteryData) + ", ";
   messageString += QString::number(batteryVoltage()) + ", ";
   messageString += QString::number(batteryCurrent()) + ", ";
   messageString += QString::number(stateOfCharge()) + ", ";
   messageString += QString::number(balanceStateOfCharge()) + ", ";
   messageString += QString::number(secondaryBatteryUnderVoltage()) + ", ";
   return messageString;
}
