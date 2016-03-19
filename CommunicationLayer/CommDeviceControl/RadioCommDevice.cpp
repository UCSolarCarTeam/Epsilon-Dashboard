#include <QDebug>
#include <QTimer>
#include "RadioCommDevice.h"

namespace
{
   const QString DEFAULT_PORT_NAME = "/dev/pts/7";
   const int DEFAULT_BAUDRATE = 9600;
}

RadioCommDevice::RadioCommDevice(QSerialPort& serialPort)
: serialPort_(serialPort)
{
   setSerialParameters(DEFAULT_PORT_NAME, DEFAULT_BAUDRATE);
   // This makes sure that it is connected after everything is created.
   // Otherwise the error messages won't be sent to the GUI
   QTimer::singleShot(0, this, SLOT(connectToDataSource()));
}

RadioCommDevice::~RadioCommDevice()
{
}

void RadioCommDevice::setSerialParameters(QString serialPortName, int baudRate)
{
   serialPort_.setPortName(serialPortName);
   serialPort_.setBaudRate(baudRate);
}

bool RadioCommDevice::connectToDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      connect(&serialPort_, SIGNAL(readyRead()),
         this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
      emit connectionSucceeded();
      return true;
   }
   else
   {
      qDebug() << serialPort_.errorString();
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioCommDevice::handleSerialDataIncoming()
{
   QByteArray incomingData = serialPort_.readAll();
   if (incomingData.isEmpty())
   {
      return;
   }
   emit dataReceived(incomingData);
}
