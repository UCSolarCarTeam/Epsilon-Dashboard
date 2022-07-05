#pragma once

#include "../FaultPriorities/FaultPriorities.h"

#include <QString>
#include <QColor>
#include <QElapsedTimer>

class QElapsedTimer;

class FaultDisplayData
{
public:
    FaultDisplayData();
    FaultDisplayData(QString, FaultPriorities::PRIORITY, bool);
    FaultDisplayData(const FaultDisplayData&);

    ~FaultDisplayData();

    FaultDisplayData& operator=(const FaultDisplayData&);
    QString name() const;
    QColor color() const;
    FaultPriorities::PRIORITY priority() const;
    bool isActive() const;
    void setActive(bool);

private:
    QColor priorityToColor(FaultPriorities::PRIORITY);
    QString name_;
    QColor color_;
    FaultPriorities::PRIORITY priority_;
    bool isActive_;
    QElapsedTimer keepAliveTimer_;
};
