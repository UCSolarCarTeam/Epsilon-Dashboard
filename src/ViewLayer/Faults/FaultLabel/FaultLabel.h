#pragma once

#include <QString>
#include <QLabel>
#include <QColor>

class FaultLabel : public QLabel
{
public:
    FaultLabel();
    FaultLabel(QString name, QColor color, int priority, bool isActive);
    FaultLabel(const FaultLabel& faultLabel);

    ~FaultLabel();

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
