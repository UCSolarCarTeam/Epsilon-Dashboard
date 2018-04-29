#pragma once

#include <QString>
#include <QLabel>

class FaultLabel : QLabel
{
public:
    FaultLabel(QString& name, QString& color, int& priority, bool isActive);

    ~FaultLabel();

    QString name();
    QString color();
    int priority();
    bool isActive();

    void setIsActive(bool value);

private:

    //QString name_;
    QString color_;
    int priority_;
    bool isActive_;
}
