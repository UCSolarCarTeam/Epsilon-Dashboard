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

#include "PacketDecoder.h"
#include "../PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../MessagingFramework/MessageDefines.h"

namespace
{
   const int INDEX_OF_PACKET_TYPE = 0;
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker)
{
   connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)),
      this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder()
{
}

void PacketDecoder::handleValidData(QByteArray messageData)
{
   MessageDefines::Type messageType =
      static_cast<MessageDefines::Type>(messageData.at(INDEX_OF_PACKET_TYPE));
   if (MessageDefines::getLengthForMessage(messageType) == messageData.size())
   {
      switch(messageType)
      {
      case MessageDefines::KeyDriverControlTelemetry:
         emit packetDecoded(KeyDriverControlTelemetry(messageData));
         return;
      case MessageDefines::DriverControlDetails:
         emit packetDecoded(DriverControlDetails(messageData));
         return;
      case MessageDefines::Faults:
         emit packetDecoded(FaultsMessage(messageData));
         return;
      case MessageDefines::BatteryData:
         emit packetDecoded(BatteryDataMessage(messageData));
         return;
      case MessageDefines::CmuData:
         emit packetDecoded(CmuDataMessage(messageData));
         return;
      case MessageDefines::MpptData:
         emit packetDecoded(MpptDataMessage(messageData));
         return;
      }
   }
   else
   {
      qDebug() << "Message length is not correct for type" << static_cast<quint8>(messageType);
      qDebug() << "Actual" << messageData.size() << "Expected" << MessageDefines::getLengthForMessage(messageType);
   }
}
