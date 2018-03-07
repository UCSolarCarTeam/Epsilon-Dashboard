#pragma once

#include "I_HomePageUi.h"

namespace Ui
{
    class HomePageUi;
}

class HomePageUi : public I_HomePageUi
{
    Q_OBJECT

public:

    explicit HomePageUi();
    ~HomePageUi();
    QPushButton& batteryButton();
    QPushButton& controlButton();
    QPushButton& faultButton();
    QPushButton& motorButton();
    QPushButton& mpptButton();
    QLabel& carLabel();

private:
    Ui::HomePageUi* ui_;
};
