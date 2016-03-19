#-------------------------------------------------
#
#  Gen 5 Dashboard
#  Copyright (C) 2015 University of Calgary Solar Car Team
#
#  This file is part of the Gen 5 Dashboard
#
#  The Gen 5 Dashboard is free software: 
#  you can redistribute it and/or modify it under the terms 
#  of the GNU Affero General Public License as published by 
#  the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  The Gen 5 Dashboard is distributed 
#  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
#  without even the implied warranty of MERCHANTABILITY or 
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
#  General Public License for more details.
#
#  You should have received a copy of the GNU Affero General 
#  Public License along with the Gen 5 Dashboard.
#  If not, see <http://www.gnu.org/licenses/>.
#
#  For further contact, email <software@calgarysolarcar.ca>
#
#-------------------------------------------------

QT += core testlib
TEMPLATE = app

TARGET = packetDecoderTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   TestPacketDecoder.cpp \
   ../PacketDecoder.cpp \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.cpp \
   ../../MessagingFramework/BatteryDataMessage.cpp \
   ../../MessagingFramework/BatteryFaults.cpp \
   ../../MessagingFramework/CmuDataMessage.cpp \
   ../../MessagingFramework/DriverControlDetails.cpp \
   ../../MessagingFramework/FaultsMessage.cpp \
   ../../MessagingFramework/KeyDriverControlTelemetry.cpp \
   ../../MessagingFramework/LimitFlags.cpp \
   ../../MessagingFramework/MessageDecodingHelpers.cpp \
   ../../MessagingFramework/MessageDefines.cpp \
   ../../MessagingFramework/MotorFaults.cpp \
   ../../MessagingFramework/MpptDataMessage.cpp \
   ../../MessagingFramework/MpptDefines.cpp \

HEADERS += \
   TestPacketDecoder.h \
   ../PacketDecoder.h \
   ../I_PacketDecoder.h \
   ../../PacketChecksumChecker/I_PacketChecksumChecker.h \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.h \
   ../../MessagingFramework/BatteryDataMessage.h \
   ../../MessagingFramework/BatteryFaults.h \
   ../../MessagingFramework/CmuDataMessage.h \
   ../../MessagingFramework/DriverControlDetails.h \
   ../../MessagingFramework/FaultsMessage.h \
   ../../MessagingFramework/KeyDriverControlTelemetry.h \
   ../../MessagingFramework/LimitFlags.h \
   ../../MessagingFramework/MessageDecodingHelpers.h \
   ../../MessagingFramework/MessageDefines.h \
   ../../MessagingFramework/MotorFaults.h \
   ../../MessagingFramework/MpptDataMessage.h \
   ../../MessagingFramework/MpptDefines.h \
