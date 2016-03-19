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

#include "CommunicationsMonitoringService.h"
#include "CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h"
#include <QDebug>

CommunicationsMonitoringService::CommunicationsMonitoringService(I_PacketChecksumChecker& packetChecksumChecker)
: packetChecksumChecker_(packetChecksumChecker)
, secondsSinceLastPacketReceived_(0)
, packetsReceivedInLastMinute_(0)
, secondsSinceLastValidPacketReceived_(0)
, validPacketsReceivedInLastMinute_(0)
, invalidPacketsReceivedInLastMinute_(0)
{
   connect(&packetChecksumChecker_, SIGNAL(validDataReceived(QByteArray)),
         this, SLOT(validPacketReceived()));
   connect(&packetChecksumChecker_, SIGNAL(invalidDataReceived()),
         this, SLOT(invalidPacketReceived()));
   connect(&updateTimer_, SIGNAL(timeout()),
         this, SLOT(update()));

   updateTimer_.setInterval(1000); // update every second
   updateTimer_.setSingleShot(false);

   start();
}

void CommunicationsMonitoringService::start()
{
   secondsSinceLastPacketReceived_ = 0;
   packetsReceivedInLastMinute_ = 0;
   secondsSinceLastValidPacketReceived_ = 0;
   validPacketsReceivedInLastMinute_ = 0;
   invalidPacketsReceivedInLastMinute_ = 0;
   updateTimer_.start();
}

void CommunicationsMonitoringService::stop()
{
   updateTimer_.stop();
}

void CommunicationsMonitoringService::validPacketReceived()
{
   validPacketsReceivedInLastMinute_++;
   secondsSinceLastValidPacketReceived_ = 0;
   QTimer::singleShot(60000, this, SLOT(decrementValidPacketsReceivedInLastMinute()));

   packetsReceivedInLastMinute_++;
   secondsSinceLastPacketReceived_ = 0;
   QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}
void CommunicationsMonitoringService::invalidPacketReceived()
{
   invalidPacketsReceivedInLastMinute_++;
   QTimer::singleShot(60000, this, SLOT(decrementInvalidPacketsReceivedInLastMinute()));

   packetsReceivedInLastMinute_++;
   secondsSinceLastPacketReceived_ = 0;
   QTimer::singleShot(60000, this, SLOT(decrementPacketsReceivedInLastMinute()));
}

void CommunicationsMonitoringService::update()
{
   secondsSinceLastPacketReceived_++;
   secondsSinceLastValidPacketReceived_++;

   emit secondsSinceLastPacketReceivedUpdate(secondsSinceLastPacketReceived_);
   emit packetsReceivedInLastMinuteUpdate(packetsReceivedInLastMinute_);
   emit secondsSinceLastValidPacketReceivedUpdate(secondsSinceLastValidPacketReceived_);
   emit validPacketsReceivedInLastMinuteUpdate(validPacketsReceivedInLastMinute_);
   emit invalidPacketsReceivedInLastMinuteUpdate(invalidPacketsReceivedInLastMinute_);
}

void CommunicationsMonitoringService::decrementPacketsReceivedInLastMinute()
{
   packetsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementValidPacketsReceivedInLastMinute()
{
   validPacketsReceivedInLastMinute_--;
}
void CommunicationsMonitoringService::decrementInvalidPacketsReceivedInLastMinute()
{
   invalidPacketsReceivedInLastMinute_--;
}
