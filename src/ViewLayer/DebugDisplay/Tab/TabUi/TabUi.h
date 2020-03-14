#pragma once
#include "I_TabUi.h"

namespace Ui
{
    class TabUi;
}

class TabUi : public I_TabUi
{
    Q_OBJECT
public:
    explicit TabUi();
    ~TabUi();
    QPushButton& homepageButton() override;
    QPushButton& batteryButton() override;
    QPushButton& controlButton() override;
    QPushButton& faultButton() override;
    QPushButton& motorButton() override;
    QPushButton& mpptButton() override;
    QPushButton& auxBmsButton() override;
private slots:
    void showTime();
private:
    Ui::TabUi* ui_;
};
