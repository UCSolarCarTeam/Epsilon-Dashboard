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

#include "PacketUnstuffer.h"
#include "../PacketSynchronizer/I_PacketSynchronizer.h"

namespace
{
   const int MINIMUM_LENGTH_OF_A_PACKET = 4;
}

PacketUnstuffer::PacketUnstuffer(const I_PacketSynchronizer& packetSynchronizer)
{
   connect(&packetSynchronizer, SIGNAL(framedPacket(QByteArray)),
      this, SLOT(handleFramedPacket(QByteArray)));
}

PacketUnstuffer::~PacketUnstuffer()
{
}

void PacketUnstuffer::injectFramedData(const QByteArray& data)
{
   handleFramedPacket(data);
}

void PacketUnstuffer::handleFramedPacket(QByteArray packet)
{
   if (!isPacketAtLeastMinimumSize(packet))
   {
      qDebug() << "Incoming packet is less that " << MINIMUM_LENGTH_OF_A_PACKET << " bytes";
      return;
   }

   const unsigned int length = packet.size();
   QByteArray decodedData;
   unsigned int indexOfCode = 0;
   while (indexOfCode < length)
   {
      unsigned int indexOfNextCode = (unsigned)packet.at(indexOfCode) + indexOfCode;
      for (unsigned int j = indexOfCode + 1; j < indexOfNextCode && j < length; j++)
      {
         decodedData.append(packet.at(j));
      }
      if (indexOfNextCode < 0xFF && indexOfNextCode < length)
      {
         decodedData.append(QChar(0x00));
      }
      indexOfCode = indexOfNextCode;
   }
   emit packetUnstuffed(decodedData);
}

bool PacketUnstuffer::isPacketAtLeastMinimumSize(const QByteArray& packet)
{
   return packet.size() >= MINIMUM_LENGTH_OF_A_PACKET;
}
