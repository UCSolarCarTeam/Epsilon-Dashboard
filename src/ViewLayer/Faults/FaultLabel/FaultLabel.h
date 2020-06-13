#pragma once

#include "../FaultPriorities/FaultPriorities.h"

#include <QString>
#include <QLabel>
#include <QColor>

class FaultLabel : public QLabel
{
public:
    FaultLabel();
    FaultLabel(QString, FaultPriorities::PRIORITY, bool, bool);
    FaultLabel(const FaultLabel&);

    ~FaultLabel();

    QString name() const;
    QColor color() const;
    FaultPriorities::PRIORITY priority() const;
    bool isActive() const;
    bool isRaceRequired() const;

    void setActive(bool);

private:

    QColor priorityToColor(FaultPriorities::PRIORITY);

    QColor color_;
    FaultPriorities::PRIORITY priority_;
    bool isActive_;
    bool isRaceRequired_;
};
