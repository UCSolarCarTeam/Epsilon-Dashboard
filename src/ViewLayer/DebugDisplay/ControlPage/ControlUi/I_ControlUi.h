#pragma once
#include <QWidget>
#include <QLabel>

class I_ControlUi: public QWidget
{
public:
    virtual ~I_ControlUi() {}
    virtual QLabel& titleLabel() = 0;
};
