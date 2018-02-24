#pragma once

#include <QWidget>
#include <QPushButton>

class I_HomePageUi: public QWidget
{
public:
    virtual ~I_HomePageUi() {}

    virtual QPushButton& batteryButton() = 0;
    virtual QPushButton& controlButton() = 0;
    virtual QPushButton& motorButton() = 0;
    virtual QPushButton& faultButton() = 0;
    virtual QPushButton& mpptButton() = 0;
};
