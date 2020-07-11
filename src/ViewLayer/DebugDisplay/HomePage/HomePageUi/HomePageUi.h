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
    QPushButton& batteryButton() override;
    QPushButton& controlButton() override;
    QPushButton& faultButton() override;
    QPushButton& motorButton() override;
    QPushButton& mpptButton() override;
    QPushButton& auxBmsButton() override;
    QLabel& carLabel() override;

private:
    Ui::HomePageUi* ui_;
};
