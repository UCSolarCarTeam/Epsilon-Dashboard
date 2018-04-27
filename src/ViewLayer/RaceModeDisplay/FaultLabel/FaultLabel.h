#pragma once

#include <QString>

class FaultLabel : QLabel
{
public:
    FaultLabel();

private:

    int priority_;
    QString name_;
    QString color_;
    bool isActive_;
}
