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

#include "CmuDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int CELL_NUMBER_INDEX = 1;
   const int PCB_TEMPERATURE_INDEX = 2;
   const int CELL_TEMPERATURE_INDEX = 6;
   const int CELL_VOLTAGE_0_INDEX = 10;
   const int NUMBER_OF_CELLS = 8;
   const int NUMBER_OF_BYTES_IN_FLOAT = 4;
}

CmuDataMessage::CmuDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

quint8 CmuDataMessage::cellNumber() const
{
   return messageData_.at(CELL_NUMBER_INDEX);
}

float CmuDataMessage::pcbTemperature() const
{
   return getFloat(messageData_, PCB_TEMPERATURE_INDEX);
}

float CmuDataMessage::cellTemperature() const
{
   return getFloat(messageData_, CELL_TEMPERATURE_INDEX);
}

QList<float> CmuDataMessage::cellVoltages() const
{
   QList<float> cellVoltagesData;
   for (int i = 0; i < NUMBER_OF_CELLS; i++)
   {
      const int indexOfCell = CELL_VOLTAGE_0_INDEX + i * NUMBER_OF_BYTES_IN_FLOAT;
      cellVoltagesData << getFloat(messageData_, indexOfCell);
   }
   return cellVoltagesData;
}

QString CmuDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::CmuData) + ", ";
   messageString += QString::number(cellNumber()) + ", ";
   messageString += QString::number(pcbTemperature()) + ", ";
   messageString += QString::number(cellTemperature()) + ", ";
   foreach(const float& cellVoltage, cellVoltages())
   {
      messageString += QString::number(cellVoltage) + ", ";
   }
   return messageString;
}
