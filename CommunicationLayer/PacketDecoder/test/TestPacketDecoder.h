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
#include <QScopedPointer>
#include <QTest>
#include "../../PacketChecksumChecker/FakePacketChecksumChecker.h"
#include "../PacketDecoder.h"

class TestPacketDecoder : public QObject
{
   Q_OBJECT
private slots:
   void init();
   void cleanup();

   void willReceiveKeyDriverControlTelemetry();
   void willReceiveDriverControlDetails();
   void willReceiveFaultsMessage();
   void willReceiveBatteryDataMessage();
   void willReceiveCmuDataMessage();
   void willReceiveMpptDataMessage();

protected slots:
   void handlePacketDecoded(const KeyDriverControlTelemetry message);
   void handlePacketDecoded(const DriverControlDetails message);
   void handlePacketDecoded(const FaultsMessage message);
   void handlePacketDecoded(const BatteryDataMessage message);
   void handlePacketDecoded(const CmuDataMessage message);
   void handlePacketDecoded(const MpptDataMessage message);

private:
   void connectPacketDecodedSignals();
   QByteArray createValidKeyDriverControlTelemetry() const;
   QByteArray createValidDriverControlDetails() const;
   QByteArray createValidFaultsMessage() const;
   QByteArray createValidBatteryDataMessage() const;
   QByteArray createValidCmuDataMessage() const;
   QByteArray createValidMpptDataMessage() const;
   QByteArray floatToByteArray(float value) const;

private:
   QScopedPointer<FakePacketChecksumChecker> checksumChecker_;
   QScopedPointer<PacketDecoder> patient_;
   QList<KeyDriverControlTelemetry> receivedKeyDriverControlTelemetry_;
   QList<DriverControlDetails> receivedDriverControlDetails_;
   QList<FaultsMessage> receivedFaultsMessages_;
   QList<BatteryDataMessage> receivedBatteryDataMessages_;
   QList<CmuDataMessage> receivedCmuDataMessages_;
   QList<MpptDataMessage> receivedMpptDataMessages_;
};
