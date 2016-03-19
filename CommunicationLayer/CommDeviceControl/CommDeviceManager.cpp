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

#include <QUdpSocket>

#include "CommDeviceManager.h"
#include <QDebug>

CommDeviceManager::CommDeviceManager(QUdpSocket& udpSocket, QIODevice& serialDevice)
: udpSocket_(udpSocket)
, serialDevice_(serialDevice)
{
}

CommDeviceManager::~CommDeviceManager()
{
}

void CommDeviceManager::connectToDevice(CommDefines::Type type)
{
   disconnectFromDevices();
   if (type == CommDefines::Udp)
   {
      connect(&udpSocket_, SIGNAL(readyRead()), this, SLOT(handleUdpDataIncoming()), Qt::UniqueConnection);
   }
   else
   {
      connect(&serialDevice_, SIGNAL(readyRead()), this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
   }
}

void CommDeviceManager::disconnectFromDevices()
{
   disconnect(&udpSocket_, 0, this, 0);
   disconnect(&serialDevice_, 0, this, 0);
}

void CommDeviceManager::handleUdpDataIncoming()
{
   while (udpSocket_.hasPendingDatagrams())
   {
      QByteArray datagram;
      datagram.resize(udpSocket_.pendingDatagramSize());
      udpSocket_.readDatagram(datagram.data(), datagram.size());

      if (!datagram.isEmpty())
      {
         emit dataReceived(datagram);
      }
   }
}

void CommDeviceManager::handleSerialDataIncoming()
{
   QByteArray incomingData = serialDevice_.readAll();
   if (incomingData.isEmpty())
   {
      return;
   }
   emit dataReceived(incomingData);
}
