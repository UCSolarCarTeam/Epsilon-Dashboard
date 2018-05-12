#pragma once

#include "../FaultPriorities/FaultPriorities.h"

#include <QString>
#include <QLabel>
#include <QColor>

class FaultLabel : public QLabel
{
public:
    FaultLabel();
    FaultLabel(QString, FaultPriorities::PRIORITY, bool);
    FaultLabel(const FaultLabel& faultLabel);

    ~FaultLabel();

    QColor priorityToColor(FaultPriorities::PRIORITY);
    QString name() const;
    QColor color() const;
    int priority() const;
    bool isActive() const;

    void setActive(bool value);

private:

    QColor color_;
    int priority_;
    bool isActive_;
};
