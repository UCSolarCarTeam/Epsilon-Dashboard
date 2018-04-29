#pragma once

#include <QFile>
#include <QJsonObject>
#include <QTextStream>

class Logging
{
public:
    Logging();
    ~Logging();

    void saveToLog(QJsonObject jsonData);
private:
    QFile logFile_;
    QTextStream logStream_;
};
