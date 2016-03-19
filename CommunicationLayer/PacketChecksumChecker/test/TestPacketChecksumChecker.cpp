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

#include <QCoreApplication>
#include <QSignalSpy>
#include "TestPacketChecksumChecker.h"
QTEST_MAIN(TestPacketChecksumChecker)

void TestPacketChecksumChecker::init()
{
   unstuffer_.reset(new FakePacketUnstuffer);
   patient_.reset(new PacketChecksumChecker(*unstuffer_));
}

void TestPacketChecksumChecker::cleanup()
{
   patient_.reset();
   unstuffer_.reset();
}

void TestPacketChecksumChecker::willValidateChecksumOfPacket()
{
   QFETCH(QByteArray, unstuffedData);

   QSignalSpy spy(patient_.data(), SIGNAL(validDataReceived(QByteArray)));
   unstuffer_->emitPacketUnstuffed(unstuffedData);

   QCOMPARE(spy.count(), 1);
   QTEST(spy[0][0].toByteArray(), "expectedResult");
}

void TestPacketChecksumChecker::willValidateChecksumOfPacket_data()
{
   QTest::addColumn<QByteArray>("unstuffedData");
   QTest::addColumn<QByteArray>("expectedResult");
   {
      QByteArray test("Batman");
      QTest::newRow("data Batman") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("123456789");
      QTest::newRow("data 123456789") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("9jsdf83sda");
      QTest::newRow("data 9jsdf83sda") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("0000000000");
      QTest::newRow("data 0000000000") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("U of C Solar Car team");
      QTest::newRow("data U of C Solar Car team") << calculateChecksumAndAddToData(test) << test;
   }
}

void TestPacketChecksumChecker::willNotValidateIfChecksumIsIncorrect()
{
   QByteArray unstuffedData(calculateChecksumAndAddToData(QByteArray("123456789")));
   ++unstuffedData.data()[unstuffedData.size() - 1];

   QSignalSpy spy(patient_.data(), SIGNAL(validDataReceived(QByteArray)));
   unstuffer_->emitPacketUnstuffed(unstuffedData);

   QCOMPARE(spy.count(), 0);
}

QByteArray TestPacketChecksumChecker::calculateChecksumAndAddToData(const QByteArray& data)
{
   quint16 checksum =  qChecksum(data.constData(), data.size());
   QByteArray dataWithChecksum(data);
   dataWithChecksum.append(checksum & 0xFF);
   dataWithChecksum.append((checksum >> 8) & 0xFF);
   return dataWithChecksum;
}
