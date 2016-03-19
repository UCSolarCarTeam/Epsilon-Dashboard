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

#include "ConnectionController.h"

ConnectionController::ConnectionController(
   I_ConnectionService& serial,
   I_ConnectionService& udp)
: type_(CommDefines::Serial)
, serial_(serial)
, udp_(udp)
{
}

ConnectionController::~ConnectionController()
{
}

void ConnectionController::setDeviceType(CommDefines::Type type)
{
   type_ = type;
}

bool ConnectionController::connectToDataSource()
{
   disconnectFromDataSource();

   if (type_ == CommDefines::Udp)
   {
      connectToConnectionService(udp_);
      return udp_.connectToDataSource();
   }
   else
   {
      connectToConnectionService(serial_);
      return serial_.connectToDataSource();
   }
}

void ConnectionController::disconnectFromDataSource()
{
   udp_.disconnectFromDataSource();
   serial_.disconnectFromDataSource();
   disconnectFromConnectionService(udp_);
   disconnectFromConnectionService(serial_);
}

void ConnectionController::connectToConnectionService(I_ConnectionService& service)
{
   connect(&service, SIGNAL(connectionFailed(QString)),
      this, SIGNAL(connectionFailed(QString)), Qt::UniqueConnection);
   connect(&service, SIGNAL(connectionSucceeded()),
      this, SIGNAL(connectionSucceeded()), Qt::UniqueConnection);
}

void ConnectionController::disconnectFromConnectionService(I_ConnectionService& service)
{
   disconnect(&service, 0, this, 0);
}
