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

#include <QChar>

#include "PacketSynchronizer.h"
#include "CommunicationLayer/CommDeviceControl/I_CommDevice.h"

namespace
{
   const QChar FRAMING_BYTE = 0x00;
}

PacketSynchronizer::PacketSynchronizer(
   I_CommDevice& inputDevice)
: buffer_()
{
   connect(&inputDevice, SIGNAL(dataReceived(QByteArray)),
      this, SLOT(handleIncomingData(QByteArray)));
}

PacketSynchronizer::~PacketSynchronizer()
{
}

void PacketSynchronizer::handleIncomingData(QByteArray incomingData)
{
   if (incomingData.isEmpty())
   {
      return;
   }

   buffer_.append(incomingData);
   if (alignStartOfPacketToBeginningOfBuffer())
   {
      while(extractPacketIfComplete());
   }
}

bool PacketSynchronizer::alignStartOfPacketToBeginningOfBuffer()
{
   int indexOfStartOfPacket = buffer_.indexOf(FRAMING_BYTE);
   if (indexOfStartOfPacket == -1)
   {
      return false;
   }
   else if (indexOfStartOfPacket > 0)
   {
      buffer_ = buffer_.mid(indexOfStartOfPacket);
   }
   return true;
}

bool PacketSynchronizer::extractPacketIfComplete()
{
   int indexOfEndOfPacket = buffer_.indexOf(FRAMING_BYTE, 1); // Find if there is an end.
   if (indexOfEndOfPacket == -1)
   {
      return false;
   }

   QByteArray packet = buffer_.left(indexOfEndOfPacket);
   packet = packet.mid(1); // remove the leading 0x00
   buffer_.remove(0, indexOfEndOfPacket);
   emit framedPacket(packet);
   return true;
}
