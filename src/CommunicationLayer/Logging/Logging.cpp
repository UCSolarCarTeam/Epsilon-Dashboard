#include <iostream>

#include <QDebug>
#include <QFile>
#include <QDate>
#include <QDir>
#include <QJsonDocument>

#include "Logging.h"

namespace
{
    QString LOG_DIR = "log";
    QString LOG_NAME = "/epsilon-dashboard-";
    QString LOG_DATE_FORMAT = "yyyy-MM-dd";
    QString LOG_EXT = ".log";
}

Logging::Logging()
{
    QString todayStr = QDate::currentDate().toString(LOG_DATE_FORMAT);
    QString logName = LOG_DIR + LOG_NAME + todayStr + LOG_EXT;

    logFile_.setFileName(logName);
    if(!QDir(LOG_DIR).exists()){
        QDir().mkdir(LOG_DIR);
    }

    if (logFile_.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        logStream_.setDevice(&logFile_);
        qInfo() << "Logging Initialized";
    }
    else
    {
        std::cerr << "Logging initalization failed" << std::endl;
        abort();
    }
}

Logging::~Logging()
{
    logFile_.close();
}

void Logging::saveToLog(QJsonObject jsonData)
{
    QJsonDocument doc(jsonData);
    QString msg(doc.toJson(QJsonDocument::Compact));
    logStream_ << msg;
    logStream_.flush();
}
