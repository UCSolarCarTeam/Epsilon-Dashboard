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

#include "RadioConnectionService.h"
#include <QDebug>

namespace
{
   const QString DEFAULT_PORT_NAME = "/dev/ttyAMA0";
   // const QString DEFAULT_PORT_NAME = "COM5";
   const int DEFAULT_BAUDRATE = 9600;
}

RadioConnectionService::RadioConnectionService(QSerialPort& serialPort)
: serialPort_(serialPort)
{
   setSerialParameters(DEFAULT_PORT_NAME, DEFAULT_BAUDRATE);
   connectToDataSource();
}

RadioConnectionService::~RadioConnectionService()
{
   disconnectFromDataSource();
}

void RadioConnectionService::setSerialParameters(QString serialPortName, int baudRate)
{
   serialPort_.setPortName(serialPortName);
   serialPort_.setBaudRate(baudRate);
}

bool RadioConnectionService::connectToDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioConnectionService::disconnectFromDataSource()
{
   serialPort_.close();
   emit connectionFailed("DISCONNECTED");
}
