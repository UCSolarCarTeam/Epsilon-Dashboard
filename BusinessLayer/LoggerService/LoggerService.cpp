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

#include "LoggerService.h"
#include "../../CommunicationLayer/PacketSynchronizer/I_PacketSynchronizer.h"

#define PIPE_DEBUG_OUTPUT_TO_FILE 0

namespace
{
   QString printOutContext(const QMessageLogContext& context)
   {
      return QString("In File %1, line %2, function %3").arg(context.file).arg(context.line).arg(context.function);
   }

   const QString LOG_DIRECTORY = "logs";
   const QString DEBUG_LOG_NAME = LOG_DIRECTORY + "/DebugLog.txt";
}

void handleQDebugMessages(QtMsgType type,
   const QMessageLogContext& context, const QString& message)
{
   QScopedPointer<QTextStream> debugFileWriter;

#if PIPE_DEBUG_OUTPUT_TO_FILE
   QFile debugFile(DEBUG_LOG_NAME);
   if (debugFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
   {
      debugFileWriter.reset(new QTextStream(&debugFile));
   }
   else
#endif
   {
      debugFileWriter.reset(new QTextStream(stdout));
   }

   switch (type)
   {
   default:
   case QtDebugMsg:
      *debugFileWriter << "DEBUG: " << QDateTime::currentDateTime().toString("Thh:mm:ss:zzz: ")
         << message << endl;
   break;
   case QtWarningMsg:
      *debugFileWriter << "WARNING: " << QDateTime::currentDateTime().toString("Thh:mm:ss:zzz: ")
         << message << endl << "   " << printOutContext(context) << endl;
      break;
   case QtCriticalMsg:
      *debugFileWriter << "CRITICAL: " << QDateTime::currentDateTime().toString("Thh:mm:ss:zzz: ")
         << message << endl << "   " << printOutContext(context) << endl;
      break;
   case QtFatalMsg:
      *debugFileWriter << "FATAL: " << QDateTime::currentDateTime().toString("Thh:mm:ss:zzz: ")
         << message << endl << "   " << printOutContext(context) << endl;
      abort();
   }
}

LoggerService::LoggerService(
      const I_PacketSynchronizer& packetSynchronizer,
      const I_PacketDecoder& packetDecoder)
{
   connectToPacketDecoder(packetDecoder);
   connect(&packetSynchronizer, SIGNAL(framedPacket(QByteArray)),
      this, SLOT(handleFramedPacket(QByteArray)));

   QDir().mkdir("logs");
   QDir debugDirectory("logs");
   QDateTime date = QDateTime::currentDateTime();
   QString currentDataTime(date.toString("yyyy.MM.dd_hh.mm.ss"));
   debugDirectory.mkdir(currentDataTime);
   debugDirectory.cd(currentDataTime);

   qInstallMessageHandler(handleQDebugMessages);
   markStartOfDebugLog();

   logCsvFile_.setFileName(debugDirectory.filePath("messageData.csv"));
   logCsvFile_.open(QIODevice::WriteOnly | QIODevice::Text);
   csvFileWriter_.setDevice(&logCsvFile_);

   rawDataFile_.setFileName(debugDirectory.filePath("rawMessageData.dat"));
   rawDataFile_.open(QIODevice::WriteOnly);
   dataWriter_.setDevice(&rawDataFile_);
}

LoggerService::~LoggerService()
{
   markEndOfDebugLog();
}

void LoggerService::handleFramedPacket(QByteArray packet)
{
   dataWriter_ << QDateTime::currentDateTime() << packet;
}

void LoggerService::handlePacketDecoded(const KeyDriverControlTelemetry message)
{
   printReceivedMessage(message);
}

void LoggerService::handlePacketDecoded(const DriverControlDetails message)
{
   printReceivedMessage(message);
}

void LoggerService::handlePacketDecoded(const FaultsMessage message)
{
   printReceivedMessage(message);
}

void LoggerService::handlePacketDecoded(const BatteryDataMessage message)
{
   printReceivedMessage(message);
}

void LoggerService::handlePacketDecoded(const CmuDataMessage message)
{
   printReceivedMessage(message);
}

void LoggerService::handlePacketDecoded(const MpptDataMessage message)
{
   printReceivedMessage(message);
}

template <class T>
void LoggerService::printReceivedMessage(const T& message)
{
   QDateTime date = QDateTime::currentDateTime();
   QString messageToPrint(QDateTime::currentDateTime().toString("hh:mm:ss:zzz") + ", ");
   messageToPrint.append(message.toString());
   csvFileWriter_ << messageToPrint << endl;
}

void LoggerService::connectToPacketDecoder(const I_PacketDecoder& decoder)
{
   connect(&decoder, SIGNAL(packetDecoded(const KeyDriverControlTelemetry)),
      this, SLOT(handlePacketDecoded(const KeyDriverControlTelemetry)));
   connect(&decoder, SIGNAL(packetDecoded(const DriverControlDetails)),
      this, SLOT(handlePacketDecoded(const DriverControlDetails)));
   connect(&decoder, SIGNAL(packetDecoded(const FaultsMessage)),
      this, SLOT(handlePacketDecoded(const FaultsMessage)));
   connect(&decoder, SIGNAL(packetDecoded(const BatteryDataMessage)),
      this, SLOT(handlePacketDecoded(const BatteryDataMessage)));
   connect(&decoder, SIGNAL(packetDecoded(const CmuDataMessage)),
      this, SLOT(handlePacketDecoded(const CmuDataMessage)));
   connect(&decoder, SIGNAL(packetDecoded(const MpptDataMessage)),
      this, SLOT(handlePacketDecoded(const MpptDataMessage)));
}

void LoggerService::markStartOfDebugLog() const
{
   qDebug() << "===================================================";
   qDebug() << "             Gen 5 Dashboard App Started";
   qDebug() << "===================================================";
}

void LoggerService::markEndOfDebugLog() const
{
   qDebug() << "===================================================";
   qDebug() << "             Gen 5 Dashboard App Closed";
   qDebug() << "===================================================";
}
