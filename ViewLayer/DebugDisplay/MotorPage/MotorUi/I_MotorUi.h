#pragma once

#include <QWidget>
#include <QLabel>

class I_MotorUi: public QWidget
{
public:
    virtual ~I_MotorUi() {}

    virtual QLabel& titleLabel() = 0;
};
