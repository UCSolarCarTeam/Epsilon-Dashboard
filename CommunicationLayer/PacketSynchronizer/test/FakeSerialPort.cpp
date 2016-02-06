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

#include "FakeSerialPort.h"

FakeSerialPort::FakeSerialPort()
{
}

FakeSerialPort::~FakeSerialPort()
{
}

qint64 FakeSerialPort::readData(char *data, qint64 maxlen)
{
   if (maxlen == 0)
   {
      // Called for post reading operation. Do nothing
      return 0;
   }

   QByteArray dataToReturn = data_.left(maxlen);
   if (dataToReturn.size() > 0)
   {
      memcpy(data, dataToReturn, dataToReturn.size());
   }
   data_.remove(0, maxlen);

   return dataToReturn.size();
}

qint64 FakeSerialPort::writeData(const char *data, qint64 len)
{
   Q_UNUSED(data);
   Q_UNUSED(len);
   return -1;
}

void FakeSerialPort::emitReadyRead()
{
   emit readyRead();
}

void FakeSerialPort::setData(QByteArray data)
{
   data_ = data;
}
