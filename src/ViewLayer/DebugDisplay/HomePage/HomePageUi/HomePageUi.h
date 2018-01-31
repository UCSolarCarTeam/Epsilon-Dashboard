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
    QPushButton& faultsButton();
    QPushButton& motorButton();
    QPushButton& mpptButton();

private:
    Ui::HomePageUi* ui_;

};

