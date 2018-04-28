#pragma once

#include <QFile>
#include <QScopedPointer>
#include <QString>
#include <QTextStream>
#include <QtGlobal>

class Logging
{
public:
    static Logging& instance();

private:
    Logging();
    ~Logging();
    static Logging instance_;

    QFile logFile_;
    QTextStream logStream_;

    static void logMessageHandler(const QString& msg);
};
