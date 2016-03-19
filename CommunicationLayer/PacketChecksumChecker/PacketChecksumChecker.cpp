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

#include <QDebug>

#include "PacketChecksumChecker.h"
#include "../PacketUnstuffer/I_PacketUnstuffer.h"

PacketChecksumChecker::PacketChecksumChecker(const I_PacketUnstuffer& unstuffer)
{
   connect(&unstuffer, SIGNAL(packetUnstuffed(QByteArray)),
      this, SLOT(checkChecksum(QByteArray)));
}

PacketChecksumChecker::~PacketChecksumChecker()
{
}

void PacketChecksumChecker::checkChecksum(QByteArray decodedData)
{
   const quint16 checksum = retrieveChecksumFromPacket(decodedData);
   decodedData.chop(sizeof(checksum));

   quint16 calculatedChecksum = qChecksum(decodedData.constData(), decodedData.size());
   if (calculatedChecksum == checksum)
   {
      emit validDataReceived(decodedData);
   }
   else
   {
      qDebug() << "Calculated =" << QByteArray::number(calculatedChecksum, 16) << "retrieved ="
         << QByteArray::number(checksum, 16);
      qDebug() << "Error decoding data, checksum doesn't match. Data is: " << decodedData;
      emit invalidDataReceived();
   }
}

quint16 PacketChecksumChecker::retrieveChecksumFromPacket(const QByteArray& decodedData)
{
   const int lastIndexOfData = decodedData.size() - 1;
   unsigned char upper = decodedData.at(lastIndexOfData);
   unsigned char lower = decodedData.at(lastIndexOfData - 1);
   quint16 checksum = ((upper << 8) & 0xFF00) | lower;
   return checksum;
}