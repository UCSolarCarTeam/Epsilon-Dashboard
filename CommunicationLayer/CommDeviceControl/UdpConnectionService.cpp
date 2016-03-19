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
#include "UdpConnectionService.h"
#include <QDebug>

UdpConnectionService::UdpConnectionService(QUdpSocket& socket)
: port_(0)
, socket_(socket)
{
}

UdpConnectionService::~UdpConnectionService()
{
}

void  UdpConnectionService::setMulticastNetwork(QHostAddress groupAddress, quint16 port)
{
   groupAddress_ = groupAddress;
   port_ = port;
}

bool UdpConnectionService::connectToDataSource()
{
   if (groupAddress_.isNull() || port_ == 0)
   {
      emit connectionFailed("Group address and port number is not set!");
      return false;
   }
   if (socket_.bind(QHostAddress::AnyIPv4, port_, QUdpSocket::ShareAddress) &&
      socket_.joinMulticastGroup(groupAddress_))
   {
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(socket_.errorString());
      return false;
   }
}

void UdpConnectionService::disconnectFromDataSource()
{
   if(socket_.state() != QUdpSocket::UnconnectedState){
      socket_.leaveMulticastGroup(groupAddress_);
   }
   socket_.close();

   emit connectionFailed("DISCONNECTED");
}
