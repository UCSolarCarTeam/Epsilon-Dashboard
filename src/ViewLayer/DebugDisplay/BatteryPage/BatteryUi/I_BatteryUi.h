#pragma once
#include <QWidget>
#include <QLabel>

class I_BatteryUi: public QWidget
{
public:
    virtual ~I_BatteryUi() {}
    virtual QLabel& titleLabel() = 0;
};
