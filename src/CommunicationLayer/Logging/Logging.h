#pragma once
#include <iostream>

#include <QCoreApplication>
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
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
