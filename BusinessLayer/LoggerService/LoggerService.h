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

#pragma once

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDateTime>
#include <QDir>

#include "../../CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
class I_PacketDecoder;
class I_PacketSynchronizer;

class LoggerService : public QObject
{
   Q_OBJECT
public:
   LoggerService(const I_PacketSynchronizer& packetSynchronizer,
      const I_PacketDecoder& packetDecoder);
   virtual ~LoggerService();

private slots:
   void handleFramedPacket(QByteArray packet);
   void handlePacketDecoded(const KeyDriverControlTelemetry message);
   void handlePacketDecoded(const DriverControlDetails message);
   void handlePacketDecoded(const FaultsMessage message);
   void handlePacketDecoded(const BatteryDataMessage message);
   void handlePacketDecoded(const CmuDataMessage message);
   void handlePacketDecoded(const MpptDataMessage message);

private:
   void connectToPacketDecoder(const I_PacketDecoder& decoder);
   template <class T>
   void printReceivedMessage(const T& message);
   void markStartOfDebugLog() const;
   void markEndOfDebugLog() const;

   QFile logCsvFile_;
   QTextStream csvFileWriter_;

   QFile rawDataFile_;
   QDataStream dataWriter_;
};
